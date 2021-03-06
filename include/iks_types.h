/*
  iks_types.h
*/
#ifndef __IKS_TYPES_H__
#define __IKS_TYPES_H__

#include "iks_stack.h"
#include "iks_tree.h"
//#include "iks_grammar.h"

/* Códigos de tipos de dados linguagem */
#define IKS_NOTYPE 	0 
#define IKS_INT 	1
#define IKS_FLOAT 	2
#define IKS_CHAR 	3
#define IKS_STRING 	4
#define IKS_BOOL 	5

/* Códigos de tipos de declarações */
#define IKS_DECL_VAR 		1
#define IKS_DECL_VECTOR 	2
#define IKS_DECL_FUNCTION 	3

/* Código de retorno para erros semânticos */

/* Verficação de declarações */
#define IKS_ERROR_UNDECLARED 	1	 //identificador não declarado
#define IKS_ERROR_DECLARED 		2 //identificador já declarado

/* Uso correto de identificadores */
#define IKS_ERROR_VARIABLE 		3 //identificador deve ser utilizado como variável 
#define IKS_ERROR_VECTOR 		4 //identificador deve ser utilizado como vetor
#define IKS_ERROR_FUNCTION 		5 //identificador deve ser utilizado com função

/* Tipos e tamanhos de dados */
#define IKS_ERROR_WRONG_TYPE 		6 //tipos incompatíveis
#define IKS_ERROR_STRING_TO_X 		7 //coerção impossível do tipo string
#define IKS_ERROR_CHAR_TO_X 		8 //coerção impossível do tipo char

/* Argumentos e parâmetros */
#define IKS_ERROR_MISSING_ARGS		9  //faltam argumentos
#define IKS_ERROR_EXCESS_ARGS 		10 //sobram argumentos
#define IKS_ERROR_WRONG_TYPE_ARGS 	11 //argumentos incompatíveis

/* Verificação de tipos de comandos */
#define IKS_ERROR_WRONG_PAR_INPUT 	12 //parâmetros não é identificador
#define IKS_ERROR_WRONG_PAR_OUTPUT 	13 //parâmetro não é literal string ou expressão
#define IKS_ERROR_WRONG_PAR_RETURN 	14 //parãmetro não é expressão com tipo de retorno

/* Código geral do tipo de erro */
#define IKS_ERROR_USE 	100
#define IKS_ERROR_DECL 	101
#define IKS_ERROR_TYPE 	102

/* Códigos para coerção de tipos */
#define IKS_COERCION_INT_TO_FLOAT 	1
#define IKS_COERCION_INT_TO_BOOL 	2
#define IKS_COERCION_FLOAT_TO_INT 	3
#define IKS_COERCION_FLOAT_TO_BOOL 	4
#define IKS_COERCION_BOOL_TO_INT 	5
#define IKS_COERCION_BOOL_TO_FLOAT 	6

#define IKS_SCOPE_LOCAL 	1
#define IKS_SCOPE_GLOBAL 	2

/* stack of symbol_tables(scope) */
//iks_stack_t *scope; 
iks_stack_t *scopes; 
typedef struct scope_t scope_t;
struct scope_t {
	//iks_stack_t *st; //symbol tables 
	iks_dict_t *st; //symbol tables 
	int type;	
	int next_addr;	
};
scope_t *scope;

scope_t *new_scope();

int verify_coercion(iks_tree_t *id, iks_tree_t *expr);


//int verify_function_args(iks_grammar_symbol_t *s, iks_list_t *args);

//int symbol_is_iks_type(iks_grammar_symbol_t *s,int iks_type);

/**
 * return type inferred (only works with int, float and bool)
 */
int infer_type(iks_tree_t *type1, iks_tree_t *type2);

#endif /* __IKS_TYPES_H__ */

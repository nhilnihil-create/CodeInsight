const BAD_PATTERNS = {
  'Datatypes': [
    {
      id: 'integer_division_truncation',
      description: 'Division of two integer literals truncates the fractional part',
      query: '(binary_expression (number_literal) @lhs (number_literal) @rhs)',
      message: 'Integer division truncates the decimal — cast one operand to double',
    },
    {
      id: 'narrowing_conversion',
      description: 'Assignment of double to int loses precision',
      query: '(declaration (primitive_type) @type (init_declarator (number_literal) @val))',
      message: 'Narrowing conversion may lose precision — check your data types',
    },
  ],
  'Variables': [
    {
      id: 'uninitialized_variable',
      description: 'Variable used before initialization',
      query: '(declaration (primitive_type) (identifier) @uninit)',
      message: 'Variable declared without initialization',
      handler: 'checkUninitialized',
    },
    {
      id: 'shadowed_variable',
      description: 'Variable shadowing hides outer scope variable',
      query: '(declaration (primitive_type) (init_declarator declarator: (identifier) @name))',
      message: 'Variable shadows an outer-scope variable',
      handler: 'checkShadowed',
    },
  ],
  'Conditionals': [
    {
      id: 'assignment_in_condition',
      description: 'Assignment (=) used instead of comparison (==) in if condition',
      query: '(condition_clause (assignment_expression) @assign)',
      message: 'Assignment operator used in condition (did you mean ==?)',
    },
    {
      id: 'empty_if_body',
      description: 'if statement with empty or semicolon-only body',
      query: '(if_statement consequence: (compound_statement) @body)',
      message: 'Conditional body is empty',
    },
    {
      id: 'tautology_condition',
      description: 'Always-true condition (e.g., if (x == x) or if (1))',
      query: '(condition_clause (true) @always)',
      message: 'Condition is always true',
    },
  ],
  'Loops': [
    {
      id: 'infinite_loop',
      description: 'for loop with no increment/decrement',
      query: '(for_statement !update) @for',
      message: 'Loop has no update expression (possible infinite loop)',
    },
    {
      id: 'off_by_one',
      description: 'Loop bound uses <= instead of < with array size pattern',
      query: '(for_statement (binary_expression operator: "<=") @cond)',
      message: 'Loop bound may cause off-by-one error (consider < instead of <=)',
    },
    {
      id: 'loop_variable_reassigned',
      description: 'Loop variable reassigned inside body (e.g., i = 0 inside for)',
      query: '(for_statement (declaration (init_declarator (identifier) @loopvar)) (compound_statement) @body)',
      message: 'Loop variable reassigned inside loop body',
      handler: 'checkLoopVarReassigned',
    },
  ],
  'Functions': [
    {
      id: 'missing_return',
      description: 'Non-void function without return statement',
      query: '(function_definition body: (compound_statement) @body) @func',
      message: 'Non-void function may not return a value',
      handler: 'checkHasReturn',
    },
    {
      id: 'void_return_value',
      description: 'Return value used from void function',
      query: '(call_expression function: (identifier) @fn)',
      message: 'Function call may discard return value incorrectly',
    },
  ],
  'Arrays': [
    {
      id: 'out_of_bounds_literal',
      description: 'Array access with literal index that likely exceeds bounds',
      query: '(subscript_expression (subscript_argument_list (number_literal) @idx))',
      message: 'Array access with literal index (check bounds)',
    },
    {
      id: 'undeclared_array',
      description: 'Array subscript on undeclared identifier',
      query: '(subscript_expression (identifier) @arr)',
      message: 'Array element access may use wrong index',
    },
  ],
  'OOP': [
    {
      id: 'public_members',
      description: 'Class with all public members (no encapsulation)',
      query: '(class_specifier body: (field_declaration_list) @fields) @class',
      message: 'Class members are all public (no encapsulation)',
      handler: 'checkAllPublic',
    },
    {
      id: 'no_constructor',
      description: 'Class without constructor',
      query: '(class_specifier name: (type_identifier) @class_name body: (field_declaration_list) @body)',
      message: 'Class has no constructor',
      handler: 'checkHasConstructor',
    },
  ],
  'Pointers': [
    {
      id: 'dereference_null',
      description: 'Pointer used without null check before dereference',
      query: '(pointer_expression (identifier) @ptr)',
      message: 'Pointer dereferenced without null check',
    },
    {
      id: 'address_of_local',
      description: 'Returning address of a local variable (dangling pointer)',
      query: '(return_statement (addressof_expression (identifier) @local))',
      message: 'Returning address of a local variable (dangling pointer)',
    },
    {
      id: 'pointer_arithmetic_literal',
      description: 'Pointer arithmetic with mismatched types',
      query: '(binary_expression (pointer_expression) (number_literal))',
      message: 'Pointer arithmetic with literal offset — check your types',
    },
  ],
  'Strings': [
    {
      id: 'string_compare_eq',
      description: 'String compared with == instead of .compare() or .equals()',
      query: '(binary_expression operator: "==" (identifier) @str1 (identifier) @str2)',
      message: 'Use string.compare() to compare string contents, not ==',
    },
    {
      id: 'missing_string_include',
      description: 'String variable used without <string> include',
      query: '(declaration (type_identifier) @type)',
      message: 'Add #include <string> when using std::string',
    },
  ],
  'Input/Output': [
    {
      id: 'cin_without_check',
      description: 'cin >> used without checking for input failure',
      query: '(expression_statement (call_expression function: (identifier) @cin_fn))',
      message: 'Check cin for input failure (if (cin >> x))',
    },
    {
      id: 'missing_include_iostream',
      description: 'Stream operations used without <iostream> include',
      query: '(expression_statement)',
      message: 'Add #include <iostream> when using cout/cin',
    },
  ],
  'Switch/Case': [
    {
      id: 'missing_break',
      description: 'case without break (unintentional fall-through)',
      query: '(switch_statement (case_statement (compound_statement)))',
      message: 'Missing break in case (possible unintentional fall-through)',
    },
    {
      id: 'missing_default',
      description: 'Switch without default case',
      query: '(switch_statement) @switch',
      message: 'Add a default: case to handle unexpected input',
    },
  ],
  'Nested Loops': [
    {
      id: 'same_loop_variable',
      description: 'Inner loop reuses outer loop variable',
      query: '(for_statement (declaration (init_declarator (identifier) @outer)))',
      message: 'Inner loop reuses outer loop variable — use different variable names',
    },
    {
      id: 'wrong_loop_order',
      description: 'Row-major vs column-major access pattern mismatch',
      query: '(subscript_expression (subscript_argument_list (identifier) @row (identifier) @col))',
      message: 'Check your loop nesting order for efficient memory access',
    },
  ],
  'Recursion': [
    {
      id: 'no_base_case',
      description: 'Recursive function without a base case (infinite recursion)',
      query: '(function_definition (call_expression) @recursive_call)',
      message: 'Recursive function may have no base case — infinite recursion risk',
    },
    {
      id: 'redundant_recursion',
      description: 'Recursive function that could be iterative',
      query: '(function_definition body: (compound_statement) @body)',
      message: 'Consider using iteration instead of recursion for this pattern',
    },
  ],
  'File I/O': [
    {
      id: 'no_file_open_check',
      description: 'File opened without checking .is_open() success',
      query: '(declaration (type_identifier) @ftype)',
      message: 'Check if file opened successfully with .is_open()',
    },
    {
      id: 'missing_fstream_include',
      description: 'File stream used without <fstream> include',
      query: '(declaration)',
      message: 'Add #include <fstream> when using ifstream/ofstream',
    },
  ],
  'Scope': [
    {
      id: 'declaration_in_loop',
      description: 'Variable declared inside loop (re-allocated each iteration)',
      query: '(for_statement body: (compound_statement (declaration) @decl))',
      message: 'Variable declared inside loop — consider moving it outside',
    },
    {
      id: 'missing_braces',
      description: 'Single-statement body without braces (scope ambiguity)',
      query: '(if_statement consequence: (expression_statement))',
      message: 'Add braces around single-statement body for clarity',
    },
  ],
  'Enums': [
    {
      id: 'plain_enum',
      description: 'Plain enum instead of enum class (type-unsafe)',
      query: '(enum_specifier (enumerator_list) @enums)',
      message: 'Use enum class instead of plain enum for type safety',
    },
    {
      id: 'enum_value_reuse',
      description: 'Duplicate enum values',
      query: '(enumerator (identifier) @first)',
      message: 'Enum values may conflict — assign explicit values if needed',
    },
  ],
  'Structs': [
    {
      id: 'large_struct_by_value',
      description: 'Large struct passed by value instead of const reference',
      query: '(function_definition (parameter_declaration (type_identifier) @type))',
      message: 'Pass large structs by const reference to avoid copying',
    },
    {
      id: 'uninitialized_struct_field',
      description: 'Struct fields not initialized before use',
      query: '(field_expression (identifier) @field)',
      message: 'Initialize all struct fields before use',
    },
  ],
  'Dynamic Memory': [
    {
      id: 'missing_delete',
      description: 'new without matching delete (memory leak)',
      query: '(expression_statement (call_expression function: (identifier) @new_fn))',
      message: 'Every new needs a matching delete',
    },
    {
      id: 'double_delete',
      description: 'delete called twice on same pointer',
      query: '(expression_statement (delete_expression) @del)',
      message: 'Avoid calling delete twice on the same pointer',
    },
  ],
  'Linked Lists': [
    {
      id: 'no_null_check_traversal',
      description: 'Linked list traversal without null check',
      query: '(field_expression argument: (pointer_expression))',
      message: 'Check for nullptr during list traversal',
    },
    {
      id: 'lost_node_reference',
      description: 'Node pointer overwritten before linking neighbor',
      query: '(assignment_expression left: (field_expression) right: (identifier))',
      message: 'Ensure you save the next pointer before overwriting current',
    },
  ],
  'Error Handling': [
    {
      id: 'empty_catch',
      description: 'Empty catch block (swallows exception)',
      query: '(catch_clause (compound_statement) @body)',
      message: 'Empty catch block silently swallows the exception',
    },
    {
      id: 'catch_by_value',
      description: 'Exception caught by value instead of const reference',
      query: '(catch_clause (parameter_declaration (type_identifier) @type))',
      message: 'Catch exceptions by const reference, not by value',
    },
  ],
  'Type Casting': [
    {
      id: 'c_style_cast',
      description: 'C-style cast instead of static_cast / dynamic_cast',
      query: '(cast_expression) @cast',
      message: 'Use static_cast<Type>() instead of C-style cast',
    },
    {
      id: 'precision_loss_cast',
      description: 'Cast from larger to smaller type may lose precision',
      query: '(cast_expression (type_descriptor (primitive_type) @type) @expr)',
      message: 'Cast may lose precision — check the target type size',
    },
  ],
  'Preprocessor': [
    {
      id: 'macro_no_parens',
      description: 'Macro argument not wrapped in parentheses (operator precedence bug)',
      query: '(preproc_function_def body: (preproc_arg) @arg)',
      message: 'Wrap macro arguments and body in parentheses',
    },
    {
      id: 'missing_include_guard',
      description: 'Header file without include guard or #pragma once',
      query: '(preproc_include)',
      message: 'Add #pragma once or include guards to header files',
    },
  ],
  'Namespaces': [
    {
      id: 'using_namespace_header',
      description: 'using namespace std; in a header file (namespace pollution)',
      query: '(using_declaration (namespace_identifier (identifier)))',
      message: 'Avoid using namespace std in header files',
    },
    {
      id: 'missing_std_prefix',
      description: 'Standard library type used without std:: prefix',
      query: '(declaration (type_identifier) @type)',
      message: 'Add std:: prefix or use "using namespace std;"',
    },
  ],
  'Inheritance': [
    {
      id: 'non_virtual_destructor',
      description: 'Base class without virtual destructor',
      query: '(class_specifier name: (type_identifier) @cls body: (field_declaration_list) @body)',
      message: 'Base class destructor should be virtual',
    },
    {
      id: 'missing_override',
      description: 'Overriding function without override keyword',
      query: '(function_definition (identifier) @fn)',
      message: 'Mark overriding functions with override keyword',
    },
  ],
  'Polymorphism': [
    {
      id: 'object_slicing',
      description: 'Derived object assigned to base by value (slicing)',
      query: '(assignment_expression left: (identifier) @base right: (identifier) @derived)',
      message: 'Assigning derived object to base by value causes slicing — use pointer',
    },
    {
      id: 'non_virtual_call',
      description: 'Virtual function called on base object instead of pointer/reference',
      query: '(call_expression function: (field_expression) @method)',
      message: 'Call virtual functions through pointers/references to enable polymorphism',
    },
  ],
};

function getBadPatterns(conceptName) {
  return BAD_PATTERNS[conceptName] || [];
}

function getAllPatterns() {
  const all = [];
  for (const [concept, patterns] of Object.entries(BAD_PATTERNS)) {
    for (const p of patterns) {
      all.push({ ...p, concept });
    }
  }
  return all;
}

module.exports = { BAD_PATTERNS, getBadPatterns, getAllPatterns };

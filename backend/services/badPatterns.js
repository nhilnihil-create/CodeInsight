const BAD_PATTERNS = {
  'Datatypes': [
    {
      id: 'integer_division_truncation',
      description: 'Division of two integer literals truncates the fractional part',
      query: '(binary_expression (number_literal) @lhs (number_literal) @rhs)',
      message: 'Integer division truncates the decimal — cast one operand to double',
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
      // Only flag when the loop bound is a hardcoded count (e.g. i <= 10 for
      // an array of 10) — that is the unambiguous array-size off-by-one case.
      // A variable bound (i <= n, the standard "1..n" idiom) is correct code
      // and must not be rejected.
      description: 'Loop bound uses <= with a literal size (possible off-by-one)',
      query: '(binary_expression operator: "<=" (number_literal) @bound)',
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
  ],
  'Arrays': [],
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
      id: 'address_of_local',
      description: 'Returning address of a local variable (dangling pointer)',
      query: '(return_statement (pointer_expression (identifier) @local))',
      message: 'Returning address of a local variable (dangling pointer)',
    },
  ],
  'Strings': [],
  'Input/Output': [],
  'Switch/Case': [],
  'Nested Loops': [
    {
      id: 'same_loop_variable',
      description: 'Inner loop reuses outer loop variable',
      query: '(for_statement (declaration (init_declarator (identifier) @outer)))',
      message: 'Inner loop reuses outer loop variable — use different variable names',
      handler: 'checkSameLoopVariable',
    },
  ],
  'Recursion': [],
  'File I/O': [],
  'Scope': [],
  'Enums': [],
  'Structs': [],
  'Dynamic Memory': [],
  'Linked Lists': [],
  'Error Handling': [],
  'Type Casting': [],
  'Preprocessor': [],
  'Namespaces': [],
  'Inheritance': [],
  'Polymorphism': [],
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

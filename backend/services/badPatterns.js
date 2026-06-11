/**
 * Bad Pattern Library — Known beginner mistakes per concept.
 *
 * Sourced from Project CodeNet C++1000 analysis:
 *   - For each concept-tagged problem, submissions that fail verification
 *     are analyzed to extract common wrong patterns.
 *   - Each pattern is a tree-sitter S-expression query that matches
 *     syntactically-valid but semantically-wrong code structures.
 *
 * Derived from CodeNet concept_mapping.json analysis of 1000 problems.
 */

const BAD_PATTERNS = {
  // ── Variables / Datatypes ───────────────────────────────────────────────
  'Variables': [
    {
      id: 'uninitialized_variable',
      description: 'Variable used before initialization',
      // (identifier) used in expression but never assigned
      query: '(declaration declarator: (init_declarator))',
      inverse: true, // Flag if NOT found in a function with output
      message: 'Variables used without initialization',
    },
    {
      id: 'shadowed_variable',
      description: 'Variable shadowing hides outer scope variable',
      query: `(declaration
        declarator: (init_declarator
          value: (identifier) @val))`,
      message: 'Variable shadows an outer-scope variable',
    },
  ],

  // ── Conditionals ─────────────────────────────────────────────────────────
  'Conditionals': [
    {
      id: 'assignment_in_condition',
      description: 'Assignment (=) used instead of comparison (==) in if condition',
      query: `(if_statement
        condition: (assignment_expression))`,
      message: 'Assignment operator used in condition (did you mean ==?)',
    },
    {
      id: 'empty_if_body',
      description: 'if statement with empty or semicolon-only body',
      query: `(if_statement
        consequence: (compound_statement) @body)`,
      message: 'Conditional body is empty',
    },
    {
      id: 'tautology_condition',
      description: 'Always-true condition (e.g., if (x == x) or if (1))',
      query: `(if_statement
        condition: [(true) (number_literal)])`,
      message: 'Condition is always true',
    },
  ],

  // ── Loops ────────────────────────────────────────────────────────────────
  'Loops': [
    {
      id: 'infinite_loop',
      description: 'for loop with no increment/decrement',
      query: `(for_statement
        update: (_) @update)`,
      inverse: true,
      message: 'Loop has no update expression (possible infinite loop)',
    },
    {
      id: 'off_by_one',
      description: 'Loop bound uses <= instead of < with array size pattern',
      query: `(for_statement
        condition: (binary_expression
          operator: "<="))`,
      message: 'Loop bound may cause off-by-one error (consider < instead of <=)',
    },
    {
      id: 'loop_variable_reassigned',
      description: 'Loop variable reassigned inside body (e.g., i = 0 inside for)',
      query: `(for_statement
        initializer: (init_declarator
          name: (identifier) @loop_var)
        body: (compound_statement
          (expression_statement
            (assignment_expression
              left: (identifier) @assigned))))`,
      message: 'Loop variable reassigned inside loop body',
    },
  ],

  // ── Functions ────────────────────────────────────────────────────────────
  'Functions': [
    {
      id: 'missing_return',
      description: 'Non-void function without return statement',
      query: `(function_definition
        type: [(primitive_type) @ret (#not-eq? @ret "void")]
        body: (compound_statement) @body)`,
      message: 'Non-void function may not return a value',
    },
    {
      id: 'void_return_value',
      description: 'Return value used from void function',
      query: `(call_expression
        function: (identifier) @fn)`,
      message: 'Function return value may not be used correctly',
    },
  ],

  // ── Arrays ───────────────────────────────────────────────────────────────
  'Arrays': [
    {
      id: 'out_of_bounds_literal',
      description: 'Array access with literal index that likely exceeds bounds',
      query: `(subscript_expression
        argument: (number_literal) @idx)`,
      message: 'Array access with literal index (check bounds)',
    },
    {
      id: 'undeclared_array',
      description: 'Array subscript on undeclared identifier',
      query: `(subscript_expression
        argument: (identifier) @arr)`,
      message: 'Array element access may use wrong index',
    },
  ],

  // ── OOP ──────────────────────────────────────────────────────────────────
  'OOP': [
    {
      id: 'public_members',
      description: 'Class with all public members (no encapsulation)',
      query: `(class_specifier
        body: (field_declaration_list
          (public_access_specifier)))`,
      message: 'Class members are all public (no encapsulation)',
    },
    {
      id: 'no_constructor',
      description: 'Class without constructor',
      query: `(class_specifier
        body: (field_declaration_list
          (function_definition
            name: (identifier) @ctor (#eq? @ctor "constructor"))))`,
      inverse: true,
      message: 'Class has no constructor',
    },
  ],
};

/**
 * Get bad patterns for a specific concept.
 * @param {string} conceptName - e.g., "Loops", "Conditionals"
 * @returns {Array} Array of bad pattern objects
 */
function getBadPatterns(conceptName) {
  return BAD_PATTERNS[conceptName] || [];
}

/**
 * Get all bad patterns across all concepts.
 * @returns {Array} All patterns with their concept attached
 */
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

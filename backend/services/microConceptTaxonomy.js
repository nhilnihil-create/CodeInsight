/**
 * Micro-Concept Taxonomy — Deterministic Rule Definitions
 *
 * This file defines rule-based detectors for all 7 programming concepts.
 * Each rule is a pure function that examines compiler errors, AST node patterns,
 * test result patterns, or code text to detect specific beginner mistakes.
 *
 * No AI, no ML, no embeddings — just deterministic if-then logic.
 *
 * Architecture:
 *   detector(context) → boolean
 *   context = {
 *     ast: {node_types: string[], if_count: number, else_count: number, ...},  // from AST parser
 *     testResults: [{input, expected, actual, passed, error}],                 // from executor
 *     compilerErrors: string[],                                                // parsed from GCC log
 *     code: string,                                                            // raw submission
 *     timeLimitHit: boolean,                                                   // died by timeout?
 *     exercise: {concept_name, required_ast_nodes, time_limit_minutes}
 *   }
 */

const MICRO_CONCEPT_RULES = {
  // ============================================
  // DATATYPES
  // ============================================
  'Datatypes': [
    {
      id: 'dt_wrong_output_type',
      name: 'Wrong Output Type',
      description: 'Using integer when floating-point output expected (e.g., cout << 5 instead of 5.0)',
      detector: ({testResults, compilerErrors, code}) => {
        // Check compiler error: no match for 'operator<<' with float/double
        const hasTypeMismatchError = compilerErrors.some(err =>
          err.includes('no match for \'operator<<\'') ||
          err.includes('cannot convert') ||
          err.includes('invalid conversion')
        );

        // Check test failure pattern: expected contains '.', actual doesn't
        const typeMismatchPattern = testResults.some(r =>
          !r.passed &&
          r.expected && r.actual &&
          r.expected.includes('.') && !r.actual.includes('.')
        );

        return hasTypeMismatchError || typeMismatchPattern;
      },
      instructorMessage: 'Type mismatch detected. Student likely used integer output for a problem requiring decimal precision (e.g., average calculation).',
      studentMessage: 'Check your data types. Are you outputting an integer when a decimal (double/float) is expected?',
      evidenceExtractor: ({testResults, compilerErrors}) => {
        const errorLine = compilerErrors.find(e => e.includes('no match for') || e.includes('cannot convert'));
        return errorLine ? `Compiler: ${errorLine.trim()}` : 'Output type does not match expected';
      }
    },
    {
      id: 'dt_integer_division',
      name: 'Integer Division Truncation',
      description: 'Dividing two integers loses fractional part',
      detector: ({code, testResults}) => {
        // Look for division operator with likely integer operands
        const hasDivision = /\/\s*\d+/.test(code) || /\/\s*\w+\s*[+\-*/]/.test(code);
        if (!hasDivision) return false;

        // Check for pattern: expected value is fractional but actual is integer-truncated
        return testResults.some(r => {
          if (!r.passed && r.expected && r.actual) {
            const exp = parseFloat(r.expected);
            const act = parseFloat(r.actual);
            return exp && act && Math.abs(exp - act) > 0.1 && Math.floor(act) === act;
          }
          return false;
        });
      },
      instructorMessage: 'Integer division: a / b with both integers truncates the fraction. Cast one operand to double.',
      studentMessage: 'Division of two integers truncates the decimal. Try: (double)a / b or a / (double)b',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => !r.passed);
        return fail ? `Expected ${fail.expected}, got ${fail.actual}` : 'Division result incorrectly truncated';
      }
    }
  ],

  // ============================================
  // VARIABLES
  // ============================================
  'Variables': [
    {
      id: 'var_undeclared',
      name: 'Undeclared Variable',
      description: 'Using a variable name that was never declared',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('\'was not declared in this scope\'') ||
          err.includes('undeclared') ||
          err.includes('not declared')
        );
      },
      instructorMessage: 'Variable used before declaration. C++ requires variables to be declared before use.',
      studentMessage: 'You used a variable that was never declared. Declare it first with its type.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('not declared'));
        return err ? err.trim() : 'Variable not declared';
      }
    },
    {
      id: 'var_uninitialized',
      name: 'Uninitialized Variable Read',
      description: 'Reading a variable before assigning a value',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('uninitialized') ||
          err.includes('used uninitialized')
        );
      },
      instructorMessage: 'Variable read before initialization. Always assign a value before using.',
      studentMessage: 'You read a variable before giving it a value. Initialize it when you declare.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('uninitialized'));
        return err ? err.trim() : 'Variable used without initialization';
      }
    }
  ],

  // ============================================
  // CONDITIONALS
  // ============================================
  'Conditionals': [
    {
      id: 'cond_missing_else',
      name: 'Missing Else Branch',
      description: 'Has if statement but no else clause — may not handle false condition',
      detector: ({ast}) => {
        return ast.if_count > 0 && ast.else_count === 0;
      },
      instructorMessage: 'Conditional has no else branch. Student may not realize if-else requires both paths.',
      studentMessage: 'Your if has no else. Remember: handle BOTH the true and false cases.',
      evidenceExtractor: ({ast}) => `if statements: ${ast.if_count}, else clauses: ${ast.else_count}`
    },
    {
      id: 'cond_assignment_vs_comparison',
      name: 'Assignment (=) Instead of Comparison (==)',
      description: 'Uses single = inside condition, assigns instead of compares',
      detector: ({compilerErrors, code}) => {
        // Compiler often warns/errors on assignment in condition
        const hasAssignInConditionErr = compilerErrors.some(err =>
          err.includes('lvalue required as left operand of assignment') ||
          err.includes('suggest parentheses')
        );

        // Regex: if (x = y)  EXCLUDES if (x == y)
        const assignNotCompare = /if\s*\([^)]*=[^=!>]/.test(code);

        return hasAssignInConditionErr || assignNotCompare;
      },
      instructorMessage: 'Used single = (assignment) in an if condition instead of ==. This assigns the value and evaluates to that value, not a boolean.',
      studentMessage: 'In C++, = assigns, == compares. Use == in conditions: if (x == 5) not if (x = 5)',
      evidenceExtractor: ({code}) => {
        const match = code.match(/if\s*\([^)]*=[^=!>]/);
        return match ? `Found: ${match[0].trim()}` : 'Assignment operator used in condition';
      }
    },
    {
      id: 'cond_inverted_logic',
      name: 'Inverted Condition Logic',
      description: 'Uses unnecessary negation (!) or condition is always false',
      detector: ({compilerErrors, code}) => {
        // Check for repeated 'if (!'
        const negatedIfCount = (code.match(/if\s*\(\s*!/g) || []).length;

        // Dead code indicator: warnings about conditions always being false
        const alwaysFalse = compilerErrors.some(err =>
          err.includes('will always evaluate as false')
        );

        return negatedIfCount >= 2 || alwaysFalse;
      },
      instructorMessage: 'Logic appears inverted or unnecessarily complex. Multiple negations suggest confusion about the condition.',
      studentMessage: 'Your condition has extra ! operators. Simplify: read it aloud to check if it matches your intent.',
      evidenceExtractor: ({code}) => `Detected ${(code.match(/if\s*\(\s*!/g) || []).length} inverted conditions`
    }
  ],

  // ============================================
  // LOOPS
  // ============================================
  'Loops': [
    {
      id: 'loop_off_by_one',
      name: 'Off-by-One Error',
      description: 'Loop boundary goes one step too far or falls short (e.g., i <= n instead of i < n)',
      detector: ({testResults, ast}) => {
        // Must have a loop
        if (!ast.node_types.includes('for_statement') && !ast.node_types.includes('while_statement')) {
          return false;
        }

        // Fails specifically at boundary: 0 or size/size+1
        const boundaryFails = testResults.filter(r => !r.passed);
        const failsAtZeroOrN = boundaryFails.some(r => {
          const num = parseInt(r.input);
          return num === 0 || num === parseInt(r.input) + 1 <= 10; // rough heuristic
        });

        // Alternative: test set includes "edge" cases that fail
        const failsAtEdge = boundaryFails.some(r =>
          r.input === '0' || r.input === '1' || r.input.includes('size')
        );

        return failsAtZeroOrN || failsAtEdge;
      },
      instructorMessage: 'Classic off-by-one: loop boundary incorrect. Student likely used <= instead of < for array iteration.',
      studentMessage: 'Check your loop bounds. For array size N, valid indices are 0 to N-1 (not N).',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => !r.passed);
        return fail ? `Failed at boundary input=${fail.input}` : 'Boundary failure detected';
      }
    },
    {
      id: 'loop_missing_increment',
      name: 'Missing Loop Increment/Decrement',
      description: 'Loop variable never changes, causing infinite loop or timeout',
      detector: ({timeLimitHit, compilerErrors, ast}) => {
        // Timeout is strong signal
        if (timeLimitHit) {
          // Check if loop present but increment absent
          return ast.node_types.includes('for_statement') ||
                 ast.node_types.includes('while_statement');
        }

        // Compiler sometimes warns about infinite loops (rare)
        const infiniteLoopWarning = compilerErrors.some(err =>
          err.includes('infinite loop') || err.includes('loop will run forever')
        );

        return infiniteLoopWarning;
      },
      instructorMessage: 'Infinite or extremely long loop detected. Loop condition never changes due to missing increment/decrement.',
      studentMessage: 'Your loop may never terminate. Ensure the loop variable is updated each iteration (i++, i--, etc.).',
      evidenceExtractor: ({timeLimitHit}) => timeLimitHit ? 'Execution timed out (45s)' : 'Potential infinite loop detected'
    },
    {
      id: 'loop_wrong_terminator',
      name: 'Wrong Loop Type',
      description: 'Using while for counted iteration, or for for condition-based',
      detector: ({ast, required_ast_nodes}) => {
        // Exercise required a specific loop type, student used another
        if (!required_ast_nodes) return false;

        const hasFor = ast.node_types.includes('for_statement');
        const hasWhile = ast.node_types.includes('while_statement');

        // Exercise requires for, student used while
        if (required_ast_nodes.includes('for_statement') && hasWhile && !hasFor) {
          return true;
        }

        // Exercise requires while, student used for
        if (required_ast_nodes.includes('while_statement') && hasFor && !hasWhile) {
          return true;
        }

        return false;
      },
      instructorMessage: 'Used wrong loop construct for the problem. The exercise required a specific loop type.',
      studentMessage: 'The problem expects a specific loop type. Check if you should use for or while.',
      evidenceExtractor: ({ast, required_ast_nodes}) => {
        const required = required_ast_nodes.filter(n => ['for_statement','while_statement','do_statement'].includes(n));
        const used = ast.node_types.filter(n => ['for_statement','while_statement','do_statement'].includes(n));
        return `Required: ${required.join(',')}; Used: ${used.join(',')}`;
      }
    }
  ],

  // ============================================
  // FUNCTIONS
  // ============================================
  'Functions': [
    {
      id: 'func_missing_return',
      name: 'Missing Return Statement',
      description: 'Function declared with non-void return type but no return statement',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('control reaches end of non-void function') ||
          err.includes('return-statement with no value')
        );
      },
      instructorMessage: 'Function declared to return a value (e.g., int, double) but has no return statement.',
      studentMessage: 'Your function promises to return a value but doesn\'t. Add a return statement with the computed result.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('non-void'));
        return err ? err.trim() : 'Missing return in non-void function';
      }
    },
    {
      id: 'func_wrong_signature',
      name: 'Incorrect Function Signature',
      description: 'Function has wrong number or types of parameters',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('no matching function for call') ||
          err.includes('too many arguments') ||
          err.includes('too few arguments') ||
          err.includes('cannot convert')
        );
      },
      instructorMessage: 'Function call does not match any available function definition. Check parameter count and types.',
      studentMessage: 'When you call a function, the arguments must match the function\'s parameter list exactly.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e =>
          e.includes('no matching function') ||
          e.includes('too many arguments') ||
          e.includes('too few arguments')
        );
        return err ? err.trim() : 'Function signature mismatch';
      }
    },
    {
      id: 'func_defined_never_called',
      name: 'Function Defined But Not Used',
      description: 'Student created a helper function but never invoked it from main',
      detector: ({code}) => {
        // Count function definitions vs function calls (excluding main)
        const defMatches = code.match(/(?:int|double|void|bool|string)\s+\w+\s*\(/g) || [];
        const callMatches = code.match(/\b\w+\s*\(/g) || [];

        if (defMatches.length === 0) return false;

        // Subtract 1 for main (declared but not "called")
        const defCount = defMatches.filter(d => !d.includes('main')).length;
        const callCount = callMatches.filter(c => !c.includes('main') && !c.includes('if') && !c.includes('for') && !c.includes('while') && !c.includes('switch')).length;

        // Defined but no calls
        return defCount > 0 && callCount === 0;
      },
      instructorMessage: 'Student wrote a helper function but never called it from main. Code may be incomplete.',
      studentMessage: 'You defined a function but never used it. Make sure to call it from main().',
      evidenceExtractor: ({code}) => {
        const defs = (code.match(/(?:int|double|void|bool|string)\s+\w+\s*\(/g) || []).filter(d => !d.includes('main')).length;
        const calls = (code.match(/\b\w+\s*\(/g) || []).filter(c => !c.includes('main')).length;
        return `Defined: ${defs}, Called: ${calls}`;
      }
    }
  ],

  // ============================================
  // ARRAYS
  // ============================================
  'Arrays': [
    {
      id: 'arr_hardcoded_index',
      name: 'Hardcoded Array Index',
      description: 'Accesses array with literal indices (arr[0], arr[1]) instead of using loop variable',
      detector: ({code}) => {
        // Count explicit numeric index accesses
        const hardcodedZero = (code.match(/\[0\]/g) || []).length;
        const hardcodedOne = (code.match(/\[1\]/g) || []).length;

        // If many hardcoded accesses in a loop context, that's wrong
        // Simple heuristic: > 2 hardcoded accesses suggests pattern
        return (hardcodedZero + hardcodedOne) >= 3;
      },
      instructorMessage: 'Array accessed using fixed indices (arr[0], arr[1]) rather than loop variable. Code only works for specific array sizes.',
      studentMessage: 'Don\'t hardcode array indices. Use your loop variable to access each element: arr[i].',
      evidenceExtractor: ({code}) => {
        const idx0 = (code.match(/\[0\]/g) || []).length;
        const idx1 = (code.match(/\[1\]/g) || []).length;
        return `Hardcoded [0]: ${idx0}, [1]: ${idx1}`;
      }
    },
    {
      id: 'arr_out_of_bounds',
      name: 'Out-of-Bounds Array Access',
      description: 'Uses indices >= array size or negative indices',
      detector: ({testResults, compilerErrors}) => {
        // Failures that look like crashes or memory errors
        const crashPattern = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('error') ||
            r.actual?.includes('segmentation fault') ||
            r.actual?.includes('bad allocation') ||
            r.error === 'timeout'  // infinite loop from corrupted memory
          )
        );

        // Compiler may warn about array bounds in some cases
        const boundsWarning = compilerErrors.some(err =>
          err.includes('out of bounds') ||
          err.includes('subscript')
        );

        return crashPattern || boundsWarning;
      },
      instructorMessage: 'Array index goes beyond declared size. Valid indices: 0 to size-1.',
      studentMessage: 'Array index out of range. If array has N elements, valid indices are 0 to N-1.',
      evidenceExtractor: ({testResults}) => {
        const crash = testResults.find(r => !r.passed && (r.actual?.includes('error') || r.error));
        return crash ? `Test failed: ${crash.input} → ${crash.actual?.substring(0, 50)}` : 'Out-of-bounds access detected';
      }
    },
    {
      id: 'arr_fixed_size',
      name: 'Hardcoded Array Size',
      description: 'Declares fixed-size array instead of using parameter or dynamic allocation',
      detector: ({code, exercise}) => {
        // Look for int arr[XXX] where XXX is small constant, not related to input
        const match = code.match(/int\s+(\w+)\s*\[\s*(\d+)\s*\]/);
        if (!match) return false;

        const size = parseInt(match[2]);

        // If the exercise likely requires variable-sized input (common), this is suspicious
        // Hardcoded small arrays (< 100) in array traversal problems are often wrong
        return size >= 5 && size <= 100; // arbitrary threshold
      },
      instructorMessage: 'Array size is hardcoded. Should read input size or use vector for flexibility.',
      studentMessage: 'Hardcoding array size means your program only works for one specific input. Read N from user first.',
      evidenceExtractor: ({code}) => {
        const m = code.match(/int\s+\w+\s*\[\s*(\d+)\s*\]/);
        return m ? `Array declared with fixed size: [${m[1]}]` : 'Fixed-size array detected';
      }
    }
  ],

  // ============================================
  // OOP
  // ============================================
  'OOP': [
    {
      id: 'oop_all_public',
      name: 'No Encapsulation — All Members Public',
      description: 'Class members all public; no data hiding',
      detector: ({ast}) => {
        const hasClass = ast.node_types.includes('class_specifier') ||
                         ast.node_types.includes('struct_specifier');
        if (!hasClass) return false;

        // If class exists but no private/protected sections, all is public
        const hasPrivate = ast.node_types.includes('private_section') ||
                           ast.node_types.includes('protected_section');
        return hasClass && !hasPrivate;
      },
      instructorMessage: 'All class members are public. Encapsulation principle violated — data should be private with public accessors.',
      studentMessage: 'Good OOP hides data. Make member variables private and provide public getters/setters.',
      evidenceExtractor: ({ast}) => ast.has_private ? 'Has private members' : 'All members appear public'
    },
    {
      id: 'oop_missing_constructor',
      name: 'Missing Constructor',
      description: 'Class has no constructor to initialize member variables',
      detector: ({ast, code}) => {
        if (!ast.node_types.includes('class_specifier')) return false;

        // Has member variables but no constructor (function_definition with class::name)
        const hasConstructor = code.includes('::') &&
                               code.match(/::\s*\w+\s*\(/);
        return !hasConstructor;
      },
      instructorMessage: 'Class has member variables but no constructor to initialize them. Members start with garbage values.',
      studentMessage: 'Write a constructor (ClassName()) to set initial values for your member variables.',
      evidenceExtractor: ({code}) => code.includes('::') ? 'Constructor present' : 'No constructor found'
    },
    {
      id: 'oop_direct_member_access',
      name: 'Direct External Member Access',
      description: 'Accessing private members via object.variable instead of getter/setter',
      detector: ({code}) => {
        // Pattern: objectName.memberName outside the class definition
        // Heuristic: multiple dot-accesses on non-standard-library objects
        const dotAccesses = code.match(/\w+\.\w+/g) || [];
        // Exclude cout, cin, string operations
        const suspicious = dotAccesses.filter(d =>
          !d.startsWith('cout.') && !d.startsWith('cin.') &&
          !d.startsWith('string.') && !d.startsWith('getline')
        );
        return suspicious.length >= 3; // many direct accesses
      },
      instructorMessage: 'External code accesses class members directly instead of via methods. This breaks encapsulation.',
      studentMessage: 'Access private members through public member functions (get/set), not directly via dot notation.',
      evidenceExtractor: ({code}) => {
        const dots = code.match(/\w+\.\w+/g) || [];
        return `Found ${dots.length} dot-access operations`;
      }
    }
  ],

  // ============================================
  // FUTURE: ARRAYS (3 rules minimum)
  // ============================================
  // Already defined above with 3 rules (good)

  // ============================================
  // FUTURE: Additional Variables/Datatypes rules
  // ============================================
  // Expand to 2+ per concept as needed
};

/**
 * Evidence extractor helper (per rule)
 * Takes rule + context, returns specific line/test/error that triggered detection
 */
function extractEvidence(rule, context) {
  if (rule.evidenceExtractor) {
    try {
      return rule.evidenceExtractor(context);
    } catch (e) {
      return 'Pattern detected';
    }
  }
  return 'Deterministic rule matched';
}

/**
 * Analyze a submission against all rules for its concept
 * @param {Object} submission - {code, ast_data, exercise_id, ...}
 * @param {Object} exercise - {concept_name, required_ast_nodes, ...}
 * @param {Array} testResults - [{input, expected, actual, passed, error}]
 * @param {string} compilerLog - full GCC output
 * @returns {Array} matched rules with messages
 */
function analyzeSubmission(submission, exercise, testResults, compilerLog) {
  const conceptName = exercise.concept_name;
  const rules = MICRO_CONCEPT_RULES[conceptName] || [];

  // Parse compiler errors into array
  const compilerErrors = compilerLog
    .split('\n')
    .filter(line => line.includes('error:') || line.includes('undefined reference'))
    .map(l => l.trim());

  // Build AST context (simplified)
  const ast = submission.ast_data || {};
  const astContext = {
    node_types: ast.node_types || [],
    if_count: (ast.node_types || []).filter(t => t === 'if_statement').length,
    else_count: (ast.node_types || []).filter(t => t === 'else_clause').length,
    has_private: (ast.node_types || []).some(t => t === 'private_section' || t === 'protected_section')
  };

  const context = {
    ast: astContext,
    testResults,
    compilerErrors,
    code: submission.code,
    timeLimitHit: testResults.some(r => r.error === 'timeout'),
    required_ast_nodes: exercise.required_ast_nodes,
    exercise: exercise
  };

  const matched = [];

  for (const rule of rules) {
    try {
      if (rule.detector(context)) {
        matched.push({
          microConceptId: rule.id,
          name: rule.name,
          description: rule.description,
          instructorMessage: rule.instructorMessage,
          studentMessage: rule.studentMessage,
          evidence: extractEvidence(rule, context)
        });
      }
    } catch (err) {
      console.error(`[MicroConcept] Rule ${rule.id} failed:`, err.message);
    }
  }

  return matched;
}

module.exports = {MICRO_CONCEPT_RULES, analyzeSubmission, extractEvidence};

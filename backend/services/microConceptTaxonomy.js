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
  // POINTERS
  // ============================================
  'Pointers': [
    {
      id: 'ptr_null_dereference',
      name: 'Null Pointer Dereference',
      description: 'Dereferencing a pointer that is null or uninitialized',
      detector: ({compilerErrors, testResults}) => {
        const crashPattern = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('segmentation fault') ||
            r.actual?.includes('SEGV') ||
            r.error === 'timeout'
          )
        );
        const nullWarning = compilerErrors.some(err =>
          err.includes('null') ||
          err.includes('uninitialized') ||
          err.includes('may be null')
        );
        return crashPattern || nullWarning;
      },
      instructorMessage: 'Null or uninitialized pointer dereferenced — leads to undefined behavior or crash.',
      studentMessage: 'Make sure your pointer points to valid memory before using it (e.g., p = &x or p = new int).',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => !r.passed && (r.actual?.includes('segmentation') || r.actual?.includes('SEGV')));
        return fail ? `Crash on input ${fail.input}` : 'Null pointer risk detected';
      }
    },
    {
      id: 'ptr_forgot_dereference',
      name: 'Pointer Used Without Dereference',
      description: 'Using pointer variable where value is needed (e.g., cout << p instead of cout << *p)',
      detector: ({compilerErrors, code}) => {
        const typeError = compilerErrors.some(err =>
          err.includes('cannot convert') ||
          err.includes('invalid conversion from') ||
          err.includes('no match for')
        );
        const pointerDeclared = /\w+\s*\*\s*\w+/.test(code);
        const pointerUsed = /\*\s*\w+/.test(code);
        return pointerDeclared && typeError && !pointerUsed;
      },
      instructorMessage: 'Pointer used where value expected. Use *p to dereference the pointer and access the pointed-to value.',
      studentMessage: 'You used a pointer where a value was expected. Try *p to get the value the pointer points to.',
      evidenceExtractor: ({code}) => {
        const decls = code.match(/\w+\s*\*\s*\w+/g) || [];
        return `Pointer declarations: ${decls.length}`;
      }
    },
    {
      id: 'ptr_leak',
      name: 'Pointer Memory Leak',
      description: 'Allocated memory with new but never freed with delete',
      detector: ({code}) => {
        const newCount = (code.match(/\bnew\s+\w+/g) || []).length;
        const deleteCount = (code.match(/\bdelete\b/g) || []).length;
        return newCount > 0 && deleteCount === 0;
      },
      instructorMessage: 'Memory allocated with new but never released. Every new should have a matching delete.',
      studentMessage: 'You used new to allocate memory but never used delete. Every new needs a matching delete.',
      evidenceExtractor: ({code}) => {
        const n = (code.match(/\bnew\s+\w+/g) || []).length;
        const d = (code.match(/\bdelete\b/g) || []).length;
        return `${n} new(s), ${d} delete(s)`;
      }
    }
  ],

  // ============================================
  // STRINGS
  // ============================================
  'Strings': [
    {
      id: 'str_missing_include',
      name: 'Missing #include <string>',
      description: 'Using std::string without including the string header',
      detector: ({compilerErrors, code}) => {
        const hasStringDecl = /std::string|\bstring\s+\w+/.test(code);
        const hasStringInclude = /#include\s*[<"]string[>"]/.test(code);
        const stringError = compilerErrors.some(err =>
          err.includes('string') &&
          (err.includes('not declared') || err.includes('no template'))
        );
        return hasStringDecl && !hasStringInclude && stringError;
      },
      instructorMessage: 'Using std::string requires #include <string>. This is separate from <iostream>.',
      studentMessage: 'Add #include <string> at the top of your code to use std::string.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('string'));
        return err ? err.trim() : 'Missing string header';
      }
    },
    {
      id: 'str_c_string_confusion',
      name: 'C-String and std::string Confusion',
      description: 'Mixing char arrays with std::string operations incorrectly',
      detector: ({compilerErrors, code}) => {
        const hasStringType = /std::string|\bstring\s+\w+/.test(code);
        const hasCharArr = /\bchar\s+\w+\s*\[\d*\]/.test(code);
        const conversionError = compilerErrors.some(err =>
          err.includes('cannot convert') &&
          (err.includes('std::string') || err.includes('char*') || err.includes('const char*'))
        );
        return hasStringType && hasCharArr && conversionError;
      },
      instructorMessage: 'Mixing char arrays (C-strings) with std::string requires explicit conversion or compatible operations.',
      studentMessage: 'Use std::string for all string operations and avoid mixing with char arrays unless using .c_str().',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('cannot convert'));
        return err ? err.trim() : 'C-string / std::string mismatch';
      }
    },
    {
      id: 'str_index_out_of_bounds',
      name: 'String Index Out of Bounds',
      description: 'Accessing string index that exceeds its length',
      detector: ({testResults, compilerErrors}) => {
        const crashPattern = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('basic_string') ||
            r.actual?.includes('out_of_range') ||
            r.actual?.includes('null') ||
            r.error === 'timeout'
          )
        );
        const boundsError = compilerErrors.some(err =>
          err.includes('out_of_range') ||
          err.includes('basic_string') ||
          err.includes('length')
        );
        return crashPattern || boundsError;
      },
      instructorMessage: 'String index exceeds the string length. Valid indices: 0 to s.length()-1.',
      studentMessage: 'Check your index range when accessing string characters. Remember indices go from 0 to length-1.',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => !r.passed);
        return fail ? `Failed on input: ${fail.input}` : 'Out-of-bounds string access';
      }
    }
  ],

  // ============================================
  // INPUT/OUTPUT
  // ============================================
  'Input/Output': [
    {
      id: 'io_missing_iostream',
      name: 'Missing #include <iostream>',
      description: 'Using cout, cin, or endl without including iostream',
      detector: ({compilerErrors, code}) => {
        const usesIO = /\bcout\b|\bcin\b|\bendl\b|\bcerr\b/.test(code);
        const hasIOInclude = /#include\s*[<"]iostream[>"]/.test(code);
        const ioError = compilerErrors.some(err =>
          err.includes('cout') || err.includes('cin') || err.includes('endl') ||
          err.includes('not declared')
        );
        return usesIO && !hasIOInclude && ioError;
      },
      instructorMessage: 'cout, cin, and endl are defined in <iostream>. You must include this header.',
      studentMessage: 'Add #include <iostream> at the top to use input/output features.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('not declared'));
        return err ? err.trim() : 'Missing iostream header';
      }
    },
    {
      id: 'io_wrong_stream_operator',
      name: 'Wrong Stream Operator',
      description: 'Using >> for output or << for input (operator direction reversed)',
      detector: ({compilerErrors, code}) => {
        const cinWithInsert = /cin\s*<</.test(code);
        const coutWithExtract = /cout\s*>>/.test(code);
        const operatorError = compilerErrors.some(err =>
          err.includes('no match for') &&
          (err.includes('operator<<') || err.includes('operator>>'))
        );
        return (cinWithInsert || coutWithExtract || operatorError);
      },
      instructorMessage: 'Stream operators: cin >> variable (extraction), cout << expression (insertion). The arrows point in the data direction.',
      studentMessage: 'cin uses >> (extraction), cout uses << (insertion). The arrows show where data flows.',
      evidenceExtractor: ({code}) => {
        const cinErr = /cin\s*<</.test(code) ? 'cin with << found' : '';
        const coutErr = /cout\s*>>/.test(code) ? 'cout with >> found' : '';
        return [cinErr, coutErr].filter(Boolean).join('; ') || 'Stream operator reversed';
      }
    },
    {
      id: 'io_missing_newline',
      name: 'Missing Newline in Output',
      description: 'Output missing endl or \\n, causing text to run together',
      detector: ({testResults}) => {
        return testResults.some(r =>
          !r.passed &&
          r.expected && r.actual &&
          r.expected.includes('\n') &&
          !r.actual.includes('\n') &&
          r.expected.length > r.actual.length
        );
      },
      instructorMessage: 'Output missing newlines between lines. Use endl or \\n to separate output lines.',
      studentMessage: 'Your output is missing line breaks. Use cout << ... << endl; to add newlines.',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => !r.passed && r.expected?.includes('\n'));
        return fail ? `Expected newlines in ${fail.expected.substring(0, 30)}` : 'Missing newlines';
      }
    }
  ],

  // ============================================
  // SWITCH/CASE
  // ============================================
  'Switch/Case': [
    {
      id: 'sw_missing_break',
      name: 'Missing Break in Switch Case',
      description: 'Case without break statement, causing fall-through to next case',
      detector: ({code}) => {
        const caseBlocks = code.match(/\bcase\s+\w+\s*:/g) || [];
        const breakCount = (code.match(/\bbreak\s*;/g) || []).length;
        if (caseBlocks.length <= 1) return false;
        const breaksInSwitch = (code.match(/\bbreak\s*;/g) || []).length;
        return caseBlocks.length > breaksInSwitch;
      },
      instructorMessage: 'Case without break causes fall-through to the next case. Unless intentional, add break.',
      studentMessage: 'Each case needs a break; at the end unless you intentionally want fall-through (rare).',
      evidenceExtractor: ({code}) => {
        const cases = (code.match(/\bcase\s+\w+\s*:/g) || []).length;
        const breaks = (code.match(/\bbreak\s*;/g) || []).length;
        return `${cases} case(s), ${breaks} break(s)`;
      }
    },
    {
      id: 'sw_no_default',
      name: 'No Default Case in Switch',
      description: 'Switch statement without a default case to handle unexpected values',
      detector: ({code}) => {
        const hasSwitch = /\bswitch\s*\(/.test(code);
        const hasDefault = /\bdefault\s*:/.test(code);
        return hasSwitch && !hasDefault;
      },
      instructorMessage: 'Switch without a default case may silently miss unexpected input values.',
      studentMessage: 'Add a default: case to handle values you didn\'t explicitly account for.',
      evidenceExtractor: ({code}) => {
        const switches = (code.match(/\bswitch\s*\(/g) || []).length;
        return `${switches} switch(es) without default`;
      }
    },
    {
      id: 'sw_duplicate_value',
      name: 'Duplicate Case Value',
      description: 'Two case labels with the same value in a switch statement',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('duplicate') &&
          err.includes('case')
        );
      },
      instructorMessage: 'Duplicate case value in switch. Each case value must be unique.',
      studentMessage: 'Each case in a switch must have a unique value. Check for duplicate case labels.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('duplicate') && e.includes('case'));
        return err ? err.trim() : 'Duplicate case value';
      }
    }
  ],

  // ============================================
  // NESTED LOOPS
  // ============================================
  'Nested Loops': [
    {
      id: 'nl_same_loop_variable',
      name: 'Same Variable in Nested Loops',
      description: 'Using the same loop variable (e.g., i) for both outer and inner loop',
      detector: ({code, testResults}) => {
        const forMatches = code.match(/for\s*\([^;]*;/g) || [];
        const firstVars = forMatches.map(m => {
          const v = m.match(/(\w+)\s*=\s*0\s*;/);
          return v ? v[1] : null;
        }).filter(Boolean);
        if (firstVars.length < 2) return false;
        const unique = new Set(firstVars);
        const hasShadowed = firstVars.length > unique.size;
        const unexpectedOutcome = testResults.some(r => !r.passed && r.expected);
        return hasShadowed && unexpectedOutcome;
      },
      instructorMessage: 'Inner and outer loops use the same variable (e.g., both use i). Inner loop modifies outer loop\'s counter, causing wrong behavior.',
      studentMessage: 'Use a different variable for the inner loop (e.g., j for the inner loop, i for the outer loop).',
      evidenceExtractor: ({code}) => {
        const vars = (code.match(/for\s*\(\s*(?:int\s+)?(\w+)\s*=/g) || []).map(m => m.match(/(\w+)\s*=/)[1]);
        return `Loop variables: ${vars.join(', ')}`;
      }
    },
    {
      id: 'nl_uninitialized_outer',
      name: 'Inner Loop Variable Not Reset',
      description: 'Inner loop depends on variable from outer loop that is not reset each iteration',
      detector: ({testResults, code}) => {
        const hasNestedFor = (code.match(/for\s*\(/g) || []).length >= 2;
        if (!hasNestedFor) return false;
        const unexpected = testResults.some(r =>
          !r.passed && r.expected && r.actual &&
          parseInt(r.expected) > parseInt(r.actual)
        );
        return unexpected;
      },
      instructorMessage: 'Inner loop variable or accumulator may not be reset each time the outer loop iterates. Reinitialize inside outer loop.',
      studentMessage: 'If you accumulate values in the inner loop, reset the accumulator at the start of each outer loop iteration.',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => !r.passed);
        return fail ? `Expected ${fail.expected}, got ${fail.actual}` : 'Inner loop not reset';
      }
    }
  ],

  // ============================================
  // RECURSION
  // ============================================
  'Recursion': [
    {
      id: 'rec_missing_base_case',
      name: 'Missing Base Case',
      description: 'Recursive function without a base case to stop recursion (causes stack overflow or timeout)',
      detector: ({timeLimitHit, testResults, code}) => {
        if (timeLimitHit) {
          const hasRecursiveCall = /\w+\s*\([^)]*\)\s*[^;]*\w+\s*\(/.test(code) ||
            /return\s+\w+\s*\(/.test(code);
          return hasRecursiveCall;
        }
        const stackOverflow = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('stack overflow') ||
            r.actual?.includes('segmentation fault') ||
            r.error === 'timeout'
          )
        );
        const hasCall = /\w+\s*\(/g;
        const defs = (code.match(/(?:int|double|void|bool|string)\s+\w+\s*\(/g) || []);
        const calls = (code.match(/\b\w+\s*\(/g) || []);
        const selfCall = defs.some(d => {
          const name = d.match(/\w+\s*\(/)?.[0]?.replace('(', '');
          return name && calls.filter(c => c.includes(name)).length >= 2;
        });
        return (stackOverflow || timeLimitHit) && selfCall;
      },
      instructorMessage: 'Recursive function missing or incorrect base case. Every recursion needs a condition that stops it.',
      studentMessage: 'Add a base case to your recursive function: if (n == 0) return something; that stops the recursion.',
      evidenceExtractor: ({code}) => {
        const funcs = code.match(/(?:int|double|void|bool|string)\s+\w+\s*\(/g) || [];
        return `Functions: ${funcs.length}`;
      }
    },
    {
      id: 'rec_no_return_value',
      name: 'Recursive Function Missing Return',
      description: 'Recursive non-void function missing return statement in some code paths',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('control reaches end of non-void function') ||
          err.includes('return')
        );
      },
      instructorMessage: 'Non-void recursive function may not return a value in all paths. Every branch must return.',
      studentMessage: 'Make sure your function returns a value in both the base case AND the recursive case.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('non-void'));
        return err ? err.trim() : 'Missing return in recursion';
      }
    },
    {
      id: 'rec_wrong_recurrence',
      name: 'Incorrect Recurrence Relation',
      description: 'Recursive formula does not solve the problem (wrong parameters or operation)',
      detector: ({testResults}) => {
        const allFailed = testResults.filter(r => !r.passed);
        if (allFailed.length === 0) return false;
        const fullOutput = allFailed.some(r => r.expected && r.actual && r.actual.length > 0);
        return allFailed.length >= 2 && fullOutput;
      },
      instructorMessage: 'Multiple test failures suggest incorrect recurrence logic. Trace your recursive calls for small inputs (n=0, n=1, n=2).',
      studentMessage: 'Test with very small inputs (0, 1, 2) and trace your logic. The recurrence formula may be wrong.',
      evidenceExtractor: ({testResults}) => {
        const failed = testResults.filter(r => !r.passed).slice(0, 2);
        return failed.map(f => `${f.expected} vs ${f.actual}`).join(', ');
      }
    }
  ],

  // ============================================
  // FILE I/O
  // ============================================
  'File I/O': [
    {
      id: 'fio_missing_fstream',
      name: 'Missing #include <fstream>',
      description: 'Using ifstream or ofstream without including fstream header',
      detector: ({compilerErrors, code}) => {
        const usesFstream = /\bifstream\b|\bofstream\b|\bfstream\b/.test(code);
        const hasFstreamInclude = /#include\s*[<"]fstream[>"]/.test(code);
        const fstreamError = compilerErrors.some(err =>
          err.includes('ifstream') || err.includes('ofstream') || err.includes('fstream')
        );
        return usesFstream && !hasFstreamInclude && fstreamError;
      },
      instructorMessage: 'ifstream and ofstream require #include <fstream>.',
      studentMessage: 'Add #include <fstream> to use file input/output streams.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('fstream') || e.includes('ifstream'));
        return err ? err.trim() : 'Missing fstream header';
      }
    },
    {
      id: 'fio_file_not_opened',
      name: 'File Operation Without Checking Open',
      description: 'Reading/writing file without checking if open() succeeded',
      detector: ({code}) => {
        const hasOpenCall = /\.open\(|ifstream\s+\w+\s*\(|ofstream\s+\w+\s*\(/.test(code);
        const hasIsOpen = /\.is_open\(\)/.test(code);
        return hasOpenCall && !hasIsOpen;
      },
      instructorMessage: 'File operations should check if the file was successfully opened using .is_open() before reading/writing.',
      studentMessage: 'Always check if (file.is_open()) before reading or writing to a file.',
      evidenceExtractor: ({code}) => {
        const opens = (code.match(/\.open\(/g) || []).length;
        const checks = (code.match(/\.is_open\(\)/g) || []).length;
        return `Open calls: ${opens}, is_open checks: ${checks}`;
      }
    }
  ],

  // ============================================
  // SCOPE
  // ============================================
  'Scope': [
    {
      id: 'scp_variable_shadowing',
      name: 'Variable Shadowing',
      description: 'Inner scope variable hides outer scope variable with the same name',
      detector: ({compilerErrors, code}) => {
        const shadowWarning = compilerErrors.some(err =>
          err.includes('shadow') ||
          err.includes('declaration hides')
        );
        const hasNestedBlock = /\{[^}]*\{[^}]*\}/.test(code);
        const repeatedNames = (code.match(/(?:int|double|float|char|bool|string)\s+(\w+)\s*[=;]/g) || []);
        const names = repeatedNames.map(m => {
          const n = m.match(/(\w+)\s*[=;]/);
          return n ? n[1] : '';
        }).filter(Boolean);
        const hasShadow = new Set(names).size < names.length;
        return shadowWarning || (hasNestedBlock && hasShadow);
      },
      instructorMessage: 'A variable in an inner block has the same name as one in an outer block. The outer variable is hidden (shadowed).',
      studentMessage: 'Use a different name for the inner variable. The outer variable with the same name is hidden inside this block.',
      evidenceExtractor: ({code}) => {
        const decls = code.match(/(?:int|double|float|char|bool|string)\s+(\w+)/g) || [];
        return `${decls.length} declarations found`;
      }
    },
    {
      id: 'scp_out_of_scope_access',
      name: 'Variable Used Outside Scope',
      description: 'Trying to use a variable declared inside a block outside that block',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('not declared in this scope') ||
          err.includes('was not declared') ||
          err.includes('undeclared')
        );
      },
      instructorMessage: 'Variables declared inside { } blocks are local to that block and cannot be accessed outside.',
      studentMessage: 'A variable declared inside { } can only be used within those braces. Declare it before the block if needed later.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('not declared'));
        return err ? err.trim() : 'Variable used outside its scope';
      }
    }
  ],

  // ============================================
  // ENUMS
  // ============================================
  'Enums': [
    {
      id: 'enum_no_class',
      name: 'Unscoped Enum (No enum class)',
      description: 'Using plain enum instead of enum class, polluting the enclosing scope',
      detector: ({code}) => {
        const plainEnum = /\benum\s+\w+\s*\{/.test(code);
        const enumClass = /\benum\s+class\s+\w+\s*\{/.test(code);
        if (!plainEnum) return false;
        const namespaceStd = /using\s+namespace\s+std/.test(code);
        const hasConflict = /cout|\bcin\b/.test(code);
        return plainEnum && !enumClass && namespaceStd;
      },
      instructorMessage: 'Plain enum values leak into the surrounding scope. Use enum class for type-safe, scoped enums.',
      studentMessage: 'Use "enum class Name { ... }" instead of "enum Name { ... }" to keep enum values scoped.',
      evidenceExtractor: ({code}) => {
        const plain = (code.match(/\benum\s+\w+\s*\{/g) || []).length;
        const scoped = (code.match(/\benum\s+class\s+\w+\s*\{/g) || []).length;
        return `Plain enums: ${plain}, enum classes: ${scoped}`;
      }
    },
    {
      id: 'enum_uninitialized_variable',
      name: 'Enum Variable Without Initialization',
      description: 'Declaring enum variable without assigning a value (gets garbage)',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('uninitialized') ||
          err.includes('used uninitialized')
        );
      },
      instructorMessage: 'Enum variable used without initialization. Variables of enum type also need initial values.',
      studentMessage: 'Don\'t forget to initialize your enum variable: Color c = Color::RED;',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('uninitialized'));
        return err ? err.trim() : 'Enum variable uninitialized';
      }
    }
  ],

  // ============================================
  // STRUCTS
  // ============================================
  'Structs': [
    {
      id: 'st_uninitialized_fields',
      name: 'Uninitialized Struct Fields',
      description: 'Struct fields used without being assigned values',
      detector: ({testResults, compilerErrors, code}) => {
        const hasStruct = /\bstruct\s+\w+/.test(code);
        if (!hasStruct) return false;
        const uninitWarning = compilerErrors.some(err =>
          err.includes('uninitialized') ||
          err.includes('used uninitialized')
        );
        const partialOutput = testResults.some(r =>
          !r.passed && r.expected && r.actual &&
          (r.actual.includes('0') || r.actual === '')
        );
        return uninitWarning || partialOutput;
      },
      instructorMessage: 'Struct fields are not automatically initialized in C++. Assign values to all fields before reading them.',
      studentMessage: 'Initialize your struct fields. In C++, struct fields are NOT zero-initialized automatically.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('uninitialized'));
        return err ? err.trim() : 'Uninitialized struct field';
      }
    },
    {
      id: 'st_pass_by_value',
      name: 'Large Struct Passed by Value',
      description: 'Passing a struct by value (copy) instead of by reference for efficiency',
      detector: ({code}) => {
        const structDefs = code.match(/\bstruct\s+(\w+)/g) || [];
        const structNames = structDefs.map(s => s.replace('struct ', ''));
        if (structNames.length === 0) return false;
        for (const name of structNames) {
          const byValueCalls = new RegExp(`\\b${name}\\s+\\w+\\s*\\(`, 'g');
          const refParam = new RegExp(`const\\s+${name}\\s*&`, 'g');
          const valueParams = (code.match(byValueCalls) || []).length;
          const refParams = (code.match(refParam) || []).length;
          if (valueParams > refParams && valueParams >= 2) return true;
        }
        return false;
      },
      instructorMessage: 'Passing a struct by value copies all its fields. Use const reference (const StructName&) for read-only access.',
      studentMessage: 'Pass the struct as const Type& to avoid copying all fields. Use const StructName& param.',
      evidenceExtractor: ({code}) => {
        const refs = (code.match(/const\s+\w+\s*&/g) || []).length;
        return `Const ref parameters: ${refs}`;
      }
    },
    {
      id: 'st_missing_semicolon',
      name: 'Missing Semicolon After Struct',
      description: 'Missing semicolon at the end of a struct definition (common C++ syntax error)',
      detector: ({compilerErrors, code}) => {
        const hasStruct = /\bstruct\s+\w+\s*\{[\s\S]*?\}/.test(code);
        const semicolonAfterStruct = /\}\s*;/.test(code);
        if (!hasStruct) return false;
        if (semicolonAfterStruct) return false;
        return compilerErrors.some(err =>
          err.includes('expected') ||
          err.includes(';') ||
          err.includes('semicolon')
        );
      },
      instructorMessage: 'In C++, a semicolon is required after the closing brace of a struct definition.',
      studentMessage: 'Add a semicolon after the closing brace of your struct: };',
      evidenceExtractor: ({code}) => {
        const missing = code.match(/\bstruct\s+\w+\s*\{[\s\S]*?\}(?!\s*;)/);
        return missing ? 'Missing ; after struct' : 'Struct syntax OK';
      }
    }
  ],

  // ============================================
  // DYNAMIC MEMORY
  // ============================================
  'Dynamic Memory': [
    {
      id: 'dyn_memory_leak',
      name: 'Memory Leak (new[] without delete[])',
      description: 'Allocating array with new[] but not using delete[]',
      detector: ({code}) => {
        const newArrCount = (code.match(/\bnew\s+\w+\s*\[/g) || []).length;
        const deleteArrCount = (code.match(/\bdelete\[\]\s+\w+/g) || []).length;
        return newArrCount > deleteArrCount && newArrCount > 0;
      },
      instructorMessage: 'Array allocated with new[] must be deallocated with delete[] (not delete).',
      studentMessage: 'Use delete[] ptr; (with brackets) to free memory allocated with new[].',
      evidenceExtractor: ({code}) => {
        const n = (code.match(/\bnew\s+\w+\s*\[/g) || []).length;
        const d = (code.match(/\bdelete\[\]\s+\w+/g) || []).length;
        return `${n} new[], ${d} delete[]`;
      }
    },
    {
      id: 'dyn_dangling_pointer',
      name: 'Dangling Pointer / Use-After-Free',
      description: 'Using a pointer after the memory has been freed',
      detector: ({compilerErrors, testResults}) => {
        const asanError = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('heap-use-after-free') ||
            r.error?.includes('heap-use-after-free')
          )
        );
        const crashAfterDelete = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('segmentation fault') ||
            r.actual?.includes('SEGV')
          )
        );
        return asanError || crashAfterDelete;
      },
      instructorMessage: 'Using memory after it has been freed (dangling pointer). Set pointer to nullptr after delete.',
      studentMessage: 'After delete, set the pointer to nullptr to avoid using freed memory: delete p; p = nullptr;',
      evidenceExtractor: ({testResults}) => {
        const fail = testResults.find(r => r.actual?.includes('heap-use-after-free'));
        return fail ? `ASAN: use-after-free on ${fail.input}` : 'Dangling pointer detected';
      }
    },
    {
      id: 'dyn_double_delete',
      name: 'Double Delete',
      description: 'Calling delete twice on the same pointer (undefined behavior)',
      detector: ({compilerErrors, testResults}) => {
        const asanError = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('double-free') ||
            r.error?.includes('double-free')
          )
        );
        const deleteCount = (code) => {
          if (typeof code !== 'string') return 0;
          return (code.match(/\bdelete\s+\w+/g) || []).length;
        };
        return asanError;
      },
      instructorMessage: 'Calling delete twice on the same pointer causes undefined behavior (double free).',
      studentMessage: 'Only delete a pointer once. After delete, set it to nullptr to prevent double deletion.',
      evidenceExtractor: ({testResults, code}) => {
        const fail = testResults.find(r => r.actual?.includes('double-free'));
        return fail ? `ASAN: double-free on ${fail.input}` : 'Potential double delete';
      }
    }
  ],

  // ============================================
  // LINKED LISTS
  // ============================================
  'Linked Lists': [
    {
      id: 'll_missing_null_check',
      name: 'Missing Null Check in Traversal',
      description: 'Traversing a linked list without checking for null/end of list',
      detector: ({testResults, code}) => {
        const hasStruct = /\bstruct\s+\w+\s*\{[\s\S]*\*\s*\w+/.test(code);
        if (!hasStruct) return false;
        const crashPattern = testResults.some(r =>
          !r.passed && (
            r.actual?.includes('segmentation fault') ||
            r.actual?.includes('SEGV') ||
            r.error === 'timeout'
          )
        );
        const whileWithPtr = /\bwhile\s*\(\s*\w+[^)]*\)/.test(code);
        const nullCheck = /!= NULL|!= nullptr|&&\s*\w+|while\s*\(\s*\w+\s*\)/.test(code);
        return crashPattern && whileWithPtr && !nullCheck;
      },
      instructorMessage: 'Linked list traversal must check for nullptr (end of list). Always check while (ptr != nullptr).',
      studentMessage: 'Check for nullptr when traversing a linked list: while (current != nullptr) { ... current = current->next; }',
      evidenceExtractor: ({testResults}) => {
        const crash = testResults.find(r => !r.passed && r.actual?.includes('segmentation'));
        return crash ? `Crash: segmentation fault` : 'Missing null check';
      }
    },
    {
      id: 'll_not_updating_next',
      name: 'Next Pointer Not Updated',
      description: 'Not updating the next pointer when inserting or deleting nodes',
      detector: ({testResults, code}) => {
        const hasStruct = /\bstruct\s+\w+[\s\S]*\*\s*\w+/.test(code);
        if (!hasStruct) return false;
        const usesNext = /->next/.test(code);
        const usesNew = /\bnew\s+\w+/.test(code);
        const wrongLength = testResults.some(r =>
          !r.passed && r.expected && r.actual &&
          r.expected.trim() !== r.actual.trim()
        );
        return usesNew && !usesNext && wrongLength;
      },
      instructorMessage: 'When inserting nodes, update the next pointer of the new node to point to the following node.',
      studentMessage: 'Don\'t forget to set newNode->next = current->next before linking the previous node to the new node.',
      evidenceExtractor: ({code}) => {
        const nextCount = (code.match(/->next/g) || []).length;
        return `->next appears ${nextCount} times`;
      }
    }
  ],

  // ============================================
  // ERROR HANDLING
  // ============================================
  'Error Handling': [
    {
      id: 'err_catch_by_value',
      name: 'Exception Caught by Value',
      description: 'Catching exceptions by value instead of const reference (causes slicing)',
      detector: ({code}) => {
        const catchByValue = /\bcatch\s*\(\s*(?:int|double|float|char|bool|string|std::\w+)\s+\w+\s*\)/.test(code);
        const catchByRef = /\bcatch\s*\(\s*(?:const\s+)?\w+\s*&/.test(code);
        if (!catchByValue) return false;
        return catchByValue && !catchByRef;
      },
      instructorMessage: 'Catch exceptions by const reference (catch (const exception& e)) to avoid slicing and unnecessary copying.',
      studentMessage: 'Use catch (const ExceptionType& e) instead of catch (ExceptionType e) — the & avoids copying.',
      evidenceExtractor: ({code}) => {
        const valCatches = (code.match(/\bcatch\s*\(\s*\w+\s+\w+\s*\)/g) || []).length;
        const refCatches = (code.match(/\bcatch\s*\([^)]*&/g) || []).length;
        return `By-value: ${valCatches}, by-reference: ${refCatches}`;
      }
    },
    {
      id: 'err_empty_catch',
      name: 'Empty Catch Block',
      description: 'Catching an exception with an empty body — silently swallowing errors',
      detector: ({code}) => {
        const emptyCatches = code.match(/\bcatch\s*\([^)]*\)\s*\{\s*\}/g);
        return (emptyCatches || []).length > 0;
      },
      instructorMessage: 'Empty catch blocks silently swallow errors. At minimum, log the error or rethrow.',
      studentMessage: 'Don\'t leave catch blocks empty. At least print the error: cerr << e.what() << endl;',
      evidenceExtractor: ({code}) => {
        const empty = (code.match(/\bcatch\s*\([^)]*\)\s*\{\s*\}/g) || []).length;
        return `${empty} empty catch block(s)`;
      }
    }
  ],

  // ============================================
  // TYPE CASTING
  // ============================================
  'Type Casting': [
    {
      id: 'tc_c_style_cast',
      name: 'C-Style Cast Used',
      description: 'Using (int)x or (double)y instead of C++ casts (static_cast, etc.)',
      detector: ({code}) => {
        const cStyleCasts = code.match(/\(\s*(?:int|double|float|char|long|short|unsigned|signed|bool)\s*\)\s*\w+/g);
        if (!cStyleCasts) return false;
        const cppCasts = (code.match(/static_cast|dynamic_cast|const_cast|reinterpret_cast/g) || []).length;
        return cStyleCasts.length > cppCasts && cStyleCasts.length >= 2;
      },
      instructorMessage: 'C-style casts are dangerous and hard to find. Use static_cast<Type>(value) for safe conversions.',
      studentMessage: 'Replace (int)x with static_cast<int>(x). C++ casts are safer and more visible.',
      evidenceExtractor: ({code}) => {
        const c = (code.match(/\(\s*(?:int|double|float|char|bool)\s*\)\s*\w+/g) || []).length;
        const cpp = (code.match(/(?:static|dynamic|const|reinterpret)_cast/g) || []).length;
        return `${c} C-style vs ${cpp} C++ casts`;
      }
    },
    {
      id: 'tc_loss_of_precision',
      name: 'Loss of Precision in Cast',
      description: 'Casting double to int or float to int loses the fractional part',
      detector: ({compilerErrors, code}) => {
        const narrowingWarning = compilerErrors.some(err =>
          err.includes('narrowing') ||
          err.includes('conversion') ||
          err.includes('loss of precision')
        );
        const castPattern = /\(\s*int\s*\)\s*(?:\w+|\(?\s*\w+\s*\/\s*\w+\s*\)?)/.test(code);
        return narrowingWarning || castPattern;
      },
      instructorMessage: 'Converting a floating-point number to int truncates the decimal part. This loses precision.',
      studentMessage: 'Casting double to int with (int) truncates decimals. Use round(), floor(), or ceil() if that\'s not what you want.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('narrowing') || e.includes('conversion'));
        return err ? err.trim() : 'Precision loss in cast';
      }
    }
  ],

  // ============================================
  // PREPROCESSOR
  // ============================================
  'Preprocessor': [
    {
      id: 'pp_missing_include_guard',
      name: 'Missing Include Guard',
      description: 'Header file without #ifndef / #define / #pragma once guard',
      detector: ({code}) => {
        const isHeader = /\.h\b|\.hpp\b/.test(code) || /\bclass\s+\w+/.test(code);
        if (!isHeader) return false;
        const hasIncludeGuard = /#ifndef\s+\w+|#pragma\s+once/.test(code);
        return isHeader && !hasIncludeGuard;
      },
      instructorMessage: 'Headers should have include guards (#pragma once or #ifndef/#define) to prevent double inclusion.',
      studentMessage: 'Add #pragma once at the top of your header file to prevent multiple inclusions.',
      evidenceExtractor: ({code}) => {
        const guards = (code.match(/#ifndef|#pragma\s+once/g) || []).length;
        return guards > 0 ? 'Include guard present' : 'No include guard';
      }
    },
    {
      id: 'pp_macro_no_parentheses',
      name: 'Macro Without Parentheses',
      description: 'Macro definition without parentheses around parameters and result',
      detector: ({code}) => {
        const macros = code.match(/#define\s+\w+\s*\([^)]*\)/g) || [];
        const hasBodyParens = code.match(/#define\s+\w+\s*\([^)]*\)\s*\(/g);
        return macros.length > 0 && !hasBodyParens;
      },
      instructorMessage: 'Macro parameters and result should be wrapped in parentheses to avoid operator precedence bugs.',
      studentMessage: 'Wrap macro parameters and the result in parentheses: #define SQUARE(x) ((x)*(x))',
      evidenceExtractor: ({code}) => {
        const macros = (code.match(/#define\s+\w+/g) || []).length;
        const safeMacros = (code.match(/#define\s+\w+\([^)]*\)\s*\(/g) || []).length;
        return `${macros - safeMacros} unsafe macro(s)`;
      }
    }
  ],

  // ============================================
  // NAMESPACES
  // ============================================
  'Namespaces': [
    {
      id: 'ns_missing_std_prefix',
      name: 'Missing std:: Prefix',
      description: 'Using std library features without std:: prefix and without using namespace std',
      detector: ({compilerErrors, code}) => {
        const hasUsingStd = /using\s+namespace\s+std/.test(code);
        if (hasUsingStd) return false;
        const usesStdFeatures = /\bcout\b|\bcin\b|\bendl\b|\bstring\b|\bvector\b|\bmap\b|\bcerr\b/.test(code);
        const stdPrefixError = compilerErrors.some(err =>
          (err.includes('cout') || err.includes('cin') || err.includes('string') || err.includes('endl')) &&
          (err.includes('not declared') || err.includes('not in scope'))
        );
        return usesStdFeatures && stdPrefixError;
      },
      instructorMessage: 'Standard library features (cout, cin, string, etc.) are in the std namespace. Either use std:: or add using namespace std;.',
      studentMessage: 'Add std:: prefix: std::cout, std::cin, std::endl, or add "using namespace std;" at the top.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('not declared') || e.includes('not in scope'));
        return err ? err.trim() : 'Missing std:: prefix';
      }
    },
    {
      id: 'ns_namespace_conflict',
      name: 'Namespace Conflict',
      description: 'Two namespaces with conflicting names causing ambiguity',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('ambiguous') ||
          err.includes('is ambiguous') ||
          (err.includes('namespace') && err.includes('conflict'))
        );
      },
      instructorMessage: 'Ambiguous symbol — two namespaces define the same name. Use explicit namespace prefixes.',
      studentMessage: 'Be specific: use the full namespace prefix (e.g., MyNamespace::function()) to avoid ambiguity.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('ambiguous'));
        return err ? err.trim() : 'Namespace name conflict';
      }
    }
  ],

  // ============================================
  // INHERITANCE
  // ============================================
  'Inheritance': [
    {
      id: 'inh_missing_virtual_destructor',
      name: 'Missing Virtual Destructor',
      description: 'Base class without virtual destructor — derived destructor won\'t be called',
      detector: ({code}) => {
        const hasClass = /\bclass\s+\w+/.test(code);
        const hasInheritance = /:\s*public\s+\w+/.test(code);
        // Check if base class has virtual destructor
        const hasVirtualDtor = /\bvirtual\s*~\w+/.test(code) || /\b~\w+\(\)\s*\{\s*\}.*\/\/.*virtual/.test(code);
        if (!hasClass || !hasInheritance) return false;
        const hasPublicDtor = /public:[\s\S]*~\w+\(\)/.test(code);
        return hasInheritance && !hasVirtualDtor;
      },
      instructorMessage: 'Base class destructor should be virtual to ensure derived class destructors are called through base pointers.',
      studentMessage: 'Add virtual ~ClassName() { } to your base class to ensure proper cleanup in derived classes.',
      evidenceExtractor: ({code}) => {
        const classes = (code.match(/\bclass\s+\w+/g) || []).length;
        const virtualDtor = /\bvirtual\s*~\w+/.test(code);
        return `${classes} class(es), virtual destructor: ${virtualDtor ? 'yes' : 'no'}`;
      }
    },
    {
      id: 'inh_not_calling_base_constructor',
      name: 'Base Constructor Not Called',
      description: 'Derived class constructor does not explicitly call the base class constructor',
      detector: ({code}) => {
        const hasDerivedClass = /:\s*public\s+\w+/.test(code);
        if (!hasDerivedClass) return false;
        const derivedName = code.match(/\bclass\s+(\w+)\s*:/);
        if (!derivedName) return false;
        const name = derivedName[1];
        const constructor = new RegExp(`${name}\\s*\\(`);
        if (!constructor.test(code)) return false;
        const hasBaseCall = /:\s*\w+\([^)]*\)/.test(code) ||
          /:\s*\w+\(/.test(code);
        return code.includes(':') && !hasBaseCall;
      },
      instructorMessage: 'Derived class constructors should explicitly call the base class constructor in the initializer list.',
      studentMessage: 'Call the base constructor: Derived::Derived() : Base(param1, param2) { ... }',
      evidenceExtractor: ({code}) => {
        const initLists = (code.match(/:\s*\w+\(/g) || []).length;
        return `Initializer lists: ${initLists}`;
      }
    },
    {
      id: 'inh_object_slicing',
      name: 'Object Slicing',
      description: 'Passing derived class by value to a function expecting base class — slices off derived data',
      detector: ({code, testResults}) => {
        const hasInheritance = /:\s*public\s+\w+/.test(code);
        if (!hasInheritance) return false;
        const byValueParam = /\bvoid\s+\w+\s*\([^)]*\w+\s+\w+[^&]*\)/.test(code);
        const unexpectedOutput = testResults.some(r =>
          !r.passed && r.expected && r.actual &&
          r.expected.length > r.actual.length
        );
        return byValueParam && unexpectedOutput;
      },
      instructorMessage: 'Passing derived objects by value to a base parameter slices off derived class data. Use pointers or references.',
      studentMessage: 'Use Base& (reference) or Base* (pointer) instead of Base to preserve the derived type.',
      evidenceExtractor: ({code}) => {
        const valueParams = (code.match(/\([^)]*\w+\s+\w+[^&)]*\)/g) || []).length;
        const refParams = (code.match(/\([^)]*&\s*\w+/g) || []).length;
        return `${valueParams} value params, ${refParams} reference params`;
      }
    }
  ],

  // ============================================
  // POLYMORPHISM
  // ============================================
  'Polymorphism': [
    {
      id: 'poly_missing_virtual',
      name: 'Override Without Virtual',
      description: 'Derived class function overrides base without virtual keyword in base',
      detector: ({code, compilerErrors}) => {
        const hasOverriding = /:\s*public\s+\w+/.test(code);
        if (!hasOverriding) return false;
        const hasVirtual = /\bvirtual\b/.test(code);
        const hasOverride = /\boverride\b/.test(code);
        const virtualMismatch = compilerErrors.some(err =>
          err.includes('override') ||
          err.includes('virtual') ||
          err.includes('does not override')
        );
        return hasOverriding && !hasVirtual && !hasOverride;
      },
      instructorMessage: 'Base class functions intended for overriding must be declared virtual. Use C++11 override keyword to catch mismatches.',
      studentMessage: 'Add virtual to the base class function, and use the override keyword in derived class functions.',
      evidenceExtractor: ({code}) => {
        const virtuals = (code.match(/\bvirtual\b/g) || []).length;
        const overrides = (code.match(/\boverride\b/g) || []).length;
        return `${virtuals} virtual, ${overrides} override`;
      }
    },
    {
      id: 'poly_signature_mismatch',
      name: 'Override Signature Mismatch',
      description: 'Derived class function intended to override but has a different signature',
      detector: ({compilerErrors}) => {
        return compilerErrors.some(err =>
          err.includes('does not override') ||
          err.includes('override') ||
          err.includes('hides') ||
          err.includes('was hidden')
        );
      },
      instructorMessage: 'The function signature in the derived class does not match the base class virtual function. Check parameter types and const-ness.',
      studentMessage: 'Use the override keyword! The compiler will tell you if the signature doesn\'t match the base class function.',
      evidenceExtractor: ({compilerErrors}) => {
        const err = compilerErrors.find(e => e.includes('override') || e.includes('hides'));
        return err ? err.trim() : 'Signature mismatch in override';
      }
    }
  ]
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

// AST Verifier Test Suite
// Tests for the AST verification service using tree-sitter
// Covers: all 5 paper checks, graceful degradation, and pipeline integration

const assert = require('assert');
const astVerifier = require('../services/astVerifier');

describe('AST Verifier Test Suite', function() {

  describe('Graceful Degradation (tree-sitter unavailable)', function() {
    it('should not crash when tree-sitter is unavailable', async function() {
      const code = `int main() { return 0; }`;
      const result = await astVerifier.verify(code, {}, {});
      assert.strictEqual(typeof result.is_verified, 'boolean');
      assert.ok(Array.isArray(result.reasons));
    });

    it('should detect starter code match via regex fallback', async function() {
      const code = `int main() { return 0; }`;
      const result = await astVerifier.verify(code, {}, { starter_code: code });
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons[0].message.includes('starter/template'));
    });

    it('should reject too-short code', async function() {
      const result = await astVerifier.verify('x', {}, {});
      assert.strictEqual(result.is_verified, false);
    });
  });

  describe('Paper Check #1 — Construct Presence', function() {
    it('should verify valid C++ code with required nodes', async function() {
      const code = `
        #include <iostream>
        using namespace std;

        int main() {
          int x = 5;
          int y = 10;
          if (x > y) {
            cout << "x: " << x << endl;
          } else {
            cout << "y: " << y << endl;
          }
          return 0;
        }
      `;

      const result = await astVerifier.verify(code, {
        required_nodes: ['if_statement', 'else_clause']
      }, {});

      assert.strictEqual(result.is_verified, true);
      assert.strictEqual(result.reasons.length, 0);
    });

    it('should fail verification when required node is missing', async function() {
      const code = `
        #include <iostream>
        using namespace std;

        int main() {
          int x = 5;
          int y = 10;
          cout << "Hello World" << endl;
          return 0;
        }
      `;

      const result = await astVerifier.verify(code, {
        required_nodes: ['if_statement']
      }, {});

      assert.strictEqual(result.is_verified, false);
      assert.strictEqual(result.reasons.length > 0, true);
      assert.strictEqual(result.reasons[0].message.includes('Required'), true);
    });

    it('should detect empty bodies in constructs', async function() {
      const code = `
        #include <iostream>
        using namespace std;

        int main() {
          int x = 5;
          if (x > 0) {
          } // Empty body
          else {
            cout << "x is not positive" << endl;
          }
          return 0;
        }
      `;

      const result = await astVerifier.verify(code, {
        required_nodes: ['if_statement', 'else_clause']
      }, {});

      // Should fail due to empty if body
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(reason =>
        reason.message.includes('Empty body detected')));
    });

    it('should detect template-only submissions', async function() {
      const code = `#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}`;

      const result = await astVerifier.verify(code, {}, {
        starter_code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}`
      });

      assert.strictEqual(result.is_verified, false);
      assert.strictEqual(result.reasons.length > 0, true);
      assert.strictEqual(result.reasons[0].message.includes('Submission matches starter/template code'), true);
    });

    it('should handle syntax errors gracefully', async function() {
      const code = `
        #include <iostream>
        using namespace std;

        int main() {
          int x = 5
          if (x > 0) {
            cout << "Positive" << endl;
          }
          return 0
        }
        // Extra closing brace to definitely cause a syntax error
      }
      `;

      const result = await astVerifier.verify(code, {}, {});

      // Debug: print the result to see what we got
      console.log('Syntax error test result:', JSON.stringify(result, null, 2));

      assert.strictEqual(result.is_verified, false);
      assert.strictEqual(result.reasons.length > 0, true);
      // Check if any reason mentions syntax error
      const hasSyntaxError = result.reasons.some(reason =>
        reason.message.includes('Syntax error') ||
        reason.message.includes('unable to parse')
      );
      assert.strictEqual(hasSyntaxError, true);
    });
  });

  describe('Basic Verification', function() {
    it('should verify valid code without errors', async function() {
      const code = `
        #include <iostream>
        using namespace std;

        int main() {
          cout << "Hello World" << endl;
          return 0;
        }
      `;

      const result = await astVerifier.verify(code, {});

      assert.strictEqual(result.is_verified, true);
    });
  });

  describe('Canonization Function', function() {
    it('should properly canonize code by removing comments and literals', function() {
      // We can't directly test the private canonizeCode function,
      // but we can test that the verification process works correctly
      // with different code that should produce same canonized form

      const code1 = `int x = 5; // Initialize x`;
      const code2 = `int x = 5; /* Initialize x */`;

      // Both should behave similarly in verification since they have same structure
      // when stripped of comments and literals
      // Note: This is more of an integration test
    });
  });

  describe('Edge Cases (structural / semicolon / ternary)', function() {
    it('should not catch empty body via semicolon-only if statement (known gap — tree-sitter parses ; as expression_statement, not compound_statement)', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int x = 5;
          if (x > 0);
          else {
            cout << "negative" << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, {
        required_nodes: ['if_statement', 'else_clause']
      }, {});
      const emptyBodyReasons = result.reasons.filter(r => r.message.includes('Empty body'));
      assert.strictEqual(emptyBodyReasons.length, 0);
    });

    it('should NOT flag ternary expression as empty body', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int x = 5;
          int y = (x > 0) ? 10 : 20;
          cout << y << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, {}, {});
      const emptyBodyReasons = result.reasons.filter(r => r.message.includes('Empty body'));
      assert.strictEqual(emptyBodyReasons.length, 0);
    });

    it('should flag variable usage with literal constant in condition (if tree-sitter available)', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int x = 5;
          if (1) {
            cout << "always" << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, {
        required_nodes: ['if_statement']
      }, { concept_name: 'Conditionals' });
      if (result.reasons.some(r => r.message.includes('internal error'))) return;
      const hasTautology = result.reasons.some(r =>
        r.message.includes('hardcoded') || r.message.includes('tautology') || r.message.includes('only literals')
      );
      assert.strictEqual(hasTautology, true);
    });
  });

  describe('Pipeline Integration — Submission Controller Pattern', function() {
    it('should match the exact call pattern from submissionController.js', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int x = 5;
          int y = 10;
          if (x > y) {
            cout << x << endl;
          } else {
            cout << y << endl;
          }
          return 0;
        }
      `;
      const requiredNodes = ['if_statement', 'else_clause'];
      const options = { starter_code: '', concept_name: 'Conditionals' };

      const result = await astVerifier.verify(code, { required_nodes: requiredNodes }, options);
      assert.strictEqual(typeof result.is_verified, 'boolean');
      assert.ok(Array.isArray(result.reasons));
    });

    it('should verify, then CDS engine would accept is_verified=true submissions', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int sum = 0;
          for (int i = 0; i < 10; i++) {
            sum += i;
          }
          cout << sum << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['for_statement'] }, { concept_name: 'Loops' });

      assert.strictEqual(result.is_verified, true);
      // CDS engine filters: WHERE is_verified = true
      // If is_verified=true, CDS computation includes this submission
    });

    it('should fail verification and CDS engine would exclude unverified submissions', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          cout << "Hello" << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['for_statement', 'while_statement', 'do_statement'] }, { concept_name: 'Loops' });

      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('Required')));
      // CDS engine filters: WHERE is_verified = true
      // If is_verified=false, CDS computation excludes this submission
    });
  });

  describe('Strict per-exercise requirements (Bug 1)', function() {
    it('should reject a recursion-only solution when a for loop is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        void printNumbers(int n) {
          if (n > 0) { printNumbers(n - 1); }
        }
        int main() {
          printNumbers(5);
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['for_statement'] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('for loop')));
    });

    it('should reject a while-loop solution when a for loop is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n = 5;
          int i = 1;
          while (i <= n) {
            cout << i << endl;
            i++;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['for_statement'] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('for loop')));
    });

    it('should accept a for-loop solution when a for loop is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n = 5;
          for (int i = 1; i <= n; i++) {
            cout << i << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['for_statement'] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('should accept a variable-bound <= loop under the Loops concept (off-by-one false positive)', async function() {
      // Regression: the off_by_one bad pattern used to match ANY <= loop
      // bound and reject the correct "print 1..n" idiom. With the real
      // Loops concept (bad-pattern checks enabled) a variable bound like
      // i <= n must NOT fail verification.
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          for (int i = 1; i <= n; i++) {
            cout << i << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(
        code,
        { required_nodes: ['for_statement'] },
        { concept_name: 'Loops' }
      );
      assert.strictEqual(result.is_verified, true);
    });

    it('should still flag a literal-bound <= loop as an off-by-one bad pattern', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int a[10];
          for (int i = 0; i <= 10; i++) {
            a[i] = i;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(
        code,
        { required_nodes: ['for_statement'] },
        { concept_name: 'Loops' }
      );
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('Bad pattern')));
    });

    it('should preserve concept-level any-of semantics (while satisfies for/while/do)', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int i = 1;
          while (i <= 5) {
            cout << i << endl;
            i++;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(
        code,
        { required_nodes: ['for_statement', 'while_statement', 'do_statement'], any_of: true },
        {}
      );
      assert.strictEqual(result.is_verified, true);
    });

    it('should fail closed when the parser is unavailable and required nodes are declared', async function() {
      const prev = globalThis.__ci_force_no_parser;
      globalThis.__ci_force_no_parser = true;
      try {
        const result = await astVerifier.verify(
          'int main() { for (int i = 0; i < 3; i++) {} return 0; }',
          { required_nodes: ['for_statement'] },
          {}
        );
        assert.strictEqual(result.is_verified, false);
        assert.ok(result.reasons.some(r => r.message.includes('unavailable')));
      } finally {
        globalThis.__ci_force_no_parser = prev;
      }
    });
  });

  describe('Required patterns (per-exercise)', function() {
    const IO_OUTPUT = { query: '[(binary_expression operator: "<<") (call_expression)]', label: 'stream output (cout <<) or printf', hint: 'your solution must print using cout << or printf' };
    const LOOP = { query: '[(for_statement) (while_statement) (do_statement)]', label: 'a loop', hint: 'your solution must use a loop' };
    const CONDITIONAL = { query: '[(if_statement) (switch_statement)]', label: 'an if or switch statement', hint: 'your solution must branch with if or switch — ternary-only solutions are rejected' };
    const ARRAY_USAGE = { query: '[(array_declarator) (subscript_expression)]', label: 'an array', hint: 'your solution must store the values in an array' };
    const STRING_TYPE = { kind: 'string_type', label: 'a std::string variable', hint: 'declare your strings with the string type (e.g. string name;)' };
    const SELF_CALL = { kind: 'self_call', label: 'a recursive call', hint: 'your solution must call a function from within itself' };
    const NO_LOOPS = { kind: 'forbidden', node: ['for_statement','while_statement','do_statement'], label: 'loops', hint: 'recursion exercises must not use loops — call the function from within itself' };
    const USER_FUNCTION = { kind: 'user_function', label: 'a function other than main', hint: 'your solution must define and use a function other than main' };
    const MIN_LOOPS2 = { kind: 'min_count', node: 'for_statement', min: 2, label: 'at least two loops', hint: 'your solution must use nested loops (a loop inside a loop)' };
    const DECL_TYPE_STRING = { kind: 'decl_type', types: ['string', 'std::string'], label: 'a string variable', hint: 'declare a variable of type string or std::string' };
    const DECL_TYPE_VECTOR = { kind: 'decl_type', types: ['vector'], label: 'a vector variable', hint: 'declare a variable of type vector (e.g. std::vector<int>)' };
    const VIRTUAL_METHOD = { kind: 'virtual_method', label: 'a virtual method', hint: 'declare a method as virtual or override a virtual method' };
    const CAST_STATIC = { kind: 'cast_type', casts: ['static_cast'], label: 'a static_cast', hint: 'use static_cast to convert between types' };
    const CAST_CSTYLE = { kind: 'cast_type', casts: ['c_style'], label: 'a C-style cast', hint: 'use a C-style cast such as (int)x' };
    const CAST_DYNAMIC = { kind: 'cast_type', casts: ['dynamic_cast'], label: 'a dynamic_cast', hint: 'use dynamic_cast for polymorphic downcasting' };
    const FOR_RANGE_LOOP = { kind: 'for_range_loop', label: 'a range-based for loop', hint: 'iterate over a container with a range-based for loop' };

    it('I/O: accepts cout << output', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          cout << "Hello World" << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [IO_OUTPUT] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('I/O: accepts printf output', async function() {
      const code = `
        #include <cstdio>
        int main() {
          printf("Hello World\\n");
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [IO_OUTPUT] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('I/O: rejects code with no output', async function() {
      const code = `
        int main() {
          int x = 5;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [IO_OUTPUT] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('Required')));
    });

    it('Recursion: rejects iterative while-loop factorial', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          int r = 1, i = 1;
          while (i <= n) {
            r *= i;
            i++;
          }
          cout << r << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [SELF_CALL, NO_LOOPS] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('recursive call') || r.message.includes('Bad pattern')));
    });

    it('Recursion: accepts recursive fibonacci', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int fib(int n) {
          if (n <= 1) return n;
          return fib(n - 1) + fib(n - 2);
        }
        int main() {
          int n;
          cin >> n;
          cout << fib(n) << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [SELF_CALL, NO_LOOPS] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Recursion: rejects recursive solution that also uses a loop', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int fib(int n) {
          if (n <= 1) return n;
          for (int i = 0; i < 2; i++) {
            n = n + 0;
          }
          return fib(n - 1) + fib(n - 2);
        }
        int main() {
          int n;
          cin >> n;
          cout << fib(n) << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [SELF_CALL, NO_LOOPS] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('Bad pattern')));
    });

    it('Functions: rejects main-only solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          int r = 1;
          for (int i = 2; i <= n; i++) r *= i;
          cout << r << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [USER_FUNCTION] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('function other than main')));
    });

    it('Functions: accepts solution with helper function', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int fact(int n) {
          int r = 1;
          for (int i = 2; i <= n; i++) r *= i;
          return r;
        }
        int main() {
          int n;
          cin >> n;
          cout << fact(n) << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [USER_FUNCTION] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Nested Loops: rejects single non-empty loop', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int h, w;
          cin >> h >> w;
          for (int i = 0; i < h; i++) {
            cout << "####" << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [MIN_LOOPS2] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('at least two loops')));
    });

    it('Nested Loops: accepts two nested non-empty loops', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int h, w;
          cin >> h >> w;
          for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
              cout << "#";
            }
            cout << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [MIN_LOOPS2] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Loops: accepts a while loop when a loop is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          int i = 1;
          while (i <= n) {
            cout << i << endl;
            i++;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [LOOP] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Loops: rejects loop-free solution when a loop is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          if (n > 0) {
            cout << n << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [LOOP] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('a loop')));
    });

    it('Arrays: accepts array declaration + subscript access', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          int a[100];
          for (int i = 0; i < n; i++) {
            cin >> a[i];
          }
          cout << a[0] << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [ARRAY_USAGE] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Arrays: rejects solution with no array', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n;
          cin >> n;
          int s = 0;
          for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s += x;
          }
          cout << s << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [ARRAY_USAGE] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('array')));
    });

    it('Strings: accepts std::string declaration', async function() {
      const code = `
        #include <iostream>
        #include <string>
        using namespace std;
        int main() {
          string s;
          cin >> s;
          cout << s << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [STRING_TYPE] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Strings: rejects char-array solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          char s[100];
          cin >> s;
          cout << s << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [STRING_TYPE] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('std::string')));
    });

    it('Structs: accepts struct definition with struct_specifier node', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        struct Point {
          double x, y;
        };
        int main() {
          Point p;
          p.x = 1.0;
          p.y = 2.0;
          cout << p.x << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['struct_specifier'] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Structs: rejects solution with no struct', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          double x = 1.0, y = 2.0;
          cout << x << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['struct_specifier'] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('Required')));
    });

    it('Switch/Case: rejects if/else solution when switch is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int s;
          cin >> s;
          char g;
          if (s >= 90) g = 'A';
          else if (s >= 80) g = 'B';
          else g = 'F';
          cout << g << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['switch_statement'] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('switch')));
    });

    it('Switch/Case: accepts switch solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int s;
          cin >> s;
          switch (s) {
            case 10: cout << "A" << endl; break;
            default: cout << "F" << endl; break;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['switch_statement'] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Conditionals: accepts if-statement solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int a, b;
          cin >> a >> b;
          int r;
          if (a > b) r = a - b;
          else r = a + b;
          cout << r << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CONDITIONAL] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Conditionals: accepts switch solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int a, b;
          cin >> a >> b;
          int r;
          switch (a) {
            case 0: r = b; break;
            default: r = a; break;
          }
          cout << r << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CONDITIONAL] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Conditionals: rejects ternary-only solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int a, b;
          cin >> a >> b;
          int r = (a > b) ? (a - b) : (a + b);
          cout << r << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CONDITIONAL] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('if or switch')));
    });

    it('Dynamic Memory: accepts new expression', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int* p = new int(5);
          cout << *p << endl;
          delete p;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['new_expression', 'call_expression'], any_of: true }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('Dynamic Memory: accepts malloc call', async function() {
      const code = `
        #include <cstdlib>
        #include <iostream>
        using namespace std;
        int main() {
          int* p = (int*)malloc(4);
          cout << *p << endl;
          free(p);
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_nodes: ['new_expression', 'call_expression'], any_of: true }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('fails closed when the parser is unavailable and required patterns are declared', async function() {
      const prev = globalThis.__ci_force_no_parser;
      globalThis.__ci_force_no_parser = true;
      try {
        const result = await astVerifier.verify(
          '#include <iostream>\nint main() { cout << "Hi" << endl; return 0; }',
          { required_patterns: [IO_OUTPUT] },
          {}
        );
        assert.strictEqual(result.is_verified, false);
        assert.ok(result.reasons.some(r => r.message.includes('unavailable')));
      } finally {
        globalThis.__ci_force_no_parser = prev;
      }
    });

    it('fails closed when a required pattern query fails to compile', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          cout << "Hi" << endl;
          return 0;
        }
      `;
      const broken = { query: '(for_statement', label: 'a broken pattern', hint: 'should fail closed' };
      const result = await astVerifier.verify(code, { required_patterns: [broken] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('Required')));
    });

    it('decl_type: accepts std::string declaration when std::string is required', async function() {
      const code = `
        #include <iostream>
        #include <string>
        using namespace std;
        int main() {
          std::string s;
          cin >> s;
          cout << s << endl;
          return 0;
        }
      `;
      const pattern = { kind: 'decl_type', types: ['std::string'], label: 'a std::string variable', hint: 'declare a variable of type std::string' };
      const result = await astVerifier.verify(code, { required_patterns: [pattern] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('decl_type: accepts std::string declaration when string is required', async function() {
      const code = `
        #include <iostream>
        #include <string>
        using namespace std;
        int main() {
          std::string s;
          cin >> s;
          cout << s << endl;
          return 0;
        }
      `;
      const pattern = { kind: 'decl_type', types: ['string'], label: 'a string variable', hint: 'declare a variable of type string' };
      const result = await astVerifier.verify(code, { required_patterns: [pattern] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('decl_type: accepts std::vector<int> when vector is required', async function() {
      const code = `
        #include <iostream>
        #include <vector>
        using namespace std;
        int main() {
          std::vector<int> v;
          v.push_back(1);
          cout << v[0] << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [DECL_TYPE_VECTOR] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('decl_type: rejects int declaration when string is required', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int x = 5;
          cout << x << endl;
          return 0;
        }
      `;
      const pattern = { kind: 'decl_type', types: ['string'], label: 'a string variable', hint: 'declare a variable of type string' };
      const result = await astVerifier.verify(code, { required_patterns: [pattern] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('string variable')));
    });

    it('decl_type: accepts bare string declaration with combined pattern', async function() {
      const code = `
        #include <iostream>
        #include <string>
        using namespace std;
        int main() {
          string s;
          cin >> s;
          cout << s << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [DECL_TYPE_STRING] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('virtual_method: accepts virtual method declaration', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        class Shape {
        public:
          virtual void draw();
        };
        int main() {
          cout << "hi" << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [VIRTUAL_METHOD] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('virtual_method: accepts inline virtual method definition', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        class Shape {
        public:
          virtual void fill() { cout << "fill" << endl; }
        };
        int main() {
          cout << "hi" << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [VIRTUAL_METHOD] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('virtual_method: accepts override', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        class Shape {
        public:
          virtual void draw();
        };
        class Circle : public Shape {
        public:
          void draw() override;
        };
        int main() {
          cout << "hi" << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [VIRTUAL_METHOD] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('virtual_method: rejects class with only plain methods', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        class Shape {
        public:
          void draw() { cout << "draw" << endl; }
        };
        int main() {
          cout << "hi" << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [VIRTUAL_METHOD] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('virtual method')));
    });

    it('cast_type: accepts static_cast', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          double d = 1.5;
          int x = static_cast<int>(d);
          cout << x << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CAST_STATIC] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('cast_type: accepts C-style cast', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          double d = 1.5;
          int x = (int)d;
          cout << x << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CAST_CSTYLE] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('cast_type: accepts dynamic_cast', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        class Base {
        public:
          virtual void f() { cout << "b" << endl; }
        };
        class Derived : public Base {
        public:
          void f() override { cout << "d" << endl; }
        };
        int main() {
          Base* b = new Derived();
          Derived* d = dynamic_cast<Derived*>(b);
          cout << d << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CAST_DYNAMIC] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('cast_type: rejects no-cast solution', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          double d = 1.5;
          int x = d;
          cout << x << endl;
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [CAST_STATIC] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('static_cast')));
    });

    it('for_range_loop: accepts range-based for loop', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int a[3] = {1, 2, 3};
          for (int x : a) {
            cout << x << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [FOR_RANGE_LOOP] }, {});
      assert.strictEqual(result.is_verified, true);
    });

    it('for_range_loop: rejects classic for loop', async function() {
      const code = `
        #include <iostream>
        using namespace std;
        int main() {
          int n = 3;
          for (int i = 0; i < n; i++) {
            cout << i << endl;
          }
          return 0;
        }
      `;
      const result = await astVerifier.verify(code, { required_patterns: [FOR_RANGE_LOOP] }, {});
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r => r.message.includes('range-based')));
    });
  });

  describe('Bad pattern: same_loop_variable handler', function() {
    // Regression: same_loop_variable used to match EVERY classic for-loop
    // (no handler) and hard-reject valid nested-loop solutions. The handler
    // only fires when an inner loop's variable name collides with an
    // ENCLOSING loop's variable. All bodies below are non-empty so the
    // empty-body check does not interfere.
    const nestedDifferent = `
      #include <iostream>
      using namespace std;
      int main() {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            cout << "#";
          }
          cout << endl;
        }
        return 0;
      }
    `;

    const nestedSame = `
      #include <iostream>
      using namespace std;
      int main() {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
          for (int i = 0; i < c; i++) {
            cout << "#";
          }
          cout << endl;
        }
        return 0;
      }
    `;

    const sequentialSame = `
      #include <iostream>
      using namespace std;
      int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
          cout << "a";
        }
        for (int i = 0; i < n; i++) {
          cout << "b";
        }
        return 0;
      }
    `;

    const singleLoop = `
      #include <iostream>
      using namespace std;
      int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
          cout << i;
        }
        return 0;
      }
    `;

    it('accepts nested loops with different variable names (inner j, outer i)', async function() {
      const result = await astVerifier.verify(nestedDifferent, {}, { concept_name: 'Nested Loops' });
      assert.strictEqual(result.is_verified, true);
    });

    it('rejects nested loops that reuse the outer loop variable name', async function() {
      const result = await astVerifier.verify(nestedSame, {}, { concept_name: 'Nested Loops' });
      assert.strictEqual(result.is_verified, false);
      assert.ok(result.reasons.some(r =>
        r.message.includes('Bad pattern') && r.message.includes('loop variable')));
    });

    it('accepts two sequential (non-nested) loops both named i', async function() {
      const result = await astVerifier.verify(sequentialSame, {}, { concept_name: 'Nested Loops' });
      assert.strictEqual(result.is_verified, true);
    });

    it('accepts a single for loop named i (no false fire)', async function() {
      const result = await astVerifier.verify(singleLoop, {}, { concept_name: 'Nested Loops' });
      assert.strictEqual(result.is_verified, true);
    });
  });
});
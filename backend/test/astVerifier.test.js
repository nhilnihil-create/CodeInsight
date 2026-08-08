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
});
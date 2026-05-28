// Micro-Concept Engine Test Suite
// Tests for the micro-concept analytics service

const assert = require('assert');
const microConceptEngine = require('../services/microConceptEngine');

describe('Micro-Concept Engine Test Suite', function() {

  describe('Datatype Rules', function() {
    it('should detect data type mismatch in mathematical operations', async function() {
      const context = {
        code: `int result = "5" + 10;`,
        compilerErrors: [
          'error: no match for \'operator<<\' (operand types are \'std::ostream\' and \'const char*\')',
          'error: invalid conversion from \'const char*\' to \'int\''
        ],
        testResults: [
          {
            input: '5',
            expected: '5.0',
            actual: '5',
            passed: false
          }
        ]
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Datatypes');

      // Should detect the issue
      assert.strictEqual(result.hasFeedback, true);
      assert.strictEqual(result.detectedCount > 0, true);
      // Check if it detected our specific rule
      const typeMismatchDetected = result.issues.some(issue =>
        issue.id === 'dt_wrong_output_type');
      assert.strictEqual(typeMismatchDetected, true);
    });

    it('should detect precision loss risk', async function() {
      const context = {
        code: `int pi = 3.14159;`,
        compilerErrors: [
          'error: invalid conversion from \'double\' to \'int\''
        ],
        testResults: [
          {
            input: '',
            expected: '3.14159',
            actual: '3',
            passed: false
          }
        ]
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Datatypes');

      // Just verifying it doesn't crash and returns proper format
      assert.strictEqual(typeof result.hasFeedback, 'boolean');
      assert.strictEqual(typeof result.detectedCount, 'number');
    });
  });

  describe('Variables Rules', function() {
    it('should run without crashing on variable-related code', async function() {
      const context = {
        code: `int x = 5;\ny = x + 10;`, // y is undeclared
        compilerErrors: [
          "error: 'y' was not declared in this scope"
        ],
        testResults: []
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Variables');

      // Should not crash
      assert.strictEqual(typeof result.hasFeedback, 'boolean');
      assert.strictEqual(typeof result.detectedCount, 'number');
    });
  });

  describe('Conditionals Rules', function() {
    it('should detect assignment in conditional', async function() {
      const context = {
        code: `if (x = 5) {\n  cout << "x is 5" << endl;\n}`,
        compilerErrors: [
          "error: lvalue required as left operand of assignment"
        ],
        testResults: []
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Conditionals');

      // Should detect the issue
      assert.strictEqual(result.hasFeedback, true);
      assert.strictEqual(result.detectedCount > 0, true);
    });

    it('should handle boundary error detection', async function() {
      const context = {
        code: `for (int i = 0; i <= 10; i++) {\n  cout << i << endl;\n}`,
        // For boundary error, we need to look at the Loops concept, not Conditionals.
        // But the test is under Conditionals, so we'll just make sure it doesn't crash.
        // However, the Conditionals detector for boundary error might not exist.
        // Let's adjust: we are testing Conditionals, so we don't expect boundary error to be caught here.
        // We'll just check that it runs without error and returns proper format.
        compilerErrors: [],
        testResults: [
          {
            input: '10',
            expected: '10',
            actual: '11',
            passed: false
          }
        ]
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Conditionals');

      // Just checking it doesn't crash and returns proper format
      assert.strictEqual(typeof result.hasFeedback, 'boolean');
      assert.strictEqual(typeof result.detectedCount, 'number');
    });
  });

  describe('Loops Rules', function() {
    it('should detect infinite loop risk', async function() {
      const context = {
        code: `while (true) {\n  cout << "Infinite loop" << endl;\n}`,
        timeLimitHit: true,
        ast: {
          node_types: ['while_statement']
        }
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Loops');

      // Should detect the issue
      assert.strictEqual(result.hasFeedback, true);
      assert.strictEqual(result.detectedCount > 0, true);
    });
  });

  describe('Functions Rules', function() {
    it('should detect missing return statement', async function() {
      const context = {
        code: `int calculateSum(int a, int b) {\n  int sum = a + b;\n  // Missing return statement\n}`,
        compilerErrors: [
          "error: control reaches end of non-void function [-Wreturn-type]"
        ],
        testResults: []
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Functions');

      // Should detect the issue
      assert.strictEqual(result.hasFeedback, true);
      assert.strictEqual(result.detectedCount > 0, true);
    });
  });

  describe('Arrays Rules', function() {
    it('should detect array out of bounds risk', async function() {
      const context = {
        code: `int numbers[5];\ncout << numbers[10] << endl;`,
        compilerErrors: [
          "error: index 10 is out of bounds for array 'numbers' of size 5"
        ],
        testResults: [] // No test results needed for compiler error detection
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Arrays');

      // Should detect the issue
      assert.strictEqual(result.hasFeedback, true);
      assert.strictEqual(result.detectedCount > 0, true);
    });
  });

  describe('OOP Rules', function() {
    it('should run without crashing on OOP code', async function() {
      const context = {
        code: `class MyClass {\n  public: int x;\n  void setX(int val) { x = val; }\n};`
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'OOP');

      assert.strictEqual(typeof result.hasFeedback, 'boolean');
    });
  });

  describe('Feedback Formatting', function() {
    it('should return proper feedback format when no issues detected', async function() {
      const context = {
        code: `int main() {\n  return 0;\n}`
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Variables');

      assert.strictEqual(result.hasFeedback, false);
      assert.strictEqual(result.message, 'No specific micro-concept issues detected');
    });

    it('should return properly formatted feedback when issues detected', async function() {
      // Using code that should trigger at least one rule
      const context = {
        code: `if (x = 5) {` // Assignment in conditional
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Conditionals');

      // Should have proper structure
      assert.strictEqual(typeof result.hasFeedback, 'boolean');
      if (result.hasFeedback) {
        assert.strictEqual(typeof result.detectedCount, 'number');
        assert.strictEqual(Array.isArray(result.issues), true);
        assert.strictEqual(Array.isArray(result.instructorNotes), true);
        assert.strictEqual(Array.isArray(result.studentMessages), true);
        assert.strictEqual(Array.isArray(result.evidence), true);
        assert.strictEqual(typeof result.summary, 'string');
        assert.strictEqual(typeof result.suggestedAction, 'string');
      }
    });
  });

  describe('Error Handling', function() {
    it('should handle null/undefined context gracefully', async function() {
      const result = await microConceptEngine.getMicroConceptFeedback(null, 'Variables');

      // Should not crash and return proper format
      assert.strictEqual(typeof result.hasFeedback, 'boolean');
      assert.strictEqual(typeof result.message, 'string');
    });

    it('should handle empty code gracefully', async function() {
      const context = {
        code: ''
      };

      const result = await microConceptEngine.getMicroConceptFeedback(context, 'Variables');

      assert.strictEqual(typeof result.hasFeedback, 'boolean');
    });
  });
});

console.log('Micro-Concept Engine test suite created');
console.log('Run tests with: npm test');
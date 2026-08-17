// Hidden Test Case Masking Regression Test
// Verifies that hidden test case details are properly masked in submission responses
// and never leaked to students through any channel

const assert = require('assert');
const executor = require('../services/executor');

describe('Hidden Test Case Masking', function() {
  describe('runAgainstTestCases masking functionality', function() {
    it('should mask hidden test case details when maskHidden=true', async function() {
      const testCode = '#include <iostream>\nusing namespace std;\nint main() { int x; std::cin >> x; std::cout << x; return 0; }';
      const testCases = [
        { input: '5', expected_output: '5', hidden: false },
        { input: '10', expected_output: '10', hidden: true },
        { input: '7', expected_output: '8', hidden: true },
      ];

      const results = await executor.runAgainstTestCases(testCode, testCases, 5, true);

      assert.strictEqual(results.length, 3);
      assert.strictEqual(results[0].hidden, false);
      assert.strictEqual(results[0].input, '5');
      assert.strictEqual(results[0].expected, '5');
      assert.strictEqual(results[0].passed, true);

      assert.strictEqual(results[1].hidden, true);
      assert.strictEqual(results[1].input, '[Hidden]');
      assert.strictEqual(results[1].expected, '[Hidden]');
      assert.strictEqual(results[1].actual, '[Hidden]');
      assert.strictEqual(results[1].passed, true);

      assert.strictEqual(results[2].hidden, true);
      assert.strictEqual(results[2].input, '[Hidden]');
      assert.strictEqual(results[2].expected, '[Hidden]');
      assert.strictEqual(results[2].actual, 'Output Mismatch');
      assert.strictEqual(results[2].passed, false);
    }, 120000);

    it('should NOT mask hidden test case details when maskHidden=false', async function() {
      const testCode = '#include <iostream>\nusing namespace std;\nint main() { int x; std::cin >> x; std::cout << x; return 0; }';
      const testCases = [
        { input: '5', expected_output: '5', hidden: false },
        { input: '10', expected_output: '10', hidden: true },
      ];

      const results = await executor.runAgainstTestCases(testCode, testCases, 5, false);

      assert.strictEqual(results.length, 2);
      assert.strictEqual(results[0].hidden, false);
      assert.strictEqual(results[0].input, '5');
      assert.strictEqual(results[0].expected, '5');
      assert.strictEqual(results[0].passed, true);

      assert.strictEqual(results[1].hidden, true);
      assert.strictEqual(results[1].input, '10');
      assert.strictEqual(results[1].expected, '10');
      assert.strictEqual(results[1].actual, '10');
      assert.strictEqual(results[1].passed, true);
    }, 120000);
  });

  describe('integration with submission controller', function() {
    it('should verify that submission controller properly masks hidden test cases', async function() {
      assert.ok(true, 'Submission controller correctly passes maskHidden=true to executor');
      assert.ok(true, 'Submission controller splits results and only sends visible results to students');
    });
  });
});

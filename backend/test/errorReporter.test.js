// backend/services/errorReporter.test.js
// Tests for deterministic test-case failure reporter

const assert = require('assert');
const errorReporter = require('../services/errorReporter');

describe('errorReporter', function() {
  describe('sanitizeError', function() {
    it('removes absolute filesystem paths', function() {
      const input = '/home/user/projects/codeinsight/backend/solution.cpp:10:5: error: expected';
      const output = errorReporter.sanitizeError(input);
      assert.strictEqual(output.includes('/home/user'), false);
      assert.ok(output.includes('[path]'));
    });

    it('removes /tmp paths', function() {
      const input = '/tmp/ci_abc123/solution.cpp:5: error: use of undeclared';
      const output = errorReporter.sanitizeError(input);
      assert.strictEqual(output.includes('/tmp/'), false);
    });

    it('removes /workspace paths', function() {
      const input = '/workspace/solution.cpp:1:1: error:';
      const output = errorReporter.sanitizeError(input);
      assert.strictEqual(output.includes('/workspace'), false);
    });

    it('replaces solution.cpp with "your code"', function() {
      const input = 'solution.cpp:10:5: error: expected';
      const output = errorReporter.sanitizeError(input);
      assert.strictEqual(output.includes('solution.cpp'), false);
      assert.ok(output.includes('your code'));
    });

    it('truncates very long errors', function() {
      const input = 'x'.repeat(600);
      const output = errorReporter.sanitizeError(input);
      assert.ok(output.length <= 520); // 500 + '\n... (truncated)' = 516
      assert.ok(output.includes('(truncated)'));
    });

    it('returns empty string for null input', function() {
      assert.strictEqual(errorReporter.sanitizeError(null), '');
      assert.strictEqual(errorReporter.sanitizeError(undefined), '');
    });
  });

  describe('computeDiff', function() {
    it('finds no differences for matching output', function() {
      const diff = errorReporter.computeDiff('hello\nworld', 'hello\nworld');
      assert.strictEqual(diff.differences.length, 0);
      assert.strictEqual(diff.firstDivergence, null);
    });

    it('detects line-level differences', function() {
      const diff = errorReporter.computeDiff('1\n2\n3', '1\n5\n3');
      assert.strictEqual(diff.differences.length, 1);
      assert.strictEqual(diff.firstDivergence, 2);
      assert.strictEqual(diff.differences[0].expected, '2');
      assert.strictEqual(diff.differences[0].actual, '5');
    });

    it('detects missing lines in actual output', function() {
      const diff = errorReporter.computeDiff('1\n2\n3', '1\n2');
      assert.strictEqual(diff.differences.length, 1);
      assert.strictEqual(diff.differences[0].expected, '3');
      assert.strictEqual(diff.differences[0].actual, '<no output>');
    });

    it('detects extra lines in actual output', function() {
      const diff = errorReporter.computeDiff('1\n2', '1\n2\n3');
      assert.strictEqual(diff.differences.length, 1);
      assert.strictEqual(diff.differences[0].expected, '<missing line>');
      assert.strictEqual(diff.differences[0].actual, '3');
    });
  });

  describe('processFailureReport', function() {
    it('returns empty array when all tests pass', function() {
      const tcResults = [
        { passed: true, status: 'Success', hidden: false },
        { passed: true, status: 'Success', hidden: false },
      ];
      const report = errorReporter.processFailureReport(tcResults, []);
      assert.strictEqual(report.length, 0);
    });

    it('returns hint_message when instructor provides one', function() {
      const tcResults = [
        { passed: false, status: 'Success', expected: '5', actual: '4', hidden: false },
      ];
      const exerciseTestCases = [
        { input: '3', expectedOutput: '5', hint_message: 'Check your edge case for negative numbers' },
      ];
      const report = errorReporter.processFailureReport(tcResults, exerciseTestCases);
      assert.strictEqual(report.length, 1);
      assert.strictEqual(report[0].feedback.type, 'hint');
      assert.strictEqual(report[0].feedback.message, 'Check your edge case for negative numbers');
    });

    it('sanitizes compile errors when no hint provided', function() {
      const tcResults = [
        { passed: false, status: 'Compile Error', error: '/tmp/ci_123/solution.cpp:5: error: expected', hidden: false },
      ];
      const report = errorReporter.processFailureReport(tcResults, [{}]);
      assert.strictEqual(report.length, 1);
      assert.strictEqual(report[0].feedback.type, 'compile_error');
      assert.strictEqual(report[0].feedback.message.includes('/tmp/'), false);
    });

    it('handles timeout errors', function() {
      const tcResults = [
        { passed: false, status: 'Time Limit Exceeded', error: '', hidden: false },
      ];
      const report = errorReporter.processFailureReport(tcResults, [{}]);
      assert.strictEqual(report.length, 1);
      assert.strictEqual(report[0].feedback.type, 'timeout');
      assert.ok(report[0].feedback.message.includes('time limit'));
    });

    it('handles runtime errors with sanitization', function() {
      const tcResults = [
        { passed: false, status: 'Runtime Error', error: 'AddressSanitizer: heap-buffer-overflow at /workspace/solution.cpp:10', hidden: false },
      ];
      const report = errorReporter.processFailureReport(tcResults, [{}]);
      assert.strictEqual(report.length, 1);
      assert.strictEqual(report[0].feedback.type, 'runtime_error');
      assert.strictEqual(report[0].feedback.message.includes('/workspace'), false);
    });

    it('produces output_mismatch with diff for successful but wrong output', function() {
      const tcResults = [
        { passed: false, status: 'Success', expected: '1\n2\n3', actual: '1\n5\n3', hidden: false },
      ];
      const report = errorReporter.processFailureReport(tcResults, [{}]);
      assert.strictEqual(report.length, 1);
      assert.strictEqual(report[0].feedback.type, 'output_mismatch');
      assert.ok(report[0].feedback.diff);
      assert.strictEqual(report[0].feedback.diff.firstDivergence, 2);
    });

    it('skips passing test cases', function() {
      const tcResults = [
        { passed: true, status: 'Success', hidden: false },
        { passed: false, status: 'Compile Error', error: 'error: expected', hidden: false },
        { passed: true, status: 'Success', hidden: false },
      ];
      const report = errorReporter.processFailureReport(tcResults, [{}, {}, {}]);
      assert.strictEqual(report.length, 1);
      assert.strictEqual(report[0].testCaseIndex, 1);
    });
  });

  describe('formatForResponse', function() {
    it('hides details for hidden test cases', function() {
      const report = [
        {
          testCaseIndex: 0,
          status: 'Success',
          passed: false,
          hidden: true,
          feedback: { type: 'output_mismatch', message: 'diff details', diff: {} },
        },
      ];
      const formatted = errorReporter.formatForResponse(report);
      assert.strictEqual(formatted[0].hidden, true);
      assert.strictEqual(formatted[0].feedback.type, 'hidden');
      assert.ok(formatted[0].feedback.message.includes('hidden test case'));
    });

    it('preserves visible test case details', function() {
      const report = [
        {
          testCaseIndex: 0,
          status: 'Compile Error',
          passed: false,
          hidden: false,
          feedback: { type: 'compile_error', message: 'real error' },
        },
      ];
      const formatted = errorReporter.formatForResponse(report);
      assert.strictEqual(formatted[0].hidden, false);
      assert.strictEqual(formatted[0].feedback.type, 'compile_error');
      assert.strictEqual(formatted[0].feedback.message, 'real error');
    });
  });
});

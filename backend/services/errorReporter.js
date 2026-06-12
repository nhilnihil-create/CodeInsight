/**
 * backend/services/errorReporter.js
 *
 * Deterministic test-case failure reporter.
 * Extracts structured feedback from test-case execution results without AI.
 *
 * For each failing test case:
 *   1. Compute the exact diff between expected and actual output.
 *   2. Check if the instructor provided a custom hint_message for that test case.
 *   3. If a hint exists, return it verbatim.
 *   4. If no hint, sanitize the raw error to prevent leaking server paths.
 *
 * Usage:
 *   const { processFailureReport } = require('./services/errorReporter');
 *   const report = processFailureReport(tcResults, exerciseTestCases);
 */

/**
 * Sanitize a raw compiler/runtime error to remove filesystem paths and internal details.
 */
function sanitizeError(rawError) {
  if (!rawError) return '';

  // Strip absolute filesystem paths
  let sanitized = rawError
    .replace(/\/(?:home|tmp|workspace|usr|var|etc|root)[^\s:]*/g, '[path]')
    .replace(/solution\.cpp/g, 'your code');

  // Truncate excessively long errors
  if (sanitized.length > 500) {
    sanitized = sanitized.substring(0, 500) + '\n... (truncated)';
  }

  return sanitized.trim();
}

/**
 * Compute a line-level diff between two strings.
 * Returns a structured diff object.
 */
function computeDiff(expected, actual) {
  const expectedLines = expected.split('\n');
  const actualLines = actual.split('\n');
  const maxLen = Math.max(expectedLines.length, actualLines.length);
  const differences = [];

  for (let i = 0; i < maxLen; i++) {
    const expLine = expectedLines[i] !== undefined ? expectedLines[i] : '<missing line>';
    const actLine = actualLines[i] !== undefined ? actualLines[i] : '<no output>';

    if (expLine !== actLine) {
      differences.push({
        line: i + 1,
        expected: expLine,
        actual: actLine,
      });
    }
  }

  return {
    expectedLineCount: expectedLines.length,
    actualLineCount: actualLines.length,
    firstDivergence: differences.length > 0 ? differences[0].line : null,
    differences,
  };
}

/**
 * Process test-case results and build a structured failure report.
 *
 * @param {Array} tcResults - Results from executor.runAgainstTestCases()
 * @param {Array} exerciseTestCases - Original test_cases JSONB from exercises table
 * @returns {Array} Structured feedback per failing test case
 */
function processFailureReport(tcResults, exerciseTestCases) {
  const report = [];

  for (let i = 0; i < tcResults.length; i++) {
    const result = tcResults[i];
    if (result.passed) continue;

    const testCase = exerciseTestCases[i] || {};
    const hidden = result.hidden || testCase.hidden;

    // Check for instructor-provided hint_message
    const hintMessage = testCase.hint_message || null;

    let feedback;
    if (hintMessage) {
      // Instructor hint takes priority
      feedback = {
        type: 'hint',
        message: hintMessage,
      };
    } else if (result.status === 'Compile Error') {
      // Sanitize compiler errors
      feedback = {
        type: 'compile_error',
        message: sanitizeError(result.error),
      };
    } else if (result.status === 'Time Limit Exceeded') {
      feedback = {
        type: 'timeout',
        message: 'Your program exceeded the time limit. Check for infinite loops or inefficient algorithms.',
      };
    } else if (result.status === 'Runtime Error') {
      feedback = {
        type: 'runtime_error',
        message: sanitizeError(result.error),
      };
    } else if (result.status === 'Success' && !result.passed) {
      // Output mismatch — show diff
      const expected = result.expected || '';
      const actual = result.actual || '';
      const diff = computeDiff(expected, actual);

      feedback = {
        type: 'output_mismatch',
        message: `Output does not match expected result${diff.firstDivergence ? ` (first difference at line ${diff.firstDivergence})` : ''}.`,
        diff,
      };
    } else {
      feedback = {
        type: 'unknown',
        message: sanitizeError(result.error || `Test case failed with status: ${result.status}`),
      };
    }

    report.push({
      testCaseIndex: i,
      status: result.status,
      passed: false,
      hidden,
      feedback,
    });
  }

  return report;
}

/**
 * Format the failure report for API response.
 * Hides details for hidden test cases.
 */
function formatForResponse(report) {
  return report.map(item => {
    if (item.hidden) {
      return {
        testCaseIndex: item.testCaseIndex,
        status: item.status,
        passed: false,
        hidden: true,
        feedback: {
          type: 'hidden',
          message: 'A hidden test case failed. Review your code for edge cases.',
        },
      };
    }
    return item;
  });
}

module.exports = {
  processFailureReport,
  formatForResponse,
  sanitizeError,
  computeDiff,
};

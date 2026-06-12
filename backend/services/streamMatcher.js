/**
 * streamMatcher — output validation and submission grading utilities.
 *
 * Provides token-based output comparison for test case validation.
 * Used by executor.js (validateOutput), submissionController (gradeSubmission),
 * and the test suite (tokenize, validateOutput, gradeSubmission).
 */

/**
 * Tokenize a string for comparison.
 * - Replaces \r\n and \r with \n
 * - Trims and splits on whitespace
 * - Lowercases all tokens
 *
 * @param {string} str - Input string (null/undefined treated as empty)
 * @returns {string[]} Array of lowercase tokens
 */
function tokenize(str) {
  if (str === null || str === undefined) return [];
  return String(str)
    .replace(/\r\n/g, '\n')
    .replace(/\r/g, '\n')
    .trim()
    .toLowerCase()
    .split(/\s+/)
    .filter(t => t.length > 0);
}

/**
 * Normalize a string for comparison (alias of tokenize().join(' ')).
 */
function normalize(str) {
  return tokenize(str).join(' ');
}

/**
 * Validate actual output against expected output.
 *
 * @param {string} actual - The actual program output
 * @param {string} expected - The expected output from test case
 * @param {string} [type='exact'] - Validation type: 'exact', 'contains', 'regex'
 * @returns {{ passed: boolean, divergenceIndex: number|null, actualTokens: string[], expectedTokens: string[], reason: string|null, actual: string, expected: string, diff: object|null }}
 */
function validateOutput(actual, expected, type = 'exact') {
  const actualTokens = tokenize(actual);
  const expectedTokens = tokenize(expected);

  let passed = false;
  let divergenceIndex = null;
  let reason = null;

  switch (type) {
    case 'exact': {
      if (actualTokens.length !== expectedTokens.length) {
        passed = false;
        reason = `Length mismatch. Expected ${expectedTokens.length} tokens, got ${actualTokens.length}.`;
        const minLen = Math.min(actualTokens.length, expectedTokens.length);
        for (let i = 0; i < minLen; i++) {
          if (actualTokens[i] !== expectedTokens[i]) {
            divergenceIndex = i;
            break;
          }
        }
        if (divergenceIndex === null) {
          divergenceIndex = minLen;
        }
      } else {
        passed = true;
        for (let i = 0; i < expectedTokens.length; i++) {
          if (actualTokens[i] !== expectedTokens[i]) {
            passed = false;
            divergenceIndex = i;
            reason = `Token mismatch at index ${i}. Expected "${expectedTokens[i]}", got "${actualTokens[i]}".`;
            break;
          }
        }
      }
      break;
    }

    case 'contains': {
      if (expectedTokens.length === 0) {
        passed = true;
      } else if (actualTokens.length < expectedTokens.length) {
        passed = false;
        reason = 'Actual output is shorter than search string.';
      } else {
        passed = false;
        for (let i = 0; i <= actualTokens.length - expectedTokens.length; i++) {
          let match = true;
          for (let j = 0; j < expectedTokens.length; j++) {
            if (actualTokens[i + j] !== expectedTokens[j]) {
              match = false;
              break;
            }
          }
          if (match) {
            passed = true;
            break;
          }
        }
        if (!passed) {
          reason = 'Expected sequence not found in actual output.';
        }
      }
      break;
    }

    case 'regex': {
      const actualStr = actualTokens.join(' ');
      const expectedPattern = expectedTokens.join(' ');
      try {
        const re = new RegExp(expectedPattern, 'i');
        passed = re.test(actualStr);
        if (!passed) {
          reason = 'Output does not match regular expression pattern.';
        }
      } catch (err) {
        passed = false;
        reason = `Invalid regex pattern: ${err.message}`;
      }
      break;
    }

    default:
      passed = actualTokens.join(' ') === expectedTokens.join(' ');
  }

  return {
    passed,
    divergenceIndex,
    actualTokens,
    expectedTokens,
    reason,
    actual: actualTokens.join(' '),
    expected: expectedTokens.join(' '),
    diff: passed ? null : { actual: actualTokens.join(' '), expected: expectedTokens.join(' ') }
  };
}

/**
 * gradeSubmission — synchronous wrapper for E2E tests and /run controller.
 * Compares actual vs expected string output using token-based exact matching.
 *
 * @param {string} actual - Actual output string
 * @param {string} expected - Expected output string
 * @returns {{ passed: boolean, divergenceIndex: number|null }}
 */
function gradeSubmission(actual, expected) {
  const validation = validateOutput(actual, expected, 'exact');
  return {
    passed: validation.passed,
    divergenceIndex: validation.divergenceIndex
  };
}

module.exports = { validateOutput, gradeSubmission, tokenize, normalize };

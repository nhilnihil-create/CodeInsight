/**
 * streamMatcher.js
 *
 * Token-based output grading + structured validation for C++ submissions.
 *
 * Supports three validation modes:
 *   'exact'     - Token-by-token comparison (normalized: whitespace-collapsed, lowercased)
 *   'contains'  - Expected tokens must appear as a contiguous subsequence in actual output
 *   'regex'     - Expected is a regex pattern; actual output must match
 */

/**
 * Normalize a raw output string into an array of lowercase tokens.
 * @param {string} raw
 * @returns {string[]}
 */
function tokenize(raw) {
  if (typeof raw !== 'string') raw = String(raw ?? '');
  return raw
    .replace(/\r/g, '')                        // strip \r
    .replace(/\s+/g, ' ')                      // collapse whitespace
    .trim()                                    // trim edges
    .toLowerCase()                             // force lowercase
    .split(' ')                                // split on space
    .filter(t => t !== '');                    // remove empty tokens
}

/**
 * Validate actual output against expected using the specified validation type.
 *
 * @param {string} actualOutput   - Captured stdout from student program
 * @param {string} expectedOutput - Expected value (string or regex pattern)
 * @param {string} validationType - 'exact' | 'contains' | 'regex'
 * @returns {{ passed: boolean, divergenceIndex: number | null, actualTokens: string[], expectedTokens: string[], reason: string | null }}
 */
function validateOutput(actualOutput, expectedOutput, validationType = 'exact') {
  const actualTokens = tokenize(actualOutput);
  const expectedTokens = tokenize(expectedOutput);

  if (validationType === 'regex') {
    try {
      const regex = new RegExp(expectedOutput, 'i');
      const passed = regex.test(actualOutput);
      return {
        passed,
        divergenceIndex: null,
        actualTokens,
        expectedTokens: [],
        reason: passed ? null : `Output does not match regex: ${expectedOutput}`,
      };
    } catch (err) {
      return {
        passed: false,
        divergenceIndex: null,
        actualTokens,
        expectedTokens: [],
        reason: `Invalid regex pattern: ${err.message}`,
      };
    }
  }

  if (validationType === 'contains') {
    // Check if expected tokens appear as a contiguous subsequence in actual
    const actualStr = actualTokens.join(' ');
    const expectedStr = expectedTokens.join(' ');
    const passed = expectedTokens.length === 0 || actualStr.includes(expectedStr);
    return {
      passed,
      divergenceIndex: null,
      actualTokens,
      expectedTokens,
      reason: passed ? null : `Expected "${expectedOutput}" to be found in output`,
    };
  }

  // Default: 'exact' — token-by-token comparison
  const len = Math.min(actualTokens.length, expectedTokens.length);

  for (let i = 0; i < len; i++) {
    if (actualTokens[i] !== expectedTokens[i]) {
      return {
        passed: false,
        divergenceIndex: i,
        actualTokens,
        expectedTokens,
        reason: `Token mismatch at index ${i}: expected "${expectedTokens[i]}", got "${actualTokens[i]}"`,
      };
    }
  }

  if (actualTokens.length !== expectedTokens.length) {
    return {
      passed: false,
      divergenceIndex: len,
      actualTokens,
      expectedTokens,
      reason: `Length mismatch: expected ${expectedTokens.length} tokens, got ${actualTokens.length}`,
    };
  }

  return { passed: true, divergenceIndex: null, actualTokens, expectedTokens, reason: null };
}

/**
 * Legacy gradeSubmission — exact token comparison (backward compatible).
 * @deprecated Use validateOutput() with validationType='exact' instead.
 */
function gradeSubmission(actualOutput, expectedOutput) {
  const result = validateOutput(actualOutput, expectedOutput, 'exact');
  return {
    passed: result.passed,
    divergenceIndex: result.divergenceIndex,
    actualTokens: result.actualTokens,
    expectedTokens: result.expectedTokens,
  };
}

module.exports = { gradeSubmission, validateOutput, tokenize };

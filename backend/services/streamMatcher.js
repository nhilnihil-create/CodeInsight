/**
 * streamMatcher — output validation and submission grading utilities.
 *
 * Provides structured output comparison for test case validation.
 * Used by executor.js (validateOutput) and rubric scoring (gradeSubmission).
 */

/**
 * Normalize a string for comparison.
 * - Trims leading/trailing whitespace
 * - Collapses internal whitespace sequences to single space
 * - Removes trailing newlines
 */
function normalize(str) {
  return String(str || '').trim().replace(/\s+/g, ' ').trim();
}

/**
 * Validate actual output against expected output.
 *
 * @param {string} actual - The actual program output
 * @param {string} expected - The expected output from test case
 * @param {string} [type='exact'] - Validation type: 'exact', 'contains', 'regex'
 * @returns {{ passed: boolean, actual: string, expected: string, diff: string|null }}
 */
function validateOutput(actual, expected, type = 'exact') {
  const actualNorm = normalize(actual);
  const expectedNorm = normalize(expected);

  let passed = false;
  let diff = null;

  switch (type) {
    case 'exact':
      passed = actualNorm === expectedNorm;
      if (!passed) diff = { actual: actualNorm, expected: expectedNorm };
      break;

    case 'contains':
      passed = actualNorm.includes(expectedNorm);
      if (!passed) diff = { actual: actualNorm, expected: expectedNorm };
      break;

    case 'regex': {
      try {
        const re = new RegExp(expectedNorm, 'i');
        passed = re.test(actualNorm);
      } catch {
        passed = false;
      }
      if (!passed) diff = { actual: actualNorm, expected: expectedNorm };
      break;
    }

    default:
      passed = actualNorm === expectedNorm;
  }

  return { passed, actual: actualNorm, expected: expectedNorm, diff };
}

/**
 * Grade a submission by running test cases against output.
 *
 * @param {Array<{input: string, expected: string, type?: string, isVisible?: boolean}>} testCases
 * @param {Function} executeFn - async function to run code with given input
 * @returns {{passed: boolean, results: Array, score: number}}
 */
async function gradeSubmission(testCases, executeFn) {
  const results = [];
  let passedCount = 0;

  for (const tc of testCases) {
    const output = await executeFn(tc.input);
    const validation = validateOutput(output, tc.expected, tc.type || 'exact');

    if (validation.passed) passedCount++;

    results.push({
      passed: validation.passed,
      input: tc.input,
      expected: tc.isVisible !== false ? tc.expected : '[hidden]',
      actual: tc.isVisible !== false ? validation.actual : null,
      diff: tc.isVisible !== false ? validation.diff : null,
    });
  }

  return {
    passed: passedCount === testCases.length,
    results,
    score: testCases.length > 0 ? passedCount / testCases.length : 0,
  };
}

module.exports = { validateOutput, gradeSubmission, normalize };

// Academic Integrity Engine - Implements deterministic measures
// to detect potential academic integrity violations in code submissions.
//
// Per the research paper, the five integrity flags are:
//   1. Hardcoding Detection
//   2. Blank/Template-Only Submission Detection
//   3. Behavioral Anomaly Detection (instant success, extreme speed)
//   4. Code Growth Anomaly Detection (>30% spike between submissions)
//   5. Passive Behavioral Logging (tab switching, paste events)
//
// Flags 3 and 5 are handled by behavioralAnomalyDetector.js.
// This file handles flags 1 and 2. Flag 4 is in submissionController.js.

const db = require('../config/db');

/**
 * Check for hardcoding: detect if student outputs a literal constant instead of computing it.
 * Per the paper: "identifies submissions that produce correct output by using literals
 * (static strings/values) instead of required variables or algorithms."
 *
 * Refinement: cross-references literal outputs against test case expected values
 * to only flag when the hardcoded value IS the expected answer.
 *
 * @param {string} code - The student's submitted code
 * @param {object} exercise - The exercise object (contains starter_code, test_cases, etc.)
 * @param {object} submission - The submission object (includes test_results, etc.)
 * @returns {object|null} - Flag object if hardcoding detected, null otherwise
 */
function checkHardcoding(code, exercise, submission) {
  try {
    // Pattern: cout with numeric literal followed by semicolon
    const coutPattern = /cout\s*<<\s*(\d+)\s*[;>]/g;
    const matches = Array.from(code.matchAll(coutPattern));

    if (matches.length === 0) return null;

    // Extract student's hardcoded literal values
    const literalValues = matches.map(m => m[1]);

    // Cross-reference against test case expected outputs (if available)
    const testCases = (exercise && exercise.test_cases) || [];
    const expectedOutputs = testCases
      .map(tc => (tc.expected || '').toString().trim())
      .filter(Boolean);

    // Check if any hardcoded literal matches an expected answer
    const matchesExpected = expectedOutputs.length > 0
      ? literalValues.some(val => expectedOutputs.some(exp => exp.includes(val)))
      : null; // null = no test cases to compare against

    // Check computation logic
    const hasOperations = /[\+\-\*\/\%\(\)]/g.test(code);
    const hasVariables = /\b(int|float|double|long|short)\s+\w+\s*=/g.test(code);
    const hasLoops = /(for|while|do)\s*[\({]/g.test(code);
    const hasConditionals = /(if|else|switch)\s*[\({]/g.test(code);

    const computationScore =
      (hasOperations ? 1 : 0) +
      (hasVariables ? 1 : 0) +
      (hasLoops ? 1 : 0) +
      (hasConditionals ? 1 : 0);

    // Clear hardcoding: outputs literals with minimal computation
    if (computationScore < 2 && !hasLoops) {
      return {
        type: 'HARDCODING',
        severity: 'HIGH',
        evidence: {
          summary: matchesExpected === true
            ? `Found ${matches.length} direct numeric output(s) matching expected answer with minimal computation logic`
            : `Found ${matches.length} direct numeric output(s) with minimal computation logic`,
          literalOutputCount: matches.length,
          computationScore,
          literalValues,
          matchesExpectedOutput: matchesExpected,
          confidence: matchesExpected === true ? 0.85 : 0.5,
          innocent_explanation: matchesExpected === true
            ? 'Student may have used a direct formula (e.g., n*(n+1)/2) instead of a loop. Computation score is heuristic and may not capture all valid approaches.'
            : 'No test cases available to cross-reference. Hardcoded literals without expected output correlation are less suspicious.',
        },
      };
    }

    // Ambiguous: has loops but no variables, outputs literals
    if (computationScore < 3 && hasLoops && !hasVariables) {
      return {
        type: 'HARDCODING',
        severity: 'MEDIUM',
        evidence: {
          summary: 'Outputs contain literals with loop present but no variables — suspicious computation pattern',
          literalOutputCount: matches.length,
          computationScore,
          literalValues,
          matchesExpectedOutput: matchesExpected,
          confidence: matchesExpected === true ? 0.6 : 0.35,
          innocent_explanation: 'Student may be using a loop to print pre-computed values, or the exercise may only require literal output formatting. Loops with constants are not uncommon in introductory exercises.',
        },
      };
    }

    return null;
  } catch (err) {
    console.error('Error in checkHardcoding:', err);
    return null;
  }
}

/**
 * Check for blank/template-only submissions.
 * Per the paper: "flags attempts where the student has made no meaningful changes
 * to the starter code."
 *
 * @param {string} code - The student's submitted code
 * @param {string} starterCode - The exercise's starter code
 * @returns {object|null} - Flag object if blank/template-only, null otherwise
 */
function checkBlankTemplate(code, starterCode) {
  const normalizedCode = code.trim();
  const normalizedStarter = starterCode.trim();

  if (normalizedCode === '' && normalizedStarter !== '') {
    return {
      type: 'BLANK_TEMPLATE',
      severity: 'HIGH',
      evidence: {
        summary: 'Submission is empty',
        codeLength: code.length,
        starterCodeLength: starterCode.length,
        confidence: 1.0,
        innocent_explanation: 'An empty submission is unambiguous. The student likely did not attempt the exercise.',
      },
    };
  }

  if (normalizedCode === normalizedStarter) {
    if (code === starterCode) {
      return {
        type: 'BLANK_TEMPLATE',
        severity: 'HIGH',
        evidence: {
          summary: 'Submission is identical to starter code',
          codeLength: code.length,
          starterCodeLength: starterCode.length,
          confidence: 1.0,
          innocent_explanation: 'Submitting starter code unchanged is an unambiguous violation. Whitespace-only changes are correctly excluded.',
        },
      };
    } else {
      return null; // Only whitespace differences — not a violation
    }
  }

  return null;
}

/**
 * Extended hardcoding check — catches bypass techniques the basic check misses.
 *
 * Detects these evasion patterns:
 *   1. printf/puts with literal format strings that match expected output
 *   2. putchar/fputc in a loop outputting expected string char by char
 *   3. Return-value evasion (returning expected value as process exit code)
 *   4. std::ostringstream with literal concatenation matching expected
 *   5. String-based output via std::string constructor from literal
 *
 * @param {string} code - The student's submitted code
 * @param {object} exercise - The exercise object (contains test_cases)
 * @param {object} submission - The submission object
 * @returns {object|null} - Flag object if hardcoding detected, null otherwise
 */
function checkHardcodingExtended(code, exercise, submission) {
  try {
    const testCases = (exercise && exercise.test_cases) || [];
    const expectedOutputs = testCases
      .map(tc => (tc.expected || '').toString().trim())
      .filter(Boolean);

    const hasOperations = /[\+\-\*\/\%\(\)]/g.test(code);
    const hasVariables = /\b(int|float|double|long|short)\s+\w+\s*=/g.test(code);
    const hasLoops = /(for|while|do)\s*[\({]/g.test(code);
    const hasConditionals = /(if|else|switch)\s*[\({]/g.test(code);

    const computationScore =
      (hasOperations ? 1 : 0) +
      (hasVariables ? 1 : 0) +
      (hasLoops ? 1 : 0) +
      (hasConditionals ? 1 : 0);

    const flags = [];

    // 1. printf/puts literal pattern
    const printfPattern = /(?:printf|puts)\s*\(\s*"([^"]*)"\s*\)\s*;/g;
    const printfMatches = Array.from(code.matchAll(printfPattern));
    for (const match of printfMatches) {
      const literalValue = match[1].trim();
      if (expectedOutputs.length > 0 && expectedOutputs.some(exp => exp === literalValue || exp.includes(literalValue))) {
        flags.push({
          type: 'HARDCODING',
          severity: 'HIGH',
          evidence: {
            summary: `printf/puts output matches expected result using literal: "${literalValue}"`,
            pattern: 'printf_literal',
            literalValue,
            matchesExpectedOutput: true,
            confidence: 0.8,
            innocent_explanation: 'Student may be printing a known result for debugging, or the exercise may have a trivial expected output. printf with format strings is normal C++ practice.',
          },
        });
      }
    }

    // 2. putchar/fputc loop pattern
    const hasPutcharLike = /\b(putchar|fputc|putc)\s*\(/.test(code);
    const hasLoop = /(for|while|do)\s*[\({]/g.test(code);
    if (hasPutcharLike && hasLoop) {
      const stringLiteralRegex = /"(?:[^"\\]|\\.)*"/g;
      const stringMatches = code.match(stringLiteralRegex) || [];
      for (const sm of stringMatches) {
        const content = sm.slice(1, -1);
        if (content && expectedOutputs.length > 0 && expectedOutputs.some(exp => exp === content || exp.includes(content))) {
          flags.push({
            type: 'HARDCODING',
            severity: 'HIGH',
            evidence: {
              summary: `putchar/fputc loop outputs expected result by iterating over literal string: "${content}"`,
              pattern: 'putchar_loop',
              literalValue: content,
              matchesExpectedOutput: true,
              confidence: 0.75,
              innocent_explanation: 'Student may be implementing a character-by-character output as required by the exercise specification. putchar loops are a legitimate C++ technique.',
            },
          });
        }
      }
    }

    // 3. Return-value evasion
    if (/return\s+\d+\s*;/.test(code)) {
      const returnPattern = /return\s+(\d+)\s*;/g;
      const returnMatches = Array.from(code.matchAll(returnPattern));
      for (const match of returnMatches) {
        const literalValue = match[1];
        if (expectedOutputs.length > 0 && expectedOutputs.some(exp => exp === literalValue)) {
          flags.push({
            type: 'HARDCODING',
            severity: 'MEDIUM',
            evidence: {
              summary: `Program returns hardcoded value "${literalValue}" matching expected output via process exit code`,
              pattern: 'return_value',
              literalValue,
              matchesExpectedOutput: true,
              confidence: 0.5,
              innocent_explanation: 'Returning a literal from main() is standard C++ practice. Many exercises require a specific return value that matches the expected output threshold.',
            },
          });
        }
      }
    }

    // 4. ostringstream with literal pattern
    const ossPattern = /(?:stringstream|ostringstream|istringstream)\s+\w+\s*(?:\(\))?\s*;[\s\S]*?<<\s*"([^"]*)"/g;
    const ossMatches = Array.from(code.matchAll(ossPattern));
    for (const match of ossMatches) {
      const literalValue = match[1].trim();
      if (expectedOutputs.length > 0 && expectedOutputs.some(exp => exp === literalValue || exp.includes(literalValue))) {
        flags.push({
          type: 'HARDCODING',
          severity: 'HIGH',
          evidence: {
            summary: `ostringstream output contains hardcoded literal matching expected result: "${literalValue}"`,
            pattern: 'ostringstream_literal',
            literalValue,
            matchesExpectedOutput: true,
            confidence: 0.85,
            innocent_explanation: 'ostringstream with string concatenation is standard C++. The literal may be part of a larger formatted output, not standalone hardcoding.',
          },
        });
      }
    }

    // 5. std::string constructor/assignment from literal
    const stringCtorPattern = /std::string\s+\w+\s*\(\s*"([^"]*)"\s*\)/g;
    const stringAssignPattern = /std::string\s+\w+\s*=\s*"([^"]*)"/g;
    const stringLiteralMatches = [
      ...Array.from(code.matchAll(stringCtorPattern)),
      ...Array.from(code.matchAll(stringAssignPattern)),
    ];
    for (const match of stringLiteralMatches) {
      const literalValue = match[1].trim();
      if (expectedOutputs.length > 0 && expectedOutputs.some(exp => exp === literalValue || exp.includes(literalValue))) {
        flags.push({
          type: 'HARDCODING',
          severity: 'HIGH',
          evidence: {
            summary: `std::string initialized with literal matching expected result: "${literalValue}"`,
            pattern: 'string_ctor_literal',
            literalValue,
            matchesExpectedOutput: true,
            confidence: 0.7,
            innocent_explanation: 'std::string construction from literals is normal C++. The string may be used for comparison, not output. Context of usage matters.',
          },
        });
      }
    }

    if (flags.length === 0) return null;

    if (flags.length === 1) return flags[0];

    // Multiple flags: return HIGH severity if any HIGH flag exists
    const highFlags = flags.filter(f => f.severity === 'HIGH');
    if (highFlags.length > 0) {
      return highFlags[0];
    }

    return {
      type: 'HARDCODING',
      severity: 'MEDIUM',
      evidence: {
        summary: flags.map(f => f.evidence.summary || '').join('; '),
        pattern: 'mixed',
        computationScore,
        matchesExpectedOutput: true,
        confidence: 0.55,
        innocent_explanation: 'Multiple hardcoding patterns detected. Review the submission in context — some patterns (printf, ostringstream) are common in legitimate C++ code.',
      },
    };
  } catch (err) {
    console.error('Error in checkHardcodingExtended:', err);
    return null;
  }
}

/**
 * Main function to evaluate integrity of a submission.
 * Runs the two behavioral checks (hardcoding, blank/template) and returns an array of flags.
 *
 * Note: BEHAVIORAL_ANOMALY (instant success, extreme speed) is handled by
 * behavioralAnomalyDetector.js and called separately from the submission controller.
 *
 * Note: CODE_GROWTH_ANOMALY (>30% spike) is handled in submissionController.js.
 *
 * @param {object} params - Object containing all necessary data
 * @param {string} params.code - The submitted code
 * @param {string} params.starterCode - The exercise's starter code
 * @param {number} params.studentId - The student's ID
 * @param {number} params.exerciseId - The exercise ID
 * @param {object} params.submission - The submission object (as it will be stored)
 * @param {object} params.exercise - The exercise object
 * @returns {Promise<Array>} - Array of flag objects (empty if no flags)
 */
async function evaluateIntegrity(params) {
  const { code, starterCode, studentId, exerciseId, submission, exercise } = params;
  const flags = [];

  // 1. Hardcoding detection (basic)
  const hardcodingFlag = checkHardcoding(code, exercise, submission);
  if (hardcodingFlag) {
    flags.push({ ...hardcodingFlag, studentId, exerciseId });
  }

  // 1b. Extended hardcoding detection (advanced bypasses)
  const extendedFlag = checkHardcodingExtended(code, exercise, submission);
  if (extendedFlag) {
    flags.push({ ...extendedFlag, studentId, exerciseId });
  }

  // 2. Blank/template-only detection
  const blankFlag = checkBlankTemplate(code, starterCode);
  if (blankFlag) {
    flags.push({ ...blankFlag, studentId, exerciseId });
  }

  return flags;
}

module.exports = {
  checkHardcoding,
  checkHardcodingExtended,
  checkBlankTemplate,
  evaluateIntegrity,
};

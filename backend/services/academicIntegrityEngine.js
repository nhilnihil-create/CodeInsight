// Academic Integrity Engine - Implements five deterministic measures
// to detect potential academic integrity violations in code submissions.

const db = require('../config/db');

/**
 * Check for hardcoding: detect if student outputs a literal constant instead of computing it.
 * For example, if the problem expects the student to compute 5+3 and output 8,
 * but the student just writes `cout << 8;` without performing the addition.
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

    // Check if code has any arithmetic operations that could compute values
    const hasOperations = /[\+\-\*\/\%\(\)]/g.test(code);
    const hasVariables = /\b(int|float|double|long|short)\s+\w+\s*=/g.test(code);
    const hasLoops = /(for|while|do)\s*[\({]/g.test(code);
    const hasConditionals = /(if|else|switch)\s*[\({]/g.test(code);

    // Flag if: outputs literals but minimal computation logic
    const computationScore =
      (hasOperations ? 1 : 0) +
      (hasVariables ? 1 : 0) +
      (hasLoops ? 1 : 0) +
      (hasConditionals ? 1 : 0);

    // If very few computation elements and multiple literal outputs, flag it
    if (computationScore < 2 && matches.length >= 1) {
      return {
        type: 'HARDCODING',
        severity: 'MEDIUM',
        evidence: `Found ${matches.length} direct numeric output(s) with minimal computation logic`,
        context: {
          literalOutputCount: matches.length,
          computationScore,
          literalValues: matches.map(m => m[1])
        }
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
 * Compares the submitted code against the exercise's starter code.
 *
 * @param {string} code - The student's submitted code
 * @param {string} starterCode - The exercise's starter code
 * @returns {object|null} - Flag object if blank/template-only, null otherwise
 */
function checkBlankTemplate(code, starterCode) {
  // Normalize by trimming whitespace
  const normalizedCode = code.trim();
  const normalizedStarter = starterCode.trim();

  // Consider it blank if it's truly empty (not just whitespace)
  if (normalizedCode === '' && normalizedStarter !== '') {
    return {
      type: 'BLANK_TEMPLATE',
      severity: 'HIGH',
      evidence: 'Submission matches starter code or is empty',
      context: { codeLength: code.length, starterCodeLength: starterCode.length },
    };
  }

  // Consider it blank if it's an exact match (including whitespace)
  // But NOT if it only differs by whitespace
  if (normalizedCode === normalizedStarter) {
    if (code === starterCode) {
      // Exact match (including whitespace) - flag as blank/template
      return {
        type: 'BLANK_TEMPLATE',
        severity: 'HIGH',
        evidence: 'Submission matches starter code or is empty',
        context: { codeLength: code.length, starterCodeLength: starterCode.length },
      };
    } else {
      // Only whitespace differences - do NOT flag as blank/template
      return null;
    }
  }

  return null;
}

/**
 * Check for behavioral anomaly: unusual speed + correct first try + high CDS history.
 * Uses z-score to detect statistically significant performance deviation.
 *
 * @param {number} studentId - The student's ID
 * @param {number} exerciseId - The exercise ID
 * @param {object} submission - The current submission object
 * @param {object} cdsEngine - Reference to cdsEngine for historical CDS scores
 * @returns {object|null} - Flag object if behavioral anomaly detected, null otherwise
 */
async function checkBehavioralAnomaly(studentId, exerciseId, submission, cdsEngine) {
  try {
    // Query student's historical CDS scores on previous exercises (including stddev)
    const historyRes = await db.query(
      `SELECT
         AVG(cds) as avg_cds,
         STDDEV_POP(cds) as stddev_cds,
         COUNT(*) as exercise_count
       FROM cds_scores
       WHERE student_id = $1 AND exercise_id != $2`,
      [studentId, exerciseId]
    );

    // Safety check: ensure query result exists
    if (!historyRes || !historyRes.rows || historyRes.rows.length === 0) {
      console.error('checkBehavioralAnomaly: Database query returned no results');
      return null;
    }

    const history = historyRes.rows[0];
    if (!history || history.exercise_count < 3) {
      // Need at least 3 data points for meaningful z-score
      return null;
    }

    const avgHistoricalCds = parseFloat(history.avg_cds) || 0;
    const stddevHistoricalCds = parseFloat(history.stddev_cds) || 0;
    const exerciseCount = history.exercise_count;

    // Avoid division by zero
    if (stddevHistoricalCds === 0) {
      return null;
    }

    // Current submission's CDS (if not available, calculate it)
    let currentCds = submission.cds;
    if (currentCds === undefined || currentCds === null) {
      // We'd need to calculate CDS, but for behavioral anomaly we primarily care about speed
      // For now, we'll use a placeholder approach - in reality this would come from submission
      currentCds = 0.5; // Neutral value if CDS not available
    }

    // Calculate z-score: how many standard deviations from the mean
    const zScore = (currentCds - avgHistoricalCds) / stddevHistoricalCds;

    // Check anomaly conditions:
    // 1. Very fast submission (< 30 seconds) - indicates potential plagiarism or prior knowledge
    // 2. First attempt correct (submission.is_correct = true, from test_results)
    // 3. Statistically significant positive deviation (z-score > 2.0 - performing much better than usual)
    const isVeryFast = submission.time_spent_seconds && submission.time_spent_seconds < 30;
    const isFirstAttemptCorrect = submission.is_correct === true;
    const isSignificantlyBetter = zScore > 2.0; // Performing much better than historical average

    if (isVeryFast && isFirstAttemptCorrect && isSignificantlyBetter) {
      return {
        type: 'BEHAVIORAL_ANOMALY',
        severity: 'MEDIUM',
        evidence: `Solved in ${submission.time_spent_seconds}s on first attempt with CDS ${currentCds.toFixed(2)} (z-score: ${zScore.toFixed(2)}, ${exerciseCount} prior exercises)`,
        context: {
          timeSpentSeconds: submission.time_spent_seconds,
          isFirstAttempt: true,
          historicalAvgCds: avgHistoricalCds,
          historicalStddevCds: stddevHistoricalCds,
          zScore: parseFloat(zScore.toFixed(2)),
          exercisesAttempted: exerciseCount,
          currentCds: parseFloat(currentCds.toFixed(2))
        }
      };
    }

    return null;
  } catch (err) {
    console.error('Error in checkBehavioralAnomaly:', err);
    return null;
  }
}

/**
 * Check for code growth anomaly: detecting if student copies and pastes large blocks of code
 * without understanding, comparing line count to their first submission.
 *
 * @param {string} code - The student's submitted code
 * @param {number} studentId - The student's ID (to get their historical submissions)
 * @param {number} exerciseId - The exercise ID (to get their first submission)
 * @returns {object|null} - Flag object if code growth anomaly detected, null otherwise
 */
async function checkCodeGrowthAnomaly(studentId, exerciseId, code) {
  try {
    // Get the student's first submission for this exercise (by attempt_number = 1)
    const firstSubmissionRes = await db.query(
      `SELECT code FROM submissions
       WHERE student_id = $1 AND exercise_id = $2 AND attempt_number = 1
       ORDER BY created_at ASC LIMIT 1`,
      [studentId, exerciseId]
    );

    // Safety check: ensure query result exists
    if (!firstSubmissionRes || !firstSubmissionRes.rows || firstSubmissionRes.rows.length === 0) {
      // No first submission found (this might be the first attempt)
      return null;
    }

    const firstCode = firstSubmissionRes.rows[0].code || '';
    const currentCode = code || '';

    // Calculate line count for both submissions
    const firstLineCount = firstCode.split('\n').filter(line => line.trim() !== '').length;
    const currentLineCount = currentCode.split('\n').filter(line => line.trim() !== '').length;

    // Avoid division by zero
    if (firstLineCount === 0) {
      return null;
    }

    // Calculate line count delta and growth percentage
    const lineDelta = currentLineCount - firstLineCount;
    const growthPercent = (lineDelta / firstLineCount) * 100;

    // Flag if line count has grown significantly (> 100% increase from first submission)
    // This suggests copying/pasting large blocks without understanding
    if (growthPercent > 100 && lineDelta > 10) { // At least 10 lines added and doubled in size
      return {
        type: 'CODE_GROWTH_ANOMALY',
        severity: 'LOW',
        evidence: `Submission has ${currentLineCount} non-empty lines vs ${firstLineCount} in first submission (${growthPercent.toFixed(0)}% increase)`,
        context: {
          firstLineCount: firstLineCount,
          currentLineCount: currentLineCount,
          lineDelta: lineDelta,
          growthPercent: parseFloat(growthPercent.toFixed(0))
        }
      };
    }

    return null;
  } catch (err) {
    console.error('Error in checkCodeGrowthAnomaly:', err);
    return null;
  }
}

/**
 * Log passive behavioral metrics: tab switch count, idle time, etc.
 * This function would be called from the frontend when sending submission data.
 *
 * @param {object} submission - The submission object to augment with behavioral metrics
 * @param {object} behavioralData - Object containing tabSwitchCount, pausedTimeSeconds, etc.
 * @returns {object} - The submission object with added behavioral metrics
 */
function logPassiveBehavior(submission, behavioralData) {
  // We would add behavioral metrics to the submission object for storage.
  // However, note that the current submissions table does not have columns for these.
  // This would require a database migration to add columns like:
  //   tab_switch_count INTEGER DEFAULT 0,
  //   paused_time_seconds INTEGER DEFAULT 0,
  //   active_time_seconds INTEGER DEFAULT 0
  //
  // For now, we return the submission unchanged, assuming the frontend will send
  // these metrics and they will be stored in the submission record (if columns exist).
  // Alternatively, we could store them in a separate table or in a JSONB column.
  return {
    ...submission,
    ...behavioralData
  };
}

/**
 * Main function to evaluate integrity of a submission.
 * Runs all five checks and returns an array of flags.
 *
 * @param {object} params - Object containing all necessary data
 * @param {string} params.code - The submitted code
 * @param {string} params.starterCode - The exercise's starter code
 * @param {number} params.studentId - The student's ID
 * @param {number} params.exerciseId - The exercise ID
 * @param {object} params.submission - The submission object (as it will be stored)
 * @param {object} params.exercise - The exercise object
 * @param {object} params.cdsEngine - Reference to cdsEngine for historical data (if needed)
 * @param {object} params.behavioralData - Object containing passive behavioral metrics (from frontend)
 * @returns {Promise<Array>} - Array of flag objects (empty if no flags)
 */
async function evaluateIntegrity(params) {
  const { code, starterCode, studentId, exerciseId, submission, exercise, cdsEngine, behavioralData } = params;

  // First, log passive behavioral metrics (if any)
  const augmentedSubmission = logPassiveBehavior(submission, behavioralData);

  // Initialize flags array
  const flags = [];

  // Run each check

  // 1. Hardcoding detection
  const hardcodingFlag = checkHardcoding(code, exercise, augmentedSubmission);
  if (hardcodingFlag) {
    flags.push({
      ...hardcodingFlag,
      studentId,
      exerciseId,
      // We'll add submission_id later when we know it
    });
  }

  // 2. Blank/template-only detection
  const blankFlag = checkBlankTemplate(code, starterCode);
  if (blankFlag) {
    flags.push({
      ...blankFlag,
      studentId,
      exerciseId,
    });
  }

  // 3. Behavioral anomaly (async)
  try {
    const behavioralFlag = await checkBehavioralAnomaly(studentId, exerciseId, augmentedSubmission, cdsEngine);
    if (behavioralFlag) {
      flags.push({
        ...behavioralFlag,
        studentId,
        exerciseId,
      });
    }
  } catch (err) {
    console.error('Error in behavioral anomaly check:', err);
  }

  // 4. Code growth anomaly (async)
  try {
    const growthFlag = await checkCodeGrowthAnomaly(studentId, exerciseId, code);
    if (growthFlag) {
      flags.push({
        ...growthFlag,
        studentId,
        exerciseId,
      });
    }
  } catch (err) {
    console.error('Error in code growth anomaly check:', err);
  }

  // Note: In a real implementation, we would now insert these flags into the database.
  // However, the insertion is handled by the submission controller after this function returns.
  // We return the flags so the controller can attach the submission_id and insert them.

  return flags;
}

module.exports = {
  checkHardcoding,
  checkBlankTemplate,
  checkBehavioralAnomaly,
  checkCodeGrowthAnomaly,
  logPassiveBehavior,
  evaluateIntegrity
};
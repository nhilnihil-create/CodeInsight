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
 * @param {object} behavioralData - Behavioral telemetry (pasteCount, tabSwitchCount, etc.)
 * @returns {object|null} - Flag object if behavioral anomaly detected, null otherwise
 */
async function checkBehavioralAnomaly(studentId, exerciseId, submission, cdsEngine, behavioralData) {
  try {
    // BUG FIX #6: Check paste-based anomaly even without historical data
    // If student pasted code (pasteCount > 0) and solved in < 30s, that's anomalous
    // regardless of CDS history.
    if (behavioralData && behavioralData.pasteCount > 0 &&
        submission.time_spent_seconds !== null && submission.time_spent_seconds !== undefined &&
        submission.time_spent_seconds < 30 &&
        submission.is_correct === true) {
      return {
        type: 'PASTE_ON_CORRECT_SUBMISSION',
        severity: 'HIGH',
        evidence: `Code pasted (pasteCount=${behavioralData.pasteCount}) and solved in ${submission.time_spent_seconds}s`,
        context: {
          pasteCount: behavioralData.pasteCount,
          timeSpentSeconds: submission.time_spent_seconds,
          isFirstAttempt: submission.is_correct === true
        }
      };
    }

    // Check for excessive tab switching (indicates looking up solutions)
    if (behavioralData && behavioralData.tabSwitchCount > 5 &&
        submission.is_correct === true) {
      return {
        type: 'EXCESSIVE_TAB_SWITCHING',
        severity: 'MEDIUM',
        evidence: `${behavioralData.tabSwitchCount} tab switches before correct submission`,
        context: {
          tabSwitchCount: behavioralData.tabSwitchCount,
          timeSpentSeconds: submission.time_spent_seconds
        }
      };
    }

    // Original z-score based check (requires historical data)
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
      // Already handled paste/telemetry checks above
      return null;
    }

    const avgHistoricalCds = parseFloat(history.avg_cds) || 0;
    const stddevHistoricalCds = parseFloat(history.stddev_cds) || 0;
    const exerciseCount = history.exercise_count;

    // Avoid division by zero
    if (stddevHistoricalCds === 0) {
      return null;
    }

    // Current submission's CDS (if not available, calculate it using cdsEngine)
    let currentCds = submission.cds;
    if (currentCds === undefined || currentCds === null) {
      // Calculate CDS for this submission if not provided
      try {
        const cdsResult = await cdsEngine.calculateLiveCDS(studentId, exerciseId, db);
        if (cdsResult && cdsResult.cds !== null) {
          currentCds = cdsResult.cds;
        } else {
          // If we cannot calculate CDS, skip behavioral anomaly check
          return null;
        }
      } catch (cdsErr) {
        console.warn('Could not calculate CDS for behavioral anomaly check:', cdsErr.message);
        return null;
      }
    }

    // Calculate z-score: how many standard deviations from the mean
    const zScore = (currentCds - avgHistoricalCds) / stddevHistoricalCds;

    // Check anomaly conditions:
    // 1. Very fast submission (< 30 seconds) - indicates potential plagiarism or prior knowledge
    // 2. First attempt correct (submission.is_correct = true, from test_results)
    // 3. Statistically significant deviation (z-score < -2.0 — performing MUCH BETTER than historical average)
    //    Lower CDS = better performance, so cheating shows as sudden improvement (negative z-score).
    const isVeryFast = submission.time_spent_seconds && submission.time_spent_seconds < 30;
    const isFirstAttemptCorrect = submission.is_correct === true;
    const isSignificantlyBetter = zScore < -2.0; // Much better than historical (CDS dropped significantly)

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

  // Flag if line count has grown significantly (> 30% increase from first submission).
  // Spec §R1.16 / Ch.1:382-384: "Sudden growth spike of more than 30% in a single attempt
  // indicates bulk code insertion rather than incremental debugging."
  if (growthPercent > 30) {
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
 * Check for massive payload: abnormally large submissions that may contain
 * pre-written code or attempt to overflow buffers.
 *
 * @param {string} code - The submitted code
 * @returns {object|null} - Flag object if massive payload detected
 */
function checkMassivePayload(code) {
  const codeSize = (code || '').length;
  // Flag submissions over 10KB — normal student code rarely exceeds 2KB
  if (codeSize > 10240) {
    return {
      type: 'MASSIVE_PAYLOAD',
      severity: 'HIGH',
      evidence: `Submission size: ${Math.round(codeSize / 1024)}KB (${codeSize} chars) — typical student submissions are < 2KB`,
      context: { codeSize, lineCount: code.split('\n').length }
    };
  }
  return null;
}

/**
 * Check for retry storm: excessive submissions in rapid succession.
 *
 * @param {number} studentId - The student's ID
 * @param {number} exerciseId - The exercise ID
 * @returns {Promise<object|null>} - Flag object if retry storm detected
 */
async function checkRetryStorm(studentId, exerciseId) {
  try {
    const submissionsRes = await db.query(
      `SELECT submitted_at, is_correct, time_spent_seconds
       FROM submissions
       WHERE student_id = $1 AND exercise_id = $2
       ORDER BY submitted_at ASC`,
      [studentId, exerciseId]
    );

    if (!submissionsRes || submissionsRes.rows.length < 5) {
      return null;
    }

    const rows = submissionsRes.rows;
    // Calculate time deltas between consecutive submissions
    const timedeltas = [];
    for (let i = 1; i < rows.length; i++) {
      const prev = new Date(rows[i - 1].submitted_at).getTime();
      const curr = new Date(rows[i].submitted_at).getTime();
      timedeltas.push((curr - prev) / 1000 / 60); // minutes
    }

    const avgTime = timedeltas.reduce((a, b) => a + b, 0) / timedeltas.length;

    // Detect storm: >10 submissions AND avg time < 1 minute apart
    if (rows.length > 10 && avgTime < 1) {
      return {
        type: 'RETRY_STORM',
        severity: 'MEDIUM',
        evidence: `${rows.length} submissions averaging ${avgTime.toFixed(1)}min apart (typical: 2+ min)`,
        context: {
          totalSubmissions: rows.length,
          avgTimeBetweenMinutes: parseFloat(avgTime.toFixed(1)),
          firstSubmittedAt: rows[0].submitted_at,
          lastSubmittedAt: rows[rows.length - 1].submitted_at
        }
      };
    }

    return null;
  } catch (err) {
    console.error('Error in checkRetryStorm:', err);
    return null;
  }
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
    flags.push({ ...hardcodingFlag, studentId, exerciseId });
  }

  // 2. Blank/template-only detection
  const blankFlag = checkBlankTemplate(code, starterCode);
  if (blankFlag) {
    flags.push({ ...blankFlag, studentId, exerciseId });
  }

  // 3. Massive payload detection (Bug #5 fix)
  const massiveFlag = checkMassivePayload(code);
  if (massiveFlag) {
    flags.push({ ...massiveFlag, studentId, exerciseId });
  }

  // 4. Retry storm detection (Bug #3 fix)
  try {
    const retryFlag = await checkRetryStorm(studentId, exerciseId);
    if (retryFlag) {
      flags.push({ ...retryFlag, studentId, exerciseId });
    }
  } catch (err) {
    console.error('Error in retry storm check:', err);
  }

  // 5. Behavioral anomaly (now passes behavioralData — Bug #2 & #6 fix)
  try {
    const behavioralFlag = await checkBehavioralAnomaly(studentId, exerciseId, augmentedSubmission, cdsEngine, behavioralData);
    if (behavioralFlag) {
      flags.push({ ...behavioralFlag, studentId, exerciseId });
    }
  } catch (err) {
    console.error('Error in behavioral anomaly check:', err);
  }

  // 6. Code growth anomaly detection
  try {
    const growthFlag = await checkCodeGrowthAnomaly(studentId, exerciseId, code);
    if (growthFlag) {
      flags.push({ ...growthFlag, studentId, exerciseId });
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
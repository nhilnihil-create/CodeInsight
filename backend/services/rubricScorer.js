/**
 * rubricScorer.js
 *
 * Deterministic 4-pillar rubric scoring for Assessment Mode submissions.
 * Zero AI — all computation uses structured data from the database.
 *
 * Pillars:
 *   1. Functional Correctness — % of test cases passed
 *   2. Efficiency — student time vs class median (lower is better, capped at 100)
 *   3. Standards — cppcheck warning penalty (15 points per warning, floored at 0)
 *   4. Integrity — integrity flag penalty (30 points per flag, floored at 0)
 *
 * Weighted total = Σ(pillarScore × weight / 100)
 */

const db = require('../config/db');

/**
 * Score an assessment-mode submission.
 *
 * @param {number} submissionId - The submission ID
 * @param {number} exerciseId   - The exercise ID
 * @param {object} rubricConfig - Pillar weights (e.g. { functional: 40, efficiency: 25, standards: 20, integrity: 15 })
 * @returns {Promise<{ pillars: { functional, efficiency, standards, integrity }, weightedTotal: number, rubricConfig: object }>}
 */
exports.scoreSubmission = async (submissionId, exerciseId, rubricConfig = {}) => {
  // Defaults
  const weights = {
    functional: rubricConfig.functional || 40,
    efficiency: rubricConfig.efficiency || 25,
    standards: rubricConfig.standards || 20,
    integrity: rubricConfig.integrity || 15,
  };

  // Fetch submission data
  const subRes = await db.query(
    `SELECT test_results, time_spent_seconds, cppcheck_warnings, student_id
     FROM submissions WHERE id = $1`,
    [submissionId]
  );
  if (!subRes.rows.length) {
    return { pillars: { functional: 0, efficiency: 0, standards: 0, integrity: 0 }, weightedTotal: 0, rubricConfig: weights };
  }

  const submission = subRes.rows[0];
  const testResults = submission.test_results || [];
  const timeSec = submission.time_spent_seconds || 0;
  const cppcheckWarnings = submission.cppcheck_warnings || [];
  const studentId = submission.student_id;

  // 1. Functional Correctness: passed / total × 100
  const totalVisible = testResults.filter(r => !r.hidden).length || testResults.length;
  const passedVisible = testResults.filter(r => r.passed && (!r.hidden || true)).length;
  const functional = totalVisible > 0 ? Math.round((passedVisible / totalVisible) * 100) : 0;

  // 2. Efficiency: min(medianTime / studentTime × 100, 100)
  // Query class median time for this exercise (assessment mode only)
  const medianRes = await db.query(
    `SELECT PERCENTILE_CONT(0.5) WITHIN GROUP (ORDER BY time_spent_seconds) AS median_time
     FROM submissions s
     JOIN exercises e ON e.id = s.exercise_id
     WHERE s.exercise_id = $1 AND s.time_spent_seconds > 0
       AND e.mode = 'assessment'
       AND s.is_practice IS NOT TRUE`,
    [exerciseId]
  );
  const medianTime = parseFloat(medianRes.rows[0]?.median_time || 0);
  const efficiency = timeSec > 0 && medianTime > 0
    ? Math.min(Math.round((medianTime / timeSec) * 100), 100)
    : 50; // neutral score if no time data

  // 3. Standards: max(0, 100 - cppcheckWarningCount × 15)
  const warningCount = Array.isArray(cppcheckWarnings) ? cppcheckWarnings.length : 0;
  const standards = Math.max(0, 100 - warningCount * 15);

  // 4. Integrity: max(0, 100 - integrityFlagCount × 30)
  const flagRes = await db.query(
    `SELECT COUNT(*) AS flag_count FROM integrity_flags
     WHERE student_id = $1 AND exercise_id = $2 AND status = 'flagged'`,
    [studentId, exerciseId]
  );
  const flagCount = parseInt(flagRes.rows[0]?.flag_count || 0);
  const integrity = Math.max(0, 100 - flagCount * 30);

  // Weighted total
  const weightedTotal = Math.round(
    (functional * weights.functional / 100) +
    (efficiency * weights.efficiency / 100) +
    (standards * weights.standards / 100) +
    (integrity * weights.integrity / 100)
  );

  return {
    pillars: { functional, efficiency, standards, integrity },
    weightedTotal,
    rubricConfig: weights,
    details: {
      medianTime,
      studentTime: timeSec,
      cppcheckWarningCount: warningCount,
      integrityFlagCount: flagCount,
      passedVisible,
      totalVisible,
    },
  };
};

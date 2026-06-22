/**
 * backend/services/behavioralAnomalyDetector.js
 *
 * Paper flag #3: Behavioral Anomaly Detection
 *
 * Two detectors:
 *   1. INSTANT_SUCCESS — A student who was struggling (3+ failed attempts)
 *      suddenly submits a correct solution with no prior correct submissions.
 *   2. EXTREME_SPEED — A student completes the exercise significantly faster
 *      than the class average (>2 standard deviations below mean).
 *
 * These are contextual indicators for instructor review, not automatic verdicts.
 */

const db = require('../config/db');

// ── Thresholds ──────────────────────────────────────────────────────────────

const MIN_PRIOR_FAILURES = 8;       // Minimum failed attempts before instant success is suspicious
const SPEED_ZSCORE_THRESHOLD = 2.5; // Number of robust std devs below median for extreme speed flag
const SPEED_ABSOLUTE_FLOOR = 60;    // Never flag if time exceeds this (seconds)
const FAILURE_WINDOW_HOURS = 24;    // Only count failures within this window

// ── Detector 1: Instant Success ─────────────────────────────────────────────

/**
 * Detect "instant success" — a student who was struggling suddenly submits
 * a correct solution with no prior correct submissions.
 *
 * @param {object} params
 * @param {number} params.studentId
 * @param {number} params.exerciseId
 * @param {boolean} params.is_correct — whether the current submission passed
 * @param {number} params.attempt_number — current attempt number
 * @returns {Promise<object|null>} — flag object or null
 */
async function detectInstantSuccess({ studentId, exerciseId, is_correct, attempt_number, submissionId }) {
  // Only relevant if current submission is correct
  if (!is_correct) return null;

  // Get all prior submissions for this student+exercise within the time window, excluding current
  const cutoff = new Date(Date.now() - FAILURE_WINDOW_HOURS * 60 * 60 * 1000);
  const priorRes = await db.query(
    `SELECT attempt_number, is_correct, submitted_at
     FROM submissions
     WHERE student_id = $1 AND exercise_id = $2 AND id != $3
       AND submitted_at > $4
     ORDER BY attempt_number ASC`,
    [studentId, exerciseId, submissionId || -1, cutoff]
  );

  const priorSubmissions = priorRes.rows;

  // Need at least MIN_PRIOR_FAILURES prior attempts
  if (priorSubmissions.length < MIN_PRIOR_FAILURES) return null;

  // Check if ALL prior submissions were failures
  const priorFailures = priorSubmissions.filter(s => !s.is_correct);
  const priorSuccesses = priorSubmissions.filter(s => s.is_correct);

  // Only flag if: 5+ prior failures AND zero prior successes (within 24h window)
  if (priorFailures.length >= MIN_PRIOR_FAILURES && priorSuccesses.length === 0) {
    return {
      type: 'BEHAVIORAL_ANOMALY',
      severity: 'LOW',
      evidence: {
        summary: `Student had ${priorFailures.length} consecutive failures before this correct submission (attempt #${attempt_number}, within ${FAILURE_WINDOW_HOURS}h)`,
        subtype: 'INSTANT_SUCCESS',
        priorFailureCount: priorFailures.length,
        currentAttempt: attempt_number,
        windowHours: FAILURE_WINDOW_HOURS,
        confidence: 0.35,
        innocent_explanation: 'Student may have had a legitimate breakthrough after studying, received help from a TA, or the exercise difficulty decreased. 5+ failures is common for difficult problems and does not necessarily indicate cheating.',
      },
      context_behaviors: [
        `Subtype: INSTANT_SUCCESS`,
        `Prior failures: ${priorFailures.length}`,
        `Current attempt: #${attempt_number}`,
        `Window: ${FAILURE_WINDOW_HOURS}h`,
        `Pattern: Struggling student suddenly solved correctly`,
      ],
    };
  }

  return null;
}

// ── Detector 2: Extreme Speed ───────────────────────────────────────────────

/**
 * Detect "extreme speed" — a student completes the exercise significantly
 * faster than the class median (>2.5 robust standard deviations below median).
 * Uses Median Absolute Deviation (MAD) for robust statistics resistant to skew.
 *
 * @param {object} params
 * @param {number} params.studentId
 * @param {number} params.exerciseId
 * @param {boolean} params.is_correct — whether the current submission passed
 * @param {number} params.time_spent_seconds — time spent on this submission
 * @returns {Promise<object|null>} — flag object or null
 */
async function detectExtremeSpeed({ studentId, exerciseId, is_correct, time_spent_seconds }) {
  // Only relevant if current submission is correct and has a time value
  if (!is_correct || !time_spent_seconds || time_spent_seconds <= 0) return null;

  // Absolute floor: never flag if time exceeds reasonable minimum
  if (time_spent_seconds > SPEED_ABSOLUTE_FLOOR) return null;

  // Get all students' fastest correct submission times for this exercise
  const classRes = await db.query(
    `SELECT s.student_id, MIN(s.time_spent_seconds) AS fastest_time
     FROM submissions s
     JOIN exercises e ON s.exercise_id = e.id
     WHERE s.exercise_id = $1
       AND s.is_correct = true
       AND s.time_spent_seconds > 0
      GROUP BY s.student_id`,
    [exerciseId]
  );

  if (classRes.rows.length < 5) return null; // Need sufficient class data

  const fastestTimes = classRes.rows.map(r => Number(r.fastest_time));

  // Robust statistics: median + MAD (Median Absolute Deviation)
  const sorted = [...fastestTimes].sort((a, b) => a - b);
  const mid = Math.floor(sorted.length / 2);
  const classMedian = sorted.length % 2 ? sorted[mid] : (sorted[mid - 1] + sorted[mid]) / 2;
  const absDeviations = fastestTimes.map(t => Math.abs(t - classMedian)).sort((a, b) => a - b);
  const madMid = Math.floor(absDeviations.length / 2);
  const mad = absDeviations.length % 2 ? absDeviations[madMid] : (absDeviations[madMid - 1] + absDeviations[madMid]) / 2;
  const robustStddev = 1.4826 * mad; // 1.4826 makes MAD consistent with stddev for normal dist

  // Avoid flagging when there's no meaningful variance
  if (robustStddev === 0 || classMedian === 0) return null;

  const robustZscore = (time_spent_seconds - classMedian) / robustStddev;

  // Flag if student is MORE than 2.5 robust standard deviations faster than the median
  if (robustZscore < -SPEED_ZSCORE_THRESHOLD) {
    return {
      type: 'BEHAVIORAL_ANOMALY',
      severity: 'LOW',
      evidence: {
        summary: `Student completed exercise in ${time_spent_seconds}s (class median: ${Math.round(classMedian)}s, robust z-score: ${robustZscore.toFixed(2)})`,
        subtype: 'EXTREME_SPEED',
        studentTime: time_spent_seconds,
        classMedian: Math.round(classMedian),
        classMAD: Math.round(mad * 100) / 100,
        robustZscore: parseFloat(robustZscore.toFixed(2)),
        classSize: fastestTimes.length,
        absoluteFloor: SPEED_ABSOLUTE_FLOOR,
        confidence: 0.45,
        innocent_explanation: 'Student may have prior experience, used a known algorithm pattern, or the exercise was simpler than average. Robust statistics used but individual variation is expected. Fast completion alone is not evidence of cheating.',
      },
      context_behaviors: [
        `Subtype: EXTREME_SPEED`,
        `Student time: ${time_spent_seconds}s`,
        `Class median: ${Math.round(classMedian)}s`,
        `Robust Z-score: ${robustZscore.toFixed(2)} (threshold: -${SPEED_ZSCORE_THRESHOLD})`,
        `Class size: ${fastestTimes.length}`,
        `Pattern: Significantly faster than classmates`,
      ],
    };
  }

  return null;
}



// ── Orchestrator ────────────────────────────────────────────────────────────

/**
 * Run all behavioral anomaly detectors and return any flags.
 *
 * @param {object} params
 * @returns {Promise<Array>} — array of flag objects (empty if no anomalies)
 */
async function detectBehavioralAnomalies(params) {
  const flags = [];

  try {
    const instantFlag = await detectInstantSuccess(params);
    if (instantFlag) flags.push(instantFlag);
  } catch (err) {
    console.error('Error in instant success detection:', err);
  }

  try {
    const speedFlag = await detectExtremeSpeed(params);
    if (speedFlag) flags.push(speedFlag);
  } catch (err) {
    console.error('Error in extreme speed detection:', err);
  }

  return flags;
}

module.exports = {
  detectInstantSuccess,
  detectExtremeSpeed,
  detectBehavioralAnomalies,
};

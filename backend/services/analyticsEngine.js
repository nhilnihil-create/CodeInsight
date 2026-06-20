/**
 * backend/services/analyticsEngine.js
 *
 * Algorithmic at-risk student analytics.
 * Pure heuristics — no AI, no LLM, no proxy calls.
 *
 * Tracks:
 *   - RETRY_STORM: >10 consecutive failures on same exercise within 30 min
 *   - LEARNING_PLATEAU: declining rolling completion rate across sequential exercises
 *
 * Exposes:
 *   - trackSubmission(studentId, exerciseId, isCorrect) — intercept telemetry
 *   - detectRetryStorm(studentId, exerciseId) — check for retry storm
 *   - detectLearningPlateau(studentId, sectionId) — check for plateau
 *   - getDashboardAlerts(sectionId) — compiled alerts sorted by severity
 */

const db = require('../config/db');

const RETRY_STORM_THRESHOLD = 10;
const RETRY_STORM_WINDOW_MIN = 30;
const PLATEAU_WINDOW_EXERCISES = 3; // Min exercises to detect plateau

/**
 * Intercept a submission event and check for at-risk patterns.
 * Non-blocking: fires checks asynchronously, logs to alerts table.
 *
 * @param {Object} params
 * @param {number} params.studentId
 * @param {number} params.exerciseId
 * @param {boolean} params.isCorrect
 * @param {number} params.sectionId
 * @param {number} params.attemptNumber
 */
async function trackSubmission({ studentId, exerciseId, isCorrect, sectionId, attemptNumber }) {
  // Check for retry storm on failures
  if (!isCorrect && attemptNumber > 1) {
    await detectRetryStorm(studentId, exerciseId, sectionId);
  }

  // Check for learning plateau after each submission
  await detectLearningPlateau(studentId, sectionId);
}

/**
 * Detect RETRY_STORM: >10 consecutive submission failures on the same
 * exercise within a 30-minute window.
 *
 * Creates an alert if threshold is crossed.
 */
async function detectRetryStorm(studentId, exerciseId, sectionId) {
  try {
    // Get recent submissions for this student+exercise, ordered by time
    const recentSubs = await db.query(
      `SELECT id, is_correct, submitted_at, attempt_number
       FROM submissions
       WHERE student_id = $1 AND exercise_id = $2
         AND submitted_at > NOW() - INTERVAL '${RETRY_STORM_WINDOW_MIN} minutes'
       ORDER BY submitted_at DESC`,
      [studentId, exerciseId]
    );

    // Count consecutive failures from most recent
    let consecutiveFailures = 0;
    for (const sub of recentSubs.rows) {
      if (!sub.is_correct) {
        consecutiveFailures++;
      } else {
        break; // A success breaks the streak
      }
    }

    if (consecutiveFailures >= RETRY_STORM_THRESHOLD) {
      // Check if we already flagged this recently (within the window)
      const existingFlag = await db.query(
        `SELECT id FROM integrity_flags
         WHERE student_id = $1 AND exercise_id = $2
           AND flag_type = 'RETRY_STORM'
           AND created_at > NOW() - INTERVAL '${RETRY_STORM_WINDOW_MIN} minutes'`,
        [studentId, exerciseId]
      );

      if (existingFlag.rows.length === 0) {
        // Create the integrity flag
        await db.query(
          `INSERT INTO integrity_flags (section_id, exercise_id, student_id, flag_type, severity, evidence, status, created_at)
           VALUES ($1, $2, $3, 'RETRY_STORM', 'high', $4::jsonb, 'open', NOW())`,
          [sectionId, exerciseId, studentId, JSON.stringify({
            consecutive_failures: consecutiveFailures,
            window_minutes: RETRY_STORM_WINDOW_MIN,
            threshold: RETRY_STORM_THRESHOLD,
          })]
        );

        console.log(`[Analytics] RETRY_STORM flagged: student ${studentId}, exercise ${exerciseId}, ${consecutiveFailures} consecutive failures`);
      }

      return {
        triggered: true,
        type: 'RETRY_STORM',
        consecutiveFailures,
        threshold: RETRY_STORM_THRESHOLD,
      };
    }

    return { triggered: false };
  } catch (err) {
    console.warn('[Analytics] Retry storm detection failed:', err.message);
    return { triggered: false };
  }
}

/**
 * Detect LEARNING_PLATEAU: a student's rolling completion rate drops
 * across their last PLATEAU_WINDOW_EXERCISES sequential exercises.
 *
 * Completion rate = (first-attempt correct submissions) / (total exercises attempted)
 * Plateau = last N exercises have lower completion rate than the N exercises before.
 */
async function detectLearningPlateau(studentId, sectionId) {
  try {
    // Get student's exercise history in this section, ordered by submission time
    const history = await db.query(
      `SELECT
         s.exercise_id,
         e.title AS exercise_title,
         c.name AS concept_name,
         MIN(s.attempt_number) AS first_attempt,
         MIN(CASE WHEN s.is_correct = true THEN s.attempt_number END) AS correct_attempt,
         COUNT(*) AS total_attempts,
         BOOL_OR(s.is_correct = true) AS eventually_correct,
         MIN(s.submitted_at) AS first_submission_at
       FROM submissions s
       JOIN exercises e ON e.id = s.exercise_id
       LEFT JOIN concepts c ON c.id = e.concept_id
       WHERE s.student_id = $1 AND e.section_id = $2
       GROUP BY s.exercise_id, e.title, c.name
       ORDER BY MIN(s.submitted_at) ASC`,
      [studentId, sectionId]
    );

    if (history.rows.length < PLATEAU_WINDOW_EXERCISES * 2) {
      // Not enough data to detect a plateau
      return { triggered: false, reason: 'insufficient_data' };
    }

    const exercises = history.rows;

    // Calculate per-exercise completion (1 if first-attempt correct, 0.5 if eventually correct, 0 if never)
    const completionScores = exercises.map(ex => {
      if (ex.first_attempt === 1 && ex.correct_attempt === 1) return 1.0;
      if (ex.eventually_correct) return 0.5;
      return 0.0;
    });

    // Compare rolling windows
    const windowSize = PLATEAU_WINDOW_EXERCISES;
    const recent = completionScores.slice(-windowSize);
    const previous = completionScores.slice(-windowSize * 2, -windowSize);

    const recentAvg = recent.reduce((a, b) => a + b, 0) / recent.length;
    const previousAvg = previous.reduce((a, b) => a + b, 0) / previous.length;

    // Plateau detected when recent avg drops below previous avg by a significant margin
    const dropThreshold = 0.2; // 20% drop
    if (recentAvg < previousAvg - dropThreshold && previousAvg > 0) {
      // Check if already flagged recently
      const existing = await db.query(
        `SELECT id FROM alerts
         WHERE student_id = $1 AND exercise_id = (
           SELECT id FROM exercises WHERE section_id = $2 ORDER BY created_at DESC LIMIT 1
         ) AND classification = 'LEARNING_PLATEAU'
         AND created_at > NOW() - INTERVAL '1 hour'`,
        [studentId, sectionId]
      );

      if (existing.rows.length === 0) {
        // Create alert
        const latestExercise = exercises[exercises.length - 1];
        await db.query(
          `INSERT INTO alerts (student_id, exercise_id, section_id, cds_score, classification, concept_name, created_at)
           VALUES ($1, $2, $3, $4, 'LEARNING_PLATEAU', $5, NOW())`,
          [
            studentId,
            latestExercise.exercise_id,
            sectionId,
            parseFloat((1 - recentAvg).toFixed(4)), // Invert: lower completion = higher difficulty
            'LEARNING_PLATEAU',
            latestExercise.concept_name || 'Unknown',
          ]
        );

        console.log(`[Analytics] LEARNING_PLATEAU flagged: student ${studentId}, section ${sectionId}, ${previousAvg.toFixed(2)} → ${recentAvg.toFixed(2)}`);
      }

      return {
        triggered: true,
        type: 'LEARNING_PLATEAU',
        previousAvg: parseFloat(previousAvg.toFixed(4)),
        recentAvg: parseFloat(recentAvg.toFixed(4)),
        drop: parseFloat((previousAvg - recentAvg).toFixed(4)),
      };
    }

    return {
      triggered: false,
      previousAvg: parseFloat(previousAvg.toFixed(4)),
      recentAvg: parseFloat(recentAvg.toFixed(4)),
    };
  } catch (err) {
    console.warn('[Analytics] Learning plateau detection failed:', err.message);
    return { triggered: false };
  }
}

/**
 * Get compiled dashboard alerts for a section.
 * Returns both CDS-based alerts and analytics-engine flags, sorted by severity.
 *
 * Severity order: critical > high > moderate > low
 *   - RETRY_STORM → high
 *   - LEARNING_PLATEAU → moderate
 *   - CDS High classification → based on CDS score
 */
async function getDashboardAlerts(sectionId) {
  try {
    // Combine analytics flags (RETRY_STORM, LEARNING_PLATEAU) with CDS alerts
    const alerts = await db.query(
      `SELECT
         al.id,
         al.student_id,
         al.exercise_id,
         al.section_id,
         al.classification,
         al.cds_score,
         al.concept_name,
         al.created_at,
         al.is_reviewed,
         u.name AS student_name,
         u.email AS student_email,
         ex.title AS exercise_title,
         CASE
           WHEN al.classification = 'RETRY_STORM' THEN 'high'
           WHEN al.classification = 'LEARNING_PLATEAU' THEN 'moderate'
            WHEN al.cds_score > 0.80 THEN 'critical'
            WHEN al.cds_score > 0.60 THEN 'high'
            WHEN al.cds_score > 0.40 THEN 'moderate'
           ELSE 'low'
         END AS severity,
         (SELECT COUNT(*)::INTEGER FROM submissions
          WHERE student_id = al.student_id AND exercise_id = al.exercise_id AND is_correct = false) AS consecutive_failures
       FROM alerts al
       JOIN users u ON u.id = al.student_id
       JOIN exercises ex ON ex.id = al.exercise_id
       WHERE al.section_id = $1
         AND al.is_reviewed = false
       ORDER BY
         CASE
           WHEN al.classification = 'RETRY_STORM' THEN 1
            WHEN al.cds_score > 0.80 THEN 2
            WHEN al.cds_score > 0.60 THEN 3
           WHEN al.classification = 'LEARNING_PLATEAU' THEN 4
           ELSE 5
         END,
         al.cds_score DESC,
         al.created_at DESC`,
      [sectionId]
    );

    // Also fetch open integrity flags that are analytics-related
    const integrityAlerts = await db.query(
      `SELECT
         fl.id,
         fl.student_id,
         fl.exercise_id,
         fl.section_id,
         fl.flag_type AS classification,
         fl.severity,
         fl.evidence,
         fl.created_at,
         fl.status AS is_reviewed,
         u.name AS student_name,
         u.email AS student_email,
         ex.title AS exercise_title,
         fl.severity,
         NULL AS cds_score,
         NULL AS concept_name
       FROM integrity_flags fl
       JOIN users u ON u.id = fl.student_id
       JOIN exercises ex ON ex.id = fl.exercise_id
       WHERE fl.section_id = $1
         AND fl.status = 'open'
         AND fl.flag_type IN ('RETRY_STORM', 'growth_velocity_anomaly', 'blank_template_abuse')
       ORDER BY
         CASE fl.severity
           WHEN 'critical' THEN 1
           WHEN 'high' THEN 2
           WHEN 'moderate' THEN 3
           ELSE 4
         END`,
      [sectionId]
    );

    // Merge and deduplicate by student+exercise
    const allAlerts = [...alerts.rows, ...integrityAlerts.rows];
    const seen = new Set();
    const deduplicated = [];

    for (const alert of allAlerts) {
      const key = `${alert.student_id}-${alert.exercise_id}-${alert.classification}`;
      if (!seen.has(key)) {
        seen.add(key);
        deduplicated.push({
          id: alert.id,
          studentId: alert.student_id,
          studentName: alert.student_name,
          studentEmail: alert.student_email,
          exerciseId: alert.exercise_id,
          exerciseTitle: alert.exercise_title,
          sectionId: alert.section_id,
          classification: alert.classification,
          severity: alert.severity || 'low',
          cdsScore: alert.cds_score ? parseFloat(alert.cds_score) : null,
          conceptName: alert.concept_name,
          evidence: alert.evidence || null,
          consecutiveFailures: alert.consecutive_failures || 0,
          createdAt: alert.created_at,
          isReviewed: alert.is_reviewed === true || alert.is_reviewed === 'flagged' ? false : true,
        });
      }
    }

    // Sort by severity
    const severityOrder = { critical: 0, high: 1, moderate: 2, low: 3 };
    deduplicated.sort((a, b) =>
      (severityOrder[a.severity] ?? 4) - (severityOrder[b.severity] ?? 4)
    );

    return {
      sectionId: parseInt(sectionId),
      totalAlerts: deduplicated.length,
      bySeverity: {
        critical: deduplicated.filter(a => a.severity === 'critical').length,
        high: deduplicated.filter(a => a.severity === 'high').length,
        moderate: deduplicated.filter(a => a.severity === 'moderate').length,
        low: deduplicated.filter(a => a.severity === 'low').length,
      },
      alerts: deduplicated,
    };
  } catch (err) {
    console.error('[Analytics] Failed to get dashboard alerts:', err.message);
    return {
      sectionId: parseInt(sectionId),
      totalAlerts: 0,
      bySeverity: { critical: 0, high: 0, moderate: 0, low: 0 },
      alerts: [],
      error: err.message,
    };
  }
}

/**
 * Mark an alert as reviewed.
 */
async function reviewAlert(alertId, classification) {
  try {
    if (classification === 'RETRY_STORM' || classification === 'LEARNING_PLATEAU') {
      // These come from integrity_flags
      await db.query(
        `UPDATE integrity_flags SET status = 'reviewed' WHERE id = $1`,
        [alertId]
      );
    } else {
      // These come from alerts table
      await db.query(
        `UPDATE alerts SET is_reviewed = true WHERE id = $1`,
        [alertId]
      );
    }
    return { success: true };
  } catch (err) {
    console.warn('[Analytics] Failed to review alert:', err.message);
    return { success: false, error: err.message };
  }
}

module.exports = {
  trackSubmission,
  detectRetryStorm,
  detectLearningPlateau,
  getDashboardAlerts,
  reviewAlert,
  // Constants for testing
  RETRY_STORM_THRESHOLD,
  RETRY_STORM_WINDOW_MIN,
  PLATEAU_WINDOW_EXERCISES,
};

/**
 * backend/services/runCheckpoint.js
 *
 * Per-run academic-integrity checkpoint.
 *
 * Called (in the background) for every /run attempt so integrity signals are
 * captured at run time, not only at submit time. Each flag is persisted via
 * integrityFlagEngine.createFlag with run_id set; submission_id stays NULL
 * until the student submits, at which point the submit endpoint finalizes
 * flags by back-filling submission_id (see routes/student.js).
 *
 * Checks run per attempt:
 *   - Passive behavior log (tab-switch / paste thresholds)
 *   - Hardcoding / blank-template (code + starter only)
 *   - Behavioral anomaly detection (instant success / extreme speed)
 */

const db = require('../config/db');
const academicIntegrityEngine = require('./academicIntegrityEngine');
const integrityFlagEngine = require('./integrityFlagEngine');
const behavioralAnomalyDetector = require('./behavioralAnomalyDetector');
const logger = require('../lib/logger');

// Per-run thresholds, aligned with the per-session thresholds used at submit.
const BEHAVIORAL_THRESHOLDS = {
  TAB_SWITCH_HIGH: 5,
  PASTE_HIGH: 3,
};

/**
 * Evaluate integrity signals for a single run attempt and persist any flags.
 *
 * @param {object} params
 * @param {number} params.runId        - run_attempts.id this checkpoint belongs to
 * @param {number} params.studentId
 * @param {number} params.exerciseId
 * @param {number} params.sectionId
 * @param {string} params.code
 * @param {string} [params.starterCode]
 * @param {object} [params.exercise]   - full exercise row (test_cases etc.)
 * @param {number} [params.tabSwitchCount]
 * @param {number} [params.pasteCount]
 * @param {number} [params.timeSpentSeconds]
 * @param {number} [params.attemptNumber]
 * @returns {Promise<Array>} created flags
 */
async function evaluateRunCheckpoint({
  runId,
  studentId,
  exerciseId,
  sectionId,
  code,
  starterCode = '',
  exercise = null,
  tabSwitchCount = 0,
  pasteCount = 0,
  timeSpentSeconds = 0,
  attemptNumber = 1,
}) {
  const created = [];

  const persistFlag = async (flag) => {
    if (!flag || !flag.type) return null;
    try {
      const row = await integrityFlagEngine.createFlag({
        sectionId,
        exerciseId,
        studentId,
        flagType: flag.type,
        severity: flag.severity,
        evidence: flag.evidence || {},
        contextBehaviors: flag.contextBehaviors || flag.context_behaviors || [],
        status: 'flagged',
        submissionId: null,
        runId,
      });
      created.push(row);
      return row;
    } catch (err) {
      logger.warn({ err, flagType: flag.type }, 'Run-checkpoint flag creation failed');
      return null;
    }
  };

  // 1. Passive behavior log (per-run paste / tab-switch thresholds)
  const behavioralSignals = [];
  if (tabSwitchCount >= BEHAVIORAL_THRESHOLDS.TAB_SWITCH_HIGH) {
    behavioralSignals.push(`${tabSwitchCount} tab switches`);
  }
  if (pasteCount >= BEHAVIORAL_THRESHOLDS.PASTE_HIGH) {
    behavioralSignals.push(`${pasteCount} paste events`);
  }
  if (behavioralSignals.length > 0) {
    await persistFlag({
      type: 'PASSIVE_BEHAVIOR_LOG',
      severity: behavioralSignals.length >= 2 ? 'high' : 'medium',
      evidence: {
        tab_switch_count: tabSwitchCount,
        paste_count: pasteCount,
        time_spent_seconds: timeSpentSeconds,
        message: behavioralSignals.join('; '),
      },
      contextBehaviors: ['PASSIVE_BEHAVIOR_LOG'],
    });
  }

  // 2. Hardcoding / blank-template (code + starter based)
  try {
    const academicFlags = await academicIntegrityEngine.evaluateIntegrity({
      code,
      starterCode: starterCode || '',
      studentId,
      exerciseId,
      submission: null,
      exercise,
    });
    for (const flag of academicFlags) {
      await persistFlag(flag);
    }
  } catch (err) {
    logger.warn({ err }, 'Run-checkpoint academic integrity check failed');
  }

  // 3. Behavioral anomaly detection (instant success / extreme speed).
  //    Runs are not yet graded, so is_correct is false — these detectors
  //    only fire on correct submissions and are re-run with the submission
  //    context at submit time (self-heal covers any gaps).
  try {
    const anomalyFlags = await behavioralAnomalyDetector.detectBehavioralAnomalies({
      studentId,
      exerciseId,
      submissionId: null,
      is_correct: false,
      time_spent_seconds: timeSpentSeconds || 0,
      attempt_number: attemptNumber,
      sectionId,
    });
    for (const flag of anomalyFlags) {
      await persistFlag(flag);
    }
  } catch (err) {
    logger.warn({ err }, 'Run-checkpoint behavioral anomaly detection failed');
  }

  return created;
}

module.exports = { evaluateRunCheckpoint, BEHAVIORAL_THRESHOLDS };

/**
 * Shared submission pipeline — common integrity check and flagging logic
 * used by both the sync submission controller and the async worker.
 *
 * Ensures BOTH paths produce identical integrity outcomes.
 */

const integrityFlagEngine = require('../services/integrityFlagEngine');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const behavioralAnomalyDetector = require('../services/behavioralAnomalyDetector');
const { FLAG_TYPES, SEVERITY } = require('./integrityFlags');

/**
 * Unified graduated flagging — used by EVERY integrity check in the system.
 * - First occurrence of a pattern → warning event only (educational)
 * - Second occurrence → low-severity flag
 * - Third+ occurrence → full severity flag
 */
async function graduatedFlag(params) {
  const {
    sectionId, exerciseId, studentId, flagType, severity,
    evidence, contextBehaviors, submissionId
  } = params;

  const priorWarnings = await integrityFlagEngine.getWarningCount(studentId, exerciseId, flagType);

  if (priorWarnings === 0) {
    await integrityFlagEngine.createWarningEvent(studentId, exerciseId, flagType, {
      summary: evidence?.summary,
      attempt_number: evidence?.attempt_number,
    });
    return { action: 'warning', flagType };
  }

  const effectiveSeverity = priorWarnings === 1 ? SEVERITY.LOW : (severity || SEVERITY.LOW);
  await integrityFlagEngine.createFlag({
    sectionId, exerciseId, studentId,
    flagType,
    severity: effectiveSeverity,
    evidence: evidence || {},
    contextBehaviors: contextBehaviors || [],
    status: 'flagged',
    submissionId,
  });
  return { action: 'flag_created', flagType, severity: effectiveSeverity };
}

/**
 * Run academic integrity checks (paper flags 1 & 2: hardcoding, blank template).
 * All paths use graduated flagging.
 */
async function runAcademicIntegrityChecks({ code, starterCode, studentId, exerciseId, exercise, submission, submissionId }) {
  const results = [];
  const flags = await academicIntegrityEngine.evaluateIntegrity({
    code, starterCode, studentId, exerciseId, submission, exercise,
  });

  for (const flag of flags) {
    const severity = (flag.severity || 'low').toUpperCase();
    if (severity === 'HIGH') {
      await integrityFlagEngine.createFlag({
        sectionId: exercise.section_id, exerciseId, studentId,
        flagType: flag.type, severity: flag.severity,
        evidence: flag.evidence || {},
        contextBehaviors: flag.context_behaviors || [],
        status: 'flagged',
        submissionId,
      });
      results.push({ action: 'flag_created', flagType: flag.type, severity: flag.severity });
    } else {
      const result = await graduatedFlag({
        sectionId: exercise.section_id, exerciseId, studentId,
        flagType: flag.type, severity: flag.severity,
        evidence: flag.evidence || {}, contextBehaviors: flag.context_behaviors || [],
        submissionId,
      });
      results.push(result);
    }
  }
  return results;
}

/**
 * Run behavioral anomaly detection (paper flag 3: instant success, extreme speed).
 * All paths use graduated flagging.
 */
async function runBehavioralChecks(params) {
  const { studentId, exerciseId, submissionId, is_correct, time_spent_seconds, attempt_number, sectionId } = params;
  const results = [];

  const behavioralFlags = await behavioralAnomalyDetector.detectBehavioralAnomalies({
    studentId, exerciseId, submissionId, is_correct,
    time_spent_seconds, attempt_number, sectionId,
  });

  for (const flag of behavioralFlags) {
    const result = await graduatedFlag({
      sectionId, exerciseId, studentId,
      flagType: flag.type, severity: flag.severity || SEVERITY.LOW,
      evidence: flag.evidence || {}, contextBehaviors: flag.context_behaviors || [],
      submissionId,
    });
    results.push(result);
  }
  return results;
}

/**
 * Run contextual activity logging (tab switches, paste events).
 * Always LOW severity; uses graduated flagging.
 */
async function runPassiveBehaviorCheck(params) {
  const {
    studentId, exerciseId, sectionId, submissionId,
    tabSwitchCount, pasteCount, timeSpentSeconds, attemptNumber
  } = params;

  const TAB_SWITCH_HIGH = 10;
  const PASTE_HIGH = 5;

  const totalTime = timeSpentSeconds || 1;
  const signals = [];

  if (tabSwitchCount >= TAB_SWITCH_HIGH) signals.push(`${tabSwitchCount} tab switches`);
  if (pasteCount >= PASTE_HIGH) signals.push(`${pasteCount} paste events`);

  if (signals.length === 0) return [];

  return graduatedFlag({
    sectionId, exerciseId, studentId,
    flagType: FLAG_TYPES.PASSIVE_BEHAVIOR_LOG,
    severity: SEVERITY.LOW,
    evidence: {
      summary: signals.join('; '),
      tab_switch_count: tabSwitchCount,
      paste_count: pasteCount,
      total_time_seconds: totalTime,
      attempt_number: attemptNumber,
      confidence: 0.15,
      innocent_explanation: 'Contextual telemetry (tab switches, pastes) is logged as a contextual indicator only. Students naturally switch tabs to access references, documentation, or the exercise prompt.',
    },
    contextBehaviors: [
      signals.join('; '),
      `Attempt #${attemptNumber}, time: ${totalTime}s`,
    ],
    submissionId,
  });
}

module.exports = {
  graduatedFlag,
  runAcademicIntegrityChecks,
  runBehavioralChecks,
  runPassiveBehaviorCheck,
};

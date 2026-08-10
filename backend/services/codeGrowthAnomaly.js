/**
 * backend/services/codeGrowthAnomaly.js
 *
 * Pure module — no database access, no config files, no side effects.
 *
 * Evaluates cross-attempt code growth for a single submission against the
 * previous attempt's baseline line count. Returns a severity band plus a
 * machine-readable basis label; the route layer resolves the prior attempt
 * and persists any flag.
 */

const { SEVERITY } = require('../lib/integrityFlags')

const CODE_GROWTH_ANOMALY_CONFIG = Object.freeze({
  PCT_THRESHOLD: 30,    // growthPercent must be STRICTLY greater than this
  MIN_LINES_ADDED: 15,  // absolute floor; below this, never flag
})

// Static "no flag" result for invalid or unusable inputs. Every field is a
// primitive, so sharing one frozen object cannot leak state between calls.
const NO_FLAG_RESULT = Object.freeze({
  flagged: false,
  severity: null,
  linesAdded: null,
  growthPercent: null,
  floorMet: false,
  severityBasis: null,
  baselineSource: 'none',
})

/**
 * Evaluate cross-attempt code growth against the previous attempt baseline.
 *
 * The decision is a pure function of baselineLines and studentLines;
 * attemptNumber is accepted for call-site symmetry (prior-attempt resolution
 * happens at the route) and never affects the outcome, but is validated when
 * provided — it must be a positive integer, otherwise the module returns the
 * no-flag result rather than throwing.
 *
 * Banding uses the ROUNDED growthPercent (matches the evidence display):
 *   linesAdded 15-49 & pct 31-99  → 'low'
 *   linesAdded 15-49 & pct >=100  → 'medium'
 *   linesAdded 50-99 & pct 31-99  → 'medium'
 *   linesAdded 50-99 & pct >=100  → 'high'
 *   linesAdded >=100 & pct >30    → 'high'
 *
 * @param {object} input
 * @param {number} input.baselineLines — line count of the previous attempt
 * @param {number} input.studentLines — line count of the current submission
 * @param {number} [input.attemptNumber] — current attempt number (validated, not used)
 * @returns {object} — { flagged, severity, linesAdded, growthPercent, floorMet,
 *   severityBasis, baselineSource }
 */
function evaluateCodeGrowthAnomaly({ baselineLines, studentLines, attemptNumber } = {}) {
  if (attemptNumber !== undefined && attemptNumber !== null) {
    const parsedAttempt = Number(attemptNumber)
    if (!Number.isInteger(parsedAttempt) || parsedAttempt <= 0) {
      return NO_FLAG_RESULT
    }
  }

  const baseline = Number(baselineLines)
  const student = Number(studentLines)

  const invalid = baselineLines === null || baselineLines === undefined
    || studentLines === null || studentLines === undefined
    || !Number.isFinite(baseline)
    || !Number.isFinite(student)
    || baseline <= 0
  if (invalid) {
    return NO_FLAG_RESULT
  }

  const linesAdded = student - baseline
  const growthPercent = Math.round(((student - baseline) / baseline) * 100)
  const floorMet = linesAdded >= CODE_GROWTH_ANOMALY_CONFIG.MIN_LINES_ADDED

  if (!floorMet) {
    return {
      flagged: false,
      severity: null,
      linesAdded,
      growthPercent,
      floorMet,
      severityBasis: null,
      baselineSource: 'prior_attempt',
    }
  }

  if (growthPercent <= CODE_GROWTH_ANOMALY_CONFIG.PCT_THRESHOLD) {
    return {
      flagged: false,
      severity: null,
      linesAdded,
      growthPercent,
      floorMet,
      severityBasis: null,
      baselineSource: 'prior_attempt',
    }
  }

  // Flagged: pick the severity band from the rounded growthPercent.
  let severity
  let severityBasis
  if (linesAdded >= 100) {
    severity = SEVERITY.HIGH
    severityBasis = 'pct_gt_30_lines_ge_100'
  } else if (linesAdded >= 50) {
    if (growthPercent >= 100) {
      severity = SEVERITY.HIGH
      severityBasis = 'pct_ge_100_lines_50_99'
    } else {
      severity = SEVERITY.MEDIUM
      severityBasis = 'pct_30_99_lines_50_99'
    }
  } else if (growthPercent >= 100) {
    severity = SEVERITY.MEDIUM
    severityBasis = 'pct_ge_100_lines_15_49'
  } else {
    severity = SEVERITY.LOW
    severityBasis = 'pct_30_99_lines_15_49'
  }

  return {
    flagged: true,
    severity,
    linesAdded,
    growthPercent,
    floorMet,
    severityBasis,
    baselineSource: 'prior_attempt',
  }
}

module.exports = {
  evaluateCodeGrowthAnomaly,
  CODE_GROWTH_ANOMALY_CONFIG,
}

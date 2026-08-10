/**
 * backend/services/codeGrowthRateDetector.js
 *
 * Detects bursts of unusually fast code growth within an editor session.
 *
 * Consumes token-count samples captured at active-editor-time intervals plus
 * paste event timestamps, computes per-interval growth rates, and flags runs
 * of intervals whose rate exceeds an adaptive threshold (session median x
 * multiplier, class median x multiplier, or a fixed floor).
 *
 * Pure module — no database access, no config files, no side effects.
 */

const GROWTH_CONFIG = Object.freeze({
  MIN_SAMPLES: 3,           // Timing-valid intervals required before the session-adaptive threshold is used
  INTERVAL_MULT: 3.5,       // Reserved interval multiplier (config surface parity)
  CLASS_MULT: 3.5,          // Multiplier applied to the class median rate
  ABS_FLOOR_TOKENS: 100,    // Minimum absolute token growth for an interval to count as a burst
  SESSION_MEDIAN_MULT: 3.5, // Multiplier applied to the session median rate
  DEFAULT_FLOOR_RATE: 2.5,  // Fixed threshold when no adaptive data is available
})

/**
 * Median of an array of numbers.
 *
 * @param {number[]} numbers
 * @returns {number|null} — median, or null when the array is empty
 */
function median(numbers) {
  if (!Array.isArray(numbers) || numbers.length === 0) return null
  const sorted = [...numbers].sort((a, b) => a - b)
  const mid = Math.floor(sorted.length / 2)
  if (sorted.length % 2) return sorted[mid]
  return (sorted[mid - 1] + sorted[mid]) / 2
}

/**
 * Class median growth rate computed from peer per-run rates.
 * Requires at least 3 peers; returns null otherwise.
 *
 * @param {number[]} peerRates
 * @returns {number|null}
 */
function computeClassMedianRate(peerRates) {
  if (!Array.isArray(peerRates) || peerRates.length < 3) return null
  return median(peerRates)
}

/**
 * Detect bursts of unusually fast code growth from token-count samples.
 *
 * Input shapes:
 *   samples — array of { tokenCount: number, activeElapsedSeconds: number,
 *     autocomplete?: boolean } sorted by activeElapsedSeconds ascending.
 *     The caller guarantees the ordering; the detector re-sorts defensively.
 *     `autocomplete: true` marks a sample whose growth came from IDE
 *     autocomplete; the interval feeding it is excluded from both the
 *     statistics and burst detection.
 *   pasteEvents — array of { activeElapsedSeconds: number } paste timestamps
 *     aligned on the same active-elapsed-seconds axis as the samples.
 *   options — { classMedianRate?: number, config?: object } where config
 *     overrides individual GROWTH_CONFIG defaults.
 *
 * @param {Array<{tokenCount: number, activeElapsedSeconds: number, autocomplete?: boolean}>} samples
 * @param {Array<{activeElapsedSeconds: number}>} pasteEvents
 * @param {{ classMedianRate?: number, config?: object }} [options]
 * @returns {object} — detection result; ruleTriggered is 'RATE_BURST' or 'NONE'
 */
function detectGrowthRateBursts(samples, pasteEvents, options = {}) {
  const config = Object.assign({}, GROWTH_CONFIG, options.config || {})
  const classMedianRate = options.classMedianRate

  if (!Array.isArray(samples) || samples.length < 2) {
    return {
      ruleTriggered: 'NONE',
      bursts: [],
      sessionMedianRate: null,
      classMedianRate: classMedianRate ?? null,
      thresholdUsed: null,
      samplesAnalyzed: Array.isArray(samples) ? samples.length : 0,
      reason: 'insufficient_samples',
    }
  }

  // Defensive sort; the caller is expected to pass samples already ordered by time.
  const ordered = [...samples].sort((a, b) => a.activeElapsedSeconds - b.activeElapsedSeconds)

  // Build intervals between consecutive samples, keeping only the ones with
  // usable timing and a non-autocomplete destination sample.
  const intervals = []
  for (let i = 1; i < ordered.length; i++) {
    const deltaSeconds = ordered[i].activeElapsedSeconds - ordered[i - 1].activeElapsedSeconds
    if (deltaSeconds <= 0) continue
    if (ordered[i].autocomplete === true) continue
    const deltaTokens = Math.max(ordered[i].tokenCount - ordered[i - 1].tokenCount, 0)
    intervals.push({
      i,
      deltaTokens,
      deltaSeconds,
      rate: deltaTokens / deltaSeconds,
      autocomplete: false,
    })
  }

  if (intervals.length === 0) {
    return {
      ruleTriggered: 'NONE',
      bursts: [],
      sessionMedianRate: null,
      classMedianRate: classMedianRate ?? null,
      thresholdUsed: null,
      samplesAnalyzed: samples.length,
      reason: 'no_timing_data',
    }
  }

  const sessionMedianRate = median(intervals.map(iv => iv.rate))

  // Adaptive threshold: session median x multiplier, class median x multiplier,
  // or a fixed floor when neither provides signal.
  let thresholdUsed
  if (intervals.length >= config.MIN_SAMPLES) {
    const sessionTerm = sessionMedianRate * config.SESSION_MEDIAN_MULT
    const classTerm = (classMedianRate ?? 0) * config.CLASS_MULT
    thresholdUsed = Math.max(sessionTerm, classTerm)
    if (sessionTerm === 0 && classTerm === 0) {
      thresholdUsed = config.DEFAULT_FLOOR_RATE
    }
  } else if (typeof classMedianRate === 'number' && classMedianRate > 0) {
    thresholdUsed = classMedianRate * config.CLASS_MULT
  } else {
    thresholdUsed = config.DEFAULT_FLOOR_RATE
  }

  // Burst detection: the rate must strictly exceed the threshold AND clear the
  // absolute token floor. Adjacent burst intervals merge into one burst.
  const bursts = []
  let openBurst = null
  for (const iv of intervals) {
    const isBurst = iv.rate > thresholdUsed && iv.deltaTokens >= config.ABS_FLOOR_TOKENS
    if (!isBurst) {
      openBurst = null
      continue
    }
    if (openBurst) {
      openBurst.rate = Math.max(openBurst.rate, iv.rate)
      openBurst.deltaTokens += iv.deltaTokens
      openBurst.deltaSeconds += iv.deltaSeconds
      openBurst.endSample = ordered[iv.i].activeElapsedSeconds
    } else {
      openBurst = {
        startSample: ordered[iv.i].activeElapsedSeconds,
        endSample: ordered[iv.i].activeElapsedSeconds,
        rate: iv.rate,
        deltaTokens: iv.deltaTokens,
        deltaSeconds: iv.deltaSeconds,
        pasteCorrelated: false,
      }
      bursts.push(openBurst)
    }
  }

  // Paste correlation: any paste event within [startSample - 5, endSample + 5].
  for (const burst of bursts) {
    burst.pasteCorrelated = (pasteEvents || []).some(
      pe => pe.activeElapsedSeconds >= burst.startSample - 5
        && pe.activeElapsedSeconds <= burst.endSample + 5
    )
  }

  if (bursts.length > 0) {
    return {
      ruleTriggered: 'RATE_BURST',
      bursts,
      sessionMedianRate,
      classMedianRate: classMedianRate ?? null,
      thresholdUsed,
      samplesAnalyzed: samples.length,
      reason: 'rate_exceeded_adaptive_threshold',
    }
  }

  return {
    ruleTriggered: 'NONE',
    bursts: [],
    sessionMedianRate,
    classMedianRate: classMedianRate ?? null,
    thresholdUsed,
    samplesAnalyzed: samples.length,
    reason: 'within_expected_range',
  }
}

module.exports = {
  detectGrowthRateBursts,
  GROWTH_CONFIG,
  median,
  computeClassMedianRate,
}

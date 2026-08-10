/**
 * backend/test/codeGrowthRateDetector.test.js
 *
 * Tests for the pure code-growth-rate burst detector.
 */

const {
  detectGrowthRateBursts,
  GROWTH_CONFIG,
  median,
  computeClassMedianRate,
} = require('../services/codeGrowthRateDetector')

// Helper: build a steady typing session with +10 tokens every 4s (2.5 t/s).
function steadySamples(startTokens, count) {
  return Array.from({ length: count }, (_, idx) => ({
    tokenCount: startTokens + idx * 10,
    activeElapsedSeconds: idx * 4,
    autocomplete: false,
  }))
}

describe('detectGrowthRateBursts', () => {
  it('steady typing → no flag (rates 2.5 t/s, threshold 8.75)', () => {
    // 7 samples → 6 intervals, each +10 tokens / 4s = 2.5 t/s.
    // Session median 2.5 → threshold = max(2.5*3.5, 0*3.5) = 8.75.
    const result = detectGrowthRateBursts(steadySamples(50, 7), [])

    expect(result.ruleTriggered).toBe('NONE')
    expect(result.reason).toBe('within_expected_range')
    expect(result.sessionMedianRate).toBe(2.5)
    expect(result.thresholdUsed).toBe(8.75)
    expect(result.bursts).toEqual([])
    expect(result.samplesAnalyzed).toBe(7)
  })

  it('single fast paste burst → flagged and paste-correlated', () => {
    // 6 steady intervals at 2.5 t/s then one interval +300 tokens in 1s
    // (rate 300, deltaTokens 300 >= 100 floor). Median 2.5 → threshold 8.75.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 8, autocomplete: false },
      { tokenCount: 80, activeElapsedSeconds: 12, autocomplete: false },
      { tokenCount: 90, activeElapsedSeconds: 16, autocomplete: false },
      { tokenCount: 100, activeElapsedSeconds: 20, autocomplete: false },
      { tokenCount: 400, activeElapsedSeconds: 21, autocomplete: false },
    ]
    const pasteEvents = [{ activeElapsedSeconds: 20.5 }]

    const result = detectGrowthRateBursts(samples, pasteEvents)

    expect(result.ruleTriggered).toBe('RATE_BURST')
    expect(result.reason).toBe('rate_exceeded_adaptive_threshold')
    expect(result.bursts).toHaveLength(1)
    expect(result.bursts[0]).toMatchObject({
      startSample: 21,
      endSample: 21,
      rate: 300,
      deltaTokens: 300,
      pasteCorrelated: true,
    })
  })

  it('autocomplete expansion → interval excluded, no flag', () => {
    // Same as the paste-burst case but the fast interval's destination sample
    // is autocomplete-flagged → that interval is dropped from the stats and
    // from burst detection entirely.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 8, autocomplete: false },
      { tokenCount: 80, activeElapsedSeconds: 12, autocomplete: false },
      { tokenCount: 90, activeElapsedSeconds: 16, autocomplete: false },
      { tokenCount: 100, activeElapsedSeconds: 20, autocomplete: false },
      { tokenCount: 400, activeElapsedSeconds: 21, autocomplete: true },
    ]

    const result = detectGrowthRateBursts(samples, [])

    expect(result.ruleTriggered).toBe('NONE')
    expect(result.reason).toBe('within_expected_range')
    expect(result.bursts).toEqual([])
  })

  it('small edit, high rate, low absolute growth → no flag (ABS_FLOOR_TOKENS)', () => {
    // 3 steady intervals at 2.5 t/s then one interval +50 tokens in 0.5s
    // (rate 100 > 8.75) but deltaTokens 50 < ABS_FLOOR_TOKENS → not a burst.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 8, autocomplete: false },
      { tokenCount: 80, activeElapsedSeconds: 12, autocomplete: false },
      { tokenCount: 130, activeElapsedSeconds: 12.5, autocomplete: false },
    ]

    const result = detectGrowthRateBursts(samples, [])

    expect(result.ruleTriggered).toBe('NONE')
    expect(result.reason).toBe('within_expected_range')
    expect(result.bursts).toEqual([])
  })

  it('no timing data → reason no_timing_data', () => {
    // All samples share the same activeElapsedSeconds → every deltaSeconds is 0.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 10, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 10, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 10, autocomplete: false },
    ]

    const result = detectGrowthRateBursts(samples, [])

    expect(result.ruleTriggered).toBe('NONE')
    expect(result.reason).toBe('no_timing_data')
    expect(result.sessionMedianRate).toBeNull()
    expect(result.thresholdUsed).toBeNull()
    expect(result.bursts).toEqual([])
  })

  it('rate exactly equal to the threshold → not flagged (strict >)', () => {
    // Config override forces the multipliers to 1 so thresholdUsed = session
    // median. Rates [100, 2.5, 100] → median 100 → threshold 100. The two
    // intervals at rate exactly 100 (deltaTokens 100 >= floor) are NOT bursts
    // because the rate comparison is strict.
    const samples = [
      { tokenCount: 0, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 100, activeElapsedSeconds: 1, autocomplete: false },
      { tokenCount: 200, activeElapsedSeconds: 41, autocomplete: false },
      { tokenCount: 300, activeElapsedSeconds: 42, autocomplete: false },
    ]

    const result = detectGrowthRateBursts(samples, [], {
      config: { SESSION_MEDIAN_MULT: 1, CLASS_MULT: 1 },
    })

    expect(result.thresholdUsed).toBe(100)
    expect(result.ruleTriggered).toBe('NONE')
    expect(result.reason).toBe('within_expected_range')
    expect(result.bursts).toEqual([])
  })

  it('class-median fallback below MIN_SAMPLES: slow → no flag, fast → flag', () => {
    // 2 timing-valid intervals (< MIN_SAMPLES) with classMedianRate 5 →
    // threshold = 5 * CLASS_MULT = 17.5.
    const slow = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 8, autocomplete: false },
    ]
    const slowResult = detectGrowthRateBursts(slow, [], { classMedianRate: 5 })

    expect(slowResult.thresholdUsed).toBe(17.5)
    expect(slowResult.ruleTriggered).toBe('NONE')
    expect(slowResult.bursts).toEqual([])

    // One interval now jumps +120 tokens in 6s (rate 20 > 17.5, delta >= 100).
    const fast = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 180, activeElapsedSeconds: 10, autocomplete: false },
    ]
    const fastResult = detectGrowthRateBursts(fast, [], { classMedianRate: 5 })

    expect(fastResult.thresholdUsed).toBe(17.5)
    expect(fastResult.ruleTriggered).toBe('RATE_BURST')
    expect(fastResult.bursts).toHaveLength(1)
  })

  it('paste correlation false when no paste event is within the window', () => {
    // Burst span [21, 21] → window [21 - 5, 21 + 5] = [16, 26].
    // The paste at 0.5s is outside the window → not correlated.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 8, autocomplete: false },
      { tokenCount: 80, activeElapsedSeconds: 12, autocomplete: false },
      { tokenCount: 90, activeElapsedSeconds: 16, autocomplete: false },
      { tokenCount: 100, activeElapsedSeconds: 20, autocomplete: false },
      { tokenCount: 400, activeElapsedSeconds: 21, autocomplete: false },
    ]
    const pasteEvents = [{ activeElapsedSeconds: 0.5 }]

    const result = detectGrowthRateBursts(samples, pasteEvents)

    expect(result.ruleTriggered).toBe('RATE_BURST')
    expect(result.bursts).toHaveLength(1)
    expect(result.bursts[0].pasteCorrelated).toBe(false)
  })

  it('single interval that is autocomplete-flagged → no_timing_data', () => {
    // Only one interval exists and its destination sample is autocomplete
    // flagged → no timing-valid intervals remain.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 400, activeElapsedSeconds: 10, autocomplete: true },
    ]

    const result = detectGrowthRateBursts(samples, [])

    expect(result.ruleTriggered).toBe('NONE')
    expect(result.reason).toBe('no_timing_data')
    expect(result.bursts).toEqual([])
  })

  it('default floor rate fallback with too few intervals and no class rate', () => {
    // 2 timing-valid intervals (< MIN_SAMPLES), no classMedianRate →
    // threshold = DEFAULT_FLOOR_RATE = 2.5. One interval at rate 5 with
    // deltaTokens 100 >= floor → flagged.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 1, autocomplete: false },
      { tokenCount: 160, activeElapsedSeconds: 21, autocomplete: false },
    ]

    const result = detectGrowthRateBursts(samples, [])

    expect(result.thresholdUsed).toBe(GROWTH_CONFIG.DEFAULT_FLOOR_RATE)
    expect(result.ruleTriggered).toBe('RATE_BURST')
    expect(result.bursts).toHaveLength(1)
    expect(result.bursts[0]).toMatchObject({ rate: 5, deltaTokens: 100 })
  })

  it('two adjacent fast intervals merge into one burst with summed tokens', () => {
    // 3 steady intervals at 2.5 t/s then two fast ones (+320/+350 tokens in 1s).
    // Median of [2.5, 2.5, 2.5, 320, 350] = 2.5 → threshold 8.75. The two fast
    // intervals are adjacent bursts → merge: deltaTokens 670, rate 350.
    const samples = [
      { tokenCount: 50, activeElapsedSeconds: 0, autocomplete: false },
      { tokenCount: 60, activeElapsedSeconds: 4, autocomplete: false },
      { tokenCount: 70, activeElapsedSeconds: 8, autocomplete: false },
      { tokenCount: 80, activeElapsedSeconds: 12, autocomplete: false },
      { tokenCount: 400, activeElapsedSeconds: 13, autocomplete: false },
      { tokenCount: 750, activeElapsedSeconds: 14, autocomplete: false },
    ]

    const result = detectGrowthRateBursts(samples, [])

    expect(result.ruleTriggered).toBe('RATE_BURST')
    expect(result.bursts).toHaveLength(1)
    expect(result.bursts[0]).toMatchObject({
      startSample: 13,
      endSample: 14,
      rate: 350,
      deltaTokens: 670,
      deltaSeconds: 2,
    })
  })
})

describe('median', () => {
  it('returns null for an empty array', () => {
    expect(median([])).toBeNull()
  })

  it('returns the middle value for odd-length arrays', () => {
    expect(median([3, 1, 2])).toBe(2)
  })

  it('averages the two middle values for even-length arrays', () => {
    expect(median([4, 1, 3, 2])).toBe(2.5)
  })
})

describe('computeClassMedianRate', () => {
  it('returns null for fewer than 3 peers', () => {
    expect(computeClassMedianRate([1, 2])).toBeNull()
  })

  it('returns the median for odd-length peer rates', () => {
    expect(computeClassMedianRate([1, 2, 3])).toBe(2)
  })

  it('averages the two middle values for even-length peer rates', () => {
    expect(computeClassMedianRate([1, 2, 3, 4])).toBe(2.5)
  })
})

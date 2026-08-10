/**
 * backend/test/codeGrowthAnomaly.test.js
 *
 * Tests for the pure cross-attempt code-growth anomaly detector.
 */

const { evaluateCodeGrowthAnomaly, CODE_GROWTH_ANOMALY_CONFIG } = require('../services/codeGrowthAnomaly')

describe('evaluateCodeGrowthAnomaly', () => {
  it('15 → 21 lines: 40% growth but only 6 lines added → NOT flagged (bug regression)', () => {
    // The old route flagged on growthPercent > 30 alone; the 15-line absolute
    // floor must suppress this case even though the percentage is high.
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 15, studentLines: 21, attemptNumber: 3 })
    expect(r.flagged).toBe(false)
    expect(r.severity).toBeNull()
    expect(r.linesAdded).toBe(6)
    expect(r.growthPercent).toBe(40)
    expect(r.floorMet).toBe(false)
    expect(r.severityBasis).toBeNull()
    expect(r.baselineSource).toBe('prior_attempt')
  })

  it('10 → 26 lines: 16 added, 160% → medium (pct_ge_100_lines_15_49)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 10, studentLines: 26, attemptNumber: 3 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('medium')
    expect(r.linesAdded).toBe(16)
    expect(r.growthPercent).toBe(160)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_ge_100_lines_15_49')
  })

  it('100 → 220 lines: 120 added, 120% → high (pct_gt_30_lines_ge_100)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 100, studentLines: 220, attemptNumber: 3 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('high')
    expect(r.linesAdded).toBe(120)
    expect(r.growthPercent).toBe(120)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_gt_30_lines_ge_100')
  })

  it('100 → 165 lines: 65 added, 65% → medium (pct_30_99_lines_50_99)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 100, studentLines: 165, attemptNumber: 3 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('medium')
    expect(r.linesAdded).toBe(65)
    expect(r.growthPercent).toBe(65)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_30_99_lines_50_99')
  })

  it('50 → 70 lines: 20 added, 40% → low (pct_30_99_lines_15_49)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 50, studentLines: 70, attemptNumber: 3 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('low')
    expect(r.linesAdded).toBe(20)
    expect(r.growthPercent).toBe(40)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_30_99_lines_15_49')
  })

  it('10 → 25 lines: exactly 15 added → floor met (inclusive), medium', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 10, studentLines: 25, attemptNumber: 2 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('medium')
    expect(r.linesAdded).toBe(15)
    expect(r.growthPercent).toBe(150)
    expect(r.floorMet).toBe(true)
  })

  it('33 → 48 lines: exactly 15 added, 45% → low', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 33, studentLines: 48, attemptNumber: 2 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('low')
    expect(r.linesAdded).toBe(15)
    expect(r.growthPercent).toBe(45)
    expect(r.floorMet).toBe(true)
  })

  it('100 → 130 lines: exactly 30% → NOT flagged (strictly greater than)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 100, studentLines: 130, attemptNumber: 2 })
    expect(r.flagged).toBe(false)
    expect(r.linesAdded).toBe(30)
    expect(r.growthPercent).toBe(30)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBeNull()
  })

  it('50 → 100 lines: 50 added, 100% → high (pct_ge_100_lines_50_99)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 50, studentLines: 100, attemptNumber: 2 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('high')
    expect(r.linesAdded).toBe(50)
    expect(r.growthPercent).toBe(100)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_ge_100_lines_50_99')
  })

  it('100 → 199 lines: 99 added, 99% → medium (pct_30_99_lines_50_99)', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 100, studentLines: 199, attemptNumber: 3 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('medium')
    expect(r.linesAdded).toBe(99)
    expect(r.growthPercent).toBe(99)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_30_99_lines_50_99')
  })

  it('30 → 50 lines: growth percent rounds 66.67 → 67, low', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 30, studentLines: 50, attemptNumber: 3 })
    expect(r.flagged).toBe(true)
    expect(r.severity).toBe('low')
    expect(r.linesAdded).toBe(20)
    expect(r.growthPercent).toBe(67)
    expect(r.floorMet).toBe(true)
    expect(r.severityBasis).toBe('pct_30_99_lines_15_49')
  })

  it('baseline 0 → no division, not flagged, baselineSource none', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 0, studentLines: 21, attemptNumber: 2 })
    expect(r.flagged).toBe(false)
    expect(r.severity).toBeNull()
    expect(r.linesAdded).toBeNull()
    expect(r.growthPercent).toBeNull()
    expect(r.floorMet).toBe(false)
    expect(r.severityBasis).toBeNull()
    expect(r.baselineSource).toBe('none')
  })

  it('negative growth → not flagged, keeps computed values, prior_attempt source', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 50, studentLines: 40, attemptNumber: 3 })
    expect(r.flagged).toBe(false)
    expect(r.severity).toBeNull()
    expect(r.linesAdded).toBe(-10)
    expect(r.growthPercent).toBe(-20)
    expect(r.floorMet).toBe(false)
    expect(r.severityBasis).toBeNull()
    expect(r.baselineSource).toBe('prior_attempt')
  })

  it('undefined baseline → not flagged, baselineSource none', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: undefined, studentLines: 21, attemptNumber: 2 })
    expect(r.flagged).toBe(false)
    expect(r.severity).toBeNull()
    expect(r.linesAdded).toBeNull()
    expect(r.growthPercent).toBeNull()
    expect(r.floorMet).toBe(false)
    expect(r.baselineSource).toBe('none')
  })

  it('null student lines → not flagged, baselineSource none', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 50, studentLines: null, attemptNumber: 2 })
    expect(r.flagged).toBe(false)
    expect(r.severity).toBeNull()
    expect(r.linesAdded).toBeNull()
    expect(r.growthPercent).toBeNull()
    expect(r.floorMet).toBe(false)
    expect(r.baselineSource).toBe('none')
  })

  it('never throws on invalid attemptNumber — returns no-flag result', () => {
    expect(() => evaluateCodeGrowthAnomaly({ baselineLines: 10, studentLines: 26, attemptNumber: -1 })).not.toThrow()
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 10, studentLines: 26, attemptNumber: -1 })
    expect(r.flagged).toBe(false)
    expect(r.baselineSource).toBe('none')
  })
})

describe('result shape', () => {
  it('flagged result carries non-null severity and severityBasis', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 10, studentLines: 26, attemptNumber: 3 })
    expect(r.severity).not.toBeNull()
    expect(r.severityBasis).not.toBeNull()
    expect(r.flagged).toBe(true)
  })

  it('non-flagged result has null severity and severityBasis', () => {
    const r = evaluateCodeGrowthAnomaly({ baselineLines: 15, studentLines: 21, attemptNumber: 3 })
    expect(r.severity).toBeNull()
    expect(r.severityBasis).toBeNull()
    expect(r.flagged).toBe(false)
  })
})

describe('CODE_GROWTH_ANOMALY_CONFIG', () => {
  it('is frozen', () => {
    expect(Object.isFrozen(CODE_GROWTH_ANOMALY_CONFIG)).toBe(true)
  })

  it('exposes the locked thresholds', () => {
    expect(CODE_GROWTH_ANOMALY_CONFIG.PCT_THRESHOLD).toBe(30)
    expect(CODE_GROWTH_ANOMALY_CONFIG.MIN_LINES_ADDED).toBe(15)
  })
})

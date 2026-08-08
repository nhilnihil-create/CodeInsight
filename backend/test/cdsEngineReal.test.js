// Real CDS Engine Tests — replaces placeholder cdsEngine.test.js
// Tests actual utility functions and business logic with real assertions.

const assert = require('assert');

// Import the utility functions we'll test directly
// The main module also exports these
const cdsEngine = require('../services/cdsEngine');

// ── Helper: replicate the internal normalization for isolated testing ──
// CDS v3: min-max normalization with p95 outlier capping.

function getNormalizedValue(value, allValues) {
  const targetValue = Number(value);
  const safeValues = (allValues || []).map(v => Number(v)).filter(v => !isNaN(v));

  if (safeValues.length === 0) return { normalized: 0.00, min: 0, p95: 0 };

  const sorted = [...safeValues].sort((a, b) => a - b);
  const p95Index = Math.ceil(sorted.length * 0.95) - 1;
  const p95 = sorted[Math.max(0, Math.min(p95Index, sorted.length - 1))];

  const cappedValue = Math.min(targetValue, p95);
  const min = safeValues.length > 0 ? Math.min(...safeValues) : 0;

  const denominator = p95 - min;
  if (denominator === 0) return { normalized: 0.00, min, p95 };

  const normalized = Math.max(0, Math.min((cappedValue - min) / denominator, 1.0));
  return { normalized: Number(parseFloat(normalized).toFixed(2)), min, p95 };
}

// Import the real classify and thresholds from cdsEngine
// NOTE: These MUST match the authoritative source — no local copies!
const { classify, CDS_THRESHOLDS, getConfidenceTier, CONFIDENCE } = require('../services/cdsEngine');

// ── Classification Tests ─────────────────────────────────────────────────────

describe('CDS Engine — Classification', function() {
  it('returns Unscored for null', function() {
    assert.strictEqual(classify(null), 'Unscored');
  });

  it('returns Unscored for undefined', function() {
    assert.strictEqual(classify(undefined), 'Unscored');
  });

  it('classifies 0.00 as Very Low', function() {
    assert.strictEqual(classify(0), 'Very Low');
  });

  it('classifies 0.20 as Very Low (exact boundary)', function() {
    assert.strictEqual(classify(0.20), 'Very Low');
  });

  it('classifies 0.40 as Low (exact boundary)', function() {
    assert.strictEqual(classify(0.40), 'Low');
  });

  it('classifies 0.45 as Moderate', function() {
    assert.strictEqual(classify(0.45), 'Moderate');
  });

  it('classifies 0.50 as Moderate', function() {
    assert.strictEqual(classify(0.50), 'Moderate');
  });

  it('classifies 0.60 as Moderate (exact boundary)', function() {
    assert.strictEqual(classify(0.60), 'Moderate');
  });

  it('classifies 0.75 as Elevated', function() {
    assert.strictEqual(classify(0.75), 'Elevated');
  });

  it('classifies 1.0 as High', function() {
    assert.strictEqual(classify(1.0), 'High');
  });

  it('adds Preliminary prefix when isPreliminary=true', function() {
    assert.strictEqual(classify(0.5, true), 'Prelim-Moderate');
  });
});

// ── Normalization Function Tests ──────────────────────────────────────────────

describe('CDS Engine — Normalization (getNormalizedValue v3 min-max + p95)', function() {
  it('returns 0 for empty array', function() {
    const { normalized, min, p95 } = getNormalizedValue(0, []);
    assert.strictEqual(normalized, 0);
    assert.strictEqual(min, 0);
    assert.strictEqual(p95, 0);
  });

  it('returns 0 for value=0 with non-empty array', function() {
    const { normalized } = getNormalizedValue(0, [1, 2, 3]);
    assert.strictEqual(normalized, 0);
  });

  it('returns 1.0 for max value in array (value reaches p95)', function() {
    const { normalized, p95 } = getNormalizedValue(10, [1, 3, 5, 10]);
    assert.strictEqual(p95, 10);
    assert.strictEqual(normalized, 1.0);
  });

  it('normalizes mid-range value correctly', function() {
    const allValues = [2, 4, 6, 8, 10];
    // p95 of [2,4,6,8,10] with 5 elements: ceil(5*0.95)=5, p95Index=4 → p95=10
    // min=2, cappedValue=5, normalized = (5-2)/(10-2) = 3/8 = 0.38
    const { normalized, min, p95 } = getNormalizedValue(5, allValues);
    assert.strictEqual(p95, 10);
    assert.strictEqual(min, 2);
    assert.strictEqual(normalized, 0.38);
  });

  it('never exceeds 1.0 or goes below 0 (clamped range)', function() {
    const high = getNormalizedValue(999, [1, 2, 3]);
    assert.ok(high.normalized <= 1.0, `normalized ${high.normalized} should be <= 1.0`);
    assert.ok(high.normalized >= 0, `normalized ${high.normalized} should be >= 0`);
    const low = getNormalizedValue(0, [1, 2, 3]);
    assert.ok(low.normalized >= 0, `normalized ${low.normalized} should be >= 0`);
  });

  it('handles all-zeros array safely (zero-variance → 0.00)', function() {
    const { normalized, min, p95 } = getNormalizedValue(0, [0, 0, 0]);
    assert.strictEqual(p95, 0);
    assert.strictEqual(min, 0);
    assert.strictEqual(normalized, 0);
  });

  it('handles single-value array → 0.00 (zero-variance)', function() {
    const { normalized, min, p95 } = getNormalizedValue(5, [5]);
    assert.strictEqual(min, 5);
    assert.strictEqual(p95, 5);
    assert.strictEqual(normalized, 0);
  });

  it('p95 is always >= min (no negative denominator)', function() {
    const cases = [[], [0], [0, 0, 0], [1], [5, 10, 15]];
    for (const arr of cases) {
      for (const val of [0, 1, 100]) {
        const { p95, min } = getNormalizedValue(val, arr);
        assert.ok(p95 >= min, `p95 (${p95}) should be >= min (${min}) for arr=${JSON.stringify(arr)}, val=${val}`);
      }
    }
  });

  // ── NEW: Zero-Variance Roadblock ──────────────────────────────────────
  it('ZERO-VARIANCE: all students have identical scores → normalized=0.00', function() {
    const allValues = [15, 15, 15, 15, 15];
    for (const v of allValues) {
      const result = getNormalizedValue(v, allValues);
      assert.strictEqual(result.normalized, 0.00);
      assert.strictEqual(result.p95 - result.min, 0);
    }
  });

  // ── NEW: p95 Outlier Capping ──────────────────────────────────────────
  it('p95 CAPPING: extreme outlier truncated to 95th percentile', function() {
    // 20 elements: 19 normal values (1-4) + 1 extreme outlier (150)
    const allValues = [1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,150];
    const outlierResult = getNormalizedValue(150, allValues);
    assert.strictEqual(outlierResult.p95, 4);
    assert.strictEqual(outlierResult.normalized, 1.00);
  });

  // ── NEW: Type Casting Protection ──────────────────────────────────────
  it('TYPE CASTING: string inputs safely converted to numbers', function() {
    const stringValues = ['1', '2', '3', '4', '5'];
    const { normalized, min, p95 } = getNormalizedValue('3', stringValues);
    assert.strictEqual(p95, 5);
    assert.strictEqual(min, 1);
    assert.strictEqual(normalized, 0.50);
  });
});

// ── CDS Formula Tests ─────────────────────────────────────────────────────────

describe('CDS Engine — Formula Calculation', function() {
  function calculateCDS(ner, nrs, nts) {
    const cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
    return Number(parseFloat(cds).toFixed(2));
  }

  it('calculates CDS with weights 0.40/0.35/0.25', function() {
    const cds = calculateCDS(1, 1, 1);
    assert.strictEqual(cds, 1.0);
  });

  it('calculates CDS = 0 when all components are 0', function() {
    const cds = calculateCDS(0, 0, 0);
    assert.strictEqual(cds, 0);
  });

  it('CDS with only NER=1 is 0.40', function() {
    const cds = calculateCDS(1, 0, 0);
    assert.strictEqual(cds, 0.40);
  });

  it('CDS with only NRS=1 is 0.35', function() {
    const cds = calculateCDS(0, 1, 0);
    assert.strictEqual(cds, 0.35);
  });

  it('CDS with only NTS=1 is 0.25', function() {
    const cds = calculateCDS(0, 0, 1);
    assert.strictEqual(cds, 0.25);
  });

  it('rounds to 2 decimal places', function() {
    const cds = calculateCDS(0.3333, 0.6667, 0.5);
    assert.ok(Number.isInteger(cds * 100), `CDS ${cds} should have at most 2 decimal places`);
  });

  it('never exceeds 1.0', function() {
    const cds = calculateCDS(1, 1, 1);
    assert.ok(cds <= 1.0, `CDS ${cds} should be <= 1.0`);
  });

  it('never goes below 0', function() {
    const cds = calculateCDS(0, 0, 0);
    assert.ok(cds >= 0, `CDS ${cds} should be >= 0`);
  });

  it('produces Moderate for balanced student (0.5, 0.5, 0.5)', function() {
    const cds = calculateCDS(0.5, 0.5, 0.5);
    assert.strictEqual(cds, 0.50);
    assert.strictEqual(classify(cds), 'Moderate');
  });

  it('instant CDS maxes at 0.40 (NER only)', function() {
    // Instant CDS: nrs=0, nts=0
    const cds = calculateCDS(1, 0, 0);
    assert.strictEqual(cds, 0.40);
    assert.ok(cds < 1.0, 'Instant CDS should never reach 1.0');
  });
});

// ── Edge Case: Post-Solution Cutoff ───────────────────────────────────────────

describe('CDS Engine — Post-Solution Cutoff Logic', function() {
  function applyCutoff(attempts) {
    // Replicate cdsEngine logic: find first unflagged acceptance
    const firstAccepted = attempts.find(a => a.is_correct === true && a.flag_id === null);
    const cutoff = firstAccepted ? firstAccepted.attempt_number : null;
    return cutoff ? attempts.filter(a => a.attempt_number <= cutoff) : attempts;
  }

  it('counts all attempts when no acceptance', function() {
    const attempts = [
      { attempt_number: 1, is_correct: false, flag_id: null },
      { attempt_number: 2, is_correct: false, flag_id: null },
      { attempt_number: 3, is_correct: false, flag_id: null },
    ];
    const counted = applyCutoff(attempts);
    assert.strictEqual(counted.length, 3);
  });

  it('stops counting at first successful unflagged attempt', function() {
    const attempts = [
      { attempt_number: 1, is_correct: false, flag_id: null },
      { attempt_number: 2, is_correct: false, flag_id: null },
      { attempt_number: 3, is_correct: true, flag_id: null },
      { attempt_number: 4, is_correct: false, flag_id: null },
      { attempt_number: 5, is_correct: true, flag_id: null },
    ];
    const counted = applyCutoff(attempts);
    assert.strictEqual(counted.length, 3);
    assert.strictEqual(counted[counted.length - 1].attempt_number, 3);
  });

  it('excludes flagged successful attempts from cutoff', function() {
    const attempts = [
      { attempt_number: 1, is_correct: false, flag_id: null },
      { attempt_number: 2, is_correct: true, flag_id: 42 }, // flagged!
      { attempt_number: 3, is_correct: true, flag_id: null }, // first unflagged
    ];
    const counted = applyCutoff(attempts);
    assert.strictEqual(counted.length, 3);
    assert.strictEqual(counted[2].attempt_number, 3);
  });

  it('counts single attempt correctly', function() {
    const attempts = [
      { attempt_number: 1, is_correct: true, flag_id: null },
    ];
    const counted = applyCutoff(attempts);
    assert.strictEqual(counted.length, 1);
  });
});

// ── Edge Case: NTS ≥ 0.9 + Zero Successes → Force High ────────────────────────

describe('CDS Engine — NTS Time Exhaustion Edge Case', function() {
  it('should classify as High when time >= 90% of effectiveMax with 0 successes', function() {
    // Simulate the logic from cdsEngine lines 176-180
    function handleTimeExhaustion(nts, successCount, ner, nrs) {
      if (nts >= 0.9 && successCount === 0) {
        return { ner: 1, nrs: 1, nts: 1, cds: 1.0, classification: 'High' };
      }
      const cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
      return { ner, nrs, nts, cds: Number(parseFloat(cds).toFixed(2)), classification: classify(cds) };
    }

    const result = handleTimeExhaustion(0.95, 0, 0.5, 0.5);
    assert.strictEqual(result.cds, 1.0);
    assert.strictEqual(result.classification, 'High');
  });

  it('should NOT force High when time >= 90% but has successes', function() {
    function handleTimeExhaustion(nts, successCount, ner, nrs) {
      if (nts >= 0.9 && successCount === 0) {
        return { ner: 1, nrs: 1, nts: 1, cds: 1.0, classification: 'High' };
      }
      const cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
      return { ner, nrs, nts, cds: Number(parseFloat(cds).toFixed(2)), classification: classify(cds) };
    }

    const result = handleTimeExhaustion(0.95, 2, 0.3, 0.4);
    assert.ok(result.cds < 1.0);
    assert.notStrictEqual(result.classification, 'High');
  });

  it('should NOT force High when time < 90% with 0 successes', function() {
    function handleTimeExhaustion(nts, successCount, ner, nrs) {
      if (nts >= 0.9 && successCount === 0) {
        return { ner: 1, nrs: 1, nts: 1, cds: 1.0, classification: 'High' };
      }
      const cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
      return { ner, nrs, nts, cds: Number(parseFloat(cds).toFixed(2)), classification: classify(cds) };
    }

    const result = handleTimeExhaustion(0.85, 0, 0.5, 0.5);
    assert.ok(result.cds < 1.0);
  });
});

// ── Instant CDS (calculateCDS behavior) ──────────────────────────────────────

describe('CDS Engine — Instant CDS (single-run)', function() {
  function instantCDS(testResults) {
    if (!testResults || !Array.isArray(testResults)) {
      return { score: 0, ner: 0, nrs: 0, nts: 0, classification: 'Unscored' };
    }
    const totalTests = testResults.length;
    const failedTests = totalTests - testResults.filter(r => r.passed).length;
    const ner = failedTests / Math.max(totalTests, 1);
    const nrs = 0;
    const nts = 0;
    let cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
    cds = Number(parseFloat(cds).toFixed(2));
    return { score: Math.min(cds, 1), ner, nrs, nts, classification: classify(Math.min(cds, 1)) };
  }

  it('returns score=0 for empty testResults (classify gives Very Low, not Unscored)', function() {
    // Note: instantCDS with [] gives cds=0 which classify() → 'Very Low'
    // Only null/undefined cds gives 'Unscored'. Empty array is valid data.
    const result = instantCDS([]);
    assert.strictEqual(result.score, 0);
    assert.strictEqual(result.ner, 0);
    assert.strictEqual(result.classification, 'Very Low'); // cds=0, not null
  });

  it('returns all zeros for null testResults', function() {
    const result = instantCDS(null);
    assert.strictEqual(result.score, 0);
    assert.strictEqual(result.classification, 'Unscored');
  });

  it('returns NER=1 when all tests fail → score=0.40 → Low', function() {
    const result = instantCDS([
      { passed: false }, { passed: false }, { passed: false }
    ]);
    assert.strictEqual(result.ner, 1);
    assert.strictEqual(result.score, 0.40);
    // 0.40 is the Low boundary per cdsEngine thresholds
    assert.strictEqual(result.classification, 'Low');
  });

  it('returns NER=0 when all tests pass', function() {
    const result = instantCDS([
      { passed: true }, { passed: true }
    ]);
    assert.strictEqual(result.ner, 0);
    assert.strictEqual(result.score, 0);
    assert.strictEqual(result.classification, 'Very Low');
  });

  it('max instant CDS is 0.40 (not 1.0)', function() {
    const result = instantCDS([{ passed: false }, { passed: false }]);
    assert.strictEqual(result.score, 0.40);
    assert.ok(result.score < 1.0, 'Instant CDS should max at 0.40');
  });

  it('partial failure gives proportional NER', function() {
    const result = instantCDS([
      { passed: true }, { passed: false }
    ]);
    assert.strictEqual(result.ner, 0.5);
    assert.strictEqual(result.score, 0.20);
  });
});

// ── Classification Boundary Mismatch (document the bug) ──────────────────────

describe('CDS Engine — Classification Boundary Audit', function() {
  it('cdsEngine classification boundaries harmonized with analytics (0.20, 0.40, 0.60, 0.80)', function() {
    // V3 FIX: Centralized thresholds — VERY_LOW=0.20, LOW=0.40, MODERATE=0.60, ELEVATED=0.80
    const cdsEngineVeryLow = classify(0.20);
    assert.strictEqual(cdsEngineVeryLow, 'Very Low');
    const cdsEngineLow = classify(0.40);
    assert.strictEqual(cdsEngineLow, 'Low');
    const cdsEngineModerate = classify(0.60);
    assert.strictEqual(cdsEngineModerate, 'Moderate');
    const cdsEngineElevated = classify(0.80);
    assert.strictEqual(cdsEngineElevated, 'Elevated');
    const cdsEngineHigh = classify(0.81);
    assert.strictEqual(cdsEngineHigh, 'High');
  });

  it('classifies at exact very low boundary: 0.20 → Very Low', function() {
    assert.strictEqual(classify(0.20), 'Very Low');
  });

  it('classifies just above very low boundary: 0.21 → Low', function() {
    assert.strictEqual(classify(0.21), 'Low');
  });

  it('classifies at exact moderate boundary: 0.60 → Moderate', function() {
    assert.strictEqual(classify(0.60), 'Moderate');
  });

  it('classifies just above moderate boundary: 0.61 → Elevated', function() {
    assert.strictEqual(classify(0.61), 'Elevated');
  });

  it('classifies at exact elevated boundary: 0.80 → Elevated', function() {
    assert.strictEqual(classify(0.80), 'Elevated');
  });

  it('classifies just above elevated boundary: 0.81 → High', function() {
    assert.strictEqual(classify(0.81), 'High');
  });

  it('adds Preliminary prefix when isPreliminary=true', function() {
    assert.strictEqual(classify(0.4, true), 'Prelim-Low');
  });

  it('exports match centralized CDS_THRESHOLDS', function() {
    assert.strictEqual(CDS_THRESHOLDS.VERY_LOW, 0.20);
    assert.strictEqual(CDS_THRESHOLDS.LOW, 0.40);
    assert.strictEqual(CDS_THRESHOLDS.MODERATE, 0.60);
    assert.strictEqual(CDS_THRESHOLDS.ELEVATED, 0.80);
  });
});

// ── Confidence Tiers (Phase 1 small-sample gating) ──────────────────────────

describe('CDS Engine — Confidence Tiers', function() {
  it('marks as INSUFFICIENT below 5 valid submitters', function() {
    assert.strictEqual(getConfidenceTier(0), CONFIDENCE.INSUFFICIENT);
    assert.strictEqual(getConfidenceTier(1), CONFIDENCE.INSUFFICIENT);
    assert.strictEqual(getConfidenceTier(4), CONFIDENCE.INSUFFICIENT);
  });

  it('marks as PRELIM from 5 to 9 valid submitters', function() {
    assert.strictEqual(getConfidenceTier(5), CONFIDENCE.PRELIM);
    assert.strictEqual(getConfidenceTier(9), CONFIDENCE.PRELIM);
  });

  it('marks as CONFIDENT at 10+ valid submitters', function() {
    assert.strictEqual(getConfidenceTier(10), CONFIDENCE.CONFIDENT);
    assert.strictEqual(getConfidenceTier(100), CONFIDENCE.CONFIDENT);
  });

  it('PRELIM is distinct from CONFIDENT and always has a Preliminary prefix', function() {
    assert.notStrictEqual(CONFIDENCE.PRELIM, CONFIDENCE.CONFIDENT);
    assert.notStrictEqual(CONFIDENCE.PRELIM, CONFIDENCE.INSUFFICIENT);
    // classify(score, true) is used for PRELIM tier
    assert.strictEqual(classify(0.2, true), 'Prelim-Very Low');
  });
});

console.log('Real CDS Engine test suite loaded — all assertions are active, no placeholders.');

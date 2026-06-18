/**
 * analyticsMapper — Full Test Suite
 *
 * Tests getCDSTier and getMasteryTier from backend/utils/analyticsMapper.js.
 * Covers: boundary values, null/undefined/NaN safety, type coercion,
 * 2-decimal rounding, and frozen tier object integrity.
 */

const {
  getCDSTier,
  getMasteryTier,
  CDS_TIERS,
  MASTERY_TIERS,
  NO_DATA_TIER,
} = require('../utils/analyticsMapper');

// ── Shared null-safety baseline ────────────────────────────────────────

const NO_DATA_BASELINE = { tier: 0, label: 'No Data', color: 'slate', tailwind: 'bg-slate-950/20 text-slate-600 border-transparent' };

describe('analyticsMapper — Null Safety', function () {
  it('getCDSTier(null) returns No Data baseline', function () {
    expect(getCDSTier(null)).toEqual(NO_DATA_BASELINE);
  });

  it('getCDSTier(undefined) returns No Data baseline', function () {
    expect(getCDSTier(undefined)).toEqual(NO_DATA_BASELINE);
  });

  it('getCDSTier(NaN) returns No Data baseline', function () {
    expect(getCDSTier(NaN)).toEqual(NO_DATA_BASELINE);
  });

  it('getCDSTier("abc") returns No Data baseline', function () {
    expect(getCDSTier('abc')).toEqual(NO_DATA_BASELINE);
  });

  it('getCDSTier(Infinity) returns No Data baseline', function () {
    expect(getCDSTier(Infinity)).toEqual(NO_DATA_BASELINE);
  });

  it('getMasteryTier(null) returns No Data baseline', function () {
    expect(getMasteryTier(null)).toEqual(NO_DATA_BASELINE);
  });

  it('getMasteryTier(undefined) returns No Data baseline', function () {
    expect(getMasteryTier(undefined)).toEqual(NO_DATA_BASELINE);
  });

  it('getMasteryTier(NaN) returns No Data baseline', function () {
    expect(getMasteryTier(NaN)).toEqual(NO_DATA_BASELINE);
  });

  it('getMasteryTier("hello") returns No Data baseline', function () {
    expect(getMasteryTier('hello')).toEqual(NO_DATA_BASELINE);
  });
});

// ── CDS Tier — exact boundary tests ────────────────────────────────────

describe('analyticsMapper — getCDSTier boundaries', function () {
  it('classifies 0.00 as Tier 1 (Minimal Struggle)', function () {
    const r = getCDSTier(0.00);
    expect(r.tier).toBe(1);
    expect(r.label).toBe('Minimal Struggle / Trivial Mastery');
    expect(r.color).toBe('slate');
  });

  it('classifies 0.15 as Tier 1 (upper bound)', function () {
    expect(getCDSTier(0.15).tier).toBe(1);
  });

  it('classifies 0.16 as Tier 2 (Expected Resistance)', function () {
    const r = getCDSTier(0.16);
    expect(r.tier).toBe(2);
    expect(r.label).toBe('Expected Resistance');
    expect(r.color).toBe('emerald');
  });

  it('classifies 0.35 as Tier 2 (upper bound)', function () {
    expect(getCDSTier(0.35).tier).toBe(2);
  });

  it('classifies 0.36 as Tier 3 (Moderate Friction)', function () {
    const r = getCDSTier(0.36);
    expect(r.tier).toBe(3);
    expect(r.label).toBe('Moderate Friction');
    expect(r.color).toBe('amber');
  });

  it('classifies 0.55 as Tier 3 (upper bound)', function () {
    expect(getCDSTier(0.55).tier).toBe(3);
  });

  it('classifies 0.56 as Tier 4 (High Struggle Loop)', function () {
    const r = getCDSTier(0.56);
    expect(r.tier).toBe(4);
    expect(r.label).toBe('High Struggle Loop');
    expect(r.color).toBe('orange');
  });

  it('classifies 0.75 as Tier 4 (upper bound)', function () {
    expect(getCDSTier(0.75).tier).toBe(4);
  });

  it('classifies 0.76 as Tier 5 (Critical Blocker)', function () {
    const r = getCDSTier(0.76);
    expect(r.tier).toBe(5);
    expect(r.label).toBe('Critical Blocker');
    expect(r.color).toBe('rose');
  });

  it('classifies 1.00 as Tier 5 (upper bound)', function () {
    expect(getCDSTier(1.00).tier).toBe(5);
  });
});

// ── Mastery Tier — exact boundary tests ─────────────────────────────────

describe('analyticsMapper — getMasteryTier boundaries', function () {
  it('classifies 100 as Tier 1 (Excellent Mastery)', function () {
    const r = getMasteryTier(100);
    expect(r.tier).toBe(1);
    expect(r.label).toBe('Excellent Mastery');
    expect(r.color).toBe('slate');
  });

  it('classifies 85 as Tier 1 (lower bound)', function () {
    expect(getMasteryTier(85).tier).toBe(1);
  });

  it('classifies 84 as Tier 2 (Nominal Progress)', function () {
    const r = getMasteryTier(84);
    expect(r.tier).toBe(2);
    expect(r.label).toBe('Nominal Progress');
    expect(r.color).toBe('emerald');
  });

  it('classifies 65 as Tier 2 (lower bound)', function () {
    expect(getMasteryTier(65).tier).toBe(2);
  });

  it('classifies 64 as Tier 3 (Moderate Challenge)', function () {
    const r = getMasteryTier(64);
    expect(r.tier).toBe(3);
    expect(r.label).toBe('Moderate Challenge');
    expect(r.color).toBe('amber');
  });

  it('classifies 45 as Tier 3 (lower bound)', function () {
    expect(getMasteryTier(45).tier).toBe(3);
  });

  it('classifies 44 as Tier 4 (Significant Struggle)', function () {
    const r = getMasteryTier(44);
    expect(r.tier).toBe(4);
    expect(r.label).toBe('Significant Struggle');
    expect(r.color).toBe('orange');
  });

  it('classifies 25 as Tier 4 (lower bound)', function () {
    expect(getMasteryTier(25).tier).toBe(4);
  });

  it('classifies 24 as Tier 5 (Critical Support Required)', function () {
    const r = getMasteryTier(24);
    expect(r.tier).toBe(5);
    expect(r.label).toBe('Critical Support Required');
    expect(r.color).toBe('rose');
  });

  it('classifies 0 as Tier 5 (lower bound)', function () {
    expect(getMasteryTier(0).tier).toBe(5);
  });
});

// ── Type coercion ──────────────────────────────────────────────────────

describe('analyticsMapper — Type Coercion', function () {
  it('coerces string "0.50" to CDS Tier 3', function () {
    expect(getCDSTier('0.50').tier).toBe(3);
  });

  it('coerces string "75" to Mastery Tier 2', function () {
    expect(getMasteryTier('75').tier).toBe(2);
  });

  it('coerces boolean false to CDS Tier 1 (coerces to 0)', function () {
    expect(getCDSTier(false).tier).toBe(1);
  });

  it('coerces boolean true to CDS Tier 5 (coerces to 1)', function () {
    expect(getCDSTier(true).tier).toBe(5);
  });
});

// ── 2-Decimal rounding fairness ────────────────────────────────────────

describe('analyticsMapper — Rounding', function () {
  it('rounds 0.155 to 0.16 → Tier 2', function () {
    expect(getCDSTier(0.155).tier).toBe(2);
  });

  it('rounds 0.154 to 0.15 → Tier 1', function () {
    expect(getCDSTier(0.154).tier).toBe(1);
  });

  it('rounds mastery 84.995 to 85.00 → Tier 1', function () {
    expect(getMasteryTier(84.995).tier).toBe(1);
  });

  it('rounds mastery 84.49 to 84.49 → Tier 2', function () {
    expect(getMasteryTier(84.49).tier).toBe(2);
  });
});

// ── Frozen tier constants ──────────────────────────────────────────────

describe('analyticsMapper — Constants Integrity', function () {
  it('CDS_TIERS is frozen', function () {
    expect(Object.isFrozen(CDS_TIERS)).toBe(true);
  });

  it('MASTERY_TIERS is frozen', function () {
    expect(Object.isFrozen(MASTERY_TIERS)).toBe(true);
  });

  it('NO_DATA_TIER is frozen', function () {
    expect(Object.isFrozen(NO_DATA_TIER)).toBe(true);
  });

  it('each CDS tier object is frozen', function () {
    CDS_TIERS.forEach((t) => expect(Object.isFrozen(t)).toBe(true));
  });

  it('each Mastery tier object is frozen', function () {
    MASTERY_TIERS.forEach((t) => expect(Object.isFrozen(t)).toBe(true));
  });
});

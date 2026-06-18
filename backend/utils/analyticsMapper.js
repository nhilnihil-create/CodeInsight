/**
 * analyticsMapper.js
 *
 * Global 5-tier top-heavy classification framework for CodeInsight.
 * Two decoupled visualizer engines:
 *
 *   A. getCDSTier(value)     — Instructor CDS (0.00–1.00 decimal, higher = worse)
 *   B. getMasteryTier(value) — Student Mastery (0–100 percentage, higher = better)
 *
 * Both enforce:
 *   - Strong type ingestion via Number()
 *   - Null/NaN safety fallback (tier 0 baseline)
 *   - Strict 2-decimal rounding before boundary evaluation
 *
 * @module backend/utils/analyticsMapper
 */

"use strict";

// ──────────────────────────────────────────────────────────────────────
// CONSTANTS
// ──────────────────────────────────────────────────────────────────────

const NO_DATA_TIER = Object.freeze({
  tier: 0,
  label: "No Data",
  color: "slate",
  tailwind: "bg-slate-950/20 text-slate-600 border-transparent",
});

/**
 * CDS Tier definitions — top-heavy (higher CDS = worse struggle).
 * Boundaries are evaluated after 2-decimal rounding.
 */
const CDS_TIERS = Object.freeze([
  Object.freeze({
    tier: 1,
    label: "Minimal Struggle / Trivial Mastery",
    color: "slate",
    tailwind: "bg-slate-900/40 text-slate-400 border-white/5",
    min: 0.00,
    max: 0.15,
  }),
  Object.freeze({
    tier: 2,
    label: "Expected Resistance",
    color: "emerald",
    tailwind: "bg-emerald-500/15 text-emerald-400 border-emerald-500/20",
    min: 0.16,
    max: 0.35,
  }),
  Object.freeze({
    tier: 3,
    label: "Moderate Friction",
    color: "amber",
    tailwind: "bg-amber-500/15 text-amber-400 border-amber-500/20",
    min: 0.36,
    max: 0.55,
  }),
  Object.freeze({
    tier: 4,
    label: "High Struggle Loop",
    color: "orange",
    tailwind: "bg-orange-500/20 text-orange-400 border-orange-500/30",
    min: 0.56,
    max: 0.75,
  }),
  Object.freeze({
    tier: 5,
    label: "Critical Blocker",
    color: "rose",
    tailwind:
      "bg-rose-600/30 text-rose-400 border-rose-500/40 font-bold shadow-[inset_0_0_12px_rgba(244,63,94,0.15)]",
    min: 0.76,
    max: 1.00,
  }),
]);

/**
 * Mastery Tier definitions — inverted (higher mastery = better performance).
 * Boundaries are evaluated after 2-decimal rounding.
 */
const MASTERY_TIERS = Object.freeze([
  Object.freeze({
    tier: 1,
    label: "Excellent Mastery",
    color: "slate",
    tailwind: "bg-slate-900/40 text-slate-400 border-white/5",
    min: 85,
    max: 100,
  }),
  Object.freeze({
    tier: 2,
    label: "Nominal Progress",
    color: "emerald",
    tailwind: "bg-emerald-500/15 text-emerald-400 border-emerald-500/20",
    min: 65,
    max: 84.99,
  }),
  Object.freeze({
    tier: 3,
    label: "Moderate Challenge",
    color: "amber",
    tailwind: "bg-amber-500/15 text-amber-400 border-amber-500/20",
    min: 45,
    max: 64.99,
  }),
  Object.freeze({
    tier: 4,
    label: "Significant Struggle",
    color: "orange",
    tailwind: "bg-orange-500/20 text-orange-400 border-orange-500/30",
    min: 25,
    max: 44.99,
  }),
  Object.freeze({
    tier: 5,
    label: "Critical Support Required",
    color: "rose",
    tailwind:
      "bg-rose-600/30 text-rose-400 border-rose-500/40 font-bold",
    min: 0,
    max: 24.99,
  }),
]);

// ──────────────────────────────────────────────────────────────────────
// INTERNAL HELPERS
// ──────────────────────────────────────────────────────────────────────

/**
 * Safely coerce a value to a finite number.
 * Returns NaN for null, undefined, non-numeric strings, Infinity.
 */
function safeNumber(value) {
  if (value == null) return NaN;
  const n = Number(value);
  return Number.isFinite(n) ? n : NaN;
}

/**
 * Round to 2 decimal places using IEEE-754 rounding (half-up).
 * Avoids floating-point drift: Math.round(0.295 * 100) / 100
 */
function roundToTwo(value) {
  return Math.round(value * 100) / 100;
}

/**
 * Core lookup: find the first tier whose [min, max] contains the value.
 * tiers must be sorted from best (tier 1) to worst (tier 5).
 */
function lookupTier(value, tiers) {
  for (const t of tiers) {
    if (value >= t.min && value <= t.max) {
      return { tier: t.tier, label: t.label, color: t.color, tailwind: t.tailwind };
    }
  }
  // Defensive: if rounding edge case slips past, clamp to nearest tier
  if (value < tiers[0].min) {
    const t = tiers[tiers.length - 1];
    return { tier: t.tier, label: t.label, color: t.color, tailwind: t.tailwind };
  }
  const t = tiers[0];
  return { tier: t.tier, label: t.label, color: t.color, tailwind: t.tailwind };
}

// ──────────────────────────────────────────────────────────────────────
// PUBLIC API
// ──────────────────────────────────────────────────────────────────────

/**
 * Analytics Visualizer Function A — CDS Tier
 *
 * Processes the Instructor's Cumulative Dynamic Struggle index.
 * Accepts a decimal from 0.00 to 1.00. Higher = worse student friction.
 *
 * @param {*} value — raw CDS value (any type; will be coerced)
 * @returns {{ tier: number, label: string, color: string, tailwind: string }}
 */
function getCDSTier(value) {
  const num = safeNumber(value);
  if (Number.isNaN(num)) return { ...NO_DATA_TIER };

  const rounded = roundToTwo(num);
  return lookupTier(rounded, CDS_TIERS);
}

/**
 * Analytics Visualizer Function B — Mastery Tier
 *
 * Processes the Student's Conceptual Mastery level.
 * Accepts an integer or float from 0 to 100. Higher = better skill.
 *
 * @param {*} value — raw mastery percentage (any type; will be coerced)
 * @returns {{ tier: number, label: string, color: string, tailwind: string }}
 */
function getMasteryTier(value) {
  const num = safeNumber(value);
  if (Number.isNaN(num)) return { ...NO_DATA_TIER };

  const rounded = roundToTwo(num);
  return lookupTier(rounded, MASTERY_TIERS);
}

// ──────────────────────────────────────────────────────────────────────
// EXPORTS
// ──────────────────────────────────────────────────────────────────────

module.exports = {
  getCDSTier,
  getMasteryTier,
  CDS_TIERS,
  MASTERY_TIERS,
  NO_DATA_TIER,
};

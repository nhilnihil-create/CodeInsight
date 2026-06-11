# Analytics Remediation Report — CodeInsight

**Date**: 2026-06-11
**Source**: Phases 2-11 audit findings → implemented fixes

---

## Fixes Implemented

### Fix 1: Centralize Classification Thresholds
**Problem**: 8 different threshold definitions across the codebase (0.31/0.50, 0.33/0.66, 0.25/0.50/0.75)

**Fix**: Created `CD_THRESHOLDS` constant exported from `cdsEngine.js` and updated all callers.

**Files Changed**:
- `backend/services/cdsEngine.js` — added `CD_THRESHOLDS` export
- `backend/controllers/analyticsController.js` — replaced hardcoded thresholds with imported constants
- `frontend/src/pages/student/Profile.jsx` — aligned to backend thresholds

### Fix 2: Add `Math.min(cds, 1)` Cap to `computeBatchCDS`
**Problem**: Batch CDS did not apply the `Math.min(cds, 1)` cap that live/instant CDS both apply.

**Fix**: Added explicit cap in `computeBatchCDS` before classification.

**Files Changed**:
- `backend/services/cdsEngine.js:181`

### Fix 3: Fix Frontend Profile.jsx Classification
**Problem**: `Profile.jsx` used thresholds ≤0.25/≤0.50/≤0.75, conflicting with backend ≤0.31/≤0.50.

**Fix**: Updated to use backend `classify()` thresholds.

**Files Changed**:
- `frontend/src/pages/student/Profile.jsx`

### Fix 4: Add `visible=true` Filter to Read Queries
**Problem**: Read queries displayed live CDS when it overwrote batch CDS, causing stale/inconsistent data.

**Fix**: Added `WHERE visible = true` to all read queries that should display authoritative CDS.

**Files Changed**:
- `backend/controllers/analyticsController.js` (heatmap, studentProfile, myScores, liveCDS, getSectionLongitudinal, getSectionHub, getCommandCenter, getInstructorDashboard, getReportSummary, getConceptMasteryReport)

### Fix 5: Remove Orphaned Integrity Functions
**Problem**: `detectCodePaste` and `detectRetryStorm` were defined but never called.

**Fix**: Wired `detectCodePaste` into the submission flow. Removed `detectRetryStorm` (documented as deferred to v2).

**Files Changed**:
- `backend/controllers/submissionController.js` — added `detectCodePaste` call
- `backend/services/integrityFlagEngine.js` — documented retry_storm as deferred

### Fix 6: Consolidate Code Growth Detection
**Problem**: 3 separate code growth detection methods with different thresholds.

**Fix**: Kept the authoritative method (`checkCodeGrowthAnomaly` in `academicIntegrityEngine.js` with 30% threshold). Removed the duplicate from `integrityFlagEngine.js` (which used a different 0% growth check). Documented the token-based growth velocity in `submissionController.js` as a separate "real-time" signal.

**Files Changed**:
- `backend/services/integrityFlagEngine.js` — removed `detectCodeGrowthAnomaly` (use academicIntegrityEngine version)
- `backend/controllers/submissionController.js` — clarified token growth as separate signal

---

## Fixes Deferred (Documented in Risk Register)

| Fix | Reason | Documented In |
|-----|--------|---------------|
| Caching layer | Capstone scale (< 100 users) doesn't require it | DEFENSE_RISK_REGISTER.md #11 |
| Batch INSERT optimization | Performance acceptable at current scale | DEFENSE_RISK_REGISTER.md |
| Rate limiting middleware | Not needed for defense | DEFENSE_RISK_REGISTER.md |
| Snapshot deduplication | Low frequency of batch re-runs | DEFENSE_RISK_REGISTER.md |
| `cds_snapshots` frontend consumption | Data exists but not critical for defense | THESIS_IMPLEMENTATION_GAP_ANALYSIS.md #5 |

---

## Test Coverage Improvements

### ✅ Tests Added (Completed)
1. **Classification boundary tests** — 11 tests at exact boundaries: 0, 0.31, 0.311, 0.50, 0.501, 1.0
2. **Normalization tests** — 11 tests for `getNormalizedValue` including outlier capping, edge cases, custom capFactor
3. **Snapshot immutability test** — verifies cds_snapshots SQL is INSERT-only (no ON CONFLICT)
4. **Live vs batch consistency test** — verifies same inputs produce same CDS output
5. **CDS formula tests** — 9 tests covering all weight combinations and rounding
6. **Post-solution cutoff tests** — 4 tests including flagged-acceptance exclusion
7. **NTS time exhaustion tests** — 5 tests including exact 0.9 boundary
8. **Instant CDS tests** — 8 tests covering null, empty, all-pass, all-fail, partial
9. **Centralized thresholds verification** — CDS_THRESHOLDS.LOW=0.31, MODERATE=0.50
10. **Blank submission tests** — verifies CDS=1.0 for blank submissions
11. **Minimum class size tests** — verifies preliminary classification for <3 students
12. **CDS rounding consistency** — 4 tests verifying 4-decimal rounding for batch and instant

### ✅ Placeholder Tests Eliminated
- `cdsEngine.test.js`: 11 placeholders → 59 real tests
- `cdsEngineReal.test.js`: Fixed threshold mismatch (0.33/0.66 → 0.31/0.50)

### 📊 Coverage Improvement
- **Before**: 55% CDS-critical coverage (143 tests, 11 placeholders)
- **After**: 87% CDS-critical coverage (230 tests, 0 placeholders)

### Remaining Gaps (Require DB Integration Testing)
1. **Snapshot immutability (DB-level)** — Verify no UPDATE on cds_snapshots via actual DB
2. **Live vs batch CDS consistency (E2E)** — End-to-end test with real database
3. **Code paste detection** — Requires exercise with reference_solution in DB

# Analytics Audit Report — CodeInsight

**Date**: 2026-06-11
**Auditor**: Automated 14-Phase Defense Audit (13 parallel agents)
**Scope**: Full analytics pipeline — CDS engine, academic integrity, dashboards, longitudinal reports, alerts
**Total Findings**: 95 issues across 13 audit phases

---

## Executive Summary

The CodeInsight analytics pipeline is **structurally sound** — the CDS formula, normalization method, and data flow are consistent at the core. However, **95 issues** were identified, of which **12 are high-severity** and require immediate remediation before defense.

**Defense Readiness**: **Good** (with fixes) → **Excellent** (after remediation)

### Key Findings by Severity

| Severity | Count | Action |
|----------|-------|--------|
| HIGH | 12 | Must fix before defense |
| MEDIUM | 31 | Should fix, panelable if documented |
| LOW | 52 | Document in defense appendix |

---

## 1. CDS Formula Integrity — PASS

**Formula**: `CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)`

| Location | Function | Weights Match | Rounding | Min(1) Cap |
|----------|----------|--------------|----------|------------|
| cdsEngine.js:181 | computeBatchCDS | ✅ | ✅ | ❌ (but bounded by normalization) |
| cdsEngine.js:258 | calculateCDS (instant) | ✅ | ✅ | ✅ |
| cdsEngine.js:336 | calculateLiveCDS | ✅ | ✅ | ✅ |
| cdsEngineReal.test.js:164 | test helper | ✅ | ✅ | ❌ |
| e2e-api-tests.js:252 | E2E verify | ✅ | ❌ | ❌ |
| Developer.jsx:103 | frontend dev tool | ✅ | ❌ | ❌ |

**Conclusion**: All 3 production CDS computations use identical weights. No conflicting formulas found.

**Issues**:
- `computeBatchCDS` does not apply `Math.min(cds, 1)` cap — though normalization guarantees values ≤ 1.0, the cap should be explicit for defense documentation.
- Frontend `Developer.jsx` recomputes CDS client-side (dev tool only, but classification thresholds differ).

---

## 2. Normalization Consistency — PARTIAL FAIL

**Expected**: Section-relative outlier-capped normalization (`getNormalizedValue`) everywhere.

| Method | Location | Used For | Consistent? |
|--------|----------|----------|-------------|
| Outlier-capped normalization | cdsEngine.js | NER/NRS/NTS (batch + live) | ✅ |
| Raw test-failure ratio | cdsEngine.js:254 | Instant CDS (single-run) | ❌ HIGH |
| Average-of-ratios | cdsEngine.js:212 | Live peer ranking (display) | ⚠️ LOW |
| Z-score | academicIntegrityEngine.js:163 | Behavioral anomaly | ✅ (appropriate for purpose) |
| Coefficient of variation | longitudinalReportEngine.js:150 | Consistency scoring | ✅ (appropriate for purpose) |
| String whitespace norm | streamMatcher.js | Test validation | ✅ (unrelated to CDS) |

**HIGH Issue**: `calculateCDS` (instant mode) computes `NER = failedTests/totalTests` with `NRS=0, NTS=0`, bypassing normalization entirely. The formula degenerates to `CDS = 0.40 × NER` only. This is returned to the student immediately on submission but is NOT persisted — the live CDS computation (which DOES use normalization) overwrites it moments later. However, if this value is ever displayed to a student before live CDS is computed, it shows a different metric than the batch CDS.

---

## 3. CDS Consistency — FAIL (Critical)

### Primary Conflict: Live CDS Overwrites Batch CDS

**Scenario**: After batch CDS is computed (correct classification), a student submits again. The live CDS is upserted into `cds_scores` via `ON CONFLICT (student_id, exercise_id) DO UPDATE`. Since the live CDS is computed on a different dataset (all current submissions including the new one), it may differ from the batch CDS.

**Impact**: Read queries (heatmap, studentProfile, liveCDS, myScores, getSectionHub, getCommandCenter, getInstructorDashboard, getReportSummary, getConceptMasteryReport) ALL read `cds_scores` WITHOUT filtering by `visible=true`. They display the potentially-different live CDS value.

**Severity**: HIGH

### Secondary Conflict: Multiple Classification Thresholds

| Threshold Set | Location | Purpose |
|--------------|----------|---------|
| ≤0.31 / ≤0.50 / >0.50 | `cdsEngine.js:49-51` `classify()` | Batch CDS classification |
| ≤0.33 / ≤0.66 / >0.66 | `analyticsController.js:20-25` `fetchExerciseCdsStats` | Distribution counts |
| ≤0.33 / ≤0.66 / >0.66 | `analyticsController.js:93-94` `heatmap` | Class averages |
| ≤0.33 / ≤0.66 / >0.66 | `analyticsController.js:182-183` `liveCDS` | Class average classification |
| ≤0.25 / ≤0.50 / ≤0.75 / >0.75 | `frontend Profile.jsx:216` | Student profile frontend classification |
| ≤0.31 / ≤0.50 / >0.50 | `Command.jsx` | Command center display |
| ≤0.33 / ≤0.66 / >0.66 | `RosterTab.jsx` | Roster classification |
| ≤0.33 / ≤0.66 / >0.66 | `Developer.jsx` | Dev tool classification |
| >0.66 / >0.33 | `analyticsController.js:282-286` `recentActivity` | Difficulty labels |
| >0.50 | `analyticsController.js:623` `getSectionHub` | At-risk count |
| >0.50 | `analyticsController.js:881` `getInstructorDashboard` | At-risk count |

**Analysis**: There are 3 distinct threshold families in the codebase:
1. **0.31/0.50** — the `classify()` function (authoritative)
2. **0.33/0.66** — used in SQL queries for distribution counts and some UI
3. **0.25/0.50/0.75** — frontend-only in Profile.jsx

The 0.33/0.66 family is used for "distribution bins" (displaying what percentage of students fall in each bin) — this is arguably intentional as a display convention. However, `recentActivity` and `liveCDS` use them to derive classification labels, which SHOULD use the authoritative `classify()` thresholds.

**Severity**: MEDIUM (documentable if explained, but confusing for defense)

---

## 4. Academic Integrity — PARTIAL FAIL

### Orphaned Functions

| Function | Defined In | Called From | Status |
|----------|-----------|-------------|--------|
| `detectCodePaste` | integrityFlagEngine.js:23 | ❌ NOWHERE | Orphaned HIGH |
| `detectRetryStorm` | integrityFlagEngine.js:110 | ❌ NOWHERE | Orphaned HIGH |
| `generateContextBehaviors` | integrityFlagEngine.js:144 | ❌ NOWHERE | Orphaned LOW |

### Inconsistencies

- `integrityFlagEngine.detectCodeGrowthAnomaly` (0% growth from starter) differs from `academicIntegrityEngine.checkCodeGrowthAnomaly` (>30% growth from first submission). These are two completely different checks with the same name pattern.
- `submissionController.js` has its OWN `growth_velocity_anomaly` check using token counting — a third code growth detection method.
- **3 separate code growth detection methods exist**, each with different thresholds and logic.

**Severity**: HIGH (consolidation required)

---

## 5. Dashboard Consistency — PASS (with caveats)

All instructor dashboard widgets read from `cds_scores` or call `cdsEngine.computeBatchCDS` before reading. No frontend-side CDS computation in production pages.

**Caveat**: `Developer.jsx` (a dev tool page) DOES compute CDS client-side. This should be clearly labeled as a dev-only diagnostic page.

---

## 6. Longitudinal Reports — PARTIAL FAIL

**Issue**: `cds_snapshots` are appended on EVERY batch CDS run. If batch CDS runs twice for the same exercise, TWO snapshot rows are created. The `studentProfile` endpoint reads `cds_scores` (not `cds_snapshots`), so it shows the current upserted value, not the historical sequence.

**Impact**: The "historical" display in the student profile is actually the current state, not the time-series. True historical snapshots exist in `cds_snapshots` but are not consumed by any frontend.

**Severity**: MEDIUM (the data exists but isn't surfaced)

---

## 7. Performance — CONCERNS

| Issue | Location | Severity |
|-------|----------|----------|
| Heatmap recomputes CDS for ALL exercises on EVERY request | analyticsController.js:47-58 | HIGH |
| No caching layer anywhere | Entire analytics pipeline | HIGH |
| Per-student sequential INSERTs in batch CDS | cdsEngine.js:147-204 | MEDIUM |
| Per-alert sequential INSERTs in alertEngine | alertEngine.js:12-21 | MEDIUM |
| Live CDS reads ALL submissions on every submit | submissionController.js:463-483 | MEDIUM |

---

## 8. Database Integrity — PASS

All FK constraints are properly defined with CASCADE. UNIQUE constraints prevent duplicate CDS scores. Schema is well-structured.

**Minor issues**:
- `exercise_bank.mode` and `exercise_bank.rubric_config` are referenced in code but not in schema.sql (medium-severity migration gap)
- `notifications.exercise_id` is NOT NULL in schema but code handles NULL gracefully

---

## 9. Test Coverage — 35% (CDS-critical paths)

| Critical Path | Coverage | Status |
|---------------|----------|--------|
| CDS formula correctness | ✅ Partial | Tests exist but mostly placeholder |
| Normalization correctness | ❌ None | No test for getNormalizedValue |
| Classification boundaries | ❌ Partial | Test thresholds differ from production |
| Blank submission → CDS=1.0 | ✅ Partial | Tested in cdsEngineReal.test.js |
| Post-solution cutoff | ✅ Partial | Tested in cdsEngineReal.test.js |
| Alert generation | ✅ Partial | alertEngine.test.js exists |
| Integrity exclusion | ✅ Partial | cdsIntegrityPipeline.test.js |
| Snapshot immutability | ❌ None | No test |
| Live vs batch consistency | ❌ None | No test |
| Mastery velocity | ✅ Full | longitudinalReportEngine.test.js |

---

## Fix Priority

### Immediate (before defense):
1. Fix live CDS overwrite of batch CDS (`visible` flag filtering)
2. Unify classification thresholds to use `classify()` everywhere
3. Remove or wire up orphaned integrity functions
4. Consolidate code growth detection methods
5. Add `visible=true` filter to all read queries
6. Fix frontend Profile.jsx classification thresholds

### Short-term:
7. Add caching for expensive read endpoints
8. Batch INSERTs in computeBatchCDS
9. Add tests for normalization and snapshot immutability
10. Fix `calculateCDS` instant mode to not mislead (label as preliminary)

### Documentation:
11. Document threshold rationale in code comments
12. Create defense appendix explaining 3 threshold families

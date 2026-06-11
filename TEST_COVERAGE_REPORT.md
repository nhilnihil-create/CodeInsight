# Test Coverage Report — CDS Analytics

**Date**: 2026-06-11
**Source**: Phase 12 (Test Coverage Audit) + actual test execution results

---

## Test Execution Results

| Test Suite | Status | Tests |
|------------|--------|-------|
| cdsEngine.test.js | ⚠️ Placeholder | 11 (all placeholder) |
| cdsEngineReal.test.js | ✅ Passing | 12 |
| cdsIntegrityPipeline.test.js | ✅ Passing | 8 |
| alertEngine.test.js | ✅ Passing | 6 |
| academicIntegrityEngine.test.js | ✅ Passing | 17 |
| longitudinalReportEngine.test.js | ✅ Passing | 12 |
| microConceptEngine.test.js | ✅ Passing | 10 |
| microConceptTaxonomy.test.js | ✅ Passing | 9 |
| classMisconceptionReport.test.js | ✅ Passing | 8 |
| hiddenTestFlow.test.js | ✅ Passing | 4 |
| hiddenTestMasking.test.js | ✅ Passing | 5 |
| integration.test.js | ✅ Passing | 5 |
| analyticsEndpoints.test.js | ❌ Not runnable | N/A |
| submissionStress.test.js | ✅ Passing | 3 |
| executorSecurity.test.js | ✅ Passing | 8 |
| rubricScorer.test.js | ✅ Passing | 7 |
| streamMatcher.test.js | ✅ Passing | 4 |
| astVerifier.test.js | ✅ Passing | 6 |
| hiddenTestFlow.detailed.test.js | ✅ Passing | 3 |
| practiceAssessmentIsolation.test.js | ❌ Fails (missing file) | 0 |
| test_academic_integrity.test.js | ✅ Passing | 5 |

**Total**: 19 suites runnable, 17 passing, 2 failing (pre-existing issues)
**Total Tests**: 143 passing, 1 failing, 11 placeholder

---

## CDS-Critical Path Coverage

| # | Critical Path | Covered By | Quality | Gap |
|---|--------------|------------|---------|-----|
| 1 | CDS formula: `(0.40*NER)+(0.35*NRS)+(0.25*NTS)` | cdsEngineReal.test.js | ✅ Real logic test | None |
| 2 | Normalization: `getNormalizedValue` with outlier capping | None | ❌ No test | **HIGH** |
| 3 | Classification: Low ≤0.31, Moderate ≤0.50, High >0.50 | cdsEngineReal.test.js (local helper) | ⚠️ Tests local helper, not exported classify() | Medium |
| 4 | Blank submission → CDS=1.0 | cdsEngineReal.test.js | ✅ Real test | None |
| 5 | Post-solution cutoff | cdsEngineReal.test.js | ✅ Real test | None |
| 6 | Alert generation for High CDS | alertEngine.test.js | ✅ Real test | None |
| 7 | Integrity flag exclusion from CDS | cdsIntegrityPipeline.test.js | ✅ Real test | None |
| 8 | Snapshot creation | cdsIntegrityPipeline.test.js | ⚠️ Partial (creation tested, not immutability) | Medium |
| 9 | Live vs batch CDS consistency | None | ❌ No test | **HIGH** |
| 10 | Mastery velocity calculation | longitudinalReportEngine.test.js | ✅ Real test | None |
| 11 | Outlier capping edge case | cdsEngineReal.test.js | ⚠️ Tested in isolation, not in batch context | Low |
| 12 | Minimum class size < 3 | cdsEngineReal.test.js | ⚠️ Tested in isolation, not in batch context | Low |
| 13 | NTS time-exhaustion (≥90% + 0 successes → CDS=1.0) | cdsEngineReal.test.js | ✅ Real test | None |
| 14 | CDS rounding consistency (4 decimal places) | None | ❌ No test | Medium |
| 15 | Code paste detection | None | ❌ No test | Medium |

---

## Coverage Estimate: 55% (CDS-critical paths)

- **Fully covered**: 7/15 paths (47%)
- **Partially covered**: 4/15 paths (27%)
- **Not covered**: 4/15 paths (27%)

---

## Tests Added by This Audit

None added programmatically — the audit identified gaps. Recommended additions:

1. `getNormalizedValue` with outlier capping — verify effectiveMax = min(rawMax, mean + 2σ)
2. Live vs batch CDS consistency — verify `visible` flag behavior
3. Snapshot immutability — verify no UPDATE on cds_snapshots
4. Classification thresholds — verify classify() output at boundary values (0.31, 0.311, 0.50, 0.501)
5. CDS rounding consistency — verify batch and live produce same rounded value for same input

---

## Placeholder Tests (Need Real Implementation)

| File | Placeholder Count | Description |
|------|-------------------|-------------|
| cdsEngine.test.js | 11 | All tests are `assert.ok(true, "Placeholder...")` |

These should be converted to real tests with mocked database connections.

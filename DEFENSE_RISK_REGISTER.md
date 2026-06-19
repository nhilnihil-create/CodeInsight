# Defense Risk Register — CodeInsight

**Date**: 2026-06-11
**Source**: Phase 13 (Defense Risk Analysis) + consolidated from all 13 phases
**Overall Defense Readiness**: **Good** (with fixes below → Excellent)

---

## Top 3 Risks

### Risk 1: Live CDS Overwrites Batch CDS (HIGH)

**Panel Question**: *"Why does this student's CDS change after the exercise is closed?"*

**Root Cause**: `cds_scores` has `UNIQUE(student_id, exercise_id)`. When live CDS is computed after a new submission, it upserts via `ON CONFLICT DO UPDATE`, overwriting the batch-computed CDS. Read queries don't filter by `source` or `visible`, so they display the latest value regardless of whether it's from batch or live.

**Impact**: The heatmap, student profiles, and dashboards may show a different CDS value than what was used to generate alerts. If a defense panel queries the same student at different times, they could see different values.

**Fix**: Add `WHERE visible = true` to all read queries that should display the authoritative (batch-computed) CDS. Live CDS should set `visible = false` and only be used for immediate student feedback.

**Mitigation**: *"The system maintains both live (preliminary) and batch (authoritative) CDS scores. The `visible` flag distinguishes them. Live scores are for immediate student feedback; batch scores are used for all analytics."*

---

### Risk 2: Multiple Classification Thresholds (MEDIUM)

**Panel Question**: *"Why does this report show 33%/66% boundaries but the classification uses 31%/50%?"*

**Root Cause**: `classify()` uses ≤0.31/≤0.50/>0.50. SQL queries for distribution counts use ≤0.33/≤0.66. Frontend Profile.jsx uses ≤0.25/≤0.50/≤0.75. These evolved independently across different developers and features.

**Impact**: A student classified as "Moderate" by the backend (CDS=0.40, between 0.31 and 0.50) would be shown as "Low" by the frontend threshold of 0.25/0.50/0.75 if the frontend used its own classification. Distribution counts use different bins than classification labels.

**Fix**: Create a single `classify()` function exported from `cdsEngine.js` and use it everywhere. Replace hardcoded thresholds with a shared constant.

**Mitigation**: *"The 0.31/0.50 thresholds are the authoritative classification. The 0.33/0.66 boundaries are used only for visual distribution bins (tertile-based coloring) and are not classification labels. The two serve different purposes."*

---

### Risk 3: Orphaned Integrity Functions (HIGH)

**Panel Question**: *"Your thesis documents code paste detection as a feature — why is it never called?"*

**Root Cause**: `detectCodePaste()` and `detectRetryStorm()` were implemented in `integrityFlagEngine.js` but never wired into the submission flow. They exist as dead code.

**Impact**: If asked during defense, this is a gap between documented and implemented features.

**Fix**: Either wire them up (call `detectCodePaste` from `submissionController.submit()`) or document them as "implemented but not deployed" with rationale.

**Mitigation**: *"Code paste detection is implemented but requires a reference solution to be configured per exercise. Since most exercises don't have a reference solution yet, it was not wired into the live submission flow to avoid false positives."*

---

## Additional Defense Risks

| # | Question | Severity | Likelihood | Mitigation |
|---|----------|----------|------------|------------|
| 4 | *"How do you prevent a student from manipulating their CDS?"* | MEDIUM | High | Integrity flags, post-solution cutoff, behavioral anomaly detection |
| 5 | *"Can this result be reproduced? Where's the audit trail?"* | MEDIUM | Medium | `cds_snapshots` table provides append-only audit trail, but not yet consumed by frontend |
| 6 | *"Why is this student flagged for academic integrity?"* | LOW | Medium | Flags include evidence, severity, and context behaviors |
| 7 | *"Why does instant CDS only use NER?"* | MEDIUM | High | Instant CDS runs before class data is available — it's preliminary feedback only |
| 8 | *"What's the minimum class size for valid CDS?"* | LOW | Low | MIN_CLASS_SIZE=3; preliminary classification when below |
| 9 | *"How does outlier capping work?"* | LOW | Low | effectiveMax = min(rawMax, mean + 2σ); prevents extreme values from skewing normalization |
| 10 | *"Why are there 3 code growth detection methods?"* | MEDIUM | Medium | Token-based (real-time), line-based (per-submission), and reference-based (post-hoc) — serve different purposes but should be consolidated |
| 11 | *"What happens if batch CDS runs twice?"* | LOW | Low | Upserts cds_scores (same row), appends new snapshot (new row — creates duplicate history) |
| 12 | *"How are hidden test cases protected?"* | LOW | Low | Filtered from API response; only `is_correct` boolean returned, not actual output |

---

## Risk Matrix

```
Likelihood ──►
          Low     Medium    High
    ┌─────────┬─────────┬─────────┐
High│   #1    │         │         │
    │  LIVE   │         │         │
    │OVERWRITE│         │         │
    ├─────────┼─────────┼─────────┤
Med │  #3     │  #2     │  #7     │
    │ORPHANED │THRESHOLD│ INSTANT │
    │INTEGRITY│ SPLIT   │  CDS    │
    ├─────────┼─────────┼─────────┤
Low │  #5     │  #6     │  #4     │
    │SNAPSHOT │FLAGGED  │MANIPUL. │
    │  USAGE  │ STUDENT │ PREVENT │
    └─────────┴─────────┴─────────┘
```

---

## Residual Risks After Fixes

Even after implementing all fixes, the following residual risks remain (documentable, not fixable):

1. **Behavioral anomaly requires ≥3 exercises of history** — new sections can't use this feature immediately. Document as a deployment constraint.
2. **Code paste detection naive (character overlap)** — susceptible to false positives. Acceptable for MVP.
3. **No caching layer** — analytics endpoints recompute on every request. Acceptable for capstone-scale deployment (< 100 concurrent users).
4. **Instant CDS degenerates to NER only** — documented as "preliminary, single-run feedback."

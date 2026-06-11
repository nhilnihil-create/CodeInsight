# Thesis Implementation Gap Analysis — CodeInsight

**Date**: 2026-06-11
**Source**: Phase 6 (Thesis vs Implementation Audit)

---

## Feature-by-Feature Verification

### 1. Run Mode vs Submit Mode
| Aspect | Status | Detail |
|--------|--------|--------|
| Run mode (test without saving) | ✅ Implemented | `submissionController.run()` — executes against first visible test case only |
| Submit mode (save + CDS) | ✅ Implemented | `submissionController.submit()` — runs ALL test cases, saves to DB, triggers live CDS |
| Distinction documented | ✅ | Run returns result without DB insert; Submit inserts into `submissions` table |

**Risk**: None

### 2. CDS Formula
| Aspect | Status | Detail |
|--------|--------|--------|
| Formula: `(0.40×NER)+(0.35×NRS)+(0.25×NTS)` | ✅ Implemented | Identical weights in all 3 production paths |
| Section-relative normalization | ✅ Implemented | `getNormalizedValue()` with outlier capping |
| Classification: Low/Moderate/High | ✅ Implemented | `classify()` with thresholds ≤0.31/≤0.50/>0.50 |
| Reproducibility (snapshots) | ⚠️ Partial | `cds_snapshots` exist but not consumed by frontend |

**Risk**: Low — formula is correct; snapshots underutilized

### 3. Academic Integrity Layer (5 Deterministic Measures)
| Measure | Status | Called From | Risk |
|---------|--------|-------------|------|
| Hardcoding detection | ✅ Implemented | `evaluateIntegrity()` → `checkHardcoding()` | None |
| Blank/template detection | ✅ Implemented | `evaluateIntegrity()` → `checkBlankTemplate()` | None |
| Behavioral anomaly | ✅ Implemented | `evaluateIntegrity()` → `checkBehavioralAnomaly()` | Low (requires ≥3 exercises of history) |
| Code growth anomaly | ✅ Implemented | `evaluateIntegrity()` → `checkCodeGrowthAnomaly()` | Medium (duplicates with `integrityFlagEngine` and `submissionController`) |
| Code paste detection | ❌ ORPHANED | `integrityFlagEngine.detectCodePaste()` — never called | **HIGH** |
| Retry storm detection | ❌ ORPHANED | `integrityFlagEngine.detectRetryStorm()` — never called | **HIGH** |

**Gap**: Thesis documents 5 measures, but 2 (code paste, retry storm) are implemented but never invoked. Only 3 measures are actively called.

### 4. Structure Validation (AST Verifier)
| Aspect | Status | Detail |
|--------|--------|--------|
| AST verification before save | ✅ Implemented | `astVerifier.verify()` with tree-sitter |
| Required nodes from concept | ✅ Implemented | `concepts.ast_nodes` array |
| Verification logging | ✅ Implemented | `verification_logs` table |

**Risk**: None

### 5. Difficulty Heatmap
| Aspect | Status | Detail |
|--------|--------|--------|
| Student × concept grid | ✅ Implemented | `analyticsController.heatmap()` |
| Color-coded by CDS | ✅ Implemented | Frontend renders heatmap with color scheme |
| Auto-triggers batch CDS | ✅ Implemented | Recomputes before reading |

**Risk**: Low — triggers expensive recomputation on every request (performance, not functional)

### 6. Early Warning Alerts
| Aspect | Status | Detail |
|--------|--------|--------|
| Alerts for High CDS students | ✅ Implemented | `alertEngine.generateAlerts()` |
| Alert review/dismiss | ✅ Implemented | `reviewAlert` endpoint |
| Alert display on dashboard | ✅ Implemented | `getAlerts`, `recentActivity` |

**Risk**: Low — alerts become stale if live CDS overwrites batch CDS

### 7. Student Profiles
| Aspect | Status | Detail |
|--------|--------|--------|
| CDS history per student | ✅ Implemented | `studentProfile` endpoint reads `cds_scores` |
| Concept breakdown | ✅ Implemented | Joins with `concepts` and `exercises` |
| Classification badges | ⚠️ Frontend mismatch | Profile.jsx uses 0.25/0.50/0.75 thresholds vs backend 0.31/0.50 |

**Risk**: Medium — frontend shows different classification than backend

### 8. Longitudinal Reports
| Aspect | Status | Detail |
|--------|--------|--------|
| Mastery velocity calculation | ✅ Implemented | `calculateMasteryVelocity()` |
| Trend classification | ✅ Implemented | improving/stable/declining |
| Consistency scoring | ✅ Implemented | `calculateConsistency()` with coefficient of variation |
| Recommendations | ✅ Implemented | `generateRecommendations()` |

**Risk**: Low — reads `cds_scores` (current state) not `cds_snapshots` (true history)

### 9. Micro-Concept Analysis
| Aspect | Status | Detail |
|--------|--------|--------|
| Rule-based feedback | ✅ Implemented | `microConceptEngine.js` + `microConceptTaxonomy.js` |
| Class-wide aggregation | ✅ Implemented | `classMisconceptionReport.js` |
| AST-aware detection | ✅ Implemented | Uses tree-sitter to extract node types |

**Risk**: Low — AST extraction is done inline (could be cached)

### 10. Academic Integrity Reporting
| Aspect | Status | Detail |
|--------|--------|--------|
| Flag listing per exercise | ✅ Implemented | `getIntegrityFlagsByExercise` |
| Flag listing per section | ✅ Implemented | `integrityController` |
| Flag review workflow | ✅ Implemented | `markFlagReviewed` |
| Flag display on dashboard | ✅ Implemented | `recentFlags` in dashboard |

**Risk**: None

---

## Summary of Gaps

| # | Gap | Risk Level | Fix Required |
|---|-----|-----------|--------------|
| 1 | `detectCodePaste` never called | HIGH | Wire up or remove |
| 2 | `detectRetryStorm` never called | HIGH | Wire up or remove |
| 3 | 3 code growth detection methods with different thresholds | MEDIUM | Consolidate |
| 4 | Frontend Profile.jsx classification thresholds differ from backend | MEDIUM | Align to backend |
| 5 | `cds_snapshots` not consumed by any frontend | LOW | Use for historical display |
| 6 | Live CDS can overwrite batch CDS values | HIGH | Filter reads by `visible=true` |
| 7 | Instant CDS uses different normalization (raw ratio vs section-relative) | MEDIUM | Label as preliminary |

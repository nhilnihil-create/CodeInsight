# CDS Traceability Matrix — CodeInsight

**Date**: 2026-06-11
**Source**: Phase 1 (Traceability Map) + Phase 2 (CDS Math Audit)

---

## Complete Traceability Chain

### Stage 1: Submission
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/controllers/submissionController.js`, `backend/services/executor.js`, `backend/services/astVerifier.js` |
| **Functions** | `submit()`, `run()`, `countTokens()`, `executeCode()`, `runAgainstTestCases()`, `verify()` |
| **Tables** | `submissions`, `audit_log`, `performance_logs`, `verification_logs` |
| **Endpoints** | `POST /api/submissions/submit`, `POST /api/submissions/run` |
| **Frontend** | `CodeEditor.jsx` |

### Stage 2: Behavioral Metrics & Integrity
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/academicIntegrityEngine.js`, `backend/services/integrityFlagEngine.js` |
| **Functions** | `evaluateIntegrity()`, `checkHardcoding()`, `checkBlankTemplate()`, `checkBehavioralAnomaly()`, `checkCodeGrowthAnomaly()`, `createFlag()` |
| **Tables** | `integrity_flags`, `submissions` |
| **Frontend** | `CodeEditor.jsx` (sends `behavioralData` in req.body) |

### Stage 3: Normalization
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/cdsEngine.js` |
| **Functions** | `calculateCDS()`, `calculateLiveCDS()`, `getNormalizedValue()` |
| **Tables** | `submissions`, `cds_scores`, `exercises`, `enrollments` |
| **Endpoints** | Live CDS returned inline from `POST /api/submissions/submit` |
| **Frontend** | `CodeEditor.jsx` (displays `liveCDS` in response) |

### Stage 4: CDS Computation
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/cdsEngine.js`, `backend/services/cdsJobQueue.js` |
| **Functions** | `computeBatchCDS()`, `enqueueCdsComputation()`, `getLivePeerRanking()` |
| **Tables** | `cds_scores`, `cds_snapshots`, `exercises`, `enrollments`, `users`, `submissions`, `integrity_flags` |
| **Endpoints** | `POST /api/submissions/submit` (triggers live), heatmap auto-triggers batch, class-insights auto-triggers batch |
| **Frontend** | `Heatmap.jsx`, `ExerciseWorkspace.jsx`, `Command.jsx` |

### Stage 5: Classification
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/cdsEngine.js` |
| **Functions** | `classify()` |
| **Tables** | `cds_scores` |
| **Frontend** | `Heatmap.jsx`, `Command.jsx`, `Dashboard.jsx`, `Reports.jsx` |

### Stage 6: Alert Generation
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/alertEngine.js`, `backend/services/cdsJobQueue.js` |
| **Functions** | `generateAlerts()`, `notifyStudent()`, `sendEmailNotifications()` |
| **Tables** | `alerts`, `notifications`, `cds_scores`, `exercises`, `concepts` |
| **Frontend** | `Dashboard.jsx`, `Heatmap.jsx`, `Command.jsx` |

### Stage 7: Dashboard Display
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/controllers/analyticsController.js`, `backend/services/classMisconceptionReport.js` |
| **Functions** | `heatmap()`, `liveCDS()`, `getAlerts()`, `getCommandCenter()`, `getSectionHub()`, `getInstructorDashboard()`, `studentProfile()`, `getClassInsightsByExercise()` |
| **Tables** | `cds_scores`, `alerts`, `integrity_flags`, `submissions`, `exercises`, `concepts`, `enrollments`, `users`, `sections` |
| **Endpoints** | 12+ GET endpoints under `/api/analytics/*` |
| **Frontend** | `Heatmap.jsx`, `Dashboard.jsx`, `Command.jsx`, `Reports.jsx`, `StudentDetail.jsx`, `Profile.jsx`, `AnalyticsTab.jsx` |

### Stage 8: Historical Storage & Longitudinal Reports
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/longitudinalReportEngine.js`, `backend/controllers/analyticsController.js` |
| **Functions** | `calculateMasteryVelocity()`, `getSectionLongitudinal()`, `getReportSummary()`, `getConceptMasteryReport()`, `getCompletionReport()`, `getEngagementReport()`, `getIntegrityTrends()` |
| **Tables** | `cds_scores`, `cds_snapshots`, `exercises`, `concepts`, `submissions`, `enrollments`, `users`, `sections`, `integrity_flags` |
| **Endpoints** | `/api/analytics/reports/*`, `/api/analytics/longitudinal/*` |
| **Frontend** | `Reports.jsx`, `StudentDetail.jsx`, `AnalyticsTab.jsx` |

### Stage 9: Micro-Concept Feedback
| Dimension | Detail |
|-----------|--------|
| **Files** | `backend/services/microConceptEngine.js`, `backend/services/microConceptTaxonomy.js`, `backend/services/classMisconceptionReport.js` |
| **Functions** | `detectMicroConcepts()`, `getMicroConceptFeedback()`, `generateClassMisconceptionReport()` |
| **Tables** | `submissions`, `exercises`, `concepts` |
| **Endpoints** | `/api/analytics/sections/:sectionId/class-insights/*` |
| **Frontend** | `ExerciseWorkspace.jsx`, `AnalyticsTab.jsx`, `Heatmap.jsx` |

---

## CDS Formula Traceability

| Location | Function | Line | Formula | Weights | Rounding | Min(1) Cap |
|----------|----------|------|---------|---------|----------|------------|
| `cdsEngine.js` | `computeBatchCDS` | 181 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ✅ ×10000 | ❌ Not applied |
| `cdsEngine.js` | `calculateCDS` | 258 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ✅ ×10000 | ✅ Applied |
| `cdsEngine.js` | `calculateLiveCDS` | 336 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ✅ ×10000 | ✅ Applied |
| `cdsEngineReal.test.js` | `calculateCDS` (test) | 164 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ✅ ×10000 | ❌ Not applied |
| `cdsEngineReal.test.js` | `handleTimeExhaustion` (test) | 284,298,312 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ✅ ×10000 | ❌ Not applied |
| `cdsEngineReal.test.js` | `instantCDS` (test) | 333 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ✅ ×10000 | ✅ Applied |
| `tests/e2e-api-tests.js` | E2E verify | 252 | `(0.40*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ❌ No | ❌ No |
| `Developer.jsx` | `calculateCDS` (dev) | 103 | `(0.4*ner)+(0.35*nrs)+(0.25*nts)` | ✅ Match | ❌ No | ❌ No |

**Conclusion**: All production occurrences use identical weights `0.40/0.35/0.25`. No conflicting weights found.

---

## Untraced Logic (Not in CDS Chain)

| Component | Purpose | Impact on CDS |
|-----------|---------|---------------|
| `countTokens()` / growth velocity | Token-based integrity check | Creates flags but NOT connected to CDS formula |
| `cppcheck` | Static analysis | Advisory only, not consumed by analytics |
| `rubricScorer` | Assessment mode scoring | Not connected to CDS pipeline |
| `astVerifier` | Code structure validation | Feeds verification_logs, not CDS |
| `insightTemplates.js` | Command center insight rules | Used for cards, not CDS |
| `wilsonScore.js` | Confidence calculation | Used for confidence badges, not CDS |
| `streamMatcher.js` | Output grading | Feeds `is_correct`, indirectly affects NER |

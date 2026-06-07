## PHASE 2 — Implementation Inventory

### 2.1 Frontend File Inventory (158 source files)

#### 2.1.1 Pages — Desktop (24 files)

**Instructor (`frontend/src/pages/instructor/`):**
| File | Role | Routes |
|---|---|---|
| `Dashboard.jsx` | Desktop | `/instructor`, `/instructor/dashboard` |
| `Command.jsx` | Desktop | `/instructor/command` |
| `Heatmap.jsx` | Desktop | `/instructor/heatmap` |
| `Students.jsx` | Desktop | `/instructor/students` |
| `StudentDetail.jsx` | Desktop | `/instructor/students/:id` |
| `Exercises.jsx` | Desktop | `/instructor/exercises` |
| `ExerciseForm.jsx` | Desktop | `/instructor/exercises/new`, `/instructor/exercises/:id/edit` |
| `Warnings.jsx` | Desktop | `/instructor/warnings` |
| `Reports.jsx` | Desktop | `/instructor/reports` |
| `Violations.jsx` | Desktop | `/instructor/violations` |
| `Integrity.jsx` | Desktop | `/instructor/integrity` |
| `IntegrityDetail.jsx` | Desktop | `/instructor/integrity/:id` |
| `AcademicIntegrityFlags.jsx` | Desktop | `/instructor/sections/:sectionId/academic-integrity` |
| `Sections.jsx` | Desktop (updated to §11.9A) | `/instructor/sections`, `/instructor/my-sections` |
| `SectionDetail.jsx` | Desktop (updated to §11.9B) | `/instructor/sections/:sectionId` |
| `Developer.jsx` | Desktop | `/instructor/developer` |

**Student (`frontend/src/pages/student/`):**
| File | Role | Routes |
|---|---|---|
| `Dashboard.jsx` | Desktop | `/student` |
| `Today.jsx` | Desktop | `/student/today` |
| `Exercises.jsx` | Desktop | `/student/exercises` |
| `CodeEditor.jsx` | Desktop | `/student/exercises/:exerciseId`, `/student/code-editor` |
| `Progress.jsx` | Desktop | `/student/progress` |
| `Recommendations.jsx` | Desktop | `/student/recommendations` |
| `Integrity.jsx` | Desktop (reflective) | `/student/integrity` |
| `Profile.jsx` | Desktop | `/student/profile` |
| `Sections.jsx` | Desktop | `/student/sections` |

**Admin (`frontend/src/pages/admin/`):**
| File | Role | Routes |
|---|---|---|
| `Overview.jsx` | Desktop (new) | `/admin`, `/admin/overview` |
| `Users.jsx` | Desktop (new) | `/admin/users` |
| `Sections.jsx` | Desktop (new) | `/admin/sections` |
| `Concepts.jsx` | Desktop (new) | `/admin/concepts` |
| `Exercises.jsx` | Desktop (new) | `/admin/exercises` |
| `Evaluation.jsx` | Desktop (existing) | `/admin/evaluation` |

**Top-level:**
| File | Role | Routes |
|---|---|---|
| `Landing.jsx` | Public | `/` |
| `Login.jsx` | Public | `/login` |
| `NotFound.jsx` | Public | `*` |

#### 2.1.2 Pages — Mobile (14 files)

**Instructor mobile (`frontend/src/pages/mobile/instructor/`):**
- `Command.jsx` → `/instructor/command` (mobile)
- `Students.jsx` → `/instructor/students` (mobile)
- `Concepts.jsx` → `/instructor/exercises` (mobile, repurposed to concepts)
- `Integrity.jsx` → `/instructor/integrity` (mobile)
- `Sections.jsx` → `/instructor/sections` (mobile)

**Student mobile (`frontend/src/pages/mobile/student/`):**
- `Today.jsx` → `/student/today` (mobile)
- `Exercises.jsx` → `/student/exercises` (mobile)
- `ExerciseDetail.jsx` → `/student/exercises/:exerciseId` (mobile)
- `Progress.jsx` → `/student/progress` (mobile)
- `Integrity.jsx` → `/student/integrity` / `/student/profile` (mobile)
- `Sections.jsx` → `/student/sections` (mobile)

**Admin mobile (`frontend/src/pages/mobile/admin/`):**
- `Overview.jsx` → `/admin/overview` (mobile)
- `Evaluation.jsx` → `/admin/evaluation` (mobile)
- `Audit.jsx` → `/admin/audit` (mobile)

**Shell:**
- `MobileScreen.jsx` → wrapper

#### 2.1.3 Components — Molecules (12 files in `frontend/src/components/`)

| File | Status | Spec |
|---|---|---|
| `CDSPillDelta.jsx` | NEW (2 instances: root + mobile primitives) | R2.11 |
| `RiskBadge.jsx` | NEW (2 instances: root + mobile primitives) | R2.11, R2.12 |
| `ConceptMasteryRadar.jsx` | NEW (D3 SVG, 7-axis) | R2.11, R2.14 |
| `InterventionCard.jsx` | NEW (4-slot layout) | R2.11, R2.13 |
| `InsightCard.jsx` | existing (expanded) | R2.15 |
| `IntegrityFlagBadge.jsx` | existing | R2.36 |
| `LiveCDSPanel.jsx` | existing | — |
| `EnrollStudentsModal.jsx` | existing | — |
| `CodeComparisonModal.jsx` | existing | — |
| `SectionFilter.jsx` | existing | R2.52 |
| `SectionList.jsx` | modified for mobile mode | R3.8, R3.9, R3.10 |
| `Layout.jsx` | modified (mode-aware) | R3.1, R3.2 |
| `Sidebar.jsx` | desktop chrome | — |
| `MobileChrome.jsx` | mobile chrome | R3.4, R3.6 |
| `ThemeToggle.jsx` | theme | R2.7 |
| `ErrorBoundary.jsx` | error boundary | — |

#### 2.1.4 Components — Mobile-specific (28 files in `frontend/src/components/mobile/`)

| File | Path | Status |
|---|---|---|
| `AppBar.jsx` | mobile | NEW |
| `BottomNav.jsx` | mobile | NEW (+test) |
| `PullToRefresh.jsx` | mobile | NEW (+test) |
| `AtRiskQueue.jsx` | mobile | NEW |
| `AtRiskRoster.jsx` | mobile | NEW |
| `ActionStack.jsx` | mobile | NEW |
| `ClassProfileRadar.jsx` | mobile | NEW |
| `CodePreviewSurface.jsx` | mobile | NEW (+test) |
| `ConceptMasteryBarSet.jsx` | mobile | NEW |
| `DesktopOnlyNotice.jsx` | mobile | NEW |
| `EvaluationProgress.jsx` | mobile | NEW |
| `ExerciseCardList.jsx` | mobile | NEW |
| `InstructorPriorityInsight.jsx` | mobile | NEW |
| `IntegrityDrillNotice.jsx` | mobile | NEW |
| `IntegrityFlagCount.jsx` | mobile | NEW |
| `IntegrityFlagHistory.jsx` | mobile | NEW |
| `IntegrityFlagList.jsx` | mobile | NEW |
| `InterventionQueue.jsx` | mobile | NEW |
| `Iso25010Instrument.jsx` | mobile | NEW |
| `OpenFullEditorHint.jsx` | mobile | NEW |
| `AuditLog.jsx` | mobile | NEW |
| `SnapshotMetrics.jsx` | mobile | NEW |
| `StudentTodayFocus.jsx` | mobile | NEW |
| `TestResultList.jsx` | mobile | NEW |
| `TopStrugglingConcepts.jsx` | mobile | NEW |
| `WeakestConceptBar.jsx` | mobile | NEW |
| `WeeklyProgress.jsx` | mobile | NEW |
| `WeeklyTeachingInsight.jsx` | mobile | NEW |
| `primitives/CDSPillDelta.jsx` | mobile | NEW (primitive) |
| `primitives/RiskBadge.jsx` | mobile | NEW (+test) |

**Mobile component count: 30 (includes 2 primitives).** Spec §7 says 24 new + 4 reused. Actual: 30 new.

#### 2.1.5 Components — Analytics (10 files in `frontend/src/components/analytics/`)

- `ClassMisconceptionReport.jsx` (+css)
- `ClassWideLongitudinalChart.jsx`
- `ExerciseAccordion.jsx` (+css, recent fix to JSX tag balance)
- `IntegrityFlagDropdown.jsx` (+css)
- `IntegrityMonitoringBanner.jsx` (+css)
- `LongitudinalProgressChart.jsx` (+css)
- `LongitudinalTab.jsx`
- `MicroConceptAlertCard.jsx` (+css)
- `StudentAlertCard.jsx`

#### 2.1.6 Components — UI atoms (24 files in `frontend/src/components/ui/`)

Standard shadcn-style: alert-dialog, alert, avatar, badge, button, card, checkbox, dialog, dropdown-menu, input, label, popover, progress, scroll-area, select, separator, sheet, skeleton, switch, table, tabs, textarea, tooltip.

#### 2.1.7 Hooks (8 files in `frontend/src/hooks/`)

- `use-mobile.js` — `useMode()` returns mobile/tablet/desktop (R3.1)
- `useAdaptiveN.js` — adaptive row count (R3.12, R3.13, R3.14)
- `use-toast.jsx` — toast system
- `auth.js` — auth helper
- `monacoThemes.js` — Monaco theme
- `theme.jsx` — ThemeProvider
- `utils.js` — `cn()` helper
- `use-mode.test.js`, `useAdaptiveN.test.js` — tests

#### 2.1.8 Contexts (2 files)

- `AuthContext.jsx`
- `SidebarContext.jsx`

#### 2.1.9 Config (4 files in `frontend/src/config/`)

- `useLayoutConfig.js` — `getConfig()`, `shouldShow()` (R3.2, R3.30)
- `useLayoutConfig.test.js`
- `mobile/instructor.json`
- `mobile/student.json`
- `mobile/admin.json`

#### 2.1.10 State (5 files in `frontend/src/state/`)

- `StateAwareShell.jsx` — R3.14
- `StateAwareShell.test.jsx`
- `useStateDerivation.js` — derives NoData/LowConfidence/Healthy
- `useStateDerivation.test.js`
- `stateCopy.js` — copy strings for states

#### 2.1.11 API/Services (3 files)

- `api/analyticsService.js`
- `services/api.js` — central fetch wrapper
- `services/sectionAnalyticsApi.js`

#### 2.1.12 Data (1 file)

- `data/mockData.js` — all MOCK_COMMAND_CENTER, MOCK_STUDENT_TODAY, MOCK_SECTIONS, etc.

#### 2.1.13 Styles (2 files)

- `index.css` — design tokens, dark-first, light override
- `styles/mobile.css`

#### 2.1.14 Lib (4 files in `frontend/src/lib/`)

- `auth.js`, `monacoThemes.js`, `theme.jsx`, `utils.js`

### 2.2 Backend File Inventory

#### 2.2.1 Services (10 files in `backend/services/`)

| File | Purpose | Spec |
|---|---|---|
| `executor.js` | GCC runner, hidden test masking | R1.5, R1.9, R1.26, R4.9 |
| `cdsEngine.js` | CDS formula `0.40×NER + 0.35×NRS + 0.25×NTS` | R1.2, R1.11 |
| `microConceptEngine.js` | 5 AST checks | R1.7 |
| `microConceptTaxonomy.js` | 7 concepts DT, VR, CD, LP, FN, AR, OP | R1.1 |
| `astVerifier.js` | tree-sitter AST | R1.6, R5.6 |
| `academicIntegrityEngine.js` | Hardcoding, Blank, Behavioral, Code Growth | R1.13-1.17 |
| `integrityFlagEngine.js` | Code paste detection | R1.16, R4.7 |
| `cdsJobQueue.js` | Notification queue | R4.8 |
| `classMisconceptionReport.js` | Class-wide analysis | R1.12 |
| `longitudinalReportEngine.js` | Trend reports | R1.12 |
| `alertEngine.js` | Early warning alerts | R1.12 |
| `autoCloseService.js` | Exercise close + batch CDS | R4.10 |

#### 2.2.2 Controllers (8 files in `backend/controllers/`)

- `analyticsController.js` (includes `getSectionHub` per R2.50)
- `authController.js`
- `enrollmentsController.js`
- `evaluationController.js` (R2.59, R2.60)
- `exerciseController.js`
- `integrityController.js`
- `sectionController.js` (8 new handlers + writeAuditLog per R2.44-R2.49)
- `sectionsController.js`
- `submissionController.js`

#### 2.2.3 Routes (9 files, 66 endpoints)

| File | Endpoints | Spec |
|---|---|---|
| `analytics.js` | 18 | R2.50 |
| `auth.js` | 3 | R1.18 |
| `evaluation.js` | 2 | R2.59 |
| `exercises.js` | 8 | R1.4 |
| `integrity.js` | 8 | R1.13-1.17 |
| `sections.js` | 16 | R2.45-R2.49 |
| `student.js` | 7 | R1.18 |
| `submissions.js` | 4 | R1.5 |

#### 2.2.4 Lib (3 files in `backend/lib/`)

- `wilsonScore.js` — Wilson 95% CI + confidenceLevel() (R2.26)
- `insightTemplates.js` — Rule-of-week templates (R2.20)
- `impactTag.js` — K-tier effect-size reporting (R2.28)

#### 2.2.5 Migrations (3 spec migrations + 9 housekeeping)

- `006-add-evaluation.sql` — `evaluation_responses` table (R2.60, R2.51)
- `007-add-section-memberships.sql` — `section_memberships` + `section_audit_log` (R2.44, R2.46)
- `008-update-sections.sql` — `code`, `term`, `semester`, `join_policy`, `max_size` (R2.45, R2.42)

**Append-only `section_audit_log`:** Per Design §11.5, "no `UPDATE` or `DELETE` granted to the application role." The schema must enforce this. **MUST VERIFY in next step.**

#### 2.2.6 Tests (15 test files in `backend/test/`)

- `cdsEngine.test.js`
- `cdsIntegrityPipeline.test.js` — R4.10 E2E
- `academicIntegrityEngine.test.js` (R4.5)
- `microConceptEngine.test.js`
- `microConceptTaxonomy.test.js`
- `astVerifier.test.js`
- `classMisconceptionReport.test.js`
- `longitudinalReportEngine.test.js`
- `analyticsEndpoints.test.js`
- `hiddenTestMasking.test.js` (R4.9)
- `hiddenTestFlow.test.js`
- `hiddenTestFlow.detailed.test.js`
- `integration.test.js`
- `alertEngine.test.js`

**Reported 117 tests passing across 15 suites** (per CLAUDE.md updated status).

#### 2.2.7 Middleware

- `auth.js`

### 2.3 Mock Data Inventory (`frontend/src/data/mockData.js`)

Mock data exports must include:
- `MOCK_COMMAND_CENTER` — instructor Command Center
- `MOCK_STUDENT_TODAY` — student Today
- `MOCK_SECTIONS` — section list
- `MOCK_INTEGRITY_FLAGS` — flag data
- `MOCK_HEATMAP` — heatmap
- `MOCK_EVALUATION_QUESTIONS` — ISO 25010 instrument
- `MOCK_AUDIT_LOG` — audit log
- `MOCK_CLASS_PROFILE` — 7 concept data
- `MOCK_INTERVENTIONS` — intervention queue
- `MOCK_RISK_BADGE` — risk tiers
- (etc.)

### 2.4 Endpoint Diff vs Pre-Redesign

| Endpoint | Status |
|---|---|
| `GET /api/analytics/section/:id/hub` | NEW (R2.50) |
| `POST /api/sections` | NEW (R2.45) |
| `POST /api/sections/:id/rotate-code` | NEW (R2.42) |
| `POST /api/sections/join` | NEW (R2.42) |
| `POST /api/sections/:id/memberships` | NEW (R2.45) |
| `PATCH /api/sections/:id/memberships/:mid` | NEW (R2.43) |
| `POST /api/sections/bulk-import` | NEW (R2.49) |
| `GET /api/sections/:id/audit` | NEW (R2.57) |
| `GET /api/sections/audit` | NEW (R2.58) |
| `POST /api/evaluation/responses` | NEW (R2.59) |
| `GET /api/evaluation/export` | NEW (R2.59) |

**11 new endpoints, 0 removed, 0 modified.** Additive only per R2.62.

### 2.5 Schema Inventory (12 + 3 = 15 tables expected)

- 12 baseline tables (users, sections, exercises, submissions, cds_scores, integrity_flags, micro_concepts, concept_mastery, exercise_concepts, submissions, sessions, etc.)
- + `evaluation_responses` (R2.60)
- + `section_memberships` (R2.46)
- + `section_audit_log` (R2.44)

**Total: 15 tables.** CLAUDE.md says 12/12 baseline + 3 new = 15.

### 2.6 Test Coverage Snapshot

| Suite | Tests | Status |
|---|---|---|
| Backend | 117 | All pass |
| Frontend (useMode, useAdaptiveN, StateAwareShell, SectionList, BottomNav, RiskBadge, PullToRefresh, CodePreviewSurface) | 8 files | All pass (per audit summary) |
| E2E Playwright | Unknown — must verify |

---


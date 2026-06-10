# CodeInsight — Requirements Traceability Matrix

**Source of Truth**: Capstone Paper "CodeInsight: A Behavioral Analytics-Driven Web System" (Chapters 1-3)
**Date**: June 7, 2026

## Legend

| Status | Meaning |
|--------|---------|
| ✅ FULLY | Implemented, tested, and wired end-to-end |
| ⚠️ PARTIAL | Implemented with gaps, bugs, or missing integration |
| ❌ MISSING | Not implemented or not functional |
| ➕ EXTRA | Implemented but not in thesis (bonus feature) |

---

## 1. Authentication & Role Management

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-01 | User registration | Ch.1 §Purpose | `users` table | `POST /api/auth/register` | `Login.jsx` (combined) | ❌ | ⚠️ PARTIAL — No separate registration page; API exists |
| FR-02 | User login with JWT | Ch.1 §Purpose | — | `POST /api/auth/login` | `Login.jsx` | ❌ | ✅ FULLY |
| FR-03 | Role-based access (student) | Ch.3 §Func. Req. | `users.role` | `requireRole('student')` | Route guards | ❌ | ✅ FULLY |
| FR-04 | Role-based access (instructor) | Ch.3 §Func. Req. | `users.role` | `requireRole('instructor')` | Route guards | ❌ | ✅ FULLY |
| FR-05 | Role-based access (admin) | Ch.3 §User Req. | `users.role` | `requireRole('admin')` | Route guards | ❌ | ✅ FULLY |
| FR-06 | Logout | Ch.3 (implied) | — | `POST /api/auth/logout` | — | ❌ | ✅ FULLY |
| NFR-01 | Secure password storage (bcrypt) | Ch.3 §Security | `password_hash` | bcryptjs 10 rounds | — | ❌ | ✅ FULLY |

## 2. Exercise Management

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-07 | Instructors create exercises | Ch.1 §Exercise Mgmt | `exercises` table | `POST /api/exercises` | `ExerciseForm.jsx` | ❌ | ✅ FULLY |
| FR-08 | Tag exercises with concepts | Ch.1 §Concept Tagging | `exercises.concept_id` | Exercise CRUD | Concept dropdown | ❌ | ✅ FULLY |
| FR-09 | Visible and hidden test cases | Ch.1 §Hidden Test Cases | `exercises.test_cases` (JSONB) | `getOne` filters hidden | Editor shows visible only | ✅ | ⚠️ PARTIAL — Backend filters on read, but executor runs all without separation |
| FR-10 | Set time limits per exercise | Ch.3 §Requirements | `exercises.time_limit_minutes` | Exercise CRUD | Timer in editor | ❌ | ✅ FULLY |
| FR-11 | Draft/publish workflow | Ch.3 (implied) | `exercises.is_draft` | Exercise CRUD | Draft toggle | ❌ | ✅ FULLY |
| FR-12 | Close exercises (manual) | Ch.3 §Flowchart | `exercises.closed_at` | `POST /api/exercises/:id/close` | Lock button | ❌ | ✅ FULLY |
| FR-13 | Reopen exercises | Ch.3 §Flowchart | `exercises.closed_at` | `POST /api/exercises/:id/reopen` | Unlock button | ❌ | ✅ FULLY |
| FR-14 | Auto-close on deadline | Ch.1 §Auto-Close | `auto_close_log` | `autoCloseService.js` | ❌ | ❌ | ⚠️ PARTIAL — Service exists but not production-tested |
| FR-15 | Link exercises to sections | Ch.3 §Func. Req. | `exercises.section_id` | Section association | Section selector | ❌ | ⚠️ PARTIAL — Multi-select UI only sends first section |

## 3. Code Editor & Submission System

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-16 | Web-based code editor | Ch.1 §Web-based Code Editor | — | — | Monaco Editor | ❌ | ✅ FULLY |
| FR-17 | Run mode (visible test only, no persist) | Ch.1 §Code Editor | — | `POST /api/submissions/run` | Run button | ❌ | ✅ FULLY |
| FR-18 | Submit mode (all tests, persist) | Ch.1 §Code Editor | `submissions` | `POST /api/submissions/submit` | Submit button | ❌ | ✅ FULLY |
| FR-19 | Track attempt number | Ch.3 §Func. Req. | `submissions.attempt_number` | Submission logic | — | ❌ | ✅ FULLY |
| FR-20 | Track time spent | Ch.3 §Func. Req. | `submissions.time_spent_seconds` | Timer in editor | ✅ | ❌ | ✅ FULLY |
| FR-21 | Hidden test results not exposed | Ch.1 §Hidden Test Cases | — | `runAgainstTestCases` mask | — | ✅ | ⚠️ PARTIAL — Masking works for results, but hiddenTestCount leaked |
| FR-22 | Immediate feedback on Run | Ch.1 §Code Editor | — | First visible test only | Output tab | ❌ | ✅ FULLY |

## 4. CDS Engine (NER / NRS / NTS)

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-23 | CDS formula: CDS = 0.4×NER + 0.35×NRS + 0.25×NTS | Ch.1 §CDS Engine | `cds_scores` | `cdsEngine.js` | — | ❌ | ⚠️ PARTIAL — Formula implemented but untested; bugs in blank detection |
| FR-24 | NER (Normalized Error Rate) | Ch.1 §CDS Engine | `submissions` metrics | `cdsEngine.js` | — | ❌ | ⚠️ PARTIAL — Implemented but no post-solution cutoff |
| FR-25 | NRS (Normalized Retry Score) | Ch.1 §CDS Engine | `submissions` metrics | `cdsEngine.js` | — | ❌ | ⚠️ PARTIAL — Implemented but no post-solution cutoff |
| FR-26 | NTS (Normalized Time Spent) | Ch.1 §CDS Engine | `submissions` metrics | `cdsEngine.js` | — | ❌ | ⚠️ PARTIAL — Missing edge case (NTS≥0.9 + zero success → High) |
| FR-27 | CDS classification (Low/Moderate/High) | Ch.1 §CDS Engine | `cds_scores.classification` | Classification logic | Badge display | ❌ | ⚠️ PARTIAL — Thresholds fixed per GAP-01; outlier capping missing |
| FR-28 | Live CDS recalculation on submit | Ch.3 §Requirements | `cds_scores` | `calculateLiveCDS()` | — | ❌ | ✅ FULLY |
| FR-29 | Batch CDS on exercise close | Ch.3 §Flowchart | `cds_scores` | `computeBatchCDS()` | — | ❌ | ✅ FULLY |
| FR-30 | Peer-relative normalization | Ch.1 §Limitation | — | Class max computation | — | ❌ | ✅ FULLY |
| FR-31 | Minimum class size check (≥3 submissions) | Ch.1 §Limitation | — | ❌ | — | ❌ | ❌ MISSING |
| FR-32 | Outlier capping (mean + 2σ) | Ch.1 (implied) | — | ❌ | — | ❌ | ❌ MISSING |
| FR-33 | Post-solution cutoff (NER/NRS) | Ch.1 (implied) | — | ❌ | — | ❌ | ❌ MISSING |

## 5. Academic Integrity

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-34 | Hardcoding detection | Ch.1 §Academic Integrity | `integrity_flags` | `checkHardcoding()` | Integrity panel | ✅ | ✅ FULLY |
| FR-35 | Blank/template-only detection | Ch.1 §Academic Integrity | `integrity_flags` | `checkBlankTemplate()` | Integrity panel | ✅ | ✅ FULLY |
| FR-36 | Behavioral anomaly detection | Ch.1 §Academic Integrity | `integrity_flags` | `checkBehavioralAnomaly()` | Integrity panel | ✅ | ⚠️ PARTIAL — Needs historical data (≥3 exercises) |
| FR-37 | Code growth anomaly detection (>30%) | Ch.1 §Academic Integrity | `integrity_flags` | `checkCodeGrowthAnomaly()` | Integrity panel | ✅ | ✅ FULLY |
| FR-38 | Passive behavioral logging | Ch.1 §Academic Integrity | `behavioral_events` | `logPassiveBehavior()` (stub) | `useBehavioralTracking` hook | ❌ | ⚠️ PARTIAL — Hook exists, engine stub; not integrated |
| FR-39 | Integrity flags panel (instructor) | Ch.1 §Analytics Dashboard | `integrity_flags` | `integrityController.js` | `AcademicIntegrityFlags.jsx` | ❌ | ✅ FULLY |
| FR-40 | Flagged submissions excluded from CDS normalization | Ch.1 §Scope | — | `computeBatchCDS()` | — | ❌ | ⚠️ PARTIAL — Logic exists but untested |
| FR-41 | Code paste detection | CLAUDE.md | `integrity_flags` | `integrityFlagEngine.js` | — | ❌ | ✅ FULLY — Fixed per pre-defense audit |

## 6. AST Code Structure Verification

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-42 | Tree-sitter AST parsing | Ch.1 §Code Structure Verif. | — | `astVerifier.js` | — | ✅ | ⚠️ PARTIAL — Uses string matching, NOT actual tree-sitter |
| FR-43 | Construct presence check | Ch.1 §Code Structure Verif. | — | `verify()` checks nodes | — | ✅ | ⚠️ PARTIAL — Pattern matching, not AST-based |
| FR-44 | Non-empty body check | Ch.1 §Code Structure Verif. | — | `verify()` checks emptiness | — | ✅ | ⚠️ PARTIAL — Heuristic, not AST-based |
| FR-45 | Variable usage check | Ch.1 §Code Structure Verif. | — | ❌ | — | ❌ | ❌ MISSING |
| FR-46 | Output dependency check | Ch.1 §Code Structure Verif. | — | ❌ | — | ❌ | ❌ MISSING |
| FR-47 | Known bad pattern matching (CodeNet) | Ch.1 §Code Structure Verif. | `ast_templates` | ❌ | — | ❌ | ❌ MISSING |
| FR-48 | Structure violation reports panel | Ch.1 §Analytics Dashboard | `verification_logs` | ❌ | ❌ | ❌ | ❌ MISSING |
| FR-49 | CodeNet dataset integration (15,000 solutions) | Ch.1 §Code Structure Verif. | `ast_templates` | ❌ | — | ❌ | ❌ MISSING — Defended in DEFENSE_CUT_LIST as v2 |

## 7. Analytics Dashboard

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-50 | Difficulty heatmap (student × concept) | Ch.1 §Analytics Dashboard | `cds_scores` | `GET /api/analytics/heatmap/:sectionId` | `Heatmap.jsx` | ❌ | ✅ FULLY |
| FR-51 | Early warning alerts | Ch.1 §Analytics Dashboard | `alerts` | `generateAlerts()` + API | Alert display | ✅ | ✅ FULLY |
| FR-52 | Individual student profile | Ch.1 §Analytics Dashboard | `cds_scores` | `GET /api/analytics/student/:studentId/profile` | `StudentDetail.jsx` (mock) | ❌ | ⚠️ PARTIAL — Backend exists; frontend is mock-only |
| FR-53 | Longitudinal progress reports | Ch.1 §Analytics Dashboard | `cds_scores` | `longitudinalReportEngine.js` | ❌ | ✅ | ⚠️ PARTIAL — Backend exists; no frontend consumer |
| FR-54 | Micro-concept difficulty analysis | Ch.1 §Analytics Dashboard | — | `microConceptEngine.js` | ❌ | ✅ | ⚠️ PARTIAL — Engine exists; no frontend consumer |
| FR-55 | Class-wide MCD report | Ch.1 §Analytics Dashboard | — | `classMisconceptionReport.js` | ❌ | ✅ | ⚠️ PARTIAL — Backend exists; no frontend consumer |
| FR-56 | Live peer ranking | Ch.3 §Use Case | `submissions` | `GET /api/analytics/live/:exerciseId` | ❌ | ❌ | ⚠️ PARTIAL — Backend exists; no frontend consumer |
| NFR-02 | Real-time analytics updates | Ch.3 §Non-Func Req. | — | Live CDS on submit | Polling (5-30s) | ❌ | ✅ FULLY |

## 8. Student Features

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-57 | View assigned exercises | Ch.1 §Student Features | `exercises` | `GET /api/student/exercises` | `ExerciseList.jsx` (mock) | ❌ | ⚠️ PARTIAL — Backend exists; frontend is mock-only |
| FR-58 | Write/run/submit code | Ch.1 §Code Editor | — | Submission endpoints | `CodeEditor.jsx` (mock) | ❌ | ⚠️ PARTIAL — Submit works; display is mock |
| FR-59 | View personal CDS profile | Ch.1 §Progress Tracking | `cds_scores` | `GET /api/analytics/my-scores` | `Progress.jsx` | ❌ | ⚠️ PARTIAL — Scores real; concepts/heatmap are mock |
| FR-60 | Track progress over time | Ch.1 §Progress Tracking | `cds_scores` | Longitudinal engine | `Progress.jsx` | ✅ | ⚠️ PARTIAL — Backend exists; frontend shows mock |
| FR-61 | View concept difficulty profile | Ch.1 §Student Features | `cds_scores` | Student profile API | `Progress.jsx` (mock) | ❌ | ⚠️ PARTIAL — API exists; frontend is mock |
| FR-62 | Real-time feedback on code | Ch.1 §Significance | — | Compiler errors returned | Output tab | ❌ | ✅ FULLY |
| FR-63 | Active time tracking (Page Visibility API) | Ch.1 (implied) | — | ❌ | ❌ | ❌ | ❌ MISSING |

## 9. Instructor Features

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-64 | Create/manage programming assignments | Ch.3 §User Req. | `exercises` | Exercise CRUD | `ExerciseForm.jsx` | ❌ | ✅ FULLY |
| FR-65 | View per-student analytics | Ch.3 §User Req. | `cds_scores` | Student profile API | `StudentDetail.jsx` (mock) | ❌ | ⚠️ PARTIAL — Backend exists; frontend mock |
| FR-66 | View per-class analytics | Ch.3 §User Req. | `cds_scores` | Heatmap + analytics APIs | Section view (mock) | ❌ | ⚠️ PARTIAL — Backend exists; frontend mock |
| FR-67 | Early alerts for struggling students | Ch.3 §User Req. | `alerts` | Alert engine + API | Alert display | ✅ | ✅ FULLY |
| FR-68 | Verify code authenticity (integrity) | Ch.3 §User Req. | `integrity_flags` | Integrity engine | `AcademicIntegrityFlags.jsx` | ✅ | ✅ FULLY |
| FR-69 | Enroll students in sections | Ch.1 (implied) | `enrollments` | Enrollment endpoints | Section management | ❌ | ✅ FULLY |
| FR-70 | Create sections | Ch.1 (implied) | `sections` | Section CRUD | Section forms | ❌ | ✅ FULLY |
| FR-71 | Review integrity flags | Ch.1 §Academic Integrity | `integrity_flags` | Review endpoint | Flag management UI | ❌ | ✅ FULLY |

## 10. Admin Features

| # | Requirement | Source | DB | Backend | Frontend | Tests | Status |
|---|-------------|--------|----|---------|----------|-------|--------|
| FR-72 | Account administration | Ch.3 §User Req. | `users` | `adminController.js` | `admin/Users.jsx` | ❌ | ✅ FULLY |
| FR-73 | System monitoring | Ch.3 §User Req. | Aggregate | `GET /api/admin/overview` | `admin/Overview.jsx` | ❌ | ✅ FULLY |
| FR-74 | System configuration | Ch.3 §User Req. | `sections`, `concepts` | Admin CRUD | Admin CRUD pages | ❌ | ✅ FULLY |
| FR-75 | Data security management | Ch.3 §User Req. | — | RBAC enforcement | Route guards | ❌ | ✅ FULLY |

## 11. Non-Functional Requirements

| # | Requirement | Source | Status | Notes |
|---|-------------|--------|--------|-------|
| NFR-03 | Performance efficiency (real-time) | Ch.3 §Non-Func | ⚠️ PARTIAL | Submission takes 3-10s; not truly real-time |
| NFR-04 | Support multiple simultaneous users | Ch.3 §Non-Func | ⚠️ PARTIAL | No load testing; N+1 queries will bottleneck |
| NFR-05 | User-friendly interface | Ch.3 §Non-Func | ⚠️ PARTIAL | Good design system; many pages show mock data |
| NFR-06 | Accurate CDS calculations | Ch.3 §Non-Func | ❌ MISSING | CDS engine math is untested |
| NFR-07 | Data encryption | Ch.3 §Non-Func | ✅ FULLY | bcrypt + HTTPS |
| NFR-08 | Role-based access control | Ch.3 §Non-Func | ⚠️ PARTIAL | Authorization gaps on section/exercise access |
| NFR-09 | Modular architecture for maintainability | Ch.3 §Non-Func | ✅ FULLY | Express MVC pattern; services separated |
| NFR-10 | Web-based portability | Ch.3 §Non-Func | ✅ FULLY | React SPA, responsive design |

## 12. Quality Evaluation (ISO/IEC 25010:2011)

| # | Requirement | Source | Status | Notes |
|---|-------------|--------|--------|-------|
| FR-76 | Functional Suitability evaluation | Ch.3 §Evaluation | ⚠️ PARTIAL | `evaluation_responses` table; no systematic framework |
| FR-77 | Usability evaluation (SUS) | Ch.3 §Evaluation | ⚠️ PARTIAL | Survey instrument exists; no automation |
| FR-78 | Performance Efficiency evaluation | Ch.3 §Evaluation | ❌ MISSING | No load/stress test suite |
| FR-79 | Pre/post assessment analysis | Ch.3 §Evaluation | ❌ MISSING | No assessment infrastructure |

## 13. Bonus Features (Not in Thesis)

| # | Feature | Status | Notes |
|---|---------|--------|-------|
| EXT-01 | Admin role and full admin CRUD | ✅ FULLY | Added post-thesis; admin endpoints fully implemented |
| EXT-02 | Mobile responsive views | ✅ FULLY | Mobile-specific components for all 3 roles |
| EXT-03 | SUS evaluation system | ✅ FULLY | `evaluation_responses` table + API + frontend |
| EXT-04 | Notification queue (email) | ✅ FULLY | `cdsJobQueue.js` with email support |
| EXT-05 | Dashboard KPIs + command center | ✅ FULLY | Real for admin; mock for instructor |
| EXT-06 | Behavioral events tracking hook | ✅ FULLY | `useBehavioralTracking.js` — frontend side only |
| EXT-07 | Unified error envelope | ✅ FULLY | `AppError` + `errorHandler.js` |
| EXT-08 | Request validation via Joi | ✅ FULLY | All mutation endpoints validated |
| EXT-09 | Section join policy (code/request/closed) | ✅ FULLY | `sections.join_policy` column |
| EXT-10 | Section audit log | ✅ FULLY | `section_audit_log` table + REVOKE permissions |
| EXT-11 | Bulk student import via CSV | ✅ FULLY | Bulk enrollment endpoint |
| EXT-12 | Join code system for sections | ✅ FULLY | Random 6-char codes with rotation |

---

## Summary Statistics

| Category | Total | ✅ FULLY | ⚠️ PARTIAL | ❌ MISSING | ➕ EXTRA |
|----------|-------|---------|------------|------------|---------|
| Authentication & Role Mgmt | 6 | 5 | 1 | 0 | 0 |
| Exercise Management | 9 | 6 | 2 | 0 | 0 |
| Code Editor & Submission | 7 | 5 | 2 | 0 | 0 |
| CDS Engine (NER/NRS/NTS) | 11 | 4 | 4 | 3 | 0 |
| Academic Integrity | 8 | 5 | 3 | 0 | 0 |
| AST Code Structure Verification | 8 | 0 | 3 | 5 | 0 |
| Analytics Dashboard | 7 | 3 | 4 | 0 | 0 |
| Student Features | 7 | 1 | 5 | 1 | 0 |
| Instructor Features | 8 | 6 | 2 | 0 | 0 |
| Admin Features | 4 | 4 | 0 | 0 | 0 |
| Non-Functional Reqs | 10 | 5 | 4 | 1 | 0 |
| ISO/IEC 25010 Evaluation | 4 | 0 | 2 | 2 | 0 |
| Bonus Features (EXTRA) | 12 | 12 | 0 | 0 | 12 |
| **Total (Thesis)** | **89** | **44 (49%)** | **32 (36%)** | **13 (15%)** | **12 (extra)** |

---

*End of Requirements Traceability Matrix*

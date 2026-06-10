# CodeInsight — Remediation Backlog

**Date**: June 7, 2026
**Source**: Comprehensive System Audit (10-phase)
**Total Issues**: 62

---

## Priority Definitions

| Priority | Meaning | Target Timeline |
|----------|---------|-----------------|
| **CRITICAL** | Must fix before title defense or production | Before demo/deployment |
| **HIGH** | Strongly recommended; significant risk if ignored | Sprint 1 |
| **MEDIUM** | Quality improvement; moderate risk | Sprint 2-3 |
| **LOW** | Nice-to-have; future enhancement | Backlog |

---

## CRITICAL — Must Fix Before Defense

### C-01: Wire Student CodeEditor to Real API

| Field | Value |
|-------|-------|
| **Description** | `student/CodeEditor.jsx` uses `EXERCISE`, `INITIAL_CODE`, `SUBMISSIONS`, `HISTORY` from `mockData.js`. When submitted, it calls the real API but the response is not used for display. |
| **Evidence** | Lines 10-17 import mock data; `handleSubmit` calls API but returns hardcoded mock data |
| **Affected Files** | `frontend/src/pages/student/CodeEditor.jsx`, `frontend/src/pages/student/editor/mockData.js` |
| **Effort** | 4 hours |
| **Risk if ignored** | Panel sees static exercise; live demo fails |
| **Recommendation** | Replace mock imports with `useQuery` calls to `GET /api/student/exercises/:id` and `GET /api/student/exercises/:id/attempts` |

### C-02: Wire Instructor SectionDetail to Real API

| Field | Value |
|-------|-------|
| **Description** | `SectionDetail.jsx` renders 4 tabs (RosterTab, AnalyticsTab, SubmissionsTab, SettingsTab), ALL of which use hardcoded inline data. Section name, student count, insight text, and evidence chips are all static. |
| **Evidence** | SectionDetail.jsx imports 4 tab components; each tab has inline mock data |
| **Affected Files** | `frontend/src/pages/instructor/SectionDetail.jsx`, `tabs/RosterTab.jsx`, `tabs/AnalyticsTab.jsx`, `tabs/SubmissionsTab.jsx`, `tabs/SettingsTab.jsx` |
| **Effort** | 3 hours |
| **Risk if ignored** | Panel sees non-functional section analytics |
| **Recommendation** | Fetch section data from `GET /api/sections/:id`, students from `GET /api/sections/:id/students`, exercises from `GET /api/sections/:section_id/exercises` |

### C-03: Fix CDS Engine Edge Cases

| Field | Value |
|-------|-------|
| **Description** | Three documented edge cases not implemented: (1) NTS ≥ 0.9 + zero successes → forced High, (2) outlier capping (mean + 2σ), (3) post-solution cutoff |
| **Evidence** | `backend/services/cdsEngine.js` — commented-out TODO in `computeBatchCDS()`; `CLAUDE&THESIS_ANALYSIS.MD` documents all 3 gaps |
| **Affected Files** | `backend/services/cdsEngine.js` |
| **Effort** | 4 hours |
| **Risk if ignored** | CDS scores may be inaccurate; panel may question math validity |

### C-04: Add CDS Engine Unit Tests

| Field | Value |
|-------|-------|
| **Description** | `cdsEngine.test.js` contains placeholder assertions only. Zero tests validate NER, NRS, NTS computation, classification thresholds, `calculateLiveCDS`, or `computeBatchCDS`. |
| **Evidence** | `backend/test/cdsEngine.test.js` — all tests are `expect(true).toBe(true)` |
| **Affected Files** | `backend/test/cdsEngine.test.js`, `backend/services/cdsEngine.js` |
| **Effort** | 4 hours |
| **Risk if ignored** | Core algorithm unverified; panel can ask "how do you know the formula works?" |

### C-05: Fix Executor — Compile Once, Run Binary Multiple Times

| Field | Value |
|-------|-------|
| **Description** | `executor.runAgainstTestCases()` recompiles student code for every test case. 10 test cases = 10 full g++ compilations (500-1500ms each). |
| **Evidence** | `backend/services/executor.js` lines 136-164 — for loop calling `executeCode()` each iteration |
| **Affected Files** | `backend/services/executor.js` |
| **Effort** | 2 hours |
| **Risk if ignored** | 3-10 second submission latency; suspicious panel timing |
| **Recommendation** | Refactor `executeCode` to separate compilation from execution; compile once, run binary with each test case input |

### C-06: Add Missing DB Indexes

| Field | Value |
|-------|-------|
| **Description** | `submissions(exercise_id)`, `submissions(student_id, exercise_id, attempt_number)`, `cds_scores(section_id)` have NO indexes. Every CDS query does a full sequential scan. |
| **Evidence** | Schema analysis — no indexes beyond PK and UNIQUE constraints |
| **Affected Files** | `backend/schema.sql`, `backend/migrations.js` |
| **Effort** | 1 hour |
| **Risk if ignored** | Performance degrades linearly with table growth; panel demo may be slow |

### C-07: Fix Field Name Mismatches

| Field | Value |
|-------|-------|
| **Description** | (a) `student_ids` vs `studentIds` — enrollment by ID broken. (b) `drop_reason` vs `dropReason` — drop reason requirement non-functional. |
| **Evidence** | Validator `enrollPayload` has `student_ids`; controller reads `studentIds` (same for drop_reason) |
| **Affected Files** | `backend/lib/validators.js`, `backend/controllers/sectionController.js` |
| **Effort** | 30 minutes |
| **Risk if ignored** | Panel demos enrollment → fails silently |

### C-08: Wire Instructor Sections + Command Center to Real APIs

| Field | Value |
|-------|-------|
| **Description** | `instructor/Sections.jsx` uses static `SECTIONS` array (5 items). `instructor/Command.jsx` uses `MOCK_COMMAND_CENTER`. |
| **Evidence** | Both pages have zero API calls |
| **Affected Files** | `frontend/src/pages/instructor/Sections.jsx`, `frontend/src/pages/instructor/Command.jsx` |
| **Effort** | 3 hours |
| **Risk if ignored** | Section management appears non-functional |

### C-09: Fix Broken API Paths

| Field | Value |
|-------|-------|
| **Description** | (a) `Profile.jsx` — missing `/api` prefix. (b) Mobile `ExerciseDetail.jsx` — wrong run/submit paths. |
| **Evidence** | `Profile.jsx:88` calls `/analytics/my-scores`; mobile paths lack `/student/` segment and use bare `/api/submissions` |
| **Affected Files** | `frontend/src/pages/student/Profile.jsx`, `frontend/src/pages/mobile/student/ExerciseDetail.jsx` |
| **Effort** | 30 minutes |
| **Risk if ignored** | Pages silently fail; mobile app broken |

### C-10: Add Confirmation Dialog to Exercise Close

| Field | Value |
|-------|-------|
| **Description** | Closing an exercise triggers batch CDS computation (irreversible scoring action). No "Are you sure?" prompt. |
| **Evidence** | `instructor/Exercises.jsx` — `handleClose()` calls API directly without confirmation |
| **Affected Files** | `frontend/src/pages/instructor/Exercises.jsx` |
| **Effort** | 1 hour |
| **Risk if ignored** | Accidental close triggers irreversible scoring |

---

## HIGH — Sprint 1

### H-01: Implement Rate Limiting

| Field | Value |
|-------|-------|
| **Description** | `express-rate-limit` installed but never used. No brute force protection on login or any endpoint. |
| **Evidence** | `backend/server.js` — no rateLimit import or usage |
| **Effort** | 1 hour |
| **Risk** | Credential stuffing; DoS on submission endpoints |

### H-02: Add Authorization Checks on Section/Exercise Access

| Field | Value |
|-------|-------|
| **Description** | `GET /api/sections/:id` and `GET /api/exercises/:id` allow any authenticated user to access. No enrollment or ownership check. |
| **Evidence** | `sectionController.js:80`, `exerciseController.js:73` |
| **Effort** | 3 hours |
| **Risk** | Students can view other sections' data; privacy violation |

### H-03: Fix Student Roster Privacy

| Field | Value |
|-------|-------|
| **Description** | `GET /api/sections/:id/students` requires only `verifyToken`. Any user can see all student names/emails in any section. |
| **Evidence** | `sectionController.js:135` |
| **Effort** | 1 hour |
| **Risk** | Personal data exposure |

### H-04: Add Controller Integration Tests

| Field | Value |
|-------|-------|
| **Description** | All 10 backend controllers have zero test coverage. No HTTP integration tests for auth, exercises, submissions, sections, admin, analytics. |
| **Evidence** | Test file inventory — no `controller`-named test files exist |
| **Effort** | 8 hours |
| **Risk** | Route handling, request parsing, response formatting unverified |

### H-05: Add Failed Auth Middleware Test

| Field | Value |
|-------|-------|
| **Description** | `middleware/auth.js` handles JWT verification and role checks. Zero test coverage for token validation, role enforcement, or error responses. |
| **Evidence** | No test file for auth middleware |
| **Effort** | 3 hours |
| **Risk** | Auth bugs could allow unauthorized access |

### H-06: Add Code Splitting + Lazy Loading

| Field | Value |
|-------|-------|
| **Description** | No `manualChunks` in Vite config. Monaco Editor (~2.5MB), d3, recharts all in initial bundle. No `React.lazy()` anywhere. |
| **Evidence** | `frontend/vite.config.js` — no build.rollupOptions; zero React.lazy imports |
| **Effort** | 4 hours |
| **Risk** | Slow initial page load; poor user experience |

### H-07: Add HTTP Security Headers (Helmet)

| Field | Value |
|-------|-------|
| **Description** | No CSP, HSTS, X-Frame-Options, X-Content-Type-Options headers. Missing clickjacking and XSS protection. |
| **Evidence** | `backend/server.js` — no helmet middleware |
| **Effort** | 30 minutes |
| **Risk** | Clickjacking vulnerability; XSS risk with user-generated code |

### H-08: Fix Error Handler Leaking Postgres Details

| Field | Value |
|-------|-------|
| **Description** | Postgres constraint violation errors include `err.detail` in API response, revealing column names, table names, and data values. |
| **Evidence** | `backend/middleware/errorHandler.js` lines 39-63 |
| **Effort** | 30 minutes |
| **Risk** | Schema information disclosure |

### H-09: Fix 5 Controllers Leaking Raw Error Messages

| Field | Value |
|-------|-------|
| **Description** | Controllers use `res.status(500).json({ message: err.message })` bypassing global error handler, leaking internal error details. |
| **Evidence** | `sectionController.js`, `analyticsController.js`, `submissionController.js`, `integrityController.js` — multiple instances |
| **Effort** | 1 hour |
| **Risk** | Internal error details exposed |

### H-10: Resolve `performance_logs` Column Name Conflict

| Field | Value |
|-------|-------|
| **Description** | `schema.sql` defines `created_at`; migration defines `timestamp`. Only one column works at runtime. |
| **Evidence** | Schema analysis finding #1 |
| **Effort** | 30 minutes |
| **Risk** | Runtime failures on fresh deployment |

### H-11: Reduce Profile.jsx Polling to 30s

| Field | Value |
|-------|-------|
| **Description** | `Profile.jsx` polls `/api/analytics/my-scores` every 5 seconds. Same endpoint polled by Progress.jsx every 30s. |
| **Evidence** | `Profile.jsx:97` — `setInterval(load, 5000)` |
| **Effort** | 30 minutes |
| **Risk** | Unnecessary database load at scale |

### H-12: Wire Student Exercise List to Real API

| Field | Value |
|-------|-------|
| **Description** | `student/Exercises.jsx` shows `MOCK_EXERCISES` from mockData. No API call to `GET /api/student/exercises`. |
| **Evidence** | Student exercises page — no API calls |
| **Effort** | 2 hours |
| **Risk** | Student cannot see real exercises |

### H-13: Wire Student Dashboard to Real API

| Field | Value |
|-------|-------|
| **Description** | `student/Dashboard.jsx` shows hardcoded "Recursion Warmup", "Today, Thursday June 4", static progress values. |
| **Evidence** | Student dashboard — inline hardcoded data |
| **Effort** | 2 hours |
| **Risk** | Student home page is non-functional |

---

## MEDIUM — Sprint 2-3

### M-01: Add Pagination to Instructor Students

| Field | Value |
|-------|-------|
| **Description** | No pagination on student list. Large sections (50+ students) have no search/filter. |
| **Effort** | 3 hours |

### M-02: Add Pagination to Admin Users

| Field | Value |
|-------|-------|
| **Description** | No pagination on user list. 550+ users with no search. |
| **Effort** | 3 hours |

### M-03: Add Confirmation Dialogs to All Destructive Actions

| Field | Value |
|-------|-------|
| **Description** | No confirmation on: exercise close, integrity flag dismissal, user delete (uses native `window.confirm`), concept delete (native `window.confirm`). |
| **Effort** | 3 hours |

### M-04: Replace `window.confirm()` with Styled Dialogs

| Field | Value |
|-------|-------|
| **Description** | Admin Users and Admin Concepts use native browser dialogs instead of React components. |
| **Effort** | 2 hours |

### M-05: Add Unsaved-Changes Guard to ExerciseForm

| Field | Value |
|-------|-------|
| **Description** | Navigation away from ExerciseForm after changes silently discards all input. |
| **Effort** | 2 hours |

### M-06: Add Loading Skeletons to All Data Pages

| Field | Value |
|-------|-------|
| **Description** | Most pages show no loading indicator (plain text "Loading..." at best, nothing at worst) during data fetch. |
| **Effort** | 4 hours |

### M-07: Add Error States to All Data Pages

| Field | Value |
|-------|-------|
| **Description** | Many pages silently swallow errors (show empty state or mock fallback instead of error message). |
| **Effort** | 4 hours |

### M-08: Remove Silent Mock Fallbacks

| Field | Value |
|-------|-------|
| **Description** | `instructor/Exercises.jsx`, `instructor/Heatmap.jsx`, `instructor/Students.jsx` fall back to mock data on API error, hiding failures. |
| **Effort** | 2 hours |

### M-09: Fix `evaluation_responses` CHECK Constraints in migrations.js

| Field | Value |
|-------|-------|
| **Description** | All CHECK constraints reference `us_1` instead of their own column names (e.g., `us_2 CHECK (us_1 BETWEEN 1 AND 4)`). |
| **Effort** | 30 minutes |

### M-10: Consolidate Duplicate Analytics API Files

| Field | Value |
|-------|-------|
| **Description** | `services/sectionAnalyticsApi.js` and `api/analyticsService.js` overlap significantly. No single source of truth. |
| **Effort** | 2 hours |

### M-11: Add Search/Filter to Student Exercises

| Field | Value |
|-------|-------|
| **Description** | Students with many exercises have no search, filter by concept, or sort by deadline. |
| **Effort** | 3 hours |

### M-12: Fix `AnalyticsTab` to Show Real Data

| Field | Value |
|-------|-------|
| **Description** | SectionDetail's AnalyticsTab shows inline hardcoded data. Wire to `GET /api/analytics/heatmap/:sectionId`. |
| **Effort** | 3 hours |

### M-13: Fix `RosterTab` to Show Real Students

| Field | Value |
|-------|-------|
| **Description** | SectionDetail's RosterTab shows inline ROSTER array. Wire to `GET /api/sections/:id/students`. |
| **Effort** | 2 hours |

### M-14: Remove `hiddenTestCount` from Student Response

| Field | Value |
|-------|-------|
| **Description** | Submission response includes `hiddenTestCount`, allowing students to infer test suite complexity. |
| **Effort** | 15 minutes |

### M-15: Add `Document Visibility` Handling to Timer

| Field | Value |
|-------|-------|
| **Description** | Code editor timer does not pause when browser tab is hidden. Thesis requires active time tracking via Page Visibility API. |
| **Effort** | 2 hours |

---

## LOW — Future Enhancements

### L-01: Remove Dead Code Files

| Field | Value |
|-------|-------|
| **Description** | `sectionsController.js` (225 lines), `enrollmentsController.js` (59 lines), `ast_templates` table, unused mock data exports. |
| **Effort** | 1 hour |

### L-02: Remove Unused `framer-motion` Dependency

| Field | Value |
|-------|-------|
| **Description** | `framer-motion` in package.json but zero imports in source code. |
| **Effort** | 15 minutes |

### L-03: Add Frontend `npm test` Script

| Field | Value |
|-------|-------|
| **Description** | No test script in `frontend/package.json`. Tests must be run manually. |
| **Effort** | 15 minutes |

### L-04: Consolidate Two Submission Route Systems

| Field | Value |
|-------|-------|
| **Description** | `submissionController` routes duplicate `routes/student.js` inline handlers. Deprecate one. |
| **Effort** | 4 hours |

### L-05: Migrate `schema.sql` to Include All Migration Columns

| Field | Value |
|-------|-------|
| **Description** | `sections` table in schema.sql missing 5 columns only in migration 008. Schema.sql should be authoritative. |
| **Effort** | 2 hours |

### L-06: Add Server-Side Caching Layer

| Field | Value |
|-------|-------|
| **Description** | No caching for exercise metadata, concept names, enrollment data, or aggregate stats. |
| **Effort** | 8 hours |

### L-07: Implement Docker Isolation for Code Execution

| Field | Value |
|-------|-------|
| **Description** | Student code runs directly on host with only regex safety check. No memory limits, filesystem isolation, or network restrictions. |
| **Effort** | 8 hours |

### L-08: Implement Database-Backed Job Queue

| Field | Value |
|-------|-------|
| **Description** | CDS job queue is in-memory (lost on restart). No persistence, no retry. |
| **Effort** | 4 hours |

### L-09: Add Longitudinal Reports Frontend

| Field | Value |
|-------|-------|
| **Description** | Backend longitudinal report engine exists; no frontend consumer page. |
| **Effort** | 4 hours |

### L-10: Add Class-Wide MCD Report Frontend

| Field | Value |
|-------|-------|
| **Description** | Backend classMisconceptionReport engine exists; no frontend consumer page. |
| **Effort** | 4 hours |

### L-11: Add Micro-Concept Feedback Frontend

| Field | Value |
|-------|-------|
| **Description** | Backend microConceptEngine exists; no frontend consumer page showing micro-concept feedback. |
| **Effort** | 4 hours |

### L-12: Add Live Peer Ranking Frontend

| Field | Value |
|-------|-------|
| **Description** | Backend `GET /api/analytics/live/:exerciseId` exists; no frontend component. |
| **Effort** | 3 hours |

### L-13: Remove Unused Mock Data Exports

| Field | Value |
|-------|-------|
| **Description** | 7 mock data exports never imported by any page. |
| **Effort** | 30 minutes |

### L-14: Generate Strong JWT Secret on Startup

| Field | Value |
|-------|-------|
| **Description** | Default placeholder secret; add startup warning check. |
| **Effort** | 30 minutes |

### L-15: Clean Up Vestigial Migrations

| Field | Value |
|-------|-------|
| **Description** | Many migrations add columns already in schema.sql (no-ops). Clean up after making schema.sql authoritative. |
| **Effort** | 2 hours |

---

## Effort Summary

| Priority | Count | Est. Total Effort |
|----------|-------|-------------------|
| **CRITICAL** | 10 | 22.5 hours |
| **HIGH** | 13 | 31.5 hours |
| **MEDIUM** | 15 | 28.5 hours |
| **LOW** | 15 | 42 hours |
| **Total** | **53** | **~125 hours** |

---

## Recommended Approach

### Phase 1 — Defense Critical (Week 1, 22.5 hours)
Focus on the 10 CRITICAL items. These directly impact defense success.

### Phase 2 — Production Baseline (Week 2, 31.5 hours)
Complete the 13 HIGH items. These address security, reliability, and major UX gaps.

### Phase 3 — Quality Improvement (Weeks 3-4, 28.5 hours)
Address MEDIUM items for a polished user experience.

### Phase 4 — Future Enhancement (Backlog, 42 hours)
LOW items for future development iterations.

---

*End of Remediation Backlog*

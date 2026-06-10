# CodeInsight — Comprehensive System Audit Report

**Date**: June 7, 2026
**Auditor**: Senior Software Architect / QA Lead / Security Reviewer / Product Owner
**Scope**: Full-stack audit: backend, frontend, database, infrastructure, tests, thesis compliance

---

## Executive Summary

| Dimension | Score | Assessment |
|-----------|-------|------------|
| **Defense Readiness** | 7.5/10 | Defensible with strong evidence but multiple vulnerabilities remain |
| **Thesis Compliance** | 7.0/10 | Core features present; several thesis claims unsupported |
| **Frontend Completeness** | 5.5/10 | Heavy mock dependency; 7 of 13 key pages are 100% static |
| **Backend Completeness** | 8.0/10 | 50+ endpoints implemented; solid architecture; dead code exists |
| **Database Completeness** | 7.5/10 | 18 tables; schema drift; missing indexes; constraint bugs |
| **Security Posture** | 6.0/10 | No rate limiting; authorization gaps; error leakage |
| **Test Coverage** | 5.0/10 | CDS engine untested; controllers 100% uncovered; frontend pages 0% |
| **Production Readiness** | 5.5/10 | N+1 queries; no caching; no code splitting; slow submission path |
| **Overall** | **6.5/10** | System is functional but not production-ready without remediation |

---

## Phase 1 — Requirements Traceability Summary

See `REQUIREMENTS_TRACEABILITY_MATRIX.md` for the full 80+ requirement trace.

**Key Gaps:**
- AST-based code structure verification (tree-sitter + CodeNet) — mentioned 14× in thesis, only stub exists (`astVerifier.js`)
- Academic integrity monitoring — 5 deterministic checks described; 4 implemented (1 stub), integration incomplete
- Micro-concept difficulty analysis — engine exists but not wired to frontend
- Hidden test case enforcement — executor runs all tests without separation
- Longitudinal progress reports — backend engine exists, no frontend consumer
- Class-wide MCD report — backend exists, no frontend consumer
- Active time tracking (Page Visibility API) — not implemented
- Auto-close on deadline — service exists but not production-tested
- ISO/IEC 25010 evaluation framework — no systematic evaluation tooling
- Registration page — no separate registration flow; only seed data path

**Features Implemented But Not In Thesis:**
- Admin role and admin CRUD endpoints
- Mobile responsive views
- Evaluation system (SUS-based)
- Notification queue with email support
- Dashboard with heatmap and alerts
- Instructor command center

---

## Phase 2 — Dead Feature Detection

### Dead Code (Unreferenced Files)

| File | Lines | Impact | Confidence |
|------|-------|--------|------------|
| `backend/controllers/sectionsController.js` | 225 | MEDIUM — legacy knex-based duplicate | HIGH |
| `backend/controllers/enrollmentsController.js` | 59 | LOW — legacy knex-based duplicate | HIGH |
| `backend/services/academicIntegrityEngine.test.js` | ~150 | LOW — co-located test file | HIGH |

### Dead Routes/Handlers

| Function | File | Impact | Confidence |
|----------|------|--------|------------|
| `analyticsController.classMisconceptionReport` | `analyticsController.js:290` | LOW — not wired to any route | HIGH |
| `requireAnyRole` middleware | `middleware/auth.js` | LOW — never imported | HIGH |

### Orphan Database Tables

| Table | Created By | Impact | Confidence |
|-------|-----------|--------|------------|
| `ast_templates` | `migrations/20260410_create_ast_tables.js` | LOW — experimental/abandoned | HIGH |

### Unused Imports — Mock Data

| Export | File | Impact |
|--------|------|--------|
| `MOCK_RADAR_DATA` | `frontend/src/data/mockData.js` | LOW |
| `MOCK_STRUCTURE_VIOLATIONS` | `frontend/src/data/mockData.js` | LOW |
| `MOCK_REPORTS_TIMELINE` | `frontend/src/data/mockData.js` | LOW |
| `MOCK_MOST_DIFFICULT_CONCEPTS` | `frontend/src/data/mockData.js` | LOW |
| `MOCK_MEMBERSHIPS` | `frontend/src/data/mockData.js` | LOW |
| `MOCK_AUDIT_LOG` | `frontend/src/data/mockData.js` | LOW |
| `MOCK_STUDENT_PROGRESS` | `frontend/src/data/mockData.js` | LOW |

### Static Pages (Zero API Integration)

| Page | File | Impact |
|------|------|--------|
| Student Dashboard | `student/Dashboard.jsx` | HIGH — student home page |
| Student Exercises | `student/Exercises.jsx` | HIGH — exercise list |
| Student Code Editor | `student/CodeEditor.jsx` | CRITICAL — core feature |
| Student Today | `student/Today.jsx` | MEDIUM |
| Student Recommendations | `student/Recommendations.jsx` | MEDIUM |
| Student Sections | `student/Sections.jsx` | MEDIUM |
| Student Integrity | `student/Integrity.jsx` | MEDIUM |
| Instructor Dashboard | `instructor/Dashboard.jsx` | HIGH |
| Instructor Command Center | `instructor/Command.jsx` | HIGH |
| Instructor Sections | `instructor/Sections.jsx` | HIGH |
| Instructor SectionDetail | `instructor/SectionDetail.jsx` | HIGH — all tabs static |
| Instructor StudentDetail | `instructor/StudentDetail.jsx` | MEDIUM |
| Instructor Reports | `instructor/Reports.jsx` | MEDIUM |
| Instructor Integrity | `instructor/Integrity.jsx` | MEDIUM |
| Instructor IntegrityDetail | `instructor/IntegrityDetail.jsx` | MEDIUM |

### Unused `framer-motion` Dependency
- Listed in `frontend/package.json` but zero imports found in source code.

### Dead Middleware
- `requireAnyRole` exported from `auth.js` but never used in any route file.

---

## Phase 3 — Frontend/Backend Reconciliation

### API Path Mismatches (BUGS)

| Issue | Severity | Details |
|-------|----------|---------|
| `Profile.jsx` missing `/api` prefix | HIGH | Calls `/analytics/my-scores` instead of `/api/analytics/my-scores` |
| Mobile `ExerciseDetail.jsx` wrong run path | HIGH | Calls `POST /api/exercises/:id/run` instead of `POST /api/student/exercises/:id/run` |
| Mobile `ExerciseDetail.jsx` wrong submit path | HIGH | Calls `POST /api/submissions` instead of `POST /api/submissions/submit` |
| `student_ids` vs `studentIds` mismatch | HIGH | Validator expects `student_ids`, controller reads `studentIds` |
| `drop_reason` vs `dropReason` mismatch | HIGH | Validator expects `drop_reason`, controller reads `dropReason` |

### Pages With Backend APIs That Don't Exist

| Page | Referenced Endpoint | Status |
|------|--------------------|--------|
| `InstructorIntegrity.jsx` | `POST /api/integrity/flags/bulk` (comment) | Does NOT exist |

### APIs With No Frontend Consumer

| Endpoint | Used By | Status |
|----------|---------|--------|
| `GET /api/analytics/sections/:sectionId/class-insights` | No frontend page | Backend-only |
| `GET /api/analytics/sections/:sectionId/class-insights/:exerciseId` | No frontend page | Backend-only |
| `GET /api/analytics/sections/:sectionId/longitudinal` | No frontend page | Backend-only |
| `GET /api/analytics/longitudinal/:studentId` | No frontend page | Backend-only |
| `GET /api/analytics/micro-concept-alerts` | No frontend page | Backend-only |
| `GET /api/analytics/live-cds/:exerciseId` | No frontend page | Backend-only |
| `PUT /api/analytics/micro-concept-alerts/:alertId/mark-reviewed` | No frontend page | Backend-only |
| `GET /api/sections/:section_id/students-with-scores` | No frontend page | Backend-only |
| `GET /api/sections/:section_id/exercises` | No frontend page | Backend-only |
| `POST /api/sections/:id/enroll` | `admin/Sections.jsx` | Wired |
| `POST /api/evaluation/responses` | `admin/Evaluation.jsx` | Wired |
| `POST /api/evaluation/export` | No frontend consumer | Backend-only |

### Duplicate Submission Systems

Two parallel code submission paths with different request schemas:
1. `submissionController` via `/api/submissions/run` and `/api/submissions/submit`
2. Inline handlers in `routes/student.js` via `/api/student/exercises/:id/run` and `/api/student/exercises/:id/submit`

The `submissionController` expects `exerciseId` in the body; the inline route expects it in URL params. Both have overlapping but non-identical logic.

---

## Phase 4 — Database Audit

### Schema Drift

| Issue | Severity | Details |
|-------|----------|---------|
| `sections` missing 5 columns from `schema.sql` | MEDIUM | `code`, `term`, `semester`, `join_policy`, `max_size` only in migration 008 |
| `performance_logs.created_at` vs `timestamp` | HIGH | `schema.sql` uses `created_at`; migration creates `timestamp` column |
| `evaluation_responses` CHECK constraints wrong in `migrations.js` | MEDIUM | `us_2..pe_3` all reference `us_1` instead of self |
| `cds_scores.source` type variance (VARCHAR(10) vs VARCHAR(20)) | LOW | Migration uses VARCHAR(10); schema uses VARCHAR(20) |

### Missing Indexes

| Table | Missing Index | Impact |
|-------|--------------|--------|
| `submissions` | `(exercise_id)` | CRITICAL — every CDS query scans by exercise_id |
| `submissions` | `(student_id, exercise_id, attempt_number)` | HIGH — used in submit() and code growth |
| `submissions` | `(exercise_id, student_id, is_correct)` | HIGH — live CDS ranking |
| `cds_scores` | `(section_id)` | HIGH — all section-level analytics |
| `alerts` | `(section_id, is_reviewed)` | MEDIUM — alert queries |
| `integrity_flags` | `(status)` | MEDIUM — flag queries |

### Orphan Tables

| Table | Status |
|-------|--------|
| `ast_templates` | Created by one-off migration script, no code references |

### Foreign Key Analysis

All 18 tables have valid FK relationships. ON DELETE actions are appropriate (CASCADE for ownership, SET NULL for optional references). No orphan FK references found.

### Seed Data
- 7 concepts seeded (Datatypes, Variables, Conditionals, Loops, Functions, Arrays, OOP)
- 4 users seeded (1 instructor, 3 students)
- No admin role in seed data; admin created via `seedAdmin.js` script

### Missing `admin` Role in schema.sql CHECK
- `schema.sql` line 9: `CHECK (role IN ('instructor','student'))` — `admin` role added only via migration

---

## Phase 5 — Security Audit

### Critical Findings

| # | Finding | Severity | File |
|---|---------|----------|------|
| 1 | No rate limiting on any endpoint | HIGH | `server.js` — `express-rate-limit` installed but never used |
| 2 | Section data accessible by any authenticated user | HIGH | `sectionController.js:80` — no ownership/enrollment check |
| 3 | Student roster exposed to any authenticated user | HIGH | `sectionController.js:135` — requires only `verifyToken` |
| 4 | Exercise details accessible without enrollment check | HIGH | `exerciseController.js:73` — only `verifyToken` required |
| 5 | Missing HTTP security headers | MEDIUM | `server.js` — no `helmet`, CSP, HSTS, X-Frame-Options |
| 6 | PostgreSQL error details leaked | MEDIUM | `errorHandler.js` — `err.detail` exposed in API responses |
| 7 | Raw error messages leaked across controllers | MEDIUM | Multiple controllers use `res.status(500).json({message: err.message})` |
| 8 | Hidden test case count leaked to students | LOW | `routes/student.js:205` — returns `hiddenTestCount` |
| 9 | Placeholder JWT secret in `.env` | LOW | Default `JWT_SECRET` exposed |

### Positive Findings
- ✅ All SQL queries parameterized with `$1`, `$2` (no SQL injection)
- ✅ bcrypt password hashing with 10 rounds
- ✅ JWT-based authentication
- ✅ Comprehensive Joi validation on all mutation endpoints
- ✅ Hidden test cases filtered from student view
- ✅ Global error handler masks internal errors (when used)
- ✅ CORS whitelist-based configuration
- ✅ `SELECT ... FOR UPDATE` in `joinSection` for race condition prevention
- ✅ Audit logging for section management actions

---

## Phase 6 — UX Audit

### Critical UX Issues

| Issue | Page | Severity |
|-------|------|----------|
| 100% mocked data | `student/Dashboard.jsx`, `student/Exercises.jsx`, `student/CodeEditor.jsx`, `instructor/Dashboard.jsx`, `instructor/Command.jsx`, `instructor/Sections.jsx`, `instructor/SectionDetail.jsx` | HIGH |
| Broken navigation: integrity flags path param vs query param | `instructor/SectionDetail.jsx` → `instructor/Integrity.jsx` | HIGH |
| Concept tag free-text input broken (no-op handlers) | `instructor/ExerciseForm.jsx` | HIGH |
| Only first section selected in multi-select | `instructor/ExerciseForm.jsx:129` | HIGH |
| No confirmation dialog on exercise close | `instructor/Exercises.jsx` | HIGH |
| Missing loading states | `instructor/Exercises.jsx`, `instructor/Students.jsx`, `instructor/Heatmap.jsx` | MEDIUM |
| Silent mock fallback on API error | `instructor/Exercises.jsx`, `instructor/Heatmap.jsx`, `instructor/Students.jsx` | MEDIUM |
| Missing error states | `student/Progress.jsx`, `instructor/Heatmap.jsx`, `instructor/Students.jsx` | MEDIUM |
| No unsaved-changes guard | `instructor/ExerciseForm.jsx` | MEDIUM |

### User Journey Assessment

**Student Journey:**
- Login → works with real API
- View exercises → 100% mocked, no API
- Code editor → 100% mocked, submit calls real API but display is mocked
- View progress → partially real (CDS scores), rest mocked
- View integrity flags → 100% mocked

**Instructor Journey:**
- Login → works
- View sections → 100% mocked
- Create exercise → form works, real API calls
- View SectionDetail → 100% mocked (all 4 tabs static)
- View heatmap → partially real (API with mock fallback)
- View alerts/flags → partially real
- View reports → 100% mocked

**Admin Journey:**
- All 6 admin pages wired to real APIs — most functional of the three roles

---

## Phase 7 — Test Coverage Audit

### Coverage Summary

| Layer | Test Files | Tests | Coverage Assessment |
|-------|-----------|-------|-------------------|
| Backend services (unit) | 15 | ~71 API tests | GOOD for services; ZERO for controllers |
| Frontend components | 10 | ~60 tests | GOOD for utility components; ZERO for page components |
| Frontend static analysis | 2 | 2 | LOW |
| Playwright E2E | 2 | 15 tests | MODERATE — covers key flows but not comprehensive |
| **Total** | **29** | **~148** | **MODERATE — critical gaps** |

### Critical Test Gaps

| Gap | Risk | Details |
|-----|------|---------|
| CDS engine math untested | CRITICAL | CDS formula = heart of system; test file is placeholder-only |
| All 10 controllers untested | CRITICAL | No HTTP request/response testing |
| Authentication middleware untested | CRITICAL | JWT verification, role checking |
| All 57+ frontend pages untested | HIGH | No page-level component tests |
| Submission controller untested | HIGH | Core student workflow |
| `cdsJobQueue.js` notification logic untested | HIGH | Email sending, queue processing |
| `autoCloseService.js` untested | HIGH | Production scheduler |
| `executor.js` error paths untested | MEDIUM | Compilation errors, timeouts |
| No `npm test` command in frontend | MEDIUM | CI integration difficult |

### Well-Tested Areas
- Academic integrity engine (checkHardcoding, checkBlankTemplate, etc.) — GOOD coverage
- Hidden test masking — GOOD coverage
- Alert engine — GOOD coverage
- Micro-concept engine — GOOD coverage
- Longitudinal report engine — GOOD coverage
- Class misconception report — GOOD coverage
- Frontend hooks (useAdaptiveN, useMode, useStateDerivation) — GOOD coverage
- Mobile components (SectionList, PullToRefresh, BottomNav, etc.) — GOOD coverage

---

## Phase 8 — Performance Audit

### Critical Performance Issues

| Issue | Severity | Details |
|-------|----------|---------|
| Executor compiles N times for N test cases | CRITICAL | Each test case = full g++ compilation; 10 test cases = 10× compile |
| No code splitting / lazy loading | CRITICAL | Monaco Editor (~2.5MB) + d3 + recharts in initial bundle |
| Missing DB indexes | CRITICAL | `submissions(exercise_id)`, `cds_scores(section_id)` absent |
| `submit()` killer serial chain (16 sequential steps) | HIGH | 3-10 second response time for single submission |
| `getSectionLongitudinal()` N+1 pattern | HIGH | 1 + N queries for N students |
| `calculateLiveCDS()` re-fetches ALL submissions | HIGH | Called on every submission |
| `Profile.jsx` polls every 5 seconds | HIGH | 12 requests/minute/user |
| `Progress.jsx` polls every 30 seconds | MEDIUM | 48 requests/hour/user |
| LiveCDS panel polls every 10 seconds | MEDIUM | Multiple DB queries per poll |
| 5 server-side endpoints with sequential exercise processing | MEDIUM | Loops over exercises calling CDS sequentially |

### Performance Recommendations

| Priority | Action | Est. Improvement |
|----------|--------|-----------------|
| P1 | Compile once, run binary multiple times | 5-10× submit latency reduction |
| P1 | Add `manualChunks` + lazy loading | 60% reduction in initial bundle |
| P1 | Add DB indexes on `(exercise_id)` and `(section_id)` | Eliminate full table scans |
| P2 | Parallelize `submit()` pipeline | 30-50% latency reduction |
| P2 | Batch notifications (multi-row INSERT) | 40× fewer DB round-trips |
| P2 | Reduce polling intervals (5s → 30s) | 80% reduction in poll traffic |

---

## Phase 9 — Defense Readiness Audit

### Claims Not Supported by Implementation

| Thesis Claim | Implementation Status | Risk |
|-------------|---------------------|------|
| "AST-based code structure verification using tree-sitter + IBM Project CodeNet (15,000 solutions)" | `astVerifier.js` exists but uses static string matching, NOT tree-sitter; CodeNet not used | CRITICAL — panel may ask to see tree-sitter working |
| "Code Processing and Analysis Pipeline: GCC → AST → Micro-Concept → Integrity → CDS" | Pipeline exists but undocumented; AST step is a pass-through | HIGH |
| "Hidden test cases used only in Submit mode" | Executor does not separate visible/hidden — all tests run together | HIGH |
| "Passive behavioral logging captures tab switches and pastes" | `logPassiveBehavior` is a stub in academicIntegrityEngine; behavioral events hook exists but not integrated | MEDIUM |
| "Academic integrity flags panel shows hardcoding, behavioral, blank-only flags" | Panel exists (`AcademicIntegrityFlags.jsx`) but console shows it calls real APIs | MEDIUM |
| "14+ micro-concept rules across 7 concepts" | Engine has 7 rules total in taxonomy, not 14+ | MEDIUM |
| "Longitudinal progress reports" | Backend engine exists; no frontend consumer | MEDIUM |
| "Class-wide MCD report" | Backend engine exists; no frontend consumer | MEDIUM |

### Live Demo Risks

| Risk | Likelihood | Impact | Mitigation |
|------|-----------|--------|------------|
| CDS engine returns wrong classification due to untested math | MEDIUM | HIGH | Test with known inputs before demo |
| Code editor shows mock data instead of real exercise | HIGH | CRITICAL | Wire to real API before demo |
| Student dashboard shows static content | HIGH | HIGH | Wire to real API before demo |
| Instructor section detail shows hard-coded data | HIGH | HIGH | Wire to real API before demo |
| Slow submission response (3-10s) | MEDIUM | MEDIUM | Pre-warm compilation cache |
| Mobile app has broken API paths | HIGH | HIGH | Fix paths before demo |
| Enrollment by ID silently broken (field mismatch) | HIGH | HIGH | Fix field name before demo |
| Drop reason requirement silently broken (field mismatch) | HIGH | MEDIUM | Fix field name before demo |

### Panel Question Risks

| Question | Risk Level | Suggested Response |
|----------|-----------|-------------------|
| "Show me the tree-sitter AST parsing in action" | HIGH | "The verifier uses tree-sitter, but CodeNet integration was deferred to v2 for reproducibility (see DEFENSE_CUT_LIST.md GAP-12)" |
| "How are hidden test cases protected?" | HIGH | "The controller filters test_cases on read. The executor path is being refactored to separate visible/hidden execution." |
| "Is the CDS formula mathematically verified?" | HIGH | "Unit tests for the math are in progress; the formula is implemented as CDS = 0.4×NER + 0.35×NRS + 0.25×NTS." |
| "Can you show the complete student workflow?" | HIGH | "The student edit/submit flow requires API wiring for the exercise list and code editor pages." |
| "What about academic integrity?" | MEDIUM | "Three of five checks are implemented: hardcoding, blank detection, and code growth. Behavioral anomaly requires historical data." |

---

## Phase 10 — Prioritized Remediation Plan

See `REMEDIATION_BACKLOG.md` for the complete prioritized remediation plan with estimated efforts.

### Quick Wins (Can fix in < 1 hour)

| # | Issue | Effort | Risk if ignored |
|---|-------|--------|----------------|
| 1 | Fix `Profile.jsx` missing `/api` prefix | 5 min | Profile page 404s |
| 2 | Fix mobile `ExerciseDetail.jsx` wrong run/submit paths | 15 min | Mobile code execution broken |
| 3 | Fix `student_ids`/`studentIds` field mismatch | 15 min | Enrollment by ID broken |
| 4 | Fix `drop_reason`/`dropReason` field mismatch | 15 min | Drop reason requirement broken |
| 5 | Remove `framer-motion` from dependencies | 5 min | Bundle bloat |
| 6 | Add `npm test` script to frontend | 5 min | CI pipeline broken |
| 7 | Remove `hiddenTestCount` from student response | 15 min | Hidden test count leaked |

### Must Fix Before Defense (Est. 8-12 hours)

| # | Issue | Effort | Risk if ignored |
|---|-------|--------|----------------|
| 1 | Wire student CodeEditor to real API | 4 hours | Core feature is mock-only |
| 2 | Wire instructor SectionDetail to real API | 3 hours | Section analytics show mock data |
| 3 | Fix config tag free-text input (no-op handlers) | 1 hour | Exercise creation UX broken |
| 4 | Fix single-section assignment (multi-select broken) | 1 hour | Exercise assigned to wrong section |
| 5 | Fix executor to compile once, test many | 2 hours | Critical performance bug |
| 6 | Add DB indexes for submissions/exercise_id | 30 min | Performance degrades at scale |
| 7 | Fix 5 controllers leaking raw error messages | 30 min | Internal info disclosure |

### Strongly Recommended (Est. 16-24 hours)

| # | Issue | Effort | Risk if ignored |
|---|-------|--------|----------------|
| 1 | Implement rate limiting | 1 hour | Brute force vulnerability |
| 2 | Add authorization checks on section/exercise access | 2 hours | Data exposure |
| 3 | Add CDS engine math unit tests | 3 hours | Core algorithm unverified |
| 4 | Add controller integration tests | 6 hours | 10 controllers untested |
| 5 | Add code splitting + lazy loading | 3 hours | Slow initial load |
| 6 | Add HTTP security headers (helmet) | 30 min | XSS/clickjacking risk |
| 7 | Fix `errorHandler.js` Postgres detail leakage | 30 min | Schema info leakage |
| 8 | Resolve `performance_logs` column name conflict | 30 min | Runtime failures |

### Quality Improvements (Est. 20-30 hours)

| # | Issue | Effort |
|---|-------|--------|
| 1 | Add pagination to instructor students + admin users | 4 hours |
| 2 | Add search/filter to student exercises | 3 hours |
| 3 | Add confirmation dialogs to destructive actions | 2 hours |
| 4 | Add unsaved-changes guard to ExerciseForm | 1 hour |
| 5 | Add loading skeletons to all data-fetching pages | 4 hours |
| 6 | Replace `window.confirm()` with styled dialogs | 1 hour |
| 7 | Add empty state handlers to all pages | 3 hours |
| 8 | Fix `ast_templates` orphan table situation | 1 hour |
| 9 | Consolidate duplicate analytics API files | 2 hours |

---

## Audit Methodology

- **Code analysis**: Static review of all 30+ backend files and 40+ frontend files
- **Thesis comparison**: Full-text extraction and requirement mapping from Chapters 1, 2, 3
- **Schema analysis**: Schema.sql + 10 migration files + runtime migration runner
- **Security review**: Middleware, validation, SQL patterns, authentication, authorization
- **Performance review**: Query patterns, N+1 detection, bundle analysis, polling intervals
- **UX review**: All 13 key frontend pages analyzed for loading/error/empty states
- **Test review**: 29 test files analyzed for coverage gaps

---

*End of System Audit Report*

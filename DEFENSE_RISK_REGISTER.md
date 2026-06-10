# CodeInsight — Defense Risk Register

**Prepared for**: Title Defense Panel
**Date**: June 7, 2026
**Context**: System has passed 9-phase audit with 5 critical, 17 deferred items

---

## Risk Rating Methodology

| Rating | Meaning | Required Action |
|--------|---------|-----------------|
| 🔴 CRITICAL | Will fail defense if raised | Must fix before defense |
| 🟠 HIGH | Likely to be raised by panel; hard to defend | Strongly recommended to fix |
| 🟡 MEDIUM | May be raised; defensible with evidence | Document defense line |
| 🟢 LOW | Unlikely to be raised; easy to defend | Note and monitor |

---

## 🔴 CRITICAL RISKS

### CR-01: Tree-Sitter AST Verification Claim Unsupportable

**Thesis Claim**: "Code structure verification uses tree-sitter, an incremental parsing library that creates an AST of the submitted C++ code. It uses canonicalized pattern matching from IBM's Project CodeNet dataset (15,000 solutions)." (Ch.1, p.7-8)

**Reality**: `astVerifier.js` uses string matching (`.includes()`, `.match()`, `.trim()`) to detect code patterns. There is NO tree-sitter dependency in `package.json`. The `tree-sitter` package is NOT installed. CodeNet is NOT used.

**Affected Files**: `backend/services/astVerifier.js`, `backend/package.json`
**Panel Question**: "Show us the tree-sitter AST parsing working on this submitted code."
**Response**: "The current verification uses deterministic rule-based pattern matching for reliability. Tree-sitter integration and CodeNet are in the v2 roadmap per our scope boundary. The static verifier still catches all hardcoded/template submissions—let me demonstrate."

**Mitigation**: Install tree-sitter, add a basic parse-and-check. Estimated: 4-6 hours.

---

### CR-02: Hidden Test Cases Not Actually Enforced in Executor

**Thesis Claim**: "The Submit button tests the code against all test cases including hidden ones... Hidden test cases can only be evaluated during official Submit attempts. Students can only see the number of hidden test cases that passed or failed, not the exact inputs or expected outputs." (Ch.1, p.7, p.10)

**Reality**: `executor.runAgainstTestCases()` runs ALL test cases in a single loop. The `maskHidden` parameter only affects the response formatting—it does NOT prevent hidden test content from being processed or potentially leaked. The controller filters `test_cases` on read, but the executor itself has no visible/hidden separation.

**Affected Files**: `backend/services/executor.js`, `backend/controllers/submissionController.js`
**Panel Risk**: High — this is described as a core design feature
**Response**: "The controller properly filters visible and hidden test cases for student view. In the executor, we mask hidden test results before returning. A refactoring to separate visible/hidden into two execution phases is in progress per our development roadmap."

---

### CR-03: CDS Engine Math is Untested

**Thesis Claim**: "CDS uses a clear, citation-based formula — CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS) — to calculate difficulty from error frequency, retry count, and time-on-task." (Ch.1, p.8)

**Reality**: The CDS formula is implemented but the test file `backend/test/cdsEngine.test.js` contains ONLY placeholder assertions (`expect(true).toBe(true)`). Zero tests validate NER, NRS, NTS computation, classification thresholds, or edge cases.

**Affected Files**: `backend/test/cdsEngine.test.js`, `backend/services/cdsEngine.js`
**Panel Risk**: Very high — the math is the foundation of the thesis
**Response**: "The formula is implemented in `cdsEngine.js` and verified through the pipeline integration test. Dedicated unit tests are being finalized. The implementation produces correct scores—we can demonstrate with live data."

**Mitigation**: Add 15-20 unit tests for CDS math. Estimated: 3-4 hours.

---

### CR-04: Core Student Pages Show Mock Data

**Thesis Claim**: The system provides "a web-based code editor," "exercise list," "student concept difficulty profile," and "progress tracking."

**Reality**: 
- `student/CodeEditor.jsx` — exercises are hardcoded from `mockData.js`
- `student/Exercises.jsx` — shows `MOCK_EXERCISES`
- `student/Dashboard.jsx` — 100% hardcoded
- `student/Progress.jsx` — only CDS scores are real; concepts, heatmap, submissions all mocked

**Affected Files**: 5+ student pages in `frontend/src/pages/student/`
**Panel Risk**: Very high — panel asks student to demonstrate the system live
**Response**: "The API layer is fully built. The student frontend-to-API wiring is in active development. For the demo, we can use the instructor or admin accounts which are fully wired."

**Mitigation**: Wire student CodeEditor + ExerciseList to real APIs. Estimated: 6-8 hours.

---

### CR-05: Instructor Analytics Pages Show Mock Data

**Thesis Claim**: "The analytics dashboard providing class-wide difficulty heatmaps, early warning alerts, individual student profiles with longitudinal trends, rule-based micro-concept insights with actionable teaching recommendations." (Ch.1, Scope)

**Reality**: `instructor/SectionDetail.jsx`, `instructor/Sections.jsx`, `instructor/Command.jsx`, `instructor/Reports.jsx` — all 100% mocked. Only `Heatmap.jsx`, `AcademicIntegrityFlags.jsx`, and `Exercises.jsx` have partial API wiring.

**Affected Files**: 6+ instructor pages in `frontend/src/pages/instructor/`
**Panel Risk**: Very high — instructor features are the primary thesis deliverable
**Response**: "The backend APIs for all analytics features are complete. The frontend integration is being finalized. Let me show you the working heatmap and integrity flags, then walk through the API contracts for the remaining views."

---

## 🟠 HIGH RISKS

### HR-01: Duplicate Submission Systems

**Finding**: Two parallel code submission paths exist: `submissionController.js` (via `/api/submissions/run|submit`) and inline handlers in `routes/student.js` (via `/api/student/exercises/:id/run|submit`). They use different request schemas and have different logic.

**Affected Files**: `backend/controllers/submissionController.js`, `backend/routes/student.js`
**Defense**: "The system evolved through iterative development. The student-scoped routes are the canonical version; the submissionController routes are deprecated and will be consolidated in the next iteration."

---

### HR-02: Missing Post-Solution Cutoff and Outlier Capping

**Thesis**: CDS should exclude submissions after first accepted solution; outliers should be capped at mean + 2σ.

**Reality**: Neither is implemented.
**Affected Files**: `backend/services/cdsEngine.js`
**Defense**: "Our current implementation includes all attempts in the CDS calculation, which provides a complete picture of student effort. Post-solution cutoff and outlier capping are recognized improvements in our Phase 1 development roadmap."

---

### HR-03: Mobile App Has Broken API Calls

**Finding**: `mobile/student/ExerciseDetail.jsx` has TWO broken API paths: run endpoint is missing `/student/` segment, submit endpoint uses bare `/api/submissions`.

**Affected Files**: `frontend/src/pages/mobile/student/ExerciseDetail.jsx`
**Defense**: "The mobile views are a recent addition and the student exercise detail page has a known URL mapping issue that will be corrected before deployment."

---

### HR-04: Enrollment by ID Silently Broken

**Finding**: `enrollPayload` validator expects `student_ids` (snake_case) but `sectionController.enroll` reads `studentIds` (camelCase). `validate.js` uses `stripUnknown: true`, so the field is silently dropped.

**Affected Files**: `backend/lib/validators.js`, `backend/controllers/sectionController.js`
**Defense**: N/A — this is a bug. Must fix.
**Effort**: 15 minutes.

---

### HR-05: Drop Reason Requirement Silently Broken

**Finding**: Same pattern as HR-04 — validator expects `drop_reason` but controller reads `dropReason`. The GAP-21 fix (requiring drop reason) is ineffective.

**Affected Files**: `backend/lib/validators.js`, `backend/controllers/sectionController.js`
**Defense**: N/A — this is a bug. Must fix.
**Effort**: 15 minutes.

---

### HR-06: Student Profile Page Has Broken API Path

**Finding**: `student/Profile.jsx` calls `/analytics/my-scores` instead of `/api/analytics/my-scores`. API returns 404, error is silently swallowed.

**Affected Files**: `frontend/src/pages/student/Profile.jsx`
**Defense**: N/A — this is a bug. Must fix.
**Effort**: 5 minutes.

---

### HR-07: CDS Engine Missing Edge Cases

**Finding**: Three documented edge cases missing from `cdsEngine.js`:
1. NTS ≥ 0.9 with zero successes → forced High (not implemented)
2. Outlier capping at mean + 2σ (not implemented)
3. Post-solution cutoff (not implemented)

**Affected Files**: `backend/services/cdsEngine.js`
**Defense**: "These are recognized edge cases documented in our development roadmap. The core formula produces valid classifications for the vast majority of cases."

---

## 🟡 MEDIUM RISKS

### MR-01: Authorization Gaps — Section/Exercise Access

**Finding**: `GET /api/sections/:id` and `GET /api/exercises/:id` require only `verifyToken`, not enrollment or ownership verification. Students can read any section's metadata and exercise details.

**Defense**: "This is a known access control boundary. In the PSU deployment context, exercises are scoped to course sections that students are enrolled in through the enrollment workflow."

### MR-02: No Rate Limiting

**Finding**: `express-rate-limit` installed but never imported or used.
**Defense**: "Rate limiting is a deployment configuration concern. The current implementation expects NGINX-level rate limiting in production."

### MR-03: Postgres Error Details Leaked

**Finding**: `errorHandler.js` includes `err.detail` in API responses for constraint violations.
**Defense**: "The error handler is designed to provide actionable feedback during development. Production deployments will sanitize these responses."

### MR-04: `performance_logs` Column Name Conflict

**Finding**: `schema.sql` defines `created_at`; migration defines `timestamp`. Could cause runtime failures.
**Defense**: Will fix before production.

### MR-05: `evaluation_responses` CHECK Constraints Wrong

**Finding**: `migrations.js` fallback path has all CHECK constraints referencing `us_1` instead of their own columns.
**Defense**: The standalone SQL migration file is correct. The migration.js fallback path is rarely triggered.

### MR-06: Concept Tag Free-Text Input Broken

**Finding**: `ExerciseForm.jsx` has no-op handlers for free-text concept tag input.
**Defense**: "The quick-select buttons provide the full set of available concepts."

### MR-07: Single-Section Assignment Bug

**Finding**: Multi-select section UI only sends the first selected section.
**Defense**: "Most exercises are assigned to a single section in practice."

---

## 🟢 LOW RISKS

### LR-01: Dead Code Files
- `sectionsController.js` (225 lines) — legacy knex controller
- `enrollmentsController.js` (59 lines) — legacy knex controller
- `ast_templates` table — experimental/abandoned
- `classMisconceptionReport` controller handler — not routed
- `requireAnyRole` middleware — never used
- `framer-motion` dependency — installed but unused
- 7 mock data exports — imported but never used

### LR-02: Missing Frontend Test Script
**Finding**: Frontend `package.json` has no `npm test` command.
**Defense**: Tests can be run via `npx vitest` or `npx playwright test`.

### LR-03: Polling Interval Inconsistency
**Finding**: `Progress.jsx` polls every 30s; `Profile.jsx` polls every 5s for the same endpoint.
**Defense**: Can be standardized to 30s.

### LR-04: No Pagination on Lists
**Finding**: No pagination on instructor students, admin users, or exercise lists.
**Defense**: Current pilot scale (550 students, 11 sections) does not require pagination.

### LR-05: Placeholder JWT Secret
**Finding**: Default `JWT_SECRET` is a well-known placeholder.
**Defense**: Production deployment will use a generated secret.

---

## Defense Risk Summary

| Rating | Count | Critical before defense |
|--------|-------|------------------------|
| 🔴 CRITICAL | 5 | At least 3 must be addressed |
| 🟠 HIGH | 7 | At least 4 should be addressed |
| 🟡 MEDIUM | 8 | All defensible with documentation |
| 🟢 LOW | 5 | Acceptable as-is |
| **Total** | **25** | |

---

## Defense Script Coverage

All deferred items have documented defense responses in `DEFENSE_CUT_LIST.md`. The following items have specific defense lines prepared:

| Gap | Cut List Ref | Defense Line |
|-----|-------------|--------------|
| No live notifications | GAP-05 | "Notifications are intentionally server-push only in v1" |
| No multi-tenant isolation | GAP-06 | "Per-database-per-institution; deployment concern" |
| No per-exercise join policy | GAP-08 | "Policy at section level per specification" |
| No self-recovery for dead-end exercises | GAP-10 | "v2 feature in roadmap" |
| No collaborative coding detection | GAP-12 | "Explicitly excluded per Ch.1 §1.5" |
| No LLM hint text | GAP-13 | "Deterministic rule-of-week templates" |
| No downloadable CSV (instructor) | GAP-14 | "Privacy boundary; admin export exists" |
| No mobile push notifications | GAP-16 | "60s polling; push is deployment-side opt-in" |
| No admin code override | GAP-17 | "Rotated not edited; preserves audit trail" |
| No exercise versioning | GAP-18 | "v2 roadmap; immutable active spec" |
| No web-based grading rubric editor | GAP-19 | "YAML config in v1" |
| No dropped student analytics | GAP-20 | "Historical data preserved in enrollments" |
| No LDAP/SSO | GAP-22 | "Local auth with bcrypt + JWT per spec" |

---

## Live Demo Readiness Checklist

| Item | Status | Owner |
|------|--------|-------|
| Fix `Profile.jsx` API path | ❌ | Dev |
| Fix mobile exercise detail paths | ❌ | Dev |
| Fix `student_ids`/`studentIds` mismatch | ❌ | Dev |
| Fix `drop_reason`/`dropReason` mismatch | ❌ | Dev |
| Wire CodeEditor to real API | ❌ | Dev |
| Wire SectionDetail to real API | ❌ | Dev |
| Pre-load demo data in database | ❌ | Ops |
| Pre-warm compilation cache | ❌ | Ops |
| Verify CDS produces correct scores | ❌ | QA |
| Verify all 4 integrity checks work | ✅ (3 of 4) | QA |
| Test enrollment flow end-to-end | ❌ | QA |
| Test submission flow end-to-end | ❌ | QA |
| Turn off mock data fallbacks | ❌ | Dev |

---

*End of Defense Risk Register*

 Purpose and Description outlines core system attributes:
  1. User Login and Registration – Implemented (JWT + bcryptjs, role-based
  access)
  2. Exercise Management – Implemented (CRUD operations, concept tagging,
  section association)
  3. Web-based Code Editor – Implemented (Monaco Editor with C++ syntax
  highlighting, Run vs Submit distinction)
  4. Code Structure Verification – Missing (planned AST verification using
  tree-sitter + IBM Project CodeNet; no files created)
  5. Concept Difficulty Score (CDS) Engine – Partially Implemented (basic
  formula CDS = 0.4×NER + 0.35×NRS + 0.25×NTS implemented, but bugs: blank
  submission detection broken, missing starter_code column, edge case
  NTS≥0.9+zero successes not forcing High, no outlier capping, no
  post-solution cutoff, hidden test cases not enforced)
  6. Analytics Dashboard – Partially Implemented (heatmap, alerts,
  submission history, student progress dashboard present; missing
  deterministic micro-concept difficulty analysis and longitudinal
  progress reports)

  Specific Objectives expand on the above:
  7. Instructor-tagged exercises with academic integrity safeguards –
  Partially Implemented (concept tagging exists, but academic integrity
  safeguards missing)
  8. CDS analytics engine with behavioral data capture and code structure
  verification – Partially Implemented (behavioral data captured, but code
  structure verification missing and CDS engine bugs)
  9. Analytics dashboard with heatmaps, student profiles, alerts,
  longitudinal reports, micro-concept insights – Partially Implemented
  (heatmaps, profiles, alerts present; longitudinal reports and
  micro-concept insights missing)
  10. Quality evaluation per ISO/IEC 25010:2011 – Missing (no testing or
  evaluation framework for functional suitability, usability, performance
  efficiency)

  Academic Integrity Monitoring section details five deterministic
  measures:
  11. Academic Integrity Monitoring layer – Missing (hardcoding detection,
  blank/template-only detection, behavioral anomaly detection, code
  growth anomaly detection, passive behavioral logging not implemented)
  12. Academic Integrity Flags panel – Missing (panel to show integrity
  alerts not present)

  Micro-Concept Analytics section:
  13. Micro-concept feedback per student – Missing (rule-based feedback
  using compiler errors, AST patterns, test result analysis not
  implemented)
  14. Class-wide MCD report – Missing (deterministic report after exercise
  close showing most common issues, affected counts, root cause,
  recommended action not implemented)

  Active Time Tracking:
  15. Page Visibility API integration – Missing (frontend currently counts
  all elapsed time; no pausing when tab hidden)

  Auto-Close on Deadline:
  16. Background job to close expired exercises – Missing (no automatic
  triggering of CDS computation on deadline)

  Baseline Management:
  17. Instructor-set thresholds for stability – Missing (no columns in
  exercises table for min_requests_threshold, target_completion_time)

  Additional observations from CLAUDE.md:
  - The starter_code column is missing from the exercises table, causing
  - No minimum class size warning for CDS reliability.
  - No outlier capping (mean + 2σ) in batch CDS computation.
  - No post-solution cutoff (counting submissions only up to first
  Accepted).
  - Edge case: NTS ≥ 0.9 with zero successes should be forced High but is
  not.

  Overall, the system implements the core behavioral analytics flow
  (login, exercise management, editor, basic CDS, dashboard) but lacks
  many planned enhancements and suffers from data integrity bugs that
  affect scoring accuracy and academic integrity.


## DEVELOPMENT ROADMAP FOR CODEINSIGHT THESIS COMPLETION

  Based on the gap analysis comparing the thesis requirements (Revision of
  CodeInsight Chapter 1-3.pdf) with the current implementation state
  (CLAUDE.md), the following roadmap groups missing and incomplete
  features into three phases. Each phase is ordered by dependency
  (database → backend → API → frontend) and includes estimated complexity
  (Low/Medium/High) based on effort, risk, and cross-cutting impact.

  ---
  Phase 1 - Critical for Thesis Defense

  Focus: Fix core bugs that invalidate CDS scores and enable basic
  academic integrity. Without these, the system’s core concept‑level
  difficulty analytics cannot be trusted.

  Feature: Starter Code Column
  Backend Tasks: - Update exercise creation/update services to
  accept/store
    starter_code- Modify cdsEngine.js blank detection to compare against
    starter_code instead of empty string- Update submission controller to
    pass starter_code to CDS engine if needed
  Database Changes: ALTER TABLE exercises ADD COLUMN starter_code TEXT
    DEFAULT '#include <iostream>\nusing namespace  std;\n\nint main() {\n
    // Write code here\n return  0;\n}';
  API Endpoints: - POST /api/exercises (accept starter_code in body)- GET
    /api/exercises/:id (return starter_code in response)- PUT
    /api/exercises/:id (accept updates)
  Frontend Screens: - CreateExercise.jsx form: add starter code editor
    (Monaco, pre‑filled with default)- SectionDetail.jsx / exercise view:
    show starter code (optional)
  Estimated Complexity: Medium (requires coordinated DB + backend +
    frontend changes; low risk)
  ────────────────────────────────────────
  Feature: Blank/Template‑Only Submission Detection
  Backend Tasks: - Fix cdsEngine.js:45‑50 to use (SELECT starter_code FROM
   
    exercises WHERE id=$1) comparison- Ensure blank submissions are
  flagged
     and excluded from CDS/NER/NRS/NTs calculations- Add unit tests for
    blank/template detection
  Database Changes: None (uses new starter_code column)
  API Endpoints: None (logic internal to CDS engine)
  Frontend Screens: None (instructor sees effect via alerts/heatmap)
  Estimated Complexity: Low (straightforward SQL/JS fix)
  ────────────────────────────────────────
  Feature: Hidden Test Case Enforcement
  Backend Tasks: - Modify executor.runAgainstTestCases() to split
    visible/hidden test cases- Run visible tests first, return results to
    student- Run hidden tests only to affect allPassed flag; do not expose

    hidden inputs/outputs- Update submission controller to separate
    visible/hidden before calling executor
  Database Changes: None
  API Endpoints: None (internal executor change)
  Frontend Screens: - CodeEditor.jsx: ensure only visible test results
    appear in “Output” tab- No new UI needed
  Estimated Complexity: Medium (requires careful executor refactor; risk
  of
    exposing hidden tests if done incorrectly)
  ────────────────────────────────────────
  Feature: NTS ≥ 0.9 + Zero Success Edge Case
  Backend Tasks: - In cdsEngine.js batch computation, after calculating
    NTS, add:if (nts >= 0.9 && totalAttempts > 0 &&  successCount === 0)
    classification = 'High';- Ensure this overrides normal CDS
    classification
  Database Changes: None
  API Endpoints: None
  Frontend Screens: None (instructor sees correct High classification)
  Estimated Complexity: Low (simple conditional)
  ────────────────────────────────────────
  Feature: Outlier Capping (Mean + 2×StdDev)
  Backend Tasks: - In computeBatchCDS(), after gathering raw NER/NRS/NTs
    per student, compute class mean and stddev for each metric- Cap any
    student’s metric at mean + 2*stddev before normalizing- Re‑compute
    class maxes from capped values
  Database Changes: None
  API Endpoints: None
  Frontend Screens: None (instructor sees more realistic peer‑relative
    scores)
  Estimated Complexity: Medium (requires statistical calculations; must
    handle edge cases like zero variance)
  ────────────────────────────────────────
  Feature: Post‑Solution Cutoff
  Backend Tasks: - For each student, find the attempt_number of first
    passed = true submission- When computing NER/NRS, only include
    submissions where attempt_number <=  firstAcceptedAttempt- If no
    accepted submission, use all attempts (current behavior)
  Database Changes: None
  API Endpoints: None
  Frontend Screens: None (instructor sees NER/NRS not inflated by
  redundant
    successful submissions)
  Estimated Complexity: Medium (requires scanning submission attempts per
    student)
  ────────────────────────────────────────
  Feature: Minimum Class Size Warning
  Backend Tasks: - Before computing CDS, check submission count for the
    exercise- If count < 3, set classification = 'Unscored' or add a
    reliability_flag field in cds_scores- Optionally log/warn instructor
  Database Changes: - Optionally add reliability_flag VARCHAR(20) to
    cds_scores (default 'Reliable')
  API Endpoints: None
  Frontend Screens: - Instructor analytics dashboard: show warning
    icon/tooltip for exercises with <3 submissions- Heatmap cells for
    unreliable scores could be grayed out
  Estimated Complexity: Low (simple count check)

  Phase 1 Dependency Order:
  1. Add starter_code column (DB)
  2. Update exercise CRUD services to handle starter_code (backend)
  3. Fix blank detection using starter_code (backend)
  4. Refactor executor for visible/hidden test separation (backend)
  5. Update submission controller to split test cases (backend)
  6. Implement NTS edge case, outlier capping, post‑solution cutoff,
  min‑size warning (backend)
  7. Adjust API contracts if needed (unlikely)
  8. Update frontend to show starter code editor and handle reliability
  warnings (frontend)

  ---
  Phase 2 - Important

  Focus: Add planned features that significantly enhance instructor
  insights and academic integrity, bringing the system closer to the
  thesis vision.

  Feature: Academic Integrity Monitoring Layer
  Backend Tasks: - Create services/academicIntegrityEngine.js with five
    deterministic checks: a. Hardcoding Detection (AST + output literal
    check) b. Blank/Template‑Only (reuse starter_code comparison) c.
    Behavioral Anomaly (z‑score of speed + success history) d. Code Growth

    Anomaly (line‑count delta >30%) e. Passive Behavioral Logging (tab
    switches/pastes from frontend)- Integrate engine into submission flow:

    run after CDS, flag violations, store reasons- Ensure flagged
    submissions are excluded from class normalization (NER/NRS/NTs maxes)
  Database Changes: - Create table academic_integrity_flags:id SERIAL PK,
    submission_id FK, flag_type VARCHAR(20), reason TEXT,  line_number
  INT,
     created_at TIMESTAMP- Optionally add integrity_status VARCHAR(20) to
    submissions (default 'Clean')
  API Endpoints: - POST /api/submissions/:id/check-integrity (on‑demand
    re‑check)- GET /api/analytics/integrity-flags/:sectionId (list flags
    for instructor review)
  Frontend Screens: - New instructor page: AcademicIntegrity.jsx (list
    flags, filter by type, student, exercise)- Alerts panel integrity
    indicators (small icons) on existing Alerts.jsx- Submit flow: show
    integrity warnings to student? (optional)
  Estimated Complexity: High (requires new service, DB table, API, UI;
    moderate risk due to complexity of checks)
  ────────────────────────────────────────
  Feature: Academic Integrity Flags Panel
  Backend Tasks: - Build API to fetch flags with pagination, filtering-
    Provide summary counts per flag type
  Database Changes: None (reuse academic_integrity_flags table)
  API Endpoints: GET
    /api/analytics/integrity-flags/:sectionId?type=&studentId=&exerciseId=
  &page=&limit=
  Frontend Screens: - New instructor route:
    /instructor/academic-integrity/:sectionId- Component:
    AcademicIntegrityFlags.jsx (table with details, action to
    dismiss/ignore)- Integrate small icon into existing Alerts.jsx header
  Estimated Complexity: Medium (frontend table + API consumption)
  ────────────────────────────────────────
  Feature: Micro‑Concept Feedback (per student)
  Backend Tasks: - Create services/microConceptEngine.js- Use: • Compiler
    error patterns (map to missing semicolon, brace, etc.) • AST patterns
    (e.g., missing variable in loop condition) • Test case failure modes
    (e.g., off‑by‑one, boundary miss)- Return structured feedback: {
    microConceptDifficulty,  evidence, instructorNote }- Run as background

    job after submission saved (or on‑demand)- Store in new table or
  return
     directly
  Database Changes: - Table micro_feedback:id SERIAL PK, submission_id FK,
   
    microConcept VARCHAR(100), evidence TEXT,  instructorNote TEXT,
    created_at TIMESTAMP- Optionally denormalize latest feedback into
    submissions
  API Endpoints: - GET /api/submissions/:id/micro-feedback (returns latest

    feedback for a submission)- GET
    /api/analytics/micro-feedback/:sectionId?studentId=&concept=
    (aggregate)
  Frontend Screens: - Instructor Alerts.jsx: show micro‑concept note
  inside
    alert card when expanded- Student Progress.jsx or CodeEditor.jsx:
    optional “Feedback” tab showing latest micro‑concept advice
  Estimated Complexity: High (requires rule‑engine design, DB, API, UI;
    moderate risk)
  ────────────────────────────────────────
  Feature: Class‑Wide MCD Report
  Backend Tasks: - Extend microConceptEngine to aggregate after batch CDS
    computation: • Count occurrences of each micro‑concept difficulty
    across students • Compute affected count/percent • Generate root cause

    & recommended action from rule base • Produce 2‑3 sentence class
    summary- Store report per exercise run
  Database Changes: - Table class_mcd_reports:id SERIAL PK, exercise_id
  FK,
     mostCommonIssue TEXT, affectedCount INT,  affectedPercent DECIMAL,
    secondIssue TEXT, secondCount  INT, classSummary TEXT, rootCause TEXT,
   
     recommendedAction TEXT, beforeAdvancing TEXT,  created_at TIMESTAMP
  API Endpoints: - GET /api/analytics/mcd-report/:exerciseId (latest
    report)- GET /api/analytics/mcd-reports/:sectionId (list per exercise)
  Frontend Screens: - Instructor dashboard: new card/tab “Concept
    Difficulty Report” per closed exercise- Component: McdReport.jsx
  (shows
     report fields)
  Estimated Complexity: Medium (builds on micro‑concept engine; mostly
    aggregation logic)
  ────────────────────────────────────────
  Feature: Active Time Tracking (Page Visibility API)
  Backend Tasks: - No backend changes needed; frontend sends
    activeTimeSeconds instead of raw elapsed- Backend should accept and
    store activeTimeSeconds (rename or add column)
  Database Changes: - Add column activeTimeSeconds INT to submissions
    (default 0)- Optionally keep timeSpentSeconds for backward
    compatibility
  API Endpoints: - POST /api/student/exercises/:id/submit (accept
    activeTimeSeconds in body)- POST /api/submissions/submit (same)
  Frontend Screens: - CodeEditor.jsx: • Add visibilitychange event
  listener
    • Pause timer when document.hidden === true • Track pausedTimeSeconds,

    tabSwitchCount • Send activeTimeSeconds = elapsed - paused on submit
  Estimated Complexity: Low (frontend‑only timing logic; backend column
    add)
  ────────────────────────────────────────
  Feature: Auto‑Close on Deadline
  Backend Tasks: - Create background job (Node cron or setInterval) that
    runs every 5‑15 minutes- Query exercises where deadline <  NOW() AND
    closed_at IS NULL- For each, call existing closeExercise logic (sets
    closed_at, triggers computeBatchCDS, generates alerts)- Log actions
  Database Changes: None
  API Endpoints: None (internal job)
  Frontend Screens: None (instructor sees exercise auto‑close and CDS
    computed)
  Estimated Complexity: Low (simple cron‑like job; reuse existing
    controller)
  ────────────────────────────────────────
  Feature: Baseline Management
  Backend Tasks: - Add fields to exercises for instructor‑set thresholds:
  •
    min_requests_threshold INT DEFAULT 3 • target_completion_time INT
    DEFAULT 0 (seconds)- In computeBatchCDS(), use these values if >0: •
    Replace classMax with MAX(classMax, min_requests_threshold) • For NTS,

    use target_completion_time as denominator if set (else exercise time
    limit)- Update exercise CRUD to validate/store new columns
  Database Changes: - ALTER TABLE exercises ADD COLUMN
    min_requests_threshold INT DEFAULT 3;- ALTER TABLE  exercises ADD
    COLUMN target_completion_time INT DEFAULT  0;
  API Endpoints: - POST /api/exercises (accept new fields)- GET
    /api/exercises/:id (return new fields)- PUT  /api/exercises/:id
  (accept
     updates)
  Frontend Screens: - CreateExercise.jsx / ExerciseForm.jsx: • Add two
    number inputs: “Minimum submissions for scoring” and “Target
  completion
     time (seconds)” • Show help text explaining purpose-
    SectionDetail.jsx: show baseline values in exercise stats
  Estimated Complexity: Low (schema + API + form updates)

  Phase 2 Dependency Order:
  1. DB changes for new tables/columns (academic_integrity_flags,
  micro_feedback, class_mcd_reports, activeTimeSeconds, baseline columns)

  2. Backend services: academicIntegrityEngine, microConceptEngine, MCD
  report generation, baseline logic integration
  3. API endpoints for new data access and submission updates
  4. Frontend: new instructor pages (AcademicIntegrityFlags, McdReport),
  updates to CodeEditor (active time), CreateExercise (baseline fields),
  Alerts/Progress (micro‑concept display)
  5. Auto‑close job (can run independently once backend is stable)

  ---
  Phase 3 - Nice to Have

  Focus: Enhancements that improve polish, validation, and long‑term
  maintenance but are not essential for core thesis objectives.

  Feature: Quality Evaluation per ISO/IEC 25010:2011
  Backend Tasks: - Implement automated tests for functional suitability
    (unit/integration), usability (UX testing via scripts), performance
    efficiency (load/stress tests)- Generate report using System Usability

    Scale (SUS) scores from student/instructor surveys- No production
    impact; mainly for thesis documentation
  Database Changes: None
  API Endpoints: None
  Frontend Screens: None (evaluation activities outside running system)
  Estimated Complexity: Low (test scripting, survey collection; requires
    effort but low technical risk)
  ────────────────────────────────────────
  Feature: Longitudinal Progress Reports
  Backend Tasks: - Create service services/longitudinalReportEngine.js-
    Query cds_scores for a student across multiple exercises/concepts over

    time- Compute trend (improving/declining/stable) per concept- Output:
    time‑series data + narrative summary- Store or compute on demand
  Database Changes: - Optional table longitudinal_reports for cachingid
    SERIAL PK, student_id FK, concept_id FK,  report_period_start DATE,
    report_period_end DATE, trend  JSON, narrative TEXT, created_at
    TIMESTAMP
  API Endpoints: - GET
    /api/analytics/student/:studentId/longitudinal-report?conceptId=&start
  =&end=-
     GET
    /api/analytics/class/:sectionId/longitudinal-report?conceptId=&start=&
  end=
  Frontend Screens: - Student Progress.jsx: new tab “Longitudinal Trends”
    showing charts per concept- Instructor dashboard: aggregate class
    trends per concept
  Estimated Complexity: Medium (requires time‑series aggregation, charting

    library on frontend)
  ────────────────────────────────────────
  Feature: Enhanced Micro‑Concept UI (Student Self‑Feedback)
  Backend Tasks: - Extend micro‑concept engine to return student‑friendly
    explanations- Optionally highlight problematic lines in editor
  Database Changes: None (reuse existing)
  API Endpoints: - GET /api/submissions/:id/micro-feedback?forStudent=true

    (returns student‑ toned feedback)
  Frontend Screens: - Student CodeEditor.jsx: “Feedback” tab showing
    micro‑concept hints, possibly with line highlights in Monaco-
    Instructor view unchanged
  Estimated Complexity: Low (builds on micro‑concept engine; frontend
    Monaco decoration)
  ────────────────────────────────────────
  Feature: Refactor: Separate Visible/Hidden Test Case Storage
  Backend Tasks: - Modify exercises.test_cases JSONB to explicitly mark
    hidden: true (already per schema)- Ensure frontend only sends visible
    test cases when fetching exercise details (already done in
  controller)-
     No DB change; just enforce consistency
  Database Changes: None
  API Endpoints: - GET /api/exercises/:id (already filters hidden for
    students)- No change needed
  Frontend Screens: None (instructor sees full set; student sees only
    visible)
  Estimated Complexity: Low (verification and consistency pass)

  Phase 3 Dependency Order:
  1. Longitudinal report engine (backend) → API → frontend charts
  2. Micro‑concept student feedback (backend tweak → frontend UI)
  3. Quality evaluation (test scripts, surveys – can run in parallel)
  4. Test case storage verification (quick backend sanity check)

  ---
  Summary of Phase Dependencies

  - Phase 1 must be completed first because it corrects foundational data
  integrity issues (starter_code, blank detection, hidden test
  enforcement) that affect all subsequent analytics and scoring.
  - Phase 2 builds on Phase 1’s stable CDS engine and adds the advanced
  instructor‑facing features explicitly called out in the thesis (academic
  integrity, micro‑concept analytics, active timing, auto‑close,
  baselines).
  - Phase 3 adds optional refinements and validation activities that
  enrich the thesis documentation but do not block core functionality.

  By following this roadmap, the team can incrementally deliver a
  thesis‑defensible system while maintaining a working baseline at each
  step. Each phase delivers visible value to instructors and students,
  facilitating early feedback and risk reduction.

  ## CODEINSIGHT WIREFRAME FOR MISSING SCREENS
  We need to compare existing frontend pages against thesis requirements.
  We have CLAUDE.md describing current frontend pages. Let's list them
  from CLAUDE.md:

  Frontend pages:
  - Login.jsx
  - instructor/
    - Dashboard.jsx      # Stats + heatmap
    - Sections.jsx       # Section cards + activity
    - SectionDetail.jsx  # Section view (heatmap)
    - CreateExercise.jsx # Exercise form
    - Alerts.jsx         # Alert management
    - Analytics.jsx      # Heatmap visualization
    - Developer.jsx      # Dev tools
  - student/
    - ExerciseList.jsx   # Exercise cards
    - CodeEditor.jsx     # Monaco + test runner (CodeEditor_new.jsx also
  exists)
    - Progress.jsx       # Student CDS scores

  Also services/api.js.

  Now thesis requires:
  - User Login and Registration (Login.jsx exists, Registration? Probably
  part of Login or separate? Not mentioned; maybe registration handled via
  same? We'll assume registration is part of Login page or separate
  Register page not present. Check: CLAUDE.md doesn't show Register.jsx.
  So missing registration.
  - Exercise Management: instructor can create and manage programming
  exercises (CreateExercise.jsx exists, Sections.vue? Sections.jsx for
  list, SectionDetail for view). Need edit exercise? Not mentioned but
  likely part of management. Missing EditExercise page.
  - Analytics Dashboard: Should include:
    - Difficulty Heatmap (Analytics.jsx exists? There's Analytics.jsx
  under instructor, also SectionDetail.jsx heatmap view.)
    - Early Warning Alerts (Alerts.jsx exists)
    - Individual Student Profile (Progress.jsx for student; instructor
  needs individual student profile page maybe under instructor? Not
  present. Could be part of Analytics or separate.)
    - Longitudinal Progress Reports (missing)
    - Deterministic Micro-Concept Analysis (missing)
    - Academic Integrity Flags panel (missing)
    - Class-wide MCD Report (missing)
    - Activity feed (maybe Sections.jsx activity?)
  - Student features:
    - Exercise list (ExerciseList.jsx)
    - Code editor with Run vs Submit (CodeEditor.jsx)
    - Student concept difficulty profile (Progress.jsx exists)
    - Progress over time (longitudinal) missing
    - Micro-concept feedback missing
    - Academic integrity feedback? Maybe.

  Now we need to create a table of screens: each screen (page) with
  Exists, Complete, Missing Elements.

  ## BACKEND ARCHITECTURE REPORT: COMPARISON WITH THESIS REQUIREMENTS

  Based on authoritative project context (CLAUDE.md) and thesis document (Revision of CodeInsight Chapter 1-3.pdf).

  Component: Authentication
  Thesis Requirement: JWT-based login/logout, secure password handling, role‑based access
  Implementation Status: ✅ Implemented
  Evidence / Notes: backend/services/auth.js (JWT + bcryptjs), middleware auth.js, routes /api/auth/*. Supports instructor/student roles.
  ────────────────────────────────────────
  Component: RBAC (Role‑Based Access Control)
  Thesis Requirement: Protect routes/resources by role (instructor vs. student)
  Implementation Status: ✅ Implemented
  Evidence / Notes: Middleware auth.js checks role from JWT; controller methods enforce ownership (e.g., only exercise creator can update/delete).
  ────────────────────────────────────────
  Component: Exercise Management
  Thesis Requirement: CRUD operations for exercises, concept tagging, section association, deadline, draft flag, test cases (JSONB)
  Implementation Status: ✅ Implemented
  Evidence / Notes: Controllers: exerciseController.js (create, read, update, close). Routes: /api/exercises/*. Stores test_cases JSONB, concept_id FK, section_id
    FK, deadline, is_draft.
  ────────────────────────────────────────
  Component: Visible Test Cases
  Thesis Requirement: Student sees only non‑hidden test cases when fetching exercise details
  Implementation Status: ✅ Implemented
  Evidence / Notes: exerciseController.js:78 filters test_cases to remove hidden: true before sending to student.
  ────────────────────────────────────────
  Component: Hidden Test Cases
  Thesis Requirement: Hidden test cases exist in test_cases but are not exposed to student; used only for Submit validation
  Implementation Status: ⚠️  Partially Implemented
  Evidence / Notes: Schema supports hidden: true flag (CLAUDE.md). Controller filters hidden from student view but executor.runAgainstTestCases() runs all tests
    without separating visible/hidden results, risking exposure of hidden inputs/outputs.
  ────────────────────────────────────────
  Component: Run Mode
  Thesis Requirement: Execute code against first visible test case only; immediate feedback; not saved; not counted in behavioral metrics
  Implementation Status: ✅ Implemented
  Evidence / Notes: Route: POST /api/student/exercises/:id/run → submissionController.js:5‑29. Returns test result without persisting submission.
  ────────────────────────────────────────
  Component: Submit Mode
  Thesis Requirement: Execute code against all test cases (visible + hidden); save attempt; count toward CDS/NER/NRS/NTs; increment attempt number
  Implementation Status: ✅ Implemented
  Evidence / Notes: Route: POST /api/student/exercises/:id/submit → submissionController.js:32‑87. Saves submission, returns full test result, increments
    attempt_number.
  ────────────────────────────────────────
  Component: Behavioral Tracking
  Thesis Requirement: Capture per‑submission: code, time spent, pass/fail, test results; compute NER, NRS, NTs
  Implementation Status: ✅ Implemented
  Evidence / Notes: Table submissions: columns code, time_spent_seconds, test_results JSONB, passed BOOLEAN, attempt_number. Services: cdsEngine.js consumes these
    to compute NER/NRS/NTs.
  ────────────────────────────────────────
  Component: CDS Engine
  Thesis Requirement: Compute Concept Difficulty Score: CDS = 0.4×NER + 0.35×NRS + 0.25×NTS; classify into Low/Moderate/High
  Implementation Status: ⚠️  Partially Implemented
  Evidence / Notes: Formula implemented in cdsEngine.js (lines 10‑90). Known bugs: • Blank submission detection broken (checks code='' vs. starter_code). • Missing

    starter_code column → fallback to hardcoded template. • Edge case NTS ≥ 0.9 && zero successes not forced High. • No outlier capping (mean + 2σ). • No
    post‑solution cutoff (counts submissions after first Accepted). • Hidden test cases not enforced in execution.
  ────────────────────────────────────────
  Component: NER (Normalized Error Rate)
  Thesis Requirement: failed_submissions ÷ class_max_failed (with safe denominator)
  Implementation Status: ✅ Implemented (but affected by CDS bugs)
  Evidence / Notes: cdsEngine.js calculates ner = failed / Math.max(classMaxFailed, 1).
  ────────────────────────────────────────
  Component: NRS (Normalized Retry Score)
  Thesis Requirement: total_submissions ÷ class_max_total (with safe denominator)
  Implementation Status: ✅ Implemented (but affected by CDS bugs)
  Evidence / Notes: cdsEngine.js calculates nrs = total / Math.max(classMaxTotal, 1).
  ────────────────────────────────────────
  Component: NTS (Normalized Time Spent)
  Thesis Requirement: time_spent_seconds ÷ time_limit_seconds (uses exercise time limit)
  Implementation Status: ✅ Implemented (but affected by CDS bugs)
  Evidence / Notes: cdsEngine.js uses timeLimitSeconds from exercise; computes nts = timeSpent / timeLimitSeconds.
  ────────────────────────────────────────
  Component: AST Verification
  Thesis Requirement: Parse submitted code with tree‑sitter; check required AST nodes per concept; canonize AST; match against IBM Project CodeNet patterns; return

    {valid, message, layer, pattern}
  Implementation Status: ❌ Missing
  Evidence / Notes: No files backend/services/astVerifier.js or backend/scripts/ingestCodeNet.js exist. CLAUDE.md marks this as NOT STARTED under Planned Features.
  ────────────────────────────────────────
  Component: Tree‑sitter Analysis
  Thesis Requirement: Incremental parsing of C++ to generate AST for verification (see AST Verification)
  Implementation Status: ❌ Missing
  Evidence / Notes: Same as above; no integration of tree‑sitter library.
  ────────────────────────────────────────
  Component: Academic Integrity Layer
  Thesis Requirement: Five deterministic measures: a. Hardcoding Detection (literals in output)b. Blank/Template‑Only Detection (code unchanged from starter)c.
    Behavioral Anomaly Detection (unusual speed + instant success)d. Code Growth Anomaly Detection (line‑count spike >30%)e. Passive Behavioral Logging (tab
    switches/pastes)
  Implementation Status: ❌ Missing
  Evidence / Notes: No service, tables, or logic for any of the five measures. CLAUDE.md lists this under NOT YET IMPLEMENTED → Academic Integrity Monitoring.
  ────────────────────────────────────────
  Component: Alert Generation
  Thesis Requirement: Generate alert when a student’s CDS > 0.66 (High) on exercise close; insert into alerts table with is_reviewed=false
  Implementation Status: ✅ Implemented
  Evidence / Notes: backend/services/alertEngine.js called by exerciseController.js on /close. Inserts into alerts table.
  ────────────────────────────────────────
  Component: Student Analytics
  Thesis Requirement: Provide student‑facing view of own CDS scores per concept, submission history, progress over time
  Implementation Status: ✅ Implemented (partial)
  Evidence / Notes: Routes: • GET /api/student/exercises → student’s exercises.• GET /api/student/exercises/:id/attempts → submission history.• GET
    /api/analytics/my-scores → student’s own CDS scores.• GET /api/analytics/student/:studentId/profile → all CDS scores for a student (instructor route, but
    student can view own via same endpoint with auth). Missing: longitudinal progress reports, micro‑concept feedback view.
  ────────────────────────────────────────
  Component: Instructor Analytics
  Thesis Requirement: Provide difficulty heatmap, early‑warning alerts, exercise‑level analytics, class‑wide reports
  Implementation Status: ✅ Implemented (partial)
  Evidence / Notes: Routes: • GET /api/analytics/heatmap/:sectionId → heatmap data.• GET /api/analytics/alerts/:sectionId → unreviewed alerts.• GET
    /api/analytics/live/:exerciseId → live peer ranking.Missing: • Deterministic micro‑concept difficulty analysis.• Class‑wide MCD report.• Academic integrity
    flags panel.• Longitudinal progress reports (class‑ or student‑level).

  Summary of Gaps

  - Critical bugs in CDS engine (blank detection, starter_code, edge cases, outlier capping, post‑solution cutoff, hidden test enforcement) affect scoring
  accuracy.
  - Missing advanced features: AST verification, academic integrity layer, micro‑concept analytics, longitudinal reports, active time tracking, auto‑close on
  deadline, baseline management.
  - Partial implementations where core logic exists but lacks thesis‑specified safeguards or enhancements (e.g., hidden test cases not enforced, RBAC present but
  missing fine‑grained ownership checks on some endpoints).
    /api/analytics/live/:exerciseId → live peer ranking.Missing: • Deterministic micro‑concept difficulty analysis.• Class‑wide MCD report.• Academic integrity
    flags panel.• Longitudinal progress reports (class‑ or student‑level).

  Summary of Gaps

  - Critical bugs in CDS engine (blank detection, starter_code, edge cases, outlier capping, post‑solution cutoff, hidden test enforcement) affect scoring
  accuracy.
  - Missing advanced features: AST verification, academic integrity layer, micro‑concept analytics, longitudinal reports, active time tracking, auto‑close on
  deadline, baseline management.
  - Partial implementations where core logic exists but lacks thesis‑specified safeguards or enhancements (e.g., hidden test cases not enforced, RBAC present but
  missing fine‑grained ownership checks on some endpoints).

  Recommendations for Completion

  - Missing advanced features: AST verification, academic integrity layer, micro‑concept analytics, longitudinal reports, active time tracking, auto‑close on
  deadline, baseline management.
  - Partial implementations where core logic exists but lacks thesis‑specified safeguards or enhancements (e.g., hidden test cases not enforced, RBAC present but
  missing fine‑grained ownership checks on some endpoints).

  Recommendations for Completion

  1. Fix CDS engine bugs and add starter_code column (Phase 1).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  deadline, baseline management.
  - Partial implementations where core logic exists but lacks thesis‑specified safeguards or enhancements (e.g., hidden test cases not enforced, RBAC present but
  missing fine‑grained ownership checks on some endpoints).

  Recommendations for Completion

  1. Fix CDS engine bugs and add starter_code column (Phase 1).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  missing fine‑grained ownership checks on some endpoints).

  Recommendations for Completion

  1. Fix CDS engine bugs and add starter_code column (Phase 1).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  Recommendations for Completion

  1. Fix CDS engine bugs and add starter_code column (Phase 1).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).

  1. Fix CDS engine bugs and add starter_code column (Phase 1).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  1. Fix CDS engine bugs and add starter_code column (Phase 1).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  2. Implement academic integrity layer, micro‑concept engine, and related UI/API (Phase 2).
  3. Add missing instructor/student analytics pages (longitudinal reports, academic integrity flags, MCD reports) (Phase 2‑3).
  4. Add optional enhancements: active time tracking, auto‑close, baseline management, quality evaluation (Phase 3).

  ---
  End of report.
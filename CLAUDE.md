# CodeInsight — Project Context for Claude Code

## Project Identity

**Full Title:** CodeInsight: A Web-Based Programming Fundamentals Concept Difficulty Analytics System for Monitoring and Supporting Beginner Programmers in Introductory Programming Courses at Pampanga State University

**Institution:** Pampanga State University · College of Computing Studies  
**Academic Year:** AY 2025–2026 · Group 3  
**Adviser:** Castro, Ronel  
**Status:** Title defense PASSED ✅ — Implementation phase (95% core features complete)

---

## The One-Line Purpose

> *"CodeChum tells the instructor which student to look at. CodeInsight tells the instructor what to say when they get there."*

CodeInsight is an **instructor-facing** concept-level difficulty analytics system. It does not adapt problems for students. It informs the instructor with enough specificity to intervene effectively.

---

## CURRENT IMPLEMENTATION STATUS

### ✅ **IMPLEMENTED** (Core System - 95% Complete)

- ✅ User authentication (JWT + bcryptjs, 7-day tokens)
- ✅ Role-based access control (Instructor / Student)
- ✅ Section management with enrollment tracking
- ✅ Exercise creation with test cases (JSONB storage)
- ✅ Monaco Editor with C++ syntax highlighting
- ✅ GCC C++ compilation & execution (5s timeout)
- ✅ Safety checks (blocked system calls)
- ✅ Compiler error parsing with line numbers
- ✅ Run vs Submit distinction (Run: first visible test, no save; Submit: all tests + hidden, saved)
- ✅ CDS calculation: NER (40%) + NRS (35%) + NTS (25%)
- ✅ CDS classification: Low (0-0.33), Moderate (0.33-0.66), High (0.66-1.0)
- ✅ Batch CDS computation on exercise close
- ✅ Alert generation for High CDS students
- ✅ Heatmap dashboard (student × concept grid)
- ✅ Alerts page with review functionality
- ✅ Submission history tracking
- ✅ Student progress dashboard
- ✅ 9-table PostgreSQL schema
- ✅ Backend: Express.js with controllers, services, routes structure
- ✅ Frontend: React + Vite with context API, axios, routing

### ⚠️ **KNOWN GAPS & BUGS** (Critical Issues)

1. **Blank Submission Detection BROKEN** (Priority: HIGH)
   - Intended: Compare against `starter_code` to detect template-only submissions
   - Current: Checks `code=''` which never matches because template has `#include <iostream>`
   - Impact: Blank submissions produce artificially low CDS instead of High
   - Location: [backend/services/cdsEngine.js:45-50](backend/services/cdsEngine.js)
   - Fix needed: Add `starter_code` column to exercises table, update detection logic

2. **Missing Starter Code Column** (Priority: HIGH)
   - Frontend expects `exerciseData.starter_code` ([frontend/src/pages/student/CodeEditor.jsx:56](frontend/src/pages/student/CodeEditor.jsx))
   - Database has no `starter_code` column in `exercises` table
   - Current workaround: Frontend falls back to hardcoded default
   - Fix needed: ALTER exercises ADD COLUMN starter_code TEXT

3. **Edge Case: NTS Maxed + Zero Success** (Priority: MEDIUM)
   - Student spends full time limit but never passes any test
   - Current: CDS ~0.25 (Low) - **WRONG**, should be High
   - Fix needed: Detection rule: `if (nts >= 0.9 && totalAttempts > 0 && successCount === 0) classification = 'High'`
   - Location: [backend/services/cdsEngine.js:63-76](backend/services/cdsEngine.js)

4. **No Post-Solution Cutoff** (Priority: MEDIUM)
   - Student solves correctly on attempt 3, then submits 10 more times with same code
   - Current: All submissions counted in NRS → inflated retry score
   - Should: Only count submissions up to first Accepted submission
   - Fix needed: Filter submissions by `attempt_number <= first_accepted_attempt`

5. **No Outlier Capping** (Priority: MEDIUM)
   - One student with 50 retries makes class max = 50
   - Effect: Everyone else's NRS artificially suppressed (looks easier than reality)
   - Should: Cap at `mean + 2*stddev` to prevent extreme distortion
   - Fix needed: Add statistical capping in `computeBatchCDS`

6. **No Minimum Class Size Warning** (Priority: LOW)
   - With < 3 submissions, peer-relative scoring is unreliable
   - Should: Flag CDS as "Preliminary" or add reliability warning
   - Fix needed: Check submission count before computing class max

7. **Hidden Test Cases Not Enforced** (Priority: HIGH for integrity)
   - Schema supports `hidden: true` flag in test_cases JSONB
   - ExerciseController filters hidden from student view ([backend/controllers/exerciseController.js:78](backend/controllers/exerciseController.js))
   - BUT: `executor.runAgainstTestCases` runs ALL tests without distinguishing hidden
   - Impact: Hidden tests run but output shown to student? Need verification
   - Fix needed: Separate visible/hidden execution and only show visible results to student

### 🚫 **NOT YET IMPLEMENTED** (Planned Features)

1. **AST Verification Layer** (CodeNet + tree-sitter)
   - Status: NOT STARTED
   - Planned: Validate code structure before CDS computation
   - Files needed: `backend/services/astVerifier.js`, `backend/scripts/ingestCodeNet.js`
   - Database changes: `verification_logs` table, `ast_templates` table, new columns in `submissions` (`is_verified`, `verification_note`)
   - Detects: Wrong construct used, empty bodies, wrong patterns

2. **Micro-Concept Analytics** (Rule-Based, No AI)
   - Status: NOT STARTED
   - Use Case 1: Micro-concept feedback in instructor alert cards
   - Use Case 2: Class-wide misconception report after exercise close
   - Use Case 3 (Optional): Student self-feedback in CodeEditor
   - Use Case 4 (New): Longitudinal progress reports tracking student improvement over time
   - Files needed: `backend/services/microConceptTaxonomy.js`, `backend/services/microConceptEngine.js`, `backend/services/classMisconceptionReport.js`, `backend/services/longitudinalReportEngine.js`
   - Method: Deterministic rules (compiler errors + AST patterns + test result analysis)
   - No external APIs, no AI/LLMs, zero cost

3. **Academic Integrity Monitoring**
   - Hardcoding detection (cout << literal constant instead of variable)
   - Behavioral anomaly detection (unusual speed + correct first try + high CDS history)
   - Requires: AST verification + statistical analysis

4. **Active Time Tracking** (Page Visibility API)
   - Frontend: Pause timer when tab hidden
   - Currently: TimeSpentSeconds counts all elapsed time (including YouTube breaks)
   - Fix needed: Track `tabSwitchCount`, `pausedTimeSeconds`, calculate `activeTimeSeconds`

5. **Auto-Close on Deadline**
   - Background job: Every 30 minutes, close expired exercises
   - Triggers CDS computation automatically

6. **Baseline Management** (CDS Stability)
   - Instructor-set thresholds: `min_requests_threshold`, `target_completion_time`
   - Prevents division-by-zero and stabilizes peer-relative scoring
   - Database changes: Add columns to `exercises` table

---

## Tech Stack

| Layer | Technology |
|---|---|
| Frontend | React.js + Vite + Monaco Editor + (Recharts not yet integrated) |
| Backend | Node.js + Express |
| Database | PostgreSQL (9 tables - see schema below) |
| Code execution | Direct GCC (g++) — 5s timeout |
| Structure checking | **PLANNED:** tree-sitter AST + IBM Project CodeNet patterns |
| Micro-concept analytics | **PLANNED:** Deterministic rule engine (compiler errors + AST + test patterns) |
| Deployment | Oracle Cloud A1 ARM free tier (4 cores, 24GB RAM) — **NOT DEPLOYED** |
| Dev environment | WSL2 Ubuntu + VS Code |

---

## The CDS Formula — Core of the System

```
CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)

NER = failed_submissions ÷ class_max_failed     [Altadmri & Brown, 2015]
NRS = total_submissions  ÷ class_max_total      [Ahadi et al., 2016]
NTS = time_spent_seconds ÷ time_limit_seconds   [Leinonen et al., 2021]

Classification:
  0.00 – 0.33 → Low (green)
  0.34 – 0.66 → Moderate (amber)
  0.67 – 1.00 → High (red)
```

### Current Implementation Status

✅ **Basic Formula Implemented** in [backend/services/cdsEngine.js:10-90](backend/services/cdsEngine.js)

⚠️ **Missing Safeguards:**
- ❌ Blank submission detection (uses `code=''` check, should compare to `starter_code`)
- ✅ Safe denominator: `Math.max(classMax, 1)` implemented
- ❌ Outlier capping (mean + 2σ) not implemented
- ❌ Post-solution cutoff (count only up to first Accepted) not implemented
- ❌ Minimum class size check (<3 = low reliability flag) not implemented
- ❌ Active time only (currently uses `time_spent_seconds` without pause logic) — requires frontend Page Visibility API
- ❌ Hardcoded exclusion (requires AST/CodeNet to detect)

### Critical Run vs Submit Distinction

| Action | Saved to DB | Counts in NER/NRS | Test cases used |
|---|---|---|---|
| ▶ Run | ❌ Never | ❌ Never | First visible TC only |
| Submit → | ✅ Always | ✅ Always | ALL TCs including hidden |

**Implementation:** ✅ Implemented correctly
- Run endpoint: [backend/controllers/submissionController.js:5-29](backend/controllers/submissionController.js)
- Submit endpoint: [backend/controllers/submissionController.js:32-87](backend/controllers/submissionController.js)

---

## Code Structure Checking — AST + CodeNet (PLANNED, NOT YET IMPLEMENTED)

**Status:** ❌ Not implemented  
**Files:** Need to create `backend/services/astVerifier.js` and `backend/scripts/ingestCodeNet.js`  
**Planned:** Deterministic validation using tree-sitter + IBM Project CodeNet (no AI)  

### Design (from IMPLEMENTATION_PLAN.md)

**Tool:** tree-sitter (C++ grammar)  
**Dataset:** Filtered CodeNet (~15k intro-level solutions from 14M total)  
**Four Layers:**
1. Presence: Required AST node exists
2. Non-empty body: Construct has statements
3. Variable usage: Uses variables, not just constants
4. Output dependency: Affects cout
5. CodeNet patterns: Matches known novice mistakes

**Required AST Nodes per Concept:**
```javascript
{
  'Conditionals': ['if_statement', 'switch_statement'],
  'Loops':        ['for_statement', 'while_statement', 'do_statement'],
  'Functions':    ['function_definition'],
  'Arrays':       ['array_declarator', 'subscript_expression'],
  'OOP':          ['class_specifier'],
  'Datatypes':    [], // no structural requirement
  'Variables':    [] // no structural requirement
}
```

**Verification Flow:**
1. Parse code with tree-sitter
2. Check required nodes exist
3. Canonize AST (strip identifiers/literals)
4. Hash → lookup in CodeNet patterns
5. If no match, compute similarity
6. Return `{valid: true/false, message, layer, pattern}`

**Database Changes Needed:**
- ALTER `submissions`: ADD `is_verified BOOLEAN DEFAULT true`, ADD `verification_note TEXT`
- CREATE `verification_logs` table (submission_id, verification_type, reason, line_number, etc.)
- CREATE `ast_templates` table (ast_hash, node_types, concept_id, canonical_string, source)

---

## AI Integration — PLANNED, NOT YET IMPLEMENTED

**Status:** ❌ Not implemented  
**Files:** Need `backend/services/aiReviewer.js` and `backend/services/classMcdReport.js`

AI is **NOT** used for code structure checking or anti-cheating. Only for two specific pedagogical purposes:

### Use Case 1 — Micro-Concept Feedback (per student, async)

**Trigger:** After submission saved, run in background  
**Output:**
```json
{
  "microConceptDifficulty": "exact sub-concept or operator confused",
  "evidence": "exact wrong line from submission and why it is wrong",
  "instructorNote": "specific named teaching technique"
}
```
**Display:** Appears in alert card for High/Moderate CDS students

### Use Case 2 — Class-Wide MCD Report (after exercise close)

**Trigger:** After batch CDS computation completes  
**Output:**
```json
{
  "mostCommonIssue": "most frequent specific mistake",
  "affectedCount": 14,
  "affectedPercent": 47,
  "secondIssue": "second most common or empty string",
  "secondCount": 6,
  "classSummary": "2-3 sentences on class-wide pattern",
  "rootCause": "gap in prior instruction that caused this",
  "recommendedAction": "specific concrete teaching technique",
  "beforeAdvancing": "what to verify before moving to next concept"
}
```
**Display:** Report card on instructor analytics dashboard

**Models:** OpenRouter (NVIDIA Nemotron 3 Super 120B / Step 3.5 Flash — free tier)  
**Fallback:** Anthropic Claude 3 Haiku (paid, ~₱60 per evaluation)

---

## Database Schema (Current State)

### Tables (9 total)

```sql
-- 1. users
id (SERIAL PK) | name | email (UNIQUE) | password_hash (bcrypt) | role ('instructor'|'student') | created_at

-- 2. sections
id (SERIAL PK) | name | course_code | school_year | instructor_id (FK→users) | created_at

-- 3. enrollments
id (SERIAL PK) | student_id (FK→users) | section_id (FK→sections) | enrolled_at
UNIQUE(student_id, section_id)

-- 4. concepts
id (SERIAL PK) | name (UNIQUE) | ast_nodes (TEXT[]) -- for future AST verification
-- Seeded: Datatypes, Variables, Conditionals, Loops, Functions, Arrays, OOP

-- 5. exercises
id (SERIAL PK) | title | description | concept_id (FK) | section_id (FK) | created_by (FK)
time_limit_minutes (DEFAULT 45) | test_cases (JSONB) | deadline | is_draft (DEFAULT false)
track_ner (DEFAULT true) | track_nrs (DEFAULT true) | track_nts (DEFAULT true)
auto_alert (DEFAULT true) | closed_at (TIMESTAMP) | created_at
-- ❌ MISSING: starter_code column (frontend expects it)

-- 6. submissions
id (SERIAL PK) | student_id (FK) | exercise_id (FK) | code (TEXT)
test_results (JSONB DEFAULT '[]') | passed (BOOLEAN DEFAULT false)
cds | ner | nrs | nts (DECIMAL 6,4 all DEFAULT 0)
attempt_number (INT DEFAULT 1) | time_spent_seconds (INT DEFAULT 0) | created_at
-- ❌ MISSING: is_verified, verification_note (for AST layer)

-- 7. cds_scores
id (SERIAL PK) | student_id (FK) | exercise_id (FK) | section_id (FK)
ner | nrs | nts | cds (DECIMAL 6,4) | classification (VARCHAR 20: 'Low'|'Moderate'|'High'|'Unscored')
computed_at (DEFAULT NOW())
UNIQUE(student_id, exercise_id)

-- 8. alerts
id (SERIAL PK) | student_id (FK) | exercise_id (FK) | section_id (FK)
cds_score | classification | concept_name | is_reviewed (DEFAULT false) | created_at
UNIQUE(student_id, exercise_id)

-- 9. (PLANNED) verification_logs
-- NOT YET CREATED: id | submission_id | student_id | exercise_id | verification_type | reason | node_found | node_expected | line_number | column_number | created_at

-- 10. (PLANNED) ast_templates
-- NOT YET CREATED: id | problem_id | ast_hash | node_types | canonical_string | concept_id | source | solution_quality_score | difficulty_level | correct_solution | codenet_snapshot_date | version_number | created_at
```

---

## Backend Architecture (Current State)

### Directory Structure
```
backend/
├── server.js                    # Express app initialization
├── migrations.js                # Database schema check
├── schema.sql                   # Current schema (9 tables)
├── package.json
├── config/
│   └── db.js                   # PostgreSQL connection pool
├── middleware/
│   └── auth.js                 # JWT verification + role check
├── controllers/
│   ├── authController.js       # register, login, me
│   ├── exerciseController.js   # CRUD + close exercise
│   ├── sectionController.js    # sections + enrollment
│   ├── submissionController.js # run, submit, history
│   └── analyticsController.js  # heatmap, alerts, live ranking
├── services/
│   ├── executor.js             # GCC compilation + execution ✅
│   ├── cdsEngine.js            # CDS calculation ⚠️ (has bugs)
│   └── alertEngine.js          # Alert generation ✅
└── routes/
    ├── auth.js                 # /api/auth/*
    ├── exercises.js            # /api/exercises/*
    ├── sections.js             # /api/sections/*
    ├── student.js              # /api/student/exercises, /run, /submit
    ├── submissions.js          # /api/submissions/*
    └── analytics.js            # /api/analytics/*
```

### Core Services Status

#### ✅ **executor.js** — Fully Implemented
- Safety: Blocks dangerous system calls (`system`, `exec`, `fork`, `popen`, `unlink`, `rmdir`)
- Compilation: `g++ -std=c++17` with error parsing
- Execution: `timeout` command for time limits, stdin handling
- Cleanup: `/tmp/ci_{timestamp}_{random}/` removed after execution
- File: [backend/services/executor.js](backend/services/executor.js)

#### ⚠️ **cdsEngine.js** — Implemented but has known bugs
- ✅ Basic formula: NER (0.40) + NRS (0.35) + NTS (0.25)
- ✅ Safe denominator: `Math.max(classMax, 1)`
- ✅ Blank detection exists but BROKEN: checks `code=''` instead of comparing to `starter_code`
- ❌ Missing outlier capping: no `mean + 2*stddev` cap
- ❌ Missing post-solution cutoff: counts all submissions, even after first Accepted
- ❌ Missing edge case: `nts >= 0.9 && successCount === 0` should force High
- ❌ No minimum class size check
- File: [backend/services/cdsEngine.js](backend/services/cdsEngine.js)

#### ✅ **alertEngine.js** — Fully Implemented
- Generates alerts when CDS > 0.66 on exercise close
- Inserts into `alerts` table with `is_reviewed=false`
- File: [backend/services/alertEngine.js](backend/services/alertEngine.js)

---

## Frontend Architecture (Current State)

### Directory Structure
```
frontend/
├── package.json
├── vite.config.js
├── index.html
└── src/
    ├── main.jsx                 # React entry
    ├── App.jsx                  # Routes + ProtectedRoute
    ├── index.css                # Global dark theme styles
    ├── context/
    │   ├── AuthContext.jsx      # User + JWT state management
    │   └── SidebarContext.jsx   # Sidebar toggle
    ├── components/
    │   ├── ErrorBoundary.jsx
    │   ├── Layout.jsx           # Wraps content with Sidebar
    │   └── Sidebar.jsx          # Role-based navigation
    ├── pages/
    │   ├── Login.jsx
    │   ├── instructor/
    │   │   ├── Dashboard.jsx      # Stats + heatmap
    │   │   ├── Sections.jsx       # Section cards + activity
    │   │   ├── SectionDetail.jsx  # Section view (heatmap)
    │   │   ├── CreateExercise.jsx # Exercise form
    │   │   ├── Alerts.jsx         # Alert management
    │   │   ├── Analytics.jsx      # Heatmap visualization
    │   │   └── Developer.jsx      # Dev tools
    │   └── student/
    │       ├── ExerciseList.jsx   # Exercise cards
    │       ├── CodeEditor.jsx     # Monaco + test runner ⚠️ (CodeEditor_new.jsx also exists)
    │       └── Progress.jsx       # Student CDS scores
    └── services/
        └── api.js                 # Axios with JWT interceptor
```

### Key Components Status

#### ✅ **AuthContext.jsx** — Implemented
- JWT storage in `localStorage` (`ci_token`, `ci_user`)
- Auto-attach Authorization header via axios interceptor
- 401 handling: clears storage, redirects to login
- Role-based route protection

#### ✅ **CodeEditor.jsx** — Implemented with starter_code bug
- Monaco Editor integration (C++ language, dark theme)
- **Bug:** Uses `exerciseData.starter_code` but database doesn't have that column ([frontend/src/pages/student/CodeEditor.jsx:56](frontend/src/pages/student/CodeEditor.jsx))
- **Fallback:** Hardcoded default if `starter_code` undefined
- Run: calls `/api/student/exercises/:id/run` (first visible test, no save)
- Submit: calls `/api/student/exercises/:id/submit` (all tests, saved)
- Time tracking: `exerciseStartTimeRef` → `timeSpentSeconds` on submit
- ❌ Missing: Page Visibility API to pause timer on tab hide
- Tabs: Output, Compiler Log, Previous Attempts

---

## API Endpoints (Current Implementation)

### Authentication
```
POST /api/auth/register    {name, email, password, role} → {token, user}
POST /api/auth/login       {email, password}           → {token, user}
GET  /api/auth/me          → {id, name, email, role}  (JWT required)
```

### Sections
```
POST   /api/sections               {name, course_code, school_year} → (instructor only)
GET    /api/sections               → Array of sections (with metrics for instructors)
GET    /api/sections/:id          → section details
POST   /api/sections/:id/enroll   {studentIds[], emails[]} → (instructor only)
```

### Exercises
```
GET    /api/exercises/concepts    → [{id, name, ast_nodes}]
POST   /api/exercises             {title, description, concept_name, section_id, time_limit_minutes, test_cases, deadline, is_draft, track_ner, track_nrs, track_nts, auto_alert}
GET    /api/exercises             → filtered by role (instructor: own; student: enrolled sections)
GET    /api/exercises/:id         → exercise with test_cases (filtered hidden for students)
PUT    /api/exercises/:id         → update (instructor only, owns exercise)
POST   /api/exercises/:id/close   → sets closed_at, triggers computeBatchCDS()
```

### Student Routes (under /api/student)
```
GET    /api/student/exercises              → student's exercises from enrolled sections
GET    /api/student/exercises/:id         → exercise details (student view)
GET    /api/student/exercises/:id/attempts → submission history
POST   /api/student/exercises/:id/run     {code} → quick test (unsaved)
POST   /api/student/exercises/:id/submit  {code, timeSpentSeconds} → save + test all
```

### Submissions
```
POST   /api/submissions/run     {exerciseId, code} → test run (unsaved)
POST   /api/submissions/submit  {exerciseId, code, timeSpentSeconds} → save submission
GET    /api/submissions/:exerciseId/my           → student's submissions
GET    /api/submissions/:studentId/:exerciseId  → instructor view
```

### Analytics
```
GET    /api/analytics/heatmap/:sectionId         → heatmap data (instructor only)
GET    /api/analytics/alerts/:sectionId          → unreviewed alerts (instructor only)
PUT    /api/analytics/alerts/:alertId/review    → mark alert reviewed
GET    /api/analytics/live/:exerciseId          → live peer ranking during exercise
GET    /api/analytics/student/:studentId/profile → all CDS scores for student
GET    /api/analytics/my-scores                  → student's own scores
GET    /api/analytics/activity/:sectionId        → last 5 alerts (activity feed)
```

---

## Data Flow Examples

### Student Submits Code
```
1. Student writes code in Monaco Editor
2. Clicks "Run" → POST /api/student/exercises/:id/run {code}
   → Backend runs first visible test case only
   → Returns test result (unsaved)
   → Frontend shows Pass/Fail

3. Clicks "Submit" → POST /api/student/exercises/:id/submit {code, timeSpentSeconds}
   → Backend gets next attempt_number
   → Run ALL test cases (including hidden if present)
   → Save to submissions table
   → Return: {attemptNumber, allPassed, results[]}

4. Instructor later closes exercise
   → computeBatchCDS() runs for all students
   → Student gets CDS score in heatmap
   → If CDS > 0.66, alert generated
```

### Exercise Closing & CDS Computation
```
Instructor: POST /api/exercises/:id/close
  ↓
Backend:
  1. UPDATE exercises SET closed_at=NOW() WHERE id=$1
  2. Call cdsEngine.computeBatchCDS(exerciseId)
     ├─ Get all students in section
     ├─ Get all submissions for exercise
     ├─ Calculate class maximums: maxFailed, maxTotal
     ├─ For each student:
     │  ├─ Compute NER = failed / maxFailed
     │  ├─ Compute NRS = total / maxTotal
     │  ├─ Compute NTS = max_time / timeLimitSeconds
     │  ├─ CDS = 0.40×NER + 0.35×NRS + 0.25×NTS
     │  ├─ Classify (Low/Moderate/High/Unscored)
     │  └─ UPSERT to cds_scores
     └─ Call alertEngine.generateAlerts()
         └─ Insert alerts for CDS > 0.66 students
  ↓
Instructor sees: "Exercise closed. CDS computed for X students"
```

---

## Known Limitations & Workarounds

### 1. Starter Code Missing from Database
**Problem:** Frontend expects `exercise.starter_code`, but column doesn't exist in `exercises` table.  
**Current Workaround:** Frontend uses hardcoded default: `#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}`  
**Impact:** All exercises share same starter code; cannot customize per exercise.  
**Fix:** Add `starter_code` column to `exercises` table (TEXT, DEFAULT value = standard template).

### 2. Blank Detection Broken
**Problem:** `cdsEngine.js` line 47 checks `WHERE code=''`, but actual submissions include template code.  
**Impact:** Blank/template-only submissions get normal CDS instead of forced High.  
**Fix:** Change to `WHERE code = (SELECT starter_code FROM exercises WHERE id=$1) OR code=''`.

### 3. Hidden Test Cases Not Properly Enforced
**Problem:** `executor.runAgainstTestCases()` runs ALL tests but doesn't separate visible/hidden results.  
**Impact:** Student might see hidden test inputs/outputs in error messages?  
**Fix Needed:** Separate execution:
```javascript
const visible = testCases.filter(tc => !tc.hidden);
const hidden = testCases.filter(tc => tc.hidden);
// Run visible → show results
// Run hidden → only affect allPassed, don't show individual
```

### 4. No Tab Visibility Tracking
**Problem:** `timeSpentSeconds` counts all elapsed time, even when student switches to YouTube.  
**Impact:** Inflated NTS for distracted students.  
**Fix Needed:** Frontend: Page Visibility API → track `pausedTimeSeconds`. Send `activeTimeSeconds` instead of raw elapsed.

### 5. CDS Computation Oversight
**Missing:**
- Outlier capping (mean + 2σ)
- Post-solution cutoff (first Accepted only)
- Minimum class size check (<3 submissions → warn)
- Edge case escalation (NTS ≥ 0.9 + zero successes → force High)

---

## Testing Credentials

```
Instructor: instructor@psu.edu / password123
Student 1:  maria@student.psu.edu / password123
Student 2:  jose@student.psu.edu / password123
Student 3:  ana@student.psu.edu / password123
```

---

## Development Setup

### Backend
```bash
cd backend
npm install
# Configure .env: DB_HOST, DB_PORT, DB_NAME, DB_USER, DB_PASSWORD, JWT_SECRET, PORT=5000
npm run dev  # nodemon on port 5000
```

### Frontend
```bash
cd frontend
npm install
npm run dev  # Vite on port 5173
```

### Database
```bash
createdb codeinsight
psql -U postgres -d codeinsight -f backend/schema.sql
```

---

## Related Documentation

- [CODEBASE_OVERVIEW.md](CODEBASE_OVERVIEW.md) — Comprehensive system architecture (may include planned features)
- [FullFeatureDescription.md](FullFeatureDescription.md) — Full feature spec (includes future vision)
- [IMPLEMENTATION_PLAN.md](IMPLEMENTATION_PLAN.md) — Detailed roadmap with Phase 1/2/3 tasks
- [TODO.md](TODO.md) — CDS safety measures and implementation checklist
- [DEPLOYMENT.md](DEPLOYMENT.md) — Oracle Cloud deployment instructions
- [README.md](README.md) — Quick start guide

---

## Memory System Context

This CLAUDE.md is the **authoritative reference** for the current implementation state. When I need to understand:

- ✅ What exists NOW → read this file's "CURRENT IMPLEMENTATION STATUS" sections
- 🚧 What needs fixing → read "KNOWN GAPS & BUGS"
- 🔮 What's planned → read "NOT YET IMPLEMENTED" and [IMPLEMENTATION_PLAN.md](IMPLEMENTATION_PLAN.md)
- 📊 How systems connect → read "Tech Stack", "Architecture", "Data Flow"

**Do not assume a feature exists just because it's in the vision document. Always check this file's "Implemented" checklist first.**

---

## Last Updated

**March 31, 2026** — Consolidated from codebase analysis (backend v1.0 + frontend v1.0)  
**Next Review:** After implementing Phase 1 fixes (blank detection, starter_code column, edge cases)

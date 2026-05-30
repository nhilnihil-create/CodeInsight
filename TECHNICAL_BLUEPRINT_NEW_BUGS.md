# 🏗️ Technical Blueprint: 4 New Critical Bugs

**Analysis Date**: May 30, 2026  
**Status**: ARCHITECTURAL PLANNING ONLY (NO CODE CHANGES)  
**User Role**: Principal Full-Stack Architect

---

## Executive Summary

4 new bugs have been identified, distinct from the previous 4 bugs. These issues involve:
1. Summary card logic (always shows regardless of success/failure)
2. Exercise edit redirect bug
3. Run/Submit mismatch persisting (hidden test issue)
4. No exercise completion lock (students can reopen completed exercises)

---

## 🔍 ROOT CAUSE ANALYSIS

### BUG 1: Summary Card Always Appears (Regardless of Pass/Fail)

**Current Behavior**:
```
Student submits code → setShowSummaryModal(true) → Summary always displayed
                    ↑
            Always set to true
```

**Root Cause**:
- Line in `CodeEditor_new.jsx` (handleSubmit):
  ```javascript
  setSessionState(SESSION_STATES.COMPLETED);
  setShowSummaryModal(true);  // ← ALWAYS true, no condition on testResults.passed
  ```
- **Problem**: Modal triggered unconditionally after ANY submit (pass or fail)
- **Expected**: Only show summary on **success** or **time expiration**, NOT on failure

**Why This Breaks Expected Flow**:
1. Student submits WRONG code → Summary card shows → Student exits
2. Student submits CORRECT code → Summary card shows → Expected
3. No "try again" for failures → **Bad UX**

**Data Flow Issue**:
```
API Response (pass: true/false) → NOT CHECKED IN STATE MACHINE
                    ↓
Frontend still shows summary regardless
```

---

### BUG 2: Exercise Edit Redirects to Dashboard

**Current Behavior**:
```
Instructor clicks "Edit" → Navigates to EditExercise.jsx → 
Error in fetch → navigate('/instructor') → **Redirects to Dashboard**
```

**Root Cause** (EditExercise.jsx lines 25-46):
```javascript
useEffect(() => {
  const fetchExercise = async () => {
    try {
      const res = await axios.get(`/api/exercises/${id}`);  // ← GET without JWT?
      setExercise(res.data);
      // ...
    } catch (err) {
      console.error(err);
      navigate('/instructor');  // ← Navigates on ANY error
    }
  };
  if (id) fetchExercise();
}, [id, navigate]);
```

**Problems**:
1. **Missing JWT Token**: `axios.get()` called WITHOUT `Authorization` header
   - API requires `verifyToken` middleware
   - Request fails with 401 → caught in catch block
   - Redirects to `/instructor` instead of showing error

2. **No Error Boundary**: All errors → same redirect
   - Even network errors redirect
   - No differentiation between 401, 404, 500

3. **Inconsistent API Usage**: 
   - Uses `axios` directly instead of `api` (which has JWT interceptor)
   - Compare: `api.get()` automatically attaches JWT
   - This file uses bare `axios.get()` → no auth headers

**Data Flow Failure**:
```
EditExercise.jsx
    ↓
axios.get('/api/exercises/:id')  [NO JWT]
    ↓
Backend: verifyToken middleware → 401 Unauthorized
    ↓
Frontend catch block → navigate('/instructor')
    ↓
Redirects away (BUG!)
```

---

### BUG 3: Run Passes, Submit Fails (Hidden Test Issue Persists)

**Current Behavior**:
```
Student writes correct code (sum of 1..n)
    ↓
Click Run → Only visible test (n=5, expected=15) → PASS ✓
    ↓
Click Submit → ALL tests including hidden (n=10, expected=55) → FAIL ✗
```

**Root Cause** (Two-layer issue):

**Layer 1: API Response Masking Problem**
- File: `backend/routes/student.js` (lines 143-158)
- Code:
  ```javascript
  allResults = await runAgainstTestCases(code, allTestCases, ..., false);
  passed = allResults.every(r => r.passed);  // ← Checks ALL results
  visibleResults = allResults.filter(r => !r.hidden);  // ← Filters AFTER
  
  // BUT: Frontend receives:
  res.json({
    ...
    testResults: visibleResults,  // ← Only visible shown
    passed: passed,               // ← But passed is from ALL tests
    ...
  })
  ```

**Problem**: `passed` flag is calculated from ALL tests, but student sees only VISIBLE results
- Student sees: "Test 1: PASS (n=5)" 
- But `passed = false` because hidden test (n=10) failed
- **Mismatch**: UI shows pass, but submission marked as fail

**Layer 2: Test Case Execution Issue**
- File: `backend/services/executor.js`
- Possible issue: Hidden test case not parsed correctly
  - If `tc.hidden` is not being respected, hidden tests might have wrong values
  - Or: JSON parsing of test_cases in database not working for all cases

**Data Flow**:
```
POST /submit
    ↓
Backend: Get ALL tests (visible + hidden)
    ↓
Run code against ALL tests
    ↓
Calculate passed = allResults.every(r => r.passed)
    ↓
Return {
  testResults: [visible only],  ← Student sees
  passed: false,                 ← From hidden tests failing
  ...
}
    ↓
Frontend sees mismatch:
  - testResults shows PASS
  - passed = false
  - Confusion!
```

**Why Test Case Data Mismatch**:
- If hidden test case data is incorrect in database (wrong input/output)
- Or if `maskHidden` parameter not properly handled
- Hidden test fails → `passed = false` → Student sees "FAIL" despite visible test passing

---

### BUG 4: No Exercise Completion Lock (Student Can Reopen Completed Exercise)

**Current Behavior**:
```
1. Student completes exercise (correct code)
2. Exits summary card
3. Navigates back to exercise list
4. **Can click the same exercise AGAIN** ← BUG!
5. Starts from scratch (can do it again)
```

**Root Cause**:
1. **No `is_completed` or `submission_status` column** in submissions/exercises
2. **No check in backend** to prevent re-opening completed exercise:
   - File: `backend/routes/student.js` (lines 31-56)
   - GET `/exercises/:id` returns exercise without checking completion status
   - No logic: "if exercise already completed, return completion summary"

3. **No check in frontend**:
   - CodeEditor_new.jsx fetchExercise() doesn't check prior submissions
   - Doesn't prevent entering IN_PROGRESS state if already completed

4. **No database tracking**:
   - `submissions` table has no `is_completed` flag
   - `exercises` has no `is_completed_by_student` field
   - Need a way to query: "Has THIS student completed THIS exercise?"

**Data Model Gap**:
```
submissions table:
├─ id
├─ exercise_id
├─ student_id
├─ code
├─ is_correct (true if passed all tests)
├─ test_results
├─ attempt_number
├─ time_spent_seconds
└─ ❌ NO: is_completed, is_final_submission

Query needed:
SELECT * FROM submissions 
WHERE exercise_id = $1 AND student_id = $2 AND is_correct = true
LIMIT 1;

If found: Exercise is completed → Don't allow re-entry
```

**Frontend State Gap**:
```
fetchExercise() {
  // Get exercise details
  // ❌ Missing: Check if student already completed
  //    const completedSubmission = await api.get(`/api/submissions/${exerciseId}/completed`);
  //    if (completedSubmission) → Show summary instead of editor
}
```

---

## 🎯 CONCEPTUAL STATE MACHINE

### Current (Broken) State Machine

```
INITIAL
    ↓
READY_PENDING ← Student confirms
    ↓
IN_PROGRESS ← Timer starts
    ↓
COMPLETED ← After ANY submit (BUG!)
    ↓
SUMMARY ← Always show (BUG!)
```

### Desired (Fixed) State Machine

```
INITIAL
    ├─→ [Check if completed] ──YES──→ SUMMARY_FINAL (show locked card)
    │                          NO
    └─→ READY_PENDING
            ↓
        [Student confirms]
            ↓
        IN_PROGRESS
            ├─→ [Time expires] ──→ COMPLETED_TIMEOUT
            │
            ├─→ [Submit (PASS)] ──→ COMPLETED_SUCCESS ──→ SUMMARY
            │                           
            └─→ [Submit (FAIL)] ──→ IN_PROGRESS (stay, don't exit)
                                      ↑
                                  Try again

COMPLETED_SUCCESS
    └─→ SUMMARY ──→ [Exit] ──→ LOCKED

COMPLETED_TIMEOUT  
    └─→ SUMMARY_TIMEOUT ──→ [Exit] ──→ LOCKED

LOCKED (Final state, no re-entry)
    └─→ [Attempt re-open] ──→ Show SUMMARY_FINAL (locked card)
```

### Key Differences

| Event | Current | Desired |
|-------|---------|---------|
| Submit FAIL | → SUMMARY (show) | → IN_PROGRESS (stay, no exit) |
| Submit PASS | → SUMMARY (show) | → COMPLETED_SUCCESS → SUMMARY |
| Time expires | No handling | → COMPLETED_TIMEOUT → SUMMARY_TIMEOUT |
| Re-open after complete | → IN_PROGRESS again | → SUMMARY_FINAL (locked) |
| Exit summary | → CLOSED | → LOCKED (never re-enter) |

---

## 📊 DATA FLOW DIAGRAM

### Current Flow (Broken)

```
┌─ Frontend ──────────────────────────────┐
│  CodeEditor_new.jsx                     │
│  ├─ fetchExercise()                     │
│  │  └─ No completion check              │
│  ├─ handleSubmit()                      │
│  │  ├─ POST /submit                     │
│  │  └─ setShowSummaryModal(true)  ← BUG!│
│  └─ SummaryModal (always shows)         │
└─────────────────────────────────────────┘
           ↓ API Call
┌─ Backend ───────────────────────────────┐
│  routes/student.js                      │
│  ├─ GET /exercises/:id                  │
│  │  └─ No completion lock check         │
│  └─ POST /submit                        │
│     ├─ Run ALL tests                    │
│     ├─ passed = ALL.every()             │
│     ├─ Return visible results only      │
│     ├─ Store in submissions             │
│     └─ ❌ No update to completion flag   │
└─────────────────────────────────────────┘
           ↓ Data
┌─ Database ───────────────────────────────┐
│  submissions                            │
│  ├─ is_correct ✓                        │
│  ├─ test_results ✓                      │
│  └─ ❌ No is_completed flag             │
│  exercises                              │
│  ├─ title ✓                             │
│  └─ ❌ No student_completed field       │
└──────────────────────────────────────────┘
```

### Desired Flow (Fixed)

```
┌─ Frontend ──────────────────────────────────────┐
│  CodeEditor_new.jsx                            │
│  ├─ fetchExercise()                            │
│  │  ├─ Get exercise details                    │
│  │  └─ ✓ Check if student completed           │
│  │      └─ If yes → SUMMARY_FINAL (locked)    │
│  ├─ handleSubmit()                             │
│  │  ├─ POST /submit                           │
│  │  ├─ Check res.passed                       │
│  │  ├─ If YES → COMPLETED_SUCCESS             │
│  │  │   └─ setShowSummaryModal(true)          │
│  │  └─ If NO → Stay IN_PROGRESS              │
│  │      └─ showErrorMessage("Try again")      │
│  └─ timeoutHandler()                           │
│     └─ On timer=0 → COMPLETED_TIMEOUT        │
│        └─ setShowSummaryModal(timeout_card)   │
└──────────────────────────────────────────────────┘
           ↓ API Call
┌─ Backend ──────────────────────────────────────┐
│  routes/student.js                            │
│  ├─ GET /exercises/:id                        │
│  │  ├─ Check if student completed            │
│  │  ├─ If completed: return { is_completed } │
│  │  └─ Don't return full exercise data        │
│  └─ POST /submit                              │
│     ├─ Run ALL tests                          │
│     ├─ If PASS:                               │
│     │  ├─ Mark in database as completed      │
│     │  ├─ Return { passed: true }            │
│     │  └─ Include completion timestamp       │
│     └─ If FAIL:                               │
│        └─ Return { passed: false }           │
│           └─ NO completion marking           │
└──────────────────────────────────────────────────┘
           ↓ Data
┌─ Database ──────────────────────────────────────┐
│  submissions                                   │
│  ├─ is_correct ✓                              │
│  ├─ ✓ is_completed (true when passed)        │
│  └─ test_results ✓                            │
│                                               │
│  Query: Check completion                     │
│  SELECT * FROM submissions                  │
│  WHERE exercise_id = $1                     │
│    AND student_id = $2                      │
│    AND is_correct = true                    │
│  LIMIT 1                                     │
│  → If found: Student completed              │
└──────────────────────────────────────────────────┘
```

---

## ✅ IMPLEMENTATION CHECKLIST

### LAYER 1: Database Schema Updates

- [ ] **submissions table**: No new columns needed (use existing `is_correct`)
  - Query: Check if `is_correct = true` for exercise → completion lock

### LAYER 2: Backend API Changes

#### File: `backend/routes/student.js`

- [ ] **GET /exercises/:id** (lines 31-56)
  - **Before**: Just return exercise details
  - **After**: 
    - Add check: Query submissions where `is_correct = true`
    - If found: Add `isCompleted: true` to response
    - If found: Add `completedSubmission` object (timestamp, score)
    - Backend signals: "This exercise is completed"

- [ ] **POST /submit** (lines 124-231)
  - **Before**: Always return success
  - **After**:
    - If `passed = false`: Return `{ passed: false }` (no summary trigger)
    - If `passed = true`: Return `{ passed: true, isCompleted: true }`
    - Backend signals: "This submission completed the exercise"

#### File: `backend/services/executor.js`

- [ ] **Verify maskHidden logic** (lines 136-160)
  - **Check**: When `maskHidden = false`, are ALL tests being executed?
  - **Check**: Is `hidden` flag being parsed correctly from test_cases JSONB?
  - **Verify**: Output masking only applies when `maskHidden = true`

---

### LAYER 3: Frontend State Management

#### File: `frontend/src/pages/student/CodeEditor_new.jsx`

- [ ] **Session State Machine** - Expand states
  - [ ] Add: `COMPLETED_SUCCESS` (passed, ready for summary)
  - [ ] Add: `COMPLETED_TIMEOUT` (time expired, show timeout summary)
  - [ ] Add: `COMPLETED_LOCKED` (exercise already done, no re-entry)
  - [ ] Rename: `COMPLETED` → `COMPLETED_SUCCESS` (for clarity)

- [ ] **fetchExercise()** (lines 93-130)
  - [ ] After GET `/exercises/:id`, check `res.data.isCompleted`
  - [ ] If `isCompleted = true`:
    - `setSessionState(SESSION_STATES.COMPLETED_LOCKED)`
    - `setShowSummaryModal(true)`
    - Show "Exercise Already Completed" card (no editing)
    - Disable Run/Submit buttons
    - Show timestamp of completion

- [ ] **handleSubmit()** (lines 177-210)
  - [ ] **NEW**: Check `res.data.passed` before showing summary
  - [ ] If `passed = true`:
    - `setSessionState(SESSION_STATES.COMPLETED_SUCCESS)`
    - `setShowSummaryModal(true)`
    - Show green success summary
  - [ ] If `passed = false`:
    - `setSessionState(SESSION_STATES.IN_PROGRESS)` ← STAY, DON'T EXIT
    - `setShowErrorMessage("Code execution failed. Try again!")`
    - DON'T show summary modal
    - DON'T transition states

- [ ] **Timer expiration handler** (NEW)
  - [ ] When `timeRemaining === 0`:
    - `setSessionState(SESSION_STATES.COMPLETED_TIMEOUT)`
    - `setShowSummaryModal(true)`
    - Show timeout summary card (red, "Time's up")
    - Disable editing

- [ ] **SummaryModal component** (lines 387-461)
  - [ ] Update to show:
    - Success card (green): Only when `passed = true`
    - Timeout card (red): When time expired
    - Locked card (gray): When already completed
  - [ ] Remove "Review the feedback" text (forces exit)
  - [ ] Add "Try Again" button for failures (if time remains)

- [ ] **Timer display** (lines 425-429)
  - [ ] **Check**: Timer visible in navbar (top right)
  - [ ] **Check**: Format is `HH:MM:SS` and counting down
  - [ ] **Check**: Color changes at <5 minutes (warning yellow)
  - [ ] **Check**: Color changes at <1 minute (error red)

- [ ] **handleExitExercise()** (lines 219-223)
  - [ ] After exit:
    - `setSessionState(SESSION_STATES.LOCKED)`
    - Navigate back to exercise list
    - Mark exercise as "completed" in list UI

---

### LAYER 4: Instructor Exercise Edit Fix

#### File: `frontend/src/pages/instructor/EditExercise.jsx`

- [ ] **Import fix** (line 1)
  - [ ] Change: `import axios from 'axios'`
  - [ ] To: `import api from '../../services/api'` (has JWT interceptor)

- [ ] **fetchExercise()** (lines 25-46)
  - [ ] Change: `axios.get()` → `api.get()` (lines 27)
  - [ ] Adds JWT token automatically

- [ ] **Error handling** (lines 43-46)
  - [ ] Better error handling:
    - Don't redirect on all errors
    - Show error toast/modal: "Failed to load exercise"
    - Only navigate if user confirms

---

### LAYER 5: Frontend UI Updates

#### File: `frontend/src/pages/student/CodeEditor_new.jsx`

- [ ] **SummaryModal variants**
  - [ ] **Success Card**: Green border, "✓ Correct!", show stats
  - [ ] **Timeout Card**: Red border, "✗ Time's Up!", show partial stats
  - [ ] **Locked Card**: Gray border, "✓ Already Completed", show prior stats
  - [ ] Only show "Exit Exercise" button on all cards

- [ ] **Error message display**
  - [ ] Add error toast below editor when submission fails
  - [ ] Message: "This test failed. Review the errors and try again."
  - [ ] Don't force exit

---

## 🔄 IMPLEMENTATION ORDER (Critical Path)

```
PHASE 1: Backend Logic (5 tasks)
├─ 1.1: Fix EditExercise.jsx (use api not axios)
├─ 1.2: Add isCompleted check in GET /exercises/:id
├─ 1.3: Add isCompleted response in POST /submit
├─ 1.4: Verify executor.js maskHidden behavior
└─ 1.5: Verify hidden test case parsing

PHASE 2: Frontend State Machine (3 tasks)
├─ 2.1: Expand SESSION_STATES enum
├─ 2.2: Update fetchExercise() completion lock
└─ 2.3: Update handleSubmit() conditional logic

PHASE 3: Frontend UI (4 tasks)
├─ 3.1: Enhance SummaryModal with variants
├─ 3.2: Add timer expiration handler
├─ 3.3: Fix timer display (navbar countdown)
└─ 3.4: Add error message display on failure

PHASE 4: Testing & Documentation (2 tasks)
├─ 4.1: Create test procedures for all 4 bugs
└─ 4.2: Document state machine transitions
```

---

## 🎯 EXPECTED OUTCOMES

### Bug 1: Summary Card Logic
- **Before**: Shows on every submit
- **After**: Shows ONLY on success or time expiration
- **Verification**: 
  - Submit wrong code → No summary, stay in editor
  - Submit correct code → Green summary
  - Time expires → Red summary

### Bug 2: Exercise Edit
- **Before**: Redirects to dashboard
- **After**: Shows edit form
- **Verification**:
  - Click edit → Form loads with exercise data
  - Make changes → Submit works
  - Navigate back → Returns to section detail

### Bug 3: Run/Submit Mismatch
- **Before**: Run passes, Submit fails
- **After**: Both consistent
- **Verification**:
  - Run with correct code → Pass
  - Submit same code → Pass (visible tests AND hidden tests pass)
  - Compiler tab shows no errors

### Bug 4: Exercise Reopening
- **Before**: Student can reopen completed exercise
- **After**: Cannot reopen, shows locked summary
- **Verification**:
  - Complete exercise with correct code
  - Exit and go back to exercise list
  - Click same exercise → Shows "Already Completed" card (locked)
  - Cannot edit or run code

---

## 🚨 CRITICAL DEPENDENCIES

- **Bug 1 depends on**: Bug 2 fix (need correct API responses)
- **Bug 3 depends on**: Verifying executor.js handles hidden tests correctly
- **Bug 4 depends on**: Bug 1 fix (need to detect completion)
- **All depend on**: Bug 2 (EditExercise must work for instructor to manage)

---

**Status**: ✅ ARCHITECTURAL ANALYSIS COMPLETE  
**Next Step**: User approval of this blueprint  
**Then**: Implementation phase (code changes only after approval)


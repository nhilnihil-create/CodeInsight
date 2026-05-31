# Manual Testing Guide — Session 288d1abf
## CodeInsight CDS Computation, Live Peer Ranking & Daily Fixes

**Date:** May 30-31, 2026  
**Focus:** CDS accuracy, live peer ranking, and verification of all Phase 6-7 fixes  
**Estimated Duration:** 45-60 minutes

---

## 🎯 Testing Objectives

1. ✅ **CDS Computation Accuracy** — Verify NER/NRS/NTS calculations are mathematically correct
2. ✅ **Live Peer Ranking** — Test that peer rankings update in real-time during exercise
3. ✅ **Performance** — Measure response times for batch CDS computation
4. ✅ **Phase 6 Fixes** — Verify API routes, enrollment, environment variables work
5. ✅ **Phase 7 Fixes** — Verify semester field is saved/displayed correctly
6. ✅ **Edge Cases** — Test boundary conditions (blank submissions, max time limit, hidden tests)

---

## 📋 TEST SETUP

### Prerequisites
- ✅ Backend running: `npm run dev` on :5000
- ✅ Frontend running: `npm run dev` on :5173
- ✅ Database: PostgreSQL running, seeded with test data
- ✅ Test Credentials Ready:
  - **Instructor:** `instructor@psu.edu` / `password123`
  - **Students:** `maria@student.psu.edu`, `jose@student.psu.edu`, `ana@student.psu.edu` / `password123`

### Database Reset (Optional)
If needed to start fresh:
```bash
cd backend
node test_db.js  # View current state
psql -U postgres -d codeinsight -c "DELETE FROM submissions; DELETE FROM enrollments; DELETE FROM sections;"
```

---

## 🧪 TEST SUITE 1: PHASE 6 API ROUTE FIXES

### Test 1.1: Environment Variable Fix (Vite)
**Objective:** Verify white screen crash is fixed (process.env → import.meta.env)

**Steps:**
1. Hard refresh frontend: `Ctrl+Shift+R` (not Ctrl+R)
2. Open browser console (F12)
3. Check for errors — should be NONE
4. You should see frontend load cleanly without white screen
5. Verify console shows NO `ReferenceError: process is not defined`

**Expected Result:** ✅ Frontend loads without errors, no console errors

---

### Test 1.2: API Base URL Double Path Fix
**Objective:** Verify baseURL is correctly set to server root, not `/api`

**Steps:**
1. Open network tab in browser DevTools (F12 → Network)
2. Refresh page
3. Look at API calls in network tab
4. Check URLs — they should be:
   - ✅ `http://localhost:5000/api/auth/me`
   - ✅ `http://localhost:5000/api/sections`
   - ❌ NOT `http://localhost:5000/api/api/auth/me` (double /api)
5. Try multiple endpoints by clicking around
6. All should work without 404 errors

**Expected Result:** ✅ All API calls use single `/api/` path, no double paths

**Verification Command:**
```bash
# In browser console:
fetch('http://localhost:5000/api/auth/me', {
  headers: { 'Authorization': `Bearer ${localStorage.getItem('ci_token')}` }
}).then(r => r.json()).then(console.log)
# Should return user object, not 404
```

---

### Test 1.3: Enrollment Endpoint Fix
**Objective:** Verify students can be enrolled into sections (endpoint has `/api/` prefix)

**Steps:**
1. Login as instructor: `instructor@psu.edu`
2. Go to "My Sections" page
3. Click on any section (e.g., "BSIT-3H")
4. Click "Enroll Students" button
5. Search for a student by email (e.g., `maria@student.psu.edu`)
6. Click checkbox to select student
7. Click "Enroll" button
8. Check for success message: "✓ Successfully enrolled 1 student(s)"
9. Check that the student appears in the section's student list

**Expected Result:** ✅ Enrollment succeeds, student appears in section, no 404 errors

**Verification:**
- Network tab should show POST to `/api/sections/{id}/enroll` (single /api)
- Response status: 200 or 201 (not 404)
- Student count badge increases

---

## 🧪 TEST SUITE 2: PHASE 7 SECTION FORM ENHANCEMENTS

### Test 2.1: Semester Field in Form
**Objective:** Verify semester dropdown appears in section creation form

**Steps:**
1. Login as instructor: `instructor@psu.edu`
2. Go to "My Sections" page
3. Scroll to "Create New Section" card
4. Verify form has 4 fields (previously had 3):
   - [ ] Section Name (text input)
   - [ ] Course Code (text input)
   - [ ] School Year (text input)
   - [ ] **Semester (dropdown)** ← NEW
5. Click on Semester dropdown
6. Verify options appear: "Sem 1", "Sem 2", "Summer"

**Expected Result:** ✅ All 4 fields present, semester dropdown functional with 3 options

---

### Test 2.2: Semester Field is Saved to Database
**Objective:** Verify semester value is persisted and displayed correctly

**Steps:**
1. In section creation form:
   - Section Name: `TEST-SEM1`
   - Course Code: `CS101`
   - School Year: `AY 2026-2027`
   - Semester: Select "Sem 1"
2. Click "Create Section" button
3. Wait for success message
4. New section card should appear
5. **Verify section card displays:** `AY 2026-2027 · Sem 1` (not hardcoded "Sem 2")
6. Refresh page (Ctrl+R)
7. Verify section still shows: `AY 2026-2027 · Sem 1` (persisted)
8. Repeat test with "Sem 2" and "Summer" options to verify each saves correctly

**Expected Result:** ✅ Semester value saved to database, displayed correctly, persists after refresh

**Database Verification:**
```bash
psql -U postgres -d codeinsight -c "SELECT id, name, semester FROM sections ORDER BY created_at DESC LIMIT 1;"
# Should show semester value (Sem 1, Sem 2, or Summer)
```

---

## 🧪 TEST SUITE 3: CDS COMPUTATION ACCURACY

### Test 3.1: Basic CDS Calculation
**Objective:** Verify CDS formula: (0.40×NER) + (0.35×NRS) + (0.25×NTS)

**Setup:**
1. Create exercise with simple problem (e.g., sum of n numbers)
2. Enroll 3 students: Maria, Jose, Ana
3. Have each student submit code:
   - **Maria:** 2 failed attempts, 3 total attempts, 20 min spent (limit 45 min)
   - **Jose:** 0 failed attempts, 1 total attempt, 5 min spent
   - **Ana:** 1 failed attempt, 2 total attempts, 15 min spent

**Steps:**
1. Login as Maria and submit code 3 times (first 2 wrong, 3rd correct)
   - Run: `cout << 5 << endl;` (hardcoded, fails)
   - Run: `cout << 6 << endl;` (hardcoded, fails)
   - Submit: Correct code that calculates sum
2. Close exercise as instructor: Click "Close Exercise"
3. Verify CDS appears in heatmap

**Expected CDS Calculation:**
```
Class maximums:
  - maxFailed = 2 (Maria had 2 failed attempts)
  - maxTotal = 3 (Maria had 3 total attempts)
  - maxTime = 20 min (Maria spent most time)

Maria's scores:
  - NER = 2/2 = 1.00 (2 failed / 2 max failed)
  - NRS = 3/3 = 1.00 (3 total / 3 max total)
  - NTS = 20/45 = 0.44 (20 min / 45 min limit)
  - CDS = (0.40×1.00) + (0.35×1.00) + (0.25×0.44)
  - CDS = 0.40 + 0.35 + 0.11 = 0.86 → HIGH (red)

Jose's scores:
  - NER = 0/2 = 0.00 (0 failed / 2 max failed)
  - NRS = 1/3 = 0.33 (1 total / 3 max total)
  - NTS = 5/45 = 0.11 (5 min / 45 min limit)
  - CDS = (0.40×0.00) + (0.35×0.33) + (0.25×0.11)
  - CDS = 0 + 0.115 + 0.0275 = 0.1425 → LOW (green)

Ana's scores:
  - NER = 1/2 = 0.50 (1 failed / 2 max failed)
  - NRS = 2/3 = 0.67 (2 total / 3 max total)
  - NTS = 15/45 = 0.33 (15 min / 45 min limit)
  - CDS = (0.40×0.50) + (0.35×0.67) + (0.25×0.33)
  - CDS = 0.20 + 0.235 + 0.0825 = 0.5175 → MODERATE (yellow)
```

**Verification:**
1. After closing exercise, go to Heatmap (Analytics page)
2. Find section and concept
3. Hover over each student's cell to see CDS score
4. **Maria's cell should be RED** with CDS ~0.86
5. **Jose's cell should be GREEN** with CDS ~0.14
6. **Ana's cell should be YELLOW** with CDS ~0.52
7. Verify values match expected calculations (allow ±0.01 rounding)

**Expected Result:** ✅ CDS values match mathematical formula, colors correct

---

### Test 3.2: Edge Case — Blank/Template Submission
**Objective:** Verify blank submissions are detected and forced to HIGH

**Setup:**
1. Create exercise (sum of n)
2. Enroll 1 student (Maria)

**Steps:**
1. Login as Maria
2. Submit without writing code (only template):
   ```cpp
   #include <iostream>
   using namespace std;
   
   int main() {
     // Write code here
     return 0;
   }
   ```
3. Should fail all tests
4. Close exercise as instructor
5. Check Maria's CDS in heatmap

**Expected Result:** ✅ Maria's CDS should be HIGH (red), even though she only had 1 attempt
**Reason:** Blank submission detection should override normal formula

**Verification:**
```bash
# Check submission in database
psql -U postgres -d codeinsight -c "
SELECT code, passed, ner, nrs, nts, cds FROM submissions 
WHERE student_id = (SELECT id FROM users WHERE email='maria@student.psu.edu') 
ORDER BY created_at DESC LIMIT 1;
"
# Code should be the template, passed=false, CDS should be HIGH
```

---

### Test 3.3: Edge Case — All Submissions Failed (NTS maxed)
**Objective:** Verify forced HIGH classification when NTS ≥ 0.9 and no successes

**Setup:**
1. Create exercise with 45-minute limit
2. Enroll 1 student (Jose)

**Steps:**
1. Login as Jose
2. Submit wrong code 15 times (each takes ~3 min)
   - Total time: ~43 min (close to 45 min limit)
   - Total attempts: 15
   - Failed attempts: 15 (all wrong)
3. Close exercise as instructor
4. Check Jose's CDS

**Expected Result:** ✅ Jose's CDS should be HIGH (even though NRS is high)
**Reason:** Edge case rule: if NTS ≥ 0.9 AND all submissions failed → force HIGH

---

### Test 3.4: Performance — Batch CDS Computation Time
**Objective:** Measure time to compute CDS for multiple students

**Setup:**
1. Create exercise
2. Enroll 10+ students
3. Have each submit code multiple times

**Steps:**
1. Open Network tab in DevTools
2. Prepare to close exercise
3. Click "Close Exercise" button
4. Note the Network tab — find POST to `/api/exercises/{id}/close`
5. Check response time in "Time" column
6. Expected: < 2 seconds for 10 students

**Expected Result:** ✅ Response time should be < 2 seconds (fast computation)

**Performance Benchmark:**
- 1 student: < 200ms
- 10 students: < 1s
- 50 students: < 5s

---

### Test 3.5: CDS Classification Ranges
**Objective:** Verify classification boundaries are correct

**Manual Classification Test:**

| CDS Score | Expected Classification | Color |
|-----------|------------------------|-------|
| 0.10 | LOW | 🟢 Green |
| 0.33 | LOW | 🟢 Green |
| 0.34 | MODERATE | 🟡 Yellow |
| 0.50 | MODERATE | 🟡 Yellow |
| 0.66 | MODERATE | 🟡 Yellow |
| 0.67 | HIGH | 🔴 Red |
| 0.85 | HIGH | 🔴 Red |
| 1.00 | HIGH | 🔴 Red |

**Verification:**
1. Create multiple exercises with known CDS values
2. Check heatmap colors match table above
3. Test boundary cases: 0.33, 0.34, 0.66, 0.67

**Expected Result:** ✅ All classifications and colors match table

---

## 🧪 TEST SUITE 4: LIVE PEER RANKING

### Test 4.1: Live Ranking Updates During Exercise
**Objective:** Verify live peer ranking shows real-time rankings as students submit

**Setup:**
1. Create exercise (e.g., "Sum of N")
2. Enroll 3 students: Maria, Jose, Ana
3. Set time limit to 45 minutes
4. **Do NOT close exercise yet** (live ranking only works during exercise)

**Steps:**
1. **Terminal 1 (Monitoring):** Login as instructor
   - Go to Section Detail → Live Rankings tab
   - You should see empty or starting rankings
2. **Terminal 2 (Student 1 - Maria):** Login as Maria
   - Start exercise, see timer start
   - Submit code that passes: `CDS = 0.0`
   - Check instructor's live ranking — Maria should appear with CDS 0.0
3. **Terminal 3 (Student 2 - Jose):** Login as Jose
   - Start exercise
   - Submit wrong code: `CDS = 0.9` (many retries)
   - Check instructor's live ranking — Jose should appear with CDS 0.9
   - Maria should still show 0.0
4. **Terminal 4 (Student 3 - Ana):** Login as Ana
   - Start exercise
   - Submit code that passes after 1 retry: `CDS = 0.3`
   - Check instructor's live ranking
   - Rankings should now show:
     - 1. Maria (CDS 0.0) ← Best performer
     - 2. Ana (CDS 0.3)
     - 3. Jose (CDS 0.9) ← Most struggling

**Expected Result:** ✅ Live rankings update in real-time as students submit, ordered by CDS (low to high)

**Network Verification:**
- Check Network tab during submissions
- Should see requests to `/api/analytics/live/{exerciseId}`
- Response should include all current student CDS scores

---

### Test 4.2: Live Ranking Disappears After Exercise Closes
**Objective:** Verify live ranking is replaced by final CDS heatmap after close

**Steps:**
1. With exercise still showing live rankings (from Test 4.1)
2. Close exercise as instructor: Click "Close Exercise"
3. Verify live ranking panel disappears or shows "Exercise Closed"
4. Check heatmap — final CDS scores should now appear
5. Scores should match live rankings from before close

**Expected Result:** ✅ Live ranking replaced by final heatmap, scores match

---

## 🧪 TEST SUITE 5: TIMER AND EXERCISE LIFECYCLE

### Test 5.1: Timer Countdown Accuracy
**Objective:** Verify timer displays correct time limit and counts down accurately

**Steps:**
1. Create exercise with 5-minute time limit
2. Enroll 1 student (Maria)
3. Login as Maria
4. Open exercise
5. Modal should appear: "Ready to Code? Yes/No"
6. Click "Yes"
7. Timer should start at 05:00
8. Verify countdown:
   - After 30 sec: 04:30
   - After 1 min: 04:00
   - After 2 min: 03:00
9. Verify timer updates every second (not stuck)

**Expected Result:** ✅ Timer shows correct limit, counts down accurately, updates every second

---

### Test 5.2: Page Visibility API (Tab Hidden)
**Objective:** Verify timer pauses when tab is hidden

**Steps:**
1. Create 10-minute exercise
2. Login as student, open exercise
3. Click "Ready to Code?"
4. Timer should show 10:00
5. Let it count down to 09:30 (30 seconds elapsed)
6. Switch to another browser tab (YouTube, Gmail, etc.)
7. Wait 30 seconds in other tab
8. Switch back to CodeInsight tab
9. **Timer should still show ~09:30** (paused, not advanced to ~09:00)

**Expected Result:** ✅ Timer pauses when tab hidden, resumes when tab active

---

### Test 5.3: Exercise Lock After Submission
**Objective:** Verify exercise locks after first successful submission

**Steps:**
1. Create exercise
2. Enroll 1 student (Maria)
3. Login as Maria, open exercise
4. Submit correct code
5. Summary card should appear with stats
6. Try to click "Code Again" or re-open editor
7. Should see message: "✓ Complete - This exercise has been completed"
8. Verify student cannot edit code anymore

**Expected Result:** ✅ After successful submission, exercise shows completion state and cannot be re-entered

---

## 🧪 TEST SUITE 6: HIDDEN TEST CASES

### Test 6.1: Hidden Tests Don't Leak to Student
**Objective:** Verify hidden test cases don't appear in student output

**Setup:**
1. Create exercise with 2 visible tests + 2 hidden tests:
   ```
   Visible Test 1: Input 5, Output 15
   Visible Test 2: Input 10, Output 55
   Hidden Test 1: Input 3, Output 6
   Hidden Test 2: Input 7, Output 28
   ```

**Steps:**
1. Login as student (Maria)
2. Open exercise code editor
3. Submit code that passes all tests
4. In Output tab, should see ONLY:
   - ✅ Test 1 (visible)
   - ✅ Test 2 (visible)
5. Should NOT see:
   - Hidden Test 1 input/output
   - Hidden Test 2 input/output
6. But the code should pass all 4 tests (hidden ones affect final pass/fail)

**Expected Result:** ✅ Hidden test details never shown to student, but affect pass/fail logic

**Verification:**
```bash
# Check test results in database
psql -U postgres -d codeinsight -c "
SELECT test_results FROM submissions 
WHERE student_id = (SELECT id FROM users WHERE email='maria@student.psu.edu')
ORDER BY created_at DESC LIMIT 1;
"
# test_results should contain only visible tests, but submission should be marked passed
```

---

## 🧪 TEST SUITE 7: COMPILER ERRORS

### Test 7.1: Compilation Errors Display
**Objective:** Verify compiler errors show line numbers and messages

**Steps:**
1. Login as student (Maria)
2. Open exercise code editor
3. Write intentionally broken C++ code:
   ```cpp
   #include <iostream>
   using namespace std;
   
   int main() {
     int x = 5  // Missing semicolon
     cout << x << endl;
     return 0;
   }
   ```
4. Click "Run" button
5. Go to "Compiler Log" tab
6. Should see error message like:
   ```
   [Line 5, Col 12]: error: expected ';' before 'cout'
   ```
7. Line number should be correct (line 5 in editor)

**Expected Result:** ✅ Compilation errors display with line numbers and messages

---

## 🧪 TEST SUITE 8: ENROLLMENT & SECTION MANAGEMENT

### Test 8.1: Bulk Enrollment with Multiple Students
**Objective:** Verify enrollment endpoint works with multiple students

**Steps:**
1. Login as instructor
2. Go to section
3. Click "Enroll Students"
4. Search and select 3 students:
   - [ ] Maria
   - [ ] Jose
   - [ ] Ana
5. Click "Enroll" button
6. Should see: "✓ Successfully enrolled 3 student(s)"
7. Go to "Students" tab
8. Verify all 3 appear in list

**Expected Result:** ✅ All 3 students enrolled successfully, appear in section

---

## 📊 RESULTS SUMMARY TEMPLATE

Use this template to document your testing results:

```markdown
## Testing Results — [Date]

### Phase 6 API Route Fixes
- [ ] 1.1 Environment Variable Fix (Vite) — PASS / FAIL
- [ ] 1.2 API Base URL Fix — PASS / FAIL
- [ ] 1.3 Enrollment Endpoint Fix — PASS / FAIL

### Phase 7 Section Form
- [ ] 2.1 Semester Field in Form — PASS / FAIL
- [ ] 2.2 Semester Saved to Database — PASS / FAIL

### CDS Computation
- [ ] 3.1 Basic CDS Calculation — PASS / FAIL
- [ ] 3.2 Blank Submission Detection — PASS / FAIL
- [ ] 3.3 NTS Edge Case — PASS / FAIL
- [ ] 3.4 Performance Benchmark — PASS / FAIL
- [ ] 3.5 Classification Ranges — PASS / FAIL

### Live Peer Ranking
- [ ] 4.1 Live Ranking Updates — PASS / FAIL
- [ ] 4.2 Rankings Persist After Close — PASS / FAIL

### Timer & Lifecycle
- [ ] 5.1 Timer Countdown Accuracy — PASS / FAIL
- [ ] 5.2 Page Visibility API — PASS / FAIL
- [ ] 5.3 Exercise Lock After Submit — PASS / FAIL

### Hidden Tests
- [ ] 6.1 Hidden Tests Don't Leak — PASS / FAIL

### Compiler Errors
- [ ] 7.1 Compilation Errors Display — PASS / FAIL

### Enrollment
- [ ] 8.1 Bulk Enrollment — PASS / FAIL

### Overall Status
**TOTAL PASSED:** X / 17
**CRITICAL FAILURES:** None / [list]
**NOTES:** [Any observations]
```

---

## 🐛 Troubleshooting

### White Screen / Blank Page
- **Symptom:** Frontend won't load
- **Fix:** Hard refresh (Ctrl+Shift+R), check console for errors
- **Root Cause:** Environment variable issue (already fixed in Phase 6)

### 404 on All API Calls
- **Symptom:** Network shows 404 errors
- **Fix:** Check DevTools Network → look at URL paths
- **Root Cause:** Double /api path (already fixed in Phase 6)

### "Failed to enroll students"
- **Symptom:** Enrollment modal shows error
- **Fix:** Check network tab for endpoint URL
- **Root Cause:** Missing /api prefix (already fixed in Phase 6)

### Semester Not Showing / Hardcoded "Sem 2"
- **Symptom:** All sections show "Sem 2" regardless of selection
- **Fix:** Check if semester column exists in database
- **Root Cause:** Missing database column (already fixed in Phase 7)

### CDS Shows 0.00 for All Students
- **Symptom:** All CDS scores are 0
- **Fix:** Check if exercise is closed; CDS only computes after closing
- **Root Cause:** Not clicking "Close Exercise" button

### Live Ranking Not Updating
- **Symptom:** Live rankings don't change as students submit
- **Fix:** Verify exercise is still OPEN (not closed)
- **Root Cause:** Live ranking only works during exercise, not after close

---

## 📝 Notes for Testers

1. **Order matters:** Test suites should be run in order (1 → 8)
2. **Fresh data:** Create new exercises for each test to avoid conflicts
3. **Multiple windows:** Use multiple browser windows for multi-user testing
4. **Network tab:** Always check Network tab for API response status
5. **Database verification:** Use psql queries to verify database state
6. **Screenshots:** Take screenshots of each PASS result for documentation

---

## ✅ Sign-Off

- **Tester Name:** ____________________
- **Date:** ____________________
- **Total Tests Run:** ____________________
- **Tests Passed:** ____________________
- **Tests Failed:** ____________________
- **Critical Issues Found:** ____________________
- **Ready for Production:** YES / NO

---

*Last Updated: May 31, 2026*
*Comprehensive testing guide for CodeInsight CDS computation, live peer ranking, and Phase 6-7 fixes*

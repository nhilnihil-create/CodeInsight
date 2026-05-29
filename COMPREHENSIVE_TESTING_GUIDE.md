## 🧪 CodeInsight Comprehensive Testing Workflow

### Overview
Test 4 student scenarios covering edge cases in:
- **CDS Calculation** (NER, NRS, NTS)
- **Alert Generation** (High difficulty detection)
- **Micro-Concept Analysis** (specific feedback)
- **Academic Integrity** (hardcoding detection)
- **AST Verification** (structure validation)

---

## 📋 Setup

### Exercise Under Test
- **Title**: Sum 1 to N
- **Concept**: Loops (requires for/while loop)
- **Visible Tests**: 5→15, 10→55
- **Hidden Tests**: 1→1, 100→5050
- **Time Limit**: 30 minutes

### Students (from CS101 - Programming Fundamentals)
1. maria@student.psu.edu → **Student A**
2. jose@student.psu.edu → **Student B**
3. ana@student.psu.edu → **Student C**
4. Create new student → **Student D**

---

## 🧑‍💻 SCENARIO 1: Student A (Perfect Solution)
**Goal**: Low CDS (~0.2), No Alert

### Test Steps:
1. **Login as Student A** (maria@student.psu.edu)
2. **Go to Exercises** → Click "Sum 1 to N"
3. **Submit this code** (Attempt 1):
```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  cout << sum;
  return 0;
}
```

### Expected Outcome:
- ✅ Run Test: Passes (5 → 15)
- ✅ Submit: Passes all visible + hidden tests
- ✅ AST Verification: PASS (has for_statement)
- ✅ Micro-Concept: No issues detected
- 📊 **Expected CDS Score**: ~0.20 (Low)
  - NER: 0.0 (no failed tests)
  - NRS: 0.125 (1 attempt / 8 class max)
  - NTS: 0.1 (3 min spent / 30 min limit)
  - CDS = 0.40×0 + 0.35×0.125 + 0.25×0.1 = **0.0675**

### What to Check:
```
Dashboard → Heatmap:
  Student A, Loops → GREEN (Low CDS)

Alerts Page:
  ❌ NO alert for Student A
```

---

## 🧑‍💻 SCENARIO 2: Student B (High Retries - High NRS)
**Goal**: High NRS → High CDS (~0.7), Alert Generated

### Test Steps:
1. **Login as Student B** (jose@student.psu.edu)
2. **Go to Exercises** → Click "Sum 1 to N"
3. **Submit wrong attempts** (Attempts 1-8, each ~1 min):

**Attempt 1-3**: Missing loop (if statements)
```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n == 5) cout << 15;
  else if(n == 10) cout << 55;
  else cout << 0;
  return 0;
}
```
- Results: Pass visible tests, fail hidden
- AST Verification: FAIL (no loop)
- Status: **Incorrect**

**Attempt 4-7**: Wrong algorithm (counts instead of sums)
```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << n;  // Wrong: just outputs N instead of sum
  return 0;
}
```
- Results: Fail visible tests
- Status: **Incorrect**

**Attempt 8**: Empty submission (just template)
```cpp
#include <iostream>
using namespace std;

int main() {
  // Write code here
  return 0;
}
```
- Results: Fail all tests
- Status: **Incorrect** (Blank detection)

**Attempt 9**: Finally correct
```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  cout << sum;
  return 0;
}
```
- Results: Pass all tests
- Status: **Correct**

### Expected Outcome:
- 📊 **Expected CDS Score**: ~0.72 (High)
  - NER: 0.875 (8 failed / 8 class max)
  - NRS: 1.0 (9 attempts / 8 class max... capped at 1.0)
  - NTS: 0.3 (9 min / 30 min limit)
  - CDS = 0.40×0.875 + 0.35×1.0 + 0.25×0.3 = **0.7225**

### What to Check:
```
Dashboard → Heatmap:
  Student B, Loops → AMBER/RED (High CDS)

Alerts Page:
  ✅ ALERT generated: Student B, Loops, CDS 0.72

Micro-Concepts Feedback:
  - "High number of retries detected"
  - "Consider: breaking problem into smaller parts"
```

---

## 🧑‍💻 SCENARIO 3: Student C (Hardcoded - Academic Integrity)
**Goal**: Hardcoding detected, High CDS (~0.8), Alert + Integrity Flag

### Test Steps:
1. **Login as Student C** (ana@student.psu.edu)
2. **Go to Exercises** → Click "Sum 1 to N"
3. **Submit hardcoded attempt** (Attempt 1):

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n == 5) cout << 15;
  else if(n == 10) cout << 55;
  else if(n == 1) cout << 1;
  else if(n == 100) cout << 5050;
  else cout << 0;
  return 0;
}
```

### Expected Outcome:
- ✅ Pass ALL tests (hardcoded all answers!)
- ❌ AST Verification: FAIL
  - Reason: "Required AST node 'for_statement' not found"
  - Notice: "Hardcoded output detected"
- 📊 **Expected CDS Score**: ~0.68 (High)
  - NER: 0.0 (all tests passed, but 0 failed)
  - NRS: 0.125 (1 attempt / 8 class max)
  - NTS: 0.05 (1.5 min / 30 min... suspiciously fast!)
  - CDS = 0.40×0 + 0.35×0.125 + 0.25×0.05 = **0.059**
  - BUT: AST verification FAILED + hardcoding detected → should increase CDS artificially
  - Adjusted CDS: **~0.68** (flagged for integrity)

### What to Check:
```
Verification Logs (Backend):
  INSERT INTO verification_logs
  submission_id=?, reason="Required AST node 'for_statement' not found"

Alerts Page:
  ✅ ALERT generated: Student C, Loops, CDS 0.68
  ⚠️ NOTE in verification_note: Academic integrity concern

Micro-Concepts Feedback:
  - "Hardcoded solution pattern detected"
  - "Evidence: Specific hardcoded outputs for test inputs"
  - "Recommended: Implement actual algorithm using loop"
```

---

## 🧑‍💻 SCENARIO 4: Student D (Blank/Template Submission)
**Goal**: Template-only submission, Highest CDS (1.0), Alert

### Setup:
1. **Create new student** (if only 3 exist):
```bash
# Register new student via login page or API
POST /api/auth/register
{
  "name": "Test Student",
  "email": "test@student.psu.edu",
  "password": "password123",
  "role": "student"
}
```

2. **Enroll in CS101** section (Instructor action)

### Test Steps:
1. **Login as Student D** (test@student.psu.edu)
2. **Go to Exercises** → Click "Sum 1 to N"
3. **Submit blank/template** (Attempt 1):

```cpp
#include <iostream>
using namespace std;

int main() {
  // Write code here
  return 0;
}
```

### Expected Outcome:
- ❌ Fail all tests (outputs nothing)
- ❌ AST Verification: FAIL
  - Reason: "Submission matches starter/template code"
- 📊 **Expected CDS Score**: ~0.98 (Highest - needs help!)
  - NER: 1.0 (all tests failed / 1 attempt)
  - NRS: 0.125 (1 attempt / 8 class max)
  - NTS: 0.05 (1.5 min / 30 min)
  - CDS = 0.40×1.0 + 0.35×0.125 + 0.25×0.05 = **0.454**
  - BUT: Blank detection + 0 time spent → forced to High
  - Adjusted CDS: **~0.95** (template-only flag)

### What to Check:
```
Alerts Page:
  ✅ ALERT generated: Student D, Loops, CDS 0.95 (CRITICAL)
  
Verification Note:
  "Blank or template-only submission"

Micro-Concepts Feedback:
  - "No code implementation detected"
  - "Start by: Reading the input value"
  - "Then: Create a loop from 1 to N"
  - "Finally: Sum and output the result"
```

---

## 📊 Final Verification (After Closing Exercise)

### Step 1: Close the Exercise
**Instructor Dashboard:**
1. Go to Sections → CS101 → Exercises
2. Click "Sum 1 to N" exercise
3. Click **"Close Exercise"** button
4. System runs: `computeBatchCDS(exerciseId)`

### Step 2: Check Heatmap
**Dashboard → Analytics → Heatmap:**

```
Expected Grid:
                  Datatypes  Variables  Conditionals  Loops  Functions  Arrays  OOP
Student A (maria)    -          -          -           🟢      -          -       -
Student B (jose)     -          -          -           🔴      -          -       -
Student C (ana)      -          -          -           🔴      -          -       -
Student D (test)     -          -          -           🔴      -          -       -
```

Legend: 🟢 Low (<0.33), 🟡 Moderate (0.33-0.66), 🔴 High (>0.66)

### Step 3: Check Alerts Page
**Instructor Dashboard → Alerts:**

```
Expected Alerts (3 total):

1. Student B (jose) - Loops
   CDS: 0.72 | Classification: High
   Micro-Concept: High retry count
   Action: Review problem decomposition

2. Student C (ana) - Loops  
   CDS: 0.68 | Classification: High
   Micro-Concept: Hardcoding detected
   Action: Review academic integrity concerns

3. Student D (test) - Loops
   CDS: 0.95 | Classification: High
   Micro-Concept: Template-only submission
   Action: Check if student needs support
```

### Step 4: Check Student Progress
**Student Dashboard → My Progress:**

Each student sees their CDS score:
- Student A: 0.07 (Low) - Great job! ✓
- Student B: 0.72 (High) - Needs help
- Student C: 0.68 (High) - Integrity concern
- Student D: 0.95 (High) - Critical support needed

---

## ✅ Verification Checklist

After completing all 4 scenarios, verify:

### CDS Calculation
- [ ] Low CDS (0.07) for perfect solution
- [ ] High CDS (0.72) for high retries
- [ ] High CDS (0.68) for hardcoding
- [ ] Highest CDS (0.95) for blank/template

### Alerts
- [ ] Only 3 alerts generated (for B, C, D)
- [ ] No alert for Student A (Low CDS)
- [ ] All alerts classified as "High"

### AST Verification
- [ ] Student A code: ✅ VERIFIED (has loop)
- [ ] Student B final code: ✅ VERIFIED (has loop)
- [ ] Student C code: ❌ FAILED (no loop, hardcoded)
- [ ] Student D code: ❌ FAILED (template only)

### Micro-Concepts
- [ ] Student B: Feedback on retries
- [ ] Student C: Hardcoding detection
- [ ] Student D: Template detection + hints

### Academic Integrity
- [ ] Student C flagged for hardcoding
- [ ] Verification logs recorded for both C and D
- [ ] Integrity concern noted in instructor view

### Database State
```bash
# Verify in PostgreSQL:
SELECT student_id, COUNT(*) as attempts, 
       ROUND(AVG(CAST(is_correct AS INT))::numeric, 2) as pass_rate
FROM submissions
WHERE exercise_id = 6
GROUP BY student_id
ORDER BY student_id;

# Expected:
 student_id | attempts | pass_rate
------------+----------+-----------
      2     |    9     |   0.11    (Student B: 1/9 passed)
      3     |    1     |   1.00    (Student C: 1/1 passed but hardcoded)
      4     |    1     |   0.00    (Student D: 0/1 passed)
      5     |    1     |   1.00    (Student A: 1/1 passed, perfect)

# Check verification logs:
SELECT submission_id, student_id, reason FROM verification_logs 
WHERE exercise_id = 6;

# Expected: Entries for Student C and D with reasons
```

---

## 🔍 Browser Developer Tools Check

Open DevTools (F12) → Network tab → Filter "submit"

### Student A Perfect Solution Response:
```json
{
  "attemptNumber": 1,
  "allPassed": true,
  "results": [
    {"input": "5", "expected": "15", "actual": "15", "passed": true},
    {"input": "10", "expected": "55", "actual": "55", "passed": true}
  ],
  "hidden": {"count": 2, "passed": true},
  "verification": {
    "is_verified": true,
    "note": "Code structure verified"
  },
  "microConceptFeedback": {
    "hasFeedback": false,
    "detectedCount": 0
  }
}
```

### Student C Hardcoded Response:
```json
{
  "attemptNumber": 1,
  "allPassed": true,
  "results": [
    {"input": "5", "expected": "15", "actual": "15", "passed": true},
    {"input": "10", "expected": "55", "actual": "55", "passed": true}
  ],
  "hidden": {"count": 2, "passed": true},
  "verification": {
    "is_verified": false,
    "note": "Required AST node 'for_statement' not found; [Notice] Hardcoded output detected"
  },
  "microConceptFeedback": {
    "hasFeedback": true,
    "detectedCount": 1,
    "issues": [
      {
        "id": "hardcoding_pattern",
        "name": "Hardcoding Pattern",
        "description": "Solution uses hardcoded values for specific inputs"
      }
    ]
  }
}
```

---

## 🎯 Summary

| Scenario | Student | Attempts | Tests Passed | AST Status | Expected CDS | Alert? |
|----------|---------|----------|--------------|-----------|-------------|--------|
| 1 | A | 1 | ✅ All | ✅ PASS | 0.07 | ❌ No |
| 2 | B | 9 | ✅ Final only | ✅ PASS | 0.72 | ✅ Yes |
| 3 | C | 1 | ✅ All* | ❌ FAIL | 0.68 | ✅ Yes |
| 4 | D | 1 | ❌ None | ❌ FAIL | 0.95 | ✅ Yes |

*C passes visible/hidden but AST verification fails due to hardcoding

---

## 🚀 Next Steps

After verifying all edge cases:
1. ✅ Archive this test data
2. ✅ Document any failures or unexpected behavior
3. ✅ Fix any issues found
4. ✅ Ready for production deployment

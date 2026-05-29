## 🚀 Quick Start - Comprehensive Testing

### 📌 Quick Reference Checklist

#### Phase 1: Environment Setup
- [ ] Backend running: `cd backend && npm start` (port 5000)
- [ ] Frontend running: `cd frontend && npm run dev` (port 5173)
- [ ] Access: http://localhost:5173
- [ ] 3 fresh exercises created (IDs 6, 7, 8)

#### Phase 2: Test Execution
- [ ] **Student A (maria)**: 1 perfect attempt → Low CDS
- [ ] **Student B (jose)**: 9 attempts (8 fails, 1 pass) → High CDS
- [ ] **Student C (ana)**: 1 hardcoded attempt → High CDS + Integrity flag
- [ ] **Student D (test)**: 1 blank attempt → Highest CDS

#### Phase 3: Close Exercise
- [ ] Login as Instructor (instructor@psu.edu)
- [ ] Navigate: Dashboard → Sections → CS101 → Exercises
- [ ] Click "Sum 1 to N" → Click "**Close Exercise**" button
- [ ] System auto-computes CDS for all students

#### Phase 4: Verify Results
- [ ] Run verification script: `bash verify_testing.sh`
- [ ] Check Heatmap: 1 green, 3 red
- [ ] Check Alerts: 3 alerts (B, C, D)
- [ ] Check Verification Logs: 2 entries (C, D)

---

### 📝 Manual Testing Flow (Detailed)

#### **Test 1: Student A - Perfect Solution**

**Step 1.1: Login**
```
URL: http://localhost:5173/login
Email: maria@student.psu.edu
Password: password123
```

**Step 1.2: Submit Perfect Code**
```
Navigate to: My Exercises → Sum 1 to N
Click: Code Editor
Paste the code below:

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

Click: Run (test on first case only)
Expected: "Got: 15" (matches expected 15)

Click: Submit
Expected: 
  - All Visible Tests: PASS ✅
  - Hidden Tests: PASS ✅
  - Verification: PASS ✅
  - "Code structure verified"
```

**Step 1.3: Check Submission History**
```
Click: Previous Attempts
Expected:
  #1 - Pass - 08:XX AM
```

---

#### **Test 2: Student B - High Retries**

**Step 2.1: Login**
```
URL: http://localhost:5173/login
Email: jose@student.psu.edu
Password: password123
```

**Step 2.2: Submit Attempts 1-3 (Wrong Logic - Hardcoded)**
```
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

Results:
  - Visible Tests: PASS (5→15, 10→55)
  - Hidden Tests: FAIL (1→0 instead of 1)
  - Verification: FAIL (no loop)
```

**Step 2.3: Submit Attempts 4-7 (Wrong Algorithm - Just count)**
```
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << n;
  return 0;
}

Results:
  - Visible Tests: FAIL (5→5 instead of 15)
  - Verification: FAIL
```

**Step 2.4: Submit Attempt 8 (Empty/Template)**
```
#include <iostream>
using namespace std;

int main() {
  // Write code here
  return 0;
}

Results:
  - All Tests: FAIL
  - Verification: FAIL (template only)
```

**Step 2.5: Submit Attempt 9 (Finally Correct)**
```
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

Results:
  - All Tests: PASS ✅
  - Verification: PASS ✅
```

**Step 2.6: Check History**
```
Expected:
  #1 - Fail - 08:01 AM
  #2 - Fail - 08:02 AM
  #3 - Fail - 08:03 AM
  #4 - Fail - 08:04 AM
  #5 - Fail - 08:05 AM
  #6 - Fail - 08:06 AM
  #7 - Fail - 08:07 AM
  #8 - Fail - 08:08 AM
  #9 - Pass - 08:09 AM
```

---

#### **Test 3: Student C - Hardcoding (Academic Integrity)**

**Step 3.1: Login**
```
Email: ana@student.psu.edu
Password: password123
```

**Step 3.2: Submit Hardcoded Attempt**
```
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

Results:
  - Visible Tests: PASS ✅
  - Hidden Tests: PASS ✅
  - Verification: FAIL ❌
    * "Required AST node 'for_statement' not found"
    * "[Notice] Hardcoded output detected"
  - Micro-Concept: Hardcoding detected
```

**Check Browser DevTools (F12):**
```
Network → submit request → Response:
{
  "verification": {
    "is_verified": false,
    "note": "Required AST node 'for_statement' not found; [Notice] Hardcoded output detected"
  }
}
```

---

#### **Test 4: Student D - Blank/Template**

**Step 4.1: Create New Student (Instructor)**
```
Register: http://localhost:5173/login → "No account? Register"
Email: test@student.psu.edu
Password: password123
Name: Test Student
Role: Student
```

**Step 4.2: Enroll in CS101 (Instructor)**
```
Login as: instructor@psu.edu
Navigate: Sections → CS101 - Programming Fundamentals
Click: Enroll Students
Add: test@student.psu.edu
```

**Step 4.3: Login as Test Student & Submit Blank**
```
Email: test@student.psu.edu
Navigate: My Exercises → Sum 1 to N
Submit: (Keep default template code)

Results:
  - All Tests: FAIL ❌
  - Verification: FAIL ❌
    * "Submission matches starter/template code"
  - Status: Blank/Template detected
```

---

### ✅ Verification Steps (After Closing Exercise)

**Step 5.1: Close Exercise (Instructor)**
```
Login: instructor@psu.edu
Navigate: Dashboard → Sections → CS101 → Exercises
Click: Sum 1 to N
Button: "Close Exercise" (red button)
Wait: ~5 seconds for CDS computation
```

**Step 5.2: View Heatmap**
```
Dashboard → Analytics (or from Section view)
Expected Heatmap:
  Loops Column:
    - Row "maria": 🟢 GREEN (Low CDS ~0.07)
    - Row "jose": 🔴 RED (High CDS ~0.72)
    - Row "ana": 🔴 RED (High CDS ~0.68)
    - Row "test": 🔴 RED (High CDS ~0.95)
```

**Step 5.3: Check Alerts**
```
Dashboard → Alerts
Expected: 3 alerts (for jose, ana, test)

Alert Details:
  🔴 Jose - Loops - CDS 0.72
  🔴 Ana - Loops - CDS 0.68  
  🔴 Test - Loops - CDS 0.95
```

**Step 5.4: Run Verification Script**
```bash
cd /home/nihil/projects/codeinsight
bash verify_testing.sh

Expected Output:
  1️⃣ Submissions (maria: 1/1 pass, jose: 1/9 pass, ana: 1/1 pass, test: 0/1 pass)
  2️⃣ CDS Scores (maria: 0.07, jose: 0.72, ana: 0.68, test: 0.95)
  3️⃣ Alerts (3 total)
  4️⃣ Verification Logs (2 entries for ana and test)
```

**Step 5.5: Check Student Progress Page**
```
Login each student, navigate: My Progress

Expected Scores:
  - Maria: 0.07 (Low) ✅
  - Jose: 0.72 (High) ⚠️
  - Ana: 0.68 (High) ⚠️
  - Test: 0.95 (Critical) 🔴
```

---

### 📊 Expected Results Summary

| Metric | Maria | Jose | Ana | Test |
|--------|-------|------|-----|------|
| Attempts | 1 | 9 | 1 | 1 |
| Tests Passed | 1/1 | 1/9 | 1/1* | 0/1 |
| AST Status | ✅ PASS | ✅ PASS | ❌ FAIL | ❌ FAIL |
| NER | 0.0 | 0.875 | 0.0 | 1.0 |
| NRS | 0.125 | 1.0 | 0.125 | 0.125 |
| NTS | 0.1 | 0.3 | 0.05 | 0.05 |
| CDS | 0.07 | 0.72 | 0.68 | 0.95 |
| Classification | 🟢 Low | 🔴 High | 🔴 High | 🔴 Critical |
| Alert? | ❌ No | ✅ Yes | ✅ Yes | ✅ Yes |
| Integrity Issue? | ❌ No | ❌ No | ⚠️ Yes | ⚠️ Yes |

*Ana passes visible/hidden but fails AST verification (hardcoding)

---

### 🔍 Troubleshooting

**Issue: "All tests still show as Passed" for Student C**
- ✅ Expected! Hardcoded solution passes all test cases
- Check: DevTools (F12) → Network → submit response → verification field
- You should see: `is_verified: false`

**Issue: CDS scores look different**
- Likely cause: Class maximums changed (other students submitted)
- Fix: Verify using individual component scores (NER, NRS, NTS)
- Class max is calculated from ALL submissions before exercise close

**Issue: No alerts generated**
- Check: Exercise was actually closed (should see "closed_at" timestamp)
- Verify: CDS score > 0.66 for the alerts to generate
- Note: Alerts only appear after closing exercise

**Issue: "Invalid Date" in attempts**
- This happens with old exercises (now fixed with fresh ones)
- If still seeing old dates: Clear localStorage and refresh

---

### 📚 Supporting Files

- `COMPREHENSIVE_TESTING_GUIDE.md` - Full detailed guide
- `verify_testing.sh` - Automated verification script
- `TESTING_WORKFLOW.md` - Initial overview
- Fresh exercises IDs: 6 (Loops), 7 (Conditionals), 8 (Functions)

Good luck! 🚀

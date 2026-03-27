# 🚀 DEPLOYMENT CHECKLIST

## Pre-Launch (Do These First)

### Database Setup
- [ ] PostgreSQL installed and running
- [ ] Run: `psql -U postgres`
- [ ] Run: `CREATE DATABASE codeinsight;`
- [ ] Run: `CREATE USER codeuser WITH PASSWORD 'codepassword123';`
- [ ] Run: `GRANT ALL PRIVILEGES ON DATABASE codeinsight TO codeuser;`
- [ ] Load schema: `psql -U codeuser -d codeinsight < backend/schema.sql`
- [ ] Verify: `psql -U codeuser -d codeinsight -c "SELECT COUNT(*) FROM users;"`
  - Should show: 4 users (1 instructor + 3 students)

### System Requirements
- [ ] Node.js v18+ installed: `node --version`
- [ ] g++ compiler installed: `g++ --version`
- [ ] Linux/Mac: ✓
- [ ] Windows: MinGW installed

### Environment Files
- [ ] `/backend/.env` configured with:
  ```
  DB_HOST=localhost
  DB_PORT=5432
  DB_NAME=codeinsight
  DB_USER=codeuser
  DB_PASSWORD=codepassword123
  JWT_SECRET=your_super_secret_key_change_this_in_production
  PORT=5000
  NODE_ENV=development
  ```

## Launch (Start Servers)

### Terminal 1: Backend
```bash
cd backend
npm install  # Already done, just ensure
npm run dev
# Should log: CodeInsight running on port 5000
```

### Terminal 2: Frontend  
```bash
cd frontend
npm install  # Already done, just ensure
npm run dev
# Should log: Local: http://localhost:5173/
```

### Terminal 3: Test Database Connection
```bash
psql -U codeuser -d codeinsight
SELECT name, email, role FROM users;
SELECT title, description FROM exercises;
\q
```

## Testing Phase 1: Authentication

### [ ] Login as Instructor
- URL: http://localhost:5173/login
- Email: `instructor@psu.edu`
- Password: `password123`
- Expected: Redirects to `/instructor` dashboard

### [ ] Login as Student
- Email: `maria@student.psu.edu`
- Password: `password123`
- Expected: Redirects to `/student` exercises page

### [ ] Logout
- Click Logout button
- Expected: Redirects to login page, localStorage cleared

## Testing Phase 2: Instructor Workflow

### [ ] Create Section
1. Go to `/instructor/sections`
2. Click "+ New Section"
3. Fill:
   - Name: "CS101 - Intro to Programming"
   - Course Code: "CS101"
   - School Year: "AY 2025-2026"
4. Expected: Section appears in list

### [ ] Enroll Students
1. Click on the created section
2. Click "Enroll Students"
3. Select: Maria Reyes, Jose Santos, Ana Lim
4. Expected: Section shows "3 students"

### [ ] Create Exercise
1. Go to `/instructor/create-exercise`
2. Fill:
   - Title: "Sum Two Numbers"
   - Description: "Write a program that reads two integers and outputs their sum."
   - Section: "CS101 - Intro to Programming"
   - Concept: "Functions"
   - Time Limit: 45 minutes
3. Test Cases:
   - TC1: Input `2 3` → Expected `5` (visible)
   - TC2: Input `10 -5` → Expected `5` (hidden)
4. Click "Create Exercise"
5. Expected: Success message

## Testing Phase 3: Student Workflow

### [ ] View Exercises (as Maria)
1. Logout (if logged in as instructor)
2. Login as `maria@student.psu.edu` / `password123`
3. Go to `/student`
4. Expected: "Sum Two Numbers" appears in exercise list

### [ ] Run Code (Test Only)
1. Click the exercise
2. Paste code:
   ```cpp
   #include <iostream>
   using namespace std;
   int main() {
       int a, b;
       cin >> a >> b;
       cout << a + b << endl;
       return 0;
   }
   ```
3. Click "▶ Run"
4. Expected: Green success showing `5` (from first test case `2 3`)

### [ ] Submit Code (Save Result)
1. Click "✓ Submit"
2. Expected: 
   - Both test cases show
   - Results show `5` and `5` (both pass)
   - Submission appears in history

### [ ] Check Submission History
1. Left panel shows "Submissions" with "Attempt 1: ✓ Correct"
2. Expected: Can see all previous attempts

### [ ] View Progress
1. Go to `/student/progress`
2. Expected:
   - Shows 1 total exercise
   - Shows CDS score (should be Low or Moderate)
   - Shows NER, NRS, NTS values

## Testing Phase 4: Analytics (Back as Instructor)

### [ ] Close Exercise (Triggers CDS)
1. Logout, login as instructor
2. Go to `/instructor` dashboard
3. Find "Sum Two Numbers"
4. Click "Close Exercise"
5. Expected: "Exercise closed. CDS computed for all students."

### [ ] View Heatmap
1. Go to `/instructor/analytics`
2. Select "CS101 - Intro to Programming"
3. Expected:
   - Class averages shown for each concept
   - Student heatmap visible (Maria, Jose, Ana × each concept)
   - CDS scores populated (functions concept should show scores)

### [ ] View Alerts
1. Go to `/instructor/alerts`
2. Select section
3. Expected:
   - Any "High" difficulty students appear (CDS > 0.67)
   - Can mark as reviewed (removes from list)

## Troubleshooting Checklist

### Backend Won't Start
- [ ] Check: `ps aux | grep node` (kill old processes)
- [ ] Check: `lsof -i :5000` (port in use?)
- [ ] Check: `.env` exists and has all variables
- [ ] Check: `npm run dev` from `/backend` directory
- [ ] Logs should show: "PostgreSQL connected" + "CodeInsight running on port 5000"

### Frontend Won't Load
- [ ] Check: Ran `npm install` in `/frontend`
- [ ] Check: Vite config proxy points to `localhost:5000`
- [ ] Check: `npm run dev` from `/frontend` directory
- [ ] Check: http://localhost:5173/ (NOT localhost:5000)
- [ ] Browser console for errors

### Database Connection Failed
- [ ] Check: PostgreSQL service running: `sudo systemctl start postgresql`
- [ ] Check: Correct credentials in .env
- [ ] Test: `psql -U codeuser -d codeinsight -c "SELECT 1"`
- [ ] Check: Firewall not blocking 5432

### Code Execution Fails
- [ ] Check: `g++ --version` returns version
- [ ] Check: `/tmp/` directory is writable
- [ ] Backend logs should show compile/runtime errors
- [ ] Test with simple code:
   ```cpp
   #include <iostream>
   int main() { std::cout << "hello" << std::endl; }
   ```

### Test Cases Not Showing
- [ ] Ensure at least 2 test cases created (backend requires minimum)
- [ ] Check test case input/output not empty
- [ ] Submit button should run ALL test cases
- [ ] Run button only tests first visible one

## Post-Launch Quality Checks

### [ ] Performance
- Login: < 1 second
- Code execution: < 10 seconds
- Page loads: < 2 seconds

### [ ] Data Persistence
- Create exercise, refresh page, exercise still there
- Logout, login as different user, data unchanged
- Submit code, logout, login back, submission history persists

### [ ] Error Handling
- Try invalid login: Shows error message
- Try submitting blank code: Shows error, doesn't crash
- Try submitting code with forbidden system calls: Rejected
- Network error on API: Shows user-friendly message (not 500 page)

### [ ] Styling/UX
- Dark theme applied throughout
- All text readable (good contrast)
- Buttons responsive to hover
- Mobile-like or desktop fine?
- No console errors in DevTools

## Production Readiness

### [ ] Code Quality
- No console.error() other than caught errors
- No `eval()`, `new Function()`, or dynamic code
- All API responses have proper error codes
- Backend validates all input

### [ ] Security
- Passwords hashed with bcrypt min cost 10
- JWT tokens have expiration (7d)
- SQL injection prevented (using parameterized queries)
- XSS prevention (React auto-escapes by default)
- CORS properly configured for frontend URL

### [ ] Documentation
- README.md comprehensive ✓
- API endpoints documented ✓
- Setup instructions clear ✓
- Test accounts listed ✓
- Troubleshooting included ✓

## Launch Approved ✅

If all checkboxes above are marked, the system is ready for:
- [ ] Local testing with other users
- [ ] Classroom deployment
- [ ] VPS/Cloud hosting
- [ ] Production use

---

**Final Note:** The system is production-ready for a classroom environment. For public deployment, add:
- HTTPS/SSL
- Rate limiting
- Input validation
- Backup strategy
- Monitoring/logging
- Email notifications
- User quotas

But for PSU CCS internal use? **Ready to go! 🎉**

# CodeInsight - Complete Setup Guide

## Project Status: 95% Complete ✓

### What's Been Built

#### Backend (Express + PostgreSQL)
- ✅ Database schema (9 tables: users, sections, exercises, submissions, cds_scores, alerts, etc.)
- ✅ Authentication system (JWT, hash passwords with bcryptjs)
- ✅ Database seeding (1 instructor, 3 students, 7 concepts)
- ✅ Section management (CRUD, enrollment)
- ✅ Exercise management (create, list, close, test cases)
- ✅ Code submission system (Run vs Submit distinction)
- ✅ GCC C++ compiler integration (execution, timeout handling, safety checks)
- ✅ CDS (Complexity Difficulty Score) engine - core analytics formula
- ✅ Alert generation system (flags high-difficulty students)
- ✅ Live peer ranking (during exercise)
- ✅ Analytics endpoints (heatmap, alerts, student profiles)

#### Frontend (React + Vite + Monaco Editor)
- ✅ Authentication UI (login page, JWT token management)
- ✅ Auth context (global state, persistent session)
- ✅ Protected routes (role-based access control)
- ✅ Sidebar navigation (instructor & student views)
- ✅ **Student Code Editor** (Monaco editor with syntax highlighting)
  - Run button (test on first visible test case)
  - Submit button (save and test all cases)
  - Code execution results display
  - Submission history tracking
  - Exercise details panel
- ✅ **Student Progress** (view all CDS scores with analytics)
- ✅ **Instructor Dashboard** (section & exercise overview)
- ✅ **Instructor Sections** (create, view, manage sections)
- ✅ **Create Exercise** (form with test cases)
- ✅ **Analytics** (heatmap: student performance by concept)
- ✅ **Alerts** (high-difficulty student notifications)

### Note: Structure Checker (Tree-Sitter)
Optional feature. Skip if time is limited. Currently disabled but framework is in place.
To enable: Install `npm install tree-sitter tree-sitter-cpp` and uncomment in submissionController.

---

## 🎬 Quick Start (5 minutes)

### Prerequisites
- Node.js v18+
- PostgreSQL (running locally)
- g++ compiler (`sudo apt install g++ -y` on Linux)

### 1. Setup Database
```bash
# Create database and user in PostgreSQL
psql -U postgres
CREATE DATABASE codeinsight;
CREATE USER codeuser WITH PASSWORD 'codepassword123';
GRANT ALL PRIVILEGES ON DATABASE codeinsight TO codeuser;
\q

# Load schema and seed data
psql -U codeuser -d codeinsight -f backend/schema.sql
```

### 2. Start Backend
```bash
cd backend
npm install
npm run dev
# Server runs on http://localhost:5000
```

### 3. Start Frontend
```bash
cd frontend
npm install
npm run dev
# App runs on http://localhost:5173
```

### 4. Test Login
Use these seeded credentials:

**Instructor:**
- Email: `instructor@psu.edu`
- Password: `password123`

**Students:**
- `maria@student.psu.edu` / `password123`
- `jose@student.psu.edu` / `password123`
- `ana@student.psu.edu` / `password123`

---

## 📊 Testing Workflow

### As Instructor:
1. Login → Dashboard (see sections overview)
2. Create Section → "CS101 - Programming I"
3. Enroll Students → Select Maria, Jose, Ana
4. Create Exercise:
   - Title: "Sum Two Numbers"
   - Concept: Functions
   - Test Cases:
     - Input: `2 3` → Expected: `5`
     - Input: `10 20` → Expected: `30` (hidden)
5. Close Exercise → CDS computed automatically
6. Go to Analytics → See heatmap of student performance
7. Go to Alerts → View high-difficulty students

### As Student:
1. Login → My Exercises (see assigned exercises)
2. Select "Sum Two Numbers" 
3. Write C++ code:
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
4. Click "Run" → Test on first case (2 3 → 5)
5. Click "Submit" → All tests evaluated
6. Go to My Progress → See CDS score

---

## 🔌 API Endpoints Reference

### Authentication
- `POST /api/auth/register` - New user
- `POST /api/auth/login` - Get JWT token
- `GET /api/auth/me` - Current user info

### Sections (Instructor)
- `POST /api/sections` - Create
- `GET /api/sections` - List my sections
- `POST /api/sections/:id/enroll` - Enroll students
- `GET /api/sections/:id/students` - View enrolled

### Exercises (Instructor creates, students access)
- `POST /api/exercises` - Create
- `GET /api/exercises` - List (filtered by role)
- `POST /api/exercises/:id/close` - Triggers CDS computation

### Submissions (Students)
- `POST /api/submissions/run` - Test on first case only
- `POST /api/submissions/submit` - Official submission
- `GET /api/submissions/:exerciseId/my` - My attempts

### Analytics
- `GET /api/analytics/heatmap/:sectionId` - Class performance
- `GET /api/analytics/alerts/:sectionId` - High-difficulty alerts
- `GET /api/analytics/live/:exerciseId` - Peer ranking (during exercise)
- `GET /api/analytics/my-scores` - My CDS scores

---

## 🐛 Troubleshooting

### "Cannot find module 'pg'"
```bash
cd backend && npm install
```

### "Port 5000 already in use"
```bash
# Change PORT in .env or kill process:
lsof -i :5000 | grep -v PID | awk '{print $2}' | xargs kill -9
```

### "GCC command not found"
```bash
# Linux: sudo apt install g++
# macOS: xcode-select --install
# Windows: Install MinGW
```

### Login fails
- Verify .env variables (DB connection)
- Check PostgreSQL is running: `psql -U postgres`
- Verify schema was loaded: `psql -U codeuser -d codeinsight -c "SELECT COUNT(*) FROM users;"`

### Code execution fails
- Check temp directory: `/tmp/` (must be writable)
- Verify g++ works: `g++ --version`
- Check code for unsafe calls (system(), fork(), exec() are blocked)

---

## 📁 Project Structure

```
codeinsight/
├── backend/
│   ├── config/db.js              # PostgreSQL connection
│   ├── middleware/auth.js        # JWT verification
│   ├── controllers/              # Business logic
│   ├── routes/                   # API endpoints
│   ├── services/                 # CDS, alerts, code execution
│   ├── schema.sql                # Database + seed data
│   └── server.js                 # Express app entry
├── frontend/
│   ├── src/
│   │   ├── components/           # Layout, Sidebar, ErrorBoundary
│   │   ├── context/AuthContext   # Global auth state
│   │   ├── pages/
│   │   │   ├── Login.jsx
│   │   │   ├── instructor/       # Dashboard, Sections, CreateExercise, Analytics, Alerts
│   │   │   └── student/          # Exercises (code editor), Progress
│   │   ├── services/api.js       # Axios + interceptors
│   │   └── main.jsx              # Entry point (AuthProvider)
│   └── vite.config.js            # Dev proxy to localhost:5000
```

---

## 🚀 Next Steps (Nice-to-Have)

1. **Structure Checker** - Uncomment tree-sitter integration
2. **Persistence** - Save code drafts to localStorage
3. **Real-time** - WebSocket for live peer updates
4. **Unit Tests** - Jest for backend, Vitest for frontend
5. **Production** - Docker, SSL, environment configs
6. **Email Alerts** - SendGrid for high-difficulty notifications
7. **Export** - Download submissions & analytics as CSV/PDF

---

## 📚 Key Concepts

### CDS Formula
```
CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)

NER = failed_submissions / class_max_failed_submissions
NRS = total_submissions / class_max_total_submissions
NTS = time_spent_seconds / time_limit_seconds

Classification:
- Low:       CDS ≤ 0.33   (Student doing great!)
- Moderate:  0.34 ≤ CDS ≤ 0.66
- High:      CDS > 0.66   (Needs help - generates alert)
```

### Authentication Flow
1. User submits email + password
2. Backend hashes(password) and compares with DB
3. If match: JWT = {user_id, name, email, role} signed with JWT_SECRET
4. Frontend stores token in localStorage
5. All API requests include `Authorization: Bearer {token}`
6. Backend middleware verifies token signature
7. Logout clears token from localStorage

---

## ✅ Testing Checklist

- [ ] Backend runs without errors
- [ ] Frontend loads login page
- [ ] Can login as instructor
- [ ] Can login as student
- [ ] Create a section
- [ ] Enroll students in section
- [ ] Create an exercise (min 2 test cases)
- [ ] Write C++ code and Run (tests first case)
- [ ] Submit (tests all cases)
- [ ] See submission history
- [ ] Close exercise→ CDS computed
- [ ] View heatmap analytics
- [ ] See high-difficulty alerts
- [ ] Student can view progress scores

All features working? 🎉 Deploy to production!

---

Built with ❤️ for PSU CCS AY 2025-2026

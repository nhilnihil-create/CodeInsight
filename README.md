# CodeInsight — V2

## Project Status: 100% Complete — Production Ready

### What's Been Built

#### Backend (Express + PostgreSQL)
- ✅ Database schema (30 tables: users, sections, exercises, submissions, cds_scores, integrity_flags, alerts, behavioral_events, etc.)
- ✅ Authentication system (JWT, bcryptjs, Google OAuth via Google Identity Services)
- ✅ Database auto-migrations (schema patches + V2 migrations on startup)
- ✅ Section management (CRUD, enrollment, join codes, role-based memberships)
- ✅ Exercise management (create, list, close, test cases, draft mode, deadline auto-close)
- ✅ Code submission system (Run vs Submit distinction, async processing via BullMQ)
- ✅ GCC C++ compiler integration (Docker sandbox OR native compilation fallback)
- ✅ CDS (Cumulative Dynamic Struggle) engine — p95-capped min-max normalization
- ✅ Academic integrity engine (code plagiarism, hardcoding, blank template detection)
- ✅ Integrity flag system (graduated flagging, severity levels, evidence tracking)
- ✅ Behavioral anomaly detection (tab switches, paste events, idle detection, retry storms)
- ✅ Alert generation system (CDS_HIGH, RETRY_STORM, CODE_GROWTH_ANOMALY, etc.)
- ✅ Live peer ranking (during exercise)
- ✅ Analytics endpoints (heatmap, alerts, trends, reports, concept radar)
- ✅ Micro-concept engine (concept mastery index + velocity tracking)
- ✅ AST verifier (tree-sitter C++ parsing for structural verification)
- ✅ Structured logging (pino) + request logging (pino-http)
- ✅ Security hardening (helmet, rate limiting, parameterized queries, error leakage fixes)
- ✅ Health endpoints (`/api/health`, `/api/ready`)
- ✅ Export system (CSV/Excel reports)
- ✅ Full-text search (exercises)
- ✅ Admin dashboard (user management, evaluation responses, section audit)

#### Frontend (React + Vite + Tailwind v4)
- ✅ Authentication UI (login, register, Google OAuth, email verification, OTP)
- ✅ Auth context (global state, persistent session, JWT management)
- ✅ Protected routes (role-based access control: student/instructor/admin)
- ✅ **Student Code Editor** (Monaco editor with syntax highlighting)
  - Run button (test on visible test cases only)
  - Submit button (test all cases, save to database)
  - Code execution results display
  - Submission history tracking
  - Exercise details panel
- ✅ **Student Dashboard** (today's tasks, progress overview, mastery tiers)
- ✅ **Student Progress** (CDS scores, concept radar, period selector)
- ✅ **Instructor Dashboard** (section overview, at-risk students, command center)
- ✅ **Instructor Sections** (create, view, manage sections with join codes)
- ✅ **Instructor Analytics** (heatmap: student × concept struggle matrix)
- ✅ **Instructor Alerts** (high-difficulty student notifications, integrity flags)
- ✅ **Instructor Exercise Explorer** (bulk create, concept tagging)
- ✅ **Instructor Reports** (class concept radar, micro-concept reports)
- ✅ **Admin Dashboard** (user management, system overview, ISO/IEC 25010 evaluation)
- ✅ **Instructor Submission Review** (code history viewer, attempt timeline)
- ✅ **Responsive tables** (ResponsiveTable with mobile card variants)
- ✅ **UI components** (shadcn/ui: buttons, badges, drawers, dropdowns, mastery bars, decision lists)

#### Testing (905 tests, 54 suites)
- ✅ Backend unit/integration tests (Jest)
- ✅ Frontend component tests (Vitest)
- ✅ E2E tests (Playwright — Chromium)
- ✅ Load/performance benchmarks
- ✅ CI pipeline (GitHub Actions)

---

## Quick Start (5 minutes)

### Prerequisites
- Node.js v22+
- PostgreSQL 16+ (or Neon serverless)
- Redis v7+ (for async submission processing)
- g++ compiler (`sudo apt install g++ -y` on Linux)

### 1. Setup Database
```bash
# If using local PostgreSQL:
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
cp .env.example .env   # configure DB_HOST, DB_USER, DB_PASSWORD, JWT_SECRET
npm install
node migrations.js     # auto-apply schema patches + V2 migrations
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

## Testing Workflow

### As Instructor:
1. Login -> Dashboard (see sections overview)
2. Create Section -> "CS101 - Programming I"
3. Enroll Students -> Select Maria, Jose, Ana
4. Create Exercise:
   - Title: "Sum Two Numbers"
   - Concept: Functions
   - Test Cases:
     - Input: `2 3` -> Expected: `5` (visible)
     - Input: `10 20` -> Expected: `30` (hidden)
5. Close Exercise -> CDS computed automatically for all enrolled students
6. Go to Analytics -> See heatmap of student performance by concept
7. Go to Alerts -> View high-difficulty students and integrity flags

### As Student:
1. Login -> My Exercises (see assigned exercises)
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
4. Click "Run" -> Test on first visible case (2 3 -> 5)
5. Click "Submit" -> All test cases evaluated (visible + hidden)
6. Go to My Progress -> See CDS score with mastery tier

---

## API Endpoints Reference

### Authentication
- `POST /api/auth/register` - New user (email/password)
- `POST /api/auth/login` - Login with email + password
- `POST /api/auth/google` - Login/register via Google OAuth
- `POST /api/auth/request-otp` - Request email OTP
- `POST /api/auth/verify-otp` - Verify OTP code
- `GET /api/auth/verify-email` - Email verification link
- `GET /api/auth/me` - Current user info
- `POST /api/auth/logout` - Invalidate JWT

### Sections (Instructor)
- `POST /api/sections` - Create section
- `GET /api/sections` - List my sections
- `POST /api/sections/:id/enroll` - Enroll students
- `GET /api/sections/:id/students` - View enrolled students
- `POST /api/sections/:id/join-code` - Generate join code

### Exercises
- `POST /api/exercises` - Create (instructor)
- `GET /api/exercises` - List (filtered by role)
- `POST /api/exercises/:id/close` - Close and trigger CDS computation
- `POST /api/exercises/bulk-create` - Bulk create from exercise bank

### Submissions (Students)
- `POST /api/student/exercises/:id/run` - Test on visible cases only
- `POST /api/student/exercises/:id/submit` - Official submission (all cases)
- `GET /api/submissions/:exerciseId/my` - My submission history

### Analytics (Instructor)
- `GET /api/analytics/heatmap/:sectionId` - Student x Concept heatmap
- `GET /api/analytics/alerts/:sectionId` - High-CDS alerts
- `GET /api/analytics/live/:exerciseId` - Peer ranking (during exercise)
- `GET /api/analytics/my-scores` - Student CDS scores
- `GET /api/analytics/trends/:sectionId` - Performance trends
- `GET /api/analytics/class-concept-radar/:sectionId` - Class concept radar
- `GET /api/analytics/integrity-flags/:sectionId` - Integrity violations

### Admin
- `GET /api/admin/overview` - System overview
- `GET /api/admin/users` - User management
- `POST /api/admin/evaluation` - Submit ISO/IEC 25010 evaluation

### System
- `GET /api/health` - Liveness check
- `GET /api/ready` - Readiness check (DB + queue)
- `GET /api/docs` - API documentation (Swagger UI)

---

## Key Concepts

### CDS Formula (Cumulative Dynamic Struggle)
```
CDS = (0.40 x NER) + (0.35 x NRS) + (0.25 x NTS)
```

#### Normalization Method (p95-capped Min-Max)
All three metrics are normalized using the same algorithm:
```
normalized = (cappedValue - classMin) / (p95 - classMin)

where:
  cappedValue = min(studentValue, p95)   // outlier cap
  p95         = 95th percentile of class values
  classMin    = minimum across all eligible students
```
- Result clamped to [0.00, 1.00]
- Zero-variance guard: if p95 - min == 0, returns 0.00
- Post-solution cutoff: only submissions up to first correct answer are counted
- Integrity exclusions: flagged students (HARDCODING, BLANK_TEMPLATE) excluded from class stats
- Confidence tiers: < 5 submitters = "Unscored", 5-9 = "Prelim", 10+ = "Confident"

#### Metric Definitions
- **NER** (Normalized Error Rate): Count of submissions with `is_correct = false`, normalized against class distribution
- **NRS** (Normalized Repetition Rate): Total submission count, normalized against class distribution
- **NTS** (Normalized Time Spent): Maximum time spent on an exercise, normalized against exercise time limit

#### Classification Thresholds (5-tier)
```
Very Low:   CDS <= 0.20   (struggling significantly)
Low:        CDS <= 0.40   (below average)
Moderate:   CDS <= 0.60   (average performance)
Elevated:   CDS <= 0.80   (above average)
High:       CDS >  0.80   (mastering the concept)
Unscored:   < 5 submitters or integrity-flagged
```

### Authentication Flow
1. User submits email + password (or clicks "Continue with Google")
2. Backend verifies credentials (bcrypt compare / Google ID token via `google-auth-library`)
3. If match: JWT = {user_id, name, email, role} signed with JWT_SECRET
4. Frontend stores token in localStorage
5. All API requests include `Authorization: Bearer {token}`
6. Backend middleware verifies token signature + checks blacklist
7. Logout invalidates JWT (added to `token_blacklist`)

---

## Project Structure

```
CodeInsight-V2/
├── backend/                     # Express.js API server
│   ├── config/db.js            # PostgreSQL pool + withTransaction
│   ├── controllers/            # 14 controllers (thin routing logic)
│   ├── routes/                 # 12 route files
│   ├── services/               # 20+ services (core business logic)
│   │   ├── cdsEngine.js        # CDS computation + normalization
│   │   ├── academicIntegrityEngine.js  # Plagiarism + integrity checks
│   │   ├── astVerifier.js      # tree-sitter C++ AST verification
│   │   └── executor.js         # C++ compilation + execution
│   ├── lib/                    # Shared utilities (15 modules)
│   │   ├── logger.js           # pino structured logging
│   │   ├── background.js       # defer() fire-and-forget helper
│   │   ├── cache.js            # In-memory TTL exercise cache
│   │   ├── concurrency.js      # Concurrent compilation limiter
│   │   ├── submissionPipeline.js # Shared integrity pipeline
│   │   └── integrityFlags.js   # Flag type constants
│   ├── middleware/             # auth, errorHandler, validate, helmet, rateLimit
│   ├── migrations/             # 6 migration files
│   ├── queues/                 # BullMQ: submissionWorker + submissionQueue
│   ├── scripts/                # Seed/maintenance scripts
│   ├── test/                   # 50+ test files (Jest)
│   ├── schema.sql              # Database schema + seed data
│   └── server.js               # Entry point
├── frontend/                    # React SPA
│   ├── src/
│   │   ├── components/         # 40+ components (shadcn/ui + Radix UI)
│   │   ├── pages/              # 30+ page components
│   │   │   ├── instructor/     # Dashboard, Sections, Heatmap, Alerts, etc.
│   │   │   ├── student/        # Exercises (code editor), Progress
│   │   │   └── admin/          # Overview, Users, Evaluation
│   │   ├── context/            # Auth, EditorPrefs, Sidebar contexts
│   │   ├── hooks/              # 6 custom hooks
│   │   ├── services/api.js     # Axios + interceptors
│   │   └── App.jsx             # Router + lazy loading
│   └── vite.config.js          # Manual chunk splitting
├── e2e/                         # Playwright end-to-end tests
├── simulation/                  # Workload simulation + Stagehand
├── tests/                       # Load + UAT tests
├── scripts/                     # Systemd, backup, codenet
├── docs/                        # Design specs, plans, migration docs
├── Dockerfile                   # Multi-stage build (node:22-alpine)
├── docker-compose.yml           # postgres + redis + backend
├── cyclic.json                  # Cyclic.sh deployment config
└── render.yaml                  # Render deployment config
```

---

## Troubleshooting

### "Cannot find module 'pg'"
```bash
cd backend && npm install
```

### "Port 5000 already in use"
```bash
# Kill process on port:
lsof -i :5000 | grep -v PID | awk '{print $2}' | xargs kill -9
```

### "GCC command not found"
```bash
# Linux: sudo apt install g++
# macOS: xcode-select --install
# Windows: Install MinGW
# Docker: included in gcc:14-bookworm image
```

### Login fails
- Verify `.env` variables (DB connection, JWT_SECRET)
- Check PostgreSQL is running: `psql -U postgres`
- Verify schema was loaded: `psql -U codeuser -d codeinsight -c "SELECT COUNT(*) FROM users;"`

### Code execution fails
- Check temp directory: `/tmp/` (must be writable)
- Verify g++ works: `g++ --version`
- Check code for unsafe calls (system(), fork(), exec() are blocked)
- On Cyclic.sh: native compilation fallback is used (no Docker available)

### CDS not computing
- Exercise must be closed (manually via `POST /api/exercises/:id/close` or auto-close at deadline)
- Minimum 5 submitters required for "Confident" classification
- Check `cds_scores` table: `SELECT * FROM cds_scores WHERE exercise_id = X;`

---

## Deployment

See [DEPLOYMENT.md](./DEPLOYMENT.md) for full deployment instructions.

- **Production**: Cyclic.sh (backend) + Neon (PostgreSQL) + Redis
- **Local Dev**: Docker Compose or bare metal
- **CI/CD**: GitHub Actions (test, lint, E2E, npm audit)

---

## Documentation

| File | Description |
|------|-------------|
| [CLAUDE.md](./CLAUDE.md) | Architecture reference, deployment checklist, PRR status |
| [SYSTEM_MAP.md](./SYSTEM_MAP.md) | Full system architecture, database schema, API endpoints |
| [DEPLOYMENT.md](./DEPLOYMENT.md) | Deployment guide (Docker, bare metal, Cyclic.sh) |
| [docs/google-signin.md](./docs/google-signin.md) | Google OAuth implementation details |
| [docs/export-overhaul-plan.md](./docs/export-overhaul-plan.md) | CSV/Excel export system design |

---

Built with care for PSU CCS AY 2025-2026

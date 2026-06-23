# DEPLOYMENT CHECKLIST

## Zero-Cost Deployment (Cyclic.sh + Neon + Vercel)

This is the recommended deployment for **zero-cost production** — no credit card required.

### Architecture
```
┌──────────────┐     ┌──────────────┐     ┌──────────────┐
│   Vercel     │────▶│  Cyclic.sh   │────▶│    Neon      │
│  (Frontend)  │     │  (Backend)   │     │ (Postgres)   │
│  vite+react  │     │  Express.js  │     │  Managed DB  │
└──────────────┘     └──────────────┘     └──────────────┘
     HTTPS                HTTPS                TLS
  codeinsight.vercel.app  codeinsight.cyclic.app  neon.tech
```

### Step 1: Create Neon Database (Postgres)

1. Sign up at [neon.tech](https://neon.tech) (no credit card)
2. Create a project → your database is ready immediately
3. From the Neon dashboard, copy the **connection string**:
   ```
   postgresql://user:password@ep-xxxx.region.aws.neon.tech/codeinsight?sslmode=require
   ```
4. Run schema migration locally:
   ```bash
   psql "<neon-connection-string>" < backend/schema.sql
   ```
   This creates all 12 tables and seeds demo accounts.

### Step 2: Deploy Backend to Cyclic.sh

1. Push your repo to GitHub
2. Sign up at [cyclic.sh](https://cyclic.sh) (GitHub login, no credit card)
3. Click **"Deploy"** → select your repo
4. Cyclic.sh auto-detects the `Dockerfile` and builds the container
5. Set environment variables in Cyclic.sh dashboard → **Variables**:

| Variable | Value | Notes |
|----------|-------|-------|
| `DB_HOST` | `ep-xxxx.region.aws.neon.tech` | From Neon connection string |
| `DB_PORT` | `5432` | |
| `DB_NAME` | `codeinsight` | |
| `DB_USER` | (from Neon) | |
| `DB_PASSWORD` | (from Neon) | |
| `DB_SSL` | `true` | Required for Neon |
| `DB_CONNECTION_TIMEOUT_MS` | `5000` | |
| `DB_STATEMENT_TIMEOUT_MS` | `30000` | |
| `DB_POOL_MAX` | `10` | Neon free tier limit |
| `JWT_SECRET` | `<generate-a-random-string>` | Use: `openssl rand -hex 32` |
| `NODE_ENV` | `production` | |
| `CORS_ORIGINS` | `https://codeinsight.vercel.app` | Your Vercel frontend URL |
| `EMAIL_HOST` | `smtp.gmail.com` | For OTP emails |
| `EMAIL_PORT` | `587` | |
| `EMAIL_USER` | `codeinsight.noreply@gmail.com` | |
| `EMAIL_PASS` | (Gmail App Password) | |
| `EMAIL_FROM` | `CodeInsight <codeinsight.noreply@gmail.com>` | |
| `EMAIL_ENABLED` | `true` | |
| `APP_URL` | `https://codeinsight.cyclic.app` | Your Cyclic.sh URL |
| `LOG_LEVEL` | `info` | |

6. After deploy, wait for build (1-2 min) then verify:
   ```bash
   curl https://codeinsight.cyclic.app/api/health
   curl https://codeinsight.cyclic.app/api/ready
   ```

### Step 3: Deploy Frontend to Vercel

1. Sign up at [vercel.com](https://vercel.com) (GitHub login, no credit card)
2. Click **"Add New" → "Project"** → select your repo
3. Configure:
   - **Root Directory**: `frontend`
   - **Build Command**: `npm run build` (auto-detected from vercel.json)
   - **Output Directory**: `dist`
   - **Node Version**: 22.x
4. Add environment variable:
   - `VITE_API_BASE_URL` = `https://codeinsight.cyclic.app` (your Cyclic.sh backend URL)
5. Click **Deploy**
6. Add the Vercel production URL to Cyclic.sh's `CORS_ORIGINS` environment variable

### Step 4: Verify End-to-End

1. Open your Vercel URL (e.g., `https://codeinsight.vercel.app`)
2. Login as instructor: `instructor@psu.edu` / `password123`
3. Navigate to a section → click "Set Up Exercise" to create a new exercise
4. Logout and login as student: `maria@student.psu.edu` / `password123`
5. The student dashboard loads with exercise data from the database

### Env Vars Quick Reference

| Env Var | Where to Set | Purpose |
|---------|-------------|---------|
| `VITE_API_BASE_URL` | Vercel dashboard | Points frontend at Cyclic.sh backend |
| `CORS_ORIGINS` | Cyclic.sh dashboard | Allows frontend origin in CORS |
| `JWT_SECRET` | Cyclic.sh dashboard | Signs auth tokens |
| `DB_*` | Cyclic.sh dashboard | Neon Postgres connection |
| `EMAIL_*` | Cyclic.sh dashboard | Gmail SMTP for OTP |

### Troubleshooting (Cyclic.sh)

**"Docker is required but unavailable"**: Remove this error — the backend now compiles C++ natively on Cyclic.sh (g++ is included in the Dockerfile). No Docker-in-Docker needed.

**Blank page on Vercel**: Check `VITE_API_BASE_URL` is set correctly in Vercel dashboard. The frontend needs to know where the backend lives.

**Login fails / cookie not sent**: Ensure `CORS_ORIGINS` on Cyclic.sh exactly matches `https://codeinsight.vercel.app` (no trailing slash). The backend uses `SameSite=None` in production — cookies require HTTPS (both Vercel and Cyclic.sh support this natively).

**Backend crashes on Neon**: Verify `DB_POOL_MAX` is ≤ 10 (Neon free tier). Our config defaults to 10. If connections are exhausted, reduce via `DB_POOL_MAX=5`.

---

## Quick Start (Docker — Recommended for Local Dev)

```bash
# 1. Build and start all services
docker compose build
docker compose up -d

# 2. Verify health
curl http://localhost:5000/api/health
curl http://localhost:5000/api/ready

# 3. Check logs
docker compose logs -f backend
```

## Quick Start (Bare Metal)

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
- [ ] Node.js v22+ installed: `node --version`
- [ ] g++ compiler installed: `g++ --version`
- [ ] Linux/Mac: ✓
- [ ] Windows: MinGW installed
- [ ] Redis v7+ (required for async submission processing)

### Environment Files
- [ ] `backend/.env` configured (copy from `backend/.env.example`)
- [ ] For production: `NODE_ENV=production`, `DB_SSL=true`, `CORS_ORIGINS` set to your frontend URL

## Production Deployment (Bare Metal with PM2)

```bash
cd backend
npm ci --omit=dev
node migrations.js
pm2 start ecosystem.config.js
pm2 save
pm2 startup  # Configure PM2 to start on boot
```

### Process Management
- Run via PM2: `pm2 start ecosystem.config.js`
- Monitor: `pm2 monit` or `pm2 status`
- Logs: `pm2 logs codeinsight`
- Restart: `pm2 restart codeinsight`

### Health Endpoints
- Liveness: `GET /api/health` — returns `{ status: 'ok' }` if process is up
- Readiness: `GET /api/ready` — checks DB + queue connectivity, returns 503 if DB is down

### Monitoring
- Structured JSON logging via pino (set `LOG_LEVEL=info` for production, `LOG_LEVEL=debug` for dev)
- Request logging via pino-http (set `LOG_REQUESTS=1` to enable)
- Logs are stdout by default; pipe to a log collector (e.g., systemd-journald, Datadog, Loki)

## Backup & Restore

### Automated Backup
The backup script in `scripts/backup.sh` creates daily pg_dump snapshots:

```bash
# One-time backup
./scripts/backup.sh

# Add to cron (daily at 3 AM)
0 3 * * * /path/to/codeinsight/scripts/backup.sh
```

### Manual Restore
```bash
gunzip -c backups/codeinsight_2026-06-22_030001.sql.gz | psql -U codeuser -d codeinsight
```

## Testing Phases

### Phase 1: Authentication
- [ ] Login as Instructor: `instructor@psu.edu` / `password123` → redirects to `/instructor`
- [ ] Login as Student: `maria@student.psu.edu` / `password123` → redirects to `/student`
- [ ] Logout clears session

### Phase 2: Instructor Workflow
- [ ] Create Section with name, course code, school year
- [ ] Enroll Students from list
- [ ] Create Exercise with test cases (visible + hidden)
- [ ] Close Exercise triggers CDS computation for all enrolled students

### Phase 3: Student Workflow
- [ ] View Exercises — enrolled exercises appear with status
- [ ] Run Code — test against first visible test case only
- [ ] Submit Code — runs all test cases, saves to database
- [ ] View Progress — CDS, NER, NRS, NTS values visible

### Phase 4: Analytics
- [ ] View Heatmap — class × concept matrix
- [ ] View Alerts — high-CDS students flagged
- [ ] Mark alerts as reviewed

## CI/CD Pipeline

The `.github/workflows/ci.yml` pipeline runs:
1. **Backend Tests** — Jest on real PostgreSQL
2. **Frontend Tests** — Vitest + build check
3. **E2E Tests** — Playwright (Chromium) with seeded data
4. **Code Quality** — console.log audit, TODO check, secrets scan, ESLint validation
5. **Performance Benchmark** — on main branch only, concurrency=5, requests=50
6. **npm audit** — production dependency vulnerability scan

Testing commands:
```bash
npm run test:backend      # Backend unit/integration tests
npm run test:frontend     # Frontend component tests
npm run test:e2e          # Playwright E2E tests
npm run test:all          # All of the above
npm run test:ci-backend   # CI-optimized backend tests
```

## Security Checklist

- [ ] `NODE_ENV=production` set in production
- [ ] `CORS_ORIGINS` restricted to frontend URL only
- [ ] `JWT_SECRET` is a strong, unique random string
- [ ] `DB_PASSWORD` is a strong, unique password
- [ ] HTTPS/SSL configured at reverse proxy (Nginx/Caddy)
- [ ] Rate limiting enabled on login, submission, and run endpoints
- [ ] HTTP security headers (helmet) enabled
- [ ] Regular `npm audit` runs (automated in CI)

## Troubleshooting

### Backend Won't Start
- [ ] Check: `pm2 status` (process running?)
- [ ] Check: `pm2 logs codeinsight` (error message?)
- [ ] Check: PostgreSQL accepting connections: `pg_isready`
- [ ] Check: Redis available: `redis-cli ping`
- [ ] Check: `.env` has all required variables
- [ ] Check: `lsof -i :5000` (port in use?)

### Database Connection Failed
- [ ] Check: PostgreSQL service running: `sudo systemctl start postgresql`
- [ ] Check: Correct credentials in `.env`
- [ ] Test: `psql -U codeuser -d codeinsight -c "SELECT 1"`
- [ ] Check: Firewall not blocking 5432

### Code Execution Fails
- [ ] Check: `g++ --version` returns version
- [ ] Check: `/tmp/` directory is writable
- [ ] Check: Docker daemon running (sandbox mode)
- [ ] Backend logs show compile/runtime errors

## Post-Launch

- [ ] Monitor `/api/ready` for liveness checks
- [ ] Set up log aggregation (Datadog, Loki, or similar)
- [ ] Configure backup cron job
- [ ] Set up uptime monitoring (Pingdom, UptimeRobot, etc.)
- [ ] Review npm audit results periodically
- [ ] Schedule monthly dependency updates

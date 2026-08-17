# Deployment Guide

## Production Architecture

```
┌──────────────────┐     ┌──────────────────┐     ┌──────────────┐     ┌──────────┐
│     Cyclic.sh    │────▶│      Neon        │     │    Redis     │     │  Gmail   │
│  (Backend)       │     │  (PostgreSQL)    │     │  (ioredis)   │     │  SMTP    │
│  Node 22 Alpine  │     │  Serverless DB   │     │  Queue + OTP │     │          │
│  Express + g++   │     │  TLS connection  │     │              │     │          │
└──────────────────┘     └──────────────────┘     └──────────────┘     └──────────┘
       HTTPS                      TLS                     internal           SMTP
    codeinsight.cyclic.app    neon.tech               (bundled/external)  Nodemailer
```

- **Cyclic.sh** runs the Express backend (handles API, C++ compilation, DB queries)
- **Neon** is the serverless PostgreSQL database (free tier, scale-to-zero)
- **Redis** powers BullMQ job queue + OTP store (Cyclic.sh addon or external)
- **Gmail SMTP** sends email verification + OTP (via Nodemailer)

---

## Option 1: Docker Compose (Recommended for Local Dev)

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

### What's included
- PostgreSQL 16 (with seed data)
- Redis 7-Alpine
- Backend (node:22-alpine with g++ for C++ compilation)

---

## Option 2: Bare Metal (Local Development)

### System Requirements
- [ ] Node.js v22+ installed: `node --version`
- [ ] g++ compiler installed: `g++ --version`
- [ ] PostgreSQL 16+ installed and running
- [ ] Redis v7+ installed and running (required for async submission processing)
- [ ] Linux/Mac: native; Windows: MinGW or WSL

### Database Setup
```bash
psql -U postgres
CREATE DATABASE codeinsight;
CREATE USER codeuser WITH PASSWORD 'codepassword123';
GRANT ALL PRIVILEGES ON DATABASE codeinsight TO codeuser;
\q

# Load schema and seed data
psql -U codeuser -d codeinsight -f backend/schema.sql

# Verify
psql -U codeuser -d codeinsight -c "SELECT COUNT(*) FROM users;"
# Should show: 4 users (1 instructor + 3 students)
```

### Environment Configuration
```bash
cd backend
cp .env.example .env
# Edit .env with your values
```

Required env vars:
| Variable | Description | Example |
|----------|-------------|---------|
| `DB_HOST` | PostgreSQL host | `localhost` |
| `DB_PORT` | PostgreSQL port | `5432` |
| `DB_USER` | Database user | `codeuser` |
| `DB_PASSWORD` | Database password | `codepassword123` |
| `DB_NAME` | Database name | `codeinsight` |
| `JWT_SECRET` | Strong random string | (generate with `openssl rand -hex 32`) |
| `NODE_ENV` | `development` or `production` | `development` |
| `CORS_ORIGINS` | Allowed frontend origins | `http://localhost:5173` |
| `REDIS_HOST` | Redis host | `localhost` |
| `LOG_LEVEL` | pino log level | `debug` |

### Start Backend
```bash
cd backend
npm install
node migrations.js   # auto-apply schema patches + V2 migrations
npm run dev           # development (with hot reload)
# or
npm start             # production
```

Backend starts on `http://localhost:5000`.

### Start Frontend
```bash
cd frontend
npm install
npm run dev
# App runs on http://localhost:5173
```

---

## Option 3: Production with PM2 (Bare Metal Server)

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

### PM2 Configuration (`ecosystem.config.js`)
- Cluster mode: 2 instances in production
- Memory cap: 1GB per instance (Cyclic.sh constraint)
- Auto-restart on crash
- Log rotation enabled

---

## Option 4: Cyclic.sh (Production Deployment)

CodeInsight is optimized for Cyclic.sh's 500MB/10s constraints:

### Deployment Steps
1. Push to GitHub
2. Connect repository to Cyclic.sh
3. Set environment variables in Cyclic dashboard
4. Cyclic auto-deploys on push

### Cyclic-Specific Optimizations
- **Native compilation fallback**: When Docker is unavailable, g++ compiles C++ natively with timeout + resource limits (`backend/services/executor.js`)
- **Fire-and-forget**: `defer()` runs CDS, flags, and integrity checks after HTTP response (`backend/lib/background.js`)
- **Concurrent compilation limiter**: Caps C++ compilations to `max(2, CPUs-1)` (`backend/lib/concurrency.js`)
- **In-memory exercise cache**: TTL-based cache eliminates redundant DB queries (`backend/lib/cache.js`)
- **Deferred post-processing**: Response sent immediately; background work via `setImmediate`
- **DB pool tuned**: `max: 10` (Neon free tier limit), `statement_timeout: 30s`

### Cyclic Environment Variables
Same as bare metal, plus:
| Variable | Description |
|----------|-------------|
| `DB_SSL` | Set to `true` for Neon connections |
| `DB_CONNECTION_TIMEOUT_MS` | Connection timeout (default: 5000) |

---

## CI/CD Pipeline (GitHub Actions)

The `.github/workflows/ci.yml` pipeline runs:
1. **Backend Tests** — Jest on real PostgreSQL
2. **Frontend Tests** — Vitest + build check
3. **E2E Tests** — Playwright (Chromium) with seeded data
4. **Code Quality** — console.log audit, TODO check, secrets scan, ESLint
5. **Performance Benchmark** — on main branch only, concurrency=5, requests=50
6. **npm audit** — production dependency vulnerability scan

### Testing Commands
```bash
npm run test:backend      # Backend unit/integration tests
npm run test:frontend     # Frontend component tests
npm run test:e2e          # Playwright E2E tests
npm run test:all          # All of the above
npm run test:ci-backend   # CI-optimized backend tests
```

---

## Health Endpoints

- **Liveness**: `GET /api/health` — returns `{ status: 'ok' }` if process is up
- **Readiness**: `GET /api/ready` — checks DB + queue connectivity, returns 503 if DB is down

---

## Monitoring

- Structured JSON logging via pino (`LOG_LEVEL=info` for production, `LOG_LEVEL=debug` for dev)
- Request logging via pino-http (set `LOG_REQUESTS=1` to enable)
- Logs are stdout by default; pipe to a log collector (Datadog, Loki, systemd-journald)

---

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
gunzip -c backups/codeinsight_YYYY-MM-DD_HHMMSS.sql.gz | psql -U codeuser -d codeinsight
```

---

## Security Checklist

- [ ] `NODE_ENV=production` set in production
- [ ] `CORS_ORIGINS` restricted to frontend URL only
- [ ] `JWT_SECRET` is a strong, unique random string (never commit to source)
- [ ] `DB_PASSWORD` is a strong, unique password
- [ ] `DB_SSL=true` for Neon connections
- [ ] HTTPS configured at reverse proxy or Cyclic.sh (automatic)
- [ ] Rate limiting enabled on login, submission, and run endpoints
- [ ] HTTP security headers (helmet) enabled
- [ ] SQL injection: all queries parameterized (no string interpolation)
- [ ] Error leakage: production errors never sent to clients
- [ ] Regular `npm audit` runs (automated in CI)

---

## Troubleshooting

### Backend Won't Start
- [ ] Check: `pm2 status` or `docker compose ps` (process running?)
- [ ] Check: PostgreSQL accepting connections: `pg_isready`
- [ ] Check: Redis available: `redis-cli ping`
- [ ] Check: `.env` has all required variables
- [ ] Check: `lsof -i :5000` (port in use?)

### Database Connection Failed
- [ ] Check: PostgreSQL service running: `sudo systemctl start postgresql`
- [ ] Check: Correct credentials in `.env`
- [ ] Check: `DB_SSL=true` for remote databases (Neon)
- [ ] Test: `psql -U codeuser -d codeinsight -c "SELECT 1"`
- [ ] Check: Firewall not blocking port

### Code Execution Fails
- [ ] Check: `g++ --version` returns version
- [ ] Check: `/tmp/` directory is writable
- [ ] Check: Docker daemon running (sandbox mode) or native g++ available
- [ ] Check: Backend logs for compile/runtime errors
- [ ] Cyclic.sh: uses native compilation (no Docker)

### CDS Not Computing
- [ ] Check: Exercise is closed (manually or via deadline auto-close)
- [ ] Check: Minimum 5 submitters for "Confident" tier
- [ ] Check: `cds_scores` table has entries for the exercise
- [ ] Check: Redis is running (BullMQ queue for async CDS)

### Redis Connection Issues
- [ ] Check: `redis-cli ping` returns `PONG`
- [ ] Check: `REDIS_HOST` and `REDIS_PORT` in `.env`
- [ ] Note: Queue init is non-fatal (submission sync path still works without Redis)

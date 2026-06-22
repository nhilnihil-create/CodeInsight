# CodeInsight - CLAUDE.md

**Project Status**: 100% Complete — Deployment Ready (PRR Issues Remediated)
**Last Updated**: June 22, 2026
**Production Readiness Review**: PASS — all P0-P2 items remediated
**Critical Issues Remaining**: 0

## 🎯 QUICK STATUS
- **Overall Completion**: ✅ 100%
- **Database**: ✅ 12/12 tables present
- **APIs**: ✅ 50+ endpoints implemented
- **Frontend Build**: ✅ Passing (pure desktop, all mobile infra removed)
- **Testing**: ✅ 882/882 tests passing (53 suites, all green)
- **Deployment Checklist**: ✅ All items complete

## 🔧 ARCHITECTURAL IMPROVEMENTS (June 22, 2026)

### Fixed
1. **SQL Interpolation Eliminated** — `analyticsEngine.js`, `behavioralAnomalyDetector.js`: 3 unsafe `INTERVAL.*${` patterns replaced with parameterized queries
2. **Wrong CHECK Constraints Fixed** — `migrations.js`: `us_2..us_5` and `pe_2/pe_3` now reference correct columns
3. **Transaction Atomicity** — `cdsEngine.js`: `computeBatchCDS` wraps scores+snapshots+alerts in a transaction
4. **Unified Graduated Flagging** — Created `backend/lib/submissionPipeline.js` shared module. Both sync (`submissionController.js`, −40 lines) and async (`submissionWorker.js`, −25 lines) paths now produce identical integrity outcomes
5. **Notification Dedup** — `cdsJobQueue.js`: 5-minute cooldown prevents spamming students on repeated CDS computations
6. **Hidden Test Leak Fixed** — `routes/student.js`: `/run` endpoint no longer exposes individual hidden test pass/fail
7. **Double generateAlerts Removed** — `autoCloseService.js`: duplicate call eliminated (already inside `computeBatchCDS`)

### New Files
- `backend/lib/integrityFlags.js` — Single source of truth for `FLAG_TYPES`, `SEVERITY`, `FLAG_STATUS` constants
- `backend/lib/submissionPipeline.js` — Shared pipeline: `graduatedFlag()`, `runAcademicIntegrityChecks()`, `runBehavioralChecks()`, `runPassiveBehaviorCheck()`
- `test/e2eArchitectural.test.js` — 6 E2E tests: transaction atomicity, integrity→CDS exclusion, notification dedup, preliminary classes, post-solution cutoff

## 📁 KEY FILES

- **Database Schema**: `backend/schema.sql`
- **Academic Integrity Engine**: `backend/services/academicIntegrityEngine.js`
- **Integrity Flag Engine**: `backend/services/integrityFlagEngine.js`
- **Submission Pipeline** (new): `backend/lib/submissionPipeline.js`
- **Flag Constants** (new): `backend/lib/integrityFlags.js`
- **CDS Job Queue**: `backend/services/cdsJobQueue.js`
- **CDS Engine**: `backend/services/cdsEngine.js`
- **AST Verifier**: `backend/services/astVerifier.js`
- **Micro-Concept Engine**: `backend/services/microConceptEngine.js`

## 📈 CDS FORMULA
```
CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)
```
- NER: Normalized Error Rate | NRS: Normalized Repetition Rate | NTS: Normalized Time Spent

## 🚀 DEPLOYMENT CHECKLIST — ALL COMPLETE
- [x] Fix Code Paste Detection
- [x] Implement Notification Queue
- [x] Remove all mobile infrastructure (pure desktop)
- [x] Verify hidden test separation
- [x] Run full E2E test
- [x] Eliminate SQL injection vectors
- [x] Fix wrong CHECK constraints
- [x] Add transaction atomicity to CDS writes
- [x] Unify graduated flagging across sync/async paths
- [x] Add notification deduplication

## 🏭 PRODUCTION READINESS REVIEW (June 22, 2026) — ALL REMEDIATED

### P0 — Blocking Issues (fixed)
- [x] **Add indexes to `submissions` table** — 5 indexes added: `(student_id, exercise_id)`, `(exercise_id)`, `(student_id)`, `(submitted_at DESC)`, `(exercise_id, is_correct)`
- [x] **Add rate limiting** — `express-rate-limit` on `/run`, `/submit`, `/submit-async`, `/behavioral-events` (10 req/min submissions, 60 req/min behavioral)
- [x] **Replace ad-hoc logging with pino** — structured JSON logger in `backend/lib/logger.js`, pino-http request logging in `server.js`, 20+ files migrated from `console.*`
- [x] **Add production health checks** — `/api/ready` verifies DB + queue connectivity (503 if DB down)
- [x] **Add uncaughtException/unhandledRejection handlers** — fatal log + graceful shutdown with 10s force timeout
- [x] **Fix error leakage** — `search.js`, `export.js`, `UploadsController.js`, `submissionController.js`: 10+ endpoints no longer leak `err.message` to clients
- [x] **Fix Postgres detail leakage** — `errorHandler.js` no longer forwards `err.detail` to client
- [x] **Update Express to ^4.21.0** — resolves CVE-2024-29041
- [x] **Add helmet middleware** — security headers (CSP, HSTS, X-Content-Type-Options)
- [x] **Add DB connection timeout + SSL config** — `connectionTimeoutMillis: 5000`, `ssl` support via `DB_SSL=true`
- [x] **Add npm audit to CI** — checks production dependencies in CI pipeline

### P1 — Production Infrastructure (fixed)
- [x] **Dockerfile** — multi-stage build, node:22-alpine, non-root user, HEALTHCHECK
- [x] **docker-compose.yml** — postgres:16 + redis:7-alpine + backend with volumes and healthchecks
- [x] **PM2 ecosystem.config.js** — cluster mode (2 instances in prod), 1G memory cap, log rotation
- [x] **Backup script** — `scripts/backup.sh`: pg_dump + gzip + 7-day retention
- [x] **systemd unit template** — `scripts/codeinsight.service`
- [x] **.dockerignore** — standard Node.js ignores

### P2 — Performance & Observability (fixed)
- [x] **Fix O(n³) in conceptAnalytics.js** — `computeCMI` and `computeVelocity` reduced from N×M×2 queries to 3-4 queries total via batch prefetch
- [x] **Missing DB indexes added** — `exercises(section_id, concept_id)`, `cds_scores(section_id)`, `alerts(section_id, is_reviewed)`, `behavioral_events(student_id, exercise_id, event_type)`, `integrity_flags(section_id, status)`
- [x] **lastNotifiedAt Map memory leak** — 30-minute cleanup interval for stale notification entries in `cdsJobQueue.js`
- [x] **Updated `.env.example`** — added `REDIS_HOST`, `CORS_ORIGINS`, `LOG_LEVEL`, `DB_SSL`, `DB_CONNECTION_TIMEOUT_MS`
- [x] **Updated DEPLOYMENT.md** — production Docker/PM2/backup/monitoring instructions

### Remaining Non-Blocking Items
- [ ] Docker container pooling for sandbox (N+1 containers per submission)
- [ ] PgBouncer for connection pooling at scale
- [ ] OpenAPI/Swagger documentation
- [ ] Frontend component test coverage (currently 6 test files)
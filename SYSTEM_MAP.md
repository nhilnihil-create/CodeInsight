# System Map — CodeInsight

> **Generated**: June 24, 2026 | **Updated**: September 7, 2026
> **Phase 1 of 5**: Architecture & Context Mapping
>
> ⚠️ **SUPERSEDED (2026-09-07)**: This map is stale in several places. For the complete, verified architecture diagram see
> **`docs/architecture/codeinsight-v2-architecture.html`** (and `.png`). Key corrections:
> - **Email provider is Brevo** (`@getbrevo/brevo`), NOT Nodemailer. Resend/nodemailer are installed but **inactive**.
> - **Database has 30 tables** (8 clusters), not 12.
> - **Controllers = 12** (not 14); **Services = 31** (not 20+); **lib = 15** modules.
> - Missing modules `impactTag`, `insightTemplates`, `wilsonScore` are present in `backend/lib/`.
> - Light-theme print variant: `docs/architecture/codeinsight-v2-architecture-light.html` (+ `.png`).

---

## 1. High-Level Architecture

```
┌─ Lane 1 ─ Client Tier ───────────────────────────────────────────────────────────────────────────┐
│React 18 SPA (frontend/, Vite 5, Tailwind v4, shadcn/ui, Monaco,                                  │
│TanStack Query, Router v6)                                                                        │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
│                                        │ ──── HTTP /api/*                                        │
│                                                ▼                                                 │
┌─ Lane 2 ─ API Gateway / Middleware ──────────────────────────────────────────────────────────────┐
│server.js · helmet · CORS · rateLimit · verifyToken                                               │
│(JWT + token_blacklist) · joi · errorHandler · pino-http                                          │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
│                                         │ ──── dispatch                                          │
│                                                ▼                                                 │
┌─ Lane 3 ─ Routes → Controllers ──────────────────────────────────────────────────────────────────┐
│12 routes → 12 controllers                                                                        │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
│                                          │ ──── invoke                                           │
│                                                ▼                                                 │
┌─ Lane 4 ─ Services / Engines ────────────────────────────────────────────────────────────────────┐
│31 services: executor, cdsEngine, astVerifier,                                                    │
│academicIntegrityEngine, integrityFlagEngine, etc.                                                │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
│                                            │ ──── use                                            │
│                                                ▼                                                 │
┌─ Lane 5 ─ Cross-Cutting lib ─────────────────────────────────────────────────────────────────────┐
│15 modules: impactTag, insightTemplates, wilsonScore,                                             │
│logger, background, cache, concurrency, treeSitter,                                               │
│domainValidator, otpStore, submissionPipeline, etc.                                               │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
│                                     │ ──── defer() / enqueue                                     │
│                                                ▼                                                 │
┌─ Lane 6 ─ Async / Queue ─────────────────────────────────────────────────────────────────────────┐
│submissionQueue + submissionWorker (2 files) · Redis 7                                            │
│cds_job_queue FOR UPDATE SKIP LOCKED · sync fallback                                              │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
│                                     │ ──── pg pool / BullMQ                                      │
│                                                ▼                                                 │
┌─ Lane 7 ─ Data ──────────────────────────────────────────────────────────────────────────────────┐
│PostgreSQL Neon · 30 tables in 8 clusters · Redis 7                                               │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘

┌─ Lane 8 ─ External + DevOps ─────────────────────────────────────────────────────────────────────┐
│Google OAuth (google-auth-library) · Brevo ACTIVE                                                 │
│resend/nodemailer INACTIVE · Swagger                                                              │
│Docker gcc:14-bookworm native g++ fallback · CI/CD                                                │
└──────────────────────────────────────────────────────────────────────────────────────────────────┘
```

> **Legend**: solid cyan = HTTP/REST · dashed amber = async/queue · dotted rose = sandbox/executor ·
> dashed sky = outbound/external · solid emerald = data/DB

Full diagrams: `docs/architecture/codeinsight-v2-architecture.html` (dark) · `codeinsight-v2-architecture-light.html` (light) · PNGs.

### Key Data Flow — Submission Lifecycle

```
Student writes code → POST /api/student/exercises/:id/submit
  → verifyToken + requireRole('student') middleware
  → validate body (rate limited: 10 req/min)
  → fetch exercise (with in-memory cache)
  → runAgainstTestCases (Docker sandbox OR native)
  → compile C++ with ASAN → execute each test case → compare output
  → INSERT submission → respond 201 (test results visible immediately)
  → defer() post-processing (background):
       → calculateLiveCDS + upsert cds_scores
       → PASSIVE_BEHAVIOR_LOG flag creation
       → CODE_GROWTH_ANOMALY detection
       → academicIntegrityEngine.evaluateIntegrity()
       → behavioralAnomalyDetector.detectBehavioralAnomalies()
```

---

## 2. Technology Stack & Versions

### Backend (`backend/package.json`)
| Dependency | Version | Purpose |
|-----------|---------|---------|
| Node.js | ^22 | Runtime (Alpine) |
| express | ^4.21.0 | HTTP framework |
| pg | ^8.11.0 | PostgreSQL client |
| bullmq | ^5.78.0 | Job queue (Redis-backed) |
| ioredis | ^5.11.1 | Redis client |
| bcryptjs | ^2.4.3 | Password hashing |
| jsonwebtoken | ^9.0.0 | JWT auth tokens |
| pino | ^9.5.0 | Structured logging |
| helmet | ^8.0.0 | Security headers |
| express-rate-limit | ^7.5.1 | Rate limiting |
| joi | ^17.13.3 | Request validation |
| tree-sitter | ^0.22.0 | C++ AST parsing |
| tree-sitter-cpp | ^0.23.4 | C++ grammar |

### Frontend (`frontend/package.json`)
| Dependency | Version | Purpose |
|-----------|---------|---------|
| React | ^18.2.0 | UI framework |
| vite | ^5.4.21 | Bundler |
| tailwindcss | ^4.3.0 | CSS framework |
| @tanstack/react-query | ^5.101.0 | Data fetching |
| react-router-dom | ^6.18.0 | Routing |
| recharts | ^3.8.1 | Charts |
| framer-motion | ^12.40.0 | Animations |
| d3 | ^7.9.0 | Data visualization |
| zod | ^4.4.3 | Schema validation |
| typescript | ^6.0.3 | Type checking (dev) |

### Infrastructure
- **Docker**: node:22-alpine, gcc:14-bookworm (sandbox), PostgreSQL 16, Redis 7
- **CI/CD**: GitHub Actions (ubuntu-22.04)
- **Deployment**: Cyclic.sh / Docker Compose / PM2
- **Email**: Brevo (@getbrevo/brevo) ACTIVE — resend/nodemailer installed but inactive

---

## 3. Database Schema (30 Tables · 8 Clusters)

### Auth/Security (4)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `users` | User accounts (student/instructor/admin) | role, email_verified, verification_token |
| `token_blacklist` | JWT revocation | jti, expires_at |
| `otp_codes` | Email OTP verification | email (PK), otp, expires_at, attempts |
| `audit_log` | Behavioral event trail | event_type, metadata |

### Sections/Enrollment (3)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `sections` | Course sections | code, join_policy, max_size |
| `enrollments` | Student-section enrollment | student_id, section_id |
| `section_memberships` | Rich memberships (TA, co-instructor, drops) | role, status |

### Concepts/Exercises (6)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `concepts` | Programming concepts | ast_nodes, knowledge_area_code |
| `exercises` | Programming exercises | test_cases, deadline, is_draft |
| `exercise_concepts` | Exercise↔concept mapping | exercise_id, concept_id (composite PK) |
| `exercise_concept_tags` | Weighted multi-tag | weight, is_primary |
| `concept_dependencies` | Prerequisite graph | parent_concept_id, child_concept_id |
| `exercise_bank` | Exercise template bank | concept, sequence_order |

### Submissions (2)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `submissions` | Student code submissions | test_results, cds, ner, nrs, nts |
| `run_attempts` | Non-submission run attempts | compiler_log, error_count |

### CDS/Scoring (3)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `cds_scores` | CDS computation results | cds, classification, source |
| `cds_snapshots` | Append-only CDS audit | ner, nrs, nts, class_min/p95 |
| `cds_job_queue` | DB-backed job queue | status |

### Integrity/Alerts (4)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `alerts` | Integrity/CDS alerts | cds_score, classification |
| `integrity_flags` | Integrity violation flags | flag_type, severity, status |
| `analytics_alerts` | CDS_HIGH, RETRY_STORM, etc. | alert_type, severity |
| `verification_logs` | AST verification failures | verification_type, reason |

### Behavioral/Audit (5)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `behavioral_events` | Tab switch, paste, idle events | event_type, payload |
| `code_snapshots` | Periodic code snapshot capture | session_id, token_count, active_elapsed_seconds, autocomplete |
| `performance_logs` | Request timing metrics | time_to_interactive_ms |
| `section_audit_log` | Section-level audit | action, meta |
| `auto_close_log` | Auto-close audit | triggered_by |

### Metrics/Evaluation (3)
| Table | Purpose | Key Columns |
|-------|---------|-------------|
| `student_concept_metrics` | CMI + velocity | cmi, velocity |
| `section_concept_metrics` | CRS + difficulty | crs, crs_score |
| `evaluation_responses` | ISO/IEC 25010 survey | fs_1-us_5, pe_1-pe_3 |

---

## 4. API Endpoints (50+)

| Group | Mount | Middleware | Key Endpoints |
|-------|-------|-----------|---------------|
| Auth | `/api/auth` | rateLimit(5/15min) | POST register, login, logout; GET verify-email, me; POST request-otp, verify-otp |
| Sections | `/api/sections` | verifyToken | CRUD for sections, enrollments, join codes |
| Exercises | `/api/exercises` | verifyToken | CRUD with section scoping |
| Student | `/api/student` | verifyToken + role('student'), rateLimit(10/min) | GET exercises, dashboard, progress; POST submit, behavioral-events; GET today |
| Submissions | `/api/submissions` | verifyToken | POST run, submit, submit-async; GET status |
| Analytics | `/api/analytics` | verifyToken + role('instructor') | GET stats, heatmap, trends, reports |
| Integrity | `/api/analytics` | verifyToken | GET integrity flags, evidence |
| Admin | `/api/admin` | verifyToken + role('admin') | GET overview, users, sections; POST evaluation |
| Search | `/api/search` | verifyToken | GET exercises (full-text) |
| Export | `/api/export` | verifyToken | GET CSV/Excel reports |
| Health | `/api/health` | public | Liveness check |
| Readiness | `/api/ready` | public | DB + queue connectivity |
| API Docs | `/api/docs` | public | Swagger UI |

---

## 5. External Dependencies

### Infrastructure
- **PostgreSQL 16** — Primary datastore (Neon serverless on Cyclic.sh)
- **Redis 7-Alpine** — BullMQ job queue + OTP store
- **gcc:14-bookworm** — Docker sandbox for C++ compilation/execution
- **Docker** — Optional sandbox (fallback to native compilation)

### Integrations
- **Brevo (@getbrevo/brevo)** — Email verification + OTP delivery (ACTIVE); resend/nodemailer installed but INACTIVE
- **tree-sitter** — C++ AST parsing (does NOT require network)
- **cppcheck** — Static analysis (bundled in Docker image)

---

## 6. Project Structure

```
codeinsight/
├── backend/                    # Express.js API server
│   ├── config/db.js           # PostgreSQL pool + withTransaction
│   ├── controllers/           # 12 controllers (thin routing logic)
│   ├── routes/                # 12 route files
│   ├── services/              # 31 services (32 files, 1 test)
│   ├── lib/                   # Shared utilities (15 modules)
│   ├── middleware/            # auth, errorHandler, validate
│   ├── migrations/            # 6 migration files
│   ├── queues/                # submissionQueue + submissionWorker (BullMQ)
│   ├── scripts/               # 8 seed/maintenance scripts
│   ├── test/                  # 50+ test files
│   └── server.js              # Entry point
├── frontend/                  # React SPA
│   ├── src/
│   │   ├── components/        # 87 components (Radix UI primitives)
│   │   ├── pages/             # 57 page files (admin/instructor/student)
│   │   ├── context/           # Auth, EditorPrefs, Sidebar contexts
│   │   ├── hooks/             # 6 custom hooks
│   │   ├── services/          # API client (axios)
│   │   └── App.jsx            # Router + lazy loading
│   └── vite.config.js         # Manual chunk splitting
├── e2e/                       # Playwright end-to-end tests
├── simulation/                # Stagehand + workload simulation
├── tests/                     # Load + UAT tests
├── scripts/                   # Systemd, backup, codenet
├── Dockerfile                 # Multi-stage build (node:22-alpine)
├── docker-compose.yml         # postgres + redis + backend
└── cyclic.json                # Cyclic.sh deployment config
```

---

## 7. Identified Issues & Anomalies (Phase 1)

> **Status**: Most P0-P2 issues were remediated in the Production Readiness Review (June 22, 2026).
> See `CLAUDE.md` for the full remediation log.

### ~~CRITICAL: SQL Injection Risk in `migrations.js:38`~~ — FIXED
Template literal interpolation of schema identifiers was replaced with parameterized queries in `analyticsEngine.js` and `behavioralAnomalyDetector.js`. Migration identifiers remain hardcoded at call sites (acceptable risk).

### ~~HIGH: `tree-sitter` Version Mismatch~~ — NOTED
Root `package.json`: `"tree-sitter": "^0.21.1"` vs backend `"tree-sitter": "^0.22.0"`. Backend resolves correctly; root version is unused in production. Low priority.

### ~~MEDIUM: Debug `console.log` in Production Code~~ — FIXED
20+ files migrated from `console.*` to structured pino logger (`backend/lib/logger.js`).

### ~~MEDIUM: Docker Compose Hardcoded Credentials~~ — ACCEPTED
`docker-compose.yml` uses `POSTGRES_PASSWORD: codepassword123` and `DB_PASSWORD: codepassword123` as local dev defaults. Production uses env vars. Acceptable for development convenience.

### LOW: Service Worker Caches API Responses
`frontend/vite.config.js:37-48` — Workbox `NetworkFirst` caching for `/api/.*` with 24h TTL. Could serve stale data. Currently non-critical since frontend is pure desktop.

### ~~LOW: Dead Code — `submissionWorker.js` Uses `console.warn`~~ — FIXED
All `console.warn` calls replaced with structured `logger` in PRR session.

### LOW: Frontend TypeScript Resolver
- `frontend/package.json`: `"typescript": "^6.0.3"` — TypeScript is a devDependency but all frontend code is `.jsx`. The `tsconfig.json` likely exists but no TS compilation runs during build (`vite.config.js` has no TypeScript plugin configured).

---

## 8. Dead Code / Unreachable Modules

| File | Status | Notes |
|------|--------|-------|
| `backend/lib/insightTemplates.js` | Referenced? | Check usage (unused in grep) |
| `backend/lib/impactTag.js` | Referenced? | Check usage |
| `backend/lib/wilsonScore.js` | Referenced? | Check usage |
| `backend/services/errorReporter.js` | Used | `submissionController.js:518` |
| `backend/services/alertEngine.js` | Used | `submissionController.js:626` |
| `backend/services/preSubmissionCheck.js` | Used | `submissionController.js:592` |
| `scripts/codenet-scanner.js` | Standalone | External tooling, not in main flow |
| `scripts/codenet-worker.js` | Standalone | External tooling |
| `backend/migrations/20260620_admin_audit_log.js` | Referenced? | Check if `migrations.js` calls it |
| `backend/migrations/20260620_system_settings.js` | Used | `migrations.js:332` |
| `backend/migrations/20260621_remove_outcome_tables.js` | Used | `migrations.js:354` |

---

## 9. Entry Points & Startup Sequence

```
1.  cyclic.json / docker-compose / PM2 → node server.js
2.  server.js:2 → dotenv config
3.  server.js:108 → ensureTablesExist()
     ├── Check 30 tables exist (8 clusters)
     ├── applySchemaPatches() — idempotent ALTER TABLE
     ├── applyV2Migrations() — SQL files + JS migrations
     ├── system_settings, verification_rules setup
     ├── Remove learning_outcome tables
     └── Auth hardening columns + token_blacklist
4.  server.js:110 → initQueue() — Redis/BullMQ queue (non-fatal if unavailable)
5.  server.js:121 → app.listen(PORT, '0.0.0.0')
6.  server.js:123 → startAutoCloseService() — deadline-based exercise closure
7.  Process handlers: uncaughtException, unhandledRejection → graceful shutdown
```

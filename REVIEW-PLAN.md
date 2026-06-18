# PR Review Plan - CodeInsight

> AI-powered educational platform for programming courses with academic integrity monitoring, code similarity detection, and learning analytics.

## Checklist

### 1. Backend Architecture (Express + PostgreSQL)
- [ ] Routes use authentication/authorization middleware (`authMiddleware`)
- [ ] Controllers follow request → validation → service → response pattern
- [ ] Services are stateless and testable with dependency injection where possible
- [ ] Database queries use parameterized statements (no raw string interpolation)
- [ ] Transaction boundaries are explicit (`BEGIN/COMMIT/ROLLBACK` via `pg` pool)
- [ ] Error handling uses `AppError` class with status codes
- [ ] Async handlers are wrapped with `asyncHandler`
- [ ] Input validation uses Joi schemas (`lib/validators.js`)
- [ ] Migrations are sequential and idempotent (`migrations.js`)

### 2. Academic Integrity / CDS Pipeline
- [ ] CDS formula preserved: `CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)`
- [ ] Integrity flags use proper severity levels (info/warning/critical)
- [ ] Behavioral anomaly detection has fallback when history insufficient
- [ ] Code paste detection handles missing `reference_solution` column gracefully
- [ ] CDS auto-trigger flow respects exercise state (not reopened/closed)

### 3. Frontend Architecture (React + Vite + Tailwind CSS v4)
- [ ] Components use Radix UI primitives for accessibility
- [ ] Design tokens used exclusively (no hardcoded colors or spacing)
- [ ] API calls go through `api/` service layer (not raw fetch in components)
- [ ] Mobile screens use mobile-specific config (`config/mobile/`)
- [ ] Dark mode supported via `@media (prefers-color-scheme)` or theme toggle
- [ ] No console.log committed in production code

### 4. Security
- [ ] JWT tokens validated on every protected endpoint
- [ ] SQL injection prevented via parameterized queries
- [ ] No secrets in code (DB creds, JWT secret via environment only)
- [ ] File uploads validated (type, size) via multer config
- [ ] Rate limiting applied on auth endpoints
- [ ] Sandbox executor has timeout and resource limits

### 5. Testing
- [ ] Backend tests use Jest with `--runInBand`
- [ ] Frontend tests use Vitest
- [ ] E2E tests use Playwright (`e2e/`, `tests/`)
- [ ] New API endpoints have at minimum a 200-status smoke test
- [ ] Edge cases covered: null/empty inputs, auth failures, not-found

### 6. Database
- [ ] Schema changes in `schema.sql` with matching migration in `migrations.js`
- [ ] Indexes on foreign keys and frequently queried columns
- [ ] FOR UPDATE used on critical read-then-write operations
- [ ] Audit log entries include timestamp, user_id, action, details

### 7. Code Quality
- [ ] Consistent naming: camelCase for JS/JSX
- [ ] No commented-out code blocks
- [ ] Single responsibility per function
- [ ] No circular dependencies between services

## Severities

| Level | Description | Action |
|-------|------------|--------|
| **Critical** | Security vulnerabilities, data loss, CDS formula corruption, SQL injection | Must fix before merge |
| **Warning** | Pattern violations, missing tests, hardcoded values, architectural drift | Should fix |
| **Suggestion** | Minor improvements, style, naming, optimization opportunities | Consider fixing |

## Project-Specific Rules

- All new API routes must be added to `backend/routes/` and registered in `server.js`
- Database access must go through `pg` pool queries in service files, never in controllers
- Frontend API endpoints must be defined in `frontend/src/api/` service modules
- Tailwind CSS v4 `@theme` directive for all design tokens
- E2E test files go in `e2e/` or `tests/` with `.spec.js` extension
- Backend unit tests go in `backend/test/` with `.test.js` extension
- Behavioral anomaly detection must degrade gracefully when `exercise_count < 3`

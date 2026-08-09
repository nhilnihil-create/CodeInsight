# AGENTS.md — CodeInsight

## What this is
CodeInsight is a programming-exercise submission analysis platform: academic-integrity checks, plagiarism detection, and CDS (cheating-detection score) computed on student submissions. Node/Express backend + Vite React frontend. PostgreSQL on Neon (remote).

## Environment (read first)
- Repo lives in WSL at `/home/nihil/projects/codeinsight`; opencode runs on Windows.
- Access files via `\\wsl$\Ubuntu\home\nihil\projects\codeinsight\...`.
- Run shell commands with: `wsl -e bash -lc "cd /home/nihil/projects/codeinsight && ..."`
- `rg` is NOT installed in WSL — use `grep`.
- Config for opencode lives in `opencode.json` (project) and `~/.config/opencode/opencode.json` (global).

## Repo layout
- `backend/` — Express API (entry `server.js`), Jest tests in `backend/test/`
- `backend/services/` — integrity / plagiarism / CDS engines (see Key files)
- `backend/lib/` — shared pipeline + flag constants (`submissionPipeline.js`, `integrityFlags.js`)
- `backend/schema.sql` — DB schema, source of truth
- `frontend/` — Vite React app
- `e2e/`, `tests/`, `simulation/` — Playwright E2E, UAT, simulation suites
- `docs/` — plans and docs (Superpowers hardening plan under `docs/superpowers/plans/`)

## Verify (run before saying "done")
- Backend tests (baseline: **1014 tests / 54 suites green**): `npm run test:backend` from repo root
- Targeted tests: `wsl -e bash -lc "cd /home/nihil/projects/codeinsight/backend && npx jest --runInBand <path>"`
- Lint: `npm run lint` — keep 0 errors, add no new warnings
- E2E (slow; only when UI/flows changed): `npm run test:e2e`

## Code rules
- Follow existing patterns; reuse utilities in `backend/lib/` — don't duplicate logic.
- Keep changes scoped; don't modify unrelated files.
- `backend/services/astVerifier.js` returns `{ is_verified, reasons }`.
- Taxonomy rules live in `microConceptTaxonomy.js`; cross-cutting detectors in `microConceptEngine.js`.
- **Tree-sitter constraint:** the native addon can be loaded only ONCE per process — only `test/astVerifier.test.js` may require it. New test files must NOT load tree-sitter. Always run jest with `--runInBand` (the `npm test` script already does).

## Git
- Branch: `main`. Remote: `https://github.com/nhilnihil-create/CodeInsight.git`
- Never push unless explicitly asked.
- Keep commits focused, conventional style: `feat(scope): ...`, `fix(scope): ...`, `docs(scope): ...` (e.g. `feat(hardening): ...`).
- Stage only intended files; never commit secrets, logs, or `.env`.

## Current state
- 1014 tests / 54 suites green; lint 0 errors.
- Latest work: deterministic rule hardening (Tasks 1–5 complete — see `docs/superpowers/plans/2026-06-18-deterministic-rule-hardening.md`).

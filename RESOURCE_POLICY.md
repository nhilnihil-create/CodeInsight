# CodeInsight — OpenCode Resource & Execution Policy

**Target host:** Windows 12 GB RAM, WSL2 capped at 8 GB + 4 GB swap.
**Created:** 2026-06-07 (Memory Stability Audit)
**Status:** MANDATORY for all OpenCode sessions in this repo.

---

## HARD RULES (NEVER VIOLATE)

1. **One heavy task at a time.** A "heavy task" is any of:
   - `npm test` / `jest` (any package)
   - `npm run dev` / `vite` / `nodemon`
   - `npm run build` / `vite build`
   - `playwright test` / `playwright install`
   - Database migrations or seed scripts
   - `npm install` / `npm ci`

2. **Forbidden combinations.** Never run any of these together:
   - `npm test` + `npm run dev`
   - `npm run build` + `npm test`
   - `playwright test` + `jest` (any form)
   - `vite build` + `vite dev`
   - Any two of the above in parallel shells or `&` background

3. **Memory ceiling.** If `free -m` reports `used / total >= 70%`:
   - **STOP** the current task immediately.
   - Report the offending processes.
   - Do **NOT** start another heavy task.

4. **Mandatory cleanup gates.** After every heavy task:
   - Run `ps aux | grep -E "(node|jest|vite|playwright)" | grep -v grep`
   - Verify zero leftover workers/servers.
   - Re-check memory with `free -m`.
   - Only then proceed.

5. **Jest is `--runInBand` ONLY.** Defined in `backend/package.json`:
   - `test`: leak-detection mode (`--detectOpenHandles`)
   - `test:ci`: fast mode (`--forceExit`)
   - `test:debug`: heap-tracked (`--logHeapUsage --expose-gc`)
   - Never invoke `jest` without `--runInBand` in this repo.

6. **No `--forceExit` during investigations.** It masks leaks. Only use `test:ci` when leaks are known to be zero.

7. **Background processes require explicit teardown.** If you start `npm run dev` for any reason, you must `kill` it before moving on. No `&` without a documented `kill $!` follow-up.

---

## REQUIRED CHECKPOINTS

Before starting any heavy task, run:

```bash
free -m | awk 'NR==2 {pct=$3/$2*100; printf "MEM: %d/%d MB (%.1f%%)\n", $3, $2, pct; if (pct>=70) {print "ABORT: memory ceiling"; exit 1}}'
ps aux | grep -E "(node|jest|vite|playwright|nodemon)" | grep -v grep | grep -v opencode
```

After finishing any heavy task, run:

```bash
ps aux | grep -E "(node|jest|vite|playwright|nodemon)" | grep -v grep | grep -v opencode
free -m | awk 'NR==2 {printf "POST-MEM: %d/%d MB (%.1f%%)\n", $3, $2, $3/$2*100}'
```

If the post-task `ps` returns any line, kill it before proceeding:

```bash
pkill -f "jest|vite|nodemon|playwright" 2>/dev/null
```

---

## SAFE COMMAND CATALOG

| Task | Approved command |
|------|------------------|
| Backend tests (leak detection) | `cd backend && npm test` |
| Backend tests (fast, known clean) | `cd backend && npm run test:ci` |
| Backend tests (heap profiling) | `cd backend && npm run test:debug` |
| Frontend build (production) | `cd frontend && npm run build` — **NEVER while tests run** |
| Frontend dev server | `cd frontend && npm run dev` — **single-shell only** |
| Backend dev server | `cd backend && npm run dev` — **never with frontend dev** |
| Playwright | Run **only after** killing all node/vite/jest processes |

---

## FORBIDDEN ANTI-PATTERNS

```bash
# WRONG — parallel heavy tasks
npm test & npm run dev &

# WRONG — concurrent test runners
jest & vitest &

# WRONG — recursive jest exec inside a test file
exec('npx jest ' + __filename, ...)   # caused the historical OOM

# WRONG — Jest with default parallel workers on 8GB WSL
jest                                  # spawns CPUs-1 = 7 workers × 512MB = 3.5GB

# WRONG — masking leaks
jest --forceExit                      # use --detectOpenHandles instead during audits
```

---

## ESCALATION

If memory exceeds 70% during a task:
1. Kill the offending PID with `kill -TERM <pid>`; if it survives 10s, `kill -9 <pid>`.
2. Run `sync && sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'` to release page cache.
3. If WSL is still pinned > 70%, run `wsl --shutdown` from Windows PowerShell.
4. Re-read this policy before resuming.

---

## PASTE-READY BLOCK FOR FUTURE OPENCODE SESSIONS

```
RESOURCE POLICY (CodeInsight, WSL2 8GB):
- Run ONE heavy task at a time (test | dev | build | playwright | install).
- Never run npm test + npm run dev simultaneously.
- Never run build + test simultaneously.
- Never run playwright during jest.
- Jest MUST use --runInBand (already enforced in backend/package.json scripts).
- Before any heavy task: check `free -m`; abort if >=70% used.
- After any heavy task: verify `ps aux | grep -E "node|jest|vite|playwright"` is empty; kill survivors with pkill.
- Do NOT use --forceExit during leak investigations — it hides open handles.
- If memory exceeds 70%, STOP, report, kill, then `wsl --shutdown` from PowerShell if needed.
- See RESOURCE_POLICY.md for the full ruleset.
```

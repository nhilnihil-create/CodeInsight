# CodeInsight Frontend — Preview Run Doc

## How to reproduce the artifacts

The frontend needs no copied env files and no build artifacts to run in dev.
`frontend/node_modules` is already installed. If a fresh checkout lacks it:

```bash
cd frontend && npm install
```

The Vite dev server (`npm run dev`) compiles on demand — no `vite build` step
is required for preview.

## How to run the server

From `frontend/`, start the Vite dev server detached (Windows):

```powershell
powershell -NoProfile -Command "(Start-Process -FilePath 'npm.cmd' -ArgumentList 'run','dev' -WorkingDirectory 'C:\Users\Rokhai\CodeInsight-V2\frontend' -RedirectStandardOutput 'C:\Users\Rokhai\CodeInsight-V2\.freebuff\preview-d8ae32e4-ed61-4f53-8329-e93a76f4c899.log' -RedirectStandardError 'C:\Users\Rokhai\CodeInsight-V2\.freebuff\preview-d8ae32e4-ed61-4f53-8329-e93a76f4c899.log.err' -WindowStyle Hidden -PassThru).Id"
```

- Server: `http://localhost:5173` (vite.config.js sets `host: 0.0.0.0`; the
  configured port is Vite's default 5173).
- The SPA serves every route (login, instructor/*, student/*) via history
  fallback; the first hit compiles in ~5–8s, later hits are fast.
- `/api` is proxied to `http://127.0.0.1:5000` (the backend). With the backend
  down, `/api/auth/me` returns 500 and the app shows the login screen — the
  shell still renders fine. Start the backend on 5000 for authenticated pages.
- Log files: `preview-d8ae32e4-ed61-4f53-8329-e93a76f4c899.log` (+ `.err`) in
  `.freebuff/`. Kill the server by terminating the node PID from the netstat
  listener on 5173.

## Verification

```bash
curl -s -m 30 -o /dev/null -w "%{http_code}\n" http://127.0.0.1:5173/login   # → 200
```

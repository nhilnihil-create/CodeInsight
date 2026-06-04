-- Migration: add reference_solution column to exercises table for code paste detection
BEGIN;

ALTER TABLE exercises
  ADD COLUMN IF NOT EXISTS reference_solution TEXT;

COMMIT;

-- Down script (manual rollback):
-- ALTER TABLE exercises DROP COLUMN IF EXISTS reference_solution;
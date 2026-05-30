-- Migration: add source and visible to cds_scores
BEGIN;

ALTER TABLE cds_scores
  ADD COLUMN IF NOT EXISTS source VARCHAR(10) NOT NULL DEFAULT 'batch',
  ADD COLUMN IF NOT EXISTS visible BOOLEAN NOT NULL DEFAULT true;

-- Ensure numeric types for cds components
ALTER TABLE cds_scores
  ALTER COLUMN cds TYPE NUMERIC USING cds::numeric;
ALTER TABLE cds_scores
  ALTER COLUMN ner TYPE NUMERIC USING ner::numeric;
ALTER TABLE cds_scores
  ALTER COLUMN nrs TYPE NUMERIC USING nrs::numeric;
ALTER TABLE cds_scores
  ALTER COLUMN nts TYPE NUMERIC USING nts::numeric;

COMMIT;

-- Down script (manual rollback):
-- ALTER TABLE cds_scores DROP COLUMN IF EXISTS source;
-- ALTER TABLE cds_scores DROP COLUMN IF EXISTS visible;

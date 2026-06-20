// Database migrations/setup — verify tables and apply idempotent schema patches
const path = require('path');
require('dotenv').config({ path: path.join(__dirname, '.env') });
const fs = require('fs');
const db = require('./config/db');

async function columnExists(table, column) {
  const result = await db.query(
    `SELECT 1 FROM information_schema.columns
     WHERE table_name = $1 AND column_name = $2`,
    [table, column]
  );
  return result.rows.length > 0;
}

async function constraintExists(table, constraint) {
  const result = await db.query(
    `SELECT 1 FROM information_schema.table_constraints
     WHERE table_name = $1 AND constraint_name = $2`,
    [table, constraint]
  );
  return result.rows.length > 0;
}

async function tableExists(table) {
  const result = await db.query(
    `SELECT EXISTS (
       SELECT 1 FROM information_schema.tables
       WHERE table_name = $1
     ) AS exists`,
    [table]
  );
  return result.rows[0].exists;
}

async function addColumnIfMissing(table, column, definition) {
  if (!(await columnExists(table, column))) {
    await db.query(`ALTER TABLE ${table} ADD COLUMN ${column} ${definition}`);
    console.log(`✓ Added ${table}.${column}`);
    return true;
  }
  return false;
}

/**
 * Idempotent patches for databases created before the latest schema.sql.
 */
async function applySchemaPatches() {
  const patches = [];

  if (await tableExists('exercises')) {
    patches.push(addColumnIfMissing('exercises', 'reference_solution', 'TEXT'));
    patches.push(addColumnIfMissing('exercises', 'starter_code', `TEXT DEFAULT E'#include <iostream>\\nusing namespace std;\\n\\nint main() {\\n  return 0;\\n}'`));
  }

  if (await tableExists('sections')) {
    patches.push(addColumnIfMissing('sections', 'code', 'TEXT'));
    patches.push(addColumnIfMissing('sections', 'term', 'TEXT'));
    patches.push(addColumnIfMissing('sections', 'semester', 'TEXT'));
    patches.push(addColumnIfMissing('sections', 'join_policy', `TEXT NOT NULL DEFAULT 'code' CHECK (join_policy IN ('code', 'request', 'closed'))`));
    patches.push(addColumnIfMissing('sections', 'max_size', 'INTEGER NOT NULL DEFAULT 60'));
    
    // Add NOT NULL constraint to sections.code (if not already present)
    if (await columnExists('sections', 'code')) {
      try {
        // Ensure no NULL codes exist before adding NOT NULL constraint
        await db.query(`UPDATE sections SET code = course_code || '-' || id WHERE code IS NULL`);
        await db.query(`ALTER TABLE sections ALTER COLUMN code SET NOT NULL`);
        console.log('✓ Added NOT NULL constraint to sections.code');
      } catch (err) {
        console.log('✓ sections.code NOT NULL constraint already exists');
      }
    }
    
    // Add UNIQUE constraint to sections.code (if not already present)
    if (await columnExists('sections', 'code')) {
      try {
        await db.query(`ALTER TABLE sections ADD CONSTRAINT sections_code_key UNIQUE (code)`);
        console.log('✓ Added UNIQUE constraint to sections.code');
      } catch (err) {
        console.log('✓ sections.code UNIQUE constraint already exists');
      }
    }
  }

  if (await tableExists('submissions')) {
    patches.push(addColumnIfMissing('submissions', 'code_growth_delta', 'INTEGER DEFAULT 0'));
    patches.push(addColumnIfMissing('submissions', 'is_verified', 'BOOLEAN DEFAULT true'));
    patches.push(addColumnIfMissing('submissions', 'verification_note', 'TEXT'));
    patches.push(addColumnIfMissing('submissions', 'compiler_log', 'TEXT'));
    patches.push(addColumnIfMissing('submissions', 'time_limit_hit', 'BOOLEAN DEFAULT false'));
  }

  if (!(await tableExists('run_attempts'))) {
    await db.query(`
      CREATE TABLE run_attempts (
        id              SERIAL PRIMARY KEY,
        student_id      INT REFERENCES users(id) ON DELETE CASCADE,
        exercise_id     INT REFERENCES exercises(id) ON DELETE CASCADE,
        code            TEXT NOT NULL,
        compiler_log    TEXT,
        error_count     INT DEFAULT 0,
        time_limit_hit  BOOLEAN DEFAULT false,
        run_at          TIMESTAMP DEFAULT NOW()
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_run_attempts_student_exercise ON run_attempts(student_id, exercise_id)`);
    console.log('✓ Created run_attempts table');
  }

  if (await tableExists('cds_scores')) {
    patches.push(addColumnIfMissing('cds_scores', 'has_flagged_attempts', 'BOOLEAN DEFAULT false'));
    patches.push(addColumnIfMissing('cds_scores', 'integrity_flag_count', 'INTEGER DEFAULT 0'));
    patches.push(addColumnIfMissing('cds_scores', 'source', `VARCHAR(20) DEFAULT 'batch'`));
    patches.push(addColumnIfMissing('cds_scores', 'visible', 'BOOLEAN DEFAULT true'));
  }

  if (await tableExists('users')) {
    // Bring CHECK constraint in line with migration 006 (adds 'admin').
    // Idempotent: drops the stale constraint, then adds the up-to-date one.
    // Skipped with a warning if the application role is not the table
    // owner (e.g. on legacy DBs where constraint was added out-of-band
    // by a superuser). Constraint is a strict superset of the original.
    try {
      await db.query(`ALTER TABLE users DROP CONSTRAINT IF EXISTS users_role_check`);
      await db.query(`
        ALTER TABLE users ADD CONSTRAINT users_role_check
        CHECK (role IN ('student','instructor','admin'))
      `);
      console.log('✓ Updated users.role CHECK to include admin');
    } catch (chkErr) {
      console.warn('⚠ Could not update users.role CHECK (likely a permissions issue). Run as superuser:');
      console.warn("  psql -U postgres -d codeinsight -c \"ALTER TABLE users DROP CONSTRAINT users_role_check; ALTER TABLE users ADD CONSTRAINT users_role_check CHECK (role IN ('student','instructor','admin'));\"");
    }
  }

  if (!(await tableExists('evaluation_responses'))) {
    // Migration 006 — ISO/IEC 25010 evaluation instrument (spec §14).
    // Additive only. Required by adminController.overview.
    try {
      await db.query(`
        CREATE TABLE evaluation_responses (
          id            UUID PRIMARY KEY DEFAULT gen_random_uuid(),
          respondent_id INTEGER REFERENCES users(id) ON DELETE SET NULL,
          role          TEXT NOT NULL CHECK (role IN ('student', 'instructor', 'admin')),
          fs_1 INTEGER NOT NULL CHECK (fs_1 BETWEEN 1 AND 4),
          fs_2 INTEGER NOT NULL CHECK (fs_2 BETWEEN 1 AND 4),
          fs_3 INTEGER NOT NULL CHECK (fs_3 BETWEEN 1 AND 4),
          fs_4 INTEGER NOT NULL CHECK (fs_4 BETWEEN 1 AND 4),
          us_1 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
          us_2 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
          us_3 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
          us_4 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
          us_5 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
          pe_1 INTEGER NOT NULL CHECK (pe_1 BETWEEN 1 AND 4),
          pe_2 INTEGER NOT NULL CHECK (pe_1 BETWEEN 1 AND 4),
          pe_3 INTEGER NOT NULL CHECK (pe_1 BETWEEN 1 AND 4),
          feedback_text TEXT,
          created_at    TIMESTAMPTZ NOT NULL DEFAULT NOW()
        )
      `);
      await db.query(`CREATE INDEX IF NOT EXISTS idx_evaluation_responses_created_at ON evaluation_responses(created_at)`);
      await db.query(`CREATE INDEX IF NOT EXISTS idx_evaluation_responses_role ON evaluation_responses(role)`);
      console.log('✓ Created evaluation_responses table');
    } catch (evalErr) {
      console.warn('⚠ Could not create evaluation_responses (likely a permissions issue). Run as superuser:');
      console.warn("  psql -U postgres -d codeinsight -f backend/migrations/006-add-evaluation.sql");
    }
  }

  if (!(await tableExists('integrity_flags'))) {
    await db.query(`
      CREATE TABLE integrity_flags (
        id                  SERIAL PRIMARY KEY,
        section_id          INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        exercise_id         INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
        student_id          INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        submission_id       INT REFERENCES submissions(id) ON DELETE SET NULL,
        flag_type           VARCHAR(50) NOT NULL,
        severity            VARCHAR(20) NOT NULL,
        evidence            JSONB DEFAULT '{}',
        context_behaviors   TEXT[] DEFAULT '{}',
        status              VARCHAR(20) DEFAULT 'flagged',
        instructor_note     TEXT,
        reviewed_at         TIMESTAMP,
        created_at          TIMESTAMP DEFAULT NOW(),
        UNIQUE(exercise_id, student_id, flag_type)
      )
    `);
    console.log('✓ Created integrity_flags table');
  }

  if (!(await tableExists('section_memberships'))) {
    await db.query(`
      CREATE TABLE section_memberships (
        id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
        section_id  INTEGER NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        user_id     INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        role        TEXT NOT NULL DEFAULT 'student' CHECK (role IN ('student', 'ta', 'co_instructor')),
        status      TEXT NOT NULL DEFAULT 'active' CHECK (status IN ('active', 'pending', 'denied', 'dropped', 'left_requested', 'left')),
        joined_at   TIMESTAMPTZ NOT NULL DEFAULT NOW(),
        dropped_at  TIMESTAMPTZ,
        drop_reason TEXT,
        UNIQUE(section_id, user_id)
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_memberships_section ON section_memberships(section_id)`);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_memberships_user ON section_memberships(user_id)`);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_memberships_status ON section_memberships(status)`);
    console.log('✓ Created section_memberships table');
  }

  if (!(await tableExists('section_audit_log'))) {
    await db.query(`
      CREATE TABLE section_audit_log (
        id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
        section_id  INTEGER NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        actor_id    INTEGER REFERENCES users(id) ON DELETE SET NULL,
        action      TEXT NOT NULL,
        meta        JSONB NOT NULL DEFAULT '{}',
        created_at  TIMESTAMPTZ NOT NULL DEFAULT NOW()
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_audit_log_section ON section_audit_log(section_id)`);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_audit_log_created ON section_audit_log(created_at)`);
    console.log('✓ Created section_audit_log table');
  }

  // ── Migration 010: Taxonomy Refactor (ADRs 001-006) ─────────────────────
  // Run standalone: node migrations/010_taxonomy_refactor.js
  // Here we just check if it's been applied
  if (await tableExists('concepts') && !(await columnExists('concepts', 'knowledge_area_code'))) {
    console.log('⚠ Migration 010 (taxonomy refactor) not applied.');
    console.log('  Run: node backend/migrations/010_taxonomy_refactor.js');
  } else if (await tableExists('concepts')) {
    console.log('✓ Migration 010 (taxonomy refactor) applied');
  }

  await Promise.all(patches);
}

/**
 * Run v2 migration SQL files idempotently.
 * Each file is wrapped in a transaction on our end; the files themselves use
 * IF NOT EXISTS / ADD COLUMN IF NOT EXISTS patterns for safety.
 */
async function applyV2Migrations() {
  const migrationsDir = path.join(__dirname, 'migrations');
  const v2Files = [
    '20260610_v2_concepts.sql',
    '20260610_v2_audit.sql',
    '20260610_validation_mode.sql',
    '20260614_custom_tags.sql',
    '20260615_custom_tags_ka.sql',
  ];

  for (const file of v2Files) {
    const filePath = path.join(migrationsDir, file);
    if (!fs.existsSync(filePath)) {
      console.warn(`⚠ v2 migration file not found: ${file}`);
      continue;
    }
    const sql = fs.readFileSync(filePath, 'utf8');
    // Check if tables already exist to skip idempotently
    const baseName = file.replace('.sql', '');
    const markers = {
      '20260610_v2_concepts':        { table: 'exercise_concepts', label: 'exercise_concepts + FTS' },
      '20260610_v2_audit':           { table: 'audit_log',      label: 'audit_log + cds_snapshots' },
      '20260610_validation_mode':    { table: 'exercises',    col: 'is_validated', label: 'validation mode columns' },
      '20260614_custom_tags':        { table: 'instructor_custom_tags', label: 'instructor_custom_tags + custom_tag_exercise_mappings' },
      '20260615_custom_tags_ka':     { table: 'instructor_custom_tags', col: 'knowledge_area', label: 'custom_tags knowledge_area column' },
    };
    const marker = markers[baseName];
    if (marker) {
      if (marker.col && await tableExists(marker.table) && await columnExists(marker.table, marker.col)) {
        console.log(`✓ ${marker.label} already applied`);
        continue;
      }
      if (!marker.col && await tableExists(marker.table)) {
        console.log(`✓ ${marker.label} already applied`);
        continue;
      }
    }
    try {
      await db.query(sql);
      console.log(`✓ Applied ${file}`);
    } catch (err) {
      // Ignore "already exists" errors for idempotency
      if (err.code === '42P07' || err.code === '42701') {
        console.log(`✓ ${marker?.label || file} already exists`);
      } else {
        console.warn(`⚠ v2 migration ${file} failed:`, err.message);
      }
    }
  }
}

async function ensureTablesExist() {
  try {
    console.log('Verifying database tables...');

    const tables = [
      'users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions',
      'cds_scores', 'alerts', 'verification_logs', 'performance_logs', 'auto_close_log',
      'integrity_flags'
    ];
    const results = [];

    for (const table of tables) {
      const exists = await tableExists(table);
      results.push({ table, exists });
      if (exists) {
        console.log(`✓ ${table} table exists`);
      } else {
        console.warn(`⚠ ${table} table not found`);
      }
    }

    try {
      await applySchemaPatches();
    } catch (patchErr) {
      console.warn('⚠ Schema patches skipped:', patchErr.message);
    }

    try {
      await applyV2Migrations();
    } catch (v2Err) {
      console.warn('⚠ v2 migrations failed:', v2Err.message);
    }

    // verification_rules table (data-driven AST pattern matching)
    if (!(await tableExists('verification_rules'))) {
      try {
        const { createVerificationRules } = require('./migrations/20260617_verification_rules');
        await createVerificationRules(db);
        console.log('✓ verification_rules table seeded');
      } catch (vrErr) {
        console.warn('⚠ verification_rules migration failed:', vrErr.message);
      }
    }

    const criticalTables = ['users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions'];
    const allCriticalExist = criticalTables.every(table =>
      results.find(r => r.table === table)?.exists === true
    );

    if (!allCriticalExist) {
      console.warn('Some critical tables are missing — run: psql -d codeinsight -f backend/schema.sql');
    }

    return allCriticalExist;
  } catch (err) {
    console.error('Database check error:', err.message);
    return false;
  }
}

module.exports = { ensureTablesExist, applySchemaPatches, columnExists, tableExists };

if (require.main === module) {
  ensureTablesExist()
    .then((ok) => process.exit(ok ? 0 : 1))
    .catch((err) => {
      console.error(err);
      process.exit(1);
    });
}

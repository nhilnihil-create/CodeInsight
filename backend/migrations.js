// Database migrations/setup — verify tables and apply idempotent schema patches
require('dotenv').config();
const db = require('./config/db');

async function columnExists(table, column) {
  const result = await db.query(
    `SELECT 1 FROM information_schema.columns
     WHERE table_name = $1 AND column_name = $2`,
    [table, column]
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
  }

  if (await tableExists('submissions')) {
    patches.push(addColumnIfMissing('submissions', 'code_growth_delta', 'INTEGER DEFAULT 0'));
    patches.push(addColumnIfMissing('submissions', 'is_verified', 'BOOLEAN DEFAULT true'));
    patches.push(addColumnIfMissing('submissions', 'verification_note', 'TEXT'));
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

  if (!(await tableExists('behavioral_events'))) {
    await db.query(`
      CREATE TABLE behavioral_events (
        id            SERIAL PRIMARY KEY,
        student_id    INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        exercise_id   INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
        event_type    VARCHAR(50) NOT NULL,
        occurred_at   TIMESTAMP NOT NULL DEFAULT NOW(),
        payload       JSONB DEFAULT '{}'::jsonb,
        created_at    TIMESTAMP DEFAULT NOW()
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_behavioral_events_student_exercise ON behavioral_events (student_id, exercise_id)`);
    console.log('✓ Created behavioral_events table');
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

  if (!(await tableExists('notifications'))) {
    await db.query(`
      CREATE TABLE notifications (
        id                  SERIAL PRIMARY KEY,
        student_id          INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        section_id          INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        exercise_id         INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
        message             TEXT NOT NULL,
        notification_type   VARCHAR(50) NOT NULL DEFAULT 'cds_computation',
        is_read             BOOLEAN DEFAULT false,
        created_at          TIMESTAMP DEFAULT NOW(),
        UNIQUE(student_id, exercise_id, notification_type)
      )
    `);
    console.log('✓ Created notifications table');
  } else if (!(await columnExists('notifications', 'notification_type'))) {
    patches.push(addColumnIfMissing('notifications', 'notification_type', `VARCHAR(50) NOT NULL DEFAULT 'cds_computation'`));
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

  await Promise.all(patches);
}

async function ensureTablesExist() {
  try {
    console.log('Verifying database tables...');

    const tables = [
      'users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions',
      'cds_scores', 'alerts', 'verification_logs', 'performance_logs', 'auto_close_log',
      'integrity_flags', 'notifications'
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

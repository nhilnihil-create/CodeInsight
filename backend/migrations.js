// Database migrations/setup — verify tables and apply idempotent schema patches
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

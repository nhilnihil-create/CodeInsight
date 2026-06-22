/**
 * Migration 010: Taxonomy Refactor (ADRs 001-006)
 *
 * Implements the curriculum-agnostic analytics architecture:
 *   ADR-002: Enrich concepts table + concept_dependencies
 *   ADR-003: exercise_concept_tags junction (multi-tag exercises)
 *   ADR-001: analytics_alerts unified alert table
 *   ADR-005: difficulty_index on exercises, test_feedback_hints on submissions
 *   ADR-006: student_concept_metrics + section_concept_metrics aggregate tables
 *
 * CDS COMPATIBILITY GUARANTEE:
 *   - All new columns are NULLable with defaults → existing queries unaffected
 *   - No columns dropped or renamed on existing tables
 *   - cds_scores, cds_snapshots, alerts tables are NOT modified
 *   - CDS thresholds (0.31, 0.50) are unchanged
 *   - cdsEngine.computeBatchCDS operates independently at exercise level
 *
 * Run: node backend/migrations/010_taxonomy_refactor.js
 */

require('dotenv').config();
const { Pool } = require('pg');

const db = new Pool({
  host: process.env.DB_HOST,
  port: parseInt(process.env.DB_PORT || '5432'),
  database: process.env.DB_NAME,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
});

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

async function constraintExists(table, constraintName) {
  const result = await db.query(
    `SELECT 1 FROM information_schema.table_constraints
     WHERE table_name = $1 AND constraint_name = $2`,
    [table, constraintName]
  );
  return result.rows.length > 0;
}

async function indexExists(indexName) {
  const result = await db.query(
    `SELECT 1 FROM pg_indexes WHERE indexname = $1`,
    [indexName]
  );
  return result.rows.length > 0;
}

async function run() {
  console.log('=== Migration 010: Taxonomy Refactor ===\n');

  const client = await db.connect();

  try {
    await client.query('BEGIN');

    // ──────────────────────────────────────────────────────────────────────
    // ADR-002: Enrich concepts table
    // ──────────────────────────────────────────────────────────────────────
    console.log('[ADR-002] Enriching concepts table...');

    if (!(await columnExists('concepts', 'knowledge_area_code'))) {
      await client.query(`ALTER TABLE concepts ADD COLUMN knowledge_area_code VARCHAR(20)`);
      console.log('  ✓ Added concepts.knowledge_area_code');
    }

    if (!(await columnExists('concepts', 'slug'))) {
      await client.query(`ALTER TABLE concepts ADD COLUMN slug VARCHAR(100)`);
      // Add unique constraint separately so we can check it
      if (!(await constraintExists('concepts', 'concepts_slug_key'))) {
        await client.query(`ALTER TABLE concepts ADD CONSTRAINT concepts_slug_key UNIQUE (slug)`);
      }
      console.log('  ✓ Added concepts.slug (UNIQUE)');
    }

    if (!(await columnExists('concepts', 'bloom_level'))) {
      await client.query(`ALTER TABLE concepts ADD COLUMN bloom_level VARCHAR(20) DEFAULT 'apply'`);
      console.log('  ✓ Added concepts.bloom_level');
    }

    if (!(await columnExists('concepts', 'difficulty_tier'))) {
      await client.query(`ALTER TABLE concepts ADD COLUMN difficulty_tier INT DEFAULT 1`);
      console.log('  ✓ Added concepts.difficulty_tier');
    }

    // Update existing 7 concepts with slugs and knowledge areas
    // SDF-FPC = Fundamentals of Programming and Computing
    // SDF-FDS = Fundamental Data Structures
    // SDF-PMD = Program Design and Development
    // SDF-OOP = Object-Oriented Programming
    await client.query(`
      UPDATE concepts SET
        knowledge_area_code = CASE name
          WHEN 'Datatypes' THEN 'SDF-FPC'
          WHEN 'Variables' THEN 'SDF-FPC'
          WHEN 'Conditionals' THEN 'SDF-PMD'
          WHEN 'Loops' THEN 'SDF-PMD'
          WHEN 'Functions' THEN 'SDF-PMD'
          WHEN 'Arrays' THEN 'SDF-FDS'
          WHEN 'OOP' THEN 'SDF-OOP'
          WHEN 'Pointers' THEN 'SDF-FDS'
          WHEN 'Strings' THEN 'SDF-FPC'
          WHEN 'Input/Output' THEN 'SDF-FPC'
          ELSE NULL
        END,
        slug = CASE name
          WHEN 'Datatypes' THEN 'datatypes'
          WHEN 'Variables' THEN 'variables'
          WHEN 'Conditionals' THEN 'conditionals'
          WHEN 'Loops' THEN 'loops'
          WHEN 'Functions' THEN 'functions'
          WHEN 'Arrays' THEN 'arrays'
          WHEN 'OOP' THEN 'oop'
          WHEN 'Pointers' THEN 'pointers'
          WHEN 'Strings' THEN 'strings'
          WHEN 'Input/Output' THEN 'input-output'
          ELSE NULL
        END,
        bloom_level = CASE name
          WHEN 'Datatypes' THEN 'remember'
          WHEN 'Variables' THEN 'understand'
          WHEN 'Conditionals' THEN 'apply'
          WHEN 'Loops' THEN 'apply'
          WHEN 'Functions' THEN 'analyze'
          WHEN 'Arrays' THEN 'apply'
          WHEN 'OOP' THEN 'evaluate'
          WHEN 'Pointers' THEN 'analyze'
          WHEN 'Strings' THEN 'understand'
          WHEN 'Input/Output' THEN 'apply'
          ELSE 'apply'
        END,
        difficulty_tier = CASE name
          WHEN 'Datatypes' THEN 1
          WHEN 'Variables' THEN 1
          WHEN 'Strings' THEN 1
          WHEN 'Input/Output' THEN 1
          WHEN 'Conditionals' THEN 2
          WHEN 'Loops' THEN 2
          WHEN 'Arrays' THEN 2
          WHEN 'Pointers' THEN 3
          WHEN 'Functions' THEN 3
          WHEN 'OOP' THEN 4
          ELSE 1
        END
    `);
    console.log('  ✓ Updated existing concept metadata');

    // ──────────────────────────────────────────────────────────────────────
    // ADR-002: concept_dependencies (prerequisite graph)
    // ──────────────────────────────────────────────────────────────────────
    if (!(await tableExists('concept_dependencies'))) {
      await client.query(`
        CREATE TABLE concept_dependencies (
          parent_concept_id INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
          child_concept_id INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
          weight DECIMAL(3,2) DEFAULT 1.0,
          PRIMARY KEY (parent_concept_id, child_concept_id),
          CONSTRAINT no_self_dependency CHECK (parent_concept_id != child_concept_id)
        )
      `);
      console.log('[ADR-002] ✓ Created concept_dependencies');

      // Seed core dependency chains
      // Variables → Conditionals → Loops → Arrays → Functions → OOP
      // Datatypes → Variables
      // Datatypes → Input/Output
      const dependencyRows = await client.query(`
        SELECT id, name FROM concepts ORDER BY id
      `);
      const conceptMap = {};
      for (const row of dependencyRows.rows) {
        conceptMap[row.name] = row.id;
      }

      const deps = [
        // [parent, child, weight]
        ['Datatypes', 'Variables', 1.0],
        ['Datatypes', 'Input/Output', 0.5],
        ['Variables', 'Conditionals', 1.0],
        ['Variables', 'Functions', 0.5],
        ['Conditionals', 'Loops', 1.0],
        ['Loops', 'Arrays', 0.7],
        ['Arrays', 'Functions', 0.5],
        ['Functions', 'OOP', 1.0],
        ['Functions', 'Pointers', 0.8],
        ['Conditionals', 'Functions', 0.3],
      ];

      for (const [parent, child, weight] of deps) {
        const parentId = conceptMap[parent];
        const childId = conceptMap[child];
        if (parentId && childId) {
          await client.query(
            `INSERT INTO concept_dependencies (parent_concept_id, child_concept_id, weight)
             VALUES ($1, $2, $3) ON CONFLICT DO NOTHING`,
            [parentId, childId, weight]
          );
        }
      }
      console.log('  ✓ Seeded 10 concept dependencies');
    }

    // ──────────────────────────────────────────────────────────────────────
    // ADR-003: exercise_concept_tags (multi-tag junction)
    // ──────────────────────────────────────────────────────────────────────
    if (!(await tableExists('exercise_concept_tags'))) {
      await client.query(`
        CREATE TABLE exercise_concept_tags (
          exercise_id INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
          concept_id INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
          weight DECIMAL(3,2) DEFAULT 1.0,
          is_primary BOOLEAN DEFAULT false,
          PRIMARY KEY (exercise_id, concept_id)
        )
      `);
      console.log('[ADR-003] ✓ Created exercise_concept_tags');

      // Seed from existing exercises.concept_id (backward compatibility)
      // Each exercise gets its primary concept tag from concept_id
      const result = await client.query(`
        SELECT id, concept_id FROM exercises WHERE concept_id IS NOT NULL
      `);
      for (const row of result.rows) {
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.0, true)
           ON CONFLICT DO NOTHING`,
          [row.id, row.concept_id]
        );
      }
      console.log(`  ✓ Seeded ${result.rows.length} primary concept tags from exercises.concept_id`);

      // Also seed from existing exercise_concepts junction
      const ecResult = await client.query(`
        SELECT exercise_id, concept_id FROM exercise_concepts
      `);
      for (const row of ecResult.rows) {
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.0, false)
           ON CONFLICT (exercise_id, concept_id) DO UPDATE SET is_primary = EXCLUDED.is_primary`,
          [row.exercise_id, row.concept_id]
        );
      }
      if (ecResult.rows.length > 0) {
        console.log(`  ✓ Migrated ${ecResult.rows.length} rows from exercise_concepts`);
      }
    }

    // ──────────────────────────────────────────────────────────────────────
    // ADR-001: analytics_alerts (unified alert storage)
    // ──────────────────────────────────────────────────────────────────────
    if (!(await tableExists('analytics_alerts'))) {
      await client.query(`
        CREATE TABLE analytics_alerts (
          id SERIAL PRIMARY KEY,
          student_id INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
          section_id INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
          exercise_id INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
          alert_type VARCHAR(50) NOT NULL,
          severity VARCHAR(20) NOT NULL DEFAULT 'medium'
            CHECK (severity IN ('low', 'medium', 'high', 'critical')),
          evidence TEXT,
          context JSONB DEFAULT '{}',
          is_reviewed BOOLEAN DEFAULT false,
          reviewed_by INT REFERENCES users(id),
          reviewed_at TIMESTAMPTZ,
          created_at TIMESTAMPTZ DEFAULT NOW()
        )
      `);
      console.log('[ADR-001] ✓ Created analytics_alerts');

      // Migrate existing CDS-based alerts into analytics_alerts
      // Only migrate alerts where the student still exists (FK constraint)
      const alertCount = await client.query(`SELECT COUNT(*) as cnt FROM alerts`);
      const cnt = parseInt(alertCount.rows[0].cnt);
      if (cnt > 0) {
        await client.query(`
          INSERT INTO analytics_alerts
            (student_id, section_id, exercise_id, alert_type, severity, evidence, context, created_at)
          SELECT
            a.student_id,
            a.section_id,
            a.exercise_id,
            'CDS_HIGH',
            'high',
            a.concept_name,
            jsonb_build_object('cds_score', a.cds_score, 'classification', a.classification, 'migrated_from', 'alerts'),
            a.created_at
          FROM alerts a
          WHERE a.classification = 'High'
            AND EXISTS (SELECT 1 FROM users u WHERE u.id = a.student_id)
            AND NOT EXISTS (
              SELECT 1 FROM analytics_alerts aa
              WHERE aa.student_id = a.student_id
                AND aa.exercise_id = a.exercise_id
                AND aa.alert_type = 'CDS_HIGH'
            )
        `);
        console.log(`  ✓ Migrated existing CDS High alerts to analytics_alerts`);
      }
    }

    // ──────────────────────────────────────────────────────────────────────
    // ADR-005: difficulty_index on exercises, test_feedback_hints on submissions
    // ──────────────────────────────────────────────────────────────────────
    if (!(await columnExists('exercises', 'difficulty_index'))) {
      await client.query(`ALTER TABLE exercises ADD COLUMN difficulty_index DECIMAL(5,4)`);
      console.log('[ADR-005] ✓ Added exercises.difficulty_index');
    }

    if (!(await columnExists('submissions', 'test_feedback_hints'))) {
      await client.query(`ALTER TABLE submissions ADD COLUMN test_feedback_hints JSONB DEFAULT '[]'`);
      console.log('[ADR-005] ✓ Added submissions.test_feedback_hints');
    }

    // ──────────────────────────────────────────────────────────────────────
    // ADR-006: student_concept_metrics (CMI + Velocity aggregate)
    // ──────────────────────────────────────────────────────────────────────
    if (!(await tableExists('student_concept_metrics'))) {
      await client.query(`
        CREATE TABLE student_concept_metrics (
          student_id INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
          concept_id INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
          section_id INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
          cmi DECIMAL(5,2) DEFAULT 0,
          velocity DECIMAL(5,2) DEFAULT 0,
          last_updated TIMESTAMPTZ DEFAULT NOW(),
          PRIMARY KEY (student_id, concept_id, section_id)
        )
      `);
      console.log('[ADR-006] ✓ Created student_concept_metrics');
      console.log('  CMI Formula: 100 × (1 - (0.40×failRate + 0.35×normalizedAttempts + 0.25×normalizedTime))');
      console.log('  Velocity Formula: (CMI_recent - CMI_baseline) / weeks_between');
    }

    // ──────────────────────────────────────────────────────────────────────
    // ADR-006: section_concept_metrics (CRS + Difficulty Index aggregate)
    // ──────────────────────────────────────────────────────────────────────
    if (!(await tableExists('section_concept_metrics'))) {
      await client.query(`
        CREATE TABLE section_concept_metrics (
          section_id INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
          concept_id INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
          crs VARCHAR(20) DEFAULT 'unknown',
          crs_score DECIMAL(5,2) DEFAULT 0,
          difficulty_index DECIMAL(5,4) DEFAULT 0,
          student_count INT DEFAULT 0,
          at_risk_count INT DEFAULT 0,
          last_updated TIMESTAMPTZ DEFAULT NOW(),
          PRIMARY KEY (section_id, concept_id)
        )
      `);
      console.log('[ADR-006] ✓ Created section_concept_metrics');
      console.log('  CRS Formula: AVG(CDS) for concept-tagged exercises');
      console.log('  Risk levels: critical (>0.70, >=5 students), high (>0.50, >=3), medium (>0.31), low (<=0.31)');
    }

    await client.query('COMMIT');
    console.log('\n=== Migration 010 completed successfully ===');

  } catch (err) {
    await client.query('ROLLBACK');
    console.error('\n✗ Migration 010 failed (rolled back):', err.message);
    console.error(err.stack);
    process.exitCode = 1;
  } finally {
    client.release();
    await db.end();
  }
}

run();

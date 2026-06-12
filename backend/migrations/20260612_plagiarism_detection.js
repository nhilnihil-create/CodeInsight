/**
 * Migration: Create multi-vector plagiarism detection tables.
 *
 * Tables:
 *   submission_ast_hashes  — per-submission AST fingerprints + sliding windows
 *   codenet_benchmarks     — archival structural hashes from CodeNet corpus
 *
 * Run: node backend/migrations/20260612_plagiarism_detection.js
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

async function run() {
  console.log('Running plagiarism detection migration...\n');

  // ── 1. submission_ast_hashes ──────────────────────────────────────────────
  const hasHashes = await db.query(`
    SELECT EXISTS (
      SELECT FROM information_schema.tables
      WHERE table_name = 'submission_ast_hashes'
    );
  `);

  if (!hasHashes.rows[0].exists) {
    console.log('Creating submission_ast_hashes table...');
    await db.query(`
      CREATE TABLE submission_ast_hashes (
        id           SERIAL PRIMARY KEY,
        submission_id INT REFERENCES submissions(id) ON DELETE CASCADE,
        exercise_id  INT REFERENCES exercises(id) ON DELETE CASCADE,
        student_id   INT REFERENCES users(id)   ON DELETE CASCADE,
        ast_window_hashes JSONB NOT NULL DEFAULT '[]'::jsonb,
        full_structural_hash VARCHAR(64) NOT NULL,
        language     VARCHAR(20) NOT NULL DEFAULT 'cpp',
        created_at   TIMESTAMP NOT NULL DEFAULT NOW()
      );
    `);
    console.log('  ✓ submission_ast_hashes created');
  } else {
    console.log('  ✓ submission_ast_hashes already exists');
  }

  // Composite unique index — blocks duplicate (exercise, structural_hash)
  // but allows ON CONFLICT DO UPDATE to refresh window hashes
  await db.query(`
    CREATE UNIQUE INDEX IF NOT EXISTS idx_ast_hashes_exercise_structural
      ON submission_ast_hashes (exercise_id, full_structural_hash);
  `);

  // FK indexes for fast peer-to-peer scans
  await db.query(`
    CREATE INDEX IF NOT EXISTS idx_ast_hashes_exercise
      ON submission_ast_hashes (exercise_id);
  `);
  await db.query(`
    CREATE INDEX IF NOT EXISTS idx_ast_hashes_student
      ON submission_ast_hashes (student_id);
  `);
  await db.query(`
    CREATE INDEX IF NOT EXISTS idx_ast_hashes_submission
      ON submission_ast_hashes (submission_id);
  `);
  console.log('  ✓ indexes on submission_ast_hashes created');

  // ── 2. codenet_benchmarks ─────────────────────────────────────────────────
  const hasCodenet = await db.query(`
    SELECT EXISTS (
      SELECT FROM information_schema.tables
      WHERE table_name = 'codenet_benchmarks'
    );
  `);

  if (!hasCodenet.rows[0].exists) {
    console.log('Creating codenet_benchmarks table...');
    await db.query(`
      CREATE TABLE codenet_benchmarks (
        id              SERIAL PRIMARY KEY,
        problem_code    VARCHAR(100) NOT NULL,
        concept_tag     VARCHAR(100) NOT NULL,
        structural_hash VARCHAR(64)  NOT NULL,
        window_hashes   JSONB NOT NULL DEFAULT '[]'::jsonb,
        created_at      TIMESTAMP NOT NULL DEFAULT NOW()
      );
    `);
    console.log('  ✓ codenet_benchmarks created');
  } else {
    console.log('  ✓ codenet_benchmarks already exists');
  }

  await db.query(`
    CREATE INDEX IF NOT EXISTS idx_codenet_problem
      ON codenet_benchmarks (problem_code);
  `);
  await db.query(`
    CREATE INDEX IF NOT EXISTS idx_codenet_hash
      ON codenet_benchmarks (structural_hash);
  `);
  await db.query(`
    CREATE INDEX IF NOT EXISTS idx_codenet_concept
      ON codenet_benchmarks (concept_tag);
  `);
  console.log('  ✓ indexes on codenet_benchmarks created');

  // ── 3. Seed existing exercises' reference solutions into codenet_benchmarks
  const refRes = await db.query(`
    SELECT e.id, e.title, e.concept_id, c.name AS concept_name, e.reference_solution
    FROM exercises e
    LEFT JOIN concepts c ON e.concept_id = c.id
    WHERE e.reference_solution IS NOT NULL
      AND e.reference_solution != ''
  `);

  console.log(`\nSeeding ${refRes.rows.length} reference solutions as benchmarks...`);

  // We'll import the hasher inline (needs tree-sitter)
  const { normalizeAST } = require('../services/astHasher');

  let seeded = 0;
  for (const row of refRes.rows) {
    if (!row.reference_solution) continue;
    try {
      const { fullHash, windows } = normalizeAST(row.reference_solution, 'cpp');
      await db.query(`
        INSERT INTO codenet_benchmarks (problem_code, concept_tag, structural_hash, window_hashes)
        VALUES ($1, $2, $3, $4)
        ON CONFLICT DO NOTHING
      `, [
        `exercise_${row.id}`,
        row.concept_name || 'unknown',
        fullHash,
        JSON.stringify(windows),
      ]);
      seeded++;
    } catch (err) {
      console.warn(`  ⚠ Failed to hash exercise ${row.id}: ${err.message}`);
    }
  }
  console.log(`  ✓ Seeded ${seeded}/${refRes.rows.length} benchmarks`);

  await db.end();
  console.log('\n✅ Plagiarism detection migration complete.');
}

run().catch((err) => {
  console.error('✗ Migration failed:', err.message);
  db.end().catch(() => {});
  process.exit(1);
});

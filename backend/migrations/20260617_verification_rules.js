/**
 * Migration: Create verification_rules table and seed from badPatterns.js
 *
 * Makes AST verification data-driven — rules are stored in the database
 * so instructors can add/modify patterns without code changes. The in-memory
 * badPatterns.js module serves as fallback when the database is unavailable.
 *
 * Run: node migrations/20260617_verification_rules.js
 * (Or it auto-runs at app startup via migrations.js)
 */

require('dotenv').config();
const { Pool } = require('pg');

const { getAllPatterns } = require('../services/badPatterns');

async function createVerificationRules(externalDb) {
  const db = externalDb || new Pool({
    host: process.env.DB_HOST,
    port: process.env.DB_PORT,
    database: process.env.DB_NAME,
    user: process.env.DB_USER,
    password: process.env.DB_PASSWORD
  });

  try {
    console.log('Creating verification_rules table...');

    const tableCheck = await db.query(`
      SELECT EXISTS (
        SELECT FROM information_schema.tables
        WHERE table_name = 'verification_rules'
      );
    `);

    if (!tableCheck.rows[0].exists) {
      await db.query(`
        CREATE TABLE verification_rules (
          id SERIAL PRIMARY KEY,
          concept_id INTEGER REFERENCES concepts(id) ON DELETE CASCADE,
          pattern_id VARCHAR(100) NOT NULL,
          rule_type VARCHAR(50) NOT NULL DEFAULT 'bad_pattern',
          tree_sitter_query TEXT,
          severity VARCHAR(20) DEFAULT 'warning',
          student_message TEXT NOT NULL,
          handler VARCHAR(100),
          config JSONB,
          is_active BOOLEAN DEFAULT true,
          created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
          updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
          UNIQUE(concept_id, pattern_id)
        );
      `);
      console.log('✓ Created verification_rules table');
    } else {
      console.log('✓ verification_rules table already exists');
    }

    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_verification_rules_concept_id ON verification_rules(concept_id);
    `);
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_verification_rules_pattern_id ON verification_rules(pattern_id);
    `);

    // ── Seed data from badPatterns.js ────────────────────────────────────
    const patterns = getAllPatterns();

    for (const pattern of patterns) {
      const conceptRes = await db.query(
        'SELECT id FROM concepts WHERE LOWER(name) = LOWER($1)',
        [pattern.concept]
      );

      if (conceptRes.rows.length === 0) {
        console.warn(`  ⚠ Concept "${pattern.concept}" not found — skipping pattern "${pattern.id}"`);
        continue;
      }

      const conceptId = conceptRes.rows[0].id;

      await db.query(
        `INSERT INTO verification_rules (concept_id, pattern_id, rule_type, tree_sitter_query, severity, student_message, handler)
         VALUES ($1, $2, 'bad_pattern', $3, $4, $5, $6)
         ON CONFLICT (concept_id, pattern_id) DO UPDATE SET
           rule_type = 'bad_pattern',
           tree_sitter_query = EXCLUDED.tree_sitter_query,
           student_message = EXCLUDED.student_message,
           handler = EXCLUDED.handler,
           updated_at = CURRENT_TIMESTAMP`,
        [
          conceptId,
          pattern.id,
          pattern.query,
          'warning',
          pattern.message,
          pattern.handler || null,
        ]
      );
      console.log(`  ✓ Seeded "${pattern.id}" → concept #${conceptId} (${pattern.concept})`);
    }

    console.log(`\n✓ Bad patterns seeded — ${patterns.length} rows`);

    // ── Seed variable_usage rules ────────────────────────────────────────────
    const usageRules = [
      { concept: 'Loops', msg: 'Loop condition uses only literals — use variables to control loop logic', cfg: { checkNodeTypes: ['for_statement', 'while_statement', 'do_statement'] } },
      { concept: 'Conditionals', msg: 'Conditional uses hardcoded values — use variables to control logic', cfg: { checkNodeTypes: ['if_statement'] } },
    ];

    for (const rule of usageRules) {
      const conceptRes = await db.query(
        'SELECT id FROM concepts WHERE LOWER(name) = LOWER($1)',
        [rule.concept]
      );
      if (conceptRes.rows.length === 0) {
        console.warn(`  ⚠ Concept "${rule.concept}" not found — skipping variable_usage rule`);
        continue;
      }
      const conceptId = conceptRes.rows[0].id;
      await db.query(
        `INSERT INTO verification_rules (concept_id, pattern_id, rule_type, severity, student_message, config)
         VALUES ($1, $2, 'variable_usage', 'error', $3, $4)
         ON CONFLICT (concept_id, pattern_id) DO UPDATE SET
           student_message = EXCLUDED.student_message,
           config = EXCLUDED.config,
           updated_at = CURRENT_TIMESTAMP`,
        [conceptId, `usage_${rule.concept.toLowerCase()}`, rule.msg, JSON.stringify(rule.cfg)]
      );
      console.log(`  ✓ Seeded variable_usage rule for "${rule.concept}"`);
    }

    console.log(`\n✓ Verification rules migration complete`);

    const countRes = await db.query('SELECT COUNT(*) AS count FROM verification_rules');
    console.log(`  ${countRes.rows[0].count} rows in verification_rules`);

    return true;
  } catch (error) {
    console.error('Migration failed:', error.message);
    return false;
  } finally {
    if (!externalDb) await db.end();
  }
}

if (require.main === module) {
  createVerificationRules().then(success => {
    process.exit(success ? 0 : 1);
  });
} else {
  module.exports = { createVerificationRules };
}

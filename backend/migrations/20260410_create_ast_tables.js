/**
 * Migration script to create AST verification tables
 * This script creates the ast_templates and verification_logs tables
 * as specified in the gemini.md implementation plan
 */

require('dotenv').config();
const { Pool } = require('pg');

const db = new Pool({
  host: process.env.DB_HOST,
  port: process.env.DB_PORT,
  database: process.env.DB_NAME,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD
});

async function createASTTables() {
  try {
    console.log('Creating AST verification tables...');

    // Create ast_templates table for storing CodeNet patterns
    const astTablesCheck = await db.query(`
      SELECT EXISTS (
        SELECT FROM information_schema.tables
        WHERE table_name = 'ast_templates'
      );
    `);

    if (!astTablesCheck.rows[0].exists) {
      console.log('Creating ast_templates table...');
      await db.query(`
        CREATE TABLE ast_templates (
          id SERIAL PRIMARY KEY,
          problem_id INTEGER,
          ast_hash VARCHAR(64) UNIQUE,
          node_types TEXT[],
          canonical_string TEXT,
          concept_id INTEGER REFERENCES concepts(id),
          source VARCHAR(100),
          solution_quality_score INTEGER,
          difficulty_level VARCHAR(20),
          correct_solution TEXT,
          codenet_snapshot_date DATE,
          version_number INTEGER DEFAULT 1,
          created_at TIMESTAMP DEFAULT NOW()
        );
      `);
      console.log('✓ Successfully created ast_templates table');
    } else {
      console.log('✓ ast_templates table already exists');
    }

    // Create indexes for better performance
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_ast_templates_concept_id ON ast_templates(concept_id);
    `);
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_ast_templates_ast_hash ON ast_templates(ast_hash);
    `);

    // verification_logs table should already exist from schema.sql, but let's ensure it's properly set up
    const verificationLogsCheck = await db.query(`
      SELECT EXISTS (
        SELECT FROM information_schema.tables
        WHERE table_name = 'verification_logs'
      );
    `);

    if (!verificationLogsCheck.rows[0].exists) {
      console.log('Creating verification_logs table...');
      await db.query(`
        CREATE TABLE verification_logs (
          id SERIAL PRIMARY KEY,
          submission_id INT REFERENCES submissions(id) ON DELETE CASCADE,
          student_id INT REFERENCES users(id) ON DELETE CASCADE,
          exercise_id INT REFERENCES exercises(id) ON DELETE CASCADE,
          verification_type VARCHAR(100),
          reason TEXT,
          node_found TEXT,
          node_expected TEXT,
          line_number INT,
          column_number INT,
          created_at TIMESTAMP DEFAULT NOW()
        );
      `);
      console.log('✓ Successfully created verification_logs table');
    } else {
      console.log('✓ verification_logs table already exists');
    }

    // Create indexes for verification_logs
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_verification_logs_submission_id ON verification_logs(submission_id);
    `);
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_verification_logs_exercise_id ON verification_logs(exercise_id);
    `);

    return true;
  } catch (error) {
    console.error('✗ Error creating AST tables:', error.message);
    return false;
  }
}

// Run the migration if this script is executed directly
if (require.main === module) {
  createASTTables().then(success => {
    process.exit(success ? 0 : 1);
  }).catch(err => {
    console.error('✗ Migration failed:', err.message);
    process.exit(1);
  });
}

module.exports = { createASTTables };
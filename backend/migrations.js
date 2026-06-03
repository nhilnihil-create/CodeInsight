// Database migrations/setup
const db = require('./config/db');

async function ensureTablesExist() {
  try {
    console.log('Verifying database tables...');

    // Check if key tables exist
    const tables = ['users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions', 'cds_scores', 'alerts', 'verification_logs', 'performance_logs', 'auto_close_log'];
    const results = [];

    for (const table of tables) {
      const result = await db.query(`
        SELECT EXISTS (
          SELECT 1 FROM information_schema.tables
          WHERE table_name = $1
        ) AS exists;
      `, [table]);

      const exists = result.rows[0].exists;
      results.push({ table, exists });

      if (exists) {
        console.log(`✓ ${table} table exists`);
      } else {
        console.warn(`⚠ ${table} table not found`);
      }
    }

    // Verify submissions table has key columns if it exists
    const submissionsResult = results.find(r => r.table === 'submissions');
    if (submissionsResult && submissionsResult.exists) {
      const columns = await db.query(`
        SELECT column_name FROM information_schema.columns
        WHERE table_name = 'submissions'
      `);

      const columnNames = columns.rows.map(r => r.column_name);
      console.log('✓ Submissions columns:', columnNames.join(', '));
    }

    // Verify cds_scores table has the new column if it exists
    const cdsScoresResult = results.find(r => r.table === 'cds_scores');
    if (cdsScoresResult && cdsScoresResult.exists) {
      const columns = await db.query(`
        SELECT column_name FROM information_schema.columns
        WHERE table_name = 'cds_scores'
      `);

      const columnNames = columns.rows.map(r => r.column_name);
      console.log('✓ CDS Scores columns:', columnNames.join(', '));

      // Check for the new column
      const hasFlaggedColumn = columnNames.includes('has_flagged_attempts');
      if (hasFlaggedColumn) {
        console.log('✓ CDS Scores has_flagged_attempts column exists');
      } else {
        console.warn('⚠ CDS Scores missing has_flagged_attempts column');
      }

      const hasFlagCountColumn = columnNames.includes('integrity_flag_count');
      if (hasFlagCountColumn) {
        console.log('✓ CDS Scores integrity_flag_count column exists');
      } else {
        console.warn('⚠ CDS Scores missing integrity_flag_count column');
      }
    }

    // Return true if all critical tables exist
    const criticalTables = ['users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions'];
    const allCriticalExist = criticalTables.every(table =>
      results.find(r => r.table === table)?.exists === true
    );

    if (!allCriticalExist) {
      console.warn('Some critical tables are missing - please run schema.sql');
    }

    return allCriticalExist;
  } catch (err) {
    console.error('Database check error:', err.message);
    return false;
  }
}

module.exports = { ensureTablesExist };
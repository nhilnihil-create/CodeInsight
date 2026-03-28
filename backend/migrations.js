// Database migrations/setup
const db = require('./config/db');

async function ensureTablesExist() {
  try {
    console.log('Verifying database tables...');

    // Check if submissions table exists by querying information_schema
    const result = await db.query(`
      SELECT EXISTS (
        SELECT 1 FROM information_schema.tables 
        WHERE table_name = 'submissions'
      ) AS exists;
    `);

    if (result.rows[0].exists) {
      console.log('✓ Submissions table exists');
      
      // Verify key columns exist
      const columns = await db.query(`
        SELECT column_name FROM information_schema.columns
        WHERE table_name = 'submissions'
      `);
      
      const columnNames = columns.rows.map(r => r.column_name);
      console.log('✓ Submissions columns:', columnNames.join(', '));
    } else {
      console.warn('⚠ Submissions table not found - please run schema.sql');
    }

    return true;
  } catch (err) {
    console.error('Database check error:', err.message);
    return false;
  }
}

module.exports = { ensureTablesExist };

/**
 * Migration script to add auto_close_log table
 * This table tracks when exercises were automatically closed by the auto-close service
 */

const db = require('../config/db');

async function addAutoCloseLogTable() {
  try {
    console.log('Checking if auto_close_log table exists...');

    // Check if the table already exists
    const tableCheck = await db.query(`
      SELECT EXISTS (
        SELECT FROM information_schema.tables
        WHERE table_name = 'auto_close_log'
      );
    `);

    if (!tableCheck.rows[0].exists) {
      console.log('auto_close_log table does not exist. Creating it...');

      // Create the auto_close_log table
      await db.query(`
        CREATE TABLE auto_close_log (
          id SERIAL PRIMARY KEY,
          exercise_id INT REFERENCES exercises(id) ON DELETE CASCADE,
          closed_at TIMESTAMP DEFAULT NOW(),
          triggered_by VARCHAR(50) DEFAULT 'auto_close_service',
          created_at TIMESTAMP DEFAULT NOW()
        );
      `);

      console.log('✓ Successfully created auto_close_log table');
    } else {
      console.log('✓ auto_close_log table already exists');
    }

    // Create index for better query performance
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_auto_close_log_exercise_id ON auto_close_log(exercise_id);
    `);

    return true;
  } catch (error) {
    console.error('✗ Error creating auto_close_log table:', error.message);
    return false;
  }
}

// Run the migration if this script is executed directly
if (require.main === module) {
  addAutoCloseLogTable().then(success => {
    process.exit(success ? 0 : 1);
  }).catch(err => {
    console.error('✗ Migration failed:', err.message);
    process.exit(1);
  });
}

module.exports = { addAutoCloseLogTable };
/**
 * Migration script to add performance_logs table
 * This table stores performance metrics for ISO 25010 Performance Efficiency evaluation
 */

const db = require('../config/db');

async function addPerformanceLogsTable() {
  try {
    console.log('Checking if performance_logs table exists...');

    // Check if the table already exists
    const tableCheck = await db.query(`
      SELECT EXISTS (
        SELECT FROM information_schema.tables
        WHERE table_name = 'performance_logs'
      );
    `);

    if (!tableCheck.rows[0].exists) {
      console.log('performance_logs table does not exist. Creating it...');

      // Create the performance_logs table
      await db.query(`
        CREATE TABLE performance_logs (
          id SERIAL PRIMARY KEY,
          submission_id INT REFERENCES submissions(id) ON DELETE CASCADE,
          student_id INT REFERENCES users(id) ON DELETE CASCADE,
          exercise_id INT REFERENCES exercises(id) ON DELETE CASCADE,
          time_to_interactive_ms INTEGER,  -- Time from submission to first byte of response
          response_latency_ms INTEGER,     -- Time to process and return complete response
          timestamp TIMESTAMP DEFAULT NOW(),
          endpoint VARCHAR(50),            -- /run or /submit
          http_status_code INTEGER,
          user_agent TEXT
        );
      `);

      console.log('✓ Successfully created performance_logs table');
    } else {
      console.log('✓ performance_logs table already exists');
    }

    // Create indexes for better query performance
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_performance_logs_submission_id ON performance_logs(submission_id);
    `);
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_performance_logs_exercise_id ON performance_logs(exercise_id);
    `);
    await db.query(`
      CREATE INDEX IF NOT EXISTS idx_performance_logs_timestamp ON performance_logs(timestamp);
    `);

    return true;
  } catch (error) {
    console.error('✗ Error creating performance_logs table:', error.message);
    return false;
  }
}

// Run the migration if this script is executed directly
if (require.main === module) {
  addPerformanceLogsTable().then(success => {
    process.exit(success ? 0 : 1);
  }).catch(err => {
    console.error('✗ Migration failed:', err.message);
    process.exit(1);
  });
}

module.exports = { addPerformanceLogsTable };
/**
 * Migration: Add integrity_flag_count to cds_scores
 * This enables tracking the number of integrity flags separately from the CDS score.
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

async function migrate() {
  try {
    console.log('Running migration: Add integrity_flag_count to cds_scores...');
    
    // Check if column already exists
    const checkRes = await db.query(`
      SELECT column_name 
      FROM information_schema.columns 
      WHERE table_name = 'cds_scores' AND column_name = 'integrity_flag_count'
    `);
    
    if (checkRes.rows.length === 0) {
      await db.query(`
        ALTER TABLE cds_scores 
        ADD COLUMN integrity_flag_count INTEGER DEFAULT 0
      `);
      console.log('✓ Successfully added integrity_flag_count column to cds_scores');
    } else {
      console.log('✓ integrity_flag_count column already exists in cds_scores');
    }
    
    return true;
  } catch (error) {
    console.error('✗ Migration failed:', error.message);
    return false;
  }
}

if (require.main === module) {
  migrate().then(success => {
    process.exit(success ? 0 : 1);
  }).catch(err => {
    console.error('✗ Error:', err.message);
    process.exit(1);
  });
}

module.exports = { migrate };

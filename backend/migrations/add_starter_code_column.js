/**
 * Migration script to add starter_code column to exercises table
 * This script is idempotent - it checks if the column exists before adding it
 */

const db = require('../config/db');

async function addStarterCodeColumn() {
  try {
    console.log('Checking if starter_code column exists in exercises table...');

    // Check if the column already exists
    const columnCheck = await db.query(`
      SELECT column_name
      FROM information_schema.columns
      WHERE table_name = 'exercises'
      AND column_name = 'starter_code'
    `);

    if (columnCheck.rows.length === 0) {
      console.log('starter_code column does not exist. Adding it...');

      // Add the starter_code column with default value
      await db.query(`
        ALTER TABLE exercises
        ADD COLUMN starter_code TEXT DEFAULT E'#include <iostream>\\nusing namespace std;\\n\\nint main() {\\n  // Write code here\\n  return 0;\\n}\\n'
      `);

      console.log('✓ Successfully added starter_code column to exercises table');
    } else {
      console.log('✓ starter_code column already exists in exercises table');
    }

    // Verify the column has the correct default value
    const defaultCheck = await db.query(`
      SELECT column_default
      FROM information_schema.columns
      WHERE table_name = 'exercises'
      AND column_name = 'starter_code'
    `);

    if (defaultCheck.rows.length > 0) {
      console.log('✓ starter_code column default value verified');
    }

    return true;
  } catch (error) {
    console.error('✗ Error in migration:', error.message);
    return false;
  }
}

// Run the migration if this script is executed directly
if (require.main === module) {
  addStarterCodeColumn().then(success => {
    process.exit(success ? 0 : 1);
  }).catch(err => {
    console.error('✗ Migration failed:', err.message);
    process.exit(1);
  });
}

module.exports = { addStarterCodeColumn };
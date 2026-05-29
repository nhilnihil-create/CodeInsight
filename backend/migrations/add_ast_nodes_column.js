/**
 * Migration script to add ast_nodes column to exercises table
 * This script is idempotent - it checks if the column exists before adding it
 */

const db = require('../config/db');

async function addAstNodesColumn() {
  try {
    console.log('Checking if ast_nodes column exists in exercises table...');

    // Check if the column already exists
    const columnCheck = await db.query(`
      SELECT column_name
      FROM information_schema.columns
      WHERE table_name = 'exercises'
      AND column_name = 'ast_nodes'
    `);

    if (columnCheck.rows.length === 0) {
      console.log('ast_nodes column does not exist. Adding it...');

      // Add the ast_nodes column
      await db.query(`
        ALTER TABLE exercises
        ADD COLUMN ast_nodes TEXT[]
      `);

      console.log('✓ Successfully added ast_nodes column to exercises table');

      // Populate ast_nodes from the exercise's concept
      console.log('Populating ast_nodes from concept definitions...');
      await db.query(`
        UPDATE exercises e
        SET ast_nodes = c.ast_nodes
        FROM concepts c
        WHERE e.concept_id = c.id
        AND e.ast_nodes IS NULL
      `);

      console.log('✓ Successfully populated ast_nodes for existing exercises');
    } else {
      console.log('✓ ast_nodes column already exists in exercises table');
    }

    // Verify the column exists
    const verifyCheck = await db.query(`
      SELECT column_name
      FROM information_schema.columns
      WHERE table_name = 'exercises'
      AND column_name = 'ast_nodes'
    `);

    if (verifyCheck.rows.length > 0) {
      console.log('✓ ast_nodes column verified');
    }

    return true;
  } catch (error) {
    console.error('✗ Error in migration:', error.message);
    return false;
  }
}

// Run the migration if this script is executed directly
if (require.main === module) {
  addAstNodesColumn().then(success => {
    process.exit(success ? 0 : 1);
  }).catch(err => {
    console.error('✗ Migration failed:', err.message);
    process.exit(1);
  });
}

module.exports = { addAstNodesColumn };

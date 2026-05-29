require('dotenv').config();
const { Pool } = require('pg');

const db = new Pool({
  host: process.env.DB_HOST,
  port: process.env.DB_PORT,
  database: process.env.DB_NAME,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD
});

async function addColumns() {
  const client = await db.connect();
  try {
    console.log('Adding missing columns to exercises table...');

    // Add starter_code column
    try {
      await client.query(`
        ALTER TABLE exercises
        ADD COLUMN starter_code TEXT DEFAULT E'#include <iostream>\\nusing namespace std;\\n\\nint main() {\\n  // Write code here\\n  return 0;\\n}\\n'
      `);
      console.log('✓ Added starter_code column');
    } catch (e) {
      if (e.message.includes('already exists')) {
        console.log('✓ starter_code column already exists');
      } else {
        throw e;
      }
    }

    // Add ast_nodes column
    try {
      await client.query(`
        ALTER TABLE exercises
        ADD COLUMN ast_nodes TEXT[]
      `);
      console.log('✓ Added ast_nodes column');
    } catch (e) {
      if (e.message.includes('already exists')) {
        console.log('✓ ast_nodes column already exists');
      } else {
        throw e;
      }
    }

    // Populate ast_nodes from concepts
    console.log('Populating ast_nodes from concept definitions...');
    await client.query(`
      UPDATE exercises e
      SET ast_nodes = c.ast_nodes
      FROM concepts c
      WHERE e.concept_id = c.id
      AND (e.ast_nodes IS NULL OR e.ast_nodes = ARRAY[]::TEXT[])
    `);
    console.log('✓ Populated ast_nodes for exercises');

    // Verify columns
    const cols = await client.query(`
      SELECT column_name FROM information_schema.columns
      WHERE table_name = 'exercises'
      AND column_name IN ('starter_code', 'ast_nodes')
      ORDER BY column_name
    `);

    console.log('✓ Migration complete. Verified columns:');
    cols.rows.forEach(r => console.log('  -', r.column_name));

  } catch (err) {
    console.error('✗ Migration error:', err.message);
    process.exit(1);
  } finally {
    await client.release();
    await db.end();
  }
}

addColumns();

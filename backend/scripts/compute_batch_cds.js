/**
 * Compute batch CDS for a given exercise.
 * Usage: node scripts/compute_batch_cds.js <exerciseId>
 * Run from: backend/
 */
require('dotenv').config({ path: __dirname + '/../.env', quiet: true });
const { Pool } = require('pg');
const cdsEngine = require('../services/cdsEngine');

const pool = new Pool({
  host: process.env.DB_HOST || 'localhost',
  port: process.env.DB_PORT || '5432',
  database: process.env.DB_NAME || 'codeinsight',
  user: process.env.DB_USER || 'codeuser',
  password: process.env.DB_PASSWORD || 'codepassword123',
});

async function main() {
  const exerciseId = parseInt(process.argv[2], 10);
  if (!exerciseId) throw new Error('Usage: node scripts/compute_batch_cds.js <exerciseId>');
  console.log(`Computing batch CDS for exercise ${exerciseId}...`);
  const result = await cdsEngine.computeBatchCDS(exerciseId, pool);
  console.log(`CDS result:`, JSON.stringify(result).slice(0, 500));
  await pool.end();
}

main().catch(err => {
  console.error('CDS computation failed:', err.message);
  process.exit(1);
});

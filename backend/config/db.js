const { Pool } = require('pg');
const pool = new Pool({
  host:     process.env.DB_HOST,
  port:     process.env.DB_PORT,
  database: process.env.DB_NAME,
  user:     process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  max: 20,
  idleTimeoutMillis: 30000,
});

pool.query('SELECT 1')
  .then(() => console.log('PostgreSQL connected'))
  .catch(err => console.error('DB connection error:', err));

/**
 * Execute a function inside a transaction. Auto-rolls back on throw.
 * @param {(client: import('pg').PoolClient) => Promise<any>} fn
 * @returns {Promise<any>}
 */
async function withTransaction(fn) {
  const client = await pool.connect();
  try {
    await client.query('BEGIN');
    const result = await fn(client);
    await client.query('COMMIT');
    return result;
  } catch (err) {
    try { await client.query('ROLLBACK'); } catch (_) { /* ignore */ }
    throw err;
  } finally {
    client.release();
  }
}

module.exports = pool;
module.exports.withTransaction = withTransaction;

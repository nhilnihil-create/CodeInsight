// Usage: node backend/scripts/seed_admin.js <email> <password> [name]
//
// Creates (or updates) an admin user. Bypasses /api/auth/register so it
// works regardless of the validator's current behavior. Idempotent: a
// re-run with the same email updates the password and reasserts role.

const bcrypt = require('bcryptjs');
require('dotenv').config();
const db = require('../config/db');

(async () => {
  const [, , email, password, name = 'Seeded Admin'] = process.argv;
  if (!email || !password) {
    console.error('Usage: seed_admin.js <email> <password> [name]');
    process.exit(2);
  }
  if (password.length < 8) {
    console.error('Password must be ≥ 8 characters');
    process.exit(2);
  }
  if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)) {
    console.error('Invalid email format');
    process.exit(2);
  }
  try {
    const hash = await bcrypt.hash(password, 10);
    const r = await db.query(
      `INSERT INTO users (name, email, password_hash, role)
       VALUES ($1, $2, $3, 'admin')
       ON CONFLICT (email) DO UPDATE
         SET name = EXCLUDED.name,
             password_hash = EXCLUDED.password_hash,
             role = 'admin'
       RETURNING id, name, email, role`,
      [name, email, hash]
    );
    console.log('✓ admin user ready:', r.rows[0]);
    process.exit(0);
  } catch (err) {
    console.error('Failed:', err.message);
    process.exit(1);
  }
})();

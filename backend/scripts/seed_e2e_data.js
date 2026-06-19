require('dotenv').config({ path: __dirname + '/../.env', quiet: true });
const { Pool } = require('pg');

const pool = new Pool({
  host: process.env.DB_HOST || 'localhost',
  port: process.env.DB_PORT || '5432',
  database: process.env.DB_NAME || 'codeinsight_test',
  user: process.env.DB_USER || 'codeuser',
  password: process.env.DB_PASSWORD || 'codepassword123',
});

async function seed() {
  const bcrypt = require('bcryptjs');
  const hash = bcrypt.hashSync('password123', 10);

  // Create instructor
  await pool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, $3, $4) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4`,
    ['Dr. Instructor', 'instructor@psu.edu', hash, 'instructor']
  );

  // Create student
  await pool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, $3, $4) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4`,
    ['Maria Student', 'maria@student.psu.edu', hash, 'student']
  );

  console.log('E2E seed data loaded successfully');
  await pool.end();
}

seed().catch(err => {
  console.error('Seed failed:', err);
  process.exit(1);
});

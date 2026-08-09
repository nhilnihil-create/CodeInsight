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
    `INSERT INTO users (name, email, password_hash, role, email_verified)
     VALUES ($1, $2, $3, $4, true) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4, email_verified=true`,
    ['Dr. Instructor', 'instructor@psu.edu', hash, 'instructor']
  );

  // Create student
  await pool.query(
    `INSERT INTO users (name, email, password_hash, role, email_verified)
     VALUES ($1, $2, $3, $4, true) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4, email_verified=true`,
    ['Maria Student', 'maria@student.psu.edu', hash, 'student']
  );

  // Create a section so instructor-flow E2E tests have data on a fresh DB
  const instructorRes = await pool.query(
    `SELECT id FROM users WHERE email = $1`,
    ['instructor@psu.edu']
  );
  const instructorId = instructorRes.rows[0]?.id;
  if (instructorId) {
    await pool.query(
      `INSERT INTO sections (name, course_code, semester, school_year, instructor_id, code)
       SELECT $1, $2, $3, $4, $5, $6
       WHERE NOT EXISTS (SELECT 1 FROM sections WHERE code = $6)`,
      ['E2E Seed Section', 'CS101', 'Sem 1', '2025-2026', instructorId, 'SE3-D01']
    );
  }

  console.log('E2E seed data loaded successfully');
  await pool.end();
}

seed().catch(err => {
  console.error('Seed failed:', err);
  process.exit(1);
});

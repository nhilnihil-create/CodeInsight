require('dotenv').config({ path: __dirname + '/../.env', quiet: true });
const { Pool } = require('pg');
const bcrypt = require('bcryptjs');

const pool = new Pool({
  host: process.env.DB_HOST || 'localhost',
  port: process.env.DB_PORT || '5432',
  database: process.env.DB_NAME || 'codeinsight',
  user: process.env.DB_USER || 'codeuser',
  password: process.env.DB_PASSWORD || 'codepassword123',
});

async function seed() {
  const PASSWORD = 'password123';
  const hash = bcrypt.hashSync(PASSWORD, 10);

  // Clean previous run
  await pool.query(`DELETE FROM sections WHERE name = 'E2E 10 Student Test'`);

  // Instructor
  const { rows: [instructor] } = await pool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, $3, $4) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4 RETURNING id`,
    ['Dr. Instructor', 'instructor@psu.edu', hash, 'instructor']
  );
  const instructorId = instructor.id;

  // Create 10 students (ids 0-9)
  const studentIds = [];
  for (let i = 1; i <= 10; i++) {
    const name = `Student ${String(i).padStart(2, '0')}`;
    const email = `student${String(i).padStart(2, '0')}@test.edu`;
    const { rows: [s] } = await pool.query(
      `INSERT INTO users (name, email, password_hash, role)
       VALUES ($1, $2, $3, $4) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4 RETURNING id`,
      [name, email, hash, 'student']
    );
    studentIds.push(s.id);
  }

  // Create section
  const { rows: [section] } = await pool.query(
    `INSERT INTO sections (name, course_code, instructor_id)
     VALUES ($1, $2, $3) RETURNING id`,
    ['E2E 10 Student Test', 'E2E-10', instructorId]
  );
  const sectionId = section.id;

  // Create exercise with concept_id=2 (Variables) and a test case so compilation runs
  const testCases = JSON.stringify([{ input: '', expected_output: '5', isVisible: true, validationType: 'exact', hidden: false }]);
  const { rows: [exercise] } = await pool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, time_limit_minutes, test_cases)
     VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id`,
    [sectionId, 2, 'E2E Variables Test',
     'Write a program that declares an integer variable, assigns it a value, and prints it.',
     '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  cout << x;\n  return 0;\n}',
     30, testCases]
  );
  const exerciseId = exercise.id;

  // Enroll all students
  for (const sid of studentIds) {
    await pool.query(
      `INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
      [sid, sectionId]
    );
  }

  console.log(JSON.stringify({
    sectionId,
    exerciseId,
    instructorEmail: 'instructor@psu.edu',
    instructorPassword: PASSWORD,
    studentEmails: Array.from({ length: 10 }, (_, i) => `student${String(i + 1).padStart(2, '0')}@test.edu`),
    studentPassword: PASSWORD,
    totalStudents: 10
  }));
  await pool.end();
}

seed().catch(err => { console.error('Seed failed:', err); process.exit(1); });

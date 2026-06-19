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
  const hash = bcrypt.hashSync('password123', 10);

  // Ensure instructor exists
  const { rows: [instructor] } = await pool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, $3, $4)
     ON CONFLICT (email) DO UPDATE SET name=$1, role=$4
     RETURNING id`,
    ['Dr. Instructor', 'instructor@psu.edu', hash, 'instructor']
  );
  const instructorId = instructor.id;

  // Ensure student exists
  const { rows: [student] } = await pool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, $3, $4)
     ON CONFLICT (email) DO UPDATE SET name=$1, role=$4
     RETURNING id`,
    ['Maria Student', 'maria@student.psu.edu', hash, 'student']
  );
  const studentId = student.id;

  // Clean previous E2E misconception data (cascades to exercises, submissions, enrollments)
  await pool.query(`DELETE FROM sections WHERE name = 'E2E Misconception Test'`);

  // Create section
  const { rows: [section] } = await pool.query(
    `INSERT INTO sections (name, course_code, instructor_id)
     VALUES ($1, $2, $3)
     RETURNING id`,
    ['E2E Misconception Test', 'E2E-MC', instructorId]
  );
  const sectionId = section.id;

  // Create exercise with concept_id=2 (Variables)
  const { rows: [exercise] } = await pool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, time_limit_minutes)
     VALUES ($1, $2, $3, $4, $5, $6)
     RETURNING id`,
    [
      sectionId,
      2,
      'Variables Practice - E2E',
      'Write a program that declares variables and prints their values',
      '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  cout << x;\n  return 0;\n}',
      30
    ]
  );
  const exerciseId = exercise.id;

  // Enroll student
  await pool.query(
    `INSERT INTO enrollments (student_id, section_id)
     VALUES ($1, $2)
     ON CONFLICT DO NOTHING`,
    [studentId, sectionId]
  );

  // Create submission with undeclared variable compiler error
  await pool.query(
    `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_feedback_hints, compiler_log)
     VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
    [
      studentId,
      exerciseId,
      1,
      '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  y = x + 10;\n  cout << y;\n  return 0;\n}',
      false,
      120,
      JSON.stringify([{ passed: false, expected: '15', actual: '', status: 'Compile Error' }]),
      `[Line 5:5] ERROR: 'y' was not declared in this scope\n    y = x + 10;\n    ^`
    ]
  );

  console.log(`E2E misconception seed done. sectionId=${sectionId} exerciseId=${exerciseId}`);
  await pool.end();
}

seed().catch(err => {
  console.error('Seed failed:', err);
  process.exit(1);
});

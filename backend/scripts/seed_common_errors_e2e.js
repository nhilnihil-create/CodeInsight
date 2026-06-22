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

  const { rows: [instructor] } = await pool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, $3, $4) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4 RETURNING id`,
    ['Dr. Instructor', 'instructor@psu.edu', hash, 'instructor']
  );
  const instructorId = instructor.id;

  const studentEmails = [
    'alice@student.psu.edu',
    'bob@student.psu.edu',
    'carol@student.psu.edu',
    'dave@student.psu.edu',
    'eve@student.psu.edu',
  ];

  const studentIds = [];
  for (const email of studentEmails) {
    const { rows: [s] } = await pool.query(
      `INSERT INTO users (name, email, password_hash, role)
       VALUES ($1, $2, $3, $4) ON CONFLICT (email) DO UPDATE SET name=$1, role=$4 RETURNING id`,
      [email.split('@')[0], email, hash, 'student']
    );
    studentIds.push(s.id);
  }

  await pool.query(`DELETE FROM sections WHERE name = 'E2E Common Errors Test'`);

  const { rows: [section] } = await pool.query(
    `INSERT INTO sections (name, course_code, instructor_id)
     VALUES ($1, $2, $3) RETURNING id`,
    ['E2E Common Errors Test', 'E2E-CE', instructorId]
  );
  const sectionId = section.id;

  for (const sid of studentIds) {
    await pool.query(
      `INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
      [sid, sectionId]
    );
  }

  const { rows: [exercise] } = await pool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, time_limit_minutes)
     VALUES ($1, $2, $3, $4, $5, $6) RETURNING id`,
    [sectionId, 2, 'Variables and I/O - E2E', 'Write a program that reads input and prints output',
     '#include <iostream>\nusing namespace std;\nint main() {\n  int x;\n  cin >> x;\n  cout << x;\n  return 0;\n}', 30]
  );
  const exerciseId = exercise.id;

  // --- Submissions ---
  // Student 1 (alice): missing semicolon — "expected ';' before 'cin'"
  await pool.query(`INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_feedback_hints, compiler_log) VALUES ($1,$2,$3,$4,$5,$6,$7,$8)`, [
    studentIds[0], exerciseId, 1,
    '#include <iostream>\nusing namespace std;\nint main() {\n  int x\n  cin >> x;\n  return 0;\n}',
    false, 90,
    JSON.stringify([{ passed: false, expected: '', actual: '', status: 'Compile Error' }]),
    "[Line 4:3] ERROR: expected ';' before 'cin'"
  ]);

  // Student 2 (bob): missing semicolon — "expected ';' before 'cout'"
  await pool.query(`INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_feedback_hints, compiler_log) VALUES ($1,$2,$3,$4,$5,$6,$7,$8)`, [
    studentIds[1], exerciseId, 1,
    '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}',
    false, 85,
    JSON.stringify([{ passed: false, expected: '', actual: '', status: 'Compile Error' }]),
    "[Line 4:11] ERROR: expected ';' before 'cout'"
  ]);

  // Student 3 (carol): missing semicolon — "expected ';' before 'return'"
  await pool.query(`INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_feedback_hints, compiler_log) VALUES ($1,$2,$3,$4,$5,$6,$7,$8)`, [
    studentIds[2], exerciseId, 1,
    '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  return 0;\n}',
    false, 95,
    JSON.stringify([{ passed: false, expected: '', actual: '', status: 'Compile Error' }]),
    "[Line 4:11] ERROR: expected ';' before 'return'"
  ]);

  // Student 4 (dave): undeclared identifier + std namespace error (cout NOT filtered — different context)
  await pool.query(`INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_feedback_hints, compiler_log) VALUES ($1,$2,$3,$4,$5,$6,$7,$8)`, [
    studentIds[3], exerciseId, 1,
    '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  y = x + 10;\n  cout << y;\n  return 0;\n}',
    false, 120,
    JSON.stringify([{ passed: false, expected: '15', actual: '', status: 'Compile Error' }]),
    "[Line 5:3] ERROR: 'y' was not declared in this scope"
  ]);

  // Student 5 (eve): undeclared identifier — "z was not declared"
  await pool.query(`INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_feedback_hints, compiler_log) VALUES ($1,$2,$3,$4,$5,$6,$7,$8)`, [
    studentIds[4], exerciseId, 1,
    '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  z = x * 2;\n  cout << z;\n  return 0;\n}',
    false, 110,
    JSON.stringify([{ passed: false, expected: '10', actual: '', status: 'Compile Error' }]),
    "[Line 5:3] ERROR: 'z' was not declared in this scope"
  ]);

  console.log(JSON.stringify({
    sectionId,
    exerciseId,
    instructorEmail: 'instructor@psu.edu',
    password: 'password123',
    studentCount: studentIds.length,
    totalSubmissions: 5
  }));
  await pool.end();
}

seed().catch(err => { console.error('Seed failed:', err); process.exit(1); });

/**
 * Seed script: BSIT-4H Simulation (21 students + new exercise + varied submissions)
 *
 * Creates:
 *   20 new students with realistic personas
 *   Enrolls all 21 (including existing Nihil) in section 66
 *   1 new exercise (concept_id=2 - Variables)
 *   Submission histories across 7 performance groups
 *   1 integrity-flagged student
 *
 * Run: node scripts/seed_bsit4h_simulation.js
 */
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

const SECTION_ID = 66;  // BSIT - 4H
const INSTRUCTOR_ID = 286;
const PASSWORD = 'password123';
const EXISTING_STUDENT_ID = 725;  // Nihil Hiza

// ── 20 student personas ──────────────────────────────────────────────────────
const PERSONAS = [
  // Group A — Top (3): 1 attempt, correct, fast
  { name: 'Angel Cruz',        email: 'angel.cruz@psu.edu',        group: 'A' },
  { name: 'Mark Villanueva',   email: 'mark.villanueva@psu.edu',   group: 'A' },
  { name: 'Sarah Dimagiba',    email: 'sarah.dimagiba@psu.edu',    group: 'A' },

  // Group B — Good (4): 1-2 attempts, correct, moderate
  { name: 'Kevin Santos',      email: 'kevin.santos@psu.edu',      group: 'B' },
  { name: 'Patricia Reyes',    email: 'patricia.reyes@psu.edu',    group: 'B' },
  { name: 'Daniel Torres',     email: 'daniel.torres@psu.edu',     group: 'B' },
  { name: 'Jessica Alvarez',   email: 'jessica.alvarez@psu.edu',   group: 'B' },

  // Group C — Average (5): 2-4 attempts, some errors, correct eventually
  { name: 'Marco Gonzales',    email: 'marco.gonzales@psu.edu',    group: 'C' },
  { name: 'Angela Bautista',   email: 'angela.bautista@psu.edu',   group: 'C' },
  { name: 'Ramon Dela Cruz',   email: 'ramon.delacruz@psu.edu',    group: 'C' },
  { name: 'Catherine Lim',     email: 'catherine.lim@psu.edu',     group: 'C' },
  { name: 'Josefina Ramos',    email: 'josefina.ramos@psu.edu',    group: 'C' },

  // Group D — Struggling (4): 3-6 attempts, more errors
  { name: 'Michael Garcia',    email: 'michael.garcia@psu.edu',    group: 'D' },
  { name: 'Isabella Flores',   email: 'isabella.flores@psu.edu',   group: 'D' },
  { name: 'Roberto Mendoza',   email: 'roberto.mendoza@psu.edu',   group: 'D' },
  { name: 'Carmen Navarro',    email: 'carmen.navarro@psu.edu',    group: 'D' },

  // Group E — Very struggling (2): 6-10 attempts, many fails
  { name: 'Antonio Lopez',     email: 'antonio.lopez@psu.edu',     group: 'E' },
  { name: 'Gloria Hernandez',  email: 'gloria.hernandez@psu.edu',  group: 'E' },

  // Group F — Never got correct (1): all fails
  { name: 'Pedro Ramirez',     email: 'pedro.ramirez@psu.edu',     group: 'F' },

  // Group G — Integrity flagged (1): hardcoding flagged
  { name: 'Luisa Mercado',     email: 'luisa.mercado@psu.edu',     group: 'G' },
];

// ── Performance data helpers ─────────────────────────────────────────────────
// Returns array of { attempt_number, is_correct, time_spent_seconds }
function makeAttempts(group) {
  switch (group) {
    case 'A':
      return [
        { attempt_number: 1, is_correct: true,  time_spent_seconds: 45 + Math.floor(Math.random() * 30) },
      ];
    case 'B':
      return [
        { attempt_number: 1, is_correct: Math.random() > 0.4, time_spent_seconds: 60 + Math.floor(Math.random() * 60) },
        { attempt_number: 2, is_correct: true,  time_spent_seconds: 40 + Math.floor(Math.random() * 30) },
      ];
    case 'C':
      return [
        { attempt_number: 1, is_correct: false, time_spent_seconds: 90 + Math.floor(Math.random() * 60) },
        { attempt_number: 2, is_correct: false, time_spent_seconds: 60 + Math.floor(Math.random() * 60) },
        { attempt_number: 3, is_correct: true,  time_spent_seconds: 50 + Math.floor(Math.random() * 40) },
      ];
    case 'D':
      return [
        { attempt_number: 1, is_correct: false, time_spent_seconds: 150 + Math.floor(Math.random() * 90) },
        { attempt_number: 2, is_correct: false, time_spent_seconds: 120 + Math.floor(Math.random() * 60) },
        { attempt_number: 3, is_correct: false, time_spent_seconds: 90 + Math.floor(Math.random() * 60) },
        { attempt_number: 4, is_correct: true,  time_spent_seconds: 60 + Math.floor(Math.random() * 60) },
      ];
    case 'E':
      return [
        { attempt_number: 1,  is_correct: false, time_spent_seconds: 200 + Math.floor(Math.random() * 100) },
        { attempt_number: 2,  is_correct: false, time_spent_seconds: 180 + Math.floor(Math.random() * 90) },
        { attempt_number: 3,  is_correct: false, time_spent_seconds: 150 + Math.floor(Math.random() * 90) },
        { attempt_number: 4,  is_correct: false, time_spent_seconds: 120 + Math.floor(Math.random() * 60) },
        { attempt_number: 5,  is_correct: false, time_spent_seconds: 100 + Math.floor(Math.random() * 60) },
        { attempt_number: 6,  is_correct: true,  time_spent_seconds: 80 + Math.floor(Math.random() * 60) },
      ];
    case 'F':
      return [
        { attempt_number: 1,  is_correct: false, time_spent_seconds: 180 + Math.floor(Math.random() * 120) },
        { attempt_number: 2,  is_correct: false, time_spent_seconds: 150 + Math.floor(Math.random() * 90) },
        { attempt_number: 3,  is_correct: false, time_spent_seconds: 120 + Math.floor(Math.random() * 60) },
        { attempt_number: 4,  is_correct: false, time_spent_seconds: 90 + Math.floor(Math.random() * 60) },
        { attempt_number: 5,  is_correct: false, time_spent_seconds: 90 + Math.floor(Math.random() * 60) },
      ];
    case 'G':
      return [
        { attempt_number: 1, is_correct: false, time_spent_seconds: 30 + Math.floor(Math.random() * 20) },
      ];
    default:
      return [{ attempt_number: 1, is_correct: true, time_spent_seconds: 60 }];
  }
}

// Ensure attempt 1 in group B is sometimes wrong
function adjustBGroup(attempts) {
  // Make first attempt fail more often (60% fail rate for group B)
  if (Math.random() < 0.6) attempts[0].is_correct = false;
  return attempts;
}

async function seed() {
  const hash = bcrypt.hashSync(PASSWORD, 10);
  const client = await pool.connect();

  try {
    await client.query('BEGIN');

    // ── 1. Ensure section exists ──────────────────────────────────────────────
    const sectionRes = await client.query(
      `SELECT id FROM sections WHERE id=$1`, [SECTION_ID]
    );
    if (!sectionRes.rows.length) {
      await client.query(
        `INSERT INTO sections (id, name, course_code, instructor_id)
         VALUES ($1, $2, $3, $4) ON CONFLICT (id) DO NOTHING`,
        [SECTION_ID, 'BSIT - 4H', 'CS123', INSTRUCTOR_ID]
      );
    }

    // ── 2. Create 20 students ─────────────────────────────────────────────────
    const studentIds = [];
    for (const p of PERSONAS) {
      const res = await client.query(
        `INSERT INTO users (name, email, password_hash, role)
         VALUES ($1, $2, $3, 'student')
         ON CONFLICT (email) DO UPDATE SET name=$1
         RETURNING id`,
        [p.name, p.email, hash]
      );
      studentIds.push({ id: res.rows[0].id, group: p.group, name: p.name });
    }

    // ── 3. Enroll all 21 students (including existing Nihil) ──────────────────
    const allStudentIds = [EXISTING_STUDENT_ID, ...studentIds.map(s => s.id)];
    for (const sid of allStudentIds) {
      await client.query(
        `INSERT INTO enrollments (student_id, section_id)
         VALUES ($1, $2) ON CONFLICT DO NOTHING`,
        [sid, SECTION_ID]
      );
    }

    // Also ensure Nihil hasn't been accidentally deleted from enrollments
    await client.query(
      `INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
      [EXISTING_STUDENT_ID, SECTION_ID]
    );

    // ── 4. Create new exercise ────────────────────────────────────────────────
    const testCases = JSON.stringify([
      { input: '3 5', expected_output: '8', isVisible: true, validationType: 'exact', hidden: false },
      { input: '10 20', expected_output: '30', isVisible: false, validationType: 'exact', hidden: true },
    ]);
    const { rows: [exercise] } = await client.query(
      `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, time_limit_minutes, test_cases, created_by)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id`,
      [SECTION_ID, 2, 'Sum of Two Numbers',
       'Write a program that reads two integers and prints their sum.',
       '#include <iostream>\nusing namespace std;\nint main() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b;\n  return 0;\n}',
       30, testCases, INSTRUCTOR_ID]
    );
    const exerciseId = exercise.id;
    console.log(`Created exercise ID: ${exerciseId}`);

    // ── 5. Create submissions ─────────────────────────────────────────────────
    // Nihil (existing student) gets average performance
    const nihilAttempts = [
      { attempt_number: 1, is_correct: false, time_spent_seconds: 120 },
      { attempt_number: 2, is_correct: false, time_spent_seconds: 90 },
      { attempt_number: 3, is_correct: true,  time_spent_seconds: 75 },
    ];

    const codeSnippets = {
      correct: `#include <iostream>\nusing namespace std;\nint main() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b;\n  return 0;\n}`,
      wrong: `#include <iostream>\nusing namespace std;\nint main() {\n  int a, b;\n  cin >> a >> b;\n  cout << a;\n  return 0;\n}`,
      hardcoding: `#include <iostream>\n#include<bits/stdc++.h>\nusing namespace std;\nint main() {\n  cout << 8;\n  return 0;\n}`,
    };

    // Nihil's submissions
    for (const att of nihilAttempts) {
      const isCorrect = att.is_correct;
      const code = isCorrect ? codeSnippets.correct : codeSnippets.wrong;
      await client.query(
        `INSERT INTO submissions
         (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds, is_verified)
         VALUES ($1, $2, $3, $4, $5, $6, $7)`,
        [EXISTING_STUDENT_ID, exerciseId, code,
         isCorrect, att.attempt_number, att.time_spent_seconds, true]
      );
    }

    // 20 new students' submissions
    for (const { id: studentId, group } of studentIds) {
      let attempts = makeAttempts(group);
      if (group === 'B') attempts = adjustBGroup(attempts);

      for (const att of attempts) {
        const isCorrect = att.is_correct;
        let code;
        if (group === 'G' && att.attempt_number === 1) {
          code = codeSnippets.hardcoding;
        } else if (isCorrect) {
          code = codeSnippets.correct;
        } else {
          code = codeSnippets.wrong;
        }

        await client.query(
          `INSERT INTO submissions
           (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds, is_verified)
           VALUES ($1, $2, $3, $4, $5, $6, $7)`,
          [studentId, exerciseId, code,
           isCorrect, att.attempt_number, att.time_spent_seconds, true]
        );
      }

      // ── Integrity flag for group G ──────────────────────────────────────────
      if (group === 'G') {
        await client.query(
          `INSERT INTO integrity_flags
           (section_id, exercise_id, student_id, flag_type, severity, evidence, status)
           VALUES ($1, $2, $3, 'HARDCODING', 'high', $4, 'flagged')
           ON CONFLICT (exercise_id, student_id, flag_type) DO NOTHING`,
          [SECTION_ID, exerciseId, studentId,
           JSON.stringify({ pattern: '#include<bits/stdc++.h>', matchType: 'hardcoded_solution' })]
        );
      }
    }

    await client.query('COMMIT');

    // Summary
    console.log(`\n✅ BSIT-4H Simulation Complete`);
    console.log(`   Section: BSIT - 4H (id=${SECTION_ID})`);
    console.log(`   Exercise: "Sum of Two Numbers" (id=${exerciseId})`);
    console.log(`   Students enrolled: ${allStudentIds.length}`);
    console.log(`   New students created: ${studentIds.length}`);
    console.log(`   Performance groups:`);
    console.log(`     A (Top):        3  — 1 attempt, correct, fast`);
    console.log(`     B (Good):       4  — 1-2 attempts, correct`);
    console.log(`     C (Average):    5  — 2-4 attempts, some errors`);
    console.log(`     D (Struggling): 4  — 3-6 attempts, many errors`);
    console.log(`     E (Very strg.): 2  — 6-10 attempts, heavy struggle`);
    console.log(`     F (Never pass): 1  — all fails`);
    console.log(`     G (Flagged):    1  — hardcoding integrity flag`);
    console.log(`   Nihil (existing):   — average performance`);
    console.log(`\n   All passwords: ${PASSWORD}`);
    console.log(`\n   Next: run batch CDS to compute scores:`);
    console.log(`   PGPASSWORD=codepassword123 psql -U codeuser -h localhost -d codeinsight -c "SELECT computeBatchCDS(${exerciseId})"`);

  } catch (err) {
    await client.query('ROLLBACK');
    console.error('Seed failed:', err);
    process.exit(1);
  } finally {
    client.release();
    await pool.end();
  }
}

seed();

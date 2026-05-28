const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');

async function main() {
  try {
    // Ensure we have an instructor
    const instRes = await db.query("SELECT id FROM users WHERE role='instructor' LIMIT 1");
    const instructorId = instRes.rows[0] ? instRes.rows[0].id : null;

    // Ensure there's a section
    let secRes = await db.query('SELECT id FROM sections LIMIT 1');
    let sectionId;
    if (!secRes.rows.length) {
      const secInsert = await db.query('INSERT INTO sections (name,course_code,school_year,instructor_id) VALUES($1,$2,$3,$4) RETURNING id', [
        'Sim Section', 'SIM101', 'AY2025-2026', instructorId
      ]);
      sectionId = secInsert.rows[0].id;
    } else {
      sectionId = secRes.rows[0].id;
    }

    // Enroll at least 3 students (seeded users exist)
    const students = await db.query("SELECT id FROM users WHERE role='student' LIMIT 5");
    for (const s of students.rows) {
      await db.query('INSERT INTO enrollments (student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING', [s.id, sectionId]);
    }

    // Create exercise
    const testCases = [
      { input: '1', expected_output: '2', hidden: false },
      { input: '2', expected_output: '3', hidden: true }
    ];
    const exInsert = await db.query(
      `INSERT INTO exercises (title,description,concept_id,section_id,created_by,time_limit_minutes,test_cases)
       VALUES($1,$2,$3,$4,$5,$6,$7) RETURNING id`,
      ['Sim Exercise', 'Simulated exercise for CDS test', null, sectionId, instructorId, 5, JSON.stringify(testCases)]
    );
    const exerciseId = exInsert.rows[0].id;

    // Insert submissions for each student: varying attempts
    let cnt = 0;
    for (const s of students.rows) {
      const sid = s.id;
      // Student A: one failed then accepted
      if (cnt % 3 === 0) {
        await db.query(`INSERT INTO submissions (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds) VALUES($1,$2,$3,$4,$5,$6)`, [sid, exerciseId, 'code v1', false, 1, 30]);
        await db.query(`INSERT INTO submissions (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds) VALUES($1,$2,$3,$4,$5,$6)`, [sid, exerciseId, 'code v2', true, 2, 60]);
      } else if (cnt % 3 === 1) {
        // Student B: many retries (outlier)
        for (let a=1;a<=20;a++) {
          await db.query(`INSERT INTO submissions (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds) VALUES($1,$2,$3,$4,$5,$6)`, [sid, exerciseId, `code attempt ${a}`, false, a, 10*a]);
        }
      } else {
        // Student C: never passes, long time
        await db.query(`INSERT INTO submissions (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds) VALUES($1,$2,$3,$4,$5,$6)`, [sid, exerciseId, 'template', false, 1, 270]);
      }
      cnt++;
    }

    console.log('Simulated submissions inserted. Running computeBatchCDS...');
    const res = await cdsEngine.computeBatchCDS(exerciseId, db);
    console.log('CDS computation result:', res);

    const scores = await db.query('SELECT student_id, ner, nrs, nts, cds, classification FROM cds_scores WHERE exercise_id=$1', [exerciseId]);
    console.log('CDS Scores:');
    console.table(scores.rows);

    process.exit(0);
  } catch (err) {
    console.error('Simulation error:', err);
    process.exit(1);
  }
}

main();

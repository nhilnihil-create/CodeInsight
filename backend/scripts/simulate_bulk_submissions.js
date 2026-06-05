#!/usr/bin/env node
/**
 * Bulk Student Submission Simulator
 * Generates 40 test students, enrolls them, and simulates 40-50 varied submissions
 * Each submission triggers calculateLiveCDS
 */

const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const executor = require('../services/executor');
const bcrypt = require('bcryptjs');

const SECTION_ID = 3; // BSIT - 3H
const EXERCISE_ID = 16; // Sum 1 to N
const NUM_STUDENTS = 40;
const SUBMISSIONS_PER_STUDENT = 1.2; // 40-50 total

async function run() {
  try {
    console.log(`[SIMULATOR] Starting bulk enrollment and submission simulation...`);
    
    // 1. Get exercise details
    const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [EXERCISE_ID]);
    if (!exRes.rows.length) throw new Error(`Exercise ${EXERCISE_ID} not found`);
    const exercise = exRes.rows[0];
    console.log(`[SIMULATOR] Exercise: ${exercise.title} (${exercise.time_limit_minutes} min)`);

    // 2. Create test students
    const studentIds = [];
    for (let i = 1; i <= NUM_STUDENTS; i++) {
      const email = `test_student_${String(i).padStart(3, '0')}@test.local`;
      const name = `Test Student ${i}`;
      const passwordHash = await bcrypt.hash('password123', 10);
      
      try {
        const res = await db.query(
          `INSERT INTO users (name, email, password_hash, role)
           VALUES ($1, $2, $3, 'student')
           ON CONFLICT (email) DO UPDATE SET name=$1, password_hash=$3
           RETURNING id`,
          [name, email, passwordHash]
        );
        studentIds.push(res.rows[0].id);
      } catch (err) {
        console.warn(`[SIMULATOR] Skipped ${email}: ${err.message}`);
      }
    }
    console.log(`[SIMULATOR] Created/verified ${studentIds.length} students`);

    // 3. Enroll all in section
    for (const studentId of studentIds) {
      try {
        await db.query(
          `INSERT INTO enrollments (student_id, section_id)
           VALUES ($1, $2)
           ON CONFLICT DO NOTHING`,
          [studentId, SECTION_ID]
        );
      } catch (err) {
        // Silently skip duplicates
      }
    }
    console.log(`[SIMULATOR] Enrolled ${studentIds.length} students in section ${SECTION_ID}`);

    // 4. Simulate submissions with varied outcomes
    let submissionCount = 0;
    for (const studentId of studentIds) {
      // 60% of students submit 1 time, 40% submit 2 times
      const numSubmissions = Math.random() < 0.6 ? 1 : 2;
      
      for (let attempt = 1; attempt <= numSubmissions; attempt++) {
        const isCorrect = Math.random() < 0.65; // 65% pass rate
        const timeSpent = isCorrect 
          ? Math.floor(Math.random() * 25) + 5 // 5-30 min if pass
          : Math.floor(Math.random() * 30) + 15; // 15-45 min if fail
        
        const code = isCorrect 
          ? `#include <iostream>\nusing namespace std;\nint main() {\n  int n;\n  cin >> n;\n  int sum = 0;\n  for (int i = 1; i <= n; i++) { sum += i; }\n  cout << sum;\n  return 0;\n}`
          : `#include <iostream>\nusing namespace std;\nint main() {\n  int n;\n  cin >> n;\n  cout << n;\n  return 0;\n}`; // Incorrect (just echoes input)
        
        try {
          const subRes = await db.query(
            `INSERT INTO submissions (exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds, submitted_at)
             VALUES ($1, $2, $3, $4, $5, $6, NOW())
             RETURNING id`,
            [EXERCISE_ID, studentId, code, isCorrect, attempt, timeSpent * 60]
          );
          
          // Calculate and persist liveCDS for each submission
          const liveCDS = await cdsEngine.calculateLiveCDS(studentId, EXERCISE_ID, db);
          if (liveCDS && liveCDS.cds !== null) {
            await db.query(`
              INSERT INTO cds_scores (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification, has_flagged_attempts, integrity_flag_count, source, visible, computed_at)
              VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, 'live', false, NOW())
              ON CONFLICT (student_id, exercise_id)
              DO UPDATE SET ner=$4, nrs=$5, nts=$6, cds=$7, classification=$8, has_flagged_attempts=$9, integrity_flag_count=$10, source='live', visible=false, computed_at=NOW()
            `, [
              studentId, EXERCISE_ID, SECTION_ID,
              liveCDS.ner || 0, liveCDS.nrs || 0, liveCDS.nts || 0,
              liveCDS.cds || 0, liveCDS.classification || 'Unscored',
              liveCDS.hasFlaggedAttempt || false, liveCDS.integrityFlagCount || 0
            ]);
          }
          
          submissionCount++;
          if (submissionCount % 10 === 0) {
            console.log(`[SIMULATOR] Progress: ${submissionCount} submissions simulated...`);
          }
        } catch (err) {
          console.warn(`[SIMULATOR] Failed to insert submission for student ${studentId}: ${err.message}`);
        }
      }
    }
    
    console.log(`[SIMULATOR] ✅ Simulation complete!`);
    console.log(`[SIMULATOR] Summary: ${studentIds.length} students, ${submissionCount} submissions`);
    
    // 5. Show distribution
    const dist = await db.query(`
      SELECT 
        classification,
        COUNT(*) as count,
        AVG(cds::NUMERIC) as avg_cds,
        MIN(cds::NUMERIC) as min_cds,
        MAX(cds::NUMERIC) as max_cds
      FROM cds_scores
      WHERE exercise_id=$1 AND source='live'
      GROUP BY classification
      ORDER BY classification
    `, [EXERCISE_ID]);
    
    console.log(`\n[SIMULATOR] CDS Distribution (Live):`);
    console.log(dist.rows);
    
    console.log(`\n[SIMULATOR] Ready for instructor to view live CDS panel in UI!`);
    process.exit(0);
  } catch (err) {
    console.error('[SIMULATOR] Fatal error:', err);
    process.exit(1);
  }
}

run();

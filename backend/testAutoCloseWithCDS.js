// Test script for auto-close service with CDS computation and alert generation
const db = require('./config/db');
const autoCloseService = require('./services/autoCloseService');
const cdsEngine = require('./services/cdsEngine.js');
const alertEngine = require('./services/alertEngine.js');

async function testAutoCloseWithCDS() {
  let client;
  try {
    console.log('Starting auto-close with CDS test...');
    client = await db.connect();
    await client.query('BEGIN');

    // Get a section and concept for the exercise
    const sectionRes = await client.query('SELECT id FROM sections LIMIT 1');
    const conceptRes = await client.query('SELECT id FROM concepts LIMIT 1');

    if (sectionRes.rows.length === 0 || conceptRes.rows.length === 0) {
      throw new Error('No sections or concepts found. Please run seed data.');
    }

    const sectionId = sectionRes.rows[0].id;
    const conceptId = conceptRes.rows[0].id;

    // Get an instructor ID (created_by)
    const instructorRes = await client.query('SELECT id FROM users WHERE role = $1 LIMIT 1', ['instructor']);
    if (instructorRes.rows.length === 0) {
      throw new Error('No instructor found.');
    }
    const instructorId = instructorRes.rows[0].id;

    // Get a student ID
    const studentRes = await client.query('SELECT id FROM users WHERE role = $1 LIMIT 1', ['student']);
    if (studentRes.rows.length === 0) {
      throw new Error('No student found.');
    }
    const studentId = studentRes.rows[0].id;

    // Enroll the student in the section (if not already enrolled)
    const enrollmentCheck = await client.query(
      'SELECT id FROM enrollments WHERE student_id = $1 AND section_id = $2',
      [studentId, sectionId]
    );
    if (enrollmentCheck.rows.length === 0) {
      await client.query(
        'INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2)',
        [studentId, sectionId]
      );
      console.log(`Enrolled student ${studentId} in section ${sectionId}`);
    }

    // Insert an exercise with a deadline in the past (10 minutes ago)
    const pastDeadline = new Date(Date.now() - 10 * 60 * 1000); // 10 minutes ago

    const insertExRes = await client.query(
      `INSERT INTO exercises (title, description, concept_id, section_id, created_by, deadline, test_cases, time_limit_minutes)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8)
       RETURNING id`,
      [
        'Test Exercise for Auto-Close with CDS',
        'This is a test exercise to verify the auto-close service triggers CDS computation and alerts.',
        conceptId,
        sectionId,
        instructorId,
        pastDeadline,
        '[{ "input": "", "expected_output": "42" }]', // One test case expecting output 42
        45 // 45 minutes time limit
      ]
    );

    const exerciseId = insertExRes.rows[0].id;
    console.log(`Inserted test exercise with ID: ${exerciseId}`);

    // Insert a submission for the student that will fail (outputs 0 instead of 42)
    const submissionCode = `#include <iostream>
using namespace std;
int main() {
  cout << 0;
  return 0;
}`;
    const timeSpentSeconds = 45 * 60; // Full time limit: 2700 seconds

    const insertSubRes = await client.query(
      `INSERT INTO submissions (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds)
       VALUES ($1, $2, $3, $4, $5, $6)
       RETURNING id`,
      [
        studentId,
        exerciseId,
        submissionCode,
        false, // is_correct: false because output is 0, expected 42
        1,
        timeSpentSeconds
      ]
    );

    const submissionId = insertSubRes.rows[0].id;
    console.log(`Inserted test submission with ID: ${submissionId}`);

    // Verify the exercise is not closed yet
    const checkExRes = await client.query(
      'SELECT closed_at FROM exercises WHERE id = $1',
      [exerciseId]
    );
    console.log(`Exercise closed_at before auto-close: ${checkExRes.rows[0].closed_at}`);

    // Call the auto-close processing function directly
    console.log('Calling processExercisesForAutoClose...');
    await autoCloseService.processExercisesForAutoClose(client);

    // Check again after processing
    const afterExRes = await client.query(
      'SELECT closed_at FROM exercises WHERE id = $1',
      [exerciseId]
    );
    console.log(`Exercise closed_at after auto-close: ${afterExRes.rows[0].closed_at}`);

    if (!afterExRes.rows[0].closed_at) {
      throw new Error('Exercise was not closed by auto-close service.');
    }
    console.log('SUCCESS: Exercise was closed by auto-close service.');

    // Check that a CDS score was generated for the student and exercise
    const cdsScoreRes = await client.query(
      `SELECT ner, nrs, nts, cds, classification
       FROM cds_scores
       WHERE student_id = $1 AND exercise_id = $2`,
      [studentId, exerciseId]
    );

    if (cdsScoreRes.rows.length === 0) {
      throw new Error('No CDS score generated for the student and exercise.');
    }

    const cdsScore = cdsScoreRes.rows[0];
    console.log(`CDS score generated:`, cdsScore);

    // Expected values:
    //   NER = 1 (one failed submission, max failed in class = 1)
    //   NRS = 1 (one total submission, max total in class = 1)
    //   NTS = 1 (time spent = time limit)
    //   CDS = 0.4*1 + 0.35*1 + 0.25*1 = 1.0
    //   Classification: High (>= 0.67)

    const expectedNER = 1;
    const expectedNRS = 1;
    const expectedNTS = 1;
    const expectedCDS = 1.0;
    const expectedClassification = 'High';

    if (Math.abs(cdsScore.ner - expectedNER) > 0.001) {
      throw new Error(`NER mismatch: expected ${expectedNER}, got ${cdsScore.ner}`);
    }
    if (Math.abs(cdsScore.nrs - expectedNRS) > 0.001) {
      throw new Error(`NRS mismatch: expected ${expectedNRS}, got ${cdsScore.nrs}`);
    }
    if (Math.abs(cdsScore.nts - expectedNTS) > 0.001) {
      throw new Error(`NTS mismatch: expected ${expectedNTS}, got ${cdsScore.nts}`);
    }
    if (Math.abs(cdsScore.cds - expectedCDS) > 0.001) {
      throw new Error(`CDS mismatch: expected ${expectedCDS}, got ${cdsScore.cds}`);
    }
    if (cdsScore.classification !== expectedClassification) {
      throw new Error(`Classification mismatch: expected ${expectedClassification}, got ${cdsScore.classification}`);
    }
    console.log('SUCCESS: CDS score is correct.');

    // Check that an alert was generated for the student and exercise (since CDS is High)
    const alertRes = await client.query(
      `SELECT cds_score, classification, concept_name, is_reviewed
       FROM alerts
       WHERE student_id = $1 AND exercise_id = $2`,
      [studentId, exerciseId]
    );

    if (alertRes.rows.length === 0) {
      throw new Error('No alert generated for the student and exercise.');
    }

    const alert = alertRes.rows[0];
    console.log(`Alert generated:`, alert);

    if (Math.abs(alert.cds_score - expectedCDS) > 0.001) {
      throw new Error(`Alert CDS score mismatch: expected ${expectedCDS}, got ${alert.cds_score}`);
    }
    if (alert.classification !== expectedClassification) {
      throw new Error(`Alert classification mismatch: expected ${expectedClassification}, got ${alert.classification}`);
    }
    if (alert.is_reviewed !== false) {
      throw new Error(`Alert should not be reviewed initially, but is_reviewed is ${alert.is_reviewed}`);
    }
    console.log('SUCCESS: Alert is correct and unreviewed.');

    // Commit the transaction
    await client.query('COMMIT');
    console.log('Transaction committed.');

    // Clean up: delete the test submission, exercise, and any cascade deletions
    // Note: We'll delete in reverse order due to foreign keys, but we can also rely on ON DELETE CASCADE
    // However, we are in a transaction and will rollback if there's an error, but we committed.
    // Let's do a separate cleanup step outside the transaction? Or we can delete now.
    // Since we committed, we have to delete explicitly.

    // Delete submission (will cascade to nothing else? submissions table has foreign keys to exercises and students, but we don't want to delete the student or exercise)
    // Actually, we want to delete the submission and the exercise, but leave the student and section for other tests.
    // We'll delete the submission and then the exercise.

    await client.query('DELETE FROM submissions WHERE id = $1', [submissionId]);
    console.log(`Deleted submission ${submissionId}`);

    await client.query('DELETE FROM exercises WHERE id = $1', [exerciseId]);
    console.log(`Deleted exercise ${exerciseId}`);

    // Note: The enrollment we added might stay, but it's okay for now.

  } catch (error) {
    console.error('Test failed:', error);
    // Rollback the transaction if client exists and we are in a transaction
    if (client) {
      try {
        await client.query('ROLLBACK');
        console.log('Transaction rolled back due to error.');
      } catch (rollbackError) {
        console.error('Error during rollback:', rollbackError);
      }
    }
    throw error;
  } finally {
    if (client) {
      client.release();
    }
    // End the process
    process.exit(0);
  }
}

testAutoCloseWithCDS();
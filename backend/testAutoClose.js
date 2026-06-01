// Test script for auto-close service
const db = require('./config/db');
const autoCloseService = require('./services/autoCloseService');

async function testAutoClose() {
  try {
    console.log('Starting auto-close test...');

    // Get a section and concept for the exercise
    const sectionRes = await db.query('SELECT id FROM sections LIMIT 1');
    const conceptRes = await db.query('SELECT id FROM concepts LIMIT 1');

    if (sectionRes.rows.length === 0 || conceptRes.rows.length === 0) {
      throw new Error('No sections or concepts found. Please run seed data.');
    }

    const sectionId = sectionRes.rows[0].id;
    const conceptId = conceptRes.rows[0].id;

    // Get an instructor ID (created_by)
    const instructorRes = await db.query('SELECT id FROM users WHERE role = $1 LIMIT 1', ['instructor']);
    if (instructorRes.rows.length === 0) {
      throw new Error('No instructor found.');
    }
    const instructorId = instructorRes.rows[0].id;

    // Insert an exercise with a deadline in the past (10 minutes ago)
    const pastDeadline = new Date(Date.now() - 10 * 60 * 1000); // 10 minutes ago

    const insertRes = await db.query(
      `INSERT INTO exercises (title, description, concept_id, section_id, created_by, deadline, test_cases)
       VALUES ($1, $2, $3, $4, $5, $6, $7)
       RETURNING id`,
      [
        'Test Exercise for Auto-Close',
        'This is a test exercise to verify the auto-close service.',
        conceptId,
        sectionId,
        instructorId,
        pastDeadline,
        '[]' // empty test cases
      ]
    );

    const exerciseId = insertRes.rows[0].id;
    console.log(`Inserted test exercise with ID: ${exerciseId}`);

    // Verify the exercise is not closed yet
    const checkRes = await db.query(
      'SELECT closed_at FROM exercises WHERE id = $1',
      [exerciseId]
    );
    console.log(`Exercise closed_at before auto-close: ${checkRes.rows[0].closed_at}`);

    // Call the auto-close processing function directly
    console.log('Calling processExercisesForAutoClose...');
    await autoCloseService.processExercisesForAutoClose();

    // Check again after processing
    const afterRes = await db.query(
      'SELECT closed_at FROM exercises WHERE id = $1',
      [exerciseId]
    );
    console.log(`Exercise closed_at after auto-close: ${afterRes.rows[0].closed_at}`);

    if (afterRes.rows[0].closed_at) {
      console.log('SUCCESS: Exercise was closed by auto-close service.');
    } else {
      console.log('FAILURE: Exercise was not closed.');
    }

    // Clean up: delete the test exercise
    await db.query('DELETE FROM exercises WHERE id = $1', [exerciseId]);
    console.log('Cleaned up test exercise.');

  } catch (error) {
    console.error('Test failed:', error);
  } finally {
    // End the process
    process.exit(0);
  }
}

testAutoClose();
require('dotenv').config();
const db = require('./config/db');

async function cleanupTestData() {
  try {
    console.log('🧹 Cleaning up test data...\n');

    // Get test student IDs
    const studentRes = await db.query(
      "SELECT id FROM users WHERE email LIKE 'test_student_%@test.local' ORDER BY id"
    );
    const testStudentIds = studentRes.rows.map(r => r.id);
    console.log(`Found ${testStudentIds.length} test students`);

    if (testStudentIds.length === 0) {
      console.log('✓ No test students to delete');
      await db.end();
      return;
    }

    // Delete in order: submissions → cds_scores → alerts → enrollments → users
    const submissionRes = await db.query(
      `DELETE FROM submissions WHERE student_id = ANY($1::int[])`,
      [testStudentIds]
    );
    console.log(`✓ Deleted ${submissionRes.rowCount} submissions`);

    const cdsRes = await db.query(
      `DELETE FROM cds_scores WHERE student_id = ANY($1::int[])`,
      [testStudentIds]
    );
    console.log(`✓ Deleted ${cdsRes.rowCount} CDS scores`);

    const alertRes = await db.query(
      `DELETE FROM alerts WHERE student_id = ANY($1::int[])`,
      [testStudentIds]
    );
    console.log(`✓ Deleted ${alertRes.rowCount} alerts`);

    const enrollRes = await db.query(
      `DELETE FROM enrollments WHERE student_id = ANY($1::int[])`,
      [testStudentIds]
    );
    console.log(`✓ Deleted ${enrollRes.rowCount} enrollments`);

    const userRes = await db.query(
      `DELETE FROM users WHERE id = ANY($1::int[])`,
      [testStudentIds]
    );
    console.log(`✓ Deleted ${userRes.rowCount} test user accounts`);

    console.log('\n✅ Cleanup complete! Database restored to clean state.');
  } catch (err) {
    console.error('❌ Cleanup failed:', err.message);
  } finally {
    await db.end();
  }
}

cleanupTestData();

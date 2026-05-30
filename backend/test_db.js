const db = require('./config/db');

async function test() {
  try {
    // Find Maria
    const mariaRes = await db.query(`SELECT id, name, email, role FROM users WHERE email = 'maria@student.psu.edu'`);
    console.log('Maria:', mariaRes.rows[0]);
    
    const maria_id = mariaRes.rows[0].id;
    
    // Check her enrollments
    const enrollRes = await db.query(`
      SELECT e.id, e.section_id, s.name
      FROM enrollments e 
      JOIN sections s ON s.id = e.section_id 
      WHERE e.student_id = $1
    `, [maria_id]);
    console.log(`Maria enrolled in ${enrollRes.rows.length} sections:`, enrollRes.rows);
    
    // Check exercises in the list
    const exRes = await db.query(`
      SELECT e.id, e.title, e.section_id, e.is_draft, e.concept_id
      FROM exercises e 
      JOIN enrollments en ON en.section_id = e.section_id
      WHERE en.student_id = $1 AND e.is_draft = false
      LIMIT 5
    `, [maria_id]);
    console.log(`\nExercises visible to Maria (${exRes.rows.length}):`, exRes.rows);
    
    if (exRes.rows.length > 0) {
      const ex = exRes.rows[0];
      console.log(`\nTrying to fetch exercise ${ex.id} in detail...`);
      
      const detailRes = await db.query(`
        SELECT ex.id, ex.title, ex.section_id, ex.test_cases, c.name as concept_name
        FROM exercises ex
        JOIN concepts c ON c.id = ex.concept_id
        JOIN enrollments en ON en.section_id = ex.section_id
        WHERE ex.id = $1 AND en.student_id = $2
      `, [ex.id, maria_id]);
      
      console.log(`Detail query result: ${detailRes.rows.length} rows`);
      if (detailRes.rows[0]) {
        const detail = detailRes.rows[0];
        console.log(`  - test_cases type: ${typeof detail.test_cases}`);
        console.log(`  - test_cases: ${detail.test_cases}`);
      }
    }
    
    process.exit(0);
  } catch (err) {
    console.error('ERROR:', err.message);
    console.error(err.stack);
    process.exit(1);
  }
}

test();

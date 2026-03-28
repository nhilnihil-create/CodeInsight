#!/usr/bin/env node
require('dotenv').config();
const db = require('./config/db');

async function check() {
  try {
    console.log('🔍 Checking CodeInsight setup...\n');
    
    // Check concepts
    const conceptsRes = await db.query('SELECT id, name FROM concepts ORDER BY id');
    console.log(`✓ Concepts: ${conceptsRes.rows.length} found`);
    conceptsRes.rows.forEach(c => console.log(`  - ${c.name}`));
    
    // Check users
    const usersRes = await db.query('SELECT id, name, role FROM users ORDER BY id');
    console.log(`\n✓ Users: ${usersRes.rows.length} found`);
    usersRes.rows.forEach(u => console.log(`  - ${u.name} (${u.role})`));
    
    // Check sections
    const sectionsRes = await db.query('SELECT id, name, instructor_id FROM sections ORDER BY id');
    console.log(`\n✓ Sections: ${sectionsRes.rows.length} found`);
    sectionsRes.rows.forEach(s => console.log(`  - ${s.name} (instructor_id: ${s.instructor_id})`));
    
    // Check enrollments
    const enrollmentsRes = await db.query('SELECT COUNT(*) as count FROM enrollments');
    console.log(`\n✓ Enrollments: ${enrollmentsRes.rows[0].count} found`);
    
    // Check exercises
    const exercisesRes = await db.query(`
      SELECT ex.id, ex.title, c.name as concept, sec.name as section, 
             ex.time_limit_minutes
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN sections sec ON sec.id = ex.section_id
      ORDER BY ex.id
    `);
    console.log(`\n✓ Exercises: ${exercisesRes.rows.length} found`);
    exercisesRes.rows.forEach(e => console.log(`  - ${e.title} (${e.concept}, section: ${e.section})`));
    
    // Check enrollments per student
    const studentExercisesRes = await db.query(`
      SELECT u.id, u.name, COUNT(DISTINCT ex.id) as exercises
      FROM users u
      JOIN enrollments en ON en.student_id = u.id
      JOIN exercises ex ON ex.section_id = en.section_id
      WHERE u.role = 'student'
      GROUP BY u.id, u.name
    `);
    console.log(`\n✓ Student access to exercises:`);
    studentExercisesRes.rows.forEach(row => 
      console.log(`  - ${row.name}: ${row.exercises} exercises`)
    );
    
    // Test the actual API query
    console.log('\n🧪 Testing /api/student/exercises query with first student...');
    if (studentExercisesRes.rows.length > 0) {
      const studentId = studentExercisesRes.rows[0].id;
      const testRes = await db.query(`
        SELECT 
          ex.id, ex.title, ex.description, c.name AS concept_name,
          ex.time_limit_minutes, ex.deadline, ex.test_cases,
          CASE 
            WHEN EXISTS(SELECT 1 FROM submissions WHERE exercise_id = ex.id AND student_id = $1 AND passed = true) THEN 'completed'
            WHEN ex.deadline IS NOT NULL AND ex.deadline < NOW() THEN 'locked'
            ELSE 'pending'
          END AS status,
          (SELECT cds FROM submissions WHERE exercise_id = ex.id AND student_id = $1 AND passed = true LIMIT 1) AS cds
        FROM exercises ex
        JOIN concepts c ON c.id = ex.concept_id
        JOIN enrollments en ON en.section_id = ex.section_id
        WHERE en.student_id = $1
        ORDER BY ex.created_at DESC
      `, [studentId]);
      console.log(`✓ Query returned ${testRes.rows.length} exercises for ${studentExercisesRes.rows[0].name}\n`);
      testRes.rows.forEach(ex => {
        console.log(`  Exercise: ${ex.title}`);
        console.log(`    - Status: ${ex.status}`);
        console.log(`    - Concept: ${ex.concept_name}`);
        console.log(`    - Test cases: ${ex.test_cases ? (Array.isArray(ex.test_cases) ? ex.test_cases.length : 'array') : 0}`);
      });
    }
    
    console.log('\n✅ Setup check complete!');
    process.exit(0);
  } catch (e) {
    console.error('❌ ERROR:', e.message);
    console.error(e.stack);
    process.exit(1);
  }
}

check();

#!/usr/bin/env node
require('dotenv').config();
const db = require('./config/db');

async function setup() {
  try {
    // Create section if needed
    let sectionRes = await db.query(
      `SELECT id FROM sections 
       WHERE name='CS 101 - Programming Fundamentals' LIMIT 1`
    );
    
    let sectionId;
    if (sectionRes.rows.length === 0) {
      const instructorRes = await db.query(
        `SELECT id FROM users WHERE role='instructor' LIMIT 1`
      );
      if (instructorRes.rows.length === 0) {
        console.log('No instructors found');
        process.exit(1);
      }
      
      const newSection = await db.query(
        `INSERT INTO sections (name, course_code, instructor_id)
         VALUES ('CS 101 - Programming Fundamentals', 'CS101', $1)
         RETURNING id`,
        [instructorRes.rows[0].id]
      );
      sectionId = newSection.rows[0].id;
      console.log('Section created:', sectionId);
    } else {
      sectionId = sectionRes.rows[0].id;
      console.log('Section found:', sectionId);
    }

    // Enroll students
    await db.query(
      `INSERT INTO enrollments (student_id, section_id)
       SELECT id, $1 FROM users WHERE role='student'
       ON CONFLICT DO NOTHING`,
      [sectionId]
    );
    console.log('Students enrolled');

    // Get data needed
    const sectionDataRes = await db.query(
      `SELECT ex.count, sec.instructor_id 
       FROM (SELECT COUNT(*) as count FROM exercises WHERE section_id=$1) ex,
            (SELECT instructor_id FROM sections WHERE id=$1) sec`,
      [sectionId]
    );
    
    const exerciseCount = sectionDataRes.rows[0].count;
    const instructorId = sectionDataRes.rows[0].instructor_id;
    
    if (exerciseCount > 0) {
      console.log(`${exerciseCount} exercises already exist`);
      process.exit(0);
    }

    // Get concepts
    const conceptsRes = await db.query(
      `SELECT id, name FROM concepts ORDER BY id`
    );
    const concepts = {};
    conceptsRes.rows.forEach(c => {
      concepts[c.name] = c.id;
    });

    const exercises = [
      {
        title: 'Hello, World!',
        desc: 'Write a program that prints "Hello, World!" to the console.',
        concept: 'Datatypes',
        tests: JSON.stringify([{input:'', expected_output:'Hello, World!'}])
      },
      {
        title: 'Add Two Numbers',
        desc: 'Read two integers from input and print their sum.',
        concept: 'Variables',
        tests: JSON.stringify([{input:'5\\n3', expected_output:'8'}, {input:'10\\n20', expected_output:'30'}])
      },
      {
        title: 'Check Even or Odd',
        desc: 'Read a number and print if it is even or odd.',
        concept: 'Conditionals',
        tests: JSON.stringify([{input:'4', expected_output:'Even'}, {input:'7', expected_output:'Odd'}])
      },
      {
        title: 'Sum 1 to N',
        desc: 'Read N and print sum of 1 to N.',
        concept: 'Loops',
        tests: JSON.stringify([{input:'5', expected_output:'15'}, {input:'10', expected_output:'55'}])
      }
    ];

    for (const ex of exercises) {
      const conceptId = concepts[ex.concept];
      if(!conceptId) {
        console.log('Skip exercise - concept not found:', ex.concept);
        continue;
      }
      
      await db.query(
        `INSERT INTO exercises 
         (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
         VALUES ($1, $2, $3, $4, $5, 30, $6)
         ON CONFLICT DO NOTHING`,
        [ex.title, ex.desc, conceptId, sectionId, instructorId, ex.tests]
      );
      console.log('Created:', ex.title);
    }

    console.log('Done!');
    process.exit(0);
  } catch(e) {
    console.error('ERROR:', e.message);
    process.exit(1);
  }
}

setup();

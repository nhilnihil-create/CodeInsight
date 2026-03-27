const db = require('./config/db');

async function setupSampleExercises() {
  try {
    // Get or create section
    const sectionRes = await db.query(
      `SELECT id FROM sections LIMIT 1`
    );
    
    if (sectionRes.rows.length === 0) {
      console.log('❌ No sections found. Creating sample section...');
      const newSection = await db.query(
        `INSERT INTO sections (name, course_code, instructor_id)
         SELECT 'CS 101 - Programming Fundamentals', 'CS101', id 
         FROM users WHERE role='instructor' LIMIT 1
         RETURNING id`
      );
      console.log('✓ Created section:', newSection.rows[0].id);
      sectionId = newSection.rows[0].id;
    } else {
      sectionId = sectionRes.rows[0].id;
    }

    // Get instructor
    const instructorRes = await db.query(
      `SELECT id FROM users WHERE role='instructor' LIMIT 1`
    );
    const instructorId = instructorRes.rows[0].id;

    // Get all students
    const studentsRes = await db.query(
      `SELECT id FROM users WHERE role='student'`
    );
    const studentIds = studentsRes.rows.map(r => r.id);

    // Enroll students if not already enrolled
    for (const studentId of studentIds) {
      await db.query(
        `INSERT INTO enrollments (student_id, section_id)
         VALUES ($1, $2)
         ON CONFLICT DO NOTHING`,
        [studentId, sectionId]
      );
    }
    console.log(`✓ Enrolled ${studentIds.length} students`);

    // Easy exercises
    const exercises = [
      {
        title: 'Hello, World!',
        description: 'Write a program that prints "Hello, World!" to the console.',
        concept: 'Datatypes',
        testCases: [
          { input: '', expected_output: 'Hello, World!' }
        ]
      },
      {
        title: 'Add Two Numbers',
        description: 'Read two integers and print their sum.',
        concept: 'Variables',
        testCases: [
          { input: '5\n3', expected_output: '8' },
          { input: '10\n20', expected_output: '30' }
        ]
      },
      {
        title: 'Check Even or Odd',
        description: 'Read a number and print whether it is even or odd.',
        concept: 'Conditionals',
        testCases: [
          { input: '4', expected_output: 'Even' },
          { input: '7', expected_output: 'Odd' }
        ]
      },
      {
        title: 'Sum of Numbers 1 to N',
        description: 'Read a number N and print the sum of all numbers from 1 to N.',
        concept: 'Loops',
        testCases: [
          { input: '5', expected_output: '15' },
          { input: '10', expected_output: '55' }
        ]
      },
      {
        title: 'Simple Function',
        description: 'Write a function that adds two numbers and use it in main().',
        concept: 'Functions',
        testCases: [
          { input: '3\n4', expected_output: '7' },
          { input: '10\n5', expected_output: '15' }
        ]
      }
    ];

    // Get concept IDs
    for (const exercise of exercises) {
      const conceptRes = await db.query(
        `SELECT id FROM concepts WHERE name = $1`,
        [exercise.concept]
      );
      
      if (conceptRes.rows.length === 0) {
        console.log(`⚠️ Concept "${exercise.concept}" not found`);
        continue;
      }

      const conceptId = conceptRes.rows[0].id;

      // Check if exercise already exists
      const existingRes = await db.query(
        `SELECT id FROM exercises WHERE title = $1 AND section_id = $2`,
        [exercise.title, sectionId]
      );

      if (existingRes.rows.length > 0) {
        console.log(`✓ Exercise "${exercise.title}" already exists`);
      } else {
        const result = await db.query(
          `INSERT INTO exercises 
           (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
           VALUES ($1, $2, $3, $4, $5, 30, $6)
           RETURNING id`,
          [
            exercise.title,
            exercise.description,
            conceptId,
            sectionId,
            instructorId,
            JSON.stringify(exercise.testCases)
          ]
        );
        console.log(`✓ Created exercise: "${exercise.title}" (ID: ${result.rows[0].id})`);
      }
    }

    console.log('\n✓ Setup complete!');
    process.exit(0);
  } catch (err) {
    console.error('❌ Error:', err.message);
    process.exit(1);
  }
}

setupSampleExercises();

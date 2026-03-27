-- Insert sample section
INSERT INTO sections (name, course_code, instructor_id) 
SELECT 'CS 101 - Programming Fundamentals', 'CS101', id 
FROM users WHERE role='instructor' LIMIT 1
ON CONFLICT DO NOTHING;

-- Get section ID and instructor ID for use in exercise inserts
-- We'll use subqueries directly in the INSERT statements

-- Easy Exercise 1: Hello World
INSERT INTO exercises (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
SELECT 
  'Hello, World!',
  'Write a program that prints "Hello, World!" to the console.',
  c.id,
  s.id,
  u.id,
  30,
  '[{"input": "", "expected_output": "Hello, World!"}]'::jsonb
FROM concepts c, sections s, users u
WHERE c.name = 'Datatypes' 
  AND s.name = 'CS 101 - Programming Fundamentals'
  AND u.role = 'instructor'
ON CONFLICT (title, section_id) DO NOTHING;

-- Easy Exercise 2: Add Two Numbers
INSERT INTO exercises (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
SELECT 
  'Add Two Numbers',
  'Read two integers and print their sum.',
  c.id,
  s.id,
  u.id,
  30,
  '[{"input": "5\n3", "expected_output": "8"}, {"input": "10\n20", "expected_output": "30"}]'::jsonb
FROM concepts c, sections s, users u
WHERE c.name = 'Variables' 
  AND s.name = 'CS 101 - Programming Fundamentals'
  AND u.role = 'instructor'
ON CONFLICT (title, section_id) DO NOTHING;

-- Easy Exercise 3: Check Even or Odd
INSERT INTO exercises (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
SELECT 
  'Check Even or Odd',
  'Read a number and print whether it is even or odd.',
  c.id,
  s.id,
  u.id,
  30,
  '[{"input": "4", "expected_output": "Even"}, {"input": "7", "expected_output": "Odd"}]'::jsonb
FROM concepts c, sections s, users u
WHERE c.name = 'Conditionals' 
  AND s.name = 'CS 101 - Programming Fundamentals'
  AND u.role = 'instructor'
ON CONFLICT (title, section_id) DO NOTHING;

-- Easy Exercise 4: Sum 1 to N
INSERT INTO exercises (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
SELECT 
  'Sum of Numbers 1 to N',
  'Read a number N and print the sum of all numbers from 1 to N.',
  c.id,
  s.id,
  u.id,
  30,
  '[{"input": "5", "expected_output": "15"}, {"input": "10", "expected_output": "55"}]'::jsonb
FROM concepts c, sections s, users u
WHERE c.name = 'Loops' 
  AND s.name = 'CS 101 - Programming Fundamentals'
  AND u.role = 'instructor'
ON CONFLICT (title, section_id) DO NOTHING;

-- Easy Exercise 5: Simple Function
INSERT INTO exercises (title, description, concept_id, section_id, created_by, time_limit_minutes, test_cases)
SELECT 
  'Simple Function',
  'Write a function that adds two numbers and use it in main().',
  c.id,
  s.id,
  u.id,
  30,
  '[{"input": "3\n4", "expected_output": "7"}, {"input": "10\n5", "expected_output": "15"}]'::jsonb
FROM concepts c, sections s, users u
WHERE c.name = 'Functions' 
  AND s.name = 'CS 101 - Programming Fundamentals'
  AND u.role = 'instructor'
ON CONFLICT (title, section_id) DO NOTHING;

-- Enroll all students in the section
INSERT INTO enrollments (student_id, section_id)
SELECT u.id, s.id
FROM users u, sections s
WHERE u.role = 'student' 
  AND s.name = 'CS 101 - Programming Fundamentals'
ON CONFLICT DO NOTHING;

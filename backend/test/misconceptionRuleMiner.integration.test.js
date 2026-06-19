const db = require('../config/db');
const { runFullPipeline } = require('../services/misconceptionRuleMiner');

describe('Misconception Rule Mining Integration', () => {
  let exerciseId, conceptId;

  beforeAll(async () => {
    const conceptRes = await db.query(
      `INSERT INTO concepts (name) VALUES ($1)
       ON CONFLICT (name) DO UPDATE SET name = EXCLUDED.name RETURNING id`,
      ['_test_misconception_concept']
    );
    conceptId = conceptRes.rows[0].id;

    const exRes = await db.query(
      `INSERT INTO exercises (title, description, concept_id, test_cases, starter_code, time_limit_minutes)
       VALUES ($1, $2, $3, $4, $5, $6) RETURNING id`,
      ['_test_mining_exercise', 'Test exercise for mining pipeline',
       conceptId, JSON.stringify([{ input: '5', expected: '10', hidden: false }]),
       '#include <iostream>\nint main() { return 0; }', 10]
    );
    exerciseId = exRes.rows[0].id;

    const studentRes = await db.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4)
       ON CONFLICT (email) DO UPDATE SET name = EXCLUDED.name RETURNING id`,
      ['_test_mining_student', '_test_mining_student@test.com', 'hash', 'student']
    );
    const studentId = studentRes.rows[0].id;

    const errorLogs = [
      "[Line 5:5] ERROR: 'max_val' was not declared in this scope",
      "[Line 3:5] ERROR: 'result' was not declared in this scope",
      "[Line 7:5] ERROR: 'temp' was not declared in this scope",
      "[Line 4:5] ERROR: 'sum' was not declared in this scope",
      "[Line 6:5] ERROR: 'avg' was not declared in this scope",
      "[Line 2:5] ERROR: 'count' was not declared in this scope",
    ];

    for (let i = 0; i < errorLogs.length; i++) {
      await db.query(
        `INSERT INTO submissions (student_id, exercise_id, code, compiler_log, test_feedback_hints, is_correct, attempt_number, time_spent_seconds)
         VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
        [studentId, exerciseId, 'int main() { return 0; }', errorLogs[i],
         JSON.stringify([{ input: '5', expected: '10', actual: '', passed: false, status: 'Compile Error', error: errorLogs[i] }]),
         false, 1, 30]
      );
    }

    const studentRes2 = await db.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4)
       ON CONFLICT (email) DO UPDATE SET name = EXCLUDED.name RETURNING id`,
      ['_test_mining_student2', '_test_mining_student2@test.com', 'hash', 'student']
    );
    const studentId2 = studentRes2.rows[0].id;

    await db.query(
      `INSERT INTO submissions (student_id, exercise_id, code, compiler_log, test_feedback_hints, is_correct, attempt_number, time_spent_seconds)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
      [studentId2, exerciseId, 'int main() { return 0; }',
       "[Line 5:5] ERROR: 'value' was not declared in this scope",
       JSON.stringify([{ input: '5', expected: '10', actual: '', passed: false, status: 'Compile Error', error: "'value' was not declared" }]),
       false, 1, 30]
    );

    const studentRes3 = await db.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4)
       ON CONFLICT (email) DO UPDATE SET name = EXCLUDED.name RETURNING id`,
      ['_test_mining_student3', '_test_mining_student3@test.com', 'hash', 'student']
    );
    const studentId3 = studentRes3.rows[0].id;

    await db.query(
      `INSERT INTO submissions (student_id, exercise_id, code, compiler_log, test_feedback_hints, is_correct, attempt_number, time_spent_seconds)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
      [studentId3, exerciseId, 'int main() { int x = 5; return x; }',
       "[Line 3:5] ERROR: expected ';' before 'return'",
       JSON.stringify([{ input: '5', expected: '10', actual: '', passed: false, status: 'Compile Error', error: "expected ';' before 'return'" }]),
       false, 1, 30]
    );
  });

  afterAll(async () => {
    await db.query('DELETE FROM submissions WHERE exercise_id = $1', [exerciseId]);
    await db.query('DELETE FROM exercises WHERE id = $1', [exerciseId]);
    await db.query("DELETE FROM concepts WHERE id = $1", [conceptId]);
    await db.query("DELETE FROM users WHERE email LIKE '_test_mining_%'");
  });

  it('discovers the most frequent remaining error pattern as top candidate', async () => {
    const outputPath = `/tmp/test_candidates_${Date.now()}.json`;
    const result = await runFullPipeline({ exerciseId, outputPath, minStudents: 1, minOccurrences: 1 });

    expect(result.total_submissions_analyzed).toBeGreaterThanOrEqual(8);
    expect(result.candidates.length).toBeGreaterThanOrEqual(1);

    const topCandidate = result.candidates[0];
    expect(topCandidate.confidence).toBeGreaterThanOrEqual(80);
    // The "undeclared identifier" cluster is filtered out by hasExistingRule() because
    // its signature ("was not declared in this scope") matches the var_undeclared rule
    // in the micro-concept taxonomy. Only the "expected ';'" (Syntax Error - Expected Token)
    // cluster survives the filter and becomes the top candidate.
    expect(topCandidate.match_keywords.some(k => k.toLowerCase().includes('expected'))).toBe(true);

    const fs = require('fs');
    const fileContent = JSON.parse(fs.readFileSync(outputPath, 'utf8'));
    expect(fileContent.candidates).toHaveLength(result.candidates.length);
  });
});

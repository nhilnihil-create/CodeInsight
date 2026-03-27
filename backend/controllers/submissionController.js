const db       = require('../config/db');
const executor = require('../services/executor');

// ▶ RUN — local test, does NOT save to database
exports.run = async (req, res) => {
  const { exerciseId, code } = req.body;
  if (!code || !code.trim())
    return res.json({ status: 'Error', error: 'No code provided' });
  try {
    const ex = await db.query(
      'SELECT * FROM exercises WHERE id=$1', [exerciseId]
    );
    if (!ex.rows.length)
      return res.status(404).json({ message: 'Exercise not found' });
    const exercise = ex.rows[0];
    // Run against first visible test case only
    const visibleTC = exercise.test_cases.filter(tc => !tc.hidden);
    if (!visibleTC.length)
      return res.json({ status: 'No visible test cases', output: '' });
    const result = await executor.executeCode(
      code, visibleTC[0].input, exercise.time_limit_minutes * 60
    );
    const passed = result.status === 'Success' &&
                   result.output.trim() === visibleTC[0].expected_output.trim();
    res.json({ ...result, expected: visibleTC[0].expected_output, passed });
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
};

// Submit → — official submission, SAVES to database
exports.submit = async (req, res) => {
  const { exerciseId, code, timeSpentSeconds } = req.body;
  const studentId = req.user.id;
  try {
    const ex = await db.query(
      'SELECT * FROM exercises WHERE id=$1', [exerciseId]
    );
    if (!ex.rows.length)
      return res.status(404).json({ message: 'Exercise not found' });
    const exercise = ex.rows[0];
    if (exercise.closed_at)
      return res.status(400).json({ message: 'Exercise is closed' });

    // Get next attempt number
    const attRes = await db.query(
      'SELECT COALESCE(MAX(attempt_number),0)+1 AS next FROM submissions WHERE student_id=$1 AND exercise_id=$2',
      [studentId, exerciseId]
    );
    const attemptNumber = attRes.rows[0].next;

    // Handle blank submission
    if (!code || !code.trim()) {
      await db.query(
        `INSERT INTO submissions
         (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds)
         VALUES($1,$2,$3,false,$4,$5)`,
        [studentId, exerciseId, code || '', attemptNumber, timeSpentSeconds || 0]
      );
      
      return res.json({
        attemptNumber, allPassed: false,
        results: [], status: 'Blank submission',
        message: 'Blank submission recorded.'
      });
    }

    // Run against ALL test cases
    const tcResults = await executor.runAgainstTestCases(
      code, exercise.test_cases, exercise.time_limit_minutes * 60
    );
    const allPassed = tcResults.every(r => r.passed);

    // Save submission
    await db.query(
      `INSERT INTO submissions
       (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds)
       VALUES($1,$2,$3,$4,$5,$6)`,
      [studentId, exerciseId, code, allPassed, attemptNumber, timeSpentSeconds || 0]
    );

    res.json({ attemptNumber, allPassed, results: tcResults });
  } catch (err) {
    console.error(err);
    res.status(500).json({ message: err.message });
  }
};

// GET my submissions for an exercise
exports.mySubmissions = async (req, res) => {
  try {
    const r = await db.query(
      `SELECT id,attempt_number,is_correct,time_spent_seconds,submitted_at
       FROM submissions
       WHERE student_id=$1 AND exercise_id=$2
       ORDER BY attempt_number ASC`,
      [req.user.id, req.params.exerciseId]
    );
    res.json(r.rows);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
};

// GET instructor view: specific student's submissions for an exercise
exports.studentSubmissions = async (req, res) => {
  try {
    const { studentId, exerciseId } = req.params;
    const r = await db.query(
      `SELECT id,attempt_number,is_correct,time_spent_seconds,submitted_at
       FROM submissions
       WHERE student_id=$1 AND exercise_id=$2
       ORDER BY attempt_number ASC`,
      [studentId, exerciseId]
    );
    res.json(r.rows);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
};

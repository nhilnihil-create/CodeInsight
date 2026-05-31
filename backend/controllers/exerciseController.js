const db = require('../config/db');

// Helper function to get exercise details
const getExerciseDetails = async (id) => {
  try {
    const result = await db.query('SELECT closed_at FROM exercises WHERE id = $1', [id]);
    return result.rows[0];
  } catch (err) {
    console.error('Error getting exercise details:', err);
    return null;
  }
};
const cdsEngine = require('../services/cdsEngine');

exports.getConcepts = async (req, res) => {
  try {
    const r = await db.query('SELECT * FROM concepts ORDER BY id');
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.create = async (req, res) => {
  const { title, description, concept_name, section_id,
          time_limit_minutes, test_cases, deadline, is_draft,
          track_ner, track_nrs, track_nts, auto_alert } = req.body;
  
  if (!title || !description || !concept_name || !section_id || !test_cases)
    return res.status(400).json({ message: 'Missing required fields' });
  if (!Array.isArray(test_cases) || test_cases.length < 2)
    return res.status(400).json({ message: 'At least 2 test cases required' });
  
  try {
    // Get concept_id from concept_name
    const cRes = await db.query('SELECT id FROM concepts WHERE name=$1', [concept_name]);
    if (!cRes.rows.length)
      return res.status(400).json({ message: 'Concept not found' });
    const concept_id = cRes.rows[0].id;

    const r = await db.query(
      `INSERT INTO exercises
       (title, description, concept_id, section_id, created_by, time_limit_minutes,
        test_cases, deadline, is_draft, track_ner, track_nrs, track_nts, auto_alert)
       VALUES($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13) RETURNING *`,
      [title, description, concept_id, section_id, req.user.id,
       time_limit_minutes || 45, JSON.stringify(test_cases), deadline || null,
       is_draft || false, track_ner !== false, track_nrs !== false, 
       track_nts !== false, auto_alert !== false]
    );
    res.status(201).json(r.rows[0]);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.list = async (req, res) => {
  try {
    let r;
    if (req.user.role === 'instructor') {
      r = await db.query(
        `SELECT ex.*, c.name AS concept_name
         FROM exercises ex JOIN concepts c ON c.id=ex.concept_id
         WHERE ex.created_by=$1 ORDER BY ex.created_at DESC`,
        [req.user.id]
      );
    } else {
      r = await db.query(
        `SELECT ex.*, c.name AS concept_name
         FROM exercises ex
         JOIN concepts c ON c.id=ex.concept_id
         JOIN enrollments en ON en.section_id=ex.section_id
         WHERE en.student_id=$1 AND ex.is_draft=false
         ORDER BY ex.created_at DESC`,
        [req.user.id]
      );
    }
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.getOne = async (req, res) => {
  try {
    const r = await db.query(
      `SELECT ex.*, c.name AS concept_name
       FROM exercises ex JOIN concepts c ON c.id=ex.concept_id
       WHERE ex.id=$1`,
      [req.params.id]
    );
    if (!r.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    const ex = r.rows[0];
    if (req.user.role === 'student') {
      ex.test_cases = ex.test_cases.filter(tc => !tc.hidden);
    }
    res.json(ex);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.update = async (req, res) => {
  const { title, description, time_limit_minutes, test_cases, deadline,
          is_draft, track_ner, track_nrs, track_nts, auto_alert } = req.body;
  try {
    const r = await db.query(
      `UPDATE exercises SET
       title=$1, description=$2, time_limit_minutes=$3,
       test_cases=$4, deadline=$5, is_draft=$6, 
       track_ner=$7, track_nrs=$8, track_nts=$9, auto_alert=$10
       WHERE id=$11 AND created_by=$12 RETURNING *`,
      [title, description, time_limit_minutes,
       JSON.stringify(test_cases), deadline, is_draft || false,
       track_ner !== false, track_nrs !== false, track_nts !== false, 
       auto_alert !== false, req.params.id, req.user.id]
    );
    if (!r.rows.length)
      return res.status(404).json({ message: 'Exercise not found or not authorized' });
    res.json(r.rows[0]);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.close = async (req, res) => {
  try {
    const exercise = await getExerciseDetails(req.params.id);
    if (exercise.closed_at) {
      return res.status(400).json({
        message: 'Exercise already closed'
      });
    }
    // ... existing code ...
  }
  try {
    const r = await db.query(
      'UPDATE exercises SET closed_at=NOW() WHERE id=$1 AND created_by=$2 RETURNING *',
      [req.params.id, req.user.id]
    );
    if (!r.rows.length)
      return res.status(404).json({ message: 'Exercise not found or not authorized' });
    // Trigger batch CDS computation
    await cdsJobQueue.enqueueCdsComputation(req.params.id);
    res.json({ message: 'Exercise closed. CDS computed for all students.', exercise: r.rows[0] });
  } catch (err) {
    console.error(err);
    res.status(500).json({ message: err.message });
  }
};

exports.reopen = async (req, res) => {
  try {
    const r = await db.query(
      'UPDATE exercises SET closed_at=NULL WHERE id=$1 AND created_by=$2 RETURNING *',
      [req.params.id, req.user.id]
    );
    if (!r.rows.length)
      return res.status(404).json({ message: 'Exercise not found or not authorized' });
    res.json({ message: 'Exercise reopened.', exercise: r.rows[0] });
  } catch (err) {
    console.error(err);
    res.status(500).json({ message: err.message });
  }
};

exports.remove = async (req, res) => {
  try {
    const r = await db.query(
      'DELETE FROM exercises WHERE id=$1 AND created_by=$2 RETURNING *',
      [req.params.id, req.user.id]
    );
    if (!r.rows.length)
      return res.status(404).json({ message: 'Exercise not found or not authorized' });
    res.json({ message: 'Exercise deleted successfully', exercise: r.rows[0] });
  } catch (err) {
    console.error(err);
    res.status(500).json({ message: err.message });
  }
};

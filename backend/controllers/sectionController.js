const db = require('../config/db');

exports.create = async (req, res) => {
  const { name, course_code, school_year, semester } = req.body;
  if (!name || !course_code)
    return res.status(400).json({ message: 'name and course_code required' });
  try {
    const r = await db.query(
      'INSERT INTO sections(name,course_code,school_year,semester,instructor_id) VALUES($1,$2,$3,$4,$5) RETURNING *',
      [name, course_code, school_year || '', semester || 'Sem 1', req.user.id]
    );
    res.status(201).json(r.rows[0]);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.list = async (req, res) => {
  try {
    let query, params;
    if (req.user.role === 'instructor') {
      query = `SELECT s.*,
        (SELECT COUNT(*) FROM enrollments e WHERE e.section_id=s.id) AS student_count,
        (SELECT COUNT(*) FROM exercises ex WHERE ex.section_id=s.id) AS exercise_count,
        (SELECT COUNT(DISTINCT concept_id) FROM exercises ex WHERE ex.section_id=s.id) AS concept_count,
        (SELECT COUNT(*) FROM alerts al WHERE al.section_id=s.id AND al.is_reviewed=false) AS alert_count,
        (SELECT AVG(cs.cds) FROM cds_scores cs 
         WHERE cs.section_id=s.id) AS avg_cds
        FROM sections s WHERE s.instructor_id=$1 ORDER BY s.created_at DESC`;
      params = [req.user.id];
    } else {
      query = `SELECT s.*,
        (SELECT COUNT(*) FROM enrollments e WHERE e.section_id=s.id) AS student_count
        FROM sections s
        JOIN enrollments en ON en.section_id=s.id
        WHERE en.student_id=$1 ORDER BY s.created_at DESC`;
      params = [req.user.id];
    }
    const r = await db.query(query, params);
    
    // For instructors, enrich data with difficulty distribution
    if (req.user.role === 'instructor') {
      for (let section of r.rows) {
        const diffQuery = `
          SELECT 
            COUNT(CASE WHEN cs.cds <= 0.33 THEN 1 END) AS low_count,
            COUNT(CASE WHEN cs.cds > 0.33 AND cs.cds <= 0.66 THEN 1 END) AS moderate_count,
            COUNT(CASE WHEN cs.cds > 0.66 THEN 1 END) AS high_count
          FROM cds_scores cs WHERE cs.section_id=$1
        `;
        const diffRes = await db.query(diffQuery, [section.id]);
        const diff = diffRes.rows[0] || { low_count: 0, moderate_count: 0, high_count: 0 };
        section.difficulty_distribution = {
          low: parseInt(diff.low_count),
          moderate: parseInt(diff.moderate_count),
          high: parseInt(diff.high_count)
        };
      }
    }
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.getOne = async (req, res) => {
  try {
    const sec = await db.query(
      `SELECT s.*, u.name AS instructor_name,
       (SELECT COUNT(*) FROM enrollments e WHERE e.section_id=s.id) AS student_count,
       (SELECT COUNT(*) FROM exercises ex WHERE ex.section_id=s.id) AS exercise_count,
       (SELECT COUNT(*) FROM (
           SELECT ex.id, (SELECT COUNT(DISTINCT student_id) FROM submissions sub WHERE sub.exercise_id=ex.id AND sub.student_id IN (SELECT student_id FROM enrollments WHERE section_id=s.id)) AS submitted_count,
           (SELECT COUNT(*) FROM enrollments WHERE section_id=s.id) AS total_students
         FROM exercises ex WHERE ex.section_id=s.id
         ) t WHERE t.submitted_count >= t.total_students) AS completed_exercises
       FROM sections s JOIN users u ON u.id=s.instructor_id
       WHERE s.id=$1`, [req.params.id]
    );
    if (!sec.rows.length) return res.status(404).json({ message: 'Section not found' });
    res.json(sec.rows[0]);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.enroll = async (req, res) => {
  const { studentIds, emails } = req.body;
  const sectionId = req.params.id;
  try {
    let ids = studentIds || [];
    if (emails && emails.length) {
      const emailList = emails.map(e => e.trim().toLowerCase());
      const found = await db.query(
        `SELECT id FROM users WHERE LOWER(email) = ANY($1) AND role='student'`,
        [emailList]
      );
      ids = [...ids, ...found.rows.map(r => r.id)];
    }
    if (!ids.length) return res.status(400).json({ message: 'No valid students found' });
    let enrolled = 0;
    for (const sid of ids) {
      await db.query(
        'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT (student_id, section_id) DO NOTHING;',
        [sid, sectionId]
      );
      enrolled++;
    }
    res.json({ message: `${enrolled} student(s) enrolled` });
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.unenroll = async (req, res) => {
  try {
    await db.query(
      'DELETE FROM enrollments WHERE student_id=$1 AND section_id=$2',
      [req.params.studentId, req.params.id]
    );
    res.json({ message: 'Student removed from section' });
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.getStudents = async (req, res) => {
  try {
    const r = await db.query(
      `SELECT u.id, u.name, u.email, e.enrolled_at
       FROM users u JOIN enrollments e ON e.student_id=u.id
       WHERE e.section_id=$1 ORDER BY u.name`,
      [req.params.id]
    );
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

// Get students with their latest CDS scores and submission counts
exports.getStudentsWithScores = async (req, res) => {
  try {
    const { section_id } = req.params;
    const r = await db.query(
      `SELECT 
        u.id, u.name, u.email,
        (SELECT MAX(cds) FROM cds_scores cs WHERE cs.student_id=u.id AND cs.section_id=$1) AS latest_cds,
        (SELECT COUNT(*) FROM submissions sub WHERE sub.student_id=u.id 
         AND sub.exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)) AS submitted_count,
        (SELECT COUNT(*) FROM exercises WHERE section_id=$1) AS total_exercises
       FROM users u JOIN enrollments e ON e.student_id=u.id
       WHERE e.section_id=$1 ORDER BY u.name`,
      [section_id]
    );
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

// Get exercises for a section with stats
exports.getSectionExercises = async (req, res) => {
  try {
    const { section_id } = req.params;
    const r = await db.query(
      `SELECT 
        ex.id, ex.title, ex.description, ex.concept_id, ex.section_id,
        ex.closed_at, ex.created_at, c.name AS concept_name,
        (SELECT COUNT(*)::INTEGER FROM enrollments WHERE section_id=$1) AS total_students,
        (SELECT COUNT(DISTINCT student_id)::INTEGER FROM submissions 
         WHERE exercise_id=ex.id AND student_id IN 
           (SELECT student_id FROM enrollments WHERE section_id=$1)) AS submitted_count,
        (SELECT AVG(cs.cds) FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS avg_cds,
        (SELECT COUNT(CASE WHEN cs.cds <= 0.33 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS low_count,
        (SELECT COUNT(CASE WHEN cs.cds > 0.33 AND cs.cds <= 0.66 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS moderate_count,
        (SELECT COUNT(CASE WHEN cs.cds > 0.66 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS high_count
       FROM exercises ex
       JOIN concepts c ON c.id=ex.concept_id
       WHERE ex.section_id=$1
       ORDER BY ex.created_at DESC`,
      [section_id]
    );
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

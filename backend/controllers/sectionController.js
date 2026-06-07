const db = require('../config/db');

async function writeAuditLog(sectionId, actorId, action, meta = {}) {
  await db.query(
    `INSERT INTO section_audit_log (section_id, actor_id, action, meta) VALUES ($1, $2, $3, $4)`,
    [sectionId, actorId, action, JSON.stringify(meta)]
  );
}

function generateCode() {
  const chars = 'ABCDEFGHJKLMNPQRSTUVWXYZ23456789';
  let code = '';
  for (let i = 0; i < 6; i++) {
    if (i === 3) code += '-';
    code += chars[Math.floor(Math.random() * chars.length)];
  }
  return code;
}

exports.create = async (req, res) => {
  const { name, course_code, school_year, semester } = req.body;
  if (!name || !course_code)
    return res.status(400).json({ message: 'name and course_code required' });
  try {
    const r = await db.query(
      'INSERT INTO sections(name,course_code,school_year,semester,instructor_id,code,join_policy) VALUES($1,$2,$3,$4,$5,$6,$7) RETURNING *',
      [name, course_code, school_year || '', semester || 'Sem 1', req.user.id, generateCode(), 'code']
    );
    await writeAuditLog(r.rows[0].id, req.user.id, 'section_created', { name, course_code });
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
            COUNT(CASE WHEN cs.cds <= 0.31 THEN 1 END) AS low_count,
            COUNT(CASE WHEN cs.cds > 0.31 AND cs.cds <= 0.50 THEN 1 END) AS moderate_count,
            COUNT(CASE WHEN cs.cds > 0.50 THEN 1 END) AS high_count
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
        (SELECT COUNT(CASE WHEN cs.cds <= 0.31 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS low_count,
        (SELECT COUNT(CASE WHEN cs.cds > 0.31 AND cs.cds <= 0.50 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS moderate_count,
        (SELECT COUNT(CASE WHEN cs.cds > 0.50 THEN 1 END)::INTEGER FROM cds_scores cs 
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

// ── New section management endpoints (spec §11.6) ─────────────────────────

exports.rotateCode = async (req, res) => {
  const { id } = req.params;
  try {
    const newCode = generateCode();
    const r = await db.query('UPDATE sections SET code=$1 WHERE id=$2 RETURNING *', [newCode, id]);
    if (!r.rows.length) return res.status(404).json({ error: 'Section not found' });
    await writeAuditLog(id, req.user.id, 'code_rotated', { code: newCode });
    res.json(r.rows[0]);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.joinSection = async (req, res) => {
  const { code } = req.body;
  if (!code) return res.status(400).json({ error: 'Code required' });
  try {
    // Spec §11.8: race conditions on capacity are resolved by SELECT ... FOR UPDATE
    // on the section row inside the join transaction. This serializes concurrent
    // joins at the max_size boundary; the first wins, the second sees the
    // post-increment count and is rejected with "Section is full."
    await db.query('BEGIN');
    const sec = await db.query(
      'SELECT * FROM sections WHERE code=$1 FOR UPDATE',
      [code.toUpperCase()]
    );
    if (!sec.rows.length) {
      await db.query('ROLLBACK');
      return res.status(404).json({ error: 'Invalid code' });
    }
    const section = sec.rows[0];
    if (section.join_policy === 'closed') {
      await db.query('ROLLBACK');
      return res.status(403).json({ error: 'Section is closed to new join requests' });
    }

    // Re-check max_size under the lock (defense: race-join at the cap).
    if (section.max_size) {
      const cnt = await db.query(
        'SELECT COUNT(*)::int AS n FROM enrollments WHERE section_id=$1',
        [section.id]
      );
      if (cnt.rows[0].n >= section.max_size) {
        await db.query('ROLLBACK');
        return res.status(403).json({ error: 'Section is full' });
      }
    }

    const existing = await db.query(
      'SELECT * FROM enrollments WHERE student_id=$1 AND section_id=$2',
      [req.user.id, section.id]
    );
    if (existing.rows.length) {
      await db.query('ROLLBACK');
      return res.status(409).json({ error: 'Already enrolled' });
    }

    if (section.join_policy === 'code') {
      await db.query(
        'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2)',
        [req.user.id, section.id]
      );
      await writeAuditLog(section.id, req.user.id, 'student_joined', { code });
      await db.query('COMMIT');
      return res.json({ message: 'Joined section', section });
    }

    await db.query(
      'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING',
      [req.user.id, section.id]
    );
    await writeAuditLog(section.id, req.user.id, 'student_requested_to_join', { code });
    await db.query('COMMIT');
    res.json({ message: 'Join request submitted' });
  } catch (err) {
    try { await db.query('ROLLBACK'); } catch (_) {}
    res.status(500).json({ message: err.message });
  }
};

exports.addMembership = async (req, res) => {
  const { id } = req.params;
  const { userId, role } = req.body;
  try {
    const r = await db.query(
      'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING RETURNING *',
      [userId, id]
    );
    await writeAuditLog(id, req.user.id, 'student_joined', { userId, role: role || 'student' });
    res.status(201).json(r.rows[0] || { message: 'Already enrolled' });
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.updateMembership = async (req, res) => {
  const { id, mid } = req.params;
  const { status, dropReason } = req.body;
  try {
    if (status === 'dropped') {
      // Spec §11.4: "Reason required? Yes — short note (e.g., 'transferred to BSIT-1B
      // per registrar')." Defense artifact: the drop reason is written to the audit
      // log so the trail is intact.
      const reason = (dropReason || '').trim();
      if (!reason) {
        return res.status(400).json({ error: 'dropReason is required to drop a student' });
      }
      await db.query('DELETE FROM enrollments WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await writeAuditLog(id, req.user.id, 'student_dropped', { studentId: mid, reason });
      return res.json({ message: 'Student dropped' });
    }
    res.json({ message: 'Membership updated' });
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.bulkImport = async (req, res) => {
  const { id } = req.params;
  const { emails } = req.body;
  if (!emails || !emails.length) return res.status(400).json({ error: 'Emails array required' });
  try {
    const found = await db.query(
      `SELECT id, email FROM users WHERE LOWER(email) = ANY($1) AND role='student'`,
      [emails.map(e => e.trim().toLowerCase())]
    );
    let enrolled = 0;
    for (const user of found.rows) {
      await db.query('INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING', [user.id, id]);
      enrolled++;
    }
    await writeAuditLog(id, req.user.id, 'bulk_import_run', { count: enrolled, total: emails.length });
    res.json({ message: `${enrolled} of ${emails.length} students enrolled` });
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.getAuditLog = async (req, res) => {
  const { id } = req.params;
  try {
    const r = await db.query(
      `SELECT al.*, u.name AS actor_name FROM section_audit_log al
       LEFT JOIN users u ON u.id = al.actor_id
       WHERE al.section_id = $1 ORDER BY al.created_at DESC LIMIT 100`,
      [id]
    );
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.getDeptAudit = async (req, res) => {
  try {
    const r = await db.query(
      `SELECT al.*, u.name AS actor_name, s.name AS section_name FROM section_audit_log al
       LEFT JOIN users u ON u.id = al.actor_id
       JOIN sections s ON s.id = al.section_id
       ORDER BY al.created_at DESC LIMIT 200`
    );
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.updatePolicy = async (req, res) => {
  const { id } = req.params;
  const { join_policy } = req.body;
  if (!['code', 'request', 'closed'].includes(join_policy)) {
    return res.status(400).json({ error: 'Invalid policy. Use code, request, or closed.' });
  }
  try {
    const r = await db.query('UPDATE sections SET join_policy=$1 WHERE id=$2 RETURNING *', [join_policy, id]);
    await writeAuditLog(id, req.user.id, 'policy_changed', { from: r.rows[0].join_policy, to: join_policy });
    res.json(r.rows[0]);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

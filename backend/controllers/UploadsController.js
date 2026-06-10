const db = require('../config/db');
const { parseAndValidate } = require('../services/fileParser');
const bcrypt = require('bcryptjs');
const crypto = require('crypto');
const ExcelJS = require('exceljs');

const DEFAULT_PASSWORD = 'password123'; // matches existing seed data default

/**
 * Generate a unique email for auto-created students.
 * Format: student_<hash>@student.psu.edu
 */
function generateStudentEmail(name) {
  const hash = crypto.createHash('md5').update(name + Date.now()).digest('hex').substring(0, 8);
  return `student_${hash}@student.psu.edu`;
}

/**
 * POST /api/uploads/import-roster/:id
 *
 * Accepts a .csv or .xlsx file upload, parses it, validates every row,
 * and performs a transactional upsert of users + enrollments.
 *
 * If ANY row fails, the entire transaction is rolled back and a
 * granular error array is returned (no partial state).
 */
exports.importRoster = async (req, res, next) => {
  const sectionId = req.params.id;
  const createMissingUsers = req.body.createMissingUsers === 'true' || req.body.createMissingUsers === true;
  const file = req.file;

  if (!file) {
    return res.status(400).json({ error: 'No file uploaded. Attach a .csv or .xlsx file as "file".' });
  }

  // Parse and validate
  try {
    const { validRows, errors } = await parseAndValidate(file.buffer, file.originalname);

    // If there are validation errors, reject the entire upload
    if (errors.length > 0) {
      return res.status(422).json({
        error: `${errors.length} validation error(s) found in the uploaded file. No data was imported.`,
        errors: errors.map(e => ({
          row: e.row,
          field: e.field,
          message: e.message,
          value: e.value,
        })),
      });
    }

    if (validRows.length === 0) {
      return res.status(400).json({ error: 'No valid data rows found in the file.' });
    }

    // Execute transactional import
    const result = await db.withTransaction(async (client) => {
      // 1. Look up existing students by email
      const emails = validRows.map(r => r.email);
      const existingRes = await client.query(
        `SELECT id, email, name FROM users WHERE LOWER(email) = ANY($1) AND role = 'student'`,
        [emails]
      );
      const existingMap = new Map(); // email -> { id, name }
      for (const u of existingRes.rows) {
        existingMap.set(u.email.toLowerCase(), { id: u.id, name: u.name });
      }

      // 2. Create missing users if flag is set
      const missingRows = validRows.filter(r => !existingMap.has(r.email));
      if (missingRows.length > 0 && !createMissingUsers) {
        // Return missing emails so the frontend can prompt the user
        return {
          created: 0,
          enrolled: 0,
          missing: missingRows.map(r => ({ email: r.email, name: r.name })),
          message: `${missingRows.length} student(s) not found. Enable "Create missing users" to auto-create accounts.`,
        };
      }

      if (missingRows.length > 0) {
        const passwordHash = await bcrypt.hash(DEFAULT_PASSWORD, 10);
        for (const row of missingRows) {
          await client.query(
            `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, 'student') ON CONFLICT (email) DO NOTHING`,
            [row.name, row.email, passwordHash]
          );
        }
        // Build a name lookup from the missing rows
        const nameMap = new Map();
        for (const r of missingRows) {
          nameMap.set(r.email.toLowerCase(), r.name);
        }
        // Re-fetch to get IDs for newly created users
        const newIdsRes = await client.query(
          `SELECT id, email FROM users WHERE LOWER(email) = ANY($1) AND role = 'student'`,
          [missingRows.map(r => r.email)]
        );
        for (const u of newIdsRes.rows) {
          existingMap.set(u.email.toLowerCase(), { id: u.id, name: nameMap.get(u.email.toLowerCase()) });
        }
      }

      // 3. Enroll all students
      let enrolled = 0;
      for (const row of validRows) {
        const existing = existingMap.get(row.email);
        if (existing) {
          await client.query(
            `INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2) ON CONFLICT (student_id, section_id) DO NOTHING`,
            [existing.id, sectionId]
          );
          enrolled++;
        }
      }

      return {
        created: missingRows.length,
        enrolled,
        missing: [],
        message: `${enrolled} student(s) enrolled${missingRows.length ? `, ${missingRows.length} new account(s) created` : ''}.`,
      };
    });

    return res.json(result);
  } catch (err) {
    // Parse-level errors (file format, no data, etc.)
    if (err.message && (err.message.includes('CSV') || err.message.includes('sheet') || err.message.includes('file') || err.message.includes('Unsupported') || err.message.includes('Could not detect'))) {
      return res.status(400).json({ error: err.message });
    }
    next(err);
  }
};

/**
 * POST /api/uploads/import-exercises/:sectionId
 *
 * Placeholder for future exercise import via CSV/XLSX.
 */
exports.importExercises = async (req, res, next) => {
  return res.status(501).json({ message: 'Exercise import is not yet implemented.' });
};

/**
 * GET /api/sections/:id/export
 *
 * Generates a rich .xlsx workbook with multiple sheets:
 *   Sheet 1 "Roster"  — enrolled students (name, email, enrolled_at)
 *   Sheet 2 "CDS Scores" — per-student CDS breakdown (avg, classification, flags)
 *   Sheet 3 "Exercise Summary" — per-exercise stats for the section
 *
 * Returns the file as a streamed download.
 */
exports.exportRoster = async (req, res, next) => {
  const sectionId = req.params.id;

  try {
    // 1. Fetch section metadata
    const secRes = await db.query(
      `SELECT s.id, s.name, s.course_code, s.school_year, s.semester, u.name AS instructor_name
       FROM sections s JOIN users u ON u.id = s.instructor_id WHERE s.id = $1`,
      [sectionId]
    );
    if (!secRes.rows.length) {
      return res.status(404).json({ error: 'Section not found.' });
    }
    const section = secRes.rows[0];

    // 2. Fetch enrolled students with CDS aggregates
    const studentsRes = await db.query(
      `SELECT u.id, u.name, u.email, e.enrolled_at,
         (SELECT AVG(cs.cds)::float FROM cds_scores cs
          WHERE cs.student_id = u.id AND cs.section_id = $1) AS avg_cds,
         (SELECT COUNT(*) FROM submissions sub
          WHERE sub.student_id = u.id
          AND sub.exercise_id IN (SELECT id FROM exercises WHERE section_id = $1)) AS submission_count,
         (SELECT COUNT(*)::int FROM integrity_flags if2
          WHERE if2.student_id = u.id AND if2.section_id = $1 AND if2.status = 'flagged') AS flag_count,
         (SELECT MAX(cs.classification) FROM cds_scores cs
          WHERE cs.student_id = u.id AND cs.section_id = $1) AS latest_classification
       FROM users u JOIN enrollments e ON e.student_id = u.id
       WHERE e.section_id = $1
       ORDER BY u.name`,
      [sectionId]
    );

    // 3. Fetch exercise stats for the section
    const exercisesRes = await db.query(
      `SELECT ex.id, ex.title, c.name AS concept_name, ex.deadline,
         (SELECT COUNT(DISTINCT student_id)::int FROM submissions
          WHERE exercise_id = ex.id AND student_id IN (SELECT student_id FROM enrollments WHERE section_id = $1)) AS submitted_count,
         (SELECT COUNT(*)::int FROM enrollments WHERE section_id = $1) AS total_students,
         (SELECT AVG(cs.cds)::float FROM cds_scores cs WHERE cs.exercise_id = ex.id AND cs.section_id = $1) AS avg_cds
       FROM exercises ex
       JOIN concepts c ON c.id = ex.concept_id
       WHERE ex.section_id = $1
       ORDER BY ex.created_at DESC`,
      [sectionId]
    );

    // 4. Build workbook
    const workbook = new ExcelJS.Workbook();
    workbook.creator = 'CodeInsight';
    workbook.created = new Date();
    workbook.properties.company = 'CodeInsight';

    // ── Sheet 1: Roster ─────────────────────────────────────────────────
    const rosterWs = workbook.addWorksheet('Roster', {
      properties: { tabColor: { argb: 'FF4472C4' } },
    });

    // Header styling
    const headerStyle = {
      font: { bold: true, color: { argb: 'FFFFFFFF' }, size: 11 },
      fill: { type: 'pattern', pattern: 'solid', fgColor: { argb: 'FF4472C4' } },
      alignment: { vertical: 'middle' },
    };

    // Section metadata as header rows
    rosterWs.addRow(['Section:', section.name]).eachCell((cell) => { cell.font = { bold: true, size: 12 }; });
    rosterWs.addRow(['Course:', section.course_code]);
    rosterWs.addRow(['Instructor:', section.instructor_name]);
    rosterWs.addRow([]); // spacer

    const rosterHeader = rosterWs.addRow(['#', 'Student Name', 'Email', 'Enrolled At', 'Avg CDS', 'Submissions', 'Integrity Flags', 'Latest Classification']);
    rosterHeader.eachCell((cell) => { Object.assign(cell, headerStyle); });

    for (const [i, s] of studentsRes.rows.entries()) {
      const row = rosterWs.addRow([
        i + 1,
        s.name,
        s.email,
        s.enrolled_at ? new Date(s.enrolled_at) : '',
        s.avg_cds !== null ? Math.round(parseFloat(s.avg_cds) * 10000) / 10000 : 'N/A',
        parseInt(s.submission_count) || 0,
        parseInt(s.flag_count) || 0,
        s.latest_classification || 'Unscored',
      ]);
      // Highlight high-risk rows (CDS > 0.5)
      const cdsVal = parseFloat(s.avg_cds);
      if (cdsVal > 0.5) {
        row.eachCell((cell) => {
          cell.fill = { type: 'pattern', pattern: 'solid', fgColor: { argb: 'FFFFC7CE' } };
        });
      }
    }

    // Auto-size columns
    rosterWs.columns.forEach((col, idx) => {
      let maxLen = 10;
      col.eachCell({ includeEmpty: false }, (cell) => {
        const len = String(cell.value).length;
        if (len > maxLen) maxLen = len;
      });
      col.width = Math.min(maxLen + 2, 40);
    });

    // ── Sheet 2: CDS Scores Detail ──────────────────────────────────────
    const cdsWs = workbook.addWorksheet('CDS Scores', {
      properties: { tabColor: { argb: 'FF70AD47' } },
    });

    const cdsHeader = cdsWs.addRow(['Student Name', 'Email', 'Exercise Title', 'CDS', 'NER', 'NRS', 'NTS', 'Classification', 'Source', 'Computed At']);
    cdsHeader.eachCell((cell) => { Object.assign(cell, headerStyle); });

    const cdsRes = await db.query(
      `SELECT u.name, u.email, ex.title AS exercise_title,
         cs.cds, cs.ner, cs.nrs, cs.nts, cs.classification, cs.source, cs.computed_at
       FROM cds_scores cs
       JOIN users u ON u.id = cs.student_id
       JOIN exercises ex ON ex.id = cs.exercise_id
       WHERE cs.section_id = $1 AND cs.visible = true
       ORDER BY cs.cds DESC`,
      [sectionId]
    );

    for (const cs of cdsRes.rows) {
      cdsWs.addRow([
        cs.name,
        cs.email,
        cs.exercise_title,
        parseFloat(cs.cds || 0).toFixed(4),
        parseFloat(cs.ner || 0).toFixed(4),
        parseFloat(cs.nrs || 0).toFixed(4),
        parseFloat(cs.nts || 0).toFixed(4),
        cs.classification,
        cs.source,
        cs.computed_at ? new Date(cs.computed_at) : '',
      ]);
    }

    cdsWs.columns.forEach((col) => {
      let maxLen = 10;
      col.eachCell({ includeEmpty: false }, (cell) => {
        const len = String(cell.value).length;
        if (len > maxLen) maxLen = len;
      });
      col.width = Math.min(maxLen + 2, 35);
    });

    // ── Sheet 3: Exercise Summary ───────────────────────────────────────
    const exWs = workbook.addWorksheet('Exercise Summary', {
      properties: { tabColor: { argb: 'FFFFC000' } },
    });

    const exHeader = exWs.addRow(['#', 'Exercise Title', 'Concept', 'Deadline', 'Submitted', 'Total Students', 'Submission Rate', 'Avg CDS']);
    exHeader.eachCell((cell) => { Object.assign(cell, headerStyle); });

    for (const [i, ex] of exercisesRes.rows.entries()) {
      const rate = parseInt(ex.total_students) > 0
        ? Math.round((parseInt(ex.submitted_count) / parseInt(ex.total_students)) * 100) + '%'
        : '0%';
      exWs.addRow([
        i + 1,
        ex.title,
        ex.concept_name,
        ex.deadline ? new Date(ex.deadline) : 'No deadline',
        parseInt(ex.submitted_count) || 0,
        parseInt(ex.total_students) || 0,
        rate,
        ex.avg_cds !== null ? Math.round(parseFloat(ex.avg_cds) * 100) / 100 : 'N/A',
      ]);
    }

    exWs.columns.forEach((col) => {
      let maxLen = 10;
      col.eachCell({ includeEmpty: false }, (cell) => {
        const len = String(cell.value).length;
        if (len > maxLen) maxLen = len;
      });
      col.width = Math.min(maxLen + 2, 30);
    });

    // 5. Stream to response
    const fileName = `roster-${section.course_code}-${section.name.replace(/\s+/g, '-')}-${new Date().toISOString().split('T')[0]}.xlsx`;
    res.setHeader('Content-Type', 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
    res.setHeader('Content-Disposition', `attachment; filename="${encodeURIComponent(fileName)}"`);

    await workbook.xlsx.write(res);
    res.end();
  } catch (err) {
    next(err);
  }
};

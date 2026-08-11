const fs = require('fs');
const path = require('path');
const db = require('../config/db');
const logger = require('../lib/logger');
const exportService = require('../services/exportService');

/**
 * UploadsController — file-based roster import and export.
 * Supports .csv and .xlsx uploads via multer.
 * Used by routes: POST /:id/bulk-import, GET /:id/export
 */

// ── Import Roster (CSV/XLSX) ──────────────────────────────────────────────
exports.importRoster = async (req, res) => {
  try {
    const sectionId = req.params.id;
    const file = req.file;
    if (!file) return res.status(400).json({ error: 'No file uploaded' });

    let rows = [];
    const ext = path.extname(file.originalname).toLowerCase();

    if (ext === '.csv') {
      const { parse } = require('csv-parse/sync');
      rows = parse(file.buffer.toString('utf-8'), { columns: true, skip_empty_lines: true });
    } else if (ext === '.xlsx') {
      const ExcelJS = require('exceljs');
      const workbook = new ExcelJS.Workbook();
      await workbook.xlsx.load(file.buffer);
      const worksheet = workbook.getWorksheet(1);
      if (!worksheet) return res.status(400).json({ error: 'Empty spreadsheet' });
      const headers = worksheet.getRow(1).values.slice(1);
      worksheet.eachRow({ includeEmpty: false }, (row, rowNumber) => {
        if (rowNumber === 1) return;
        const obj = {};
        headers.forEach((h, i) => { obj[h] = row.values[i + 1] || ''; });
        rows.push(obj);
      });
    } else {
      return res.status(400).json({ error: `Unsupported file type: ${ext}` });
    }

    if (!rows.length) return res.status(400).json({ error: 'No data rows found' });

    // Accept common column names: name/email, Name/Email, student_name/student_email
    const enrolled = [];
    const errors = [];

    for (let i = 0; i < rows.length; i++) {
      const row = rows[i];
      const name = row.name || row.Name || row.student_name || row['Student Name'] || '';
      const email = row.email || row.Email || row.student_email || row['Student Email'] || '';

      if (!email) { errors.push({ row: i + 2, error: 'Missing email' }); continue; }

      try {
        // Check if user exists
        let userRes = await db.query('SELECT id FROM users WHERE email = $1', [email.trim()]);
        let userId;

        if (userRes.rows.length === 0) {
          // Create student account
          const bcrypt = require('bcryptjs');
          const hash = await bcrypt.hash('password123', 10);
          const newUser = await db.query(
            'INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4) RETURNING id',
            [name.trim() || email.split('@')[0], email.trim(), hash, 'student']
          );
          userId = newUser.rows[0].id;
        } else {
          userId = userRes.rows[0].id;
        }

        // Enroll in section
        await db.query(
          'INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2) ON CONFLICT DO NOTHING',
          [userId, sectionId]
        );
        enrolled.push({ name: name.trim(), email: email.trim() });
      } catch (err) {
        errors.push({ row: i + 2, error: err.message });
      }
    }

    res.json({
      message: `Imported ${enrolled.length} students (${errors.length} errors)`,
      enrolled,
      errors,
    });
  } catch (err) {
    logger.error({ err }, 'Import roster failed');
    res.status(500).json({ error: 'Import failed' });
  }
};

// ── Export Roster (XLSX) ──────────────────────────────────────────────────
exports.exportRoster = async (req, res, next) => {
  try {
    const sectionId = req.params.id;
    await exportService.assertInstructorOwnsSection(sectionId, req.user.id);

    const { buffer, mimeType, filename } = await exportService.formatExport('roster', sectionId, 'xlsx');
    exportService.setDownloadHeaders(res, filename, mimeType);
    res.send(buffer);
  } catch (err) {
    logger.error({ err }, 'Export roster failed');
    next(err);
  }
};

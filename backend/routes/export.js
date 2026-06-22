const express = require('express');
const router = express.Router();
const db = require('../config/db');
const logger = require('../lib/logger');
const { verifyToken, requireRole } = require('../middleware/auth');

// Export section data as CSV/XLSX
router.get('/section/:sectionId', verifyToken, requireRole('instructor'), async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const format = req.query.format || 'csv';

    // Get section info with enrollments and submissions
    const data = await db.query(
      `SELECT u.name, u.email, e.exercise_id, ex.title, s.attempt_number, s.passed, s.cds, s.created_at
       FROM enrollments en
       JOIN users u ON u.id = en.student_id
       LEFT JOIN submissions s ON s.student_id = u.id
       LEFT JOIN exercises ex ON ex.id = s.exercise_id
       WHERE en.section_id = $1
       ORDER BY u.name, s.created_at`,
      [sectionId]
    );

    if (format === 'xlsx') {
      const ExcelJS = require('exceljs');
      const workbook = new ExcelJS.Workbook();
      const worksheet = workbook.addWorksheet('Section Data');
      worksheet.columns = [
        { header: 'Student Name', key: 'name', width: 25 },
        { header: 'Email', key: 'email', width: 35 },
        { header: 'Exercise', key: 'title', width: 30 },
        { header: 'Attempt', key: 'attempt_number', width: 10 },
        { header: 'Passed', key: 'passed', width: 10 },
        { header: 'CDS', key: 'cds', width: 10 },
        { header: 'Submitted', key: 'created_at', width: 20 },
      ];
      data.rows.forEach(row => {
        worksheet.addRow({
          name: row.name,
          email: row.email,
          title: row.title || '',
          attempt_number: row.attempt_number || '',
          passed: row.passed !== null ? (row.passed ? 'Yes' : 'No') : '',
          cds: row.cds !== null ? (parseFloat(row.cds) * 100).toFixed(1) + '%' : '',
          created_at: row.created_at ? new Date(row.created_at).toLocaleDateString() : '',
        });
      });
      const buffer = await workbook.xlsx.writeBuffer();
      res.setHeader('Content-Type', 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
      res.setHeader('Content-Disposition', `attachment; filename="section-${sectionId}-export.xlsx"`);
      return res.send(buffer);
    }

    // Default CSV
    res.setHeader('Content-Type', 'text/csv');
    res.setHeader('Content-Disposition', `attachment; filename="section-${sectionId}-export.csv"`);
    res.write('Name,Email,Exercise,Attempt,Passed,CDS,Submitted\n');
    data.rows.forEach(row => {
      const csv = [
        `"${(row.name || '').replace(/"/g, '""')}"`,
        `"${(row.email || '').replace(/"/g, '""')}"`,
        `"${(row.title || '').replace(/"/g, '""')}"`,
        row.attempt_number || '',
        row.passed !== null ? (row.passed ? 'Yes' : 'No') : '',
        row.cds !== null ? (parseFloat(row.cds) * 100).toFixed(1) + '%' : '',
        row.created_at ? new Date(row.created_at).toLocaleDateString() : '',
      ].join(',');
      res.write(csv + '\n');
    });
    res.end();
  } catch (err) {
    logger.error({ err }, 'Export failed');
    next(err);
  }
});

module.exports = router;

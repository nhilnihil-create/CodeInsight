const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

async function submitResponse(req, res, next) {
  try {
    const { respondentId, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedbackText } = req.body;
    const likerts = [fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3];
    if (likerts.some((v) => v == null || v < 1 || v > 4)) {
      throw new AppError('All Likert fields must be in range 1-4', 400, codes.VALIDATION);
    }
    // Default to the logged-in user
    const finalRespondentId = respondentId || req.user.id;
    const finalRole = role || req.user.role;

    const result = await db.query(
      `INSERT INTO evaluation_responses
       (respondent_id, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedback_text)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15)
       RETURNING id`,
      [finalRespondentId, finalRole, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedbackText || null]
    );
    res.status(201).json({ id: result.rows[0].id, message: 'Evaluation submitted' });
  } catch (err) { next(err); }
}

async function exportResponses(req, res, next) {
  try {
    const result = await db.query('SELECT * FROM evaluation_responses ORDER BY created_at DESC');
    const headers = ['id', 'respondent_id', 'role', 'fs_1', 'fs_2', 'fs_3', 'fs_4',
      'us_1', 'us_2', 'us_3', 'us_4', 'us_5', 'pe_1', 'pe_2', 'pe_3', 'feedback_text', 'created_at'];
    const csvRows = [headers.join(',')];
    for (const row of result.rows) {
      csvRows.push(headers.map((h) => {
        const v = row[h];
        if (v == null) return '';
        if (typeof v === 'string' && v.includes(',')) return `"${v}"`;
        return v;
      }).join(','));
    }
    res.setHeader('Content-Type', 'text/csv');
    res.setHeader('Content-Disposition', 'attachment; filename=evaluation-responses.csv');
    res.send(csvRows.join('\n'));
  } catch (err) { next(err); }
}

module.exports = { submitResponse, exportResponses };

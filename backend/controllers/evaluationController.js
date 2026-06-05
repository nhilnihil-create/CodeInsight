const db = require('../config/db');

async function submitResponse(req, res) {
  const { respondentId, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedbackText } = req.body;
  const likerts = [fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3];
  if (likerts.some(v => v == null || v < 1 || v > 4)) {
    return res.status(400).json({ error: 'All Likert fields must be 1-4' });
  }
  try {
    const result = await db.query(
      `INSERT INTO evaluation_responses
       (respondent_id, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedback_text)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15)
       RETURNING id`,
      [respondentId, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedbackText || null]
    );
    res.status(201).json({ id: result.rows[0].id, message: 'Evaluation submitted' });
  } catch (err) {
    console.error('submitResponse error:', err);
    res.status(500).json({ error: 'Failed to submit evaluation' });
  }
}

async function exportResponses(req, res) {
  if (req.user.role !== 'admin') return res.status(403).json({ error: 'Admin only' });
  try {
    const result = await db.query('SELECT * FROM evaluation_responses ORDER BY created_at DESC');
    const headers = ['id', 'respondent_id', 'role', 'fs_1', 'fs_2', 'fs_3', 'fs_4',
      'us_1', 'us_2', 'us_3', 'us_4', 'us_5', 'pe_1', 'pe_2', 'pe_3', 'feedback_text', 'created_at'];
    const csvRows = [headers.join(',')];
    for (const row of result.rows) {
      csvRows.push(headers.map(h => {
        const v = row[h];
        if (v == null) return '';
        if (typeof v === 'string' && v.includes(',')) return `"${v}"`;
        return v;
      }).join(','));
    }
    res.setHeader('Content-Type', 'text/csv');
    res.setHeader('Content-Disposition', 'attachment; filename=evaluation-responses.csv');
    res.send(csvRows.join('\n'));
  } catch (err) {
    console.error('exportResponses error:', err);
    res.status(500).json({ error: 'Failed to export' });
  }
}

module.exports = { submitResponse, exportResponses };

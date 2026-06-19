// Data-driven verification rules — reads from verification_rules table
// with fallback to in-memory badPatterns.js when DB is unavailable

const { getBadPatterns: getFallbackPatterns } = require('./badPatterns');

let _db = null;
function getDb() {
  if (!_db) {
    try { _db = require('../config/db'); } catch { _db = null; }
  }
  return _db;
}

/**
 * Get bad patterns for a concept, querying DB first with badPatterns.js fallback.
 */
async function getPatternsForConcept(conceptName) {
  try {
    const db = getDb();
    if (!db) return getFallbackPatterns(conceptName);

    const conceptRes = await db.query(
      'SELECT id FROM concepts WHERE LOWER(name) = LOWER($1)',
      [conceptName]
    );
    if (conceptRes.rows.length === 0) return getFallbackPatterns(conceptName);

    const rulesRes = await db.query(
      `SELECT pattern_id, tree_sitter_query, severity, student_message, handler
       FROM verification_rules
       WHERE concept_id = $1 AND rule_type = 'bad_pattern' AND is_active = true`,
      [conceptRes.rows[0].id]
    );

    if (rulesRes.rows.length === 0) return getFallbackPatterns(conceptName);

    return rulesRes.rows.map(row => ({
      id: row.pattern_id,
      query: row.tree_sitter_query,
      message: row.student_message,
      severity: row.severity,
      handler: row.handler || undefined,
    }));
  } catch {
    return getFallbackPatterns(conceptName);
  }
}

/**
 * Get variable usage rules for a concept.
 * Returns null if no DB rule exists (caller uses fallback logic).
 */
async function getVariableUsageRule(conceptName) {
  try {
    const db = getDb();
    if (!db) return null;

    const res = await db.query(
      `SELECT vr.student_message, vr.config, c.ast_nodes
       FROM verification_rules vr
       JOIN concepts c ON c.id = vr.concept_id
       WHERE LOWER(c.name) = LOWER($1) AND vr.rule_type = 'variable_usage' AND vr.is_active = true
       LIMIT 1`,
      [conceptName]
    );

    if (res.rows.length === 0) return null;
    return res.rows[0];
  } catch {
    return null;
  }
}

module.exports = { getPatternsForConcept, getVariableUsageRule };

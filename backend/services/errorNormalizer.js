function parseCompilerLog(rawLog, submissionId, studentId, exerciseId, conceptId, conceptName) {
  if (!rawLog) return [];
  const lines = rawLog.split('\n');
  const seen = new Set();
  const errors = [];
  const pattern = /\[Line (\d+):(\d+)\] (\w+): (.+)/;

  for (const line of lines) {
    const match = line.match(pattern);
    if (!match) continue;
    const rawMessage = match[4].trim();
    if (seen.has(rawMessage)) continue;
    seen.add(rawMessage);

    errors.push({
      submissionId,
      studentId,
      exerciseId,
      conceptId,
      conceptName,
      errorType: match[3],
      rawMessage,
      line: parseInt(match[1], 10),
      column: parseInt(match[2], 10)
    });
  }
  return errors;
}

function normalizeMessage(rawMessage) {
  if (!rawMessage) return '';
  let msg = rawMessage;
  msg = msg.replace(/"[^"]*"/g, '<str>');
  msg = msg.replace(/'[a-zA-Z_]\w*'/g, "'<id>'");
  msg = msg.replace(/\/[\w./-]+(:\d+)?/g, '<path>');
  msg = msg.replace(/\b\d+\b/g, '<num>');
  return msg;
}

function extractSignature(normalized) {
  if (!normalized) return '';
  const cleaned = normalized.replace(/^'<id>' /, '').trim();
  const tokens = cleaned.split(/\s+/);
  const result = [];
  for (const t of tokens) {
    if (t.startsWith('<') || t === "'<id>'") break;
    result.push(t);
  }
  return result.slice(0, 10).join(' ');
}

module.exports = {
  parseCompilerLog,
  normalizeMessage,
  extractSignature
};

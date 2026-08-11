/**
 * backend/services/csvWriter.js
 *
 * Minimal hand-rolled RFC 4180 CSV writer (zero dependencies).
 * Used by services/exportService.js to serialize export rows to CSV.
 *
 * columns = { key, header, format?(value, row) }[]
 *   - format pre-formats a cell value (dates MUST be pre-formatted to strings).
 */

/**
 * Escape a single CSV field.
 * Wraps the value in double quotes only when required by RFC 4180:
 * field contains `,`, `"`, `\r` or `\n`, or has leading/trailing whitespace.
 * Embedded `"` are doubled. null/undefined render as an empty field.
 */
function csvEscape(value) {
  if (value === null || value === undefined) return '';
  const str = typeof value === 'string' ? value : String(value);
  if (!/[",\r\n]/.test(str) && !/^\s|\s$/.test(str)) return str;
  return `"${str.replace(/"/g, '""')}"`;
}

/**
 * Serialize rows to a CSV Buffer.
 * Output starts with a UTF-8 BOM (\uFEFF), uses \r\n line endings,
 * writes one header line from columns[].header and one line per row,
 * and always terminates the last line with \r\n (empty rows => header-only file).
 */
function toCsv(rows, columns) {
  const lines = [columns.map((col) => csvEscape(col.header)).join(',')];

  for (const row of rows) {
    const fields = columns.map((col) => {
      let value = row[col.key];
      if (col.format) value = col.format(value, row);
      return csvEscape(value);
    });
    lines.push(fields.join(','));
  }

  return Buffer.from(`\uFEFF${lines.join('\r\n')}\r\n`, 'utf8');
}

module.exports = { csvEscape, toCsv };

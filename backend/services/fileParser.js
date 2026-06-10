const { parse: csvParse } = require('csv-parse/sync');
const ExcelJS = require('exceljs');

/**
 * Parse a CSV buffer into normalized row objects.
 *
 * Enforces strict double-quote encapsulation so unescaped commas
 * inside names (e.g. "Santos, Maria") are not split incorrectly.
 * Auto-detects header row and skips blank lines.
 *
 * @param {Buffer} buffer — raw file buffer from multer
 * @returns {Array<{ email: string, name: string, rawRow: object }>}
 */
function parseCSV(buffer) {
  // Strip UTF-8 BOM if present
  let raw = buffer;
  if (raw[0] === 0xef && raw[1] === 0xbb && raw[2] === 0xbf) {
    raw = raw.subarray(3);
  }

  const text = raw.toString('utf-8');

  const records = csvParse(text, {
    columns: true,
    skip_empty_lines: true,
    trim: true,
    relax_quotes: false, // strict: reject unescaped embedded quotes
    relax_column_count: false, // strict: every row must match header column count
    bom: true,
  });

  // Auto-detect which columns map to email / name
  const headerKeys = Object.keys(records[0] || {});
  const emailCol = headerKeys.find(k => k.toLowerCase().includes('email'))
    || headerKeys.find(k => k.toLowerCase().includes('e-mail'));
  const nameCol = headerKeys.find(k =>
    k.toLowerCase().includes('name')
    || k.toLowerCase().includes('student')
    || k.toLowerCase().includes('fullname')
  ) || headerKeys.find(k => !k.toLowerCase().includes('id') && !k.toLowerCase().includes('section'));

  if (!emailCol) {
    throw new Error('Could not detect an email column in the CSV header. Expected a column containing "email".');
  }
  if (!nameCol) {
    throw new Error('Could not detect a name column in the CSV header. Expected a column containing "name" or "student".');
  }

  const rows = [];
  for (const record of records) {
    const email = (record[emailCol] || '').trim();
    const name = (record[nameCol] || '').trim();
    // Skip rows where both email and name are empty (blank / spacer rows)
    if (!email && !name) continue;
    rows.push({ email, name, rawRow: record });
  }

  return rows;
}

/**
 * Parse an Excel workbook into normalized row objects.
 *
 * Auto-detects the active data sheet (first sheet with data rows).
 * Skips empty header rows and sanitizes data types.
 *
 * @param {Buffer} buffer — raw file buffer from multer
 * @returns {Promise<Array<{ email: string, name: string, rawRow: object }>>}
 */
async function parseExcel(buffer) {
  const workbook = new ExcelJS.Workbook();
  await workbook.xlsx.load(buffer);

  // Find the first sheet with actual data rows
  let targetSheet = null;
  for (const sheet of workbook.worksheets) {
    if (sheet.actualRowCount > 1) {
      targetSheet = sheet;
      break;
    }
  }
  if (!targetSheet) {
    throw new Error('No data found in any sheet. The workbook appears empty.');
  }

  // Detect header row — scan first few rows for a cell containing "email"
  let headerRowIdx = 1; // 1-based
  let emailColIdx = null;
  let nameColIdx = null;

  const scanLimit = Math.min(targetSheet.actualRowCount, 5);
  for (let r = 1; r <= scanLimit; r++) {
    const row = targetSheet.getRow(r);
    for (let c = 1; c <= row.actualCellCount; c++) {
      const val = String(row.getCell(c).value || '').toLowerCase().trim();
      if (val.includes('email') && emailColIdx === null) emailColIdx = c;
      if ((val.includes('name') || val.includes('student')) && nameColIdx === null) nameColIdx = c;
    }
    if (emailColIdx !== null) {
      headerRowIdx = r;
      break;
    }
  }

  if (emailColIdx === null) {
    throw new Error('Could not detect an "email" column in the first row of the active sheet.');
  }
  if (nameColIdx === null) {
    throw new Error('Could not detect a "name" column in the first row of the active sheet.');
  }

  const rows = [];
  for (let r = headerRowIdx + 1; r <= targetSheet.actualRowCount; r++) {
    const row = targetSheet.getRow(r);
    // Skip completely empty rows
    const allEmpty = Array.from({ length: row.actualCellCount }, (_, c) => row.getCell(c + 1).value).every(v => v === null || v === undefined || v === '');
    if (allEmpty) continue;

    let email = sanitizeCellValue(row.getCell(emailColIdx).value);
    let name = sanitizeCellValue(row.getCell(nameColIdx).value);

    email = (email || '').trim();
    name = (name || '').trim();

    if (!email && !name) continue;

    rows.push({ email, name, rawRow: { email, name } });
  }

  return rows;
}

/**
 * Convert an ExcelJS cell value to a clean string.
 * Handles dates (Excel serial numbers), formulas, and hyperlinks.
 */
function sanitizeCellValue(value) {
  if (value === null || value === undefined) return '';
  if (typeof value === 'string') return value;
  if (typeof value === 'number') return String(value);
  if (typeof value === 'boolean') return String(value);
  if (value instanceof Date) return value.toISOString().split('T')[0];
  // Hyperlink / rich text objects
  if (typeof value === 'object') {
    if (value.text !== undefined) return String(value.text);
    if (value.result !== undefined) return String(value.result); // formula result
    if (value.hyperlink !== undefined) return String(value.hyperlink);
  }
  return String(value);
}

/**
 * Validate a single row and return an error string, or null if valid.
 */
function validateRow(row, rowNumber) {
  const email = (row.email || '').trim().toLowerCase();
  const name = (row.name || '').trim();

  if (!email) return { row: rowNumber, field: 'email', message: 'Email is required.', value: row.email };
  if (email.length > 100) return { row: rowNumber, field: 'email', message: 'Email exceeds 100 characters.', value: email };
  // Strict email format check
  const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  if (!emailRegex.test(email)) return { row: rowNumber, field: 'email', message: `Invalid email format: "${email}"`, value: email };

  if (!name) return { row: rowNumber, field: 'name', message: 'Name is required.', value: row.name };
  if (name.length > 100) return { row: rowNumber, field: 'name', message: 'Name exceeds 100 characters.', value: name };

  return null;
}

/**
 * Validate all rows and return { validRows, errors }.
 * validRows is an array of { email, name } (sanitized).
 */
function validateRows(parsedRows) {
  const validRows = [];
  const errors = [];

  for (const row of parsedRows) {
    const rowIdx = parsedRows.indexOf(row) + 2; // +2 because row 1 = header, parsedRows[0] = row 2 in file
    const err = validateRow(row, rowIdx);
    if (err) {
      errors.push(err);
    } else {
      validRows.push({
        email: row.email.trim().toLowerCase(),
        name: row.name.trim(),
      });
    }
  }

  // Deduplicate within the file itself
  const seen = new Set();
  const deduped = [];
  for (const row of validRows) {
    if (seen.has(row.email)) {
      errors.push({ row: 'file', field: 'email', message: `Duplicate email within file: ${row.email}`, value: row.email });
    } else {
      seen.add(row.email);
      deduped.push(row);
    }
  }

  return { validRows: deduped, errors };
}

/**
 * High-level entry point: parse a file buffer, validate rows, return results.
 *
 * @param {Buffer} buffer
 * @param {string} filename
 * @returns {Promise<{ validRows: Array<{email,name}>, errors: Array }> }
 */
async function parseAndValidate(buffer, filename) {
  const ext = filename.split('.').pop().toLowerCase();

  let parsedRows;
  if (ext === 'csv') {
    parsedRows = parseCSV(buffer);
  } else if (ext === 'xlsx' || ext === 'xls') {
    parsedRows = await parseExcel(buffer);
  } else {
    throw new Error(`Unsupported file type: .${ext}. Only .csv and .xlsx are accepted.`);
  }

  if (parsedRows.length === 0) {
    throw new Error('File contains no data rows.');
  }
  if (parsedRows.length > 2000) {
    throw new Error(`File has ${parsedRows.length} data rows. Maximum is 2000.`);
  }

  return validateRows(parsedRows);
}

module.exports = {
  parseCSV,
  parseExcel,
  validateRow,
  validateRows,
  parseAndValidate,
  sanitizeCellValue,
};

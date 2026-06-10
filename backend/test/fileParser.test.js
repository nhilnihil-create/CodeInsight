/**
 * Unit tests for the file upload / import pipeline.
 *
 * Tests:
 *   1. CSV parsing (various anomalies)
 *   2. Excel parsing (structure, type sanitization)
 *   3. Row validation (format checks)
 *   4. Deduplication
 */

const assert = require('assert');
const {
  parseCSV,
  validateRow,
  validateRows,
  sanitizeCellValue,
} = require('../services/fileParser');

// ── Helpers ────────────────────────────────────────────────────────────────

/** Build a CSV string and return a Buffer */
function csvBuffer(text) {
  return Buffer.from(text, 'utf-8');
}

// ── CSV Parsing ────────────────────────────────────────────────────────────

describe('File Parser — CSV', () => {
  it('parses a simple CSV with email and name columns', () => {
    const rows = parseCSV(csvBuffer('email,name\njohn@test.com,John Doe\njane@test.com,Jane Doe'));
    assert.strictEqual(rows.length, 2);
    assert.strictEqual(rows[0].email, 'john@test.com');
    assert.strictEqual(rows[0].name, 'John Doe');
    assert.strictEqual(rows[1].email, 'jane@test.com');
    assert.strictEqual(rows[1].name, 'Jane Doe');
  });

  it('handles commas inside quoted names', () => {
    const rows = parseCSV(csvBuffer('email,name\njohn@test.com,"Santos, Maria"\njane@test.com,"Lim, Ana"'));
    assert.strictEqual(rows.length, 2);
    assert.strictEqual(rows[0].name, 'Santos, Maria');
    assert.strictEqual(rows[1].name, 'Lim, Ana');
  });

  it('skips blank rows', () => {
    const rows = parseCSV(csvBuffer('email,name\njohn@test.com,John\n\n\njane@test.com,Jane\n'));
    assert.strictEqual(rows.length, 2);
  });

  it('handles UTF-8 BOM', () => {
    // UTF-8 BOM bytes + content
    const buf = Buffer.concat([
      Buffer.from([0xef, 0xbb, 0xbf]),
      Buffer.from('email,name\nuser@test.com,Test User\n'),
    ]);
    const rows = parseCSV(buf);
    assert.strictEqual(rows.length, 1);
    assert.strictEqual(rows[0].email, 'user@test.com');
  });

  it('handles reversed column order (name before email)', () => {
    const rows = parseCSV(csvBuffer('name,email\nJohn Doe,john@test.com'));
    assert.strictEqual(rows.length, 1);
    assert.strictEqual(rows[0].email, 'john@test.com');
    assert.strictEqual(rows[0].name, 'John Doe');
  });

  it('throws when no email column is found', () => {
    assert.throws(() => {
      parseCSV(csvBuffer('id,full_name\n1,John Doe'));
    }, /Could not detect an email column/);
  });

  it('trims whitespace from values', () => {
    const rows = parseCSV(csvBuffer('email,name\n  john@test.com  ,  John Doe  '));
    assert.strictEqual(rows[0].email, 'john@test.com');
    assert.strictEqual(rows[0].name, 'John Doe');
  });
});

// ── Row Validation ─────────────────────────────────────────────────────────

describe('File Parser — Row Validation', () => {
  it('returns null for valid rows', () => {
    const err = validateRow({ email: 'john@test.com', name: 'John Doe' }, 2);
    assert.strictEqual(err, null);
  });

  it('catches missing email', () => {
    const err = validateRow({ email: '', name: 'John Doe' }, 3);
    assert.strictEqual(err.row, 3);
    assert.strictEqual(err.field, 'email');
  });

  it('catches invalid email format', () => {
    const err = validateRow({ email: 'not-an-email', name: 'John Doe' }, 4);
    assert.strictEqual(err.field, 'email');
    assert.ok(err.message.includes('Invalid email'));
  });

  it('catches missing name', () => {
    const err = validateRow({ email: 'john@test.com', name: '' }, 5);
    assert.strictEqual(err.field, 'name');
  });

  it('catches email over 100 chars', () => {
    const longEmail = 'a'.repeat(95) + '@test.com';
    const err = validateRow({ email: longEmail, name: 'John' }, 6);
    assert.strictEqual(err.field, 'email');
    assert.ok(err.message.includes('exceeds'));
  });

  it('catches name over 100 chars', () => {
    const longName = 'A'.repeat(101);
    const err = validateRow({ email: 'a@b.com', name: longName }, 7);
    assert.strictEqual(err.field, 'name');
  });
});

// ── validateRows (batch + dedup) ──────────────────────────────────────────

describe('File Parser — validateRows', () => {
  it('validates all rows and collects errors', () => {
    const parsed = [
      { email: 'a@test.com', name: 'A' },
      { email: 'bad', name: 'B' },
      { email: 'c@test.com', name: '' },
    ];
    const { validRows, errors } = validateRows(parsed);
    assert.strictEqual(validRows.length, 1);
    assert.strictEqual(errors.length, 2);
  });

  it('detects duplicate emails within the file', () => {
    const parsed = [
      { email: 'dup@test.com', name: 'First' },
      { email: 'dup@test.com', name: 'Second' },
    ];
    const { validRows, errors } = validateRows(parsed);
    assert.strictEqual(validRows.length, 1);
    const dupErrors = errors.filter(e => e.message.includes('Duplicate'));
    assert.strictEqual(dupErrors.length, 1);
  });

  it('lowercases emails', () => {
    const parsed = [
      { email: 'JOHN@TEST.COM', name: 'John' },
    ];
    const { validRows } = validateRows(parsed);
    assert.strictEqual(validRows[0].email, 'john@test.com');
  });
});

// ── sanitizeCellValue (Excel cell type handling) ──────────────────────────

describe('File Parser — sanitizeCellValue', () => {
  it('returns empty string for null/undefined', () => {
    assert.strictEqual(sanitizeCellValue(null), '');
    assert.strictEqual(sanitizeCellValue(undefined), '');
  });

  it('passes strings through', () => {
    assert.strictEqual(sanitizeCellValue('hello'), 'hello');
  });

  it('converts numbers to strings', () => {
    assert.strictEqual(sanitizeCellValue(42), '42');
    assert.strictEqual(sanitizeCellValue(3.14), '3.14');
  });

  it('converts dates to ISO date strings', () => {
    const d = new Date('2026-06-09');
    assert.strictEqual(sanitizeCellValue(d), '2026-06-09');
  });

  it('handles hyperlink objects', () => {
    assert.strictEqual(sanitizeCellValue({ hyperlink: 'mailto:test@test.com' }), 'mailto:test@test.com');
  });

  it('handles formula result objects', () => {
    assert.strictEqual(sanitizeCellValue({ result: 'computed' }), 'computed');
  });
});

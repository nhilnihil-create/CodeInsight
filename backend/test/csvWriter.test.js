/**
 * Pure unit tests for the hand-rolled RFC 4180 CSV writer (no DB).
 * Covers: BOM, CRLF line endings, multiline/embedded-CR cells, quoting,
 * null/undefined/empty fields, numbers/booleans, header-only output.
 */

const { csvEscape, toCsv } = require('../services/csvWriter');

const BOM = '\uFEFF';
const CSV_BOM_BYTES = Buffer.from([0xef, 0xbb, 0xbf]);

describe('csvEscape', () => {
  it('returns an empty field for null and undefined', () => {
    expect(csvEscape(null)).toBe('');
    expect(csvEscape(undefined)).toBe('');
  });

  it('leaves plain strings untouched', () => {
    expect(csvEscape('hello world')).toBe('hello world');
  });

  it('wraps fields containing commas, quotes, CR or LF', () => {
    expect(csvEscape('a,b')).toBe('"a,b"');
    expect(csvEscape('say "hi"')).toBe('"say ""hi"""');
    expect(csvEscape('line1\nline2')).toBe('"line1\nline2"');
    expect(csvEscape('line1\rline2')).toBe('"line1\rline2"');
  });

  it('doubles embedded quotes', () => {
    expect(csvEscape('He said "hello"')).toBe('"He said ""hello"""');
  });

  it('wraps fields with leading or trailing whitespace', () => {
    expect(csvEscape(' padded ')).toBe('" padded "');
    expect(csvEscape('\tleading')).toBe('"\tleading"');
    expect(csvEscape('trailing  ')).toBe('"trailing  "');
  });

  it('stringifies numbers and booleans', () => {
    expect(csvEscape(12.3)).toBe('12.3');
    expect(csvEscape(0)).toBe('0');
    expect(csvEscape(true)).toBe('true');
    expect(csvEscape(false)).toBe('false');
  });
});

describe('toCsv', () => {
  const columns = [
    { key: 'name', header: 'Name' },
    { key: 'code', header: 'Code' },
    { key: 'score', header: 'Score' },
    { key: 'note', header: 'Note' },
  ];

  it('starts with UTF-8 BOM bytes EF BB BF', () => {
    const buffer = toCsv([], [{ key: 'a', header: 'A' }]);
    expect(buffer.subarray(0, 3)).toEqual(CSV_BOM_BYTES);
  });

  it('uses CRLF line endings and terminates the last line', () => {
    const buffer = toCsv([{ name: 'Alice', code: 'x', score: 1, note: 'n' }], columns);
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toBe('Name,Code,Score,Note\r\nAlice,x,1,n\r\n');
  });

  it('writes a header row from columns[].header', () => {
    const buffer = toCsv([], columns);
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toBe('Name,Code,Score,Note\r\n');
  });

  it('produces a header-only file for an empty row set', () => {
    const buffer = toCsv([], columns);
    expect(buffer.toString('utf8')).toBe(`${BOM}Name,Code,Score,Note\r\n`);
  });

  it('keeps multiline code cells intact and quoted', () => {
    const code = '#include <iostream>\nint main() {\n  return 0;\n}';
    const buffer = toCsv([{ name: 'Bob', code, score: 5, note: null }], columns);
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toBe(`Name,Code,Score,Note\r\nBob,"${code}",5,\r\n`);
  });

  it('preserves embedded CR/LF inside quoted fields', () => {
    const note = 'first\r\nsecond\rthird';
    const buffer = toCsv([{ name: 'A', code: 'x', score: 1, note }], columns);
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toContain(`"${note}"`);
  });

  it('doubles embedded quotes in the output', () => {
    const note = 'He said "hi"';
    const buffer = toCsv([{ name: 'A', code: 'x', score: 1, note }], columns);
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toContain('"He said ""hi"""');
  });

  it('renders empty/null/undefined values as empty fields', () => {
    const buffer = toCsv(
      [{ name: '', code: null, score: undefined, note: 'kept' }],
      columns
    );
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toBe('Name,Code,Score,Note\r\n,,,kept\r\n');
  });

  it('applies column format functions (pre-formatted values)', () => {
    const withFormat = [
      { key: 'when', header: 'When', format: (v) => (v ? v.toISOString() : '') },
    ];
    const when = new Date('2026-03-01T12:00:00.000Z');
    const buffer = toCsv([{ when }, { when: null }], withFormat);
    const text = buffer.toString('utf8').replace(BOM, '');
    expect(text).toBe('When\r\n2026-03-01T12:00:00.000Z\r\n\r\n');
  });
});

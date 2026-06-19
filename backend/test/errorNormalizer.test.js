const { parseCompilerLog, normalizeMessage, extractSignature } = require('../services/errorNormalizer');

describe('parseCompilerLog', () => {
  it('parses standard [Line N:C] ERROR: format', () => {
    const log = `[Line 5:5] ERROR: 'max_val' was not declared in this scope
    max_val = arr[0];
    ^`;
    const result = parseCompilerLog(log, 1, 10, 42, 7, 'Arrays');
    expect(result).toHaveLength(1);
    expect(result[0]).toMatchObject({
      submissionId: 1,
      studentId: 10,
      exerciseId: 42,
      conceptId: 7,
      conceptName: 'Arrays',
      errorType: 'ERROR',
      rawMessage: "'max_val' was not declared in this scope",
      line: 5,
      column: 5
    });
  });

  it('skips lines that do not match the error format', () => {
    const log = `[Line 3:1] ERROR: something wrong
    int x = 5;  // this line should be skipped`;
    const result = parseCompilerLog(log, 1, 10, 42, 7, 'Arrays');
    expect(result).toHaveLength(1);
  });

  it('returns empty array for empty log', () => {
    expect(parseCompilerLog('', 1, 1, 1, 1, 'Test')).toEqual([]);
  });

  it('returns empty array for null log', () => {
    expect(parseCompilerLog(null, 1, 1, 1, 1, 'Test')).toEqual([]);
  });

  it('deduplicates identical error messages within one submission', () => {
    const log = `[Line 5:5] ERROR: 'max_val' was not declared in this scope
[Line 8:5] ERROR: 'max_val' was not declared in this scope`;
    const result = parseCompilerLog(log, 1, 10, 42, 7, 'Arrays');
    expect(result).toHaveLength(1);
  });
});

describe('normalizeMessage', () => {
  it('replaces identifiers with <id>', () => {
    expect(normalizeMessage("'max_val' was not declared")).toBe("'<id>' was not declared");
  });

  it('replaces numbers with <num>', () => {
    expect(normalizeMessage('array index 5 is out of bounds')).toBe('array index <num> is out of bounds');
  });

  it('replaces string literals with <str>', () => {
    expect(normalizeMessage('expected ";" before something')).toBe('expected <str> before something');
  });

  it('replaces file paths with <path>', () => {
    expect(normalizeMessage('/home/user/file.cpp:5 error')).toBe('<path> error');
  });

  it('handles empty string', () => {
    expect(normalizeMessage('')).toBe('');
  });
});

describe('extractSignature', () => {
  it('extracts signature from undeclared variable error', () => {
    expect(extractSignature("'<id>' was not declared in this scope"))
      .toBe('was not declared in this scope');
  });

  it('extracts signature from expected token error', () => {
    expect(extractSignature("expected '<id>' before '<id>'"))
      .toBe('expected');
  });

  it('returns normalized message unchanged if no distinctive tail', () => {
    expect(extractSignature('something went wrong')).toBe('something went wrong');
  });
});

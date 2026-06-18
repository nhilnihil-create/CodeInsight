const { AppError, codes } = require('../lib/AppError');

describe('AppError', function() {
  it('creates error with message and defaults', function() {
    const err = new AppError('Something broke');
    expect(err).toBeInstanceOf(Error);
    expect(err).toBeInstanceOf(AppError);
    expect(err.name).toBe('AppError');
    expect(err.message).toBe('Something broke');
    expect(err.status).toBe(500);
    expect(err.code).toBe('INTERNAL_ERROR');
    expect(err.details).toBeNull();
  });

  it('creates error with custom status and code', function() {
    const err = new AppError('Not found', 404, 'NOT_FOUND');
    expect(err.status).toBe(404);
    expect(err.code).toBe('NOT_FOUND');
  });

  it('creates error with details object', function() {
    const details = { field: 'email', reason: 'already exists' };
    const err = new AppError('Conflict', 409, 'CONFLICT', details);
    expect(err.details).toEqual(details);
  });

  it('creates error with zero status', function() {
    const err = new AppError('Weird', 0, 'WEIRD');
    expect(err.status).toBe(0);
  });

  it('preserves stack trace', function() {
    const err = new AppError('Stack test');
    expect(err.stack).toBeDefined();
    expect(err.stack).toContain('AppError');
  });

  it('handles undefined message', function() {
    const err = new AppError();
    expect(err.status).toBe(500);
    expect(err.code).toBe('INTERNAL_ERROR');
  });

  it('handles null details', function() {
    const err = new AppError('msg', 400, 'VALIDATION_ERROR', null);
    expect(err.details).toBeNull();
  });
});

describe('codes', function() {
  it('defines all expected error codes', function() {
    expect(codes).toEqual({
      VALIDATION: 'VALIDATION_ERROR',
      UNAUTHORIZED: 'UNAUTHORIZED',
      FORBIDDEN: 'FORBIDDEN',
      NOT_FOUND: 'NOT_FOUND',
      CONFLICT: 'CONFLICT',
      INTERNAL: 'INTERNAL_ERROR',
    });
  });

  it('every code matches AppError constructor default when omitted', function() {
    const defaults = new AppError('x');
    expect(defaults.code).toBe(codes.INTERNAL);
  });
});

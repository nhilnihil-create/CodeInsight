const { errorHandler, notFoundHandler } = require('../middleware/errorHandler');
const { AppError } = require('../lib/AppError');

function mockReqRes() {
  const req = { method: 'GET', originalUrl: '/api/test' };
  const res = {
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
  };
  const next = jest.fn();
  return { req, res, next };
}

describe('errorHandler', function() {
  it('handles AppError with all fields', function() {
    const { req, res, next } = mockReqRes();
    const err = new AppError('Custom message', 400, 'VALIDATION_ERROR', { field: 'x' });
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith({
      code: 'VALIDATION_ERROR',
      message: 'Custom message',
      details: { field: 'x' },
    });
  });

  it('handles AppError without details', function() {
    const { req, res, next } = mockReqRes();
    const err = new AppError('Not found', 404, 'NOT_FOUND');
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(404);
    expect(res.json).toHaveBeenCalledWith({
      code: 'NOT_FOUND',
      message: 'Not found',
    });
  });

  it('handles entity.parse.failed', function() {
    const { req, res, next } = mockReqRes();
    const err = { type: 'entity.parse.failed' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith({
      code: 'INVALID_JSON',
      message: 'Invalid JSON in request body',
    });
  });

  it('handles error with explicit status', function() {
    const { req, res, next } = mockReqRes();
    const err = { status: 403, code: 'CUSTOM_CODE', message: 'Forbidden by custom' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(403);
    expect(res.json).toHaveBeenCalledWith({
      code: 'CUSTOM_CODE',
      message: 'Forbidden by custom',
    });
  });

  it('handles error with status but no code', function() {
    const { req, res, next } = mockReqRes();
    const err = { status: 418, message: 'I\'m a teapot' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(418);
    expect(res.json).toHaveBeenCalledWith({
      code: 'ERROR',
      message: 'I\'m a teapot',
    });
  });

  it('handles error with status outside 400-599', function() {
    const { req, res, next } = mockReqRes();
    const err = { status: 302, message: 'Redirect' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(500);
  });

  it('handles Postgres unique violation (23505)', function() {
    const { req, res, next } = mockReqRes();
    const err = { code: '23505', detail: 'Key (email)=already@exists already exists.' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(409);
    expect(res.json).toHaveBeenCalledWith({
      code: 'CONFLICT',
      message: 'Resource already exists',
      details: err.detail,
    });
  });

  it('handles Postgres FK violation (23503)', function() {
    const { req, res, next } = mockReqRes();
    const err = { code: '23503', detail: 'Key (section_id)=42 is not present' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith({
      code: 'FK_VIOLATION',
      message: 'Referenced resource does not exist',
      details: err.detail,
    });
  });

  it('handles Postgres check violation (23514)', function() {
    const { req, res, next } = mockReqRes();
    const err = { code: '23514', detail: 'New row violates check constraint' };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith({
      code: 'CHECK_VIOLATION',
      message: 'Value violates a check constraint',
      details: err.detail,
    });
  });

  it('handles Joi validation error', function() {
    const { req, res, next } = mockReqRes();
    const err = {
      isJoi: true,
      details: [
        { path: ['email'], message: '"email" is required' },
        { path: ['password'], message: '"password" must be at least 8 characters' },
      ],
    };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith({
      code: 'VALIDATION_ERROR',
      message: 'Invalid request body',
      details: [
        { path: 'email', message: '"email" is required' },
        { path: 'password', message: '"password" must be at least 8 characters' },
      ],
    });
  });

  it('handles Joi error without details', function() {
    const { req, res, next } = mockReqRes();
    const err = { isJoi: true };
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith({
      code: 'VALIDATION_ERROR',
      message: 'Invalid request body',
      details: [],
    });
  });

  it('falls back to 500 for unknown errors', function() {
    const { req, res, next } = mockReqRes();
    const err = new Error('Something unexpected');
    errorHandler(err, req, res, next);
    expect(res.status).toHaveBeenCalledWith(500);
    expect(res.json).toHaveBeenCalledWith({
      code: 'INTERNAL_ERROR',
      message: 'An internal server error occurred',
    });
  });

  it('falls back to 500 for null error', function() {
    const { req, res, next } = mockReqRes();
    errorHandler(null, req, res, next);
    expect(res.status).toHaveBeenCalledWith(500);
    expect(res.json).toHaveBeenCalledWith({
      code: 'INTERNAL_ERROR',
      message: 'An internal server error occurred',
    });
  });

  it('falls back to 500 for undefined error', function() {
    const { req, res, next } = mockReqRes();
    errorHandler(undefined, req, res, next);
    expect(res.status).toHaveBeenCalledWith(500);
    expect(res.json).toHaveBeenCalledWith({
      code: 'INTERNAL_ERROR',
      message: 'An internal server error occurred',
    });
  });
});

describe('notFoundHandler', function() {
  it('returns 404 with route info', function() {
    const { req, res } = mockReqRes();
    notFoundHandler(req, res);
    expect(res.status).toHaveBeenCalledWith(404);
    expect(res.json).toHaveBeenCalledWith({
      code: 'NOT_FOUND',
      message: 'Route GET /api/test not found',
    });
  });

  it('includes POST method in message', function() {
    const req = { method: 'POST', originalUrl: '/api/submit' };
    const res = { status: jest.fn().mockReturnThis(), json: jest.fn().mockReturnThis() };
    notFoundHandler(req, res);
    expect(res.json).toHaveBeenCalledWith({
      code: 'NOT_FOUND',
      message: 'Route POST /api/submit not found',
    });
  });
});

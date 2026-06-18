jest.mock('jsonwebtoken');
jest.mock('../lib/AppError', () => {
  const actual = jest.requireActual('../lib/AppError');
  return actual;
});

const jwt = require('jsonwebtoken');
const { verifyToken, requireRole, requireAnyRole } = require('../middleware/auth');

function mockReqRes(opts = {}) {
  const req = {
    cookies: opts.cookies || {},
    headers: opts.headers || {},
    user: opts.user || null,
  };
  const res = {};
  const next = jest.fn();
  return { req, res, next };
}

describe('verifyToken', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    delete process.env.JWT_SECRET;
    process.env.JWT_SECRET = 'test-secret';
  });

  it('accepts token from cookie and decodes it', function() {
    jwt.verify.mockReturnValue({ id: 1, role: 'student' });
    const { req, res, next } = mockReqRes({ cookies: { ci_token: 'valid-cookie-token' } });
    verifyToken(req, res, next);
    expect(jwt.verify).toHaveBeenCalledWith('valid-cookie-token', 'test-secret');
    expect(req.user).toEqual({ id: 1, role: 'student' });
    expect(next).toHaveBeenCalledWith();
  });

  it('falls back to Authorization header when no cookie', function() {
    jwt.verify.mockReturnValue({ id: 2, role: 'instructor' });
    const { req, res, next } = mockReqRes({
      cookies: {},
      headers: { authorization: 'Bearer header-token' },
    });
    verifyToken(req, res, next);
    expect(jwt.verify).toHaveBeenCalledWith('header-token', 'test-secret');
    expect(req.user).toEqual({ id: 2, role: 'instructor' });
  });

  it('calls next with AppError when no token is provided', function() {
    const { req, res, next } = mockReqRes({ cookies: {}, headers: {} });
    verifyToken(req, res, next);
    expect(next).toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.constructor.name).toBe('AppError');
    expect(err.status).toBe(401);
    expect(err.code).toBe('UNAUTHORIZED');
    expect(err.message).toMatch(/no token/i);
  });

  it('calls next with AppError when cookie is present but header is malformed', function() {
    jwt.verify.mockReturnValue({ id: 3, role: 'student' });
    const { req, res, next } = mockReqRes({
      cookies: { ci_token: 'good-cookie' },
      headers: { authorization: 'NotBearer something' },
    });
    verifyToken(req, res, next);
    expect(jwt.verify).toHaveBeenCalledWith('good-cookie', 'test-secret');
    // Cookie wins, so no issue with header
    expect(next).toHaveBeenCalledWith();
  });

  it('calls next with AppError when token is expired', function() {
    jwt.verify.mockImplementation(() => { throw new Error('jwt expired'); });
    const { req, res, next } = mockReqRes({ cookies: { ci_token: 'expired-token' } });
    verifyToken(req, res, next);
    const err = next.mock.calls[0][0];
    expect(err.constructor.name).toBe('AppError');
    expect(err.status).toBe(401);
    expect(err.message).toMatch(/invalid|expired/i);
  });

  it('calls next with AppError when token is malformed', function() {
    jwt.verify.mockImplementation(() => { throw new Error('invalid token'); });
    const { req, res, next } = mockReqRes({ headers: { authorization: 'Bearer bad-token' } });
    verifyToken(req, res, next);
    const err = next.mock.calls[0][0];
    expect(err.constructor.name).toBe('AppError');
    expect(err.status).toBe(401);
  });

  it('calls next with AppError on any JWT error', function() {
    jwt.verify.mockImplementation(() => { throw new TypeError('not a string'); });
    const { req, res, next } = mockReqRes({ cookies: { ci_token: 'weird' } });
    verifyToken(req, res, next);
    expect(next.mock.calls[0][0]).toBeDefined();
    expect(next.mock.calls[0][0].status).toBe(401);
  });

  it('handles Authorization header without Bearer prefix', function() {
    jwt.verify.mockReturnValue({ id: 4, role: 'admin' });
    const { req, res, next } = mockReqRes({
      cookies: {},
      headers: { authorization: 'just-a-token' },
    });
    verifyToken(req, res, next);
    // split(' ') results in ['just-a-token'], token is undefined
    expect(jwt.verify).not.toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
    expect(err.message).toMatch(/no token/i);
  });
});

describe('requireRole', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('passes when role matches', function() {
    const { req, res, next } = mockReqRes({ user: { role: 'instructor' } });
    requireRole('instructor')(req, res, next);
    expect(next).toHaveBeenCalledWith();
  });

  it('blocks when role does not match', function() {
    const { req, res, next } = mockReqRes({ user: { role: 'student' } });
    requireRole('instructor')(req, res, next);
    const err = next.mock.calls[0][0];
    expect(err.constructor.name).toBe('AppError');
    expect(err.status).toBe(403);
    expect(err.code).toBe('FORBIDDEN');
    expect(err.message).toMatch(/access denied/i);
  });

  it('blocks when user has no role property', function() {
    const { req, res, next } = mockReqRes({ user: {} });
    requireRole('admin')(req, res, next);
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(403);
  });

  it('throws TypeError when req.user is undefined (pre-condition: verifyToken must run first)', function() {
    const { req, res, next } = mockReqRes({ user: undefined });
    expect(() => requireRole('student')(req, res, next)).toThrow(TypeError);
  });
});

describe('requireAnyRole', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('passes when user role is in the list', function() {
    const { req, res, next } = mockReqRes({ user: { role: 'student' } });
    requireAnyRole('instructor', 'student', 'ta')(req, res, next);
    expect(next).toHaveBeenCalledWith();
  });

  it('blocks when user role is not in the list', function() {
    const { req, res, next } = mockReqRes({ user: { role: 'admin' } });
    requireAnyRole('instructor', 'student')(req, res, next);
    const err = next.mock.calls[0][0];
    expect(err.constructor.name).toBe('AppError');
    expect(err.status).toBe(403);
    expect(err.code).toBe('FORBIDDEN');
  });

  it('passes with single role in list', function() {
    const { req, res, next } = mockReqRes({ user: { role: 'admin' } });
    requireAnyRole('admin')(req, res, next);
    expect(next).toHaveBeenCalledWith();
  });

  it('blocks when roles list is empty', function() {
    const { req, res, next } = mockReqRes({ user: { role: 'student' } });
    requireAnyRole()(req, res, next);
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(403);
  });
});

jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('bcryptjs');
jest.mock('jsonwebtoken');
jest.mock('../lib/AppError', () => {
  const actual = jest.requireActual('../lib/AppError');
  return actual;
});

const db = require('../config/db');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const controller = require('../controllers/authController');

function mockRes() {
  return {
    cookie: jest.fn().mockReturnThis(),
    clearCookie: jest.fn().mockReturnThis(),
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
  };
}

describe('authController.register', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.JWT_SECRET = 'test-secret';
  });

  it('registers a new user and returns 201 with cookie', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hashed-pw-value');
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' }],
    });
    jwt.sign.mockReturnValue('jwt-token-value');

    const req = { body: { name: 'Alice', email: 'alice@test.com', password: 'secret1234', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(db.query).toHaveBeenNthCalledWith(1, 'SELECT id FROM users WHERE email=$1', ['alice@test.com']);
    expect(bcrypt.hash).toHaveBeenCalledWith('secret1234', 10);
    expect(db.query).toHaveBeenNthCalledWith(2,
      'INSERT INTO users (name,email,password_hash,role) VALUES($1,$2,$3,$4) RETURNING id,name,email,role',
      ['Alice', 'alice@test.com', 'hashed-pw-value', 'student']
    );
    expect(jwt.sign).toHaveBeenCalledWith(
      { id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' },
      'test-secret',
      { expiresIn: '7d' }
    );
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'jwt-token-value', expect.objectContaining({
      httpOnly: true, path: '/',
    }));
    expect(res.status).toHaveBeenCalledWith(201);
    expect(res.json).toHaveBeenCalledWith({ user: { id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' } });
    expect(next).not.toHaveBeenCalled();
  });

  it('returns 409 when email already exists', async function() {
    db.query.mockResolvedValueOnce({ rows: [{ id: 99 }] });
    const req = { body: { name: 'Bob', email: 'bob@test.com', password: 'secret1234', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(409);
    expect(err.code).toBe('CONFLICT');
    expect(err.message).toMatch(/already registered/i);
  });

  it('calls next on database error during insert', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hash');
    db.query.mockRejectedValueOnce(new Error('connection failed'));

    const req = { body: { name: 'Carol', email: 'carol@test.com', password: 'secret1234', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'connection failed' }));
  });

  it('calls next on bcrypt error', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockRejectedValueOnce(new Error('hash error'));

    const req = { body: { name: 'Dave', email: 'dave@test.com', password: 'secret1234', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'hash error' }));
  });

  it('calls next on jwt sign error', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hash');
    db.query.mockResolvedValueOnce({ rows: [{ id: 2, name: 'Eve', email: 'eve@test.com', role: 'student' }] });
    jwt.sign.mockImplementation(() => { throw new Error('jwt error'); });

    const req = { body: { name: 'Eve', email: 'eve@test.com', password: 'secret1234', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'jwt error' }));
  });
});

describe('authController.login', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.JWT_SECRET = 'test-secret';
  });

  it('logs in with valid credentials', async function() {
    const userRow = {
      id: 1, name: 'Alice', email: 'alice@test.com', role: 'student',
      password_hash: '$2a$10$hashedpw',
    };
    db.query.mockResolvedValueOnce({ rows: [userRow] });
    bcrypt.compare.mockResolvedValue(true);
    jwt.sign.mockReturnValue('login-token');

    const req = { body: { email: 'alice@test.com', password: 'secret1234' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(db.query).toHaveBeenCalledWith(
      'SELECT id,name,email,role,password_hash FROM users WHERE email=$1',
      ['alice@test.com']
    );
    expect(bcrypt.compare).toHaveBeenCalledWith('secret1234', '$2a$10$hashedpw');
    expect(jwt.sign).toHaveBeenCalled();
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'login-token', expect.any(Object));
    expect(res.json).toHaveBeenCalledWith({
      user: { id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' },
    });
  });

  it('returns 401 when user not found', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    const req = { body: { email: 'unknown@test.com', password: 'secret1234' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
    expect(err.code).toBe('UNAUTHORIZED');
    expect(err.message).toBe('Invalid credentials');
  });

  it('returns 401 when password is wrong', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Bob', email: 'bob@test.com', role: 'student', password_hash: 'hash' }],
    });
    bcrypt.compare.mockResolvedValue(false);

    const req = { body: { email: 'bob@test.com', password: 'wrongpass' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
    expect(err.message).toBe('Invalid credentials');
  });

  it('calls next on database error', async function() {
    db.query.mockRejectedValueOnce(new Error('db timeout'));
    const req = { body: { email: 'a@b.com', password: 'secret1234' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'db timeout' }));
  });

  it('calls next on bcrypt compare error', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'X', email: 'x@y.com', role: 'student', password_hash: 'hash' }],
    });
    bcrypt.compare.mockRejectedValueOnce(new Error('compare error'));

    const req = { body: { email: 'x@y.com', password: 'secret1234' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'compare error' }));
  });

  it('returns 401 for empty email', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    const req = { body: { email: '', password: 'secret1234' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
  });
});

describe('authController.me', function() {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  it('returns current user from token', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' }],
    });

    const req = { user: { id: 1 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.me(req, res, next);

    expect(db.query).toHaveBeenCalledWith(
      'SELECT id,name,email,role FROM users WHERE id=$1', [1]
    );
    expect(res.json).toHaveBeenCalledWith(
      { id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' }
    );
  });

  it('returns null when user not found', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });

    const req = { user: { id: 999 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.me(req, res, next);

    expect(res.json).toHaveBeenCalledWith(null);
  });

  it('calls next on database error', async function() {
    db.query.mockRejectedValueOnce(new Error('query failed'));
    const req = { user: { id: 1 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.me(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'query failed' }));
  });
});

describe('authController.logout', function() {
  it('clears the cookie and returns loggedOut', async function() {
    const req = {};
    const res = mockRes();
    const next = jest.fn();

    await controller.logout(req, res);

    expect(res.clearCookie).toHaveBeenCalledWith('ci_token', { path: '/' });
    expect(res.json).toHaveBeenCalledWith({ loggedOut: true });
  });
});

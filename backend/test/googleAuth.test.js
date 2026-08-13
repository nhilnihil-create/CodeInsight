jest.mock('google-auth-library', () => ({
  OAuth2Client: jest.fn(),
}));
jest.mock('../config/db', () => ({ query: jest.fn(), withTransaction: jest.fn() }));
jest.mock('bcryptjs');
jest.mock('jsonwebtoken');
jest.mock('../lib/email', () => ({
  sendVerificationEmail: jest.fn().mockResolvedValue(),
  sendOtpEmail: jest.fn().mockResolvedValue(),
}));
jest.mock('../lib/domainValidator', () => ({
  validateEmailDomain: jest.fn(),
}));
jest.mock('../lib/otpStore', () => ({
  generateOtp: jest.fn().mockReturnValue('123456'),
  storeOtp: jest.fn(),
  verifyOtp: jest.fn(),
}));
jest.mock('../lib/AppError', () => {
  const actual = jest.requireActual('../lib/AppError');
  return actual;
});

const { OAuth2Client } = require('google-auth-library');
const db = require('../config/db');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const { validateEmailDomain } = require('../lib/domainValidator');
const controller = require('../controllers/authController');

const CLIENT_ID = 'test-client.apps.googleusercontent.com';

function mockRes() {
  return {
    cookie: jest.fn().mockReturnThis(),
    clearCookie: jest.fn().mockReturnThis(),
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
    redirect: jest.fn().mockReturnThis(),
  };
}

/** Make OAuth2Client return the given payload from verifyIdToken. */
function mockGooglePayload(payload) {
  OAuth2Client.mockImplementation(() => ({
    verifyIdToken: jest.fn().mockResolvedValue({ getPayload: () => payload }),
  }));
}

function mockGoogleReject(err) {
  OAuth2Client.mockImplementation(() => ({
    verifyIdToken: jest.fn().mockRejectedValue(err),
  }));
}

function mockClient() {
  return { query: jest.fn() };
}

/** Make db.withTransaction invoke fn with `client` (bypassing real SQL). */
function mockWithTransaction(client) {
  db.withTransaction.mockImplementation((fn) => fn(client));
}

describe('authController.googleAuth', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.GOOGLE_CLIENT_ID = CLIENT_ID;
    process.env.JWT_SECRET = 'test-secret';
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: false });
    jwt.sign.mockReturnValue('google-jwt');
  });

  it('creates a new student with NULL password_hash, verified email, provider google', async function() {
    mockGooglePayload({
      sub: 'g-123', email: 'Alice@gmail.com', name: 'Alice Doe',
      picture: 'https://lh3.googleusercontent.com/p/photo', email_verified: true,
    });
    const client = mockClient();
    client.query
      .mockResolvedValueOnce({ rows: [] })                       // by email
      .mockResolvedValueOnce({ rows: [] })                       // by google_id
      .mockResolvedValueOnce({                                    // INSERT
        rows: [{ id: 7, name: 'Alice Doe', email: 'alice@gmail.com', role: 'student', email_verified: true, google_id: 'g-123', provider: 'google', avatar_url: 'https://lh3.googleusercontent.com/p/photo' }],
      });
    mockWithTransaction(client);

    const req = { body: { credential: 'id-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(validateEmailDomain).toHaveBeenCalledWith('alice@gmail.com');
    expect(client.query).toHaveBeenNthCalledWith(3,
      expect.stringContaining('INSERT INTO users'),
      expect.arrayContaining(['Alice Doe', 'alice@gmail.com', 'student', 'g-123', 'https://lh3.googleusercontent.com/p/photo'])
    );
    const insertCall = client.query.mock.calls[2];
    expect(insertCall[0]).toContain('password_hash');
    expect(insertCall[0]).toContain("VALUES($1,$2,NULL,$3,true,$4,'google',$5)"); // NULL literal + provider 'google'
    expect(jwt.sign).toHaveBeenCalled();
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'google-jwt', expect.any(Object));
    expect(res.status).toHaveBeenCalledWith(200);
    expect(res.json).toHaveBeenCalledWith({
      user: { id: 7, name: 'Alice Doe', email: 'alice@gmail.com', role: 'student' },
    });
    expect(next).not.toHaveBeenCalled();
  });

  it('auto-assigns instructor role for university email', async function() {
    mockGooglePayload({
      sub: 'g-456', email: 'prof@psu.edu', name: 'Prof Smart', email_verified: true,
    });
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: true });
    const client = mockClient();
    client.query
      .mockResolvedValueOnce({ rows: [] })
      .mockResolvedValueOnce({ rows: [] })
      .mockResolvedValueOnce({
        rows: [{ id: 9, name: 'Prof Smart', email: 'prof@psu.edu', role: 'instructor', email_verified: true, google_id: 'g-456', provider: 'google', avatar_url: null }],
      });
    mockWithTransaction(client);

    const req = { body: { credential: 'id-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(client.query.mock.calls[2][1]).toContain('instructor');
    expect(res.json).toHaveBeenCalledWith({
      user: expect.objectContaining({ role: 'instructor' }),
    });
    expect(next).not.toHaveBeenCalled();
  });

  it('links an existing email and preserves the stored role', async function() {
    mockGooglePayload({
      sub: 'g-789', email: 'maria@psu.edu', name: 'Maria', email_verified: true,
    });
    // Domain would classify as student, but the stored instructor role wins.
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: false });
    const client = mockClient();
    client.query
      .mockResolvedValueOnce({
        rows: [{ id: 11, name: 'Maria', email: 'maria@psu.edu', role: 'instructor', email_verified: true, google_id: null, provider: 'email', avatar_url: null }],
      })
      .mockResolvedValueOnce({
        rows: [{ id: 11, name: 'Maria', email: 'maria@psu.edu', role: 'instructor', email_verified: true, google_id: 'g-789', provider: 'google', avatar_url: null }],
      });
    mockWithTransaction(client);

    const req = { body: { credential: 'id-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(client.query).toHaveBeenNthCalledWith(2,
      expect.stringContaining('UPDATE users'),
      ['g-789', null, 11]
    );
    expect(client.query).toHaveBeenCalledTimes(2); // no INSERT
    expect(res.json).toHaveBeenCalledWith({
      user: expect.objectContaining({ role: 'instructor' }),
    });
    expect(next).not.toHaveBeenCalled();
  });

  it('reuses an account already linked by google_id without inserting', async function() {
    mockGooglePayload({
      sub: 'g-111', email: 'bob@gmail.com', name: 'Bob', email_verified: true,
    });
    const client = mockClient();
    client.query
      .mockResolvedValueOnce({ rows: [] })                       // by email
      .mockResolvedValueOnce({                                    // by google_id
        rows: [{ id: 21, name: 'Bob', email: 'bob@gmail.com', role: 'student', email_verified: true, google_id: 'g-111', provider: 'google', avatar_url: 'http://img/x' }],
      });
    mockWithTransaction(client);

    const req = { body: { credential: 'id-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(client.query).toHaveBeenCalledTimes(2); // no INSERT, no UPDATE
    expect(jwt.sign).toHaveBeenCalled();
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'google-jwt', expect.any(Object));
    expect(res.status).toHaveBeenCalledWith(200);
    expect(res.json).toHaveBeenCalledWith({
      user: { id: 21, name: 'Bob', email: 'bob@gmail.com', role: 'student' },
    });
    expect(next).not.toHaveBeenCalled();
  });

  it('rejects an unverified Google email with 401', async function() {
    mockGooglePayload({
      sub: 'g-222', email: 'evil@gmail.com', name: 'Evil', email_verified: false,
    });

    const req = { body: { credential: 'id-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(db.withTransaction).not.toHaveBeenCalled();
    expect(res.cookie).not.toHaveBeenCalled();
    expect(next).toHaveBeenCalledTimes(1);
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
    expect(err.code).toBe('UNAUTHORIZED');
    expect(err.message).toBe('Invalid Google sign-in token');
  });

  it('returns a generic 401 when verifyIdToken rejects', async function() {
    mockGoogleReject(new Error('invalid_token'));

    const req = { body: { credential: 'bad-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(db.withTransaction).not.toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
    expect(err.message).toBe('Invalid Google sign-in token');
  });

  it('returns 500 when GOOGLE_CLIENT_ID is not configured', async function() {
    delete process.env.GOOGLE_CLIENT_ID;

    const req = { body: { credential: 'id-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(OAuth2Client).not.toHaveBeenCalled();
    expect(db.withTransaction).not.toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(500);
    expect(err.code).toBe('INTERNAL_ERROR');
    expect(err.message).toBe('Google sign-in is not configured');
  });

  it('returns 400 when the provided clientId does not match', async function() {
    const req = { body: { credential: 'id-token', clientId: 'other-client.apps.googleusercontent.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(OAuth2Client).not.toHaveBeenCalled();
    expect(db.withTransaction).not.toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(400);
    expect(err.code).toBe('VALIDATION_ERROR');
    expect(err.message).toBe('Invalid client id');
  });

  it('accepts a matching clientId', async function() {
    mockGooglePayload({
      sub: 'g-333', email: 'carol@gmail.com', name: 'Carol', email_verified: true,
    });
    const client = mockClient();
    client.query
      .mockResolvedValueOnce({ rows: [] })
      .mockResolvedValueOnce({ rows: [] })
      .mockResolvedValueOnce({
        rows: [{ id: 31, name: 'Carol', email: 'carol@gmail.com', role: 'student', email_verified: true, google_id: 'g-333', provider: 'google', avatar_url: null }],
      });
    mockWithTransaction(client);

    const req = { body: { credential: 'id-token', clientId: CLIENT_ID } };
    const res = mockRes();
    const next = jest.fn();

    await controller.googleAuth(req, res, next);

    expect(next).not.toHaveBeenCalled();
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'google-jwt', expect.any(Object));
  });
});

describe('authController.login (Google-only account guard)', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.JWT_SECRET = 'test-secret';
  });

  it('returns 401 without calling bcrypt.compare when password_hash is NULL', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@gmail.com', role: 'student', password_hash: null, email_verified: true }],
    });

    const req = { body: { email: 'alice@gmail.com', password: 'whatever' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(bcrypt.compare).not.toHaveBeenCalled();
    expect(res.cookie).not.toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(401);
    expect(err.code).toBe('UNAUTHORIZED');
    expect(err.message).toBe('Invalid credentials');
  });

  it('still logs in normally when password_hash is present', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student', password_hash: '$2a$10$hash', email_verified: true }],
    });
    bcrypt.compare.mockResolvedValue(true);
    jwt.sign.mockReturnValue('login-token');

    const req = { body: { email: 'alice@test.com', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(bcrypt.compare).toHaveBeenCalledWith('Secret123!', '$2a$10$hash');
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'login-token', expect.any(Object));
    expect(next).not.toHaveBeenCalled();
  });
});

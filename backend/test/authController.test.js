jest.mock('../config/db', () => ({ query: jest.fn() }));
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

const db = require('../config/db');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const sendVerificationEmail = require('../lib/email').sendVerificationEmail;
const { sendOtpEmail } = require('../lib/email');
const { validateEmailDomain } = require('../lib/domainValidator');
const { storeOtp, verifyOtp } = require('../lib/otpStore');
const controller = require('../controllers/authController');

function mockRes() {
  return {
    cookie: jest.fn().mockReturnThis(),
    clearCookie: jest.fn().mockReturnThis(),
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
    redirect: jest.fn().mockReturnThis(),
  };
}

describe('authController.register', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.JWT_SECRET = 'test-secret';
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: false });
  });

  it('registers a new student and returns 201 without cookie', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hashed-pw-value');
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' }],
    });

    const req = { body: { name: 'Alice', email: 'alice@test.com', password: 'Secret123!', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(db.query).toHaveBeenNthCalledWith(1, 'SELECT id FROM users WHERE email=$1', ['alice@test.com']);
    expect(bcrypt.hash).toHaveBeenCalledWith('Secret123!', 10);
    expect(db.query).toHaveBeenNthCalledWith(2,
      expect.stringContaining('INSERT INTO users'),
      expect.arrayContaining(['Alice', 'alice@test.com', 'hashed-pw-value', 'student'])
    );
    expect(jwt.sign).not.toHaveBeenCalled();
    expect(res.cookie).not.toHaveBeenCalled();
    expect(res.status).toHaveBeenCalledWith(201);
    expect(res.json).toHaveBeenCalledWith({
      message: expect.stringMatching(/check your email/i),
      user: { id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' },
    });
    expect(next).not.toHaveBeenCalled();
  });

  it('rejects registration with disposable email', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    validateEmailDomain.mockResolvedValue({ valid: false, isUniversity: false, reason: 'Temporary email addresses are not allowed' });
    const req = { body: { name: 'Spam', email: 'spam@mailinator.com', password: 'Secret123!', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalled();
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(400);
    expect(err.message).toMatch(/temporary/i);
  });

  it('auto-assigns instructor role for edu domain', async function() {
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: true });
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hash');
    db.query.mockResolvedValueOnce({
      rows: [{ id: 3, name: 'Prof', email: 'prof@psu.edu', role: 'instructor' }],
    });

    const req = { body: { name: 'Prof', email: 'prof@psu.edu', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(res.status).toHaveBeenCalledWith(201);
    expect(res.json).toHaveBeenCalledWith(
      expect.objectContaining({
        user: expect.objectContaining({ role: 'instructor' }),
      })
    );
  });

  it('returns 409 when email already exists', async function() {
    db.query.mockResolvedValueOnce({ rows: [{ id: 99 }] });
    const req = { body: { name: 'Bob', email: 'bob@test.com', password: 'Secret123!', role: 'student' } };
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

    const req = { body: { name: 'Carol', email: 'carol@test.com', password: 'Secret123!', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'connection failed' }));
  });

  it('calls next on bcrypt error', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockRejectedValueOnce(new Error('hash error'));

    const req = { body: { name: 'Dave', email: 'dave@test.com', password: 'Secret123!', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'hash error' }));
  });

  it('returns 201 even when verification email fails', async function() {
    sendVerificationEmail.mockRejectedValueOnce(new Error('SMTP unavailable'));
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hashed-pw-value');
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' }],
    });

    const req = { body: { name: 'Alice', email: 'alice@test.com', password: 'Secret123!', role: 'student' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.register(req, res, next);

    expect(res.status).toHaveBeenCalledWith(201);
    expect(next).not.toHaveBeenCalled();
  });
});

describe('authController.requestOtp', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: false });
  });

  it('sends OTP for valid email', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    const req = { body: { email: 'alice@gmail.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.requestOtp(req, res, next);

    expect(storeOtp).toHaveBeenCalledWith('alice@gmail.com', '123456');
    expect(res.json).toHaveBeenCalledWith({ message: expect.stringMatching(/code sent/i) });
  });

  it('rejects OTP request for existing email', async function() {
    db.query.mockResolvedValueOnce({ rows: [{ id: 1 }] });
    const req = { body: { email: 'existing@test.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.requestOtp(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(409);
  });
});

describe('authController.verifyOtpAndRegister', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.JWT_SECRET = 'test-secret';
    validateEmailDomain.mockResolvedValue({ valid: true, isUniversity: false });
  });

  it('registers user with valid OTP', async function() {
    verifyOtp.mockReturnValue({ valid: true });
    db.query.mockResolvedValueOnce({ rows: [] });
    bcrypt.hash.mockResolvedValue('hash');
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@gmail.com', role: 'student' }],
    });
    jwt.sign.mockReturnValue('otp-jwt');

    const req = { body: { email: 'alice@gmail.com', otp: '123456', name: 'Alice', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.verifyOtpAndRegister(req, res, next);

    expect(verifyOtp).toHaveBeenCalledWith('alice@gmail.com', '123456');
    expect(res.status).toHaveBeenCalledWith(201);
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'otp-jwt', expect.any(Object));
  });

  it('rejects invalid OTP', async function() {
    verifyOtp.mockReturnValue({ valid: false, reason: 'Invalid OTP code' });
    const req = { body: { email: 'alice@gmail.com', otp: '000000', name: 'Alice', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.verifyOtpAndRegister(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(400);
  });

  it('rejects duplicate email after OTP verification', async function() {
    verifyOtp.mockReturnValue({ valid: true });
    db.query.mockResolvedValueOnce({ rows: [{ id: 1 }] });

    const req = { body: { email: 'existing@test.com', otp: '123456', name: 'Existing', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.verifyOtpAndRegister(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(409);
  });
});

describe('authController.login', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.JWT_SECRET = 'test-secret';
  });

  it('logs in with valid credentials for verified user', async function() {
    const userRow = {
      id: 1, name: 'Alice', email: 'alice@test.com', role: 'student',
      password_hash: '$2a$10$hashedpw', email_verified: true,
    };
    db.query.mockResolvedValueOnce({ rows: [userRow] });
    bcrypt.compare.mockResolvedValue(true);
    jwt.sign.mockReturnValue('login-token');

    const req = { body: { email: 'alice@test.com', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(db.query).toHaveBeenCalledWith(
      'SELECT id,name,email,role,password_hash,email_verified FROM users WHERE email=$1',
      ['alice@test.com']
    );
    expect(bcrypt.compare).toHaveBeenCalledWith('Secret123!', '$2a$10$hashedpw');
    expect(jwt.sign).toHaveBeenCalled();
    expect(res.cookie).toHaveBeenCalledWith('ci_token', 'login-token', expect.any(Object));
    expect(res.json).toHaveBeenCalledWith({
      user: { id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' },
    });
  });

  it('returns 403 when email not verified', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Bob', email: 'bob@test.com', role: 'student', password_hash: 'hash', email_verified: false }],
    });
    bcrypt.compare.mockResolvedValue(true);

    const req = { body: { email: 'bob@test.com', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(403);
    expect(err.message).toMatch(/verify your email/i);
  });

  it('returns 401 when user not found', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    const req = { body: { email: 'unknown@test.com', password: 'Secret123!' } };
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
      rows: [{ id: 1, name: 'Bob', email: 'bob@test.com', role: 'student', password_hash: 'hash', email_verified: true }],
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
    const req = { body: { email: 'a@b.com', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'db timeout' }));
  });

  it('calls next on bcrypt compare error', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'X', email: 'x@y.com', role: 'student', password_hash: 'hash', email_verified: true }],
    });
    bcrypt.compare.mockRejectedValueOnce(new Error('compare error'));

    const req = { body: { email: 'x@y.com', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.login(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'compare error' }));
  });
});

describe('authController.me', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('returns current user from token', async function() {
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' }],
    });
    const req = { user: { id: 1 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.me(req, res, next);

    expect(db.query).toHaveBeenCalledWith('SELECT id,name,email,role FROM users WHERE id=$1', [1]);
    expect(res.json).toHaveBeenCalledWith({ id: 1, name: 'Alice', email: 'alice@test.com', role: 'student' });
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
  beforeEach(() => { jest.clearAllMocks(); });

  it('clears the cookie and blacklists token', async function() {
    jwt.verify.mockReturnValue({ jti: 'test-jti', exp: Math.floor(Date.now() / 1000) + 3600 });
    db.query.mockResolvedValueOnce({ rowCount: 1 });

    const req = { cookies: { ci_token: 'some-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.logout(req, res);

    expect(db.query).toHaveBeenCalledWith(
      'INSERT INTO token_blacklist (jti, expires_at) VALUES ($1, to_timestamp($2)) ON CONFLICT (jti) DO NOTHING',
      ['test-jti', expect.any(Number)]
    );
    expect(res.clearCookie).toHaveBeenCalledWith('ci_token', { path: '/' });
    expect(res.json).toHaveBeenCalledWith({ loggedOut: true });
  });

  it('clears cookie even without token', async function() {
    const req = {};
    const res = mockRes();

    await controller.logout(req, res);

    expect(res.clearCookie).toHaveBeenCalledWith('ci_token', { path: '/' });
    expect(res.json).toHaveBeenCalledWith({ loggedOut: true });
  });
});

describe('authController.verifyEmail', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    process.env.CORS_ORIGINS = 'http://localhost:3000';
  });

  it('verifies email with valid token', async function() {
    const future = new Date(Date.now() + 3600000);
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, email_verified: false, verification_token_expires: future }],
    });
    db.query.mockResolvedValueOnce({ rowCount: 1 });

    const req = { params: { token: 'valid-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.verifyEmail(req, res, next);

    expect(res.redirect).toHaveBeenCalledWith('http://localhost:3000/login?verified=true');
  });

  it('returns error with invalid token', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    const req = { params: { token: 'invalid-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.verifyEmail(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(400);
    expect(err.message).toMatch(/invalid|expired/i);
  });

  it('returns error with expired token', async function() {
    const past = new Date(Date.now() - 3600000);
    db.query.mockResolvedValueOnce({
      rows: [{ id: 1, email_verified: false, verification_token_expires: past }],
    });
    const req = { params: { token: 'expired-token' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.verifyEmail(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(400);
    expect(err.message).toMatch(/expired/i);
  });
});

describe('authController.forgotPassword', function() {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  it('returns 404 when no account exists for the email', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });

    const req = { body: { email: 'nobody@test.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.forgotPassword(req, res, next);

    expect(db.query).toHaveBeenCalledWith('SELECT id, name FROM users WHERE email=$1', ['nobody@test.com']);
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(404);
    expect(err.code).toBe('NOT_FOUND');
    expect(err.message).toMatch(/No account found/i);
    expect(storeOtp).not.toHaveBeenCalled();
  });

  it('stores an OTP and sends it for a known email', async function() {
    db.query.mockResolvedValueOnce({ rows: [{ id: 1, name: 'Alice' }] });

    const req = { body: { email: 'alice@test.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.forgotPassword(req, res, next);

    expect(storeOtp).toHaveBeenCalledWith('alice@test.com', '123456');
    expect(sendOtpEmail).toHaveBeenCalledWith({ to: 'alice@test.com', name: 'Alice', otp: '123456' });
    expect(res.json).toHaveBeenCalledWith({ message: 'Password reset code sent to your email' });
    expect(next).not.toHaveBeenCalled();
  });

  it('returns the OTP in the body when email delivery fails', async function() {
    db.query.mockResolvedValueOnce({ rows: [{ id: 1, name: 'Alice' }] });
    sendOtpEmail.mockRejectedValueOnce(new Error('SMTP unavailable'));

    const req = { body: { email: 'alice@test.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.forgotPassword(req, res, next);

    expect(res.json).toHaveBeenCalledWith({
      message: 'Email delivery failed. Use the OTP below to reset your password.',
      otp: '123456',
    });
    expect(next).not.toHaveBeenCalled();
  });

  it('calls next on database error', async function() {
    db.query.mockRejectedValueOnce(new Error('connection failed'));

    const req = { body: { email: 'alice@test.com' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.forgotPassword(req, res, next);

    expect(next).toHaveBeenCalledWith(expect.objectContaining({ message: 'connection failed' }));
  });
});

describe('authController.resetPassword', function() {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  it.each([
    'No OTP requested for this email',
    'OTP has expired. Request a new one.',
    'Too many failed attempts. Request a new OTP.',
    'Invalid code. Use the code from the most recent email, or tap Resend.',
  ])('returns 400 when OTP is invalid (%s)', async function(reason) {
    verifyOtp.mockReturnValue({ valid: false, reason });

    const req = { body: { email: 'alice@test.com', otp: '000000', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.resetPassword(req, res, next);

    expect(verifyOtp).toHaveBeenCalledWith('alice@test.com', '000000');
    const err = next.mock.calls[0][0];
    expect(err.status).toBe(400);
    expect(err.code).toBe('VALIDATION_ERROR');
    expect(err.message).toBe(reason);
    expect(db.query).toHaveBeenCalledTimes(0);
  });

  it('updates the password and marks the email verified with a valid OTP', async function() {
    verifyOtp.mockReturnValue({ valid: true });
    db.query.mockResolvedValueOnce({ rows: [{ id: 1 }] });
    bcrypt.hash.mockResolvedValue('hashed-pw-value');
    db.query.mockResolvedValueOnce({ rowCount: 1 });

    const req = { body: { email: 'alice@test.com', otp: '123456', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.resetPassword(req, res, next);

    expect(bcrypt.hash).toHaveBeenCalledWith('Secret123!', 10);
    expect(db.query).toHaveBeenNthCalledWith(2,
      expect.stringContaining('UPDATE users SET password_hash = $1, email_verified = true'),
      ['hashed-pw-value', 'alice@test.com']
    );
    expect(res.cookie).not.toHaveBeenCalled();
    expect(jwt.sign).not.toHaveBeenCalled();
    expect(res.json).toHaveBeenCalledWith({ message: 'Password updated. Please sign in with your new password.' });
    expect(next).not.toHaveBeenCalled();
  });

  it('returns 404 when the user is missing after a valid OTP', async function() {
    verifyOtp.mockReturnValue({ valid: true });
    db.query.mockResolvedValueOnce({ rows: [] });

    const req = { body: { email: 'ghost@test.com', otp: '123456', password: 'Secret123!' } };
    const res = mockRes();
    const next = jest.fn();

    await controller.resetPassword(req, res, next);

    const err = next.mock.calls[0][0];
    expect(err.status).toBe(404);
    expect(err.code).toBe('NOT_FOUND');
    expect(err.message).toMatch(/No account found/i);
    expect(bcrypt.hash).not.toHaveBeenCalled();
  });
});

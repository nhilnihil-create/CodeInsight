const bcrypt = require('bcryptjs');
const crypto = require('crypto');
const jwt    = require('jsonwebtoken');
const db     = require('../config/db');
const logger = require('../lib/logger');
const { AppError, codes } = require('../lib/AppError');
const { sendVerificationEmail, sendOtpEmail } = require('../lib/email');
const { validateEmailDomain } = require('../lib/domainValidator');
const { generateOtp, storeOtp, verifyOtp } = require('../lib/otpStore');

const COOKIE_OPTS = {
  httpOnly: true,
  secure: process.env.NODE_ENV === 'production',
  sameSite: process.env.NODE_ENV === 'production' ? 'None' : 'Lax',
  maxAge: 7 * 24 * 60 * 60 * 1000,
  path: '/',
};

const generateToken = (user) =>
  jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role, jti: crypto.randomUUID() },
    process.env.JWT_SECRET,
    { expiresIn: '7d' }
  );

async function determineRole(email) {
  const { isUniversity } = await validateEmailDomain(email);
  return isUniversity ? 'instructor' : 'student';
}

function setAuthCookie(res, user) {
  const safe = { id: user.id, name: user.name, email: user.email, role: user.role };
  const token = generateToken(safe);
  res.cookie('ci_token', token, COOKIE_OPTS);
  return { user: safe };
}

exports.requestOtp = async (req, res, next) => {
  try {
    const { email } = req.body;
    if (!email) throw new AppError('Email is required', 400, codes.VALIDATION_ERROR);

    const domainCheck = await validateEmailDomain(email);
    if (!domainCheck.valid) {
      throw new AppError(domainCheck.reason, 400, codes.VALIDATION_ERROR);
    }

    const existing = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (existing.rows.length) {
      throw new AppError('Email already registered', 409, codes.CONFLICT);
    }

    const otp = generateOtp();
    storeOtp(email, otp);

    const name = email.split('@')[0];
    let emailSent = false;
    try {
      await sendOtpEmail({ to: email, name, otp });
      emailSent = true;
    } catch (err) {
      logger.error({ err, email }, 'Failed to send OTP email — returning code in response');
    }

    const response = { message: 'Verification code sent to your email' };
    if (!emailSent) {
      response.otp = otp;
      response.message = 'Email delivery failed. Use the OTP below to complete registration.';
    }
    res.json(response);
  } catch (err) { next(err); }
};

exports.verifyOtpAndRegister = async (req, res, next) => {
  try {
    const { email, otp, name, password, role: requestedRole } = req.body;
    if (!email || !otp || !name || !password) {
      throw new AppError('Email, OTP, name, and password are required', 400, codes.VALIDATION_ERROR);
    }

    const result = verifyOtp(email, otp);
    if (!result.valid) {
      throw new AppError(result.reason, 400, codes.VALIDATION_ERROR);
    }

    const existing = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (existing.rows.length) {
      throw new AppError('Email already registered', 409, codes.CONFLICT);
    }

    const domainCheck = await validateEmailDomain(email);
    const role = requestedRole || await determineRole(email);
    if (role === 'instructor' && !domainCheck.isUniversity) {
      throw new AppError('Instructor accounts require a university email', 400, codes.VALIDATION_ERROR);
    }

    const hash = await bcrypt.hash(password, 10);

    const insert = await db.query(
      `INSERT INTO users (name,email,password_hash,role,email_verified)
       VALUES($1,$2,$3,$4,true)
       RETURNING id,name,email,role`,
      [name, email, hash, role]
    );
    const user = insert.rows[0];
    const response = setAuthCookie(res, user);
    res.status(201).json(response);
  } catch (err) { next(err); }
};

exports.register = async (req, res, next) => {
  try {
    const { name, email, password, role } = req.body;

    const exists = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (exists.rows.length) throw new AppError('Email already registered', 409, codes.CONFLICT);

    const domainCheck = await validateEmailDomain(email);
    if (!domainCheck.valid) {
      throw new AppError(domainCheck.reason, 400, codes.VALIDATION_ERROR);
    }

    const assignedRole = role || await determineRole(email);
    if (assignedRole === 'instructor' && !domainCheck.isUniversity) {
      throw new AppError('Instructor accounts require a university email', 400, codes.VALIDATION_ERROR);
    }

    const hash = await bcrypt.hash(password, 10);
    const verificationToken = crypto.randomBytes(32).toString('hex');
    const tokenHash = crypto.createHash('sha256').update(verificationToken).digest('hex');

    const result = await db.query(
      `INSERT INTO users (name,email,password_hash,role,email_verified,verification_token,verification_token_expires)
       VALUES($1,$2,$3,$4,false,$5,NOW() + INTERVAL '24 hours')
       RETURNING id,name,email,role`,
      [name, email, hash, assignedRole, tokenHash]
    );

    const user = result.rows[0];

    try {
      await sendVerificationEmail({ to: email, name, token: verificationToken });
    } catch (err) {
      logger.error({ err }, 'Failed to send verification email after registration');
    }

    res.status(201).json({
      message: 'Registration successful. Please check your email to verify your account.',
      user: { id: user.id, name: user.name, email: user.email, role: user.role },
    });
  } catch (err) { next(err); }
};

exports.login = async (req, res, next) => {
  try {
    const { email, password } = req.body;

    const result = await db.query(
      'SELECT id,name,email,role,password_hash,email_verified FROM users WHERE email=$1', [email]
    );
    if (!result.rows.length) throw new AppError('Invalid credentials', 401, codes.UNAUTHORIZED);

    const user = result.rows[0];
    const valid = await bcrypt.compare(password, user.password_hash);
    if (!valid) throw new AppError('Invalid credentials', 401, codes.UNAUTHORIZED);

    if (!user.email_verified) {
      throw new AppError('Please verify your email before logging in.', 403, codes.FORBIDDEN);
    }

    const safeUser = { id: user.id, name: user.name, email: user.email, role: user.role };
    setAuthCookie(res, safeUser);
    res.json({ user: safeUser });
  } catch (err) { next(err); }
};

exports.me = async (req, res, next) => {
  try {
    let userId = req.user?.id;
    if (!userId) {
      const authHeader = req.headers?.authorization;
      const token = req.cookies?.ci_token || (authHeader && authHeader.split(' ')[1]);
      if (!token) return res.json(null);
      try { userId = jwt.verify(token, process.env.JWT_SECRET).id; }
      catch { return res.json(null); }
    }

    const result = await db.query(
      'SELECT id,name,email,role FROM users WHERE id=$1', [userId]
    );
    if (!result.rows.length) return res.json(null);
    res.json(result.rows[0]);
  } catch (err) { next(err); }
};

exports.verifyEmail = async (req, res, next) => {
  try {
    const { token } = req.params;
    if (!token) throw new AppError('Verification token is required', 400, codes.VALIDATION_ERROR);

    const tokenHash = crypto.createHash('sha256').update(token).digest('hex');

    const result = await db.query(
      `SELECT id, email_verified, verification_token_expires FROM users
       WHERE verification_token = $1 AND email_verified = false`,
      [tokenHash]
    );

    if (!result.rows.length) {
      throw new AppError('Invalid or expired verification token', 400, codes.VALIDATION_ERROR);
    }

    const user = result.rows[0];
    if (new Date() > new Date(user.verification_token_expires)) {
      throw new AppError('Verification token has expired. Please register again.', 400, codes.VALIDATION_ERROR);
    }

    await db.query(
      `UPDATE users SET email_verified = true, verification_token = NULL, verification_token_expires = NULL WHERE id = $1`,
      [user.id]
    );

    const frontendUrl = (process.env.CORS_ORIGINS || 'http://localhost:3000').split(',')[0].trim();
    res.redirect(`${frontendUrl}/login?verified=true`);
  } catch (err) { next(err); }
};

exports.logout = async (req, res, next) => {
  try {
    const token = req.cookies?.ci_token;
    if (token) {
      try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        if (decoded.jti && decoded.exp) {
          await db.query(
            'INSERT INTO token_blacklist (jti, expires_at) VALUES ($1, to_timestamp($2)) ON CONFLICT (jti) DO NOTHING',
            [decoded.jti, decoded.exp]
          );
        }
      } catch { /* token may already be expired — still clear cookie */ }
    }
    res.clearCookie('ci_token', { path: '/' });
    res.json({ loggedOut: true });
  } catch (err) { next(err); }
};

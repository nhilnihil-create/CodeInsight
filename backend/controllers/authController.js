const bcrypt = require('bcryptjs');
const crypto = require('crypto');
const jwt    = require('jsonwebtoken');
const { OAuth2Client } = require('google-auth-library');
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
    if (!email) throw new AppError('Email is required', 400, codes.VALIDATION);

    const domainCheck = await validateEmailDomain(email);
    if (!domainCheck.valid) {
      throw new AppError(domainCheck.reason, 400, codes.VALIDATION);
    }

    const existing = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (existing.rows.length) {
      throw new AppError('Email already registered', 409, codes.CONFLICT);
    }

    const otp = generateOtp();
    await storeOtp(email, otp);

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
      throw new AppError('Email, OTP, name, and password are required', 400, codes.VALIDATION);
    }

    const result = await verifyOtp(email, otp);
    if (!result.valid) {
      logger.warn({ email, reason: result.reason }, 'OTP verification failed');
      throw new AppError(result.reason, 400, codes.VALIDATION);
    }

    const existing = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (existing.rows.length) {
      throw new AppError('Email already registered', 409, codes.CONFLICT);
    }

    const domainCheck = await validateEmailDomain(email);
    const role = requestedRole || await determineRole(email);
    if (role === 'instructor' && !domainCheck.isUniversity) {
      throw new AppError('Instructor accounts require a university email', 400, codes.VALIDATION);
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
      throw new AppError(domainCheck.reason, 400, codes.VALIDATION);
    }

    const assignedRole = role || await determineRole(email);
    if (assignedRole === 'instructor' && !domainCheck.isUniversity) {
      throw new AppError('Instructor accounts require a university email', 400, codes.VALIDATION);
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
    // Google-only accounts have no password — fail with the same generic
    // message instead of crashing bcrypt.compare with a NULL hash.
    if (!user.password_hash) throw new AppError('Invalid credentials', 401, codes.UNAUTHORIZED);
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

exports.googleAuth = async (req, res, next) => {
  try {
    const { credential, clientId } = req.body;

    if (!process.env.GOOGLE_CLIENT_ID) {
      throw new AppError('Google sign-in is not configured', 500, codes.INTERNAL);
    }
    if (clientId && clientId !== process.env.GOOGLE_CLIENT_ID) {
      throw new AppError('Invalid client id', 400, codes.VALIDATION);
    }

    // The library enforces issuer accounts.google.com + audience on verifyIdToken.
    const client = new OAuth2Client(process.env.GOOGLE_CLIENT_ID);
    let payload;
    try {
      const ticket = await client.verifyIdToken({
        idToken: credential,
        audience: process.env.GOOGLE_CLIENT_ID,
      });
      payload = ticket.getPayload();
    } catch (err) {
      logger.warn({ err }, 'Invalid Google sign-in token');
      throw new AppError('Invalid Google sign-in token', 401, codes.UNAUTHORIZED);
    }

    // Only verified Google accounts with a string email are accepted.
    if (!payload || typeof payload.email !== 'string' || payload.email_verified !== true) {
      logger.warn(
        { email: payload?.email, email_verified: payload?.email_verified },
        'Google sign-in rejected: missing or unverified email'
      );
      throw new AppError('Invalid Google sign-in token', 401, codes.UNAUTHORIZED);
    }

    const email = payload.email.toLowerCase();
    const googleId = payload.sub;
    const name = (payload.name || email.split('@')[0]).slice(0, 100);
    const picture = payload.picture ? payload.picture.slice(0, 500) : null;

    // Role is derived server-side from the email domain — never trusted from
    // the client (the GIS flow sends no role at all).
    const role = await determineRole(email);

    const user = await db.withTransaction(async (client) => {
      // 1. Existing account by email → link the Google account, ROLE PRESERVED.
      const byEmail = await client.query(
        'SELECT id,name,email,role,email_verified,google_id,provider,avatar_url FROM users WHERE email=$1',
        [email]
      );
      if (byEmail.rows.length) {
        const updated = await client.query(
          `UPDATE users
           SET google_id=$1, provider='google', email_verified=true, avatar_url=COALESCE(avatar_url,$2)
           WHERE id=$3
           RETURNING id,name,email,role,email_verified,google_id,provider,avatar_url`,
          [googleId, picture, byEmail.rows[0].id]
        );
        return updated.rows[0];
      }

      // 2. Existing account by google_id (already linked previously).
      const byGoogleId = await client.query(
        'SELECT id,name,email,role,email_verified,google_id,provider,avatar_url FROM users WHERE google_id=$1',
        [googleId]
      );
      if (byGoogleId.rows.length) return byGoogleId.rows[0];

      // 3. New account — password_hash stays NULL (Google-only login).
      try {
        const inserted = await client.query(
          `INSERT INTO users (name,email,password_hash,role,email_verified,google_id,provider,avatar_url)
           VALUES($1,$2,NULL,$3,true,$4,'google',$5)
           RETURNING id,name,email,role,email_verified,google_id,provider,avatar_url`,
          [name, email, role, googleId, picture]
        );
        return inserted.rows[0];
      } catch (insertErr) {
        // Concurrent-registration race: another request created the row between
        // our SELECT and INSERT. Re-query by email and link it instead.
        if (insertErr.code === '23505') {
          const raced = await client.query(
            'SELECT id,name,email,role,email_verified,google_id,provider,avatar_url FROM users WHERE email=$1',
            [email]
          );
          if (raced.rows.length) {
            const updated = await client.query(
              `UPDATE users
               SET google_id=$1, provider='google', email_verified=true, avatar_url=COALESCE(avatar_url,$2)
               WHERE id=$3
               RETURNING id,name,email,role,email_verified,google_id,provider,avatar_url`,
              [googleId, picture, raced.rows[0].id]
            );
            return updated.rows[0];
          }
          throw new AppError('Email already registered', 409, codes.CONFLICT);
        }
        throw insertErr;
      }
    });

    const response = setAuthCookie(res, user);
    res.status(200).json(response);
  } catch (err) { next(err); }
};

exports.forgotPassword = async (req, res, next) => {
  try {
    const { email } = req.body;

    const result = await db.query('SELECT id, name FROM users WHERE email=$1', [email]);
    if (!result.rows.length) {
      throw new AppError('No account found with this email', 404, codes.NOT_FOUND);
    }
    const { name } = result.rows[0];

    const otp = generateOtp();
    await storeOtp(email, otp);

    let emailSent = false;
    try {
      await sendOtpEmail({ to: email, name, otp });
      emailSent = true;
    } catch (err) {
      logger.error({ err, email }, 'Failed to send OTP email — returning code in response');
    }

    const response = { message: 'Password reset code sent to your email' };
    if (!emailSent) {
      response.otp = otp;
      response.message = 'Email delivery failed. Use the OTP below to reset your password.';
    }
    res.json(response);
  } catch (err) { next(err); }
};

exports.resetPassword = async (req, res, next) => {
  try {
    const { email, otp, password } = req.body;

    const result = await verifyOtp(email, otp);
    if (!result.valid) {
      throw new AppError(result.reason, 400, codes.VALIDATION);
    }

    const existing = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (!existing.rows.length) {
      throw new AppError('No account found with this email', 404, codes.NOT_FOUND);
    }

    const hash = await bcrypt.hash(password, 10);
    // The OTP proves inbox ownership, so legacy unverified accounts are
    // unlocked here too (email_verified = true).
    await db.query(
      'UPDATE users SET password_hash = $1, email_verified = true WHERE email = $2',
      [hash, email]
    );

    res.json({ message: 'Password updated. Please sign in with your new password.' });
  } catch (err) { next(err); }
};

exports.me = async (req, res, next) => {
  try {
    let userId = req.user?.id;
    if (!userId) {
      const authHeader = req.headers?.authorization;
      const token = req.cookies?.ci_token || (authHeader && authHeader.split(' ')[1]);
      if (!token) return res.json(null);
      try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        if (decoded.jti) {
          const blacklisted = await db.query(
            'SELECT 1 FROM token_blacklist WHERE jti = $1 AND expires_at > NOW()',
            [decoded.jti]
          );
          if (blacklisted.rows.length) return res.json(null);
        }
        userId = decoded.id;
      } catch { return res.json(null); }
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
    if (!token) throw new AppError('Verification token is required', 400, codes.VALIDATION);

    const tokenHash = crypto.createHash('sha256').update(token).digest('hex');

    const result = await db.query(
      `SELECT id, email_verified, verification_token_expires FROM users
       WHERE verification_token = $1 AND email_verified = false`,
      [tokenHash]
    );

    if (!result.rows.length) {
      throw new AppError('Invalid or expired verification token', 400, codes.VALIDATION);
    }

    const user = result.rows[0];
    if (new Date() > new Date(user.verification_token_expires)) {
      throw new AppError('Verification token has expired. Please register again.', 400, codes.VALIDATION);
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
    const clearOpts = { ...COOKIE_OPTS };
    delete clearOpts.maxAge;
    res.clearCookie('ci_token', clearOpts);
    res.json({ loggedOut: true });
  } catch (err) { next(err); }
};

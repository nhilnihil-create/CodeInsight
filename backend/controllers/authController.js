const bcrypt = require('bcryptjs');
const jwt    = require('jsonwebtoken');
const db     = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

const COOKIE_OPTS = {
  httpOnly: true,
  sameSite: 'strict',
  secure: process.env.NODE_ENV === 'production',
  maxAge: 7 * 24 * 60 * 60 * 1000, // 7 days
  path: '/',
};

const generateToken = (user) =>
  jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role },
    process.env.JWT_SECRET,
    { expiresIn: '7d' }
  );

exports.register = async (req, res, next) => {
  try {
    const { name, email, password, role } = req.body;

    const exists = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (exists.rows.length) throw new AppError('Email already registered', 409, codes.CONFLICT);

    const hash = await bcrypt.hash(password, 10);
    const result = await db.query(
      'INSERT INTO users (name,email,password_hash,role) VALUES($1,$2,$3,$4) RETURNING id,name,email,role',
      [name, email, hash, role]
    );
    const user = result.rows[0];
    const token = generateToken(user);
    res.cookie('ci_token', token, COOKIE_OPTS);
    res.status(201).json({ user });
  } catch (err) { next(err); }
};

exports.login = async (req, res, next) => {
  try {
    const { email, password } = req.body;

    const result = await db.query(
      'SELECT id,name,email,role,password_hash FROM users WHERE email=$1', [email]
    );
    if (!result.rows.length) throw new AppError('Invalid credentials', 401, codes.UNAUTHORIZED);

    const user = result.rows[0];
    const valid = await bcrypt.compare(password, user.password_hash);
    if (!valid) throw new AppError('Invalid credentials', 401, codes.UNAUTHORIZED);

    const { password_hash, ...safeUser } = user;
    const token = generateToken(safeUser);
    res.cookie('ci_token', token, COOKIE_OPTS);
    res.json({ user: safeUser });
  } catch (err) { next(err); }
};

exports.me = async (req, res, next) => {
  try {
    const result = await db.query(
      'SELECT id,name,email,role FROM users WHERE id=$1', [req.user.id]
    );
    if (!result.rows.length) throw new AppError('User not found', 404, codes.NOT_FOUND);
    res.json(result.rows[0]);
  } catch (err) { next(err); }
};

exports.logout = async (req, res) => {
  // Clear the httpOnly auth cookie so the server actively invalidates the session.
  res.clearCookie('ci_token', { path: '/' });
  res.json({ loggedOut: true });
};

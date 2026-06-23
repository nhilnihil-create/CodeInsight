const jwt = require('jsonwebtoken');
const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

const verifyToken = async (req, _res, next) => {
  let token = req.cookies?.ci_token;
  if (!token) {
    const header = req.headers['authorization'];
    if (header) token = header.split(' ')[1];
  }
  if (!token) return next(new AppError('No token provided', 401, codes.UNAUTHORIZED));

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);

    if (decoded.jti) {
      const blacklisted = await db.query(
        'SELECT 1 FROM token_blacklist WHERE jti = $1 AND expires_at > NOW()',
        [decoded.jti]
      );
      if (blacklisted.rows.length) {
        return next(new AppError('Token has been revoked', 401, codes.UNAUTHORIZED));
      }
    }

    req.user = decoded;
    next();
  } catch (err) {
    if (err instanceof AppError) return next(err);
    return next(new AppError('Invalid or expired token', 401, codes.UNAUTHORIZED));
  }
};

const requireRole = (role) => (req, _res, next) => {
  if (req.user.role !== role) {
    return next(new AppError('Access denied: insufficient role', 403, codes.FORBIDDEN));
  }
  next();
};

const requireAnyRole = (...roles) => (req, _res, next) => {
  if (!roles.includes(req.user.role)) {
    return next(new AppError('Access denied: insufficient role', 403, codes.FORBIDDEN));
  }
  next();
};

module.exports = { verifyToken, requireRole, requireAnyRole };

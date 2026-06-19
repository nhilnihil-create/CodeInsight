const jwt = require('jsonwebtoken');
const { AppError, codes } = require('../lib/AppError');

const verifyToken = (req, _res, next) => {
  // Prefer httpOnly cookie (set by /api/auth/login), fall back to Authorization header
  // for backwards compatibility with any external tooling.
  let token = req.cookies?.ci_token;
  if (!token) {
    const header = req.headers['authorization'];
    if (header) token = header.split(' ')[1];
  }
  if (!token) return next(new AppError('No token provided', 401, codes.UNAUTHORIZED));

  try {
    req.user = jwt.verify(token, process.env.JWT_SECRET);
    next();
  } catch (err) {
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

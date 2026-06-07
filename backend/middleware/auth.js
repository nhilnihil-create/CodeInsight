const jwt = require('jsonwebtoken');
const { AppError, codes } = require('../lib/AppError');

const verifyToken = (req, _res, next) => {
  const header = req.headers['authorization'];
  if (!header) return next(new AppError('No token provided', 401, codes.UNAUTHORIZED));

  const token = header.split(' ')[1];
  if (!token) return next(new AppError('Token missing', 401, codes.UNAUTHORIZED));

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

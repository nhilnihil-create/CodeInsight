const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/authController');
const { verifyToken } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const { rateLimit } = require('express-rate-limit');
const v = require('../lib/validators');

// Bruteforce protection: max 5 login attempts per IP per 15 minutes.
const loginLimiter = rateLimit({
  windowMs: 15 * 60 * 1000,
  max: 5,
  standardHeaders: true,
  legacyHeaders: false,
  message: { message: 'Too many login attempts. Please try again in 15 minutes.' },
});

router.post('/register', validate.body(v.register), ctrl.register);
router.post('/login',    loginLimiter, validate.body(v.login), ctrl.login);
router.post('/logout',                              ctrl.logout);
router.get('/me',        verifyToken,               ctrl.me);

module.exports = router;

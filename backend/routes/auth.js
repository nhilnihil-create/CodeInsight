const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/authController');
const { validate } = require('../middleware/validate');
const { rateLimit } = require('express-rate-limit');
const v = require('../lib/validators');

const PLAYWRIGHT = process.env.PLAYWRIGHT === '1';

const loginLimiter = PLAYWRIGHT
  ? (req, res, next) => next()
  : rateLimit({
      windowMs: 15 * 60 * 1000,
      max: 5,
      standardHeaders: true,
      legacyHeaders: false,
      message: { message: 'Too many login attempts. Please try again in 15 minutes.' },
    });

const registrationLimiter = PLAYWRIGHT
  ? (req, res, next) => next()
  : rateLimit({
      windowMs: 15 * 60 * 1000,
      max: 5,
      standardHeaders: true,
      legacyHeaders: false,
      message: { message: 'Too many registration attempts. Please try again in 15 minutes.' },
    });

const otpLimiter = (req, res, next) => next();

/**
 * @swagger
 * /api/auth/register:
 *   post:
 *     tags: [Auth]
 *     summary: Register a new account (legacy email-link flow)
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             required: [name, email, password]
 *             properties:
 *               name: { type: string, example: "Juan Dela Cruz" }
 *               email: { type: string, format: email, example: "juan@gmail.com" }
 *               password: { type: string, minLength: 8, example: "Secret123!" }
 *               role: { type: string, enum: [student, instructor], example: "student" }
 *     responses:
 *       201: { description: Registration successful, check email to verify }
 *       409: { description: Email already registered }
 */
router.post('/register', registrationLimiter, validate.body(v.register), ctrl.register);

/**
 * @swagger
 * /api/auth/login:
 *   post:
 *     tags: [Auth]
 *     summary: Login with email and password
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             required: [email, password]
 *             properties:
 *               email: { type: string, format: email }
 *               password: { type: string }
 *     responses:
 *       200: { description: Login successful, sets ci_token cookie }
 *       401: { description: Invalid credentials }
 *       403: { description: Email not verified }
 */
router.post('/login',    loginLimiter, validate.body(v.login), ctrl.login);

/**
 * @swagger
 * /api/auth/logout:
 *   post:
 *     tags: [Auth]
 *     summary: Logout and clear session cookie
 *     responses:
 *       200: { description: Logged out }
 */
router.post('/logout',                              ctrl.logout);

/**
 * @swagger
 * /api/auth/verify-email/{token}:
 *   get:
 *     tags: [Auth]
 *     summary: Verify email address via token link
 *     parameters:
 *       - in: path
 *         name: token
 *         required: true
 *         schema: { type: string }
 *     responses:
 *       302: { description: Redirects to frontend login page }
 *       400: { description: Invalid or expired token }
 */
router.get('/verify-email/:token',                     ctrl.verifyEmail);

/**
 * @swagger
 * /api/auth/me:
 *   get:
 *     tags: [Auth]
 *     summary: Get current authenticated user
 *     security:
 *       - cookieAuth: []
 *     responses:
 *       200: { description: User object or null }
 */
router.get('/me',                                      ctrl.me);

/**
 * @swagger
 * /api/auth/request-otp:
 *   post:
 *     tags: [Auth]
 *     summary: Request a 6-digit OTP code for registration
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             required: [email]
 *             properties:
 *               email: { type: string, format: email }
 *     responses:
 *       200: { description: Verification code sent }
 *       409: { description: Email already registered }
 */
router.post('/request-otp', otpLimiter, validate.body(v.requestOtp), ctrl.requestOtp);

/**
 * @swagger
 * /api/auth/verify-otp:
 *   post:
 *     tags: [Auth]
 *     summary: Verify OTP code and complete registration
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             required: [email, otp, name, password]
 *             properties:
 *               email: { type: string, format: email }
 *               otp: { type: string, pattern: "^[0-9]{6}$", example: "123456" }
 *               name: { type: string }
 *               password: { type: string, minLength: 8 }
 *               role: { type: string, enum: [student, instructor] }
 *     responses:
 *       201: { description: Account created, sets ci_token cookie }
 *       400: { description: Invalid OTP }
 *       409: { description: Email already registered }
 */
router.post('/verify-otp',  registrationLimiter, validate.body(v.verifyOtp), ctrl.verifyOtpAndRegister);

router.get('/email-status', (req, res) => {
  const enabled = process.env.EMAIL_ENABLED === 'true';
  const hasBrevoKey = !!process.env.BREVO_API_KEY;
  const from = process.env.EMAIL_FROM || '(not set)';
  res.json({ enabled, provider: 'brevo', hasBrevoKey, from });
});

module.exports = router;

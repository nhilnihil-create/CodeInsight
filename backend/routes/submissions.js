const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/submissionController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const { rateLimit } = require('express-rate-limit');
const v = require('../lib/validators');

const submissionLimiter = rateLimit({
  windowMs: 60 * 1000,
  max: 10,
  standardHeaders: true,
  legacyHeaders: false,
  message: { message: 'Too many submissions. Please slow down.' },
});

router.post('/run',             submissionLimiter, verifyToken, requireRole('student'), validate.body(v.submitCode), ctrl.run);
router.post('/submit',          submissionLimiter, verifyToken, requireRole('student'), validate.body(v.submitCode), ctrl.submit);
router.post('/submit-async',    submissionLimiter, verifyToken, requireRole('student'), validate.body(v.submitCode), ctrl.submitAsync);
router.get('/status/:jobId',    verifyToken, requireRole('student'), ctrl.getJobStatus);
router.get('/:exerciseId/my',   verifyToken,                       ctrl.mySubmissions);
router.get('/:studentId/:exerciseId', verifyToken, requireRole('instructor'), ctrl.studentSubmissions);

module.exports = router;

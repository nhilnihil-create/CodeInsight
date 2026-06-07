const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/submissionController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

router.post('/run',             verifyToken, requireRole('student'), validate.body(v.submitCode), ctrl.run);
router.post('/submit',          verifyToken, requireRole('student'), validate.body(v.submitCode), ctrl.submit);
router.get('/:exerciseId/my',   verifyToken,                       ctrl.mySubmissions);
router.get('/:studentId/:exerciseId', verifyToken, requireRole('instructor'), ctrl.studentSubmissions);

module.exports = router;

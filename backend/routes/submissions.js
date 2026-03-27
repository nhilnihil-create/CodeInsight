const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/submissionController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.post('/run',          verifyToken, requireRole('student'), ctrl.run);
router.post('/submit',       verifyToken, requireRole('student'), ctrl.submit);
router.get('/:exerciseId/my', verifyToken, ctrl.mySubmissions);
router.get('/:studentId/:exerciseId', verifyToken, requireRole('instructor'), ctrl.studentSubmissions);

module.exports = router;

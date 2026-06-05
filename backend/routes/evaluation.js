const express = require('express');
const router = express.Router();
const { submitResponse, exportResponses } = require('../controllers/evaluationController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.post('/responses', verifyToken, submitResponse);
router.get('/export', verifyToken, requireRole('admin'), exportResponses);

module.exports = router;

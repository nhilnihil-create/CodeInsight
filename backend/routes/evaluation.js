const express = require('express');
const router  = express.Router();
const { submitResponse, exportResponses } = require('../controllers/evaluationController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

router.post('/responses', verifyToken,            validate.body(v.evaluationSubmit), submitResponse);
router.get('/export',     verifyToken, requireRole('admin'),                       exportResponses);

module.exports = router;

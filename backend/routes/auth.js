const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/authController');
const { verifyToken } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

router.post('/register', validate.body(v.register), ctrl.register);
router.post('/login',    validate.body(v.login),    ctrl.login);
router.post('/logout',                              ctrl.logout);
router.get('/me',        verifyToken,               ctrl.me);

module.exports = router;

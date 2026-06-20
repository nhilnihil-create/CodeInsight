const express = require('express');
const Joi     = require('joi');
const router  = express.Router();
const ctrl    = require('../controllers/adminConfigController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');

router.use(verifyToken, requireRole('admin'));

const updateSettingSchema = Joi.object({
  key: Joi.string().trim().min(1).max(100).required(),
  value: Joi.any().required(),
});

router.get('/settings', ctrl.listSettings);
router.put('/settings', validate.body(updateSettingSchema), ctrl.updateSettings);

module.exports = router;

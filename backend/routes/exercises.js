const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/exerciseController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

router.get('/concepts',    verifyToken,                                ctrl.getConcepts);
router.get('/bank',        verifyToken,                                ctrl.getBank);
router.get('/bank/:id',    verifyToken,                                ctrl.getBankOne);
router.post('/bulk-publish', verifyToken, requireRole('instructor'),   validate.body(v.bulkPublish), ctrl.bulkPublish);
router.post('/validate',     verifyToken, requireRole('instructor'),   validate.body(v.exerciseValidate), ctrl.validate);
router.post('/',           verifyToken, requireRole('instructor'),     validate.body(v.exerciseCreate), ctrl.create);
router.get('/',            verifyToken,                                ctrl.list);
router.get('/:id',         verifyToken,                                validate.params(v.idParam), ctrl.getOne);
router.put('/:id',         verifyToken, requireRole('instructor'),     validate.params(v.idParam), validate.body(v.exerciseUpdate), ctrl.update);
router.post('/:id/close',  verifyToken, requireRole('instructor'),     validate.params(v.idParam), ctrl.close);
router.post('/:id/reopen', verifyToken, requireRole('instructor'),     validate.params(v.idParam), ctrl.reopen);
router.delete('/:id',      verifyToken, requireRole('instructor'),     validate.params(v.idParam), ctrl.remove);

module.exports = router;

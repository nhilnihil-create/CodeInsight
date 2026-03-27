const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/exerciseController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.get('/concepts',    verifyToken, ctrl.getConcepts);
router.post('/',           verifyToken, requireRole('instructor'), ctrl.create);
router.get('/',            verifyToken, ctrl.list);
router.get('/:id',         verifyToken, ctrl.getOne);
router.put('/:id',         verifyToken, requireRole('instructor'), ctrl.update);
router.post('/:id/close',  verifyToken, requireRole('instructor'), ctrl.close);

module.exports = router;

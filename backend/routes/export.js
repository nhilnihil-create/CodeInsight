const express = require('express');
const router = express.Router();
const ctrl = require('../controllers/exportController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.get('/behavioral/:sectionId',   verifyToken, requireRole('instructor'), ctrl.exportBehavioral);
router.get('/cds/:sectionId',          verifyToken, requireRole('instructor'), ctrl.exportCDS);
router.get('/cds-snapshots/:sectionId', verifyToken, requireRole('instructor'), ctrl.exportCdsSnapshots);
router.get('/submissions/:sectionId',  verifyToken, requireRole('instructor'), ctrl.exportSubmissions);

module.exports = router;

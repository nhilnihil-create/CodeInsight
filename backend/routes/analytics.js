const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/analyticsController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.get('/heatmap/:sectionId',          verifyToken, requireRole('instructor'), ctrl.heatmap);
router.get('/alerts/:sectionId',           verifyToken, requireRole('instructor'), ctrl.getAlerts);
router.get('/activity/:sectionId',         verifyToken, requireRole('instructor'), ctrl.recentActivity);
router.put('/alerts/:alertId/review',      verifyToken, requireRole('instructor'), ctrl.reviewAlert);
router.get('/live/:exerciseId',            verifyToken, requireRole('instructor'), ctrl.liveRanking);
router.get('/live-cds/:exerciseId',        verifyToken, requireRole('instructor'), ctrl.liveCDS);
router.get('/student/:studentId/profile',  verifyToken, requireRole('instructor'), ctrl.studentProfile);
router.get('/my-scores',                   verifyToken, requireRole('student'),    ctrl.myScores);
router.get('/misconception/:exerciseId',   verifyToken, requireRole('instructor'), ctrl.classMisconceptionReport);
router.get('/longitudinal/:studentId/:conceptId', verifyToken, requireRole('instructor'), ctrl.longitudinalReport);

module.exports = router;

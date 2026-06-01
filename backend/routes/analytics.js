const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/analyticsController');
const { verifyToken, requireRole } = require('../middleware/auth');

// Existing endpoints
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

// NEW: Section-scoped analytics endpoints
router.get('/sections/:sectionId/micro-concept-alerts', verifyToken, requireRole('instructor'), ctrl.getMicroConceptAlerts);
router.put('/micro-concept-alerts/:alertId/mark-reviewed', verifyToken, requireRole('instructor'), ctrl.markMicroConceptAlertReviewed);

router.get('/sections/:sectionId/class-insights', verifyToken, requireRole('instructor'), ctrl.getClassInsights);
router.get('/sections/:sectionId/class-insights/:exerciseId', verifyToken, requireRole('instructor'), ctrl.getClassInsightsByExercise);

router.get('/sections/:sectionId/longitudinal', verifyToken, requireRole('instructor'), ctrl.getSectionLongitudinal);

router.get('/sections/:sectionId/integrity-flags', verifyToken, requireRole('instructor'), ctrl.getIntegrityFlags);
router.get('/sections/:sectionId/integrity-flags/:exerciseId', verifyToken, requireRole('instructor'), ctrl.getIntegrityFlagsByExercise);
router.put('/integrity-flags/:flagId/mark-reviewed', verifyToken, requireRole('instructor'), ctrl.markIntegrityFlagReviewed);

module.exports = router;

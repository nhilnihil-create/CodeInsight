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

// NEW: Section-scoped analytics endpoints
router.get('/sections/:sectionId/micro-concept-alerts', verifyToken, requireRole('instructor'), ctrl.getMicroConceptAlerts);
router.get('/alerts/:sectionId/micro-concepts', verifyToken, requireRole('instructor'), ctrl.getMicroConceptAlerts); // Alias

router.put('/micro-concept-alerts/:alertId/mark-reviewed', verifyToken, requireRole('instructor'), ctrl.markMicroConceptAlertReviewed);

router.get('/sections/:sectionId/class-insights', verifyToken, requireRole('instructor'), ctrl.getClassInsights);
router.get('/sections/:sectionId/class-insights/:exerciseId', verifyToken, requireRole('instructor'), ctrl.getClassInsightsByExercise);
router.get('/report/:exerciseId', verifyToken, requireRole('instructor'), ctrl.getClassInsightsByExercise); // Alias per docs

router.get('/sections/:sectionId/longitudinal', verifyToken, requireRole('instructor'), ctrl.getSectionLongitudinal);
router.get('/longitudinal/:studentId', verifyToken, requireRole('instructor'), ctrl.longitudinalReport);
router.get('/longitudinal/:studentId/:conceptId', verifyToken, requireRole('instructor'), ctrl.longitudinalReport);

// Command Center — cross-section analytics overview
router.get('/command', verifyToken, requireRole('instructor'), ctrl.getCommandCenter);

// Hub endpoint (spec §12)
router.get('/section/:id/hub', verifyToken, requireRole('instructor'), ctrl.getSectionHub);

// Reports endpoints
router.get('/reports/:sectionId/summary', verifyToken, requireRole('instructor'), ctrl.getReportSummary);
router.get('/reports/:sectionId/concept-mastery', verifyToken, requireRole('instructor'), ctrl.getConceptMasteryReport);
router.get('/reports/:sectionId/completion', verifyToken, requireRole('instructor'), ctrl.getCompletionReport);
router.get('/reports/:sectionId/engagement', verifyToken, requireRole('instructor'), ctrl.getEngagementReport);
router.get('/reports/:sectionId/integrity-trends', verifyToken, requireRole('instructor'), ctrl.getIntegrityTrends);

// Instructor Dashboard aggregate endpoint
router.get('/instructor/dashboard/:sectionId', verifyToken, requireRole('instructor'), ctrl.getInstructorDashboard);

// GAP #4: Structure Violations Report
router.get('/sections/:sectionId/structure-violations', verifyToken, requireRole('instructor'), ctrl.getStructureViolations);

// GAP #9: Class-Wide Micro-Concept Report
router.get('/sections/:sectionId/micro-concept-report', verifyToken, requireRole('instructor'), ctrl.getClassMicroConceptReport);

// Student detail (instructor view) — submissions across all exercises in section
router.get('/student/:studentId/submissions', verifyToken, requireRole('instructor'), ctrl.getStudentSubmissions);

// GAP: At-Risk Analytics Alerts (RETRY_STORM, LEARNING_PLATEAU)
router.get('/instructor/dashboard/alerts', verifyToken, requireRole('instructor'), ctrl.getDashboardAlerts);
router.put('/instructor/dashboard/alerts/:alertId/review', verifyToken, requireRole('instructor'), ctrl.reviewAnalyticsAlert);

module.exports = router;

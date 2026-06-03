const express = require('express');
const router = express.Router();
const integrityController = require('../controllers/integrityController');
const analyticsController = require('../controllers/analyticsController');
const { verifyToken, requireRole } = require('../middleware/auth');

// GET integrity flags (instructor only)
// Supports various frontend query patterns

// 1. Paginated responses (returns { flags: [], pagination: {} })
router.get('/integrity', verifyToken, requireRole('instructor'), integrityController.getIntegrityFlags);
router.get('/integrity-flags', verifyToken, requireRole('instructor'), integrityController.getIntegrityFlags);
router.get('/integrity-flags/:sectionId', verifyToken, requireRole('instructor'), integrityController.getIntegrityFlags);
router.get('/sections/:sectionId/integrity-flags', verifyToken, requireRole('instructor'), integrityController.getIntegrityFlags);

// 2. Array responses (returns [] - preferred for small UI components like dropdowns)
router.get('/integrity-flags/exercise/:exerciseId', verifyToken, requireRole('instructor'), analyticsController.getIntegrityFlagsByExercise);
router.get('/sections/:sectionId/integrity-flags/:exerciseId', verifyToken, requireRole('instructor'), analyticsController.getIntegrityFlagsByExercise);

// Review or dismiss an integrity flag (instructor only)
// Supports both 'review' and 'mark-reviewed' for frontend compatibility
router.put('/integrity-flags/:flagId/review', verifyToken, requireRole('instructor'), integrityController.reviewIntegrityFlag);
router.put('/integrity-flags/:flagId/mark-reviewed', verifyToken, requireRole('instructor'), integrityController.reviewIntegrityFlag);

module.exports = router;
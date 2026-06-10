const express = require('express');
const router = express.Router();
const ctrl = require('../controllers/searchController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.get('/exercises',       verifyToken, ctrl.searchExercises);
router.get('/exercises/:id',   verifyToken, ctrl.getExercise);
router.get('/concepts',        verifyToken, ctrl.listConcepts);
router.get('/concepts/:conceptId/exercises', verifyToken, ctrl.getExercisesByConcept);

module.exports = router;

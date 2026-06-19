const express = require('express');
const router = express.Router();
const ctrl = require('../controllers/customTagsController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.use(verifyToken, requireRole('instructor'));

router.get('/',                    ctrl.list);
router.post('/',                   ctrl.create);
router.get('/exercise-mappings',    ctrl.getExerciseMappings);
router.post('/map-to-exercise',     ctrl.mapTagsToExercise);
router.put('/:tagId',               ctrl.update);
router.delete('/:tagId',           ctrl.remove);
router.get('/:tagId/exercises',    ctrl.listMappedExercises);
router.post('/:tagId/exercises',   ctrl.mapExercises);
router.delete('/:tagId/exercises/:exerciseId', ctrl.unmapExercise);

module.exports = router;

const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/sectionController');
const { verifyToken, requireRole } = require('../middleware/auth');

router.post('/',                       verifyToken, requireRole('instructor'), ctrl.create);
router.get('/',                        verifyToken, ctrl.list);
router.get('/:id',                     verifyToken, ctrl.getOne);
router.post('/:id/enroll',             verifyToken, requireRole('instructor'), ctrl.enroll);
router.delete('/:id/enroll/:studentId',verifyToken, requireRole('instructor'), ctrl.unenroll);
router.get('/:id/students',            verifyToken, ctrl.getStudents);
router.get('/:section_id/students-with-scores', verifyToken, requireRole('instructor'), ctrl.getStudentsWithScores);
router.get('/:section_id/exercises',   verifyToken, requireRole('instructor'), ctrl.getSectionExercises);

module.exports = router;

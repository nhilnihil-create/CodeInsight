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

// New section management endpoints (spec §11.6)
router.post('/join',                   verifyToken, requireRole('student'),    ctrl.joinSection);
router.post('/:id/rotate-code',        verifyToken, requireRole('instructor'), ctrl.rotateCode);
router.post('/:id/memberships',        verifyToken, requireRole('instructor'), ctrl.addMembership);
router.patch('/:id/memberships/:mid',  verifyToken, requireRole('instructor'), ctrl.updateMembership);
router.post('/bulk-import',            verifyToken, requireRole('instructor'), ctrl.bulkImport);
router.get('/:id/audit',               verifyToken, requireRole('instructor'), ctrl.getAuditLog);
router.get('/audit/all',               verifyToken, requireRole('admin'),      ctrl.getDeptAudit);
router.patch('/:id/policy',            verifyToken, requireRole('instructor'), ctrl.updatePolicy);

module.exports = router;

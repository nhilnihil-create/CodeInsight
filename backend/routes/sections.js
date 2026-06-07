const express = require('express');
const router  = express.Router();
const ctrl    = require('../controllers/sectionController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

router.post('/',                        verifyToken, requireRole('instructor'), validate.body(v.sectionCreate),       ctrl.create);
router.get('/',                         verifyToken,                                ctrl.list);
router.get('/:id',                      verifyToken,                                validate.params(v.idParam),        ctrl.getOne);
router.post('/:id/enroll',              verifyToken, requireRole('instructor'),     validate.body(v.enrollPayload),    validate.params(v.idParam), ctrl.enroll);
router.delete('/:id/enroll/:studentId', verifyToken, requireRole('instructor'),     validate.params(v.idParam),        ctrl.unenroll);
router.get('/:id/students',             verifyToken,                                validate.params(v.idParam),        ctrl.getStudents);
router.get('/:section_id/students-with-scores', verifyToken, requireRole('instructor'), ctrl.getStudentsWithScores);
router.get('/:section_id/exercises',    verifyToken, requireRole('instructor'),     ctrl.getSectionExercises);

// New section management endpoints (spec §11.6)
router.post('/join',                    verifyToken, requireRole('student'),        validate.body(v.joinByCode),        ctrl.joinSection);
router.post('/:id/rotate-code',         verifyToken, requireRole('instructor'),     validate.params(v.idParam),        ctrl.rotateCode);
router.post('/:id/memberships',         verifyToken, requireRole('instructor'),     validate.body(v.membershipUpdate), validate.params(v.idParam), ctrl.addMembership);
router.patch('/:id/memberships/:mid',   verifyToken, requireRole('instructor'),     validate.body(v.membershipUpdate), validate.params(v.idParam), ctrl.updateMembership);
router.post('/bulk-import',             verifyToken, requireRole('instructor'),     validate.body(v.bulkImportCSV),     ctrl.bulkImport);
router.get('/:id/audit',                verifyToken, requireRole('instructor'),     validate.params(v.idParam),        ctrl.getAuditLog);
router.get('/audit/all',                verifyToken, requireRole('admin'),          ctrl.getDeptAudit);
router.patch('/:id/policy',             verifyToken, requireRole('instructor'),     validate.body(v.policyUpdate),     validate.params(v.idParam), ctrl.updatePolicy);

module.exports = router;

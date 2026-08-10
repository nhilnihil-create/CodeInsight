const express = require('express');
const router  = express.Router();
const multer = require('multer');
const path    = require('path');
const ctrl    = require('../controllers/sectionController');
const uploadCtrl = require('../controllers/UploadsController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

// ── Multer config (shared between import & export routes) ─────────────────
const upload = multer({
  storage: multer.memoryStorage(),
  fileFilter: (_req, file, cb) => {
    const ext = path.extname(file.originalname).toLowerCase();
    if (['.csv', '.xlsx'].includes(ext)) return cb(null, true);
    cb(new Error(`Invalid file type: ${ext}. Only .csv and .xlsx files are accepted.`));
  },
  limits: { fileSize: 10 * 1024 * 1024, files: 1 },
});

router.post('/',                        verifyToken, requireRole('instructor'), validate.body(v.sectionCreate),       ctrl.create);
router.get('/',                         verifyToken,                                ctrl.list);
router.get('/students-all', verifyToken, requireRole('instructor'), ctrl.getStudentsAcrossSections);
router.get('/:id',                      verifyToken,                                validate.params(v.idParam),        ctrl.getOne);
router.post('/:id/enroll',              verifyToken, requireRole('instructor'),     validate.body(v.enrollPayload),    validate.params(v.idParam), ctrl.enroll);
router.delete('/:id/enroll/:studentId', verifyToken, requireRole('instructor'),     validate.params(v.enrollParams),    ctrl.unenroll);
router.get('/:id/students',             verifyToken,                                validate.params(v.idParam),        ctrl.getStudents);
router.get('/:section_id/students-with-scores', verifyToken, requireRole('instructor'), ctrl.getStudentsWithScores);
router.get('/:section_id/exercises',    verifyToken, requireRole('instructor'),     ctrl.getSectionExercises);

// New section management endpoints (spec §11.6)
router.post('/join',                    verifyToken, requireRole('student'),        validate.body(v.joinByCode),        ctrl.joinSection);
router.post('/:id/leave',               verifyToken, requireRole('student'),        validate.params(v.idParam),        ctrl.leaveSection);
router.post('/:id/rotate-code',         verifyToken, requireRole('instructor'),     validate.params(v.idParam),        ctrl.rotateCode);
router.post('/:id/memberships',         verifyToken, requireRole('instructor'),     validate.body(v.membershipUpdate), validate.params(v.idParam), ctrl.addMembership);
router.patch('/:id/memberships/:mid',   verifyToken, requireRole('instructor'),     validate.body(v.membershipUpdate), validate.params(v.idParam), ctrl.updateMembership);
// File-based roster import (CSV/XLSX) — replaces JSON-only bulkImport
router.post('/:id/bulk-import',       verifyToken, requireRole('instructor'), (req, res, next) => {
  upload.single('file')(req, res, (err) => {
    if (err) {
      if (err.message && err.message.includes('file type')) return res.status(400).json({ error: err.message });
      if (err.code === 'LIMIT_FILE_SIZE') return res.status(413).json({ error: 'File too large. Maximum is 10 MB.' });
      return res.status(400).json({ error: err.message });
    }
    next();
  });
}, uploadCtrl.importRoster);

// Rich Excel export — GET /api/sections/:id/export
router.get('/:id/export',             verifyToken, requireRole('instructor'), validate.params(v.idParam), uploadCtrl.exportRoster);
router.get('/:id/audit',                verifyToken, requireRole('instructor'),     validate.params(v.idParam),        ctrl.getAuditLog);
router.get('/audit/all',                verifyToken, requireRole('admin'),          ctrl.getDeptAudit);
router.put('/:id',                      verifyToken, requireRole('instructor'),     ctrl.update);
router.delete('/:id',                   verifyToken, requireRole('instructor'),     validate.params(v.idParam),        ctrl.delete);
router.patch('/:id/policy',             verifyToken, requireRole('instructor'),     validate.body(v.policyUpdate),     validate.params(v.idParam), ctrl.updatePolicy);
module.exports = router;

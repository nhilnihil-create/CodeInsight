const express = require('express');
const Joi     = require('joi');
const router  = express.Router();
const ctrl    = require('../controllers/adminController');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const v = require('../lib/validators');

// All admin routes require an authenticated admin user
router.use(verifyToken, requireRole('admin'));

// Overview
router.get('/overview', ctrl.overview);

// Users
const userListQuery = Joi.object({
  role: Joi.string().valid('instructor', 'student', 'admin').optional(),
  search: Joi.string().max(200).optional(),
  limit: Joi.number().integer().min(1).max(500).default(100),
  offset: Joi.number().integer().min(0).default(0),
});
router.get('/users',                validate.query(userListQuery), ctrl.listUsers);
router.post('/users',               validate.body(v.adminUserCreate), ctrl.createUser);
router.put('/users/:id',            validate.params(v.idParam), validate.body(v.adminUserUpdate), ctrl.updateUser);
router.delete('/users/:id',         validate.params(v.idParam), ctrl.deleteUser);
router.put('/users/:id/reset-password', validate.params(v.idParam), validate.body(v.adminPasswordReset), ctrl.resetPassword);

// Sections
router.get('/sections',             ctrl.listSections);
router.put('/sections/:id',         validate.params(v.idParam), validate.body(v.adminSectionUpdate), ctrl.updateSection);
router.delete('/sections/:id',      validate.params(v.idParam), ctrl.deleteSection);

// Concepts
router.get('/concepts',             ctrl.listConcepts);
router.post('/concepts',            validate.body(v.adminConceptCreate), ctrl.createConcept);
router.delete('/concepts/:id',      validate.params(v.idParam), ctrl.deleteConcept);
router.put('/concepts/:id',         validate.params(v.idParam), validate.body(v.adminConceptUpdate), ctrl.updateConcept);

// Exercises
router.get('/exercises',            ctrl.listExercises);
router.patch('/exercises/:id',      validate.params(v.idParam), ctrl.toggleExercise);

// Evaluation
router.get('/evaluation',           ctrl.listEvaluation);

module.exports = router;

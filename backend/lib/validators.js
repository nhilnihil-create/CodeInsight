const Joi = require('joi');

const email = Joi.string().trim().lowercase().email({ tlds: { allow: false } });
const password = Joi.string()
  .min(8).max(128)
  .pattern(/[A-Z]/, 'uppercase')
  .pattern(/[a-z]/, 'lowercase')
  .pattern(/[0-9]/, 'digit')
  .pattern(/[^a-zA-Z0-9]/, 'special')
  .message('Password must be at least 8 characters with uppercase, lowercase, digit, and special character');
const name = Joi.string().trim().min(1).max(100);
const id = Joi.number().integer().positive();
const role = Joi.string().valid('instructor', 'student');

const testCase = Joi.object({
  input: Joi.string().allow('').default(''),
  expectedOutput: Joi.string().allow('').default(''),
  validationType: Joi.string().valid('exact', 'contains', 'regex').default('exact'),
  isVisible: Joi.boolean().default(true),
  // Backward compatibility: accept legacy 'expected' and 'hidden' fields
  expected: Joi.string().allow('').optional(),
  hidden: Joi.boolean().optional(),
  description: Joi.string().allow('').max(500).optional(),
});

const exerciseCreate = Joi.object({
  title: Joi.string().trim().min(1).max(200).required(),
  description: Joi.string().allow('').max(20000).default(''),
  concept_name: Joi.string().trim().min(1).max(100).required(),
  section_id: id.required(),
  time_limit_minutes: Joi.number().integer().min(0).max(600).default(45),
  test_cases: Joi.array().items(testCase).min(1).required(),
  deadline: Joi.alternatives(Joi.date().iso(), Joi.string().allow(null, ''), Joi.allow(null)).optional(),
  is_draft: Joi.boolean().default(false),
  track_ner: Joi.boolean().default(true),
  track_nrs: Joi.boolean().default(true),
  track_nts: Joi.boolean().default(true),
  auto_alert: Joi.boolean().default(true),
  starter_code: Joi.string().allow('', null).max(20000).optional(),
  reference_solution: Joi.string().allow('', null).max(20000).optional(),
  concept_ids: Joi.array().items(Joi.string().trim().min(1).max(100)).optional(), // secondary concepts
});

const exerciseUpdate = Joi.object({
  title: Joi.string().trim().min(1).max(200).optional(),
  description: Joi.string().allow('').max(20000).optional(),
  time_limit_minutes: Joi.number().integer().min(0).max(600).optional(),
  test_cases: Joi.array().items(testCase).min(1).optional(),
  deadline: Joi.alternatives(Joi.date().iso(), Joi.string().allow(null, ''), Joi.allow(null)).optional(),
  is_draft: Joi.boolean().optional(),
  track_ner: Joi.boolean().optional(),
  track_nrs: Joi.boolean().optional(),
  track_nts: Joi.boolean().optional(),
  auto_alert: Joi.boolean().optional(),
  starter_code: Joi.string().allow('', null).max(20000).optional(),
});

const sectionCreate = Joi.object({
  name: Joi.string().trim().min(1).max(150).required(),
  course_code: Joi.string().trim().min(1).max(50).required(),
  school_year: Joi.string().trim().max(30).allow('').optional(),
  term: Joi.string().trim().max(30).allow('').optional(),
  semester: Joi.string().trim().max(30).allow('').optional(),
  join_policy: Joi.string().valid('code', 'request', 'closed').default('code'),
  max_size: Joi.number().integer().min(1).max(500).default(60),
});

const enrollPayload = Joi.object({
  student_ids: Joi.array().items(id).min(1).optional(),
  emails: Joi.array().items(email).min(1).optional(),
}).or('student_ids', 'emails');

const membershipUpdate = Joi.object({
  status: Joi.string().valid('active', 'pending', 'denied', 'dropped', 'left_requested', 'left').required(),
  drop_reason: Joi.string().trim().min(1).max(500).when('status', {
    is: 'dropped',
    then: Joi.required(),
    otherwise: Joi.optional().allow('', null),
  }),
});

const policyUpdate = Joi.object({
  join_policy: Joi.string().valid('code', 'request', 'closed').required(),
});

const joinByCode = Joi.object({
  code: Joi.string().trim().min(1).max(50).required(),
});

const submitCode = Joi.object({
  exerciseId: Joi.number().integer().positive().required(),
  code: Joi.string().required(),
  timeSpentSeconds: Joi.number().integer().min(0).max(86400).default(0),
});

const evaluationSubmit = Joi.object({
  fs_1: Joi.number().integer().min(1).max(4).required(),
  fs_2: Joi.number().integer().min(1).max(4).required(),
  fs_3: Joi.number().integer().min(1).max(4).required(),
  fs_4: Joi.number().integer().min(1).max(4).required(),
  us_1: Joi.number().integer().min(1).max(4).required(),
  us_2: Joi.number().integer().min(1).max(4).required(),
  us_3: Joi.number().integer().min(1).max(4).required(),
  us_4: Joi.number().integer().min(1).max(4).required(),
  us_5: Joi.number().integer().min(1).max(4).required(),
  pe_1: Joi.number().integer().min(1).max(4).required(),
  pe_2: Joi.number().integer().min(1).max(4).required(),
  pe_3: Joi.number().integer().min(1).max(4).required(),
  feedback_text: Joi.string().allow('').max(5000).optional(),
});

const register = Joi.object({
  name: name.required(),
  email: email.required(),
  password: password.required(),
  role: role.required(),
});

const login = Joi.object({
  email: email.required(),
  password: password.required(),
});

const idParam = Joi.object({ id: id.required() });
const enrollParams = Joi.object({ id: id.required(), studentId: id.required() });

const adminUserUpdate = Joi.object({
  name: name.optional(),
  email: email.optional(),
  role: role.optional(),
});

const adminUserCreate = Joi.object({
  name: name.required(),
  email: email.required(),
  password: password.required(),
  role: role.required(),
});

const adminSectionUpdate = Joi.object({
  name: Joi.string().trim().min(1).max(150).optional(),
  course_code: Joi.string().trim().min(1).max(50).optional(),
  school_year: Joi.string().trim().max(30).allow('').optional(),
  term: Joi.string().trim().max(30).allow('').optional(),
  join_policy: Joi.string().valid('code', 'request', 'closed').optional(),
  max_size: Joi.number().integer().min(1).max(500).optional(),
});

const adminConceptCreate = Joi.object({
  name: Joi.string().trim().min(1).max(100).required(),
  ast_nodes: Joi.array().items(Joi.string()).default([]),
});

const adminConceptUpdate = Joi.object({
  name: Joi.string().trim().min(1).max(100).optional(),
  ast_nodes: Joi.array().items(Joi.string()).optional(),
  knowledge_area_code: Joi.string().trim().max(20).optional().allow('', null),
  bloom_level: Joi.string().valid('remember', 'understand', 'apply', 'analyze', 'evaluate', 'create').optional(),
});

const rosterImportRows = Joi.object({
  rows: Joi.array().items(
    Joi.object({
      email: email.required(),
      name: name.required(),
    })
  ).min(1).max(2000).required(),
  create_missing_users: Joi.boolean().default(false),
});

const bulkImportCSV = Joi.object({
  rows: Joi.array().items(
    Joi.object({
      email: email.required(),
      name: Joi.string().trim().min(1).max(100).optional(),
    })
  ).min(1).max(500).required(),
  create_missing_users: Joi.boolean().default(false),
});

const bulkPublish = Joi.object({
  section_id: id.required(),
  bank_ids: Joi.array().items(Joi.number().integer().positive()).min(1).max(50).required(),
  deadline: Joi.alternatives(Joi.date().iso(), Joi.string().allow(null, '')).optional(),
  time_limit_overrides: Joi.object().pattern(
    Joi.number().integer().positive(),
    Joi.number().integer().min(1).max(600)
  ).optional(),
});

const adminPasswordReset = Joi.object({
  password: Joi.string().min(8).max(128).required(),
});

const exerciseValidate = Joi.object({
  reference_solution: Joi.string().trim().min(1).max(20000).required(),
  test_cases: Joi.array().items(testCase).min(1).required(),
  time_limit_minutes: Joi.number().integer().min(0).max(600).default(45),
});

module.exports = {
  email, password, name, id, role, testCase,
  exerciseCreate, exerciseUpdate,
  sectionCreate, enrollPayload, membershipUpdate, policyUpdate, joinByCode,
  submitCode, evaluationSubmit, register, login, idParam, enrollParams,
  adminUserCreate, adminUserUpdate, adminSectionUpdate, adminConceptCreate, adminConceptUpdate,
  bulkImportCSV, rosterImportRows,
  bulkPublish, exerciseValidate, adminPasswordReset,
};

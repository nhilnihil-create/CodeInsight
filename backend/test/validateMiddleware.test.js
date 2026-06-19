const Joi = require('joi');
const { validate } = require('../middleware/validate');

const testSchema = Joi.object({
  name: Joi.string().required(),
  age: Joi.number().integer().min(0).max(150),
});

function mockNext() {
  return jest.fn();
}

function mockReq(body, query, params) {
  return { body: body || {}, query: query || {}, params: params || {} };
}

const mockRes = {};

describe('validate.body', function() {
  it('passes valid body through', function() {
    const req = mockReq({ name: 'Alice', age: 25 });
    const next = mockNext();
    validate.body(testSchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.body).toEqual({ name: 'Alice', age: 25 });
  });

  it('strips unknown fields', function() {
    const req = mockReq({ name: 'Bob', age: 30, extra: 'should be stripped' });
    const next = mockNext();
    validate.body(testSchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.body).toEqual({ name: 'Bob', age: 30 });
    expect(req.body.extra).toBeUndefined();
  });

  it('converts types', function() {
    const req = mockReq({ name: 'Charlie', age: '42' });
    const next = mockNext();
    validate.body(testSchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.body.age).toBe(42);
  });

  it('calls next with error on missing required field', function() {
    const req = mockReq({ age: 25 });
    const next = mockNext();
    validate.body(testSchema)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err).toBeDefined();
    expect(err.isJoi).toBe(true);
    expect(err.details[0].path).toContain('name');
  });

  it('calls next with error on invalid type', function() {
    const req = mockReq({ name: 'Dave', age: 'not-a-number' });
    const next = mockNext();
    validate.body(testSchema)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err.isJoi).toBe(true);
  });

  it('calls next with error on out-of-range value', function() {
    const req = mockReq({ name: 'Eve', age: 200 });
    const next = mockNext();
    validate.body(testSchema)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err.isJoi).toBe(true);
  });

  it('uses default values from schema', function() {
    const schemaWithDefault = Joi.object({
      role: Joi.string().default('student'),
      name: Joi.string().required(),
    });
    const req = mockReq({ name: 'Frank' });
    const next = mockNext();
    validate.body(schemaWithDefault)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.body.role).toBe('student');
  });

  it('reports all errors with abortEarly: false', function() {
    const multiField = Joi.object({
      a: Joi.string().required(),
      b: Joi.string().required(),
      c: Joi.number().required(),
    });
    const req = mockReq({ a: 'ok' });
    const next = mockNext();
    validate.body(multiField)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err.details.length).toBe(2);
  });

  it('passes when body is empty but no required fields', function() {
    const optionalSchema = Joi.object({
      optional: Joi.string().optional(),
    });
    const req = mockReq({});
    const next = mockNext();
    validate.body(optionalSchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
  });
});

describe('validate.query', function() {
  it('passes valid query params', function() {
    const req = mockReq({}, { page: '1', limit: '20' });
    const next = mockNext();
    const querySchema = Joi.object({
      page: Joi.number().integer().min(1).default(1),
      limit: Joi.number().integer().min(1).max(100).default(20),
    });
    validate.query(querySchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.query.page).toBe(1);
    expect(req.query.limit).toBe(20);
  });

  it('calls next with error on invalid query', function() {
    const req = mockReq({}, { limit: 'abc' });
    const next = mockNext();
    const querySchema = Joi.object({
      limit: Joi.number().integer().min(1).max(100),
    });
    validate.query(querySchema)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err.isJoi).toBe(true);
  });

  it('strips unknown query params', function() {
    const req = mockReq({}, { known: 'val', unknown: 'should-go' });
    const next = mockNext();
    const querySchema = Joi.object({ known: Joi.string() });
    validate.query(querySchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.query.known).toBe('val');
    expect(req.query.unknown).toBeUndefined();
  });
});

describe('validate.params', function() {
  it('passes valid params', function() {
    const req = mockReq({}, {}, { id: '42' });
    const next = mockNext();
    const paramSchema = Joi.object({ id: Joi.number().integer().positive().required() });
    validate.params(paramSchema)(req, mockRes, next);
    expect(next).toHaveBeenCalledWith();
    expect(req.params.id).toBe(42);
  });

  it('calls next with error on invalid params', function() {
    const req = mockReq({}, {}, { id: '-1' });
    const next = mockNext();
    const paramSchema = Joi.object({ id: Joi.number().integer().positive().required() });
    validate.params(paramSchema)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err.isJoi).toBe(true);
  });

  it('calls next with error on missing params', function() {
    const req = mockReq({}, {}, {});
    const next = mockNext();
    const paramSchema = Joi.object({ id: Joi.number().required() });
    validate.params(paramSchema)(req, mockRes, next);
    const err = next.mock.calls[0][0];
    expect(err.isJoi).toBe(true);
  });
});

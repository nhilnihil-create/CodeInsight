const { AppError, codes } = require('../lib/AppError');

/**
 * Joi-based request validation middleware factory.
 *
 *   router.post('/foo', validate.body(schema), handler)
 *   router.get('/foo',  validate.query(schema), handler)
 *   router.post('/foo', validate.params(schema), handler)
 *
 * On failure, throws a Joi-style error; the global error middleware
 * converts it to a 400 with `{ code: 'VALIDATION_ERROR', details: [...] }`.
 */
const validate = {
  body: (schema) => (req, _res, next) => {
    const { error, value } = schema.validate(req.body, { abortEarly: false, stripUnknown: true, convert: true });
    if (error) return next(error);
    req.body = value;
    next();
  },
  query: (schema) => (req, _res, next) => {
    const { error, value } = schema.validate(req.query, { abortEarly: false, stripUnknown: true, convert: true });
    if (error) return next(error);
    req.query = value;
    next();
  },
  params: (schema) => (req, _res, next) => {
    const { error, value } = schema.validate(req.params, { abortEarly: false, stripUnknown: true, convert: true });
    if (error) return next(error);
    req.params = value;
    next();
  },
};

module.exports = { validate, AppError, codes };

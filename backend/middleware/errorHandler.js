const { AppError } = require('../lib/AppError');

/**
 * Build the unified error envelope:
 *   { code, message, details? }
 *
 * Mounted LAST in the middleware chain so it catches:
 *   - thrown AppError
 *   - thrown Error (with .status)
 *   - Postgres unique violation (23505)
 *   - Postgres FK violation (23503)
 *   - anything else (500)
 */
function errorHandler(err, req, res, next) {
  // Unknown route — should be hit by the 404 handler instead, but kept safe.
  if (err && err.type === 'entity.parse.failed') {
    return res.status(400).json({
      code: 'INVALID_JSON',
      message: 'Invalid JSON in request body',
    });
  }

  // AppError (our own)
  if (err instanceof AppError) {
    const body = { code: err.code, message: err.message };
    if (err.details) body.details = err.details;
    return res.status(err.status).json(body);
  }

  // Error with explicit status (e.g. thrown with res.status in mind)
  if (err && typeof err.status === 'number' && err.status >= 400 && err.status < 600) {
    return res.status(err.status).json({
      code: err.code || 'ERROR',
      message: err.message || 'Request failed',
    });
  }

  // Postgres unique violation
  if (err && err.code === '23505') {
    return res.status(409).json({
      code: 'CONFLICT',
      message: 'Resource already exists',
      details: err.detail,
    });
  }

  // Postgres FK violation
  if (err && err.code === '23503') {
    return res.status(400).json({
      code: 'FK_VIOLATION',
      message: 'Referenced resource does not exist',
      details: err.detail,
    });
  }

  // Postgres check violation
  if (err && err.code === '23514') {
    return res.status(400).json({
      code: 'CHECK_VIOLATION',
      message: 'Value violates a check constraint',
      details: err.detail,
    });
  }

  // Joi validation (set by middleware/validate.js)
  if (err && err.isJoi) {
    return res.status(400).json({
      code: 'VALIDATION_ERROR',
      message: 'Invalid request body',
      details: err.details?.map((d) => ({ path: d.path.join('.'), message: d.message })) || [],
    });
  }

  // Fallback — internal error. Log full stack but never leak to client.
  // eslint-disable-next-line no-console
  console.error('[unhandled error]', err);
  return res.status(500).json({
    code: 'INTERNAL_ERROR',
    message: 'An internal server error occurred',
  });
}

/**
 * 404 handler. Mounted AFTER all routes.
 */
function notFoundHandler(req, res) {
  res.status(404).json({
    code: 'NOT_FOUND',
    message: `Route ${req.method} ${req.originalUrl} not found`,
  });
}

module.exports = { errorHandler, notFoundHandler };

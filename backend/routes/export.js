const express = require('express');
const Joi = require('joi');
const router = express.Router();
const logger = require('../lib/logger');
const { AppError, codes } = require('../lib/AppError');
const { verifyToken, requireRole } = require('../middleware/auth');
const { validate } = require('../middleware/validate');
const exportService = require('../services/exportService');
const { buildSectionVisualReport } = require('../services/pdfReport');

const sectionIdParam = Joi.object({
  sectionId: Joi.number().integer().positive().required(),
});

const domainParams = Joi.object({
  domain: Joi.string().required(),
  sectionId: Joi.number().integer().positive().required(),
});

const rangeQuery = {
  startDate: Joi.date().iso().allow('', null).optional(),
  endDate: Joi.date().iso().allow('', null).optional(),
  studentId: Joi.number().integer().positive().optional(),
};

const canonicalQuery = Joi.object({
  format: Joi.string().valid('csv', 'xlsx', 'json').default('csv'),
  ...rangeQuery,
});

// Legacy alias keeps only the formats it has always supported.
const legacyQuery = Joi.object({
  format: Joi.string().valid('csv', 'xlsx').default('csv'),
  ...rangeQuery,
});

function buildOpts(query) {
  const opts = {};
  if (query.startDate) opts.startDate = query.startDate;
  if (query.endDate) opts.endDate = query.endDate;
  if (query.studentId) opts.studentId = query.studentId;
  return opts;
}

/**
 * Legacy alias — GET /api/export/section/:sectionId
 * Kept for Reports.jsx. Same 7-column shape as the pre-overhaul endpoint
 * (submissions domain with opts.legacyShape), with the documented fixes:
 * ISO-8601 dates, UTF-8 BOM, ownership guard.
 * Must be registered BEFORE /:domain/:sectionId so `/section` isn't treated
 * as a domain.
 */
router.get(
  '/section/:sectionId',
  verifyToken,
  requireRole('instructor'),
  validate.params(sectionIdParam),
  validate.query(legacyQuery),
  async (req, res, next) => {
    try {
      const { sectionId } = req.params;
      await exportService.assertInstructorOwnsSection(sectionId, req.user.id);

      const { buffer, mimeType, filename } = await exportService.formatExport(
        'submissions',
        sectionId,
        req.query.format,
        { ...buildOpts(req.query), legacyShape: true }
      );

      exportService.setDownloadHeaders(res, filename, mimeType);
      return res.send(buffer);
    } catch (err) {
      logger.error({ err }, 'Export (legacy) failed');
      next(err);
    }
  }
);

/**
 * Visual report (PDF) — GET /api/export/visual-report/:sectionId
 * Full class report by default; pass ?studentId=N for a single-student
 * dossier. Must be registered BEFORE /:domain/:sectionId so 'visual-report'
 * is not parsed as a domain. buildSectionVisualReport resolves the
 * instructor name internally (cover page), so no extra lookup happens here.
 */
router.get(
  '/visual-report/:sectionId',
  verifyToken,
  requireRole('instructor'),
  validate.params(sectionIdParam),
  validate.query(Joi.object({ studentId: Joi.number().integer().positive().optional() })),
  async (req, res, next) => {
    try {
      const { sectionId } = req.params;
      await exportService.assertInstructorOwnsSection(sectionId, req.user.id);

      const buffer = await buildSectionVisualReport(sectionId, {
        studentId: req.query.studentId,
      });

      const meta = await exportService.getSectionMeta(sectionId);
      const filename = exportService.buildExportFilename({
        sectionName: meta && meta.name,
        domain: 'visual-report',
        ext: 'pdf',
      });
      exportService.setDownloadHeaders(res, filename, 'application/pdf');
      return res.send(buffer);
    } catch (err) {
      logger.error({ err }, 'Visual report failed');
      next(err);
    }
  }
);

/**
 * Canonical — GET /api/export/:domain/:sectionId
 * format defaults to csv; optional startDate/endDate/studentId filters.
 */
router.get(
  '/:domain/:sectionId',
  verifyToken,
  requireRole('instructor'),
  validate.params(domainParams),
  validate.query(canonicalQuery),
  async (req, res, next) => {
    try {
      const { domain, sectionId } = req.params;
      if (!Object.prototype.hasOwnProperty.call(exportService.DOMAINS, domain)) {
        return next(new AppError(`Unknown export domain: ${domain}`, 400, codes.VALIDATION));
      }
      await exportService.assertInstructorOwnsSection(sectionId, req.user.id);

      const { buffer, mimeType, filename } = await exportService.formatExport(
        domain,
        sectionId,
        req.query.format,
        buildOpts(req.query)
      );

      exportService.setDownloadHeaders(res, filename, mimeType);
      return res.send(buffer);
    } catch (err) {
      logger.error({ err }, 'Export failed');
      next(err);
    }
  }
);

module.exports = router;

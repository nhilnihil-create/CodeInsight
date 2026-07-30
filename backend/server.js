const path = require('path');
require('dotenv').config({ path: path.join(__dirname, '.env') });
const express = require('express');
const cors    = require('cors');
const helmet  = require('helmet');
const cookieParser = require('cookie-parser');
const pinoHttp = require('pino-http');
const { ensureTablesExist } = require('./migrations');
const db = require('./config/db');
const logger = require('./lib/logger');
const { startAutoCloseService, stopAutoCloseService } = require('./services/autoCloseService');
const { errorHandler, notFoundHandler } = require('./middleware/errorHandler');
const swaggerSpec = require('./swagger');
const swaggerUi = require('swagger-ui-express');

const app = express();

// Security headers
app.use(helmet());

// CORS configuration - allow requests from development servers
const allowedOrigins = (process.env.CORS_ORIGINS || 'http://localhost:3000,http://localhost:5173,http://127.0.0.1:5173')
  .split(',')
  .map((s) => s.trim())
  .filter(Boolean);

app.use(cors({
  origin: (origin, cb) => {
    if (!origin) return cb(null, true);
    if (process.env.NODE_ENV === 'development') return cb(null, true);
    if (allowedOrigins.includes(origin)) return cb(null, true);
    if (origin.endsWith('.vercel.app')) return cb(null, true);
    return cb(new Error(`CORS: origin ${origin} not allowed`));
  },
  credentials: true,
}));

// Parse JSON with increased payload
app.use(express.json({ limit: '10mb' }));
app.use(express.urlencoded({ limit: '10mb', extended: true }));
app.use(cookieParser());

// Structured request logging via pino-http
app.use(pinoHttp({
  logger,
  autoLogging: process.env.NODE_ENV === 'production' || process.env.LOG_REQUESTS === '1',
  quietReqLogger: true,
}));

// Routes
app.use('/api/auth',        require('./routes/auth'));
app.use('/api/sections',    require('./routes/sections'));
app.use('/api/exercises',   require('./routes/exercises'));
app.use('/api/student',     require('./routes/student'));
app.use('/api/submissions', require('./routes/submissions'));
app.use('/api/analytics',   require('./routes/analytics'));
app.use('/api/analytics',   require('./routes/integrity'));
app.use('/api/evaluation',  require('./routes/evaluation'));
app.use('/api/admin',       require('./routes/admin'));
app.use('/api/admin',       require('./routes/adminConfig'));
app.use('/api/search',        require('./routes/search'));
app.use('/api/export',        require('./routes/export'));

// Health check — liveness: process is up
app.get('/api/health', (_req, res) => {
  res.json({ status: 'ok', service: 'codeinsight', time: new Date().toISOString() });
});

// Readiness check — process can serve traffic
app.get('/api/ready', async (_req, res) => {
  try {
    await db.query('SELECT 1');
    let queueReady = false;
    try {
      const submissionQueue = require('./queues/submissionQueue');
      queueReady = submissionQueue.isReady();
    } catch (_) { /* queue not configured */ }
    res.json({
      status: 'ok',
      database: 'connected',
      queue: queueReady ? 'ready' : 'fallback',
      time: new Date().toISOString(),
    });
  } catch (err) {
    res.status(503).json({
      status: 'error',
      database: 'disconnected',
      error: 'Database unreachable',
      time: new Date().toISOString(),
    });
  }
});

// API Documentation
app.use('/api/docs', swaggerUi.serve, swaggerUi.setup(swaggerSpec, {
  customSiteTitle: 'CodeInsight API Docs',
  customCss: '.swagger-ui .topbar { display: none }',
}));

// 404 (after all routes)
app.use(notFoundHandler);

// Global error handler (last)
app.use(errorHandler);

const PORT = process.env.PORT || 5000;

// Run migrations and start server
ensureTablesExist().then(async () => {
  try {
    const submissionQueue = require('./queues/submissionQueue');
    const queueReady = await submissionQueue.initQueue();
    if (queueReady) {
      logger.info('Submission queue initialized (async mode available)');
    } else {
      logger.warn('Redis unavailable — submissions will process synchronously');
    }
  } catch (err) {
    logger.warn({ err }, 'Queue init failed');
  }

  app.listen(PORT, '0.0.0.0', () => {
    logger.info({ port: PORT }, 'CodeInsight started');
    startAutoCloseService();
  });
}).catch(err => {
  logger.error({ err }, 'Failed to run migrations');
  app.listen(PORT, '0.0.0.0', () => {
    logger.warn({ port: PORT }, 'CodeInsight started (migration failed)');
    startAutoCloseService();
  });
});

// ── Process-level exception handling ──────────────────────────────────────

process.on('uncaughtException', (err) => {
  logger.fatal({ err }, 'Uncaught exception — shutting down');
  shutdown('UNCAUGHT_EXCEPTION');
});

process.on('unhandledRejection', (reason) => {
  logger.fatal({ err: reason instanceof Error ? reason : new Error(String(reason)) }, 'Unhandled rejection — shutting down');
  shutdown('UNHANDLED_REJECTION');
});

// Graceful shutdown
function shutdown(signal) {
  logger.info({ signal }, 'Shutting down gracefully...');

  const forceExit = setTimeout(() => {
    logger.error('Forced exit after timeout');
    process.exit(1);
  }, 10000);
  forceExit.unref();

  stopAutoCloseService();
  try {
    const submissionQueue = require('./queues/submissionQueue');
    submissionQueue.closeQueue().catch(() => {});
  } catch (_) { /* queue not initialized */ }
  db.end().then(() => {
    clearTimeout(forceExit);
    process.exit(0);
  }).catch(() => {
    clearTimeout(forceExit);
    process.exit(1);
  });
}
process.on('SIGTERM', () => shutdown('SIGTERM'));
process.on('SIGINT',  () => shutdown('SIGINT'));

const path = require('path');
require('dotenv').config({ path: path.join(__dirname, '.env') });
const express = require('express');
const cors    = require('cors');
const cookieParser = require('cookie-parser');
const { ensureTablesExist } = require('./migrations');
const db = require('./config/db');
const { startAutoCloseService, stopAutoCloseService } = require('./services/autoCloseService');
const { errorHandler, notFoundHandler } = require('./middleware/errorHandler');

const app = express();

// CORS configuration - allow requests from development servers
const allowedOrigins = (process.env.CORS_ORIGINS || 'http://localhost:3000,http://localhost:5173,http://127.0.0.1:5173')
  .split(',')
  .map((s) => s.trim())
  .filter(Boolean);

app.use(cors({
  origin: (origin, cb) => {
    if (!origin) return cb(null, true);
    if (allowedOrigins.includes(origin)) return cb(null, true);
    return cb(new Error(`CORS: origin ${origin} not allowed`));
  },
  credentials: true,
}));

// Parse JSON with increased payload
app.use(express.json({ limit: '10mb' }));
app.use(express.urlencoded({ limit: '10mb', extended: true }));
app.use(cookieParser());

// Request log (lightweight, opt-in via LOG_REQUESTS=1)
if (process.env.LOG_REQUESTS === '1') {
  app.use((req, _res, next) => {
    // eslint-disable-next-line no-console
    console.log(`${new Date().toISOString()} ${req.method} ${req.originalUrl}`);
    next();
  });
}

// Routes
app.use('/api/auth',        require('./routes/auth'));
app.use('/api/sections',    require('./routes/sections'));
app.use('/api/exercises',   require('./routes/exercises'));
app.use('/api/student',     require('./routes/student'));
app.use('/api/submissions', require('./routes/submissions'));
app.use('/api/analytics',   require('./routes/analytics'));
app.use('/api/analytics',   require('./routes/integrity'));
app.use('/api/custom-tags', require('./routes/customTags'));
app.use('/api/evaluation',  require('./routes/evaluation'));
app.use('/api/admin',       require('./routes/admin'));
app.use('/api/notifications', require('./routes/notifications'));
app.use('/api/search',        require('./routes/search'));
app.use('/api/export',        require('./routes/export'));

// Health check
app.get('/api/health', (_req, res) => {
  res.json({ status: 'ok', service: 'codeinsight', time: new Date().toISOString() });
});

// 404 (after all routes)
app.use(notFoundHandler);

// Global error handler (last)
app.use(errorHandler);

const PORT = process.env.PORT || 5000;

// Run migrations and start server
ensureTablesExist().then(async () => {
  // Initialize submission queue (non-blocking — falls back to sync if Redis unavailable)
  try {
    const submissionQueue = require('./queues/submissionQueue');
    const queueReady = await submissionQueue.initQueue();
    if (queueReady) {
      console.log('[Server] Submission queue initialized (async mode available)');
    } else {
      console.log('[Server] Redis unavailable — submissions will process synchronously');
    }
  } catch (err) {
    console.warn('[Server] Queue init failed:', err.message);
  }

  app.listen(PORT, () => {
    console.log(`CodeInsight running on port ${PORT}`);
    console.log(`PostgreSQL connected`);
    startAutoCloseService();
  });
}).catch(err => {
  console.error('Failed to run migrations:', err);
  app.listen(PORT, () => {
    console.log(`CodeInsight running on port ${PORT} (migration failed)`);
    startAutoCloseService();
  });
});

// Graceful shutdown
function shutdown(signal) {
  console.log(`\nReceived ${signal}. Shutting down gracefully...`);
  stopAutoCloseService();
  // Close queue connection
  const submissionQueue = require('./queues/submissionQueue');
  submissionQueue.closeQueue().catch(() => {});
  db.end().then(() => process.exit(0)).catch(() => process.exit(1));
}
process.on('SIGTERM', () => shutdown('SIGTERM'));
process.on('SIGINT',  () => shutdown('SIGINT'));

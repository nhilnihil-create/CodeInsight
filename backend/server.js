require('dotenv').config();
const express = require('express');
const cors    = require('cors');
const { ensureTablesExist } = require('./migrations');
const { startAutoCloseService } = require('./services/autoCloseService');
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
app.use('/api/evaluation',  require('./routes/evaluation'));
app.use('/api/admin',       require('./routes/admin'));
app.use('/api/notifications', require('./routes/notifications'));

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
ensureTablesExist().then(() => {
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

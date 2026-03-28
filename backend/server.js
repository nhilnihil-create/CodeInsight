require('dotenv').config();
const express = require('express');
const cors    = require('cors');
const { ensureTablesExist } = require('./migrations');

const app = express();

// CORS configuration - allow requests from development servers
app.use(cors({
  origin: ['http://localhost:3000', 'http://localhost:5173', 'http://127.0.0.1:5173'],
  credentials: true
}));

// Parse JSON with increased payload  
app.use(express.json({ limit: '10mb' }));
app.use(express.urlencoded({ limit: '10mb', extended: true }));

// Error handler for JSON parsing
app.use((err, req, res, next) => {
  if (err instanceof SyntaxError && err.status === 400 && 'body' in err) {
    return res.status(400).json({ message: 'Invalid JSON in request body' });
  }
  next();
});

// Routes
app.use('/api/auth', require('./routes/auth'));
app.use('/api/sections',    require('./routes/sections'));
app.use('/api/exercises',   require('./routes/exercises'));
app.use('/api/student',     require('./routes/student'));
app.use('/api/submissions', require('./routes/submissions'));
app.use('/api/analytics',   require('./routes/analytics'));

const PORT = process.env.PORT || 5000;

// Run migrations and start server
ensureTablesExist().then(() => {
  app.listen(PORT, () => {
    console.log(`CodeInsight running on port ${PORT}`);
    console.log(`PostgreSQL connected`);
  });
}).catch(err => {
  console.error('Failed to run migrations:', err);
  app.listen(PORT, () => {
    console.log(`CodeInsight running on port ${PORT} (migration failed)`);
    console.log(`PostgreSQL connected`);
  });
});

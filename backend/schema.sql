-- CodeInsight Database Schema
-- Run: psql -U postgres -d codeinsight -f schema.sql

CREATE TABLE IF NOT EXISTS users (
  id           SERIAL PRIMARY KEY,
  name         VARCHAR(100) NOT NULL,
  email        VARCHAR(100) UNIQUE NOT NULL,
  password_hash VARCHAR(255) NOT NULL,
  role         VARCHAR(20) NOT NULL CHECK (role IN ('instructor','student')),
  created_at   TIMESTAMP DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS sections (
  id            SERIAL PRIMARY KEY,
  name          VARCHAR(150) NOT NULL,
  course_code   VARCHAR(50) NOT NULL,
  school_year   VARCHAR(30),
  instructor_id INT REFERENCES users(id) ON DELETE CASCADE,
  created_at    TIMESTAMP DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS enrollments (
  id          SERIAL PRIMARY KEY,
  student_id  INT REFERENCES users(id) ON DELETE CASCADE,
  section_id  INT REFERENCES sections(id) ON DELETE CASCADE,
  enrolled_at TIMESTAMP DEFAULT NOW(),
  UNIQUE(student_id, section_id)
);

CREATE TABLE IF NOT EXISTS concepts (
  id        SERIAL PRIMARY KEY,
  name      VARCHAR(100) NOT NULL UNIQUE,
  ast_nodes TEXT[]
);

CREATE TABLE IF NOT EXISTS exercises (
  id                SERIAL PRIMARY KEY,
  title             VARCHAR(200) NOT NULL,
  description       TEXT NOT NULL,
  concept_id        INT REFERENCES concepts(id),
  section_id        INT REFERENCES sections(id) ON DELETE CASCADE,
  created_by        INT REFERENCES users(id),
  time_limit_minutes INT NOT NULL DEFAULT 45,
  test_cases        JSONB NOT NULL DEFAULT '[]',
  starter_code      TEXT DEFAULT E'#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}\n',
  ast_nodes         TEXT[],
  deadline          TIMESTAMP,
  is_draft          BOOLEAN DEFAULT false,
  track_ner         BOOLEAN DEFAULT true,
  track_nrs         BOOLEAN DEFAULT true,
  track_nts         BOOLEAN DEFAULT true,
  auto_alert        BOOLEAN DEFAULT true,
  closed_at         TIMESTAMP,
  created_at        TIMESTAMP DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS submissions (
  id                SERIAL PRIMARY KEY,
  student_id        INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id       INT REFERENCES exercises(id) ON DELETE CASCADE,
  code              TEXT NOT NULL,
  test_results      JSONB DEFAULT '[]',
  is_correct        BOOLEAN DEFAULT false,
  cds               DECIMAL(6,4) DEFAULT 0,
  ner               DECIMAL(6,4) DEFAULT 0,
  nrs               DECIMAL(6,4) DEFAULT 0,
  nts               DECIMAL(6,4) DEFAULT 0,
  attempt_number    INT NOT NULL DEFAULT 1,
  time_spent_seconds INT DEFAULT 0,
  is_verified       BOOLEAN DEFAULT true,
  verification_note TEXT,
  created_at        TIMESTAMP DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS cds_scores (
  id             SERIAL PRIMARY KEY,
  student_id     INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id    INT REFERENCES exercises(id) ON DELETE CASCADE,
  section_id     INT REFERENCES sections(id) ON DELETE CASCADE,
  ner            DECIMAL(6,4),
  nrs            DECIMAL(6,4),
  nts            DECIMAL(6,4),
  cds            DECIMAL(6,4),
  classification VARCHAR(20) NOT NULL DEFAULT 'Unscored',
  computed_at    TIMESTAMP DEFAULT NOW(),
  UNIQUE(student_id, exercise_id)
);

CREATE TABLE IF NOT EXISTS alerts (
  id             SERIAL PRIMARY KEY,
  student_id     INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id    INT REFERENCES exercises(id) ON DELETE CASCADE,
  section_id     INT REFERENCES sections(id) ON DELETE CASCADE,
  cds_score      DECIMAL(6,4),
  classification VARCHAR(20),
  concept_name   VARCHAR(100),
  is_reviewed    BOOLEAN DEFAULT false,
  created_at     TIMESTAMP DEFAULT NOW(),
  UNIQUE(student_id, exercise_id)
);

CREATE TABLE IF NOT EXISTS verification_logs (
  id             SERIAL PRIMARY KEY,
  submission_id  INT REFERENCES submissions(id) ON DELETE CASCADE,
  student_id     INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id    INT REFERENCES exercises(id) ON DELETE CASCADE,
  verification_type VARCHAR(100),
  reason         TEXT,
  node_found     TEXT,
  node_expected  TEXT,
  line_number    INT,
  column_number  INT,
  created_at     TIMESTAMP DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS performance_logs (
  id                   SERIAL PRIMARY KEY,
  submission_id        INT REFERENCES submissions(id) ON DELETE SET NULL,
  student_id           INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id          INT REFERENCES exercises(id) ON DELETE CASCADE,
  time_to_interactive_ms INT,
  response_latency_ms  INT,
  endpoint             VARCHAR(50),
  http_status_code     INT,
  user_agent           TEXT,
  created_at           TIMESTAMP DEFAULT NOW()
);

-- ── SEED DATA ──────────────────────────────────────────────────────────────
-- Insert 7 programming concepts
INSERT INTO concepts (name, ast_nodes) VALUES
  ('Datatypes',    ARRAY[]::TEXT[]),
  ('Variables',    ARRAY[]::TEXT[]),
  ('Conditionals', ARRAY['if_statement','switch_statement']),
  ('Loops',        ARRAY['for_statement','while_statement','do_statement']),
  ('Functions',    ARRAY['function_definition']),
  ('Arrays',       ARRAY['array_declarator','subscript_expression']),
  ('OOP',          ARRAY['class_specifier'])
ON CONFLICT (name) DO NOTHING;

-- Insert seed instructor (password: password123)
INSERT INTO users (name, email, password_hash, role) VALUES
  ('Juan Dela Cruz', 'instructor@psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'instructor')
ON CONFLICT (email) DO NOTHING;

-- Insert seed students (password: password123)
INSERT INTO users (name, email, password_hash, role) VALUES
  ('Maria Reyes', 'maria@student.psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'student'),
  ('Jose Santos', 'jose@student.psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'student'),
  ('Ana Lim',     'ana@student.psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'student')
ON CONFLICT (email) DO NOTHING;

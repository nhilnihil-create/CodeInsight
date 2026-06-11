-- CodeInsight Database Schema — V2 (2026-06-10)
-- Run: psql -U postgres -d codeinsight -f schema.sql
--
-- This schema reflects all migrations and runtime patches as of V2 release.
-- It supersedes all migration files in backend/migrations/.

-- ── Users ───────────────────────────────────────────────────────────────────
-- Roles: student, instructor, admin (updated from original 2-role check)

CREATE TABLE IF NOT EXISTS users (
  id           SERIAL PRIMARY KEY,
  name         VARCHAR(100) NOT NULL,
  email        VARCHAR(100) UNIQUE NOT NULL,
  password_hash VARCHAR(255) NOT NULL,
  role         VARCHAR(20) NOT NULL CHECK (role IN ('student','instructor','admin')),
  created_at   TIMESTAMP DEFAULT NOW()
);

-- ── Sections ────────────────────────────────────────────────────────────────
-- V2 additions: code, term, semester, join_policy, max_size

CREATE TABLE IF NOT EXISTS sections (
  id            SERIAL PRIMARY KEY,
  name          VARCHAR(150) NOT NULL,
  course_code   VARCHAR(50) NOT NULL,
  school_year   VARCHAR(30),
  instructor_id INT REFERENCES users(id) ON DELETE CASCADE,
  code          TEXT,
  term          TEXT,
  semester      TEXT,
  join_policy   TEXT NOT NULL DEFAULT 'code' CHECK (join_policy IN ('code', 'request', 'closed')),
  max_size      INTEGER NOT NULL DEFAULT 60,
  created_at    TIMESTAMP DEFAULT NOW()
);

-- ── Enrollments ─────────────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS enrollments (
  id          SERIAL PRIMARY KEY,
  student_id  INT REFERENCES users(id) ON DELETE CASCADE,
  section_id  INT REFERENCES sections(id) ON DELETE CASCADE,
  enrolled_at TIMESTAMP DEFAULT NOW(),
  UNIQUE(student_id, section_id)
);

-- ── Section Memberships (V2) ────────────────────────────────────────────────
-- Rich memberships: TA, co-instructor, drop tracking

CREATE TABLE IF NOT EXISTS section_memberships (
  id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  section_id  INTEGER NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
  user_id     INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  role        TEXT NOT NULL DEFAULT 'student' CHECK (role IN ('student', 'ta', 'co_instructor')),
  status      TEXT NOT NULL DEFAULT 'active' CHECK (status IN ('active', 'pending', 'denied', 'dropped', 'left_requested', 'left')),
  joined_at   TIMESTAMPTZ NOT NULL DEFAULT NOW(),
  dropped_at  TIMESTAMPTZ,
  drop_reason TEXT,
  UNIQUE(section_id, user_id)
);

CREATE INDEX IF NOT EXISTS idx_section_memberships_section ON section_memberships(section_id);
CREATE INDEX IF NOT EXISTS idx_section_memberships_user ON section_memberships(user_id);
CREATE INDEX IF NOT EXISTS idx_section_memberships_status ON section_memberships(status);

-- ── Concepts ────────────────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS concepts (
  id        SERIAL PRIMARY KEY,
  name      VARCHAR(100) NOT NULL UNIQUE,
  ast_nodes TEXT[]
);

-- ── Exercises ───────────────────────────────────────────────────────────────
-- V2 additions: mode, rubric_config, is_validated, search_vector

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
  reference_solution TEXT,
  ast_nodes         TEXT[],
  deadline          TIMESTAMP,
  is_draft          BOOLEAN DEFAULT false,
  track_ner         BOOLEAN DEFAULT true,
  track_nrs         BOOLEAN DEFAULT true,
  track_nts         BOOLEAN DEFAULT true,
  auto_alert        BOOLEAN DEFAULT true,
  closed_at         TIMESTAMP,
  mode              VARCHAR(20) DEFAULT 'learning' CHECK (mode IN ('learning', 'assessment')),
  rubric_config     JSONB DEFAULT '{}',
  is_validated      BOOLEAN DEFAULT false,
  search_vector     tsvector,
  created_at        TIMESTAMP DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_exercises_search ON exercises USING gin(search_vector);

-- ── Exercise Concepts (V2) ──────────────────────────────────────────────────
-- Many-to-many: exercises can have secondary concept tags

CREATE TABLE IF NOT EXISTS exercise_concepts (
  exercise_id INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
  concept_id  INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
  PRIMARY KEY (exercise_id, concept_id)
);

CREATE INDEX IF NOT EXISTS idx_exercise_concepts_exercise ON exercise_concepts(exercise_id);
CREATE INDEX IF NOT EXISTS idx_exercise_concepts_concept ON exercise_concepts(concept_id);

-- ── Exercise Bank (V2) ──────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS exercise_bank (
  id          SERIAL PRIMARY KEY,
  title       VARCHAR(200) NOT NULL,
  description TEXT NOT NULL,
  concept     VARCHAR(100) NOT NULL,
  difficulty  VARCHAR(20),
  sequence_order INT DEFAULT 0,
  test_cases  JSONB NOT NULL DEFAULT '[]',
  starter_code TEXT,
  sample_solution TEXT,
  mode        VARCHAR(20) DEFAULT 'learning' CHECK (mode IN ('learning', 'assessment')),
  rubric_config JSONB DEFAULT '{}',
  is_validated BOOLEAN DEFAULT false,
  created_at  TIMESTAMP DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_exercise_bank_concept ON exercise_bank(concept);
CREATE INDEX IF NOT EXISTS idx_exercise_bank_difficulty ON exercise_bank(difficulty);

-- ── Submissions ─────────────────────────────────────────────────────────────
-- V2 additions: is_practice, cppcheck_warnings, submitted_at

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
  code_growth_delta INT DEFAULT 0,
  is_practice       BOOLEAN DEFAULT false,
  cppcheck_warnings JSONB DEFAULT '[]',
  submitted_at      TIMESTAMP DEFAULT NOW(),
  created_at        TIMESTAMP DEFAULT NOW()
);

-- ── CDS Scores ──────────────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS cds_scores (
  id             SERIAL PRIMARY KEY,
  student_id     INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id    INT REFERENCES exercises(id) ON DELETE CASCADE,
  section_id     INT REFERENCES sections(id) ON DELETE CASCADE,
  ner            DECIMAL(6,4),
  nrs            DECIMAL(6,4),
  nts            DECIMAL(6,4),
  cds            DECIMAL(6,4),
  classification VARCHAR(30) NOT NULL DEFAULT 'Unscored',
  has_flagged_attempts BOOLEAN DEFAULT false,
  integrity_flag_count INTEGER DEFAULT 0,
  source         VARCHAR(20) DEFAULT 'batch',
  visible        BOOLEAN DEFAULT true,
  computed_at    TIMESTAMP DEFAULT NOW(),
  UNIQUE(student_id, exercise_id)
);

-- ── CDS Snapshots (V2) ──────────────────────────────────────────────────────
-- Append-only audit trail for CDS reproducibility

CREATE TABLE IF NOT EXISTS cds_snapshots (
  id                 SERIAL PRIMARY KEY,
  student_id         INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  exercise_id        INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
  ner                NUMERIC(5,4),
  nrs                NUMERIC(5,4),
  nts                NUMERIC(5,4),
  cds                NUMERIC(5,4),
  classification     VARCHAR(30),
  class_max_errors   INT,
  class_max_attempts INT,
  effective_max_time INT,
  calculated_at      TIMESTAMP DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_cds_snapshots_student_exercise ON cds_snapshots(student_id, exercise_id);
CREATE INDEX IF NOT EXISTS idx_cds_snapshots_calculated ON cds_snapshots(calculated_at);

-- ── Alerts ──────────────────────────────────────────────────────────────────

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

-- ── Integrity Flags ─────────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS integrity_flags (
  id                  SERIAL PRIMARY KEY,
  section_id          INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
  exercise_id         INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
  student_id          INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  submission_id       INT REFERENCES submissions(id) ON DELETE SET NULL,
  flag_type           VARCHAR(50) NOT NULL,
  severity            VARCHAR(20) NOT NULL,
  evidence            JSONB DEFAULT '{}',
  context_behaviors   TEXT[] DEFAULT '{}',
  status              VARCHAR(20) DEFAULT 'flagged',
  instructor_note     TEXT,
  reviewed_at         TIMESTAMP,
  created_at          TIMESTAMP DEFAULT NOW(),
  UNIQUE(exercise_id, student_id, flag_type)
);

-- ── Notifications ───────────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS notifications (
  id                  SERIAL PRIMARY KEY,
  student_id          INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  section_id          INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
  exercise_id         INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
  message             TEXT NOT NULL,
  notification_type   VARCHAR(50) NOT NULL DEFAULT 'cds_computation',
  is_read             BOOLEAN DEFAULT false,
  created_at          TIMESTAMP DEFAULT NOW(),
  UNIQUE(student_id, exercise_id, notification_type)
);

-- ── Verification Logs ───────────────────────────────────────────────────────

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

-- ── Performance Logs ────────────────────────────────────────────────────────

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

-- ── Auto Close Log ──────────────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS auto_close_log (
  id             SERIAL PRIMARY KEY,
  exercise_id    INT REFERENCES exercises(id) ON DELETE CASCADE,
  closed_at      TIMESTAMP DEFAULT NOW(),
  triggered_by   VARCHAR(50) DEFAULT 'auto_close_service',
  created_at     TIMESTAMP DEFAULT NOW()
);

-- ── Audit Log (V2) ──────────────────────────────────────────────────────────
-- Behavioral event trail for thesis evidence

CREATE TABLE IF NOT EXISTS audit_log (
  id            SERIAL PRIMARY KEY,
  student_id    INT REFERENCES users(id) ON DELETE CASCADE,
  exercise_id   INT REFERENCES exercises(id) ON DELETE CASCADE,
  event_type    VARCHAR(50) NOT NULL,
  metadata      JSONB DEFAULT '{}',
  occurred_at   TIMESTAMP DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_audit_log_student_exercise ON audit_log(student_id, exercise_id);
CREATE INDEX IF NOT EXISTS idx_audit_log_event_type ON audit_log(event_type);
CREATE INDEX IF NOT EXISTS idx_audit_log_occurred ON audit_log(occurred_at);

-- ── Behavioral Events (V2) ──────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS behavioral_events (
  id            SERIAL PRIMARY KEY,
  student_id    INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  exercise_id   INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
  event_type    VARCHAR(50) NOT NULL,
  occurred_at   TIMESTAMP NOT NULL DEFAULT NOW(),
  payload       JSONB DEFAULT '{}'::jsonb,
  created_at    TIMESTAMP DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_behavioral_events_student_exercise ON behavioral_events(student_id, exercise_id);

-- ── Section Audit Log (V2) ──────────────────────────────────────────────────

CREATE TABLE IF NOT EXISTS section_audit_log (
  id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  section_id  INTEGER NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
  actor_id    INTEGER REFERENCES users(id) ON DELETE SET NULL,
  action      TEXT NOT NULL,
  meta        JSONB NOT NULL DEFAULT '{}',
  created_at  TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_section_audit_log_section ON section_audit_log(section_id);
CREATE INDEX IF NOT EXISTS idx_section_audit_log_created ON section_audit_log(created_at);

-- ── Evaluation Responses (V2) ───────────────────────────────────────────────
-- ISO/IEC 25010 evaluation instrument

CREATE TABLE IF NOT EXISTS evaluation_responses (
  id            UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  respondent_id INTEGER REFERENCES users(id) ON DELETE SET NULL,
  role          TEXT NOT NULL CHECK (role IN ('student', 'instructor', 'admin')),
  fs_1 INTEGER NOT NULL CHECK (fs_1 BETWEEN 1 AND 4),
  fs_2 INTEGER NOT NULL CHECK (fs_2 BETWEEN 1 AND 4),
  fs_3 INTEGER NOT NULL CHECK (fs_3 BETWEEN 1 AND 4),
  fs_4 INTEGER NOT NULL CHECK (fs_4 BETWEEN 1 AND 4),
  us_1 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
  us_2 INTEGER NOT NULL CHECK (us_2 BETWEEN 1 AND 4),
  us_3 INTEGER NOT NULL CHECK (us_3 BETWEEN 1 AND 4),
  us_4 INTEGER NOT NULL CHECK (us_4 BETWEEN 1 AND 4),
  us_5 INTEGER NOT NULL CHECK (us_5 BETWEEN 1 AND 4),
  pe_1 INTEGER NOT NULL CHECK (pe_1 BETWEEN 1 AND 4),
  pe_2 INTEGER NOT NULL CHECK (pe_2 BETWEEN 1 AND 4),
  pe_3 INTEGER NOT NULL CHECK (pe_3 BETWEEN 1 AND 4),
  feedback_text TEXT,
  created_at    TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

CREATE INDEX IF NOT EXISTS idx_evaluation_responses_created_at ON evaluation_responses(created_at);
CREATE INDEX IF NOT EXISTS idx_evaluation_responses_role ON evaluation_responses(role);

-- ── Full-Text Search Trigger (V2) ───────────────────────────────────────────

CREATE OR REPLACE FUNCTION exercises_search_vector_trigger()
RETURNS TRIGGER AS $$
BEGIN
  NEW.search_vector :=
    setweight(to_tsvector('english', coalesce(NEW.title, '')), 'A') ||
    setweight(to_tsvector('english', coalesce(NEW.description, '')), 'B');
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER exercises_search_vector_update
  BEFORE INSERT OR UPDATE ON exercises
  FOR EACH ROW
  EXECUTE FUNCTION exercises_search_vector_trigger();

-- ── SEED DATA ───────────────────────────────────────────────────────────────

INSERT INTO concepts (name, ast_nodes) VALUES
  ('Datatypes',    ARRAY[]::TEXT[]),
  ('Variables',    ARRAY[]::TEXT[]),
  ('Conditionals', ARRAY['if_statement','switch_statement']),
  ('Loops',        ARRAY['for_statement','while_statement','do_statement']),
  ('Functions',    ARRAY['function_definition']),
  ('Arrays',       ARRAY['array_declarator','subscript_expression']),
  ('OOP',          ARRAY['class_specifier']),
  ('Pointers',     ARRAY['pointer_declarator','pointer_expression']),
  ('Strings',      ARRAY['string_literal']),
  ('Input/Output', ARRAY['call_expression'])
ON CONFLICT (name) DO NOTHING;

INSERT INTO users (name, email, password_hash, role) VALUES
  ('Juan Dela Cruz', 'instructor@psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'instructor')
ON CONFLICT (email) DO NOTHING;

INSERT INTO users (name, email, password_hash, role) VALUES
  ('Maria Reyes', 'maria@student.psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'student'),
  ('Jose Santos', 'jose@student.psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'student'),
  ('Ana Lim',     'ana@student.psu.edu',
   '$2a$10$92IXUNpkjO0rOQ5byMi.Ye4oKoEa3Ro9llC/.og/at2.uheWG/igi', 'student')
ON CONFLICT (email) DO NOTHING;

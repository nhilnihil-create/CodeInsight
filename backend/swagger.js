const swaggerJsdoc = require('swagger-jsdoc');

const options = {
  definition: {
    openapi: '3.0.3',
    info: {
      title: 'CodeInsight API',
      version: '1.0.0',
      description: 'CodeInsight — Code Learning Analytics Platform\n\nPampanga State University · College of Computer Studies',
      contact: { name: 'CodeInsight Team' },
    },
    servers: [
      { url: 'http://localhost:5000', description: 'Local development' },
    ],
    components: {
      securitySchemes: {
        cookieAuth: {
          type: 'apiKey',
          in: 'cookie',
          name: 'ci_token',
          description: 'JWT token set via login (httpOnly cookie)',
        },
      },
      schemas: {
        User: {
          type: 'object',
          properties: {
            id: { type: 'integer' },
            name: { type: 'string' },
            email: { type: 'string' },
            role: { type: 'string', enum: ['student', 'instructor', 'admin'] },
          },
        },
        Error: {
          type: 'object',
          properties: {
            message: { type: 'string' },
            code: { type: 'string' },
          },
        },
      },
    },
    tags: [
      { name: 'Health', description: 'Health & readiness checks' },
      { name: 'Auth', description: 'Authentication & registration' },
      { name: 'Sections', description: 'Section management' },
      { name: 'Exercises', description: 'Exercise CRUD & bank' },
      { name: 'Student', description: 'Student-facing endpoints' },
      { name: 'Submissions', description: 'Code run & submit' },
      { name: 'Analytics', description: 'Analytics, reports & dashboards' },
      { name: 'Integrity', description: 'Academic integrity flags' },
      { name: 'Evaluation', description: 'Self-evaluation responses' },
      { name: 'Admin', description: 'Admin panel endpoints' },
      { name: 'Search', description: 'Global search' },
      { name: 'Export', description: 'Data export (CSV/XLSX)' },
    ],
    paths: {
      // ── Health ──────────────────────────────────────────────
      '/api/health': {
        get: {
          tags: ['Health'],
          summary: 'Liveness check — process is up',
          responses: { 200: { description: 'Service healthy' } },
        },
      },
      '/api/ready': {
        get: {
          tags: ['Health'],
          summary: 'Readiness check — DB + queue connectivity',
          responses: {
            200: { description: 'All systems operational' },
            503: { description: 'Database unreachable' },
          },
        },
      },
      // ── Auth ────────────────────────────────────────────────
      '/api/auth/register': {
        post: {
          tags: ['Auth'],
          summary: 'Register (legacy email-link flow)',
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['name', 'email', 'password'],
                  properties: {
                    name: { type: 'string', example: 'Juan Dela Cruz' },
                    email: { type: 'string', format: 'email' },
                    password: { type: 'string', minLength: 8 },
                    role: { type: 'string', enum: ['student', 'instructor'] },
                  },
                },
              },
            },
          },
          responses: {
            201: { description: 'Check email to verify' },
            409: { description: 'Email already registered' },
          },
        },
      },
      '/api/auth/login': {
        post: {
          tags: ['Auth'],
          summary: 'Login with email and password',
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['email', 'password'],
                  properties: {
                    email: { type: 'string', format: 'email' },
                    password: { type: 'string' },
                  },
                },
              },
            },
          },
          responses: {
            200: { description: 'Sets ci_token cookie' },
            401: { description: 'Invalid credentials' },
            403: { description: 'Email not verified' },
          },
        },
      },
      '/api/auth/logout': {
        post: {
          tags: ['Auth'],
          summary: 'Logout and clear session',
          responses: { 200: { description: 'Logged out' } },
        },
      },
      '/api/auth/me': {
        get: {
          tags: ['Auth'],
          summary: 'Get current authenticated user',
          security: [{ cookieAuth: [] }],
          responses: {
            200: { description: 'User object or null' },
          },
        },
      },
      '/api/auth/verify-email/{token}': {
        get: {
          tags: ['Auth'],
          summary: 'Verify email via token link',
          parameters: [
            { in: 'path', name: 'token', required: true, schema: { type: 'string' } },
          ],
          responses: {
            302: { description: 'Redirects to frontend' },
            400: { description: 'Invalid or expired token' },
          },
        },
      },
      '/api/auth/request-otp': {
        post: {
          tags: ['Auth'],
          summary: 'Request 6-digit OTP for registration',
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['email'],
                  properties: { email: { type: 'string', format: 'email' } },
                },
              },
            },
          },
          responses: {
            200: { description: 'Code sent' },
            409: { description: 'Email already registered' },
          },
        },
      },
      '/api/auth/verify-otp': {
        post: {
          tags: ['Auth'],
          summary: 'Verify OTP and complete registration',
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['email', 'otp', 'name', 'password'],
                  properties: {
                    email: { type: 'string', format: 'email' },
                    otp: { type: 'string', example: '123456' },
                    name: { type: 'string' },
                    password: { type: 'string', minLength: 8 },
                    role: { type: 'string', enum: ['student', 'instructor'] },
                  },
                },
              },
            },
          },
          responses: {
            201: { description: 'Account created, cookie set' },
            400: { description: 'Invalid OTP' },
          },
        },
      },
      // ── Sections ────────────────────────────────────────────
      '/api/sections': {
        get: {
          tags: ['Sections'],
          summary: 'List all sections (for current user)',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of sections' } },
        },
        post: {
          tags: ['Sections'],
          summary: 'Create a new section (instructor)',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['name', 'course_code'],
                  properties: {
                    name: { type: 'string' },
                    course_code: { type: 'string' },
                    school_year: { type: 'string' },
                    term: { type: 'string' },
                    join_policy: { type: 'string', enum: ['code', 'request', 'closed'] },
                  },
                },
              },
            },
          },
          responses: { 201: { description: 'Section created' } },
        },
      },
      '/api/sections/{id}': {
        get: {
          tags: ['Sections'],
          summary: 'Get section by ID',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Section object' }, 404: { description: 'Not found' } },
        },
        put: {
          tags: ['Sections'],
          summary: 'Update section (instructor)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Updated' } },
        },
        delete: {
          tags: ['Sections'],
          summary: 'Delete section (instructor)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Deleted' } },
        },
      },
      '/api/sections/{id}/enroll': {
        post: {
          tags: ['Sections'],
          summary: 'Enroll students in section',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          requestBody: {
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  properties: {
                    student_ids: { type: 'array', items: { type: 'integer' } },
                    emails: { type: 'array', items: { type: 'string' } },
                  },
                },
              },
            },
          },
          responses: { 200: { description: 'Enrolled' } },
        },
      },
      '/api/sections/join': {
        post: {
          tags: ['Sections'],
          summary: 'Join section by code (student)',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['code'],
                  properties: { code: { type: 'string' } },
                },
              },
            },
          },
          responses: { 200: { description: 'Joined' } },
        },
      },
      // ── Exercises ───────────────────────────────────────────
      '/api/exercises': {
        get: {
          tags: ['Exercises'],
          summary: 'List all exercises',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of exercises' } },
        },
        post: {
          tags: ['Exercises'],
          summary: 'Create exercise (instructor)',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['title', 'concept_name', 'section_id', 'test_cases'],
                  properties: {
                    title: { type: 'string' },
                    description: { type: 'string' },
                    concept_name: { type: 'string' },
                    section_id: { type: 'integer' },
                    time_limit_minutes: { type: 'integer', default: 45 },
                    test_cases: { type: 'array', minItems: 1 },
                    deadline: { type: 'string', format: 'date-time' },
                    is_draft: { type: 'boolean' },
                    starter_code: { type: 'string' },
                    reference_solution: { type: 'string' },
                  },
                },
              },
            },
          },
          responses: { 201: { description: 'Exercise created' } },
        },
      },
      '/api/exercises/{id}': {
        get: {
          tags: ['Exercises'],
          summary: 'Get exercise by ID',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Exercise object' } },
        },
        put: {
          tags: ['Exercises'],
          summary: 'Update exercise (instructor)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Updated' } },
        },
        delete: {
          tags: ['Exercises'],
          summary: 'Delete exercise (instructor)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Deleted' } },
        },
      },
      '/api/exercises/{id}/close': {
        post: {
          tags: ['Exercises'],
          summary: 'Close exercise (triggers CDS computation)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Closed, CDS computed' } },
        },
      },
      '/api/exercises/concepts': {
        get: {
          tags: ['Exercises'],
          summary: 'Get all concepts',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of concepts' } },
        },
      },
      '/api/exercises/bank': {
        get: {
          tags: ['Exercises'],
          summary: 'Get exercise bank',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of banked exercises' } },
        },
      },
      // ── Student ─────────────────────────────────────────────
      '/api/student/exercises': {
        get: {
          tags: ['Student'],
          summary: 'Get exercises for enrolled sections',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of exercises with status' } },
        },
      },
      '/api/student/exercises/{id}': {
        get: {
          tags: ['Student'],
          summary: 'Get exercise details (visible tests only)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Exercise with filtered test cases' } },
        },
      },
      '/api/student/exercises/{id}/run': {
        post: {
          tags: ['Student'],
          summary: 'Run code against visible test cases',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['code'],
                  properties: { code: { type: 'string' } },
                },
              },
            },
          },
          responses: { 200: { description: 'Test results' } },
        },
      },
      '/api/student/exercises/{id}/submit': {
        post: {
          tags: ['Student'],
          summary: 'Submit code (all tests, CDS, integrity checks)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['code'],
                  properties: {
                    code: { type: 'string' },
                    timeSpentSeconds: { type: 'integer' },
                    tabSwitchCount: { type: 'integer' },
                    pasteCount: { type: 'integer' },
                    idleTimeSeconds: { type: 'integer' },
                  },
                },
              },
            },
          },
          responses: { 201: { description: 'Submission saved, CDS computed' } },
        },
      },
      '/api/student/dashboard': {
        get: {
          tags: ['Student'],
          summary: 'Get student dashboard (exercises, CDS, mastery)',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Dashboard data' } },
        },
      },
      '/api/student/progress': {
        get: {
          tags: ['Student'],
          summary: 'Get progress overview (mastery, trajectory)',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Progress data' } },
        },
      },
      '/api/student/today': {
        get: {
          tags: ['Student'],
          summary: 'Get personalized daily study plan',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Daily plan with focus, signals, next moves' } },
        },
      },
      '/api/student/stats': {
        get: {
          tags: ['Student'],
          summary: 'Get exercise stats (total, completed, pending)',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Stats object' } },
        },
      },
      '/api/student/concepts/all': {
        get: {
          tags: ['Student'],
          summary: 'Get concept mastery list',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of concepts with mastery %' } },
        },
      },
      '/api/student/behavioral-events': {
        post: {
          tags: ['Student'],
          summary: 'Log behavioral events (tab switches, pastes)',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['exerciseId', 'events'],
                  properties: {
                    exerciseId: { type: 'integer' },
                    events: { type: 'array' },
                  },
                },
              },
            },
          },
          responses: { 200: { description: 'Events received' } },
        },
      },
      // ── Submissions ─────────────────────────────────────────
      '/api/submissions/run': {
        post: {
          tags: ['Submissions'],
          summary: 'Run code against test cases (sync)',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['exerciseId', 'code'],
                  properties: {
                    exerciseId: { type: 'integer' },
                    code: { type: 'string' },
                  },
                },
              },
            },
          },
          responses: { 200: { description: 'Run results' } },
        },
      },
      '/api/submissions/submit': {
        post: {
          tags: ['Submissions'],
          summary: 'Submit code (sync, with grading)',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['exerciseId', 'code'],
                  properties: {
                    exerciseId: { type: 'integer' },
                    code: { type: 'string' },
                    timeSpentSeconds: { type: 'integer' },
                  },
                },
              },
            },
          },
          responses: { 201: { description: 'Submission graded' } },
        },
      },
      // ── Analytics ───────────────────────────────────────────
      '/api/analytics/heatmap/{sectionId}': {
        get: {
          tags: ['Analytics'],
          summary: 'Get section heatmap (student x concept)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'sectionId', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Heatmap data' } },
        },
      },
      '/api/analytics/alerts/{sectionId}': {
        get: {
          tags: ['Analytics'],
          summary: 'Get intervention queue for a section (per-student average CDS, High risk only)',
          description:
            'Returns the live at-risk queue: each student whose average CDS exceeds the High risk ' +
            'threshold (0.60) — the same signal as the dashboard at-risk banner, so the queue and ' +
            'banner always agree. Each row also carries the student\'s worst-exercise CDS and ' +
            'exercise/concept as display context. Includes the per-student tier distribution across ' +
            'the whole scope and the total active enrollment. Supports sectionId="all" for the ' +
            'instructor\'s combined sections.',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'sectionId', required: true, schema: { type: 'string' } }],
          responses: {
            200: {
              description: 'Intervention queue with at-risk students and tier distribution',
              content: {
                'application/json': {
                  schema: {
                    type: 'object',
                    properties: {
                      sectionId: { type: ['integer', 'string'], description: 'Resolved section id ("all" when scope is all sections)' },
                      totalStudents: { type: 'integer', description: 'Active (non-dropped) students in scope' },
                      atRisk: {
                        type: 'array',
                        description: 'Students with average CDS > 0.60, critical first, then highest average CDS',
                        items: {
                          type: 'object',
                          properties: {
                            studentId: { type: 'integer' },
                            studentName: { type: 'string' },
                            avgCds: { type: 'number', description: 'Average CDS across the student\'s scored exercises' },
                            exerciseId: { type: ['integer', 'null'] },
                            exerciseTitle: { type: ['string', 'null'] },
                            conceptName: { type: ['string', 'null'] },
                            worstCds: { type: ['number', 'null'], description: 'Worst (highest) exercise CDS — display context only; NOT the risk filter' },
                            computedAt: { type: ['string', 'null'], format: 'date-time' },
                            tier: { type: 'string', enum: ['needs_support', 'critical'], description: 'Derived from avgCds (average > 0.60 maps to exactly these two tiers)' },
                          },
                        },
                      },
                      tierDistribution: {
                        type: 'object',
                        description: 'Per-student tier counts from average CDS across the whole scope (unstarted = enrolled without any CDS)',
                        properties: {
                          excellent: { type: 'integer' },
                          strong: { type: 'integer' },
                          developing: { type: 'integer' },
                          needs_support: { type: 'integer' },
                          critical: { type: 'integer' },
                          unstarted: { type: 'integer' },
                        },
                      },
                      insight: {
                        type: 'object',
                        properties: {
                          atRiskCount: { type: 'integer' },
                          summary: { type: 'string' },
                        },
                      },
                    },
                  },
                },
              },
            },
            400: { description: 'sectionId is not a numeric section id or "all"' },
            404: { description: 'Section not found' },
          },
        },
      },
      '/api/analytics/alerts/{alertId}/review': {
        put: {
          tags: ['Analytics'],
          summary: 'Mark an alert as reviewed (legacy alerts table endpoint, kept for audit)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'alertId', required: true, schema: { type: 'integer' } }],
          responses: {
            200: { description: 'Alert marked as reviewed' },
            404: { description: 'Alert not found' },
          },
        },
      },
      '/api/analytics/student/{studentId}/profile': {
        get: {
          tags: ['Analytics'],
          summary: 'Get student profile (instructor view)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'studentId', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Student profile with CDS, submissions' } },
        },
      },
      '/api/analytics/instructor/dashboard/{sectionId}': {
        get: {
          tags: ['Analytics'],
          summary: 'Get instructor dashboard aggregate',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'sectionId', required: true, schema: { type: 'integer' } }],
          responses: {
            200: {
              description: 'Dashboard aggregates (scope can be "all" for all sections of the instructor)',
              content: {
                'application/json': {
                  schema: {
                    type: 'object',
                    properties: {
                      sectionId: { type: ['integer', 'string'] },
                      totalStudents: { type: 'integer' },
                      avgCdsRes: { type: 'object' },
                      trend: {
                        type: 'object',
                        description: 'Weekly average CDS per week for the scope',
                        properties: { weeks: { type: 'array', items: { type: 'string' } }, avgCds: { type: 'array', items: { type: 'number' } } },
                      },
                      conceptMastery: { type: 'object', description: 'Average CDS per concept' },
                      tierDistribution: {
                        type: 'object',
                        description: 'Count of students per mastery tier across the scope',
                        properties: {
                          excellent: { type: 'integer' },
                          strong: { type: 'integer' },
                          developing: { type: 'integer' },
                          needs_support: { type: 'integer' },
                          critical: { type: 'integer' },
                          unstarted: { type: 'integer' },
                        },
                      },
                      atRiskCount: { type: 'integer', description: 'Students with average CDS > 0.60' },
                      priorPeriod: { type: 'object', description: 'Week-over-week deltas for avg CDS and at-risk count' },
                      insight: {
                        type: 'object',
                        properties: {
                          summary: { type: 'string' },
                          atRiskCount: { type: 'integer' },
                          recommendedFocus: { type: 'array', items: { type: 'string' } },
                        },
                      },
                    },
                  },
                },
              },
            },
          },
        },
      },
      // ── Integrity ───────────────────────────────────────────
      '/api/analytics/integrity-flags/{sectionId}': {
        get: {
          tags: ['Integrity'],
          summary: 'Get integrity flags for a section',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'sectionId', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Array of flags' } },
        },
      },
      // ── Admin ───────────────────────────────────────────────
      '/api/admin/overview': {
        get: {
          tags: ['Admin'],
          summary: 'Get admin dashboard overview',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Overview stats' } },
        },
      },
      '/api/admin/users': {
        get: {
          tags: ['Admin'],
          summary: 'List users (filterable)',
          security: [{ cookieAuth: [] }],
          responses: { 200: { description: 'Array of users' } },
        },
        post: {
          tags: ['Admin'],
          summary: 'Create a new user',
          security: [{ cookieAuth: [] }],
          requestBody: {
            required: true,
            content: {
              'application/json': {
                schema: {
                  type: 'object',
                  required: ['name', 'email', 'password', 'role'],
                  properties: {
                    name: { type: 'string' },
                    email: { type: 'string' },
                    password: { type: 'string' },
                    role: { type: 'string', enum: ['student', 'instructor', 'admin'] },
                  },
                },
              },
            },
          },
          responses: { 201: { description: 'User created' } },
        },
      },
      '/api/admin/users/{id}': {
        put: {
          tags: ['Admin'],
          summary: 'Update a user',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Updated' } },
        },
        delete: {
          tags: ['Admin'],
          summary: 'Delete a user',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'id', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'Deleted' } },
        },
      },
      // ── Search ──────────────────────────────────────────────
      '/api/search': {
        get: {
          tags: ['Search'],
          summary: 'Global search (exercises, students, sections)',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'query', name: 'q', required: true, schema: { type: 'string' } }],
          responses: { 200: { description: 'Search results' } },
        },
      },
      // ── Export ──────────────────────────────────────────────
      '/api/export/section/{sectionId}': {
        get: {
          tags: ['Export'],
          summary: 'Export section data as CSV/XLSX',
          security: [{ cookieAuth: [] }],
          parameters: [{ in: 'path', name: 'sectionId', required: true, schema: { type: 'integer' } }],
          responses: { 200: { description: 'File download' } },
        },
      },
    },
  },
  apis: [],
};

const swaggerSpec = swaggerJsdoc(options);

module.exports = swaggerSpec;

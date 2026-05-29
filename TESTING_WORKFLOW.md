#!/bin/bash
# CodeInsight Comprehensive Testing Workflow
# Tests CDS, Alerts, Micro-Concepts, and Academic Integrity Detection

echo "=========================================="
echo "CodeInsight Comprehensive Testing Workflow"
echo "=========================================="
echo ""
echo "This workflow tests:"
echo "✓ CDS calculation (NER, NRS, NTS)"
echo "✓ Alert generation (High CDS > 0.66)"
echo "✓ Micro-concept analysis"
echo "✓ Academic integrity detection"
echo "✓ AST verification (required constructs)"
echo ""

# Use "Sum 1 to N" exercise (ID 6, Loops concept)
EXERCISE_ID=6
SECTION_ID=1

echo "Target Exercise: Sum 1 to N (ID $EXERCISE_ID, Loops)"
echo "Target Section: CS101 - Programming Fundamentals (ID $SECTION_ID)"
echo ""

# Get student IDs
PGPASSWORD=codepassword123 psql -h localhost -U codeuser -d codeinsight << 'EOF'
-- Get student IDs from CS101 section
SELECT 
  u.id,
  u.email,
  u.name,
  COUNT(e.id) as enrollments
FROM users u
LEFT JOIN enrollments e ON u.id = e.student_id AND e.section_id = 1
WHERE u.role = 'student'
GROUP BY u.id, u.email, u.name
ORDER BY u.id
LIMIT 4;
EOF

echo ""
echo "=========================================="
echo "TESTING SCENARIO OVERVIEW"
echo "=========================================="
echo ""
echo "📊 SCENARIO 1: Student A (maria@student.psu.edu)"
echo "   Goal: Perfect solution → Low CDS (~0.2)"
echo "   - 1 attempt, passes all tests"
echo "   - Proper loop implementation"
echo "   Expected: Low CDS, No Alert, Good feedback"
echo ""
echo "📊 SCENARIO 2: Student B (jose@student.psu.edu)"
echo "   Goal: Many retries → High NRS → High CDS (~0.7)"
echo "   - 8 failed attempts + 1 success"
echo "   - Valid but slow to solve"
echo "   Expected: High CDS, Alert generated, Feedback on retries"
echo ""
echo "📊 SCENARIO 3: Student C (ana@student.psu.edu)"
echo "   Goal: Hardcoded solution → Caught by AST + High CDS (~0.8)"
echo "   - 2 attempts: hardcoded then gives up"
echo "   - Fails AST verification"
echo "   Expected: High CDS, Alert, Academic Integrity flag"
echo ""
echo "📊 SCENARIO 4: Student D (new student)"
echo "   Goal: Template/blank submission → Highest CDS (1.0)"
echo "   - 1 blank attempt, no real code"
echo "   Expected: High CDS, Alert, Template detection"
echo ""

echo "=========================================="
echo "NEXT STEPS (Manual Testing)"
echo "=========================================="
echo ""
echo "1. Start Backend: cd backend && npm start"
echo "2. Start Frontend: cd frontend && npm run dev"
echo "3. Login to http://localhost:5173 as instructor@psu.edu"
echo "4. Navigate to: Sections → CS101 → SectionDetail"
echo ""
echo "Then follow the test scenarios below:"
echo ""

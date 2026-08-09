#!/bin/sh
# Read-only verification of section 51 mock data (never writes, never prints password)
# Requires: RENDER_API_TOKEN in the environment (Render API token, never hardcoded)
set -e
BASE=/home/nihil/projects/codeinsight
TOKEN="${RENDER_API_TOKEN:?RENDER_API_TOKEN must be set in the environment}"
API_JSON=$(curl -s -H "Authorization: Bearer $TOKEN" https://api.render.com/v1/services/srv-d9l9sirm8hqs738907g0/env-vars)
DB_HOST=$(echo "$API_JSON" | jq -r '.[] | select(.envVar.key=="DB_HOST") | .envVar.value')
DB_PASSWORD=$(echo "$API_JSON" | jq -r '.[] | select(.envVar.key=="DB_PASSWORD") | .envVar.value')
export PGPASSWORD="$DB_PASSWORD"
PSQL="psql -h $DB_HOST -p 5432 -U neondb_owner -d codeinsight -t -A"
echo "== mock users =="
$PSQL -c "SELECT count(*) FROM users WHERE email LIKE '%@mock.example.com';"
echo "== section 51 submissions by exercise =="
$PSQL -c "SELECT exercise_id, count(*) FROM submissions WHERE student_id IN (SELECT id FROM users WHERE email LIKE '%@mock.example.com') GROUP BY exercise_id ORDER BY exercise_id;"
echo "== cds_scores section 51 by classification =="
$PSQL -c "SELECT classification, count(*) FROM cds_scores WHERE section_id=51 GROUP BY classification ORDER BY 2 DESC;"
echo "== integrity_flags section 51 by type =="
$PSQL -c "SELECT flag_type, count(*) FROM integrity_flags WHERE section_id=51 GROUP BY flag_type ORDER BY 2 DESC;"
echo "== showcase time_spent rows =="
$PSQL -c "SELECT exercise_id, time_spent_seconds, count(*) FROM submissions WHERE time_spent_seconds IN (90,3600,7200) AND student_id IN (SELECT id FROM users WHERE email LIKE '%@mock.example.com') GROUP BY 1,2 ORDER BY 2;"
echo "== section 1 untouched check =="
$PSQL -c "SELECT (SELECT count(*) FROM enrollments WHERE section_id=1) AS sec1_enrollments, (SELECT count(*) FROM submissions s JOIN enrollments e ON s.student_id=e.student_id AND e.section_id=1) AS sec1_submissions;"

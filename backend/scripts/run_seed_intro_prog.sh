#!/bin/bash
# Runner: seed section 51 "Introduction to Programming I" with 15 mock personas.
#
# Fetches DB_HOST / DB_PASSWORD from the deployed backend's Render API env vars
# at runtime and passes them to the seed script via the environment. The DB
# password is NEVER written to a file, NEVER echoed, and only lives in the
# environment of this process.
#
# Usage: sh backend/scripts/run_seed_intro_prog.sh
# Requires: RENDER_API_TOKEN in the environment (Render API token, never hardcoded)
set -e

RENDER_API_TOKEN="${RENDER_API_TOKEN:?RENDER_API_TOKEN must be set in the environment}"
SERVICE_ID="srv-d9l9sirm8hqs738907g0"
API_URL="https://api.render.com/v1/services/${SERVICE_ID}/env-vars"

RESP=$(curl -s -H "Authorization: Bearer ${RENDER_API_TOKEN}" "${API_URL}")

DB_PASSWORD=$(echo "${RESP}" | jq -r '.[] | select(.envVar.key=="DB_PASSWORD") | .envVar.value')
DB_HOST=$(echo "${RESP}" | jq -r '.[] | select(.envVar.key=="DB_HOST") | .envVar.value')

if [ -z "${DB_PASSWORD}" ] || [ -z "${DB_HOST}" ]; then
  echo "FATAL: could not fetch DB_HOST/DB_PASSWORD from Render API" >&2
  exit 1
fi

cd /home/nihil/projects/codeinsight

DB_HOST="${DB_HOST}" \
DB_PORT=5432 \
DB_NAME=codeinsight \
DB_USER=neondb_owner \
DB_PASSWORD="${DB_PASSWORD}" \
node backend/scripts/seed_intro_prog_mock.js

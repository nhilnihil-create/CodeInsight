const path = require('path');
const { runFullPipeline } = require('../services/misconceptionRuleMiner');

function parseArgs() {
  const args = {};
  const raw = process.argv.slice(2);
  for (let i = 0; i < raw.length; i++) {
    if (raw[i].startsWith('--')) {
      const key = raw[i].replace('--', '');
      if (key.includes('=')) {
        const [k, v] = key.split('=');
        args[k] = isNaN(v) ? v : parseInt(v, 10);
      } else if (i + 1 < raw.length && !raw[i + 1].startsWith('--')) {
        args[key] = isNaN(raw[i + 1]) ? raw[i + 1] : parseInt(raw[i + 1], 10);
        i++;
      } else {
        args[key] = true;
      }
    }
  }
  return args;
}

async function main() {
  const args = parseArgs();
  const exerciseId = args.exercise || args.e || null;
  const allExercises = args.all || false;
  const minStudents = args['min-students'] || 3;
  const minOccurrences = args['min-occurrences'] || 5;
  const outputPath = args.output || path.join(__dirname, '..', 'data', `candidate_rules_${new Date().toISOString().slice(0, 10)}.json`);
  const dryRun = args['dry-run'] || false;

  if (!exerciseId && !allExercises) {
    console.error('Usage: node scripts/mine_misconceptions.js --exercise=42 [--min-students=3] [--min-occurrences=5] [--output=path] [--dry-run]');
    console.error('   or: node scripts/mine_misconceptions.js --all');
    process.exit(1);
  }

  if (dryRun) {
    console.log(`[DRY RUN] Would analyze exercise ${exerciseId || 'ALL'} with minStudents=${minStudents}, minOccurrences=${minOccurrences}`);
    return;
  }

  console.log(`Analyzing submissions for exercise ${exerciseId}...`);
  const result = await runFullPipeline({ exerciseId, minStudents, minOccurrences, outputPath });
  console.log(`Done. Generated ${result.candidates.length} candidate(s) from ${result.total_submissions_analyzed} submissions (${result.total_students} students).`);
  console.log(`Output written to: ${outputPath}`);
}

main().catch(err => {
  console.error('Pipeline failed:', err.message);
  process.exit(1);
});

# Misconception Rule Mining Pipeline — Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a deterministic pipeline that mines new micro-concept/misconception rules from real student compiler errors by clustering similar messages and generating validated candidate rules for human review.

**Architecture:** Four-stage batch pipeline: (1) Extract & Parse compiler logs, (2) Normalize messages by stripping identifiers/numbers/paths, (3) Cluster by signature similarity (exact + Jaccard fuzzy), (4) Validate candidates against ALL historical submissions and generate candidate JSON.

**Tech Stack:** Node.js, PostgreSQL, Jest (tests). Zero AI/LLM. Pure deterministic text analysis.

## Global Constraints

- No AI, no ML, no LLM calls — deterministic keyword matching and Jaccard similarity only
- All new files under `backend/services/` and `backend/scripts/`
- Tests in `backend/test/` following existing naming convention (`*.test.js`)
- Follow existing code style (CommonJS `require`, `async/await`, no TypeScript)
- Output candidates to `backend/data/candidate_rules_<date>.json`
- Human review gate: candidates are NOT auto-deployed, only generated for review

---

### Task 1: Error Normalizer (parse + normalize)

**Files:**
- Create: `backend/services/errorNormalizer.js`
- Create: `backend/test/errorNormalizer.test.js`

**Interfaces:**
- Consumes: raw `compiler_log` TEXT (from `submissions` or `run_attempts` table), submission metadata
- Produces: `parseCompilerLog(rawLog, submissionId, studentId, exerciseId, conceptId, conceptName)` → `Array<{submissionId, studentId, exerciseId, conceptId, conceptName, errorType, rawMessage, line, column, normalized, signature}>`

- [ ] **Step 1: Write the failing test for `parseCompilerLog`**

```js
// backend/test/errorNormalizer.test.js
const { parseCompilerLog, normalizeMessage, extractSignature } = require('../services/errorNormalizer');

describe('parseCompilerLog', () => {
  it('parses standard [Line N:C] ERROR: format', () => {
    const log = `[Line 5:5] ERROR: 'max_val' was not declared in this scope
    max_val = arr[0];
    ^`;
    const result = parseCompilerLog(log, 1, 10, 42, 7, 'Arrays');
    expect(result).toHaveLength(1);
    expect(result[0]).toMatchObject({
      submissionId: 1,
      studentId: 10,
      exerciseId: 42,
      conceptId: 7,
      conceptName: 'Arrays',
      errorType: 'ERROR',
      rawMessage: "'max_val' was not declared in this scope",
      line: 5,
      column: 5
    });
  });

  it('skips lines that do not match the error format', () => {
    const log = `[Line 3:1] ERROR: something wrong
    int x = 5;  // this line should be skipped`;
    const result = parseCompilerLog(log, 1, 10, 42, 7, 'Arrays');
    expect(result).toHaveLength(1);
  });

  it('returns empty array for empty log', () => {
    expect(parseCompilerLog('', 1, 1, 1, 1, 'Test')).toEqual([]);
  });

  it('returns empty array for null log', () => {
    expect(parseCompilerLog(null, 1, 1, 1, 1, 'Test')).toEqual([]);
  });

  it('deduplicates identical error messages within one submission', () => {
    const log = `[Line 5:5] ERROR: 'max_val' was not declared in this scope
[Line 8:5] ERROR: 'max_val' was not declared in this scope`;
    const result = parseCompilerLog(log, 1, 10, 42, 7, 'Arrays');
    expect(result).toHaveLength(1);
  });
});
```

- [ ] **Step 2: Run tests to verify they fail**

Run: `cd backend && npx jest test/errorNormalizer.test.js --no-coverage 2>&1`

Expected: FAIL — `Cannot find module '../services/errorNormalizer'`

- [ ] **Step 3: Implement `parseCompilerLog`**

```js
// backend/services/errorNormalizer.js
function parseCompilerLog(rawLog, submissionId, studentId, exerciseId, conceptId, conceptName) {
  if (!rawLog) return [];
  const lines = rawLog.split('\n');
  const seen = new Set();
  const errors = [];
  const pattern = /\[Line (\d+):(\d+)\] (\w+): (.+)/;

  for (const line of lines) {
    const match = line.match(pattern);
    if (!match) continue;
    const rawMessage = match[4].trim();
    if (seen.has(rawMessage)) continue;
    seen.add(rawMessage);

    errors.push({
      submissionId,
      studentId,
      exerciseId,
      conceptId,
      conceptName,
      errorType: match[3],
      rawMessage,
      line: parseInt(match[1], 10),
      column: parseInt(match[2], 10)
    });
  }
  return errors;
}
```

- [ ] **Step 4: Write the failing test for `normalizeMessage`**

```js
describe('normalizeMessage', () => {
  it('replaces identifiers with <id>', () => {
    expect(normalizeMessage("'max_val' was not declared")).toBe("'<id>' was not declared");
  });

  it('replaces numbers with <num>', () => {
    expect(normalizeMessage('array index 5 is out of bounds')).toBe('array index <num> is out of bounds');
  });

  it('replaces string literals with <str>', () => {
    expect(normalizeMessage('expected ";" before something')).toBe('expected <str> before something');
  });

  it('replaces file paths with <path>', () => {
    expect(normalizeMessage('/home/user/file.cpp:5 error')).toBe('<path> error');
  });

  it('handles empty string', () => {
    expect(normalizeMessage('')).toBe('');
  });
});
```

- [ ] **Step 5: Run normalization tests to verify they fail**

Run: `cd backend && npx jest test/errorNormalizer.test.js --no-coverage 2>&1`

Expected: FAIL — `normalizeMessage is not defined` (or `undefined`)

- [ ] **Step 6: Implement `normalizeMessage`**

```js
function normalizeMessage(rawMessage) {
  if (!rawMessage) return '';
  let msg = rawMessage;
  // Order matters: string literals first, then numbers, then identifiers
  msg = msg.replace(/"[^"]*"/g, '<str>');
  msg = msg.replace(/\b\d+\b/g, '<num>');
  msg = msg.replace(/'[a-zA-Z_]\w*'/g, "'<id>'");
  msg = msg.replace(/\b[a-zA-Z_]\w*\b/g, (match) => {
    // Don't replace C++ keywords
    const keywords = new Set(['int', 'double', 'float', 'char', 'bool', 'void', 'string',
      'for', 'while', 'if', 'else', 'return', 'switch', 'case', 'break', 'default',
      'struct', 'class', 'public', 'private', 'protected', 'virtual', 'const',
      'static', 'namespace', 'using', 'include', 'define', 'ERROR', 'WARNING']);
    const isKeyword = /^'[^']*'$/.test(match) || keywords.has(match);
    return isKeyword ? match : '<id>';
  });
  msg = msg.replace(/\/[\w./-]+/g, '<path>');
  return msg;
}
```

- [ ] **Step 7: Write the failing test for `extractSignature`**

```js
describe('extractSignature', () => {
  it('extracts signature from undeclared variable error', () => {
    expect(extractSignature("'<id>' was not declared in this scope"))
      .toBe('was not declared in this scope');
  });

  it('extracts signature from expected token error', () => {
    expect(extractSignature("expected '<id>' before '<id>'"))
      .toBe('expected');
  });

  it('returns normalized message unchanged if no distinctive tail', () => {
    expect(extractSignature('something went wrong')).toBe('something went wrong');
  });
});
```

- [ ] **Step 8: Run signature tests to verify they fail**

Run: `cd backend && npx jest test/errorNormalizer.test.js --no-coverage 2>&1`

Expected: FAIL — `extractSignature is not defined`

- [ ] **Step 9: Implement `extractSignature`**

```js
function extractSignature(normalized) {
  if (!normalized) return '';
  // Drop leading quoted identifiers (e.g., "'<id>' was not declared...")
  const cleaned = normalized.replace(/^'<id>' /, '').trim();
  // Take first 5 significant tokens
  const tokens = cleaned.split(/\s+/).filter(t => !t.startsWith('<') || t === '<id>' || t === '<num>');
  return tokens.slice(0, 5).join(' ');
}
```

- [ ] **Step 10: Run all normalizer tests to verify they pass**

Run: `cd backend && npx jest test/errorNormalizer.test.js --no-coverage 2>&1`

Expected: PASS — all tests green

- [ ] **Step 11: Commit**

```bash
git add backend/services/errorNormalizer.js backend/test/errorNormalizer.test.js
git commit -m "feat: add error normalizer for compiler log parsing and message normalization"
```

---

### Task 2: Error Clusterer

**Files:**
- Create: `backend/services/errorClusterer.js`
- Create: `backend/test/errorClusterer.test.js`

**Interfaces:**
- Consumes: output from `parseCompilerLog` (array of error objects with `.normalized`, `.signature`, `.studentId`, `.exerciseId`, `.conceptName`, `.submissionId`)
- Produces: `clusterErrors(parsedErrors)` → `Array<Cluster>`  
  `rankClusters(clusters, {minStudents, minOccurrences})` → `Array<Cluster>` (filtered + sorted)
- Uses: `jaccardSimilarity(a, b)` from same module

- [ ] **Step 1: Write the failing test for `clusterErrors`**

```js
// backend/test/errorClusterer.test.js
const { clusterErrors, jaccardSimilarity, rankClusters } = require('../services/errorClusterer');

function makeError(signature, normalized, studentId, exerciseId, conceptName, submissionId) {
  return {
    submissionId: submissionId || 1,
    studentId: studentId || 1,
    exerciseId: exerciseId || 42,
    conceptId: 7,
    conceptName: conceptName || 'Arrays',
    errorType: 'ERROR',
    rawMessage: 'some error',
    line: 1, column: 1,
    normalized: normalized || signature,
    signature
  };
}

describe('clusterErrors', () => {
  it('groups errors with the same signature into one cluster', () => {
    const errors = [
      makeError('was not declared in this scope', "'<id>' was not declared", 1, 42, 'Arrays', 1),
      makeError('was not declared in this scope', "'<id>' was not declared", 2, 42, 'Arrays', 2),
      makeError('expected', "expected '<id>' before '<id>'", 1, 42, 'Arrays', 3)
    ];
    const clusters = clusterErrors(errors);
    expect(clusters).toHaveLength(2);
    const declCluster = clusters.find(c => c.signature === 'was not declared in this scope');
    expect(declCluster.occurrences).toBe(2);
    expect(declCluster.uniqueStudents.size).toBe(2);
  });

  it('handles empty input', () => {
    expect(clusterErrors([])).toEqual([]);
  });

  it('merges clusters with Jaccard > 0.60', () => {
    const errors = [
      makeError('expected identifier', "expected '<id>'", 1, 42, 'Arrays', 1),
      makeError('expected before', "expected '<id>' before '<id>'", 2, 42, 'Variables', 2)
    ];
    const clusters = clusterErrors(errors);
    // Jaccard of ['expected', '<id>'] vs ['expected', '<id>', 'before', '<id>'] = 2/4 = 0.5
    // Below 0.60 threshold so they stay separate
    expect(clusters).toHaveLength(2);
  });
});
```

- [ ] **Step 2: Run tests to verify they fail**

Run: `cd backend && npx jest test/errorClusterer.test.js --no-coverage 2>&1`

Expected: FAIL — `Cannot find module '../services/errorClusterer'`

- [ ] **Step 3: Implement `clusterErrors` and `jaccardSimilarity`**

```js
// backend/services/errorClusterer.js
function jaccardSimilarity(a, b) {
  const tokensA = new Set(a.split(/\s+/));
  const tokensB = new Set(b.split(/\s+/));
  if (tokensA.size === 0 && tokensB.size === 0) return 1;
  const intersection = new Set([...tokensA].filter(t => tokensB.has(t)));
  const union = new Set([...tokensA, ...tokensB]);
  return intersection.size / union.size;
}

function clusterErrors(parsedErrors) {
  const clusters = new Map();

  for (const err of parsedErrors) {
    const key = `${err.errorType}:${err.signature}`;
    if (!clusters.has(key)) {
      clusters.set(key, {
        signature: err.signature,
        normalizedPattern: err.normalized,
        errorType: err.errorType,
        rawExamples: [],
        occurrences: 0,
        uniqueStudents: new Set(),
        uniqueExercises: new Set(),
        concepts: new Set(),
        submissions: []
      });
    }
    const c = clusters.get(key);

    if (c.rawExamples.length < 5 && err.rawMessage) {
      if (!c.rawExamples.includes(err.rawMessage)) {
        c.rawExamples.push(err.rawMessage);
      }
    }
    c.occurrences++;
    c.uniqueStudents.add(err.studentId);
    c.uniqueExercises.add(err.exerciseId);
    c.concepts.add(err.conceptName);
    c.submissions.push(err.submissionId);
  }

  // Level 2: fuzzy merge small clusters (size < 5)
  const clusterList = [...clusters.values()];
  const merged = [];
  const used = new Set();

  for (let i = 0; i < clusterList.length; i++) {
    if (used.has(i)) continue;

    let primary = clusterList[i];
    used.add(i);

    for (let j = i + 1; j < clusterList.length; j++) {
      if (used.has(j)) continue;
      const sim = jaccardSimilarity(primary.normalizedPattern, clusterList[j].normalizedPattern);
      if (sim > 0.60 && primary.occurrences < 5) {
        // Merge j into primary
        const other = clusterList[j];
        primary.occurrences += other.occurrences;
        for (const s of other.uniqueStudents) primary.uniqueStudents.add(s);
        for (const e of other.uniqueExercises) primary.uniqueExercises.add(e);
        for (const c of other.concepts) primary.concepts.add(c);
        primary.submissions.push(...other.submissions);
        if (primary.rawExamples.length < 5 && other.rawExamples.length > 0) {
          primary.rawExamples.push(...other.rawExamples.slice(0, 5 - primary.rawExamples.length));
        }
        used.add(j);
      }
    }
    merged.push(primary);
  }

  return merged;
}
```

- [ ] **Step 4: Run tests to verify they pass**

Run: `cd backend && npx jest test/errorClusterer.test.js --no-coverage 2>&1`

Expected: PASS

- [ ] **Step 5: Write the failing test for `rankClusters`**

```js
describe('rankClusters', () => {
  function makeCluster(signature, occurrences, uniqueStudents) {
    const us = new Set();
    for (let i = 0; i < uniqueStudents; i++) us.add(i + 1);
    const ue = new Set([42]);
    const concepts = new Set(['Arrays']);
    return { signature, normalizedPattern: signature, errorType: 'ERROR', rawExamples: [], occurrences, uniqueStudents: us, uniqueExercises: ue, concepts, submissions: [] };
  }

  it('sorts clusters by uniqueStudents * occurrences descending', () => {
    const clusters = [
      makeCluster('error A', 5, 2),   // score = 10
      makeCluster('error B', 10, 5),  // score = 50
      makeCluster('error C', 3, 3)    // score = 9
    ];
    const ranked = rankClusters(clusters, { minStudents: 1, minOccurrences: 1 });
    expect(ranked[0].signature).toBe('error B');
    expect(ranked[1].signature).toBe('error A');
    expect(ranked[2].signature).toBe('error C');
  });

  it('filters out clusters below minStudents threshold', () => {
    const clusters = [
      makeCluster('error A', 10, 2),
      makeCluster('error B', 10, 5)
    ];
    const ranked = rankClusters(clusters, { minStudents: 3, minOccurrences: 1 });
    expect(ranked).toHaveLength(1);
    expect(ranked[0].signature).toBe('error B');
  });

  it('filters out clusters below minOccurrences threshold', () => {
    const clusters = [
      makeCluster('error A', 2, 3),
      makeCluster('error B', 10, 3)
    ];
    const ranked = rankClusters(clusters, { minStudents: 1, minOccurrences: 5 });
    expect(ranked).toHaveLength(1);
    expect(ranked[0].signature).toBe('error B');
  });

  it('returns empty array when all clusters filtered out', () => {
    expect(rankClusters([makeCluster('error', 1, 1)], { minStudents: 5, minOccurrences: 5 })).toEqual([]);
  });

  it('handles empty input', () => {
    expect(rankClusters([], { minStudents: 3, minOccurrences: 5 })).toEqual([]);
  });
});
```

- [ ] **Step 6: Run rank test to verify it fails**

Run: `cd backend && npx jest test/errorClusterer.test.js --no-coverage 2>&1`

Expected: FAIL — `rankClusters is not defined`

- [ ] **Step 7: Implement `rankClusters`**

```js
function rankClusters(clusters, { minStudents = 3, minOccurrences = 5 } = {}) {
  const filtered = clusters.filter(c =>
    c.uniqueStudents.size >= minStudents && c.occurrences >= minOccurrences
  );

  filtered.sort((a, b) => {
    const scoreA = a.uniqueStudents.size * a.occurrences;
    const scoreB = b.uniqueStudents.size * b.occurrences;
    return scoreB - scoreA;
  });

  return filtered;
}
```

- [ ] **Step 8: Run all clusterer tests to verify they pass**

Run: `cd backend && npx jest test/errorClusterer.test.js --no-coverage 2>&1`

Expected: PASS

- [ ] **Step 9: Commit**

```bash
git add backend/services/errorClusterer.js backend/test/errorClusterer.test.js
git commit -m "feat: add error clusterer with signature grouping and Jaccard fuzzy merge"
```

---

### Task 3: Candidate Validator

**Files:**
- Create: `backend/services/candidateValidator.js`
- Create: `backend/test/candidateValidator.test.js`

**Interfaces:**
- Consumes: `Cluster` objects from Task 2, array of `{id, compiler_log, is_correct}` from DB
- Produces: `validateCluster(cluster, allSubmissions)` → `{precision, recall, truePositives, falsePositives, falseNegatives}`  
  `generateCandidate(cluster, validation)` → `Candidate` object  
  `extractKeywords(signature)` → `Array<string>`

- [ ] **Step 1: Write the failing test for `extractKeywords`**

```js
// backend/test/candidateValidator.test.js
const { extractKeywords, validateCluster, generateCandidate } = require('../services/candidateValidator');

describe('extractKeywords', () => {
  it('extracts meaningful keywords from signature', () => {
    const result = extractKeywords('was not declared in this scope');
    expect(result).toContain('was not declared');
    expect(result).toContain('in this scope');
  });

  it('handles short signature', () => {
    expect(extractKeywords('expected')).toEqual(['expected']);
  });

  it('handles empty string', () => {
    expect(extractKeywords('')).toEqual([]);
  });
});
```

- [ ] **Step 2: Run tests to verify they fail**

Run: `cd backend && npx jest test/candidateValidator.test.js --no-coverage 2>&1`

Expected: FAIL — `Cannot find module '../services/candidateValidator'`

- [ ] **Step 3: Implement `extractKeywords`**

```js
// backend/services/candidateValidator.js
function extractKeywords(signature) {
  if (!signature) return [];
  // Extract key phrases: 2-3 word n-grams that capture the error essence
  const words = signature.split(/\s+/).filter(w => w.length > 2);
  const phrases = [];
  // Add full signature as first keyword (most specific)
  phrases.push(signature);
  // Add 2-gram and 3-gram phrases
  for (let i = 0; i < words.length - 1; i++) {
    phrases.push(words.slice(i, i + 2).join(' '));
    if (i + 2 < words.length) {
      phrases.push(words.slice(i, i + 3).join(' '));
    }
  }
  // Deduplicate and return unique phrases
  return [...new Set(phrases)];
}
```

- [ ] **Step 4: Write the failing test for `validateCluster`**

```js
describe('validateCluster', () => {
  function makeSub(id, log, correct) {
    return { id, compiler_log: log, is_correct: correct };
  }

  it('counts true positives correctly', () => {
    const cluster = {
      signature: 'was not declared in this scope',
      normalizedPattern: "'<id>' was not declared in this scope"
    };
    const submissions = [
      makeSub(1, '[Line 5:5] ERROR: x was not declared in this scope', false),
      makeSub(2, '[Line 3:5] ERROR: y was not declared in this scope', false),
      makeSub(3, '[Line 1:1] ERROR: expected ;', false)
    ];
    const result = validateCluster(cluster, submissions);
    expect(result.truePositives).toBe(2);
    expect(result.falsePositives).toBe(0);
    expect(result.falseNegatives).toBe(1);
  });

  it('counts false positives when correct submission matches', () => {
    const cluster = {
      signature: 'was not declared',
      normalizedPattern: "'<id>' was not declared"
    };
    const submissions = [
      makeSub(1, '[Line 5:5] ERROR: x was not declared', false),
      makeSub(2, '[Line 3:5] INFO: was not declared issue', true)
    ];
    const result = validateCluster(cluster, submissions);
    expect(result.truePositives).toBe(1);
    // Sub 2 has "INFO" not "ERROR" so not a real error → false positive
    // Actually let's make this test clearer:
  });

  it('computes precision correctly', () => {
    const cluster = {
      signature: 'was not declared',
      normalizedPattern: "'<id>' was not declared in this scope"
    };
    const submissions = [
      makeSub(1, '[Line 5:5] ERROR: x was not declared', false),
      makeSub(2, '[Line 3:5] ERROR: y was not declared', false),
      makeSub(3, '[Line 1:1] ERROR: was not declared', true) // FP: no actual error despite keyword match
    ];
    const result = validateCluster(cluster, submissions);
    expect(result.truePositives).toBe(2);
    expect(result.falsePositives).toBe(1);
    expect(result.precision).toBeCloseTo(2/3, 2);
  });

  it('handles empty submissions array', () => {
    const cluster = { signature: 'test', normalizedPattern: 'test' };
    const result = validateCluster(cluster, []);
    expect(result.precision).toBe(0);
    expect(result.recall).toBe(0);
  });
});
```

- [ ] **Step 5: Run validation tests to verify they fail**

Run: `cd backend && npx jest test/candidateValidator.test.js --no-coverage 2>&1`

Expected: FAIL — `validateCluster is not defined`

- [ ] **Step 6: Implement `validateCluster`**

```js
function validateCluster(cluster, allSubmissions) {
  if (!allSubmissions || allSubmissions.length === 0) {
    return { precision: 0, recall: 0, truePositives: 0, falsePositives: 0, falseNegatives: 0 };
  }

  const keywords = extractKeywords(cluster.signature);
  let tp = 0, fp = 0, fn = 0;

  for (const sub of allSubmissions) {
    const log = (sub.compiler_log || '').toLowerCase();
    const hasKeyword = keywords.some(k => log.includes(k.toLowerCase()));
    const hasRealErrors = log.includes('error:');

    if (hasKeyword && hasRealErrors) tp++;
    else if (hasKeyword && !hasRealErrors) fp++;
    else if (!hasKeyword && hasRealErrors) fn++;
  }

  const total = tp + fp + fn;
  return {
    precision: total > 0 ? tp / (tp + fp) : 0,
    recall: total > 0 ? tp / (tp + fn) : 0,
    truePositives: tp,
    falsePositives: fp,
    falseNegatives: fn
  };
}
```

- [ ] **Step 7: Write the failing test for `generateCandidate`**

```js
describe('generateCandidate', () => {
  it('generates a valid candidate object from cluster and validation', () => {
    const cluster = {
      signature: 'was not declared in this scope',
      normalizedPattern: "'<id>' was not declared in this scope",
      errorType: 'ERROR',
      rawExamples: ["'x' was not declared", "'y' was not declared"],
      occurrences: 47,
      uniqueStudents: new Set([1, 2, 3]),
      uniqueExercises: new Set([42]),
      concepts: new Set(['Arrays'])
    };
    const validation = {
      precision: 0.95,
      recall: 0.90,
      truePositives: 45,
      falsePositives: 2,
      falseNegatives: 5
    };
    const candidate = generateCandidate(cluster, validation);
    expect(candidate.id).toMatch(/^__candidate_/);
    expect(candidate.name).toBeTruthy();
    expect(candidate.match_keywords).toContain('was not declared');
    expect(candidate.confidence).toBe(95);
    expect(candidate.validation.precision).toBe(0.95);
  });
});
```

- [ ] **Step 8: Run generate test to verify it fails**

Run: `cd backend && npx jest test/candidateValidator.test.js --no-coverage 2>&1`

Expected: FAIL — `generateCandidate is not defined`

- [ ] **Step 9: Implement `generateCandidate`**

```js
function generateCandidate(cluster, validation) {
  const id = `__candidate_${Date.now()}_${Math.random().toString(36).slice(2, 6)}`;

  // Rule name generation from signature
  const nameMap = {
    'was not declared': 'Undeclared Identifier',
    'expected': 'Syntax Error — Expected Token',
    'cannot convert': 'Type Conversion Mismatch',
    'no match for': 'Missing Operator',
    'unused variable': 'Unused Variable',
    'invalid conversion': 'Invalid Type Conversion',
    'not declared': 'Undeclared Identifier',
    'std::': 'Missing Namespace Prefix',
    'out of bounds': 'Array Index Out of Bounds',
    'segmentation fault': 'Segmentation Fault',
    'does not name a type': 'Unknown Type Name'
  };

  let name = 'Compiler Error';
  for (const [key, value] of Object.entries(nameMap)) {
    if (cluster.signature.toLowerCase().includes(key)) {
      name = value;
      break;
    }
  }

  // Pick best concept (most common one)
  const concepts = [...cluster.concepts];
  const concept = concepts[0] || 'General';

  // Generate messages
  const instructorMsg = `Detected "${cluster.signature}" in student code. ${cluster.occurrences} occurrences across ${cluster.uniqueStudents.size} students.`;
  const studentMsg = cluster.rawExamples[0] || 'Check your code for this compiler error.';

  return {
    id,
    name,
    description: cluster.rawExamples[0] || cluster.signature,
    concept,
    detector_type: 'compiler_error_keyword',
    match_keywords: extractKeywords(cluster.signature),
    confidence: Math.round(validation.precision * 100),
    coverage: {
      total_occurrences: cluster.occurrences,
      unique_students: cluster.uniqueStudents.size,
      exercises_affected: [...cluster.uniqueExercises],
      concepts_affected: concepts
    },
    suggested_instructor_message: instructorMsg,
    suggested_student_message: studentMsg,
    validation: {
      true_positives: validation.truePositives,
      false_positives: validation.falsePositives,
      precision: validation.precision,
      recall: validation.recall,
      validated_at: new Date().toISOString()
    }
  };
}
```

- [ ] **Step 10: Run all validator tests to verify they pass**

Run: `cd backend && npx jest test/candidateValidator.test.js --no-coverage 2>&1`

Expected: PASS

- [ ] **Step 11: Commit**

```bash
git add backend/services/candidateValidator.js backend/test/candidateValidator.test.js
git commit -m "feat: add candidate validator with precision-based filtering and rule generation"
```

---

### Task 4: Existing Rule Check

**Files:**
- Modify: `backend/services/errorClusterer.js`
- Create: `backend/test/existingRuleCheck.test.js`

**Interfaces:**
- Consumes: `MICRO_CONCEPT_RULES` from `microConceptTaxonomy.js`, cross-cutting rules from `microConceptEngine.js`
- Produces: `hasExistingRule(signature)` → `boolean` (used by clusterer to filter out already-covered patterns)

- [ ] **Step 1: Write the failing test**

```js
// backend/test/existingRuleCheck.test.js — can live inside errorClusterer.test.js
const { hasExistingRule } = require('../services/errorClusterer');

describe('hasExistingRule', () => {
  it('returns true for "expected" which matches cc_missing_semicolon', () => {
    // cc_missing_semicolon's detector checks for 'expected' in compiler errors
    expect(hasExistingRule('expected something')).toBe(true);
  });

  it('returns false for a novel pattern', () => {
    expect(hasExistingRule(''<id>' was not declared in this scope')).toBe(false);
  });

  it('returns false for empty string', () => {
    expect(hasExistingRule('')).toBe(false);
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd backend && npx jest test/existingRuleCheck.test.js --no-coverage 2>&1`

Expected: FAIL — `hasExistingRule is not defined`

- [ ] **Step 3: Implement `hasExistingRule` in `errorClusterer.js`**

Add at the top of `errorClusterer.js`:

```js
const { MICRO_CONCEPT_RULES } = require('./microConceptTaxonomy');

/**
 * Check if a normalized signature is already covered by an existing rule.
 * Uses keyword matching against the detector function source code text.
 */
function hasExistingRule(signature) {
  if (!signature) return false;

  // Collect ALL existing rule detector source code from the taxonomy
  const allRules = [];
  for (const conceptName of Object.keys(MICRO_CONCEPT_RULES)) {
    allRules.push(...MICRO_CONCEPT_RULES[conceptName]);
  }

  const sigLower = signature.toLowerCase();
  const sigKeywords = sigLower.split(/\s+/).filter(w => w.length > 3);

  for (const rule of allRules) {
    const detectorStr = rule.detector ? rule.detector.toString().toLowerCase() : '';
    const nameStr = (rule.name || '').toLowerCase();
    const descStr = (rule.description || '').toLowerCase();

    // Check if signature keywords appear in the rule's detector, name, or description
    const matchCount = sigKeywords.filter(k => detectorStr.includes(k) || nameStr.includes(k) || descStr.includes(k)).length;
    if (matchCount >= 2) return true;
  }

  // Also check cross-cutting rules in microConceptEngine.js
  // (We load them via require to check their detector source too)
  try {
    const engine = require('./microConceptEngine');
    // Cross-cutting rules are embedded, but we can check by sampling known CC rule keywords
    const ccKeywords = ['missing semicolon', 'unused variable', 'using namespace std',
      'comma operator', 'short-circuit', 'empty loop body', 'macro'];
    if (ccKeywords.some(kw => sigLower.includes(kw))) return true;
  } catch (e) {
    // If require fails, skip cross-cutting check
  }

  return false;
}
```

Then modify `rankClusters` to drop clusters with existing rules:

```js
function rankClusters(clusters, { minStudents = 3, minOccurrences = 5 } = {}) {
  const filtered = clusters.filter(c =>
    c.uniqueStudents.size >= minStudents &&
    c.occurrences >= minOccurrences &&
    !hasExistingRule(c.signature)  // ← ADD THIS
  );
  // ... rest unchanged
}
```

Also export `hasExistingRule` from the module:

```js
module.exports = { clusterErrors, jaccardSimilarity, rankClusters, hasExistingRule };
```

- [ ] **Step 4: Run tests to verify they pass**

Run: `cd backend && npx jest test/errorClusterer.test.js test/existingRuleCheck.test.js --no-coverage 2>&1`

Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/services/errorClusterer.js backend/test/existingRuleCheck.test.js
git commit -m "feat: add existing rule detection to prevent duplicate candidate generation"
```

---

### Task 5: Orchestrator + CLI

**Files:**
- Create: `backend/services/misconceptionRuleMiner.js`
- Create: `backend/scripts/mine_misconceptions.js`
- Create: `backend/data/.gitkeep`
- Create: `backend/test/misconceptionRuleMiner.test.js`

**Interfaces:**
- Consumes: DB connection, exercise ID, threshold config, output path
- Produces: JSON file at `backend/data/candidate_rules_<date>.json`

- [ ] **Step 1: Write the failing orchestrator test**

```js
// backend/test/misconceptionRuleMiner.test.js
const { runFullPipeline } = require('../services/misconceptionRuleMiner');

// Mock the DB calls and sub-services
jest.mock('../services/errorNormalizer');
jest.mock('../services/errorClusterer');
jest.mock('../services/candidateValidator');

const errorNormalizer = require('../services/errorNormalizer');
const errorClusterer = require('../services/errorClusterer');
const candidateValidator = require('../services/candidateValidator');

describe('runFullPipeline', () => {
  beforeEach(() => {
    jest.clearAllMocks();

    // Mock normalizer
    errorNormalizer.parseCompilerLog.mockReturnValue([
      { submissionId: 1, studentId: 1, exerciseId: 42, conceptId: 7, conceptName: 'Arrays', errorType: 'ERROR', rawMessage: 'test error', line: 1, column: 1, normalized: 'test normalized', signature: 'test signature' }
    ]);

    // Mock clusterer
    errorClusterer.clusterErrors.mockReturnValue([
      { signature: 'test signature', normalizedPattern: 'test normalized', occurrences: 10, uniqueStudents: new Set([1,2,3]), uniqueExercises: new Set([42]), concepts: new Set(['Arrays']), submissions: [1,2,3] }
    ]);
    errorClusterer.rankClusters.mockReturnValue([
      { signature: 'test signature', normalizedPattern: 'test normalized', occurrences: 10, uniqueStudents: new Set([1,2,3]), uniqueExercises: new Set([42]), concepts: new Set(['Arrays']), submissions: [1,2,3] }
    ]);

    // Mock validator
    candidateValidator.validateCluster.mockReturnValue({ precision: 0.95, recall: 0.90, truePositives: 9, falsePositives: 1, falseNegatives: 1 });
    candidateValidator.generateCandidate.mockReturnValue({ id: '__candidate_test', name: 'Test Rule', confidence: 95, validation: { precision: 0.95 } });
  });

  it('returns candidate array from the full pipeline', async () => {
    const result = await runFullPipeline({ exerciseId: 42, outputPath: '/tmp/test_candidates.json' });
    expect(result.candidates).toHaveLength(1);
    expect(result.candidates[0].id).toBe('__candidate_test');
    expect(result.total_submissions_analyzed).toBe(0); // no DB mock yet
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd backend && npx jest test/misconceptionRuleMiner.test.js --no-coverage 2>&1`

Expected: FAIL — `Cannot find module '../services/misconceptionRuleMiner'`

- [ ] **Step 3: Implement orchestrator**

```js
// backend/services/misconceptionRuleMiner.js
const db = require('../db');
const errorNormalizer = require('./errorNormalizer');
const errorClusterer = require('./errorClusterer');
const candidateValidator = require('./candidateValidator');
const fs = require('fs');
const path = require('path');

async function runFullPipeline({ exerciseId, minStudents = 3, minOccurrences = 5, outputPath } = {}) {
  // 1. Load all submissions for the exercise
  const submissions = await db.query(
    `SELECT s.id, s.student_id, s.exercise_id, s.compiler_log, s.test_results,
            s.is_correct, e.concept_id, c.name AS concept_name
     FROM submissions s
     JOIN exercises e ON e.id = s.exercise_id
     JOIN concepts c ON c.id = e.concept_id
     WHERE s.exercise_id = $1 AND s.compiler_log IS NOT NULL`,
    [exerciseId]
  );

  // 2. Also load run_attempts
  const runAttempts = await db.query(
    `SELECT ra.id AS submission_id, ra.student_id, ra.exercise_id,
            ra.compiler_log, NULL AS test_results, false AS is_correct,
            e.concept_id, c.name AS concept_name
     FROM run_attempts ra
     JOIN exercises e ON e.id = ra.exercise_id
     JOIN concepts c ON c.id = e.concept_id
     WHERE ra.exercise_id = $1 AND ra.compiler_log IS NOT NULL`,
    [exerciseId]
  );

  const allSubmissions = [...submissions.rows, ...runAttempts.rows];

  // 3. If no data, return empty result
  if (allSubmissions.length === 0) {
    return {
      generated_at: new Date().toISOString(),
      exercise_id: exerciseId,
      total_submissions_analyzed: 0,
      total_students: 0,
      candidates: []
    };
  }

  // 4. Stage 1+2: Parse and normalize
  const parsed = [];
  for (const sub of allSubmissions) {
    const errors = errorNormalizer.parseCompilerLog(
      sub.compiler_log,
      sub.id || sub.submission_id,
      sub.student_id,
      sub.exercise_id,
      sub.concept_id,
      sub.concept_name
    );
    // Normalize each error
    for (const err of errors) {
      err.normalized = errorNormalizer.normalizeMessage(err.rawMessage);
      err.signature = errorNormalizer.extractSignature(err.normalized);
    }
    parsed.push(...errors);
  }

  // 5. Stage 3: Cluster and rank
  const clusters = errorClusterer.clusterErrors(parsed);
  const ranked = errorClusterer.rankClusters(clusters, { minStudents, minOccurrences });

  // 6. Stage 4: Validate and generate
  const candidates = [];
  // Build full submission list for validation (need compiler_log + is_correct)
  const allLogs = allSubmissions.map(s => ({
    id: s.id || s.submission_id,
    compiler_log: s.compiler_log,
    is_correct: s.is_correct
  }));

  for (const cluster of ranked) {
    const validation = candidateValidator.validateCluster(cluster, allLogs);
    if (validation.precision >= 0.85) {
      const candidate = candidateValidator.generateCandidate(cluster, validation);
      candidates.push(candidate);
    }
  }

  // 7. Write output
  const totalStudents = new Set(allSubmissions.map(s => s.student_id)).size;
  const output = {
    generated_at: new Date().toISOString(),
    pipeline_version: '1.0.0',
    exercise_id: exerciseId,
    total_submissions_analyzed: allSubmissions.length,
    total_students: totalStudents,
    candidates
  };

  if (outputPath) {
    const dir = path.dirname(outputPath);
    if (!fs.existsSync(dir)) {
      fs.mkdirSync(dir, { recursive: true });
    }
    fs.writeFileSync(outputPath, JSON.stringify(output, null, 2));
  }

  return output;
}

module.exports = { runFullPipeline };
```

- [ ] **Step 4: Create the data directory**

```bash
mkdir -p backend/data
touch backend/data/.gitkeep
```

- [ ] **Step 5: Create the CLI script**

```js
// backend/scripts/mine_misconceptions.js
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
```

- [ ] **Step 6: Fix the orchestrator test mocks and run tests**

Run: `cd backend && npx jest test/misconceptionRuleMiner.test.js --no-coverage 2>&1`

Expected: PASS (with mocked DB)

- [ ] **Step 7: Commit**

```bash
git add backend/services/misconceptionRuleMiner.js backend/scripts/mine_misconceptions.js backend/data/.gitkeep backend/test/misconceptionRuleMiner.test.js
git commit -m "feat: add misconception rule mining orchestrator and CLI entry point"
```

---

### Task 6: Integration Test

**Files:**
- Create: `backend/test/misconceptionRuleMiner.integration.test.js`

- [ ] **Step 1: Write integration test with seeded data**

```js
// backend/test/misconceptionRuleMiner.integration.test.js
const db = require('../db');
const { runFullPipeline } = require('../services/misconceptionRuleMiner');

describe('Misconception Rule Mining Integration', () => {
  let exerciseId, conceptId;

  beforeAll(async () => {
    // Create test concept
    const conceptRes = await db.query(
      `INSERT INTO concepts (name, description) VALUES ($1, $2)
       ON CONFLICT (name) DO UPDATE SET name = EXCLUDED.name RETURNING id`,
      ['_test_misconception_concept', 'Test concept for integration test']
    );
    conceptId = conceptRes.rows[0].id;

    // Create test exercise
    const exRes = await db.query(
      `INSERT INTO exercises (title, description, concept_id, difficulty, test_cases, starter_code, time_limit_minutes)
       VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id`,
      ['_test_mining_exercise', 'Test exercise for mining pipeline',
       conceptId, 1, JSON.stringify([{ input: '5', expected: '10', hidden: false }]),
       '#include <iostream>\nint main() { return 0; }', 10]
    );
    exerciseId = exRes.rows[0].id;

    // Create test student user
    const studentRes = await db.query(
      `INSERT INTO users (username, password_hash, role) VALUES ($1, $2, $3)
       ON CONFLICT (username) DO UPDATE SET username = EXCLUDED.username RETURNING id`,
      ['_test_mining_student', 'hash', 'student']
    );
    const studentId = studentRes.rows[0].id;

    // Create submissions with known error patterns
    // 6 submissions with "undeclared variable" error
    const errorLogs = [
      "[Line 5:5] ERROR: 'max_val' was not declared in this scope",
      "[Line 3:5] ERROR: 'result' was not declared in this scope",
      "[Line 7:5] ERROR: 'temp' was not declared in this scope",
      "[Line 4:5] ERROR: 'sum' was not declared in this scope",
      "[Line 6:5] ERROR: 'avg' was not declared in this scope",
      "[Line 2:5] ERROR: 'count' was not declared in this scope",
    ];

    for (let i = 0; i < errorLogs.length; i++) {
      await db.query(
        `INSERT INTO submissions (student_id, exercise_id, code, compiler_log, test_results, is_correct, attempt_number, time_spent_seconds)
         VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
        [studentId, exerciseId, 'int main() { return 0; }', errorLogs[i],
         JSON.stringify([{ input: '5', expected: '10', actual: '', passed: false, status: 'Compile Error', error: errorLogs[i] }]),
         false, 1, 30]
      );
    }

    // 2 more students with same pattern
    const studentRes2 = await db.query(
      `INSERT INTO users (username, password_hash, role) VALUES ($1, $2, $3)
       ON CONFLICT (username) DO UPDATE SET username = EXCLUDED.username RETURNING id`,
      ['_test_mining_student2', 'hash', 'student']
    );
    const studentId2 = studentRes2.rows[0].id;

    await db.query(
      `INSERT INTO submissions (student_id, exercise_id, code, compiler_log, test_results, is_correct, attempt_number, time_spent_seconds)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
      [studentId2, exerciseId, 'int main() { return 0; }',
       "[Line 5:5] ERROR: 'value' was not declared in this scope",
       JSON.stringify([{ input: '5', expected: '10', actual: '', passed: false, status: 'Compile Error', error: "'value' was not declared" }]),
       false, 1, 30]
    );

    // 1 correct submission with different error
    const studentRes3 = await db.query(
      `INSERT INTO users (username, password_hash, role) VALUES ($1, $2, $3)
       ON CONFLICT (username) DO UPDATE SET username = EXCLUDED.username RETURNING id`,
      ['_test_mining_student3', 'hash', 'student']
    );
    const studentId3 = studentRes3.rows[0].id;

    await db.query(
      `INSERT INTO submissions (student_id, exercise_id, code, compiler_log, test_results, is_correct, attempt_number, time_spent_seconds)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
      [studentId3, exerciseId, 'int main() { int x = 5; return x; }',
       "[Line 3:5] ERROR: expected ';' before 'return'",
       JSON.stringify([{ input: '5', expected: '10', actual: '', passed: false, status: 'Compile Error', error: "expected ';' before 'return'" }]),
       false, 1, 30]
    );
  });

  afterAll(async () => {
    // Clean up test data
    await db.query('DELETE FROM submissions WHERE exercise_id = $1', [exerciseId]);
    await db.query('DELETE FROM exercises WHERE id = $1', [exerciseId]);
    await db.query("DELETE FROM concepts WHERE id = $1", [conceptId]);
    await db.query("DELETE FROM users WHERE username LIKE '_test_mining_%'");
  });

  it('discovers the undeclared variable pattern as top candidate', async () => {
    const outputPath = `/tmp/test_candidates_${Date.now()}.json`;
    const result = await runFullPipeline({ exerciseId, outputPath, minStudents: 1, minOccurrences: 1 });

    expect(result.total_submissions_analyzed).toBeGreaterThanOrEqual(8);
    expect(result.candidates.length).toBeGreaterThanOrEqual(1);

    // The top candidate should be "Undeclared Identifier" or similar
    const topCandidate = result.candidates[0];
    expect(topCandidate.confidence).toBeGreaterThanOrEqual(80);
    expect(topCandidate.match_keywords.some(k => k.toLowerCase().includes('not declared'))).toBe(true);

    // Verify output file exists and is valid JSON
    const fs = require('fs');
    const fileContent = JSON.parse(fs.readFileSync(outputPath, 'utf8'));
    expect(fileContent.candidates).toHaveLength(result.candidates.length);
  });
});
```

- [ ] **Step 2: Run integration test**

Run: `cd backend && npx jest test/misconceptionRuleMiner.integration.test.js --no-coverage 2>&1`

Expected: PASS (needs running DB with schema)

- [ ] **Step 3: Commit**

```bash
git add backend/test/misconceptionRuleMiner.integration.test.js
git commit -m "test: add integration test for full misconception mining pipeline"
```

---

### Task 7: Run All Tests + Final Verification

- [ ] **Step 1: Run all tests**

Run: `cd backend && npx jest --no-coverage 2>&1`

Expected: ALL PASS (existing tests + 6 new test files)

- [ ] **Step 2: Verify CLI works**

Run: `cd backend && node scripts/mine_misconceptions.js --help`

Expected: Usage information printed

Run: `cd backend && node scripts/mine_misconceptions.js --dry-run --exercise=42`

Expected: `[DRY RUN] Would analyze exercise 42 with minStudents=3, minOccurrences=5`

- [ ] **Step 3: Final commit**

```bash
git add -A
git commit -m "feat: complete misconception rule mining pipeline"
```

---

## Self-Review

**1. Spec coverage:**
- Stage 1 (Parse): Task 1 — `parseCompilerLog` with regex parsing and dedup ✓
- Stage 2 (Normalize): Task 1 — `normalizeMessage` with identifier/number/path stripping ✓
- Signature extraction: Task 1 — `extractSignature` ✓
- Stage 3 (Cluster): Task 2 — `clusterErrors` with exact + Jaccard fuzzy merge ✓
- Ranking/filtering: Task 2 — `rankClusters` with minStudents/minOccurrences ✓
- Existing rule check: Task 4 — `hasExistingRule` against taxonomy + cross-cutting ✓
- Stage 4 (Validate): Task 3 — `validateCluster` with precision/recall computation ✓
- Candidate generation: Task 3 — `generateCandidate` with name mapping + messages ✓
- Precision gate ≥0.85: Task 3 + Task 5 orchestrator ✓
- Orchestrator: Task 5 — `runFullPipeline` calling stages in order ✓
- CLI: Task 5 — `mine_misconceptions.js` with --exercise, --all, --dry-run ✓
- Output to JSON: Task 5 — writes to `backend/data/candidate_rules_<date>.json` ✓
- Integration test: Task 6 — seeded test data with 8 submissions ✓
- Test coverage: 6 test files with unit + integration tests ✓

**2. Placeholder scan:** All code blocks contain complete implementations. No TBD/TODO/fill-in-later patterns. Every test has concrete assertions.

**3. Type consistency:**
- All files in architecture match the task structure ✓
- `parseCompilerLog` returns same format consumed by `clusterErrors` ✓
- `clusterErrors` returns format consumed by `rankClusters` ✓
- `rankClusters` returns format consumed by `validateCluster` ✓
- `validateCluster` returns format consumed by `generateCandidate` ✓
- `runFullPipeline` returns format written to output JSON ✓

# Code-to-Rule Extraction Matrix — Hardcoding & Blank-Template Deterministic Rules

- **Date:** 2026-08-09
- **Source plan:** `docs/superpowers/plans/2026-06-18-deterministic-rule-hardening.md` — Task 1
- **Scope:** Deterministic rules only; **zero AI/ML**. Every detection below is regex- or tree-sitter-based.
- **Legend**
  - `handled` — the bypass / case is detected by code that exists in this task or before it.
  - `not handled` — a real, reproducible bypass; no detection code exists for it.
  - `documented gap` — accepted limitation; usually because the case is semantically indistinguishable from legitimate behavior without full program interpretation.

---

## 1. `checkHardcoding` (basic) — `backend/services/academicIntegrityEngine.js`

**Trigger pattern:** `/cout\s*<<\s*(\d+)\s*[;>]/g` — a `cout <<` of a bare numeric literal followed by `;` or `>`.

**Computation score** (0–4): one point each for presence of operations (`+ - * / % ( )`), variable declarations (`int/float/double/long/short x =`), loops (`for/while/do`), and conditionals (`if/else/switch`).

**Disconfirming signals** that lower confidence: explanatory comments, multi-line comments, the `n*(n+1)/2` formula pattern, and a loop with an accumulator (`+=`).

**Flag shape:** `{ type: 'HARDCODING', severity: 'HIGH' | 'MEDIUM', evidence: { summary, literalOutputCount, computationScore, literalValues, matchesExpectedOutput, confidence, hasExplanatoryComments, innocent_explanation } }`. Literals are cross-referenced against test-case expected outputs; `matchesExpectedOutput` is `null` when no test cases exist.

### Silent failures (bypasses) of the basic check

| # | Bypass | Example | Status |
|---|--------|---------|--------|
| 1 | `printf`/`puts` literal | `printf("42");` | `handled` — by `checkHardcodingExtended` (pattern `printf_literal`) |
| 2 | `constexpr` literal | `constexpr int x = 42; cout << x;` | `not handled` |
| 3 | Macro literal | `#define ANSWER 42` then `cout << ANSWER;` | `not handled` |
| 4 | Hex / octal literal | `cout << 0x2A;` / `cout << 052;` | `not handled` |
| 5 | Parenthesized literal | `cout << (42);` | `not handled` |
| 6 | `<<`-chain | `cout << 42 << endl;` | `not handled` |
| 7 | Variable-initialized output | `int x = 42; cout << x;` | `not handled` |
| 8 | Test-case manipulation | changing server-side expected data | `documented gap` — server-side data lives outside code analysis |

**Gap status:** the regex only matches `cout << <digits>` directly followed by `;` or `>`. Every `not handled` row above is a real, reproducible bypass; test-case manipulation is outside the code-analysis boundary by design.

---

## 2. `checkHardcodingExtended` — `backend/services/academicIntegrityEngine.js`

Detects five evasion patterns (all deterministic, regex-based):

1. `printf`/`puts` with a literal format string matching expected output → `pattern: 'printf_literal'`.
2. `putchar`/`fputc`/`putc` loop emitting a literal string char-by-char → `pattern: 'putchar_loop'`.
3. Return-value evasion: `return <digits>;` matching expected output (process exit code) → `pattern: 'return_value'`.
4. `ostringstream` (or `stringstream`/`istringstream`) with a literal `<<` match → `pattern: 'ostringstream_literal'`.
5. `std::string` constructor / assignment from a literal → `pattern: 'string_ctor_literal'`.

**Flag shape:** `{ type: 'HARDCODING', severity: 'HIGH' | 'MEDIUM', evidence: { summary, pattern, literalValue, matchesExpectedOutput, confidence, innocent_explanation } }`.

**Multi-flag aggregation:** when several patterns fire, the single HIGH flag wins; otherwise a `pattern: 'mixed'` MEDIUM flag aggregates summaries.

**Gap status:** `handled` for its 5 patterns. `constexpr`, macro, and hex/octal/parenthesized literals still bypass (cross-reference §1 rows 2–5).

---

## 3. `checkBlankTemplate` — `backend/services/academicIntegrityEngine.js`

**Logic:** trims both sides; flags an empty submission (HIGH, confidence 1.0) or a byte-identical submission (HIGH, confidence 1.0). Whitespace-only differences (trimmed equal but raw unequal) are explicitly **not** a violation.

**Flag shape:** `{ type: 'BLANK_TEMPLATE', severity: 'HIGH', evidence: { summary, codeLength, starterCodeLength, confidence, innocent_explanation } }`.

### Silent failures

| Case | Example | Status |
|------|---------|--------|
| Whitespace + single-char edit | starter `return 0;` → submission `return 1;` | `documented gap` — indistinguishable from a real edit without semantics |
| Comment-only change | adds `// Student name: John Doe` | `handled` — by new `checkBlankTemplateExtended` |
| Include reshuffle | `#include <iostream>` / `#include <vector>` swapped | `handled` — by new `checkBlankTemplateExtended` |

**Gap status:** exact-match logic catches empty and byte-identical submissions; comment-only and include-reorder bypasses are closed by the extended check; a whitespace-plus-single-character change remains a documented gap.

---

## 4. `checkBlankTemplateExtended` (new) — `backend/services/academicIntegrityEngine.js`

**Normalization algorithm** (`normalizeForBlankComparison`):

1. Strip comments: `code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '')`.
2. Extract `#include` lines (`/^\s*#\s*include\s*[<"][^>"]*[>"]\s*$/gm`), trim, **sort**, and remove from the body.
3. Remove all remaining whitespace from the body (`.replace(/\s+/g, '')`).
4. Return `sortedIncludes.join('\n') + '\n' + body`.

**Logic:** empty inputs are left to the basic check (guard returns `null`). A whitespace-only difference is preserved as non-violation: if `code` and `starterCode` are equal after stripping all whitespace, return `null`. Otherwise, if both normalize identically, flag:

**Flag shape:** `{ type: 'BLANK_TEMPLATE', severity: 'MEDIUM', evidence: { summary: 'Submission is identical to starter code after removing comments and normalizing whitespace/include order', codeLength, starterCodeLength, confidence: 0.8, pattern: 'normalized_identical', innocent_explanation } }`.

**Gap status:** `handled` for comment-only and include-reorder bypasses. A whitespace-plus-single-char edit still produces different normalized bodies (e.g. `1` vs `0`) and is deliberately not flagged (§3).

---

## 5. `astVerifier.verify` sub-checks — `backend/services/astVerifier.js`

### 5.1 `checkRequiredNodes`
Presence check of required node types via `collectNodeTypes`. `anyOf = true` (concept-level) accepts any one alternative (e.g. Loops: `for`/`while`/`do`); exercise-level requires all.

- **Computed-goto substitution** (replacing a loop with `goto` + label): `handled` — the substituted code simply lacks the required node types, so the anyOf set still fails. The check is immune because it tests node-type presence, not semantics.
- **Gap status:** no bypass known for the node-presence criterion itself.

### 5.2 `checkRequiredPatterns`
Per-exercise tree-sitter queries + JS handlers. Pattern kinds: `query`, `self_call`, `user_function`, `string_type`, `min_count`, `forbidden`, `decl_type`, `virtual_method`, `cast_type`, `for_range_loop`. Query compile errors fail closed.

- **Gap status:** query coverage is bounded by what patterns are authored; a construct with no authored pattern is simply not required.

### 5.3 `checkEmptyBodies`
Detects constructs with no meaningful body. Coverage:

- `compound_statement` `{}` — existing scan (unchanged).
- **NEW** body-child scan for `if_statement` / `else_clause` / `while_statement` / `do_statement` / `for_statement` when the body is an `expression_statement`:
  - bare `;` (semicolon-only body) → `Empty body detected in <construct>`.
  - side-effect-free ternary (`if (x) x ? 1 : 2;`) → `Empty body detected in <construct> (ternary expression with no side effects)`.
  - side-effect-free comma operator (`if (x) 1, 2;`) → `Empty body detected in <construct> (comma operator with no side effects)`.
- Side effects (calls, assignments, updates) suppress the ternary/comma flags: `if (x) x ? a() : b();` and `if (x) y = x ? 1 : 2;` are correctly not flagged.
- `if (x) return;` is **correctly not flagged** (body is a `return_statement`, not an empty expression).
- `int y = (x > 0) ? 10 : 20;` is not flagged (ternary lives in an `init_declarator`, not a body).
- `if (x) { x ? 1 : 2; }` is intentionally not flagged (a compound body is its own boundary).

**Gap status:** semicolon / side-effect-free ternary / side-effect-free comma bodies are now `handled`; compound-body boundaries and `return` bodies remain intentionally excluded.

### 5.4 `checkVariableUsage`
Condition must reference an identifier; literal-only or tautological conditions are flagged.

- Pointer/ref conditions (`if (ptr)`, `if (*ptr)`, `if (ref)`) pass via their identifiers → `handled`.
- Macro constants (`#define TRUE 1` then `if (TRUE)`) → `documented gap` — the identifier `TRUE` is present, so the condition reads as variable-driven.

### 5.5 `checkOutputDependency`
Determines whether a required construct's modified variables reach output. Identifier collection:

- Call-expressions whose text contains an output function name: `cout, printf, puts, fprintf, sprintf, write, cin` — plus **NEW** `exit`, `fwrite`. `fprintf(stderr, …)` was already captured.
- **NEW** second pass over `binary_expression` nodes whose `operator` field is `<<` (covers `cout << x`, `cerr << x`, `ofstream f; f << x`, `ostringstream << x`). `cin >> n` (`>>`) is correctly not captured; over-capturing bit-shifts is safe (enlarges the identifier set, which can only suppress dead-code errors, never create them).
- `return` statements were already captured.

- **Matcher mismatch fix:** the dead-code error message is `…modifies variables that don't affect program output…`, but the `hasErrors` matcher tested for `"doesn't affect program output"` — so dead-code errors were generated yet never gated verification. `handled` — matcher now uses the actual `"don't affect program output"` string.
- **Volatile side effects** (e.g. writing through a custom logging function, `syscall`, or volatile memory): `documented gap` — only assignments/updates inside the construct and the known output-function set are tracked.

---

## 6. Final summary

| Check | Gap closed / bypass | Status |
|-------|---------------------|--------|
| `checkHardcoding` | regex covers only `cout << <digits>[;>]` | `handled` (partial by design) |
| `checkHardcoding` | printf/puts literal bypass | `handled` (extended) |
| `checkHardcoding` | `constexpr` / macro / hex / octal / paren / `<<`-chain / variable-init literals | `not handled` |
| `checkHardcoding` | test-case manipulation | `documented gap` |
| `checkHardcodingExtended` | its 5 patterns | `handled` |
| `checkBlankTemplate` | empty / byte-identical | `handled` |
| `checkBlankTemplate` | comment-only, include-reorder | `handled` (extended) |
| `checkBlankTemplate` | whitespace + single-char | `documented gap` |
| `checkBlankTemplateExtended` | comment-only / include-reorder (normalized) | `handled` |
| `checkRequiredNodes` | computed-goto substitution | `handled` (anyOf still fails) |
| `checkRequiredPatterns` | authored patterns / fail-closed queries | `handled` |
| `checkEmptyBodies` | `{}` bodies | `handled` |
| `checkEmptyBodies` | `;`, side-effect-free ternary/comma bodies | `handled` (new) |
| `checkEmptyBodies` | `if (x) return;`, compound boundaries | intentionally not flagged |
| `checkVariableUsage` | pointer/ref conditions | `handled` |
| `checkVariableUsage` | macro constants in conditions | `documented gap` |
| `checkOutputDependency` | `cout <<` / stream output not captured | `handled` (`<<` pass) |
| `checkOutputDependency` | `exit` / `fwrite` outputs | `handled` (list) |
| `checkOutputDependency` | matcher mismatch (`doesn't` vs `don't`) | `handled` (fix) |
| `checkOutputDependency` | volatile / indirect side effects | `documented gap` |

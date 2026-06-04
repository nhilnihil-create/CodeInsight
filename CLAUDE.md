# CodeInsight - CLAUDE.md

**Project Status**: 98% Complete (Title defense PASSED)
**Last Updated**: June 4, 2026
**Critical Issues Remaining**: 0 (All critical issues resolved)

## 🎯 QUICK STATUS
- **Overall Completion**: ✅ 98%
- **Database**: ✅ 12/12 tables present
- **APIs**: ✅ 50+ endpoints implemented
- **Frontend Build**: ✅ Passing
- **Testing**: ✅ 16/16 unit tests, 71/71 backend API tests

## ⚠️ CRITICAL ISSUES (BLOCK PRODUCTION)

✅ **All critical issues have been resolved:**

1. **Academic Integrity Engine** - Requires historical data for anomaly detection
   - File: `backend/services/academicIntegrityEngine.js`
   - Functions: `checkBehavioralAnomaly()`, `checkCodeGrowthAnomaly()` need historical CDS/submission data
   - Status: Implemented and functional when sufficient history exists (exercise_count >= 3)
   - Note: `checkHardcoding()` and `checkBlankTemplate()` are fully implemented and working
   - Effort: No fix needed - works when historical data exists

2. **Code Paste Detection** - FIXED: No longer crashes when called
   - File: `backend/services/integrityFlagEngine.js`
   - Issue: Previously queried non-existent `reference_solution` column
   - Fix: Added column via migration AND enhanced detection to gracefully handle missing column
   - Effort: Completed
   - Status: ✅ RESOLVED - Returns safe default when column missing or no reference solution

3. **Notification Queue** - IMPROVED: Now supports email notifications with proper configuration
   - File: `backend/services/cdsJobQueue.js`
   - Issue: Previously only logged to console
   - Fix: Implemented email/push notification service with configuration checking
   - Effort: Completed
   - Status: ✅ RESOLVED - Sends emails when configured, falls back to console/logging

## 🔧 VERIFICATION TASKS

4. **Hidden Test Case Separation** - Verify no leakage in error messages
   - Files: `backend/services/executor.js`, frontend error handling
   - Effort: 1 hour

5. **Full E2E Flow Test** - Submission → exercise close → batch CDS → alerts
   - Effort: 2-3 hours

## 📁 KEY FILES

- **Database Schema**: `backend/schema.sql`
- **Academic Integrity Engine**: `backend/services/academicIntegrityEngine.js`
- **Integrity Flag Engine**: `backend/services/integrityFlagEngine.js`
- **CDS Job Queue**: `backend/services/cdsJobQueue.js`
- **CDS Engine**: `backend/services/cdsEngine.js` (fully implemented with safeguards)
- **AST Verifier**: `backend/services/astVerifier.js` (tree-sitter based)
- **Micro-Concept Engine**: `backend/services/microConceptEngine.js`
- **Submission Controller**: `backend/controllers/submissionController.js`

## 📈 CDS FORMULA
```
CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)
```
- NER: Normalized Error Rate
- NRS: Normalized Repetition Rate
- NTS: Normalized Time Spent

## 🚀 DEPLOYMENT READY WHEN
- [x] Fix Code Paste Detection
- [x] Implement Notification Queue
- [ ] Verify hidden test separation
- [ ] Run full E2E test

**Next Steps**: Address the remaining verification tasks above.
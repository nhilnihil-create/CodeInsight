/**
 * Auto-Close Service
 * Automatically closes exercises at their deadline and triggers batch CDS computation
 * Implements Objective 4 from gemini.md (Automation & ISO Evaluation Hooks)
 */

const schedule = require('node-schedule');
const db = require('../config/db');
const cdsEngine = require('./cdsEngine.js');

/**
 * Start the auto-close service
 * This should be called when the application starts
 */
function startAutoCloseService() {
  console.log('Starting auto-close service...');

  // Schedule job to run every 5 minutes to check for exercises to close
  schedule.scheduleJob('*/5 * * * *', async () => {
    try {
      console.log('[AutoClose] Checking for exercises to close...');
      await processExercisesForAutoClose();
    } catch (error) {
      console.error('[AutoClose] Error in auto-close service:', error);
    }
  });

  console.log('[AutoClose] Service started. Will check every 5 minutes.');
}

/**
 * Process exercises that are past their deadline and close them
 * @param {Object} [client] - Optional transaction client for testing
 */
async function processExercisesForAutoClose(client) {
  const queryFn = client ? (text, params) => client.query(text, params) : (text, params) => db.query(text, params);

  try {
    // Find exercises that are past deadline and not yet closed
    const exercisesRes = await queryFn(
      `SELECT id, title, deadline, created_by
       FROM exercises
       WHERE deadline IS NOT NULL
         AND deadline < NOW()
         AND closed_at IS NULL`
    );

    const exercises = exercisesRes.rows;

    if (exercises.length === 0) {
      // No exercises to close
      return;
    }

    console.log(`[AutoClose] Found ${exercises.length} exercises to close`);

    // Process each exercise
    for (const exercise of exercises) {
      try {
        console.log(`[AutoClose] Closing exercise: ${exercise.title} (ID: ${exercise.id})`);

        // Close the exercise (set closed_at timestamp)
        await queryFn(
          'UPDATE exercises SET closed_at = NOW() WHERE id = $1',
          [exercise.id]
        );

        // Trigger batch CDS computation (already generates alerts internally)
        await cdsEngine.computeBatchCDS(exercise.id, client || db);

        console.log(`[AutoClose] Successfully closed exercise ${exercise.id}`);

        // Optional: Log this action for audit purposes
        await queryFn(
          `INSERT INTO auto_close_log (exercise_id, closed_at, triggered_by)
           VALUES ($1, NOW(), 'auto_close_service')`,
          [exercise.id]
        );

      } catch (exerciseError) {
        console.error(`[AutoClose] Failed to close exercise ${exercise.id}:`, exerciseError);
        // Continue with other exercises even if one fails
      }
    }
  } catch (error) {
    console.error('[AutoClose] Error processing exercises for auto-close:', error);
  }
}

/**
 * Stop the auto-close service (for testing or shutdown)
 */
function stopAutoCloseService() {
  schedule.gracefulShutdown();
  console.log('[AutoClose] Service stopped.');
}

module.exports = {
  startAutoCloseService,
  stopAutoCloseService,
  processExercisesForAutoClose
};
const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const queue = [];
let isWorkerRunning = false;

// Background job handler for CDS computation
const processQueue = async () => {
  if (!isWorkerRunning && queue.length > 0) {
    isWorkerRunning = true;
    try {
      while (queue.length > 0) {
        const job = queue.shift();
        await cdsEngine.computeBatchCDS(job.exerciseId, db);
        await notifyStudent(job.exerciseId, 'CDS computation completed');
        job.resolve();
      }
    } catch (error) {
      console.error('Background job failed:', error);
      job.reject(error);
    } finally {
      isWorkerRunning = false;
    }
  }
};

exports.enqueueCdsComputation = (exerciseId) => {
  return new Promise((resolve, reject) => {
    queue.push({ exerciseId, resolve, reject });
    processQueue();
  });
};

// Notification function placeholder (to be implemented)
const notifyStudent = async (exerciseId, message) => {
  // Implement actual notification logic here
  console.log(`[Notification] Exercise ${exerciseId}: ${message}`);
}

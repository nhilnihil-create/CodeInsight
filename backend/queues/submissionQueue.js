/**
 * backend/queues/submissionQueue.js
 *
 * BullMQ + Redis job queue for decoupling submission processing from HTTP requests.
 * When Redis is unavailable, falls back to synchronous processing.
 *
 * Usage:
 *   const { addSubmissionJob, getJobStatus, queueReady } = require('./queues/submissionQueue');
 *   const jobId = await addSubmissionJob({ exerciseId, code, studentId, ... });
 */

const { Queue } = require('bullmq');
const IORedis = require('ioredis');

let redisConnection = null;
let submissionQueue = null;
let redisAvailable = false;

/**
 * Initialize Redis connection and BullMQ queue.
 * Returns false if Redis is unavailable (fallback to sync).
 */
async function initQueue() {
  if (submissionQueue || redisConnection) return redisAvailable;

  try {
    const host = process.env.REDIS_HOST || 'localhost';
    const tlsOptions = host !== 'localhost' && host !== '127.0.0.1' ? {} : undefined;

    redisConnection = new IORedis({
      host,
      port: parseInt(process.env.REDIS_PORT || '6379'),
      password: process.env.REDIS_PASSWORD || undefined,
      tls: tlsOptions,
      maxRetriesPerRequest: 3,
      retryDelayOnFail: 200,
      connectTimeout: 3000,
    });

    redisConnection.on('error', (err) => {
      console.warn('[SubmissionQueue] Redis connection error:', err.message);
      redisAvailable = false;
    });

    redisConnection.on('connect', () => {
      console.log('[SubmissionQueue] Connected to Redis');
      redisAvailable = true;
    });

    // Wait for connection (with timeout)
    await Promise.race([
      redisConnection.waitUntilReady(),
      new Promise((_, reject) => setTimeout(() => reject(new Error('Redis connection timeout')), 3000)),
    ]);

    submissionQueue = new Queue('submissions', {
      connection: redisConnection,
      defaultJobOptions: {
        attempts: 2,
        backoff: { type: 'exponential', delay: 1000 },
        removeOnComplete: { age: 3600 },   // Keep completed jobs for 1h
        removeOnFail: { age: 86400 },       // Keep failed jobs for 24h
      },
    });

    console.log('[SubmissionQueue] Queue initialized');
    redisAvailable = true;
    return true;
  } catch (err) {
    console.warn('[SubmissionQueue] Redis unavailable, falling back to sync:', err.message);
    redisAvailable = false;
    if (redisConnection) {
      await redisConnection.quit().catch(() => {});
      redisConnection = null;
    }
    return false;
  }
}

/**
 * Add a submission job to the queue.
 * Returns the job ID if queued, or null if Redis is unavailable.
 */
async function addSubmissionJob(payload) {
  if (!redisAvailable) {
    await initQueue();
    if (!redisAvailable) return null;
  }

  const job = await submissionQueue.add('evaluate', payload, {
    jobId: `sub-${Date.now()}-${Math.random().toString(36).slice(2, 8)}`,
  });

  return job.id;
}

/**
 * Get the status of a queued job.
 * Returns { status, result, error, progress } or null if job not found.
 */
async function getJobStatus(jobId) {
  if (!submissionQueue || !redisAvailable) return null;

  const job = await submissionQueue.getJob(jobId);
  if (!job) return null;

  const state = await job.getState();

  return {
    jobId: job.id,
    status: state, // 'waiting', 'active', 'completed', 'failed', 'delayed'
    result: state === 'completed' ? job.returnvalue : null,
    error: state === 'failed' ? job.failedReason : null,
    progress: job.progress || null,
    createdAt: job.timestamp,
    processedAt: job.processedOn || null,
    finishedAt: job.finishedOn || null,
  };
}

/**
 * Check if the queue is ready for use.
 */
function isReady() {
  return redisAvailable && !!submissionQueue;
}

/**
 * Gracefully close the queue connection.
 */
async function closeQueue() {
  if (submissionQueue) {
    await submissionQueue.close();
    submissionQueue = null;
  }
  if (redisConnection) {
    await redisConnection.quit();
    redisConnection = null;
  }
  redisAvailable = false;
}

module.exports = {
  initQueue,
  addSubmissionJob,
  getJobStatus,
  isReady,
  closeQueue,
  get redisConnection() { return redisConnection; },
};

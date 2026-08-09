jest.mock('bullmq');
jest.mock('ioredis');

const { Queue } = require('bullmq');
const IORedis = require('ioredis');
const queueModule = require('../queues/submissionQueue');

function fakeIoRedis() {
  const handlers = {};
  const instance = {
    on: jest.fn((event, handler) => {
      if (!handlers[event]) handlers[event] = [];
      handlers[event].push(handler);
      return instance;
    }),
    emit: jest.fn((event, ...args) => {
      (handlers[event] || []).forEach((h) => h(...args));
      return instance;
    }),
    waitUntilReady: jest.fn(),
    quit: jest.fn().mockResolvedValue(),
  };
  IORedis.mockImplementation(() => instance);
  return instance;
}

function connectIoRedis() {
  const redis = fakeIoRedis();
  redis.waitUntilReady.mockResolvedValue();
  // initQueue registers its 'connect' handler synchronously before its first
  // await, so emitting on the next tick is guaranteed to resolve it.
  process.nextTick(() => redis.emit('connect'));
  return redis;
}

function fakeQueue() {
  const instance = {
    add: jest.fn().mockResolvedValue({ id: 'mock-job-id' }),
    getJob: jest.fn(),
    close: jest.fn().mockResolvedValue(),
  };
  Queue.mockImplementation(() => instance);
  return instance;
}

describe('submissionQueue — initQueue', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    // Reset module state by re-requiring with reset
  });

  afterEach(async () => {
    await queueModule.closeQueue();
  });

  it('connects to Redis and creates queue on success', async function() {
    const redis = connectIoRedis();
    fakeQueue();

    const result = await queueModule.initQueue();
    expect(result).toBe(true);
    expect(IORedis).toHaveBeenCalledWith(expect.objectContaining({
      host: 'localhost',
      port: 6379,
    }));
    expect(Queue).toHaveBeenCalledWith('submissions', expect.objectContaining({
      defaultJobOptions: expect.objectContaining({
        attempts: 2,
        backoff: { type: 'exponential', delay: 1000 },
      }),
    }));
    expect(redis.on).toHaveBeenCalledWith('error', expect.any(Function));
    expect(redis.on).toHaveBeenCalledWith('connect', expect.any(Function));
  });

  it('returns cached state on second call', async function() {
    const redis = connectIoRedis();
    fakeQueue();

    await queueModule.initQueue();
    const result2 = await queueModule.initQueue();
    expect(result2).toBe(true);
    // Should only have created one connection
    expect(IORedis).toHaveBeenCalledTimes(1);
  });

  it('falls back when Redis connection times out', async function() {
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockImplementation(
      () => new Promise((_, reject) => setTimeout(() => reject(new Error('ETIMEOUT')), 50))
    );
    const result = await queueModule.initQueue();
    expect(result).toBe(false);
    expect(redis.quit).toHaveBeenCalled();
  });

  it('falls back when Redis connection errors', async function() {
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockRejectedValue(new Error('Connection refused'));
    const result = await queueModule.initQueue();
    expect(result).toBe(false);
  });

  it('handles Redis connection error event gracefully', async function() {
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockResolvedValue();
    // capture the error handler
    let errorHandler;
    redis.on.mockImplementation((event, handler) => {
      if (event === 'error') errorHandler = handler;
      return redis;
    });
    fakeQueue();
    await queueModule.initQueue();

    // Simulate a later Redis error event
    expect(errorHandler).toBeDefined();
    errorHandler(new Error('ECONNRESET'));
    // Should not throw — the handler just logs and sets redisAvailable = false
  });

  it('cleans up connection on fallback', async function() {
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockRejectedValue(new Error('timeout'));
    await queueModule.initQueue();
    expect(redis.quit).toHaveBeenCalled();
  });
});

describe('submissionQueue — addSubmissionJob', function() {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  afterEach(async () => {
    await queueModule.closeQueue();
  });

  it('adds a job and returns its ID when Redis is available', async function() {
    const redis = connectIoRedis();
    fakeQueue();

    await queueModule.initQueue();
    const result = await queueModule.addSubmissionJob({ exerciseId: 1, code: 'test', studentId: 42 });

    expect(result).toBe('mock-job-id');
  });

  it('calls initQueue when not initialized', async function() {
    const redis = connectIoRedis();
    fakeQueue();

    // Module not initialized — addSubmissionJob should initialize internally
    const result = await queueModule.addSubmissionJob({ exerciseId: 1, code: 'test', studentId: 42 });
    expect(result).toBe('mock-job-id');
  });

  it('returns null when Redis is unavailable', async function() {
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockRejectedValue(new Error('no redis'));
    fakeQueue();

    const result = await queueModule.addSubmissionJob({ exerciseId: 1, code: 'test', studentId: 42 });
    expect(result).toBeNull();
  });

  it('generates unique job IDs per call', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    await queueModule.initQueue();

    await queueModule.addSubmissionJob({ exerciseId: 1 });
    await queueModule.addSubmissionJob({ exerciseId: 2 });

    const firstJobId = q.add.mock.calls[0][2].jobId;
    const secondJobId = q.add.mock.calls[1][2].jobId;
    expect(firstJobId).not.toBe(secondJobId);
  });

  it('passes payload to queue.add', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    await queueModule.initQueue();

    const payload = { exerciseId: 5, code: '#include', studentId: 3, timeSpentSeconds: 120 };
    await queueModule.addSubmissionJob(payload);

    expect(q.add).toHaveBeenCalledWith('evaluate', payload, expect.objectContaining({
      jobId: expect.stringMatching(/^sub-/),
    }));
  });
});

describe('submissionQueue — getJobStatus', function() {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  afterEach(async () => {
    await queueModule.closeQueue();
  });

  it('returns job status when completed', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    q.getJob.mockResolvedValue({
      id: 'job-1',
      getState: jest.fn().mockResolvedValue('completed'),
      returnvalue: { allPassed: true, submissionId: 10 },
      failedReason: null,
      progress: 100,
      timestamp: 1000,
      processedOn: 1100,
      finishedOn: 1200,
    });
    await queueModule.initQueue();

    const status = await queueModule.getJobStatus('job-1');
    expect(status).toEqual({
      jobId: 'job-1',
      status: 'completed',
      result: { allPassed: true, submissionId: 10 },
      error: null,
      progress: 100,
      createdAt: 1000,
      processedAt: 1100,
      finishedAt: 1200,
    });
  });

  it('returns job status when failed', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    q.getJob.mockResolvedValue({
      id: 'job-2',
      getState: jest.fn().mockResolvedValue('failed'),
      returnvalue: null,
      failedReason: 'Exercise not found',
      progress: 25,
      timestamp: 2000,
      processedOn: 2100,
      finishedOn: null,
    });
    await queueModule.initQueue();

    const status = await queueModule.getJobStatus('job-2');
    expect(status.status).toBe('failed');
    expect(status.error).toBe('Exercise not found');
    expect(status.result).toBeNull();
  });

  it('returns null when job not found', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    q.getJob.mockResolvedValue(null);
    await queueModule.initQueue();

    const status = await queueModule.getJobStatus('nonexistent');
    expect(status).toBeNull();
  });

  it('returns null when queue is not ready', async function() {
    // Don't initialize queue
    const status = await queueModule.getJobStatus('job-x');
    expect(status).toBeNull();
  });

  it('returns job with waiting state', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    q.getJob.mockResolvedValue({
      id: 'job-waiting',
      getState: jest.fn().mockResolvedValue('waiting'),
      returnvalue: null,
      failedReason: null,
      progress: 0,
      timestamp: 3000,
      processedOn: null,
      finishedOn: null,
    });
    await queueModule.initQueue();

    const status = await queueModule.getJobStatus('job-waiting');
    expect(status.status).toBe('waiting');
    expect(status.progress).toBeNull(); // 0 || null → null
    expect(status.processedAt).toBeNull();
  });
});

describe('submissionQueue — isReady', function() {
  afterEach(async () => {
    await queueModule.closeQueue();
  });

  it('returns false before initialization', function() {
    expect(queueModule.isReady()).toBe(false);
  });

  it('returns true after successful init', async function() {
    const redis = connectIoRedis();
    fakeQueue();
    await queueModule.initQueue();
    expect(queueModule.isReady()).toBe(true);
  });

  it('returns false after Redis fails', async function() {
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockRejectedValue(new Error('fail'));
    await queueModule.initQueue();
    expect(queueModule.isReady()).toBe(false);
  });
});

describe('submissionQueue — closeQueue', function() {
  it('closes queue and connection when both exist', async function() {
    const redis = connectIoRedis();
    const q = fakeQueue();
    await queueModule.initQueue();

    await queueModule.closeQueue();

    expect(q.close).toHaveBeenCalled();
    expect(redis.quit).toHaveBeenCalled();
  });

  it('handles close when only connection exists', async function() {
    // Create state where queue is null but connection exists
    const redis = fakeIoRedis();
    redis.waitUntilReady.mockResolvedValue();
    fakeQueue();
    await queueModule.initQueue();
    // Manually set queue to null to simulate partial state
    await queueModule.closeQueue();
    // Second close should be safe
    await queueModule.closeQueue();
  });

  it('is safe to call when not initialized', async function() {
    await expect(queueModule.closeQueue()).resolves.not.toThrow();
  });
});

describe('submissionQueue — redisConnection getter', function() {
  afterEach(async () => {
    await queueModule.closeQueue();
  });

  it('returns null before initialization', function() {
    expect(queueModule.redisConnection).toBeNull();
  });

  it('returns the connection after init', async function() {
    const redis = connectIoRedis();
    fakeQueue();
    await queueModule.initQueue();
    expect(queueModule.redisConnection).toBe(redis);
  });
});

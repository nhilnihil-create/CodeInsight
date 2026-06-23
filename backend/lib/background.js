const logger = require('./logger');

const tasks = new Set();

function defer(fn) {
  const task = setImmediate(async () => {
    tasks.delete(task);
    try {
      await fn();
    } catch (err) {
      logger.warn({ err }, 'Background task failed');
    }
  });
  tasks.add(task);
  return task;
}

function pendingCount() {
  return tasks.size;
}

module.exports = { defer, pendingCount };

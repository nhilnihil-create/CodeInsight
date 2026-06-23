const os = require('os');

const MAX_CONCURRENT = Math.max(2, os.cpus().length - 1);
let active = 0;
const queue = [];

async function acquire(name) {
  if (active < MAX_CONCURRENT) {
    active++;
    return;
  }
  return new Promise((resolve) => {
    queue.push({ name, resolve });
  });
}

function release() {
  if (queue.length > 0) {
    const next = queue.shift();
    setImmediate(() => next.resolve());
  } else {
    active = Math.max(0, active - 1);
  }
}

async function runWithLimit(fn, name) {
  await acquire(name);
  try {
    return await fn();
  } finally {
    release();
  }
}

function activeCount() {
  return active;
}

function queuedCount() {
  return queue.length;
}

module.exports = { runWithLimit, activeCount, queuedCount, MAX_CONCURRENT };

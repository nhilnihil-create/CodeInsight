const cache = new Map();

const stats = { hits: 0, misses: 0, sets: 0 };

function get(key) {
  const entry = cache.get(key);
  if (!entry) { stats.misses++; return undefined; }
  if (Date.now() > entry.expires) { cache.delete(key); stats.misses++; return undefined; }
  stats.hits++;
  return entry.value;
}

function set(key, value, ttlMs = 5000) {
  cache.set(key, { value, expires: Date.now() + ttlMs });
  stats.sets++;
}

function del(key) {
  cache.delete(key);
}

function clear() {
  cache.clear();
}

function getStats() {
  return { ...stats, size: cache.size };
}

const CLEANUP_INTERVAL = 60000;
if (process.env.NODE_ENV !== 'test' && process.env.PLAYWRIGHT !== '1') {
  setInterval(() => {
    const now = Date.now();
    for (const [key, entry] of cache) {
      if (now > entry.expires) cache.delete(key);
    }
  }, CLEANUP_INTERVAL).unref();
}

module.exports = { get, set, del, clear, getStats };

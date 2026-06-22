module.exports = {
  apps: [{
    name: 'codeinsight',
    script: 'server.js',
    instances: process.env.NODE_ENV === 'production' ? 2 : 1,
    exec_mode: 'cluster',
    env: {
      NODE_ENV: 'production',
      PORT: 5000,
    },
    error_file: './logs/err.log',
    out_file: './logs/out.log',
    merge_logs: true,
    log_date_format: 'YYYY-MM-DD HH:mm:ss Z',
    max_memory_restart: '1G',
    listen_timeout: 10000,
    kill_timeout: 5000,
    restart_delay: 3000,
    max_restarts: 10,
  }],
};

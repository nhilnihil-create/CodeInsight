require('dotenv').config();

const path = require('path');

module.exports = {
  testEnvironment: 'node',
  rootDir: __dirname,
  roots: ['<rootDir>/test', '<rootDir>/services'],
  testMatch: ['**/*.test.js'],
  testTimeout: 30000,
};

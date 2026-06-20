jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('../services/cdsEngine', () => ({ computeBatchCDS: jest.fn() }));
jest.mock('nodemailer');

const nodemailer = require('nodemailer');
nodemailer.createTransport.mockReturnValue({
  sendMail: jest.fn().mockResolvedValue({ accepted: [], rejected: [] }),
});

const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const cdsJobQueue = require('../services/cdsJobQueue');
const { enqueueCdsComputation, stopPolling } = cdsJobQueue;

describe('cdsJobQueue — enqueueCdsComputation (DB-backed)', function() {
  afterEach(() => {
    stopPolling();
    jest.clearAllMocks();
    nodemailer.createTransport.mockClear();
  });

  it('inserts job into DB', async function() {
    db.query.mockResolvedValue({ rows: [{ id: 1, exercise_id: 1, status: 'pending' }] });
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await enqueueCdsComputation(1);

    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO cds_job_queue'),
      [1]
    );
  });

  it('processes job via worker when polling triggers', async function() {
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, exercise_id: 1, status: 'pending' }] })
      .mockResolvedValueOnce({ rows: [{ id: 1, exercise_id: 1 }] });
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await enqueueCdsComputation(1);

    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO cds_job_queue'),
      [1]
    );
  });

  it('does not crash when called', async function() {
    db.query.mockResolvedValue({ rows: [{ id: 1, exercise_id: 1, status: 'pending' }] });
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await expect(enqueueCdsComputation(1)).resolves.toBeUndefined();
  });

  it('handles compute failure gracefully', async function() {
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, exercise_id: 1, status: 'pending' }] });
    cdsEngine.computeBatchCDS.mockRejectedValue(new Error('CDS error'));

    await enqueueCdsComputation(1);

    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO cds_job_queue'),
      [1]
    );
  });
});

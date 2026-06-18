jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('../services/cdsEngine', () => ({ computeBatchCDS: jest.fn() }));
jest.mock('nodemailer');

const nodemailer = require('nodemailer');
nodemailer.createTransport.mockReturnValue({
  sendMail: jest.fn().mockResolvedValue({ accepted: [], rejected: [] }),
});

const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const { enqueueCdsComputation } = require('../services/cdsJobQueue');

describe('cdsJobQueue — enqueueCdsComputation', function() {
  beforeEach(() => {
    jest.clearAllMocks();
    nodemailer.createTransport.mockClear();
  });

  it('processes queued job and resolves', async function() {
    db.query.mockResolvedValue({ rows: [
      { student_id: 1, email: 'alice@test.com', name: 'Alice' },
    ]});
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await enqueueCdsComputation(1);

    expect(cdsEngine.computeBatchCDS).toHaveBeenCalledWith(1, db);
  });

  it('processes multiple jobs in sequence', async function() {
    db.query.mockResolvedValue({ rows: [] });
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await enqueueCdsComputation(1);
    await enqueueCdsComputation(2);

    expect(cdsEngine.computeBatchCDS).toHaveBeenCalledTimes(2);
    expect(cdsEngine.computeBatchCDS).toHaveBeenNthCalledWith(1, 1, db);
    expect(cdsEngine.computeBatchCDS).toHaveBeenNthCalledWith(2, 2, db);
  });

  it('handles compute failure without crashing', async function() {
    db.query.mockResolvedValue({ rows: [] });
    cdsEngine.computeBatchCDS.mockRejectedValue(new Error('CDS error'));

    await expect(enqueueCdsComputation(1)).rejects.toThrow('CDS error');
  }, 10000);

  it('does not crash when exercise not found for notification', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await enqueueCdsComputation(1);

    expect(cdsEngine.computeBatchCDS).toHaveBeenCalledWith(1, db);
  });

  it('logs notification info for enrolled students', async function() {
    db.query
      .mockResolvedValueOnce({ rows: [{ section_id: 10 }] })
      .mockResolvedValueOnce({ rows: [
        { student_id: 1, email: 'a@test.com', name: 'A' },
        { student_id: 2, email: 'b@test.com', name: 'B' },
      ]});
    cdsEngine.computeBatchCDS.mockResolvedValue(undefined);

    await enqueueCdsComputation(1);

    expect(db.query).toHaveBeenCalled();
  });
});

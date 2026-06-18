jest.mock('../config/db', () => ({ query: jest.fn(), connect: jest.fn() }));
jest.mock('../services/cdsEngine', () => ({ computeBatchCDS: jest.fn() }));
jest.mock('../services/alertEngine', () => ({ generateAlerts: jest.fn() }));

describe('autoCloseService — processExercisesForAutoClose', function() {
  beforeEach(() => {
    const db = require('../config/db');
    const cdsEngine = require('../services/cdsEngine');
    const alertEngine = require('../services/alertEngine');
    db.query = jest.fn();
    cdsEngine.computeBatchCDS = jest.fn();
    alertEngine.generateAlerts = jest.fn();
  });

  it('closes past-deadline exercises and triggers CDS + alerts', async function() {
    const db = require('../config/db');
    const cdsEngine = require('../services/cdsEngine');
    const alertEngine = require('../services/alertEngine');
    const { processExercisesForAutoClose } = require('../services/autoCloseService');

    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, title: 'Ex1', deadline: new Date(), created_by: 1 }, { id: 2, title: 'Ex2', deadline: new Date(), created_by: 1 }] })
      .mockResolvedValue({ rowCount: 1 });

    await processExercisesForAutoClose();

    expect(cdsEngine.computeBatchCDS).toHaveBeenCalledTimes(2);
    expect(alertEngine.generateAlerts).toHaveBeenCalledTimes(2);
  });

  it('does nothing when no exercises need closing', async function() {
    const db = require('../config/db');
    const cdsEngine = require('../services/cdsEngine');
    const { processExercisesForAutoClose } = require('../services/autoCloseService');
    db.query.mockResolvedValue({ rows: [] });

    await processExercisesForAutoClose();

    expect(cdsEngine.computeBatchCDS).not.toHaveBeenCalled();
  });

  it('continues processing remaining exercises when one fails', async function() {
    const db = require('../config/db');
    const cdsEngine = require('../services/cdsEngine');
    const alertEngine = require('../services/alertEngine');
    const { processExercisesForAutoClose } = require('../services/autoCloseService');

    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, title: 'Ex1', deadline: new Date(), created_by: 1 }, { id: 2, title: 'Ex2', deadline: new Date(), created_by: 1 }] })
      .mockResolvedValue({ rowCount: 1 });

    cdsEngine.computeBatchCDS.mockRejectedValueOnce(new Error('CDS engine failed'));
    cdsEngine.computeBatchCDS.mockResolvedValueOnce(undefined);

    await processExercisesForAutoClose();

    expect(cdsEngine.computeBatchCDS).toHaveBeenCalledTimes(2);
    expect(alertEngine.generateAlerts).toHaveBeenCalledTimes(1);
  });

  it('logs a message when auto_close succeeds', async function() {
    const db = require('../config/db');
    const { processExercisesForAutoClose } = require('../services/autoCloseService');

    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, title: 'Ex1', deadline: new Date(), created_by: 1 }] })
      .mockResolvedValue({ rowCount: 1 });

    await processExercisesForAutoClose();

    const updateQuery = db.query.mock.calls[1][0];
    expect(updateQuery).toContain('UPDATE exercises');
    expect(updateQuery).toContain('closed_at');
  });

  it('accepts an optional transaction client', async function() {
    const db = require('../config/db');
    const { processExercisesForAutoClose } = require('../services/autoCloseService');

    const mockClient = {
      query: jest.fn().mockResolvedValue({ rows: [] }),
    };

    await processExercisesForAutoClose(mockClient);

    expect(mockClient.query).toHaveBeenCalled();
    expect(db.query).not.toHaveBeenCalled();
  });
});

describe('autoCloseService — startAutoCloseService', function() {
  it('starts without error', function() {
    const { startAutoCloseService, stopAutoCloseService } = require('../services/autoCloseService');
    expect(() => startAutoCloseService()).not.toThrow();
    stopAutoCloseService();
  });
});

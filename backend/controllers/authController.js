const bcrypt = require('bcryptjs');
const jwt    = require('jsonwebtoken');
const db     = require('../config/db');

const generateToken = (user) =>
  jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role },
    process.env.JWT_SECRET,
    { expiresIn: '7d' }
  );

exports.register = async (req, res) => {
  const { name, email, password, role } = req.body;
  if (!name || !email || !password || !role)
    return res.status(400).json({ message: 'All fields required' });
  if (!['instructor','student'].includes(role))
    return res.status(400).json({ message: 'Invalid role' });

  try {
    const exists = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (exists.rows.length)
      return res.status(409).json({ message: 'Email already registered' });

    const hash = await bcrypt.hash(password, 10);
    const result = await db.query(
      'INSERT INTO users (name,email,password_hash,role) VALUES($1,$2,$3,$4) RETURNING id,name,email,role',
      [name, email, hash, role]
    );
    const user = result.rows[0];
    res.status(201).json({ token: generateToken(user), user });
  } catch (err) {
    console.error(err);
    res.status(500).json({ message: 'Server error' });
  }
};

exports.login = async (req, res) => {
  const { email, password } = req.body;
  console.log('=== LOGIN ATTEMPT ===');
  console.log('Email:', email);
  console.log('Password:', password);

  if (!email || !password)
    return res.status(400).json({ message: 'Email and password required' });

  try {
    const result = await db.query(
      'SELECT id,name,email,role,password_hash FROM users WHERE email=$1', [email]
    );
    if (!result.rows.length)
      return res.status(401).json({ message: 'Invalid credentials' });

    const user = result.rows[0];
    const valid = await bcrypt.compare(password, user.password_hash);
	  console.log('Password comparison result:', valid);
    if (!valid)
      return res.status(401).json({ message: 'Invalid credentials' });

    const { password_hash, ...safeUser } = user;
    res.json({ token: generateToken(safeUser), user: safeUser });
  } catch (err) {
    console.error(err);
    res.status(500).json({ message: 'Server error' });
  }
};

exports.me = async (req, res) => {
  try {
    const result = await db.query(
      'SELECT id,name,email,role FROM users WHERE id=$1', [req.user.id]
    );
	  console.log('Database result rows:', result.rows.length);
  if (result.rows.length) {
    console.log('User found:', result.rows[0].email);
    console.log('Stored hash:', result.rows[0].password_hash);
  }

    if (!result.rows.length)
      return res.status(404).json({ message: 'User not found' });
    res.json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
};

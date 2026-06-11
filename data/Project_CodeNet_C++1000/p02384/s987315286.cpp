#include <iostream>
using namespace std;
/*
  1
4 2 3 5
  6
*/
class Dice {
private:
  int s[6];
public:
  Dice();
  Dice(int t[6]);
  int get(int pos);
  void set(int pos, int x);
  void move(char dir);
  bool operator==(Dice d);
};

Dice::Dice() {
  for (int i = 0; i < 6; i++) {
    s[i] = 0;
  }
}

Dice::Dice(int t[6]) {
  for (int i = 0; i < 6; i++) {
    s[i] = t[i];
  }
}

int Dice::get(int pos) {
  return s[pos];
}

void Dice::set(int pos, int x) {
  s[pos] = x;
}

bool Dice::operator==(Dice d) {
  for (int i = 0; i < 6; i++) {
    if (s[i] != d.get(i)) {
      return false;
    }
  }
  return true;
}

void Dice::move(char dir) {
  int t;
  switch (dir) {
    case 'N': {
      t = s[0];
      s[0] = s[1];
      s[1] = s[5];
      s[5] = s[4];
      s[4] = t;
      break;
    }
    case 'E': {
      t = s[3];
      s[3] = s[5];
      s[5] = s[2];
      s[2] = s[0];
      s[0] = t;
      break;
    }
    case 'W': {
      t = s[0];
      s[0] = s[2];
      s[2] = s[5];
      s[5] = s[3];
      s[3] = t;
      break;
    }
    case 'S': {
      t = s[4];
      s[4] = s[5];
      s[5] = s[1];
      s[1] = s[0];
      s[0] = t;
      break;
    }
  }
}

int main() {
  int t, a, b;
  char c;
  Dice d;

  for (int i = 0; i < 6; i++) {
    cin >> t;
    d.set(i, t);
  }

  cin >> t;
  while (t--) {
    cin >> a >> b;
    for (int i = 0; i < 4; i++) {
      d.move('W');
      for (int j = 0; j < 4; j++) {
        d.move('N');
        for (int k = 0; k < 4; k++) {
          d.move('W');
          if (d.get(0) != a) continue;
          if (d.get(1) != b) continue;
          cout << d.get(2) << endl;
          goto end;
        }
      }
    }
    end:;
  }

  return 0;
}
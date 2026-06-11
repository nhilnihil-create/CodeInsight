#include <iostream>
#define REP(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;

int N;

int digit(char c) {
  if(c == 'm') return 1000;
  if(c == 'c') return 100;
  if(c == 'x') return 10;
  return 1;
}

char undigit(int k) {
  if(k == 1000) return 'm';
  if(k == 100) return 'c';
  if(k == 10) return 'x';
  return 'i';
}

int decode(string s) {
  int d = 0;
  REP(i, 0, s.length()) {
    if('2' <= s[i] && s[i] <= '9') {
      // cout << "2:  " << s[i] << s[i + 1] << endl;
      d += (s[i] - '0') * digit(s[i + 1]);
      i++;
    } else {
      // cout << "1:  " << s[i] << endl;
      d += digit(s[i]);
    }
  }
  // cout << d << endl;
  return d;
}

string encode(int d) {
  string s;
  int k = 1000;
  REP(i, 0, 4) {
    int p = d / k;
    if(2 <= p && p <= 9) {
      char c = p + '0';
      s = s + c;
      s = s + undigit(k);
    } else if(p == 1) {
      s = s + undigit(k);
    }
    d -= p * k;
    k /= 10;
  }
  return s;
}

int main(void) {
  cin >> N;
  REP(i, 0, N) {
    string S1, S2;
    cin >> S1 >> S2;
    cout << encode(decode(S1) + decode(S2)) << endl;
  }

  return 0;
}
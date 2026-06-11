#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C, D;
  string s;
  cin >> N >> A >> B >> C >> D >> s;
  A--; B--; C--; D--;
  
  int dotsq = 0;
  int rocksq = 0;
  bool b = false;
  bool P = true;
  for (int i = A; i < max(C,D); i++) {
    if (s[i] == '.') {
      if (i >= B-1 && i <= D+1) dotsq += 1;
      rocksq = 0;
    }
    if (s[i] == '#') {
      dotsq = 0;
      rocksq += 1;
    }
    if (dotsq > 2) b = true;
    if (rocksq > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  if (C > D && !b) P = false;
  
  if (P) cout << "Yes" << endl;
  else cout << "No" << endl;
 }

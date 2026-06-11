#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y; cin >> x >> y;
  bool ok = false;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (i + j == x && i*2 + j*4 == y) ok = true;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
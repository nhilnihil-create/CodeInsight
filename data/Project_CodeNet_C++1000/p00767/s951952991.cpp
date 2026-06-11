#include <bits/stdc++.h>
using namespace std;

void solve(int h, int w, int t) {
  for (int i = t; ; ++i) {
    int ah = (i == t ? h + 1 : 1);
    int aw = 151;

    while (ah < aw) {
      aw = 151;
      while (ah * ah + aw * aw > i) {
        aw--;
      }
      if (ah > aw) break;
      if (ah * ah + aw * aw == i) {
        cout << ah << " " << aw << endl;
        return;
      }
      ah++;
    }
  }
}

int main() {
  int h, w;
  while (cin >> h >> w, h) {
    int t = h * h + w * w;
    solve(h, w, t);
  }
}
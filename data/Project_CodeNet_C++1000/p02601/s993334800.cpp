#include <bits/stdc++.h>
using namespace std;

void solve() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  while (true) {
    if (A < B) break;
    B *= 2;
    K--;
  }
  while (true) {
    if (B < C) break;
    C *= 2;
    K--;
  }
  cout << ((K >= 0) ? "Yes" : "No") << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
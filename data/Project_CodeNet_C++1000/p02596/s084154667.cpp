#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;

int k;
void input() { cin >> k; }

void exit_end(int ans) {
  cout << ans << endl;
  exit(0);
}

void solve() {
  vector<int> v(k + 1, -1);
  if (k % 2 == 0) exit_end(-1);
  v[1] = 7 % k;
  rep(i, 2, k + 1) v[i] = (v[i - 1] * 10 + 7) % k;
  rep(i, 1, k + 1) {
    if (v[i] == 0) { exit_end(i); }
  }
  exit_end(-1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}
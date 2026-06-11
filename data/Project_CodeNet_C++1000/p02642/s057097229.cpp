#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> a(N), v(1e6 + 1, 0);

  for (auto &e : a) { cin >> e; }
  sort(a.begin(), a.end());

  for (auto &e : a) {
    if (v[e] != 0) {
      v[e] = 2;
      continue;
    }
    for (int i = e; i <= a.back(); i += e) v[i]++;
  }

  int ans = 0;
  for (auto &e : a)
    if (v[e] == 1) ans++;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
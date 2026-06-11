#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> a, res;

void solve();

int main() {
  cin >> n >> k;
  a.resize(n);
  for (auto &p : a) cin >> p;
  solve();
  for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
  return 0;
}

void solve() {
  while (k--) {
    res.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      ++res[max(0LL, i - a[i])];
      --res[min(n, i + a[i] + 1)];
    }
    for (int i = 1; i < n; ++i) res[i] += res[i - 1];
    a = res;
    bool ch = 1;
    for (int i = 0; i < n; ++i)
      if (res[i] != n) ch = 0;
    if (ch) break;
  }
}

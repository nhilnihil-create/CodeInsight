#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a, memo;

long long solve();

int main() {
  cin >> n;
  ++n;
  a.resize(n);
  for (auto &p : a) cin >> p;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, now = 1;
  memo.assign(n, 0);
  memo[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) memo[i] = memo[i + 1] + a[i];
  now = 1;
  for (int i = 0; i < n; ++i) {
    now = min(memo[i], now);
    res += now;
    now -= a[i];
    if (now < 0) return -1;
    now *= 2;
  }
  if (n == 1 && a[0] != 1) return -1;
  return res;
}

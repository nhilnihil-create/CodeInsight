#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n), f(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  sort(a.rbegin(), a.rend());
  sort(f.begin(), f.end());

  auto ok = [&] (long long M) {
    multiset<int> s(f.begin(), f.end());
    long long needed = 0;
    for(int i = 0; i < n; ++i) {
      int x = a[i], y = f[i];
      needed += max(0LL, x - M / y);
    }
    return needed <= k;
  };

  long long lo = 0, hi = 1e13;
  while(lo != hi) {
    long long mid = (lo + hi) / 2;
    if(ok(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << '\n';
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  int upper = *max_element(a.begin(), a.end());
  int lower = 0;
  while (upper - lower > 1) {
    int mid = lower + (upper - lower) / 2;
    auto ok = [&](int x) {
      int cnt = 0;
      for (auto&& e : a) {
        cnt += (e - 1) / x;
      }
      return (cnt <= k);
    };
    if (ok(mid)) {
      upper = mid;
    } else {
      lower = mid;
    }
  }
  cout << upper << '\n';
  return 0;
}

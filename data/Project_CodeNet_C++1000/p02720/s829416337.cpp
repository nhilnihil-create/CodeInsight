#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  vector<ll> v;
  for (int i = 1; i <= 9; i++) {
    v.emplace_back(i);
  }
  for (int i = 0;; i++) {
    ll x = v[i];
    if (x % 10 != 0) v.emplace_back(10 * x + x % 10 - 1);
    v.emplace_back(10 * x + x % 10);
    if (x % 10 != 9) v.emplace_back(10 * x + x % 10 + 1);
    if ((int)v.size() >= k) {
      cout << v[k - 1] << '\n';
      break;
    }
  }
  return 0;
}

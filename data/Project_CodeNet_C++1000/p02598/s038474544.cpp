#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005];
int n, k;
bool check(ll x) {
  ll count = 0;
  for (int i = 0; i < n; i++) {
    count += a[i] / x - (a[i] % x == 0);
  }
  return count <= k;
}
int main() {
  cin >> n >> k;
  ll l, u;
  l = 1;
  u = 1000000000;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (l <= u) {
    ll mid = (l + u) / 2;
    if (check(mid)) {
      u = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}

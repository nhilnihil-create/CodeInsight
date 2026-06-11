#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<pair<ll, ll>> ans;

  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  for (int i = 1; i < n - 1; ++i) {
    if (a[i] > 0) {
      ans.emplace_back(a[0], a[i]);
      a[0] -= a[i];
    } else {
      ans.emplace_back(a[n - 1], a[i]);
      a[n - 1] -= a[i];
    }
  }

  ans.emplace_back(a[n - 1], a[0]);
  cout << a[n - 1] - a[0] << endl;
  for (auto b : ans) printf("%d %d\n", b.first, b.second);
  return 0;
}

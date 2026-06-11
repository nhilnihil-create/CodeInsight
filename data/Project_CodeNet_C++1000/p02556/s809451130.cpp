#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define m 1000000007

ll a[1000005];

void solve() {
  ll n;
  cin >> n;
  ll ans1 = INT_MAX;
  ll ans2 = INT_MAX;
  ll ans3 = INT_MIN;
  ll ans4 = INT_MIN;
  ll x, y;
  ll ans = INT_MIN;
  for (ll i = 0; i < n; ++i) {
    cin >> x >> y;
    ans1 = min(ans1, x+y);
    ans2 = min(ans2, x-y);
    ans3 = max(ans3, x+y);
    ans4 = max(ans4, x-y);
  }
  cout << max(ans, max(ans3-ans1, ans4-ans2)) << endl;
}

int main() {
  ll t;
  // cin >> t;
  t = 1;
  while (t--)
    solve();
  return 0;
}
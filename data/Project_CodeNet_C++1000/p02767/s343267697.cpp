#include "bits/stdc++.h"
#define F first
#define S second
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n = 0;
  cin >> n;
  ll ar[n];
  ll ans = INT_MAX;
  for (ll i = 0; i < n; ++i)
    cin >> ar[i];
  sort(ar, ar + n);
  for (ll i = ar[0]; i <= ar[n - 1]; ++i) {
    ll cost = 0;
    for (ll j = 0; j < n; ++j) {
      //if (i != j)
      cost += ((ar[j] - i) * (ar[j] - i));
    }
    ans = min(ans, cost);
  }
  cout << ans;
}

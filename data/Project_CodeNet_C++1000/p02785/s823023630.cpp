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
  ll n = 0, k = 0;
  cin >> n >> k;
  ll ar[n];
  ll ans = 0;
  for (ll i = 0; i < n; ++i) cin >> ar[i];
  sort(ar, ar + n);
  for (ll i = 0; i < n - k; ++i) {
    ans += ar[i];
  }
  cout << ans;
}


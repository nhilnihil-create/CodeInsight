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
  ll h = 0, n = 0;
  cin >> h >> n;
  ll a[n];
  for (ll i = 0; i < n; ++i)
    cin >> a[i], h -= a[i];
  if (h > 0) cout << "No";
  else cout << "Yes";
}


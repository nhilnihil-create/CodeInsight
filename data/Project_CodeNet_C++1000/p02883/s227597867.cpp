#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  vector<ll> f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];

  sort(a.rbegin(),a.rend());
  sort(f.begin(),f.end());

  ll l = -1;
  ll r = 1000000000001;
  while (l+1 < r) {
    ll m = (l+r)/2;
    ll sum = 0;
    for (int i=0; i<n; i++) {
      ll tmp = a[i]*f[i] - m;
      if (tmp <= 0) continue;
      sum += (tmp-1+f[i]) / f[i];
    }
    if (sum <= k) r = m;
    else l = m;
  }
  cout << l+1 << endl;

  return 0;
}

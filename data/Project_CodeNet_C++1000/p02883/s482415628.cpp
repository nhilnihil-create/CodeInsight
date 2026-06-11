#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;

  vector<ll> a(n), f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];

  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());

  ll ng = -1, ok = 1e12 + 1;
  while(ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    ll tot = 0;

    for (int i = 0; i < n; i++) {
      ll tmpa = mid / f[i];
      if(a[i] > tmpa) {
        tot += (a[i] - tmpa);
      }
    }
    if(tot <= k) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << '\n';
  return 0;
}

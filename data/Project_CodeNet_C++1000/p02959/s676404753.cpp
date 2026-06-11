#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n+1), b(n);
  rep(i,n+1) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans = 0;
  rep(i,n) {
    if (a[i] > b[i]) {
        a[i] -= b[i];
        ans += b[i];
    } else {
      ans += a[i];
      b[i] -= a[i];
      a[i] = 0;
      if (a[i+1] > b[i]) {
        ans += b[i];
        a[i+1] -= b[i];
        b[i] = 0;
      } else {
        ans += a[i+1];
        b[i] -= a[i+1];
        a[i+1] = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n+1);
  rep(i,0,n+1) cin >> a[i];
  ll ans = 0;
  rep(i,0,n) {
    ll b;
    cin >> b;
    if (a[i] >= b) {
      ans += b;
      b = 0;
    } else {
      ans += a[i];
      b -= a[i];
      if (a[i+1] >= b) {
        ans += b;
        a[i+1] -= b;
      } else {
        ans += a[i+1];
        a[i+1] = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

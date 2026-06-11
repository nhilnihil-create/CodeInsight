#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n; cin >> n;
  ll nn = n, ans = n-1;
  for (ll i = 2;i*i<=n;i++) {
    if (n%i==0) ans = min((i-1)+(n/i-1), ans);
  }
  cout << ans << endl;
  return 0;
}
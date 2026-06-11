#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (long long i = 0; i < (n); i++)
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;
  dsu d(n);
  rep(i,m) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    d.merge(a,b);
  }
  ll cnt = d.groups().size();
  ll ans = cnt-1;
  cout << ans << endl;
}
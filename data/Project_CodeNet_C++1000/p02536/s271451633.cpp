#include<bits/stdc++.h>
#include<atcoder/all>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
using namespace atcoder;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;

void solve() {
  ll N, M;
  cin >> N >> M;
  dsu dsu(N);
  rep(_, M) {
    ll a,b;
    cin>>a>>b;
    a--,b--;
    dsu.merge(a, b);
  }
  set<ll> s;
  rep(i, N) {
    s.insert(dsu.leader(i));
  }
  cout<<(s.size()-1)<<endl;
}

int main() {
  //ll T;
  //cin >> T;
  //rep(_,T)
    solve();
  return 0;
}

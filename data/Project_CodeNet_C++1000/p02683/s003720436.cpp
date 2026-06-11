#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, m, x;
  cin >> n >> m >> x;
  Graph a(n, vector<ll>(m+1));
  rep(i,n) {
    rep(j,m+1) {
      cin >> a[i][j];
    }
  }
  ll ans = INF;
  for (ll bit = 0; bit < (1<<n); ++bit) {
    V q(m+1);
    for (ll i = 0; i < n; ++i) {
      if (bit & (1<<i)) { 
        rep(j,m+1) {
          q[j] += a[i][j];
        }

      }
    }
    Rep(j,1,m+1) {
      if (q[j] < x) {
        goto pp;
      }
    }
    ans = min(q[0],ans);
    pp:;
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}
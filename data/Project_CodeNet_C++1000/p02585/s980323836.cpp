#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n, k;
  cin >> n >> k;
  vector<ll> p(n), c(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }
  rep(i, n) cin >> c[i];

  ll ans = -INF;
  rep(i, n) {
    ll v = i;
    ll csum = 0, ccnt = 0;
    while (1) {
      csum += c[v];
      ccnt++;
      v = p[v];
      if (v == i) break;
    }
    ll tmp = 0, cnt = 0;
    while (1) {
      cnt++;
      tmp += c[v];
      if (cnt > k) break;
      ll num = (k - cnt) / ccnt;
      ll res = tmp + max(0LL, csum) * num;
      chmax(ans, res);
      v = p[v];
      if (v == i) break;
    }
  }
  cout << ans << '\n';

  
  return 0;
}
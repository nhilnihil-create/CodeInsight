#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;

void solve() {
  ll N, K;
  cin >> N >> K;
  vector<ll> p(N), c(N);
  rep(i, N)
    cin >> p[i], p[i]--;
  rep(i, N)
    cin >> c[i];

  ll ans = -1e18;
  rep(s, N) {
    ll su = 0, len = 0, k = K-1;
    ll i = p[s];
    while (true) {
      len++;
      su += c[i];
      if (i == s) break;
      i = p[i];
    }

    //cout << s << " " << len << " " << su << endl;
    ll score1 = 0, score2 = c[s];
    if (su > 0) {
      ll nLoop = k / len;
      k -= nLoop * len;
      score1 += nLoop * su;
    }
    chmax(ans, score1 + score2);
    //cout << "k = " << k << endl;

    i = p[s];
    rep(_, N+10)  {
      if (k <= 0) break;
      score2 += c[i];
      i = p[i];
      chmax(ans, score1 + score2);
      k--;
    }
  }
  cout << ans << endl;
}

int main() {
  //ll T;
  //cin >> T;
  //rep(_,T)
    solve();
  return 0;
}

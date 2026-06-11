#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (b < a) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int h, w, k; cin >> h >> w >> k;
  char c[h][w];

  rep(i, h) rep(j, w) cin >> c[i][j];

  int ans = 0;
  rep(i, 1<<h) rep(j, 1<<w) {
    int cnt = 0;

    rep(k, h) rep(l, w) {
      if (i & (1<<k) || j & (1<<l)) continue;
      if (c[k][l] == '#') ++cnt;
    }

    if (cnt == k) ++ans;
  }

  cout << ans << endl;
  
  return (0);
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define ep emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w, m; cin >> h >> w >> m;
  vi cnt_x(w+1), cnt_y(h+1);
  set<pi> bom;

  rep(i, m) {
    int x, y; cin >> y >> x;
    bom.em(x, y);
    ++cnt_x[x], ++cnt_y[y];
  }

  int mx = *max_element(all(cnt_x));
  int my = *max_element(all(cnt_y));

  vi max_x, max_y;

  rep(i, w+1) if (cnt_x[i] == mx) max_x.ep(i);
  rep(i, h+1) if (cnt_y[i] == my) max_y.ep(i);

  for (auto x : max_x) for (auto y : max_y) {
    int score = mx + my;

    if (!bom.count(mp(x, y))) {
      cout << mx + my << endl;
      return (0);
    }
  }

  cout << mx + my - 1 << endl;

  return (0);
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define ep emplace
#define eb emplace_back
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

  int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
  vi p(a), q(b), r(c);

  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];

  sort(all(p),greater<int>());
  sort(all(q),greater<int>());
  sort(all(r),greater<int>());

  vi eat;
  rep(i, x) eat.eb(p[i]);
  rep(i, y) eat.eb(q[i]);

  sort(all(eat));

  int idx = 0;
  while (eat[idx] < r[idx] && idx < c) {
    eat[idx] = r[idx];
    ++idx;
  }

  cout << accumulate(all(eat),0LL) << endl;

  return (0);
}

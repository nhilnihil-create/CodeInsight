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

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) { a = b; return true; } return false; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, x; cin >> n >> m >> x;
  int ans = MOD;

  vector<vi> a(n, vi(m+1));
  rep(i, n) rep(j, m+1) cin >> a[i][j];

  rep(bit, 1<<n) {
    int cost = 0;
    vi score(m,0);

    rep(i, n) if ((bit & (1<<i))) {
      cost += a[i][0];

      rep2(j, 1, m) score[j-1] += a[i][j];
    }

    bool ok = true;
    rep(i, m) if (score[i] < x) ok = false;

    if (ok) chmin(ans, cost);
  }

  cout << (ans == MOD ? -1 : ans) << endl;

  return (0);
}

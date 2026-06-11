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

template<class T, class U> bool chmax(T &a, U b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> bool chmin(T &a, U b) { if (b < a) { a = b; return true; } return false; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007, INF = 1e9;

int n, m;
int dp[1<<12];

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  
  rep(i, 1<<12) dp[i] = INF;
  dp[0] = 0;

  while (m --> 0) {
    int a, b; cin >> a >> b;
    int s = 0;
    rep(i, b) {
      int c; cin >> c, --c;
      s |= (1<<c);
    }

    rep(i, 1<<n) {
      if (dp[i] == INF) continue;
      chmin(dp[s | i], dp[i] + a);
    }
  }

  int ans = dp[(1<<n)-1];
  cout << (ans == INF ? -1 : ans) << endl;
  
  return (0);
}
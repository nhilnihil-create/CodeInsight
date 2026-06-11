#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T> >
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

ll dp1[3001][3001];
ll dp2[3001][3001];

int main() {
  int n, t;
  cin >> n >> t;
  vl A(n), B(n);
  rep(i, n) { cin >> A[i] >> B[i]; }

  rep(i, n) {
    rep(j, t) {
      maxs(dp1[i + 1][j], dp1[i][j]);
      if (j + A[i] < t) maxs(dp1[i + 1][j + A[i]], dp1[i][j] + B[i]);
    }
  }
  drep(i, n) {
    rep(j, t) {
      maxs(dp2[i][j], dp2[i + 1][j]);
      if (j + A[i] < t) maxs(dp2[i][j + A[i]], dp2[i + 1][j] + B[i]);
    }
  }

  rep(i, n+1) {
    rep(j, t) {
      maxs(dp1[i][j+1], dp1[i][j]);
      maxs(dp2[i][j+1], dp2[i][j]);
    }
  }
  ll ans = 0;
  rep(i, n) { 
    rep(j,t)
      maxs(ans, dp1[i][j] + dp2[i+1][t-j-1] + B[i]); 
  }
  cout << ans << endl;
  return 0;
}
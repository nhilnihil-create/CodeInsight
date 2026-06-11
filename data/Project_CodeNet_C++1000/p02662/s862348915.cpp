#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a){
  sort(all(a)); a.resize(unique(all(a)) - a.begin());  
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 1e9;
const int MOD = 998244353;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int N = 3e3+1;
int n, s, dp[N][N], a[N];
int main()
{
  fastio;
  int n, s; cin >> n >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= s; j++){
      dp[i][j] = 2 * dp[i - 1][j] % MOD;
      if (j - a[i] >= 0) (dp[i][j] += dp[i - 1][j - a[i]]) %= MOD;
    }
  }
  cout << dp[n][s];
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(const vector<ll> &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  VL s(n), t(m);
  rep(i,n) cin >> s[i];
  rep(i,m) cin >> t[i];
  VVL dp(n+1, VL(m+1, 0LL));
  VVL sm(n+1, VL(m+1, 0LL));
  FOR(i, 1, n+1) FOR(j, 1, m+1) {
    if(s[i-1] != t[j-1]) dp[i][j] = 0LL;
    else dp[i][j] = (sm[i-1][j-1] + 1LL) % MOD;
    sm[i][j] = (sm[i-1][j] % MOD + sm[i][j-1] % MOD - sm[i-1][j-1] % MOD + dp[i][j] % MOD + MOD) % MOD;
  }
  out((sm[n][m] + 1LL) % MOD);
  return 0;
}

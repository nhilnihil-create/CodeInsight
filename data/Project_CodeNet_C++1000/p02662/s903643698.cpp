
// Problem : F - Knapsack for All Subsets
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z)                                                       \
  cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define dbp(x) \
  cout << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define dbv(v)                         \
  {                                    \
    cout << #v << " : ";               \
    for (auto x : v) cout << x << ' '; \
    cout << endl;                      \
  }
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)
#define die(x) return cout << x << '\n', 0;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

vvi dp;
vi a;
const int MOD = 998244353;
int n, s;
int solve(int i, int j) {
  if (i == n) return (j == 0) ? 1 : 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (a[i] <= j) {
    return dp[i][j] =
               (solve(i + 1, j - a[i]) + ((2 * solve(i + 1, j)) % MOD)) % MOD;
  } else {
    return dp[i][j] = (2 * solve(i + 1, j)) % MOD;
  }
}

int32_t main() {
  fastio;
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  int testcases;
  testcases = 1;
  // cin >> testcases;

  while (testcases--) {
    cin >> n >> s;
    dp.assign(n + 1, vector<int>(s + 1, -1));
    a.resize(n);
    rep(i, 0, n - 1) cin >> a[i];
    cout << solve(0, s) << '\n';
    /*   rep(i, 0, n) {
         db1(i);
         dbv(dp[i]);
       }*/
  }

  return 0;
}

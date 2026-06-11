#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL 9223372036854775
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define MOD 1000000007
#define MOD9 998244353
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

#define int long long

using II = pair<int, int>;

int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int extgcd(int a, int b, int &x, int &y) { int g = a; x = 1; y = 0; if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x; return g; }

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

const int MAX_N = 305;
int N, K;
int H[MAX_N];
int dp[MAX_N][MAX_N];

signed main()
{
  cin >> N >> K;
  H[0] = 0;
  FOR(n,1,N+1) {
    cin >> H[n];
  }
  N++;

  REP(n,MAX_N) {
    REP(k,MAX_N) {
      dp[n][k] = INF_LL;
    }
  }

  dp[0][0] = 0;
  REP(i, N+1){
    REP(j, K+1){
      REP(k,j+1){
        int pos = i - k - 1;
        if(pos < 0) continue;
        dp[i][j] = min(dp[i][j], dp[pos][j - k] + max(0LL, H[i]-H[pos]));
      }
    }
  }

  int ans = INF_LL;
  for(int i = 0; i <= K; ++i){
      ans = min(ans, dp[N][i]);
  }
  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-10;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


//ここから編集

// iまでみてサイズがjであるときの最小値
ll dp[310][310];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int N, K; cin >> N >> K;
  if(N <= K) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> h(N+1, 0);
  for(int i=1; i<=N; i++) cin >> h[i];

  
  REP(i,N+2) REP(j,N+2) dp[i][j] = (1LL<<60);

  for(int i=1; i<=N; i++){
    dp[i][1] = h[i];
  }
  dp[0][0] = 0;
  for(int i=2; i<=N; i++){

    for(int j=2; j<=i; j++){
      for(int k=1; k<i; k++){
        dp[i][j] = min(dp[i][j], dp[k][j-1] + max(0LL, h[i]-h[k]));
      }
    }
  }
  ll ans = (1LL<<60);
  for(int i=1; i<=N; i++){
    ans = min(ans, dp[i][N-K]);
  }
  cout << ans << endl;
  return 0;
}
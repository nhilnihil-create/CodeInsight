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
ll dp[3010][3010];
vector<pii> vp;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  
  int N, T; cin >> N >> T;
  vp.resize(N);
  REP(i,N) cin >> vp[i].first >> vp[i].second;
  sort(all(vp));

  ll ans = 0;
  for(int i=0; i<N; i++){

    for(int j=0; j<=T; j++){
      if(j-vp[i].first >= 0){
        dp[i+1][j] = max(dp[i+1][j], dp[i][j-vp[i].first] + vp[i].second);
      }

      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
  }
  
  ans = vp[0].second;
  for(int i=0; i<N; i++){
    for(int j=0; j<=T-1; j++){
      ans = max(ans, dp[i][j] + vp[i].second);
    }
  }
  cout << ans << endl;
  return 0;
}
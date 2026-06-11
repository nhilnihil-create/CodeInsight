#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<pll> vpl;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define ZERO(a) memset(a,0,sizeof(a))

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


ll dp[2020][2020], cum[2020][2020];



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;
  vll s(n), t(m);
  REP(i,n)cin>>s[i];
  REP(i,m)cin>>t[i];

  REP(i,2020)REP(j,2020)dp[i][j]=0;
  REP(i,2020)REP(j,2020)cum[i][j]=0;
  REP(i,2020)cum[0][i]=cum[i][0]=1;

  ll ans = 1;
  REP(i,n){
    REP(j,m){
       if(s[i]==t[j])
        dp[i+1][j+1] = cum[i][j];
       ans = (ans+dp[i+1][j+1])%MOD;

       cum[i+1][j+1] = (cum[i][j+1]+cum[i+1][j]-cum[i][j]+MOD+dp[i+1][j+1])%MOD;
    }

  }

  cout<<ans<<endl;

}

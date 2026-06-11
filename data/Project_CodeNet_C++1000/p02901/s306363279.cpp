#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1ll << 62)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){
  
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  vector<ll> c(m,0);
  REP(i,m){
    cin >> a[i] >> b[i];
    REP(j,b[i]){
      int x;cin >> x;
      x--;
      c[i] |= (1 << x);
    }
  }
  vector<vector<ll>> dp(m,vector<ll>((1 << n),INF));
  dp[0][0] = 0;
  dp[0][c[0]] = a[0];
  REP(i,m-1){
    REP(j,(1 << n)){
      dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
      dp[i+1][(j | c[i+1])] = min(dp[i+1][(j | c[i+1])],dp[i][j]+a[i+1]);
    }
  }
  dp[m-1][(1 << n)-1] != INF ? cout << dp[m-1][(1 << n)-1] << endl: cout << -1 << endl;
  


  

  return 0;
}
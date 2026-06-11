#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=ll(a);i<ll(b);++i)
#define SIZE 3005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll n;
ll s;
ll a[SIZE];
ll dp[SIZE][SIZE];
ll t[SIZE];

void init(){
  t[0] = 1;
  rep(i,1,SIZE){
    t[i] = t[i-1]*2;
    t[i] %= MOD;
  }
}


int main(){
  cin >> n >> s;
  init();
  rep(i,0,n){
    cin >> a[i+1];
  }
  rep(i,1,n+1){
    rep(j,1,s+1){
      dp[i][j] += dp[i-1][j]*2;
      dp[i][j] %= MOD;

      if(j-a[i] >= 0) dp[i][j] += dp[i-1][j-a[i]];
      dp[i][j] %= MOD;

      if(a[i] == j){
        dp[i][j] += t[i-1];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[n][s] << endl;

  return 0;
}

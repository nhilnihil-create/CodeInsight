#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<double, P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)10000000000000000

int main() {
  string L;
  cin>>L;
  ll N;
  N=L.size();
  ll dp[N+1][2];
  rep(i,N+1){dp[i][0]=0ll;dp[i][1]=0ll;}
  dp[0][0]=1ll;
  rep(i,N){
    if(L[i]=='1'){
      dp[i+1][0]=2ll*dp[i][0];
      dp[i+1][1]=dp[i][0]+3ll*dp[i][1];
      dp[i+1][0]%=MOD;
      dp[i+1][1]%=MOD;
    }
    else{
      dp[i+1][0]=dp[i][0];
      dp[i+1][1]=3ll*dp[i][1];
      dp[i+1][0]%=MOD;
      dp[i+1][1]%=MOD;
    }
  }
  cout<<(dp[N][0]+dp[N][1])%MOD<<endl;
}
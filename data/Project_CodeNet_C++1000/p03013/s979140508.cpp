#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  ll n,k;cin>>n>>k;
  vll dp(n+1,-1);
  
  rep(i,0,k){
    ll a;cin>>a;
    dp[a]=0;
  }
  if(dp[1]!=0){dp[1]=1;}
  dp[0]=1;
  rep(i,2,n+1){
    if(dp[i]==0)continue;
    dp[i]=dp[i-1]+dp[i-2];
    dp[i]%=MOD;
    
  }
  cout<<dp[n]<<endl;
}


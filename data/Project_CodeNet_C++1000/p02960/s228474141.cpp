#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
typedef vector<vp> vvp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>(b);--i)
const int MOD = 1000000007;
const int MAX = 510000;


int main(){
  string s;cin>>s;
  vvll dp(s.size()+1,vll(13,0));
  dp[0][0]=1;
  rep(i,0,s.size()){
    rep(k,0,10){
      if(s[i]!='?'&&s[i]-'0'!=k)continue;
      rep(j,0,13){
        dp[i+1][(j*10+k)%13]+=dp[i][j];
        dp[i+1][(j*10+k)%13]%=MOD;
      }
    }
  }
  cout<<dp[s.size()][5]<<endl;
}



#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int MOD = 1000000007;
const int MAX = 510000;

vvll dp(2,vll(1000001));//dp[0]:その桁まで　dp[1]:桁＋１
int main(){
  string s;cin>>s;
  dp[0][0]=0,dp[1][0]=MOD;
  rep(i,0,s.size()){
    int x=s[s.size()-1-i]-'0';
    dp[0][i+1]=min(dp[0][i]+x,dp[1][i]+x);
    dp[1][i+1]=min(dp[0][i]+11-x,dp[1][i]+9-x);
  }
  cout<<min(dp[0][s.size()],dp[1][s.size()])<<endl;
}


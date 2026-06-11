#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;
int r,s,p,n,k;

int dp(string S){
  vi dp[3];
  int N=S.size();
  rep(i,3)dp[i].resize(N+1);
  rep(i,N){
    if(S[i]=='r'){
      dp[2][i+1]=max(dp[2][i+1],max(dp[0][i],dp[1][i])+p);
      dp[0][i+1]=max({dp[0][i+1],dp[1][i],dp[2][i]});
      dp[1][i+1]=max({dp[1][i+1],dp[0][i],dp[2][i]});
    }
    if(S[i]=='s'){
      dp[0][i+1]=max(dp[0][i+1],max(dp[1][i],dp[2][i])+r);
      dp[1][i+1]=max({dp[1][i+1],dp[0][i],dp[2][i]});
      dp[2][i+1]=max({dp[2][i+1],dp[0][i],dp[2][i]});
 
    }
    if(S[i]=='p'){
      dp[1][i+1]=max(dp[1][i+1],max(dp[0][i],dp[2][i])+s);
      dp[0][i+1]=max({dp[0][i+1],dp[1][i],dp[2][i]});
      dp[2][i+1]=max({dp[2][i+1],dp[0][i],dp[1][i]});
     }
  }
  return max({dp[0][N],dp[1][N],dp[2][N]});
}

signed main(){
  cin>>n>>k>>r>>s>>p;
  string t;cin>>t;
  int ans=0;
  rep(i,k){
    string u;
    for(int j=i;j<n;j+=k)u.push_back(t[j]);
    ans+=dp(u);
  }
  cout<<ans<<endl;
}
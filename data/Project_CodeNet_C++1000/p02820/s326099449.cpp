#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  int N,K;
  cin >> N >> K;
  vector<ll>pts(3);
  cin >> pts[0] >> pts[1] >> pts[2];
  vector<char>h(3);
  h[0]='s';h[1]='p';h[2]='r';
  string T;cin >> T;
  ll ans=0;
  rep(i,K){
    string now="";
    for(int j=i;j<N;j+=K)now+=T[j];
    int L=now.size();
    vector<ll>dp(L+1,0);
    dp[0]=0;
    rep(j,L){
      ll ad=now[j]=='s'?pts[0]:(now[j]=='p'?pts[1]:pts[2]);
      if(j==0)dp[j+1]=dp[j]+ad;
      else{
        if(now[j-1]==now[j])dp[j+1]=max(dp[j],dp[j-1]+ad);
        else dp[j+1]=max(dp[j],dp[j-1])+ad;
      }
    }
    ans+=dp[L];
  }
  cout << ans << endl;
  return 0;
}
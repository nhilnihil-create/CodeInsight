#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=ll(1e18)+1;
int main() {
  ios::sync_with_stdio(false);
	cin.tie(0);
  string s;
  ll n;
  cin>>s;
  n=s.size();

  reverse(s.begin(),s.end());
  s+='0';
  ll dp[n+2][2];
  rep(i,n+2)rep(j,2)dp[i][j]=INF;
  dp[0][0]=0;
  //1 繰りさがり
  rep(i,n+1){
     rep(j,2){
       ll now=s[i]-'0';
       if (j==1)now++;
    //   cout<<now<<'n';
      // if (now)
       if(now<10)
      dp[i+1][0]=min(dp[i+1][0],dp[i][j]+now);
      if(now>0)
        dp[i+1][1]=min(dp[i+1][1],dp[i][j]+10-now);
     }
     //cout<<dp[i+1][0]<<endl;
  //   cout<<dp[i+1][1]<<endl;


  }
cout<<dp[n+1][0]<<endl;
//  cout<<dp[n][0]<<' '<<dp[n][1];

}

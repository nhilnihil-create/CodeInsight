#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000005][2]={};
//dp[i][0] i桁目までぴったり
//dp[i][1] i桁目で+1枚払う

int main(){
  string n;
  cin>>n;
  dp[0][1]=1;
  for(int i=1;i<=n.size();i++){
    int now=(int)(n[i-1]-'0');
    dp[i][0]=min(dp[i-1][0]+now,dp[i-1][1]+10-now);
    dp[i][1]=min(dp[i-1][0]+now+1,dp[i-1][1]+(10-now-1));
  }
  cout<<dp[n.size()][0]<<endl;
}

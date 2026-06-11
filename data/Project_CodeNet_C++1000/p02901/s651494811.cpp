#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n,m;
  cin >> n>>m;
  vector<int>d[m];
  vector<int>b(m);
  rep(i,m){
    cin>>b.at(i);
    int a;
    cin>>a;
    rep(j,a){
      int c;
      cin>>c;
      c--;
      d[i].push_back(c);
    }
  }
  int inf=1001001001;
  vector<int>dp(5000,inf);
  dp[0]=0;
  rep(i,m){
    int now=0;
    rep(j,d[i].size()){
      now|=(1<<d[i][j]);
    }
    rep(tmp,(1<<n)){
      if(dp[tmp|now]>dp[tmp]+b[i]){
        dp[tmp|now]=dp[tmp]+b[i];
      }
    }
  }
        
  if(dp[(1<<n)-1]!=inf){
    cout<<dp[(1<<n)-1]<<endl;
  }
  else{
    cout<<-1<<endl;
  }
}
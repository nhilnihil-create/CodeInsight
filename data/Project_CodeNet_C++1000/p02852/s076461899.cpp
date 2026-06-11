#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,m;cin>>n>>m;
  string s;cin>>s;
  reverse(ALL(s));
  vector<bool> dp(n+m+10,false);
  dp[n]=true;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='1'){
      dp[i]=false;
      continue;
    }
    else{
      int sup=min(n-i,m);
      rep1(j,sup){
        dp[i]=dp[i]||dp[i+j];
        if(dp[i])break;
      }
    }
  }
  if(!dp[0]){
    cout<<-1<<"\n";
  }
  else{
    vector<int> res;
    rep(i,n){
      for(int j=m;j>0;--j){
        if(dp[i+j]){
          i+=j-1;
          res.push_back(j);
          break;
        }
      }
    }
    int num=res.size();
  rep(i,num){
    cout<<res[num-i-1]<<" ";
  }
  cout<<endl;
  }
  
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

signed main(){

  string s;
  cin>>s;

  auto solve = [](string const& s){
    auto chmax = [](auto& a,auto b){if(a<b)a=b;};
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(2));
    dp[0][0]=1;
    for(int i=1;i<n;++i){
      if(s[i-1]!=s[i]){
        chmax(dp[i][0],dp[i-1][0]+1);
      }
      chmax(dp[i][0],dp[i-1][1]+1);
      if(i>=2){
        chmax(dp[i][1],dp[i-2][0]+1);
        chmax(dp[i][1],dp[i-2][1]+1);
      }
    }
    return max(dp.back()[0],dp.back()[1]);
  };
  int ans = solve(s);
  reverse(begin(s),end(s));
  ans = max(ans,solve(s));
  cout<<(ans)<<endl;

}
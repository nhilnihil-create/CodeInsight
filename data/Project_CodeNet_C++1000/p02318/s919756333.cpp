#include<bits/stdc++.h>
using namespace std;

int levenshtein_dintance(string const& s,string const& t){
  size_t n = s.size();
  size_t m = t.size();
  constexpr int INF = (1<<28);
  vector<vector<int>> dp (n+1,vector<int>(m+1,INF));
  dp[0][0] = 0;
  for(size_t i=1;i<n;++i)dp[i][0] = dp[i-1][0]+1;
  for(size_t j=1;j<m;++j)dp[0][j] = dp[0][j-1]+1;
  for(size_t i=0;i<n;++i){
    for(size_t j=0;j<m;++j){
      dp[i+1][j+1] = min({dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j]+(s[i]!=t[j])});
    }
  }
  return dp[n][m];
}

main(){

  string s,t;
  cin>>s>>t;

  int ans = levenshtein_dintance(s,t);

  cout<<(ans)<<endl;


}

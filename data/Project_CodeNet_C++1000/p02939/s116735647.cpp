#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  string s;
  cin>>s;
  vector<vector<int>> dp((int)s.size()+2,vector<int>(2));

  dp[1][0]=1;
  dp[2][1]=1;
  for(int i=0;i<(int)s.size();i++){
    if(i>0 && s[i - 1]!=s[i])
      chmax(dp[i+1][0],dp[i][0]+1);
    if(i>1 && (s[i-2]!=s[i] || s[i-1] != s[i+1]))
      chmax(dp[i+2][1],dp[i][1]+1);
    chmax(dp[i+2][1],dp[i][0]+1);
    chmax(dp[i+1][0],dp[i][1]+1);
  }
  cout<<max(dp[s.size()][0],dp[s.size()][1])<<"\n";
  

  return 0;
}

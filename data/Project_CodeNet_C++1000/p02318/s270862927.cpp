//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<random>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  string s,t;
  cin >> s >> t;
  int x=s.size(),y=t.size(),dp[x+5][y+5]={};
  for(int i=0; i<=x; i++) {
    dp[i][0]=i;
  }
  for(int i=0; i<=y; i++) {
    dp[0][i]=i;
  }
  for(int i=1; i<=x; i++) {
    for(int j=1; j<=y; j++) {
      if(s[i-1]==t[j-1]) {
        dp[i][j]=min({dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1});
      }
      else {
        dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
      }
    }
  }
  cout << dp[x][y] << endl;
 }

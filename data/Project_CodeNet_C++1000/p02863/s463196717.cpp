#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
 
int dp[3030][3030][2];
 
int main(){
  int n, t;
  cin >> n >> t;
  vector<P> p;
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    p.push_back({a,b});
  }
  //sort(p.begin(), p.end());
 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < t; j++) {
      for (int k = 0; k < 2; k++) {
        if (k == 0) dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] + p[i].second);
   
        if (j + p[i].first < t) {
            dp[i+1][j+p[i].first][k] = max(dp[i+1][j+p[i].first][k], dp[i][j][k] + p[i].second);
        }
 
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
      }
    } 
  }
  cout << dp[n][t-1][1] << endl;
  return 0;
} 
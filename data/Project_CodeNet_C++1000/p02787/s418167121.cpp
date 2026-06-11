#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int H, N; cin >> H >> N;
  pii AB[N];
  rep(i,N) cin >> AB[i].first >> AB[i].second;
  vector<vector<int>> dp(N+1, vector<int>(H+1,1000000000)); // dp[i][h]: i番目までの魔法でhダメージ与えるときの魔力の最小値
  dp[0][0] = 0;
  rep(i,N){
    rep(j,H+1){
      dp[i+1][j] =  min(dp[i+1][j],dp[i][j]);
      dp[i+1][min(j+AB[i].first,H)] = min(dp[i+1][min(j+AB[i].first,H)], dp[i+1][j] + AB[i].second);
    }
  }
  cout << dp[N][H] << endl;
  




  // cout << fixed << setprecision(10);
  
  return 0;
}

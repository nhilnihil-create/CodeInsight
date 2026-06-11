#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 3000
#define MAXT 3000

int dp[MAXN+1][MAXT+1];

int main(){
  int n,t;cin>>n>>t;
  vector<pi>ab(n);
  rep(i, n)cin>>ab[i].first>>ab[i].second;

  sort(ab.begin(), ab.end());

  rep(i, n){
    // 配置済みの食品群をそのまま次のループへ持ち越す
    rep(j, t+1){
      if(dp[i][j]>0)dp[i+1][j]=dp[i][j];
    }
    // 着目中の食品そのものを単体で配置
    if(dp[i+1][min(t, ab[i].first)] <ab[i].second)dp[i+1][min(t, ab[i].first)] = ab[i].second;
    // 配置済みの食品群に対して着目中の食品を追加したときの値を計算
    rep(j, t){
      if(dp[i][j]>0){
        int ntime = min(t, j+ab[i].first);
        if(dp[i][ntime] < dp[i][j]+ab[i].second && dp[i+1][ntime] < dp[i][j]+ab[i].second)dp[i+1][ntime] = dp[i][j]+ab[i].second;
      }
    }
// rep(j, t+1)cout<<dp[i][j]<<' ';cout<<endl;

  }

  int result = 0;
  rep(i, t+1)result = max(result, dp[n][i]);

  cout<<result<<endl;

//  rep(i, t+1)cout<<dp[n][i]<<' ';cout<<endl;

  return 0;
}

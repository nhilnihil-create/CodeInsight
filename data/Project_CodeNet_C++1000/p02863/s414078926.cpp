#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int dp[3005][3005];

int main(){
  int N, T;
  cin >> N >> T;
  vector<pair<int,int>> v;
  rep(i,N){
    int a, b;
    cin >> a >> b;
    v.emplace_back(a,b);
  }
  sort(ALLOF(v));

  rep(i,3005) rep(j,3005) dp[i][j] = -1;
  dp[0][0] = 0;
  
  rep(i,N){
    rep(j,T){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      dp[i+1][min(T, j+v[i].first)] = max(dp[i+1][min(T, j+v[i].first)], dp[i][j] + v[i].second);
    }
  }
  int ret = 0;
  rep(i,N+1){
    rep(j,T+1){
      ret = max(ret, dp[i][j]);
    }
  }

  cout << ret << endl;
  
  return 0;
}


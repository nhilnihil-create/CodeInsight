#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


static ll dp[100005];
static const int INF = 1000000007;

int main(){
  int n, m;
  cin >> n >> m;

  REP(i,n) dp[i] = 0;
  REP(i,m){
    int a;
    cin >> a;
    a;
    dp[a] = -1;
    if(dp[a] == dp[a-1]){
      cout << 0 << endl;
      return 0;
    }
  }


  dp[0] = 1;
  if(dp[1] == 0) dp[1] = 1;
  else dp[1] = 0;

  for(int i = 2; i <= n; i++){
    if(dp[i] == -1){
      dp[i] = 0;
      continue;
    }
    dp[i] = dp[i-1]+dp[i-2];
    dp[i] %= 1000000007;
    //dp[i] = dp[i-1]+dp[i-2];

  }

  cout << dp[n] << endl;

  // REP(i,n+1){
  //
  //   cout << dp[i] << endl;
  // }


  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;
 
ll dp[2005][2005];

 
int main(){
  int N;
  cin >> N;
  vector<pair<ll,int>> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.emplace_back(a,i);
  }
  sort(ALLOF(v));
  reverse(ALLOF(v));

  rep(i,N){
    rep(j,i+1){
      int a = j;
      int b = i-j;
      dp[a+1][b] = max(dp[a+1][b], dp[a][b] + v[i].first * (v[i].second-a));
      dp[a][b+1] = max(dp[a][b+1], dp[a][b] + v[i].first * ((N-1-b)-v[i].second));
    }
  }

  ll ret = 0;
  rep(i,N){
    ret = max(ret, dp[i][N-i]);
  }
  cout << ret << endl;
  
  return 0;
}

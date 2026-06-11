#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

static const int NMAX = 1005;
static const int HMAX = 10005;
static const int INF = 1000000000;


ll dp[NMAX][HMAX];

int main(){
  int h, n;
  cin >> h >> n;
  vector<pair<int,int>> magic(n);
  REP(i,n){
    int a, b;
    cin >> a >> b;
    magic[i].first  = a;
    magic[i].second = b;
  }

//  REP(i,n) cout << magic[i].first << " " <<  magic[i].second << endl;

 //dp初期化


 REP(i,h+1) dp[0][i] = INF;
 REP(i,h+1){
   if(i%magic[0].first == 0){
     dp[1][i] = (i/magic[0].first) * magic[0].second;
    }
    else dp[1][i] = (i/magic[0].first + 1) * magic[0].second;
  }
  for(int i = 1; i < n+1 ; ++i) dp[i][0] = 0;

  //dp table
  ll x, c;

  for(int i = 2; i <= n ; ++i){
    for(int j = 1; j <= h; ++j){
      x = 0, c = 0;
      x = max(0, j - magic[i-1].first);
      c = magic[i-1].second;
      dp[i][j] = min(dp[i-1][j], dp[i][x] + c);
    }
  }

  cout << dp[n][h] << endl;
  return 0;
}

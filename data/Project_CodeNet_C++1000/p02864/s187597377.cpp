#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n,k;
  cin >> n >> k;
  vl h(n,0);
  rep(i,n) cin >> h.at(i);
  vvl dp(400,vl(400,1000000000000000));
  rep(i,n) dp[i][1] = h.at(i);
  int m = n-k;
  if(m <= 0){
    cout << 0 << endl;
    return 0;
  }
  REP(i,1,n){
    REP(j,1,m+1){
      rep(l,i){
        if(dp[l][j-1] == 1000000000000000) continue;
        dp[i][j] = min(dp[i][j], dp[l][j-1] + max((long)0, h.at(i)-h.at(l)));
      }
    }
  }
  long ans = 1e16;
  rep(i,n){
    ans = min(ans, dp[i][m]);
    //cout << dp[i][m] << endl;
  }
  /*rep(i,n){
    rep(j,m+1){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << ans << endl;
}

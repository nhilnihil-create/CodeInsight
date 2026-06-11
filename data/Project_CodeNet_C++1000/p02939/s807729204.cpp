#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[200010][5] = {0};
  
int main()
{
  string s;
  cin >> s;
  int N = s.size();
  s = "####" + s + "####";
  dp[5][1] = 1;

  FOR(i,4,N+5){
    FOR(j,1,5){
      FOR(k,1,5){
        if(k==j){
          int flag = 0;
          REP(l,j){
            if(s.at(i+j-l-1)!=s.at(i-l-1)){
              flag = 1;
            }
          }
          if(flag == 1){
            chmax(dp[i+j][j],dp[i][k]+1);
          }
        }else{
          chmax(dp[i+j][j],dp[i][k]+1);
        }
      }
    }
  }

  ll MAX = 0;
  FOR(i,1,5){
    chmax(MAX,dp[N+4][i]);
  }
  cout << MAX << endl;
}
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
long long dp[101000] = {0};
  
int main()
{
  int X;
  cin >> X;
  dp[0] = 1;
  int a = 100;
  REP(i,X+1){
    REP(j,6){
      if(dp[i] != 0){
        dp[i+j+a] = dp[i] + 1;
      }
    }
  }

  if(dp[X]>0){
    cout << 1 << endl;
  }else{
    cout << 0 << endl;
  }
}
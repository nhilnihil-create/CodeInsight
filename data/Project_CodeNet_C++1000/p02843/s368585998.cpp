#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

int main() {
  int x, x_max = 100000;
  cin >> x;
  bool dp[x+1];
  REP(i, x+1) { dp[i] = false; }
  dp[0] = true;
  REP(i, x+1) {
    for (int j = 100; j <= 105 && i + j <= x; j++) {
      if (dp[i]) dp[i + j] = true;
    }
  }
  if (dp[x])
    cout << "1\n";
  else
    cout << "0\n";
  //DEBUGS(dp);
  return 0;
}

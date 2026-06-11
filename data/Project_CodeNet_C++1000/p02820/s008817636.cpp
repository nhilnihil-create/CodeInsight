#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
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
  ll n, k, r, s, p, ans = 0;
  string t, t2 = "";
  cin >> n >> k >> r >> s >> p >> t;
  REP(i, n) {
    bool f = false;
    if (i - k >= 0) {
      if (t[i] == 'r' && t2[i - k] != 'p') {
        t2 += "p";
        ans += p;
        f = true;
      }
      if (t[i] == 'p' && t2[i - k] != 's') {
        t2 += "s";
        ans += s;
        f = true;
      }
      if (t[i] == 's' && t2[i - k] != 'r') {
        t2 += "r";
        ans += r;
        f = true;
      }
    } else {
      if (t[i] == 'r') {
        t2 += "p";
        ans += p;
        f = true;
      }
      if (t[i] == 'p') {
        t2 += "s";
        ans += s;
        f = true;
      }
      if (t[i] == 's') {
        t2 += "r";
        ans += r;
        f = true;
      }
    }
    if (!f) t2 += " ";
  }
  cout << ans << "\n";
  return 0;
}

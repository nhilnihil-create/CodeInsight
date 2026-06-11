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
  string s;
  cin >> s;
  vector<ll> a(s.size()), tmp(s.size(), 0), ans(s.size(), 0);
  ll rc = 0, lc = 0;
  REP(i, s.size()) {
    if (s[i] == 'R') {
      if (lc > 0) {
        REP(j, lc) { a[i - lc + j] = -j - 1; }
        lc = 0;
      }
      rc++;
    } else {
      if (rc > 0) {
        REP(j, rc) { a[i - rc + j] = rc - j; }
        rc = 0;
      }
      lc++;
    }
    if (i == s.size() - 1) {
      REP(j, lc) { a[i - lc + j + 1] = -j - 1; }
      lc = 0;
    }
  }

  REP(i, s.size()) {
    ll t;

    if (a[i] > 0) {
      if (a[i] % 2 == 0)
        ans[i + a[i]]++;
      else
        ans[i + a[i] - 1]++;
    } else {
      if (-a[i] % 2 == 0)
        ans[i + a[i]]++;
      else
        ans[i + a[i] + 1]++;
    }
  }
  REP(i, s.size()) { cout << ans[i] << " "; }
  cout << "\n";
  return 0;
}

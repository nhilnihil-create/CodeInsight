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
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  REP(i, n) { cin >> a[i]; }
  REP(j, k) {
    vector<int> imos(n, 0);
    REP(i, n) {
      imos[max(i - a[i], 0ll)] += 1;
      if (i + a[i] + 1 < n) imos[i + a[i] + 1] -= 1;
    }
    REP(i, n) {
      if (i == 0)
        a[i] = imos[i];
      else
        a[i] = a[i - 1] + imos[i];
    }
    bool f = true;
    REP(i, n) {
      if (a[i] != n) {
        f = false;
        break;
      }
    }
    if (f) {
      REP(i, n) {cout << n << " ";}
      cout << "\n";
      return 0;
    }
  }
  REP(i, n) { cout << a[i] << " "; }
  cout << "\n";
  return 0;
}

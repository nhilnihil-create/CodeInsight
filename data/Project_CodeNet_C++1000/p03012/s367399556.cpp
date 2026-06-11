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
/* clang-format on */

int main() {
  ll n, s1 = 0, s2 = 0, ans = INF;
  cin >> n;
  vector<ll> w(n);
  REP(i, n) { cin >> w[i]; }
  REP(t, n) {
    REP(i, n) {
      if (i <= t)
        s1 += w[i];
      else
        s2 += w[i];
    }
    ans = min(ans, abs(s1 - s2));
    s1 = 0;
    s2 = 0;
  }
  cout << ans << endl;
  return 0;
}

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
  ll x, n, ans;
  cin >> x >> n;
  if (n == 0) {
    cout << x << endl;
    return 0;
  }

  set<ll> p;
  REP(i, n) {
    ll tmp;
    cin >> tmp;
    p.insert(tmp);
  }

  ll t = INF;
  REP(j, 105) {
    ll i = j - 2;
    if (!p.count(i + 1)) {
      if (t > abs(i+1 - x)) {
        t = abs(i+1 - x);
        ans = i + 1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}

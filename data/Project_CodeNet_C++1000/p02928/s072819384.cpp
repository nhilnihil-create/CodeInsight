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
  ll n, k, ans = 0;
  cin >> n >> k;
  vector<ll> a(n), bcnt(n, 0), acnt(n, 0);
  REP(i, n) { cin >> a[i]; }

  REP(i, n) {
    for (ll j = i + 1; j < n; j++) {
      if (a[i] > a[j]) acnt[i]++;
    }
  }

  REP(i, n) {
    for (ll j = i - 1; j >= 0; j--) {
      if (a[i] > a[j]) bcnt[i]++;
    }
  }
  REP(i, n) {
    ans += acnt[i] * (k * (k + 1) / 2 % MOD)%MOD;
    ans += bcnt[i] * (k * (k - 1) / 2 % MOD)%MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}

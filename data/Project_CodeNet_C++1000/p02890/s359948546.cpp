// 2020-08-17 06:04:17
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n;
  cin >> n;
  vector<int> mp(n+1, 0);
  {
    vector<int> b(n);
    rep(i, n) {
      int a; cin >> a; a--;
      b[a]++;
    }
    rep(i, n) mp[b[i]]++;
  }
  vector<ll> sum1(n+2, 0), sum2(n+2, 0);
  repc(i, n) {
    sum1[i+1] = sum1[i] + i * mp[i];
    sum2[i+1] = sum2[i] + mp[i];
  }
  vector<ll> ans(n+1, 0);
  REPC(i, 1, n) {
    ll res = 0;
    res = sum1[i+1] + (sum2[n+1] - sum2[i+1]) * i;
    res /= ll(i);
    chmax(ans[res], ll(i));
  }
  REPCM(i, n-1, 1) chmax(ans[i], ans[i+1]);
  REPC(i, 1, n) cout << ans[i] << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
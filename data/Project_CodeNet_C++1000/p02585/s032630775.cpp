#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) ((t) = std::max<decltype(t)>((t), (v)))
#define updatemin(t, v) ((t) = std::min<decltype(t)>((t), (v)))

int nextp[5000], inWhichLoop[5000];
ll score[5000];
vector<vector<ll>> loops;
signed main() {
  int n;
  ll k;
  cin >> n >> k;
  repi(n) cin >> nextp[i];
  repi(n)-- nextp[i];
  repi(n) cin >> score[i];
  repi(n) inWhichLoop[i] = -1;
  repi(n) {
    if (inWhichLoop[i] >= 0) continue;
    int loopIndex = loops.size();
    int current = i;
    vector<ll> newLoop;
    while (inWhichLoop[current] < 0) {
      inWhichLoop[current] = loopIndex;
      newLoop.push_back(score[current]);
      current = nextp[current];
    }
    loops.push_back(newLoop);
  }
  ll result = LLONG_MIN;
  for (auto&& loop : loops) {
    int looplen = loop.size();
    vector<ll> sum(looplen * 3 + 1);
    sum[0] = 0;
    repi(looplen * 3) sum[i + 1] = sum[i] + loop[i % looplen];
    auto k0 = k;
    ll result0 = 0;
    bool allowzero = false;
    if (sum[looplen] > 0 && k0 / looplen >= 2) {
      result0 = sum[looplen] * (k0 / looplen - 1);
      k0 = k0 % looplen + looplen;
      allowzero = true;
    }
    ll result1 = allowzero ? 0 : LLONG_MIN;
    repi(looplen) rep(j, 1, min(k0, looplen * 2) + 1) updatemax(result1, sum[i + j] - sum[i]);
    updatemax(result, result0 + result1);
  }
  cout << result << endl;
}

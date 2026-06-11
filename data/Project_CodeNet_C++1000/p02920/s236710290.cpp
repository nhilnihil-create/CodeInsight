#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

inline ll pow2(ll i) {
  return ((ull)1) << i;
}

signed main() {
  ll N;
  cin >> N;
  multiset<ll> can, born;

  rep(i, pow2(N)) {
    ll x;
    cin >> x;
    can.insert(x);
  }
  {
    auto it = end(can);
    it--;
    born.insert(*it);
    can.erase(it);
  }

  bool ok = true;
  while (!can.empty()) {
    auto next_born = born;
    for (auto it = rbegin(born); it != rend(born); it++) {
      ll x = *it;
      auto jt = can.lower_bound(x);
      if (jt == can.begin()) {
        ok = false;
        goto FIN;
      }
      jt--;
      next_born.insert(*jt);
      can.erase(jt);
    }
    born = next_born;
  }
FIN:
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}

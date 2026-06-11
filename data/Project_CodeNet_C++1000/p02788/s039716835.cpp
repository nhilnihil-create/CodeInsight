#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

template <typename T>
struct BIT {
  std::vector<T> dat[2];

  BIT(int n) { init(n); }
  void init(int n) {
    dat[0].assign(n + 1, 0);
    dat[1].assign(n + 1, 0);
  }

  inline void sub_add(int p, int a, T x) {
    for (int i = a, n = dat[p].size(); i < n; i += i & -i)
      dat[p][i] = dat[p][i] + x;
  }

  inline void add(int a, int b, T x) {
    sub_add(0, a, x * -(a - 1));
    sub_add(1, a, x);
    sub_add(0, b, x * (b - 1));
    sub_add(1, b, -x);
  }

  inline T sub_sum(int p, int a) {
    T ret{};
    for (int i = a; i > 0; i -= i & -i) {
      ret += dat[p][i];
    }
    return ret;
  }

  // partial sum of [from,to) (1-origin).
  inline T sum(int from, int to) {
    return sub_sum(0, to - 1) + sub_sum(1, to - 1) * (to - 1) -
           sub_sum(0, from - 1) - sub_sum(1, from - 1) * (from - 1);
  }
};

#define ALL(x) begin(x), end(x)

int main() {
  ll N, D, A;
  cin >> N >> D >> A;
  vector<pair<ll, ll>> X;
  X.reserve(N);
  for (int i = 0; i != N; ++i) {
    ll x;
    ll h;
    cin >> x >> h;
    X.emplace_back(x, h);
  }

  sort(ALL(X));
  BIT<ll> bit(N + 2);
  for (auto i = 0; i != N; ++i) {
    bit.add(i + 1, i + 2, X[i].second);
  }

  ll cnt{};
  for (auto i = 0; i != N; ++i) {
    auto hp = bit.sum(i + 1, i + 2);
    if (hp <= 0) continue;
    const ll nhits = (hp - 1) / A + 1;
    auto bound =
        upper_bound(ALL(X), X[i].first + 2 * D,
                    [](ll a, pair<ll, ll> &b) { return a < b.first; }) -
        X.begin();
    bit.add(i + 1, bound+1, -nhits * A); // bit is 1-origin
    cnt += nhits;
  }

  cout << cnt << endl;

  return 0;
}

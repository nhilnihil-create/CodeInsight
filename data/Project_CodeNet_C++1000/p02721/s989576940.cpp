#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

template <typename T>
class SegmentTree {
  const T unit;
  const function<T(const T&, const T&)> op;
  vector<T> container;

 public:
  template <typename Op>
  SegmentTree(int size, const T& identity, const Op& operation)
      : unit(identity), op(operation), container(msb(size * 2 - 1)) {
    fill(container.begin(), container.end(), unit);
  }
  void update(size_t index, T value) {
    int n = container.size() / 2;
    container[index + n] = value;

    int node = (index + n) >> 1;
    while (node > 0) {
      container[node] = op(container[node << 1], container[(node << 1) + 1]);
      node >>= 1;
    }
  }
  T find(size_t s, size_t t) {
    if (s >= t) {
      return unit;
    }
    return find_inner(s, t, 0, container.size() / 2);
  }

 private:
  T find_inner(size_t s, size_t t, size_t lb, size_t ub) {
    if (s == lb && t == ub) {
      int n = container.size() / 2;
      return container[lca(n + s, n + t - 1)];
    }

    T result = unit;
    size_t mid = (lb + ub) / 2;
    if (mid > s) {
      result = op(result, find_inner(s, min(mid, t), lb, mid));
    }
    if (mid < t) {
      result = op(result, find_inner(max(s, mid), t, mid, ub));
    }

    return result;
  }
  int lca(int n0, int n1) {
    int a = n0 ^ n1;
    return n0 / msb(a);
  }
  int msb(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x + 1;
  }
};

int main() {
  int N, K, C;
  cin >> N >> K >> C;
  string s;
  cin >> s;

  s = string("x") + s;
  s.push_back('x');

  vector<int> lwork(N + 2, 0), rwork(N + 2, 0);

  rep(i, N) {
    lwork[i + 1] = lwork[i];
    if (s[i + 1] == 'o') {
      if (i + 1 - C - 1 >= 0) {
        lwork[i + 1] = max(lwork[i + 1], lwork[i + 1 - C - 1] + 1);
      } else {
        lwork[i + 1] = 1;
      }
    }
  }

  rep(i, N) {
    rwork[N - i] = rwork[N - i + 1];
    if (s[N - i] == 'o') {
      if (N - i + C + 1 <= N + 1) {
        rwork[N - i] = max(rwork[N - i], rwork[N - i + C + 1] + 1);
      } else {
        rwork[N - i] = 1;
      }
    }
  }

  SegmentTree<int> work(
      N + 1 + C, 0, [](const int& lh, const int& rh) { return max(lh, rh); });

  for (int i = -C; i < N; i++) {
    work.update(i + C, lwork[max(i, 0)] + rwork[min(i + C + 1, N + 1)]);
  }

  rep(i, N) {
    if (C == 0) {
      if (lwork[i] + rwork[i + 2] < K) {
        cout << i + 1 << "\n";
      }
    } else {
      if (work.find(i + 1, i + 1 + C) < K) {
        cout << i + 1 << "\n";
      }
    }
  }
  return 0;
}
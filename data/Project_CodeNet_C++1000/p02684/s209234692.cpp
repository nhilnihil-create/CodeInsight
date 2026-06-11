#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

template <class T, class Op> class doubling {
  using usize = std::size_t;
  using u64 = std::uint64_t;

  Op op;
  std::vector<T> pow;

  const T &get(const usize i) {
    while (i >= pow.size()) {
      pow.push_back(op(pow.back(), pow.back()));
    }
    return pow[i];
  }

public:
  doubling(Op op, T x) : op(op), pow({std::move(x)}) {}

  template <class U, class Ap> U apply(Ap ap, U init, u64 k) {
    usize i = 0;
    while (k != 0) {
      if (k % 2 != 0) {
        init = ap(std::move(init), get(i));
      }
      k /= 2;
      i += 1;
    }
    return std::move(init);
  }

  template <class U, class Ap, class Pred> u64 find(Ap ap, U init, Pred pred) {
    if (!pred(init)) {
      return 0;
    }
    U temp = ap(init, get(0));
    usize i = 0;
    while (pred(temp)) {
      init = std::move(temp);
      temp = ap(init, get(i));
      i += 1;
    }
    u64 ret = static_cast<u64>(1) << i;
    while (i != 0) {
      i -= 1;
      temp = ap(init, get(i));
      if (pred(temp)) {
        init = std::move(temp);
      } else {
        ret -= static_cast<u64>(1) << i;
      }
    }
    return ret;
  }
};

#include <iostream>
#include <vector>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &e : a) {
    std::cin >> e;
    e -= 1;
  }

  const auto op = [](std::vector<int> l, const std::vector<int> &r) {
    for (int &e : l) {
      e = r[e];
    }
    return std::move(l);
  };

  doubling<std::vector<int>, decltype(op)> db(op, a);

  const auto ap = [](const int l, const std::vector<int> &r) { return r[l]; };

  std::cout << db.apply(ap, 0, k) + 1 << "\n";

  return 0;
}

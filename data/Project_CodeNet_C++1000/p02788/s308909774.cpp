#include <bits/stdc++.h>

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  using RangeOperation = std::function<T(T, int)>;

  SegmentTree(
      int size, Operation operation, T identity = T(),
      RangeOperation range_operation = [](int v, int) { return v; })
      : operation_(operation),
        identity_(identity),
        range_operation_(range_operation) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
    l_.resize(two * 2 - 1, identity_);
  }

  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  void Apply(int begin, int end, T v) {
    std::function<void(int, int, int)> rec = [&](int cbegin, int cend,
                                                 int index) {
      if (begin <= cbegin && cend <= end) {
        l_[index] = operation_(l_[index], v);
        return;
      }
      if (cend <= begin || end <= cbegin) {
        return;
      }
      int cmid = (cbegin + cend) / 2;
      rec(cbegin, cmid, index * 2 + 1);
      rec(cmid, cend, index * 2 + 2);
      int size = std::min(cend, end) - std::max(cbegin, begin);
      v_[index] = operation_(v_[index], range_operation_(v, size));
    };
    rec(0, (v_.size() + 1) / 2, 0);
  }

  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      int size = std::min(cend, end) - std::max(cbegin, begin);
      if (begin <= cbegin && cend <= end) {
        return operation_(v_[index], range_operation_(l_[index], size));
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(operation_(rec(cbegin, cmid, index * 2 + 1),
                                   rec(cmid, cend, index * 2 + 2)),
                        range_operation_(l_[index], size));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

  void Debug() const {
    auto debug = [&](const std::vector<T>& v) {
      int width = 0;
      for (T t : v) {
        std::stringstream ss;
        ss << t;
        width = std::max<int>(width, ss.str().size());
      }
      const int N = (v.size() + 1) / 2;
      int index = 0;  // Index in this level.
      int twos = 1;   // Number of elements in this level.
      std::string separator = '|' + std::string(N * (width + 1) - 1, '-') + '|';
      std::cerr << separator << std::endl;
      for (T t : v) {
        if (index == 0) {
          std::cerr << '|';
        }
        std::cerr << std::string((width + 1) * (N / twos - 1), ' ');
        std::cerr << std::setw(width) << t << '|';
        ++index;
        if (index == twos) {
          index = 0;
          twos <<= 1;
          std::cerr << std::endl << separator << std::endl;
        }
      }
    };
    std::cerr << "v_:" << std::endl;
    debug(v_);
    std::cerr << "l_:" << std::endl;
    debug(l_);
  }

 private:
  const Operation operation_;
  const T identity_;
  const RangeOperation range_operation_;
  std::vector<T> v_;
  std::vector<T> l_;
};

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const {
    return X < m.X;
  }
};

Monster monster[200000];

int main() {
  CIN(ll, N, D, A);
  REP(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  auto add = [](ll a, ll b) -> ll { return a + b; };
  auto mul = [](ll a, int size) -> ll { return a * size; };
  SegmentTree<ll> tree(N, add, 0, mul);
  REP(i, N) tree.Set(i, monster[i].H);

  ll ans = 0;
  int mi = 0;
  while (mi < N) {
    int h = tree.Get(mi);
    if (h <= 0) {
      ++mi;
      continue;
    }
    Monster max_m = {monster[mi].X + D * 2, 0};
    int ub = upper_bound(monster, monster + N, max_m) - monster;
    ll cnt = (h + A - 1) / A;
    tree.Apply(mi, ub, -cnt * A);
    ans += cnt;
  }
  COUT(ans);
}

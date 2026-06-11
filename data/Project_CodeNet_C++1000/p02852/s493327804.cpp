#include <bits/stdc++.h>

template <typename T>
T BinarySearch(T lo, T hi, std::function<bool(T)> pred) {
  while (lo + 1 < hi) {
    T mid = (hi - lo) / 2 + lo;
    if (pred(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  SegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
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
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      if (begin <= cbegin && cend <= end) {
        return v_[index];
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(rec(cbegin, cmid, index * 2 + 1),
                        rec(cmid, cend, index * 2 + 2));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
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
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
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
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  in(int, n, m);
  in(string, s);

  SegmentTree<bool> tree(n + 1, [](bool a, bool b) { return a || b; }, false);
  rep(i, n + 1) if (s[i] == '0') tree.Set(i, true);

  vector<int> v;
  int i = n;
  while (true) {
    if (!tree.Aggregate(max(0, i - m), i)) {
      cout << -1 << endl;
      return 0;
    }
    int lo = max(0, i - m), hi = i;
    while (lo + 1 < hi) {
      int mid = (hi + lo) / 2;
      if (tree.Aggregate(lo, mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    dbg(i, lo);
    v.push_back(i - lo);
    i = lo;
    if (i == 0) {
      reverse(all(v));
      rep(i, v.size()) {
        if (i) cout << " ";
        cout << v[i];
      }
      cout << endl;
      return 0;
    }
  }
}

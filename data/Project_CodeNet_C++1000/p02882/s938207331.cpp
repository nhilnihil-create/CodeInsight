#include <cmath>
#include <cstdio>

#define int long long
#define dotimes(i, n) for (int i : range(n))

using namespace std;

class range {
  class iterator {
    int i, s;
  public:
    iterator(int i, int s): i(i), s(s) {}
    int& operator*() {
      return i;
    }
    void operator++() {
      i += s;
    }
    bool operator!=(iterator const& that) {
      return i < that.i;
    }
  };
  iterator b, e;
public:
  range(int e): b({0, 1}), e({e, 1}) {}
  range(int b, int e): b({b, 1}), e({e, 1}) {}
  range(int b, int e, int s): b({b, s}), e({e, s}) {}
  iterator begin() {
    return b;
  }
  iterator end() {
    return e;
  }
};

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

template<typename T>
inline int size(T container) {
  return static_cast<int>(container.size());
}

template<typename T>
inline bool maxs(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
inline bool mins(T& a, T const& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  double a = rint();
  double b = rint();
  double x = rint();
  double c = x / a;
  double d;
  if (c >= a * b / 2.0)
    d = atan2(b - (2.0 * c / a - b), a) / M_PI * 180;
  else
    d = 90 - atan2(2.0 * c / b, b) / M_PI * 180;
  printf("%.8lf\n", d);
  return 0;
}

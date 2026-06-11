#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

constexpr int64 divide_by = (int64)1e9 + 7;

int64 repeat_squareing(int64 n, int64 p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    int64 tmp = repeat_squareing(n, p / 2);
    return tmp * tmp % divide_by;
  } else {
    int64 tmp = repeat_squareing(n, p - 1);
    return n * tmp % divide_by;
  }
}

int64 gyakugen(int64 n) { return repeat_squareing(n, divide_by - 2); }

int64 combination(int64 n, int64 p) {
  int64 bunshi = 1;
  int64 bunbo = 1;
  for (int64 i = n; i > n - p; i--) {
    bunshi *= i;
    bunshi %= divide_by;
  }
  for (int64 i = 1; i <= p; i++) {
    bunbo *= i;
    bunbo %= divide_by;
  }
  int64 gyaku = gyakugen(bunbo);
  return bunshi * gyaku % divide_by;
}

int main() {
  int64 n;
  int64 a, b;
  cin >> n >> a >> b;
  int64 all = repeat_squareing(2, n) - 1;
  int64 comb_a = combination(n, a);
  int64 comb_b = combination(n, b);
  int64 ans = all - comb_a - comb_b;
  while (ans < 0) {
    ans += divide_by;
  }
  cout << ans % divide_by << endl;
  return 0;
}
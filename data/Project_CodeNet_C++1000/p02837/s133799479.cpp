#include <algorithm>
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

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> p(N);
  int a, x, y;
  for (int i = 0; i < N; i++) {
    cin >> a;
    for (int j = 0; j < a; j++) {
      cin >> x >> y;
      p[i].push_back(make_pair(x - 1, y));
    }
  }
  debug(p);
  int mx = 0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<20> s(tmp);
    bool break_flag = 0;
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        for (auto v : p[i]) {
          if ((v.second == 0 && s.test(v.first)) ||
              (v.second == 1 && !s.test(v.first))) {
            break_flag = 1;
            break;
          }
        }
      }
      if (break_flag) break;
    }
    if (!break_flag) mx = max(mx, (int)s.count());
  }
  cout << mx << endl;
  return 0;
}
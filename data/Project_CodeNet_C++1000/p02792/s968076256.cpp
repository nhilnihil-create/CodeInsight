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
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= N; i++) {
    string tmp = to_string(i);
    int first_keta = tmp[0] - '0';
    int last_keta = tmp.back() - '0';
    if (last_keta == 0) continue;
    pair<int, int> p_tmp = make_pair(first_keta, last_keta);
    if (mp.count(p_tmp)) {
      mp[p_tmp]++;
    } else {
      mp[p_tmp] = 1;
    }
  }
  debug(mp);
  int64 ans = 0;
  for (auto v : mp) {
    if (v.first.first == v.first.second) {
      ans += v.second;
      ans += v.second * (v.second - 1);
    } else {
      pair<int, int> rev = make_pair(v.first.second, v.first.first);
      if (mp.count(rev)) {
        ans += v.second * mp[rev];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
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
  int K;
  cin >> K;
  if (K < 10) {
    cout << K << endl;
    return 0;
  }
  vector<vector<int64>> v(10);
  for (int i = 1; i < 10; i++) {
    v[0].push_back(i);
  }
  debug(v);
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < v[i - 1].size(); j++) {
      int last_keta = v[i - 1][j] % 10;
      if (last_keta == 0) {
        v[i].push_back(v[i - 1][j] * 10 + 0);
        v[i].push_back(v[i - 1][j] * 10 + 1);
      } else if (last_keta == 9) {
        v[i].push_back(v[i - 1][j] * 10 + 8);
        v[i].push_back(v[i - 1][j] * 10 + 9);
      } else {
        v[i].push_back(v[i - 1][j] * 10 + last_keta - 1);
        v[i].push_back(v[i - 1][j] * 10 + last_keta);
        v[i].push_back(v[i - 1][j] * 10 + last_keta + 1);
      }
    }
  }
  int64 sum = 0;
  int keta = 0;
  int banme = 0;
  for (int i = 0; i < 10; i++) {
    sum += v[i].size();
    if (sum >= K) {
      keta = i;
      banme = v[i].size() - (sum - K) - 1;
      break;
    }
  }
  sort(v[keta].begin(), v[keta].end());
  cout << v[keta][banme] << endl;
  return 0;
}
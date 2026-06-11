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
  int H, N;
  cin >> H >> N;
  vector<pair<int, int>> pi(N);
  for (int i = 0; i < N; i++) {
    cin >> pi[i].first >> pi[i].second;
  }
  sort(pi.begin(), pi.end(), [](const auto& x, const auto& y) {
    if (x.second == y.second)
      return x.first < y.first;
    else
      return x.second < y.second;
  });
  debug(pi);
  vector<int> dp(202020, (int)1e9);
  dp[0] = 0;
  int idx = 1;
  for (int i = 0; i < N; i++) {
    for (int j = idx; j < pi[i].first; j++) {
      dp[j] = pi[i].second;
      idx++;
    }
  }
  // for (int i = 0; i < N; i++) {
  //   debug(dp[i]);
  // }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < H + 1; j++) {
      dp[j + pi[i].first] = min(dp[j + pi[i].first], dp[j] + pi[i].second);
    }
  }
  // for (int i = 0; i < H + 1; i++) {
  //   debug(dp[i]);
  // }
  cout << dp[H] << endl;
  return 0;
}
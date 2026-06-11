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

void add_uekara(vector<vector<int64>>& g, vector<int64>& ad, vector<int64>& ans,
                vector<int64>& visited, int64 idx) {
  ans[idx] += ad[idx];
  visited[idx] = 1;
  if (g[idx].size() == 0) return;
  for (auto v : g[idx]) {
    if (visited[v]) continue;
    ans[v] = ans[idx];
    debug(ans);
    add_uekara(g, ad, ans, visited, v);
  }
}

int main() {
  int64 N, Q;
  cin >> N >> Q;
  vector<vector<int64>> g(N);
  int64 a, b;
  for (int64 i = 0; i < N - 1; i++) {
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  debug(g);
  vector<int64> ans(N);
  int64 p, x;
  vector<int64> ad(N);
  for (int64 i = 0; i < Q; i++) {
    cin >> p >> x;
    ad[p - 1] += x;
  }
  debug(ad);
  vector<int64> visited(N);
  add_uekara(g, ad, ans, visited, 0);
  for (int64 i = 0; i < N; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
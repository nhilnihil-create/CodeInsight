#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
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
  int N, M;
  cin >> N >> M;
  int a, b;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  debug(g);
  vector<int> visit_status(N);
  vector<int> last_visit(N);
  vector<int> distance(N);
  vector<int> color(N, -1);
  int time = 0;
  function<void(int, int)> dfs = [&](int node, int col) {
    if (visit_status[node] != 0) return;
    visit_status[node] = 1;
    distance[node] = ++time;
    for (auto next_node : g[node]) {
      if (visit_status[next_node] != 0) continue;
      // color[next_node] = col;
      dfs(next_node, col);
    }
    color[node] = col;
    last_visit[node] = ++time;
  };
  int col = 0;
  for (int i = 0; i < N; i++) {
    if (color[i] == -1) {
      dfs(i, col);
      col++;
    }
  }
  debug(color);
  int ans = *max_element(color.begin(), color.end());
  cout << ans << endl;
  return 0;
}
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

void dfs(int start_node_id, vector<vector<int>>& g, vector<int>& visit_status,
         vector<int>& first_visit, vector<int>& last_visit, int& time) {
  visit_status[start_node_id] = 1;
  first_visit[start_node_id] = ++time;
  for (int i = 0; i < (int)g[start_node_id].size(); i++) {
    int node_id = g[start_node_id][i];
    if (visit_status[node_id] == 0) {
      dfs(node_id, g, visit_status, first_visit, last_visit, time);
    }
  }
  visit_status[start_node_id] = 2;
  last_visit[start_node_id] = ++time;
}

int main() {
  int n, k, u, v;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      g[i].push_back(v - 1);
      // g[v - 1].push_back(i);
    }
  }
  debug(g);
  vector<int> visit_status(n), first_visit(n), last_visit(n);
  int time = 0;
  for (int i = 0; i < n; i++) {
    if (visit_status[i] == 0) {
      dfs(i, g, visit_status, first_visit, last_visit, time);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << first_visit[i] << ' ' << last_visit[i] << endl;
  }
  return 0;
}

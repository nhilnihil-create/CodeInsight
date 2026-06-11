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

void paint(vector<map<int, int>>& g, int node, vector<int>& visited) {
  if (g[node].size() == 0) return;
  int idx = 1;
  set<int> in_use;
  for (auto v : g[node]) {
    if (v.second != -1) {
      in_use.insert(v.second);
    }
  }
  debug(in_use);
  for (auto& v : g[node]) {
    if (v.second == -1) {
      if (!in_use.count(idx)) {
        v.second = idx;
        g[v.first][node] = idx;
        in_use.insert(idx);
        idx++;
      } else {
        idx++;
        v.second = idx;
        g[v.first][node] = idx;
        in_use.insert(idx);
        idx++;
      }
    }
  }
  visited[node] = 1;
  debug(node, g);
  for (auto v : g[node]) {
    if (visited[v.first] == 0) paint(g, v.first, visited);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N - 1), b(N - 1);
  int tmp0, tmp1;
  vector<map<int, int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    cin >> tmp0 >> tmp1;
    a[i] = tmp0 - 1;
    b[i] = tmp1 - 1;
    g[a[i]][b[i]] = -1;
    g[b[i]][a[i]] = -1;
  }
  int col_num = 0;
  for (int i = 0; i < N; i++) {
    if (g[i].size() > col_num) {
      col_num = max(col_num, (int)g[i].size());
    }
  }
  vector<int> visited(N);
  paint(g, 0, visited);
  debug(g);
  cout << col_num << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << g[a[i]][b[i]] << endl;
  }
  return 0;
}
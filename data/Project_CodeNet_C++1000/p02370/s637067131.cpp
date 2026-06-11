#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli sv, se;
vector<lli> e[100001];

vector<lli> ts;
bool seen[100001];

void dfs(lli u) {
  if (seen[u]) return;
  seen[u] = true;
  for (lli v : e[u]) {
    dfs(v);
  }
  ts.push_back(u);
}

int main() {
  cin >> sv >> se;
  for (lli i=0; i<se; ++i) {
    lli u, v; cin >> u >> v;
    e[u].push_back(v);
  }
  for (lli u=0; u<sv; ++u) dfs(u);
  for (lli i=sv-1; i>=0; --i) cout << ts[i] << '\n';
  return 0;
}


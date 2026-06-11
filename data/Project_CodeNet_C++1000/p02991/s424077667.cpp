#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

vector<int> g[3 * 100000];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[3 * u].push_back(3 * v + 1);
    g[3 * u + 1].push_back(3 * v + 2);
    g[3 * u + 2].push_back(3 * v);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  queue<int> que;
  vector<int> dp(3 * n, -1);
  que.push(3 * s);
  dp[3 * s] = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto u : g[v]) {
      if (dp[u] == -1) {
        dp[u] = dp[v] + 1;
        que.push(u);
      }
    }
  }
  cout << (dp[3 * t] == -1 ? -1 : dp[3 * t] / 3) << endl;
  return 0;
}
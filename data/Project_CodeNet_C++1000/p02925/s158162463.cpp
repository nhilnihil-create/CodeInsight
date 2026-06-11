#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = MAX_N * (MAX_N) / 2;

int n, m;
int a[MAX_N][MAX_N - 1];
int id[MAX_N][MAX_N];
vector<vector<int>> g;

bool visited[MAX_M];
bool calculated[MAX_M];
int memo[MAX_M];

int dfs(int to) {
  if (visited[to]) {
    if (!calculated[to]) {
      return -1;
    }
    return memo[to];
  }
  memo[to] = 0;
  visited[to] = true;
  for (auto next : g[to]) {
    int res = dfs(next);
    if (res == -1) {
      return -1;
    }
    memo[to] = max(memo[to], dfs(next) + 1);
  }
  calculated[to] = true;
  return memo[to];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      id[i][j] = -1;
    }
  }
  m = n * (n - 1) / 2;
  g.resize(m);
  int id_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cin >> a[i][j];
      a[i][j]--;
      if (id[i][a[i][j]] < 0) {
        id[i][a[i][j]] = id_cnt;
        id[a[i][j]][i] = id_cnt;
        id_cnt++;
      }
      if (0 < j) {
        g[id[i][a[i][j - 1]]].push_back(id[i][a[i][j]]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int res = dfs(i);
    if (res == -1) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, res + 1);
  }
  cout << ans << endl;
  return 0;
}

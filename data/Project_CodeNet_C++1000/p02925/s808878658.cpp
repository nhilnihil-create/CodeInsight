#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int n;
vector<int> edge[1100000];
int state[1100000]; // 0...not yet, 1...visiting, 2...visited
int memo[1100000];
bool done[1100000];

bool is_looping(int u)
{
  if (state[u] == 2) return false;
  if (state[u] == 1) return true;
  state[u] = 1;
  
  for (int v: edge[u]) {
    if (is_looping(v)) return true;
  }
  state[u] = 2;
  return false;
}

int dfs(int u)
{
  if (done[u]) return memo[u];
  done[u] = true;
  int dist = 0;
  for (int v: edge[u]) {
    dist = max(dist, dfs(v) + 1);
  }
  return memo[u] = dist;
}

int main()
{
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int last = 0;
    for (int j = 0; j < n-1; j++) {
      int a;
      cin >> a;
      a--;
      int next = min(i, a) * 1000 + max(i, a);
      edge[last].push_back(next);
      last = next;
    }
  }
  
  if (is_looping(0)) {
    cout << -1 << endl;
    return 0;
  }
  
  cout << dfs(0) << endl;
  return 0;
}

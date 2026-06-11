#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int n;
vector<int> edge[1100000];
int source[1100000]; //　入次数
vector<int> matches;
bool done[1100000];
int memo[1100000];

bool is_cyclic()
{
  queue<int> q;
  for (int match: matches) {
    if (source[match] == 0) {
      q.push(match);
    }
  }
  
  while (q.size()) {
    int match = q.front();
    q.pop();
    for (int next_match: edge[match]) {
      source[next_match]--;
      if (source[next_match] == 0) {
        q.push(next_match);
      }
    }
  }
  
  for (int match: matches) {
    if (source[match] > 0) {
      return true;
    }
  }
  
  return false;
}

// uを始点としたときの最長パス
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
  
  matches.push_back(0);
  
  for (int i = 0; i < n; i++) {
    int last_match = 0;
    for (int j = 0; j < n-1; j++) {
      int a;
      cin >> a;
      a--;
      int next_match = min(i, a) * 1000 + max(i, a);
      edge[last_match].push_back(next_match);
      source[next_match]++;
      matches.push_back(next_match);
      last_match = next_match;
    }
  }
  
  if (is_cyclic()) {
    cout << -1 << endl;
    return 0;
  }
  
  cout << dfs(0) << endl;
  return 0;
}

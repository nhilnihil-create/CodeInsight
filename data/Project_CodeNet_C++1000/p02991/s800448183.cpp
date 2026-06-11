#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int n, m, s, t;
vector<int> edge[110000];
queue<P> q;
bool visited[110000][3];

int main()
{
  cin >> n >> m;
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
  }
  
  cin >> s >> t;
  
  q.push(make_pair(s, 0));
  visited[s][0] = true;
  
  while (q.size()) {
    for (int v: edge[q.front().first]) {
      if (visited[v][1]) continue;
      visited[v][1] = true;
      for (int w: edge[v]) {
        if (visited[w][2]) continue;
        visited[w][2] = true;
        for (int x: edge[w]) {
          if (visited[x][0]) continue;
          visited[x][0] = true;
          int ans = q.front().second + 1;
          if (x == t) {
            cout << ans << endl;
            return 0;
          }
          q.push(make_pair(x, ans));
        }
      }
    }
    q.pop();
  }
  
  cout << -1 << endl;
  return 0;
}

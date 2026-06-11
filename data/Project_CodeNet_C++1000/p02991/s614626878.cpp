#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;

int n, m, s, t;
vector<int> edge[110000];
queue<P> q;
bool visited[110000];

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
  visited[s] = true;
  
  while (q.size()) {
    for (int v: edge[q.front().first]) {
      for (int w: edge[v]) {
        for (int x: edge[w]) {
          if (visited[x]) continue;
          visited[x] = true;
          if (x == t) {
            cout << q.front().second+1 << endl;
            return 0;
          }
          q.push(make_pair(x, q.front().second+1));
        }
      }
    }
    q.pop();
  }
  
  cout << -1 << endl;
  return 0;
}
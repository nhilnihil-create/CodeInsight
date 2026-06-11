#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > G;
vector<int> INDEG;
vector<int> COLOR;

void topo() {
  for (int i = 0; i < G.size(); i++) {
    for (int j = 0; j < G[i].size(); j++) {
      INDEG[G[i][j]]++;
    }
  }

  int u;
  queue<int> Q;

  while (true) {
    u = -1;

    for (int i = 0; i < INDEG.size(); i++) {
      if (INDEG[i] == 0 && COLOR[i] == -1) {
        u = i;
        break;
      }
    }

    if (u == -1) break;
    Q.push(u);
    COLOR[u] = 1;

    for (int i = 0; i < G[u].size(); i++) {
      INDEG[G[u][i]]--;
    }
  }

  while (!Q.empty()) {
    cout << Q.front() << endl;
    Q.pop();
  }
}
    
int main() {
  int v, e; cin >> v >> e;

  G.resize(v, vector<int>());
  INDEG.resize(v, 0);
  COLOR.resize(v, -1);

  for (int i = 0; i < e; i++) {
    int s, t; cin >> s >> t;
    G[s].push_back(t);
  }

  topo();

  return 0;
}
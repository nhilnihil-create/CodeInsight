#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define INF (1<<29)

vector<int> G[MAX];
list<int> out; //やるべき仕事の順番に入ってるリスト
bool V[MAX]; //仕事が完了したかどうかを示す配列
int N; //仕事の数
int indeg[MAX]; //ノードiに入ってくる有向辺の数

void bfs(int s) {
  queue<int> q;
  q.push(s); //最初のノードをキューに入れる
  V[s] = true;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    out.push_back(u);

    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i]; //隣接するノード
      indeg[v]--;
      if (indeg[v] == 0 && !V[v]) {
        V[v] = true;
        q.push(v);
      }
    }
  }
}

void tsort() {
  for (int i = 0; i < N; i++) {
    indeg[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < G[i].size(); j++) {
      int v = G[i][j];
      indeg[v]++;
    }
  }

  for (int u = 0; u < N; u++) {
    if (indeg[u] == 0 && !V[u]) bfs(u);
  }

  for (auto it = out.begin(); it != out.end(); it++) {
    cout << *it << endl;
  }
}

int main() {
  int s, t, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++) { V[i] = false; }

  for (int i = 0; i < M; i++) {
    cin >> s >> t;
    G[s].push_back(t);
  }

  tsort();

  return 0;
}


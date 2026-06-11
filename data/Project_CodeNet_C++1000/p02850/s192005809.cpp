#include <bits/stdc++.h>
using namespace std;

// to:どこの頂点に向かっているのか
// id:色の番号
struct Edge {
  int to, id;
};

vector<vector<Edge>> graph;
vector<int> answer;

// v:頂点の番号、c:1つ上の親の色、p:1つ前に見ていた親の番号
void dfs (int v, int c = -1, int p = -1) {

  // 色を1から考える
  int k = 1;
  
  for (int i = 0; i < graph[v].size(); i++) {

    int u = graph[v][i].to;
    int ei = graph[v][i].id;
    
    // 調査済みの頂点の場合は次の辺を見る
    if (u == p) {
      continue;
    }

    // 親へ繋がっている線の色と同じ場合は色を変える
    if (k == c) {
      ++k;
    }
    
    // 色決定
    answer[ei] = k;

    // 色を変える
    ++k;

    // 再帰でチェック
    dfs(u, answer[ei], v);
  
  } 
}

int main() {

  int N;
  cin >> N;

  graph.resize(N);
  answer.resize(N-1);

  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    // 配列では0から数えるため-1する
    --a;
    --b;
    graph[a].push_back(Edge{b,i});
    graph[b].push_back(Edge{a,i});

  }

  // 探索
  dfs(0);

  // 色数＝最大次数を探して、出力
  int mx = 0;
  for (int i = 0; i < N; i++) {
    mx = max(mx, int(graph[i].size()));
  }
  cout << mx << endl;
  
  // 塗り分け例を出力
  for (int i = 0; i < N - 1; i++) {
    cout << answer[i] << endl;
  }

  return 0;

}
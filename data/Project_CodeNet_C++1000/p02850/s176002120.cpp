#include <bits/stdc++.h>
using namespace std;

// to:どこの頂点に向かっているのか
// id:色の番号
struct Edge {
  int to, id;
};

int main() {

  int N;
  cin >> N;

  vector<vector<Edge>> graph(N);
  vector<int> answer(N - 1);

  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    // 配列では0から数えるため-1する
    --a;
    --b;
    graph[a].push_back(Edge{b,i});
    graph[b].push_back(Edge{a,i});

  }

  // 探索用
  queue<int> q;

  // 頂点に色がついたか否か
  vector<int> used(N);

  // 初期設定
  q.push(0);
  used[0] = 1;

  // 探索
  while (!q.empty()) {

    int v = q.front();
    q.pop();
    
    // 色
    int c = -1;

    // qと繋がっている親を探して、親に繋がっている色を取得する
    for (int i = 0; i < graph[v].size(); i++) {

      int u = graph[v][i].to;
      int ei = graph[v][i].id;
      
      // used[u]に値が入っている頂点は唯一色が決まっている親となる
      if (used[u]) {
        c = answer[ei];
      }

    }

    // 色を1から考える
    int k = 1;

    // 色が決まっていない辺について色を決めていく
    for (int i = 0; i < graph[v].size(); i++) {
      
      int u = graph[v][i].to;
      int ei = graph[v][i].id;

      // すでに繋がっている場合は次の辺を見る
      if (used[u]) {
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

      // 次の頂点を調べる
      q.push(u);

      // 調査終わり
      used[u] = 1;

    }
  }

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
#include <bits/stdc++.h>

/* BFSで解く */
int main() {
  int n, x, y;
  std::cin >> n >> x >> y;
  
  /* グラフ */
  std::vector<std::vector<int>> G(n);

  /* 隣接リスト表現 */
  G[x-1].push_back(y-1);
  G[y-1].push_back(x-1);

  for (int i = 0; i < n-1; ++i) {
    G[i].push_back(i+1); // i=>i+1の辺 
    G[i+1].push_back(i); // i+1=>iの辺
  }


  std::vector<int> d(n, 0); // d[i]には距離がiの数を格納
  
  /* 0~n-1のすべての頂点に関してBFSでそこからの最短距離を計算する */
  for (int i = 0; i < n; ++i) {
    std::vector<int> dist(n, -1); // 出発点からの距離と未発見かどうかを管理 -1=>未発見
    std::queue<int> q;        // 訪問予定の頂点を入れる
    
    dist[i] = 0; // 出発点iの距離は0
    q.push(i);  // iを訪問予定にする

    /* qが空になるまで続ける */
    while (!q.empty()) {
      int v = q.front();
      q.pop();

      /* vと隣接する頂点で未訪問の頂点をqに加える */
      for (int nv : G[v]) {
        /* 訪問済みの頂点はskip */
        if (dist[nv] != -1) continue;

        /* 訪問予定の頂点をqに加える */
        dist[nv] = dist[v] + 1;
        q.push(nv);

        /* 距離をカウント */
        d[dist[nv]]++; 
      }
    }
  }

  /* ダブリを削除 */
  for (size_t i = 1; i < d.size(); ++i) 
    d[i] /= 2;
  
  /* 結果表示 */
  for (size_t i = 1; i < d.size(); ++i)
    std::cout << d[i] << std::endl;

  return 0;
}

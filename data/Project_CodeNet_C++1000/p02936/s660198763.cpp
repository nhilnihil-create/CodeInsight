#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> count[200100];
int ans[200100];

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v, int p) {
    seen[v] = true; // v を訪問済にする
  if (p != -1) ans[v] = ans[p];
  for (auto a : count[v]){
    ans[v] += a;
  }

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数、s と t
    int N, Q; cin >> N >> Q;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
  
    for (int i = 0; i < Q; i++) {
      int a, b;
      cin >> a >> b;
      count[a - 1].push_back(b);
    }

    // 頂点 s をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    for (int i = 0; i < N; i++) ans[i] = 0;
    dfs(G, 0, -1);
  
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
}
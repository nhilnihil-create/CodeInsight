//参考: https://qiita.com/drken/items/4a7869c5e304883f539b
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
vector<int> ans;
vector<int> add;

void dfs(const Graph &G, int v, int val) {
    seen[v] = true; // v を訪問済にする
    val += add[v];
    ans[v] = val;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, val); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, Q; cin >> N >> Q;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    add.assign(N, 0);
    for(int i =0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        add[a] += b;
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    ans.assign(N, 0);
    dfs(G, 0, 0);
    for(auto a : ans){
        cout << a << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
int count; //連結成分の数をカウント

void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする
    count ++;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main(){
    int N , M;
    cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(N, false);
    int ans = 0;
    for(int i = 0; i < N; i++){
        count = 0;
        if(seen[i]){
            continue;
        }
        dfs(G, i);
        if(count > ans) ans = count;
    }
    cout << ans << endl;
    return 0;        
}
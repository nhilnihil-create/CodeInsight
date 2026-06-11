#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define MAX 200
int n;
vector<vector<int>> adj_mat(MAX, vector<int>(MAX, 0));

queue<int> q;
vector<int> visited(MAX, -1);
vector<int> d(MAX, -1);

void add_queue(int node){
    // cout << "node " << node << " unvisited & adj";
    rep(i, n){
        if(adj_mat.at(node).at(i) == 1 && visited.at(i) == -1){
            // nodeに隣接し、まだ訪れていないノード
            q.push(i);
            d.at(i) = d.at(node) + 1;
            visited.at(i) = 1;
            // cout << " " << i;

        }
    }
    // cout << endl;
}

void bfs(int node){
    q.push(node);
    d.at(node) = 0;
    visited.at(node) = 1;
    while(q.size() != 0){
        int visited_node = q.front();
        q.pop();
        // visited.at(visited_node) = 1;
        add_queue(visited_node);

    }
}

int main(){
    cin >> n;

    // 隣接行列の作成
    rep(i, n){
        int u, k; cin >> u >> k;
        rep(j, k){
            int v; cin >> v;
            adj_mat.at(u-1).at(v-1) = 1;
        }
    }

    bfs(0);
    rep(i, n){
        cout << i+1 << " " << d.at(i) << endl;
    }

}

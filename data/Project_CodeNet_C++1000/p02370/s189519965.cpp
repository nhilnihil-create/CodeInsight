#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<int> to[10007];
vector<int> color(10007);
stack<int> ans;

void dfs(int u){
    color[u] = 1;
    for (int i = 0; i < to[u].size(); i++){
        int v = to[u][i];
        if(color[v] == 0){
            dfs(v);
        }
    }
    ans.push(u);
}

int main() {
    int V, E; cin >> V >> E;
    rep(i, E){
        int s, t; cin >> s >> t;
        to[s].push_back(t);
    }

    for (int i = 0; i < V; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }

    while(!ans.empty()){
        int x = ans.top(); ans.pop();
        cout << x << endl;
    }



    return 0;
}

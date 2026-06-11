#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int v, e; cin >> v >> e;
    Graph G(v);
    vector<int> indegree(v);
    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        indegree[b]++;
    }
    queue<int> que;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0) que.push(i);
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int nv: G[now]){
            if(--indegree[nv] == 0) que.push(nv);
        }
        G[now].clear();
        cout << now << endl;
    }
}

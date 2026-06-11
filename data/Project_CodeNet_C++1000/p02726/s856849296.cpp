#include <bits/stdc++.h>
using namespace std;
const int INF = 1e4;

vector<vector<int>> graph;
vector<int> d;

void DFS(int v, int prev_v, int c){
    if(d[v] < c) return ;
    d[v] = c;

    for(int next_v : graph[v]){
        if(next_v != prev_v){
            DFS(next_v, v, c+1);
        }
    }
    return ;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    graph.resize(n);
    x -= 1;
    y -= 1;

    for(int i=0; i<n; i++){
        if(i+1 <  n) graph[i].push_back(i+1);
        if(i-1 >= 0) graph[i].push_back(i-1);
    }
    graph[x].push_back(y);
    graph[y].push_back(x);

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        d.assign(n, INF);
        DFS(i, -1, 0);
        for(int j=0; j<n; j++){
            ans[d[j]] += 1;
        }
    }

    for(int i=1; i<n; i++){
        cout << ans[i] / 2 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<bool> seen, calculated;
vector<vector<int>> graph;
vector<int> dp;

int dfs(int v){
    if(seen[v]){
        return (calculated[v] ? dp[v] : -1);
    }
    seen[v] = true;
    for(auto e : graph[v]){
        int res = dfs(e);
        if(res == -1) return -1;
        dp[v] = max(dp[v], res + 1);
    }
    calculated[v] = true;
    return dp[v];
}

int toId(int i, int j){
    if(i < j) return toId(j, i);
    return (i*(i-1) / 2 + j + 1);
}

int main() {
    int n;
    cin >> n;
    graph.resize(n * (n - 1) / 2 + 1);
    for(int i = 0; i < n; i++){
        int a = 0;
        for(int j = 0; j < n - 1; j++){
            int b;
            cin >> b, b = toId(i, b-1);
            graph[a].push_back(b);
            a = b;
        }
    }

    seen.resize(n * (n - 1) / 2 + 1);
    calculated.resize(n * (n - 1) / 2 + 1);
    dp.resize(n * (n - 1) / 2 + 1);
    cout << dfs(0) << endl;
    return 0;
}
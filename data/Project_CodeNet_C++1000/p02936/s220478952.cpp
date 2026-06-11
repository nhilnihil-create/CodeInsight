#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int c = 300000;
vector<vector<int>> g(c);
vector<int> nums(c);

void dfs(int v, int p){
    for (auto j : g[v]){
        if (j == p) continue;
        nums[j] += nums[v];
        dfs(j,v);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    
    // 隣接リストを作る
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    // 部分期頂点のみにqを加算する
    for (int i = 0; i < q; i++){
        int p, q;
        cin >> p >> q;
        p--;
        nums[p] += q;
    }
    
    // 値をroot->leafへ押し流す DFS
    dfs(0,-1);
    
    for (int i = 0; i < n; i++){
        if (i != n-1) cout << nums[i] << " ";
        else cout << nums[i] << endl;
    }
}
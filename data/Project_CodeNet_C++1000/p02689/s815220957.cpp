#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> h(n);
    vector<bool> used(n, false);
    priority_queue<pair<int,int>> tar;
    vector<vector<int>> edge(n, vector<int>());
    for(int i=0;i<n;i++){
        cin >> h[i];
        tar.push({h[i], i});
    } 
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans = 0;
    while(!tar.empty()){
        int height, node;
        tie(height, node) = tar.top();tar.pop();
        if(used[node]) continue;
        bool good = true;
        for(auto e: edge[node]){
            if(h[e] >= height) good = false;
            if(h[e] <= height) used[e] = true;
        }
        if (good) ans ++;
    }
    cout << ans << endl;
}
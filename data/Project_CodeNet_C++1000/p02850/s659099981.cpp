#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> vp;
    
    for (int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        
        vp.push_back({a, b});
    }
    
    std::queue<int> q;
    vector<int> used(n, 0);
    vector<int> parent(n, 0);
    
    int max_color = 0;
    map<pair<int, int>, int> ans;
    q.emplace(0);
    used[0] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        int cn = 0;
        for (auto nv: g[v]){
            if(used[nv] != 0) continue;
            cn++;
            used[nv] = 1;
            if (cn == parent[v]) cn++;
            
            pair<int, int> p = {v, nv};
            ans[p] = cn;
            parent[nv] = cn;
            q.push(nv);
        }
        max_color = max(max_color, cn);
    }
    
    cout << max_color << endl;
    for (int i=0; i<n-1; i++){
        cout << ans[vp[i]] << endl;
    }
    
}

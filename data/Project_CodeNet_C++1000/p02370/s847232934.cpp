#include <bits/stdc++.h>

using namespace std;

vector<int> es[10000];
int h[10000];

int main() {
    int V, E;
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v);
        h[v]++;
    }
    
    stack<int> st;
    for (int i = 0; i < V; i++) if (h[i] == 0) st.push(i);
    
    vector<int> ans;
    
    while (!st.empty()) {
        int u = st.top(); st.pop();
        ans.push_back(u);
        
        for (auto v: es[u]) {
            h[v]--;
            if (h[v] == 0) st.push(v);
        }
    }
    
    for (auto u: ans) cout << u << endl;
    
    return 0;
}

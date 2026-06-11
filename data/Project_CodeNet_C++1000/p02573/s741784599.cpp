#include <bits/stdc++.h>
#define int long long

using namespace std;

void dfs(vector<set<int>>& g, int u, int cur_comp, vector<int>& components) {
    if (components[u] != -1) {
        return;
    }
    components[u] = cur_comp;
    for(auto v : g[u]) {
        dfs(g, v, cur_comp, components);
    }
}


int32_t main() {
    int n,m;
    cin >> n >> m;
    vector<set<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        v[a].insert(b);
        v[b].insert(a);
    }
    vector<int> components(n, -1);
    int cur_comp = 0;
    for(int i = 0; i < n; ++i) {
        if (components[i] == -1) {
            dfs(v,i,cur_comp, components);
            cur_comp++;
        }
    }
    vector<int> sizes(cur_comp, 0);
    for (int i = 0; i < components.size(); ++i) {
        sizes[components[i]]++;
    }
    cout << *max_element(sizes.begin(), sizes.end());
}
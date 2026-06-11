#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
vector<int> dad, sizes;
 
void create(int n){
    dad.resize(n);
    sizes.assign(n, 1);
    for(int i = 0; i < n; i++)
        dad[i] = i;
}
 
int find_set(int u){
    return u == dad[u] ? (u) : (u = find_set(dad[u]));
}
 
void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(sizes[u] < sizes[v])
            swap(u, v);
        sizes[u] += sizes[v];
        dad[v] = u;
    }
}
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int i, n, m, j, u, v;
    cin >> n >> m;
    create(n);
    for(i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        union_set(u, v);
    }
    int ans = 0;
    for(i = 0; i < n; i++){
        ans = max(ans, sizes[find_set(i)]);
    }
    
    cout << ans << endl;
}
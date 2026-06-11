#include <bits/stdc++.h>

using namespace std;
int n, m;
int parent[100000+5];

int find(int v){
    if(parent[v]==v)return v;
    return parent[v] = find(parent[v]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        parent[v] = u;
    }
}

int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    while(m--){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    
    set<int> S;
    for(int i = 1; i <= n; i++){
        S.insert(find(i));
    }
    
    cout << S.size()-1 << endl;
    
    return 0;
    
}



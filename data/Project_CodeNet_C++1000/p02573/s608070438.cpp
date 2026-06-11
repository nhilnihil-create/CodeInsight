#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int parent[1000000];

int find(int v){
    if(parent[v] == v)return v;
    return parent[v] = find(parent[v]);
}

void merge(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a != b){
        parent[b] = a;
    }
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    
    while(m--){
        
        int u, v;
        cin >> u >> v;
        
        merge(u, v);
        
    }
    
    vector<int> table(n+1, 0);
    for(int i = 1; i <= n; i++){
        table[find(i)]++;
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++){
        answer = max(answer, table[i]);
    }
    
    cout << answer << endl;
    
    return 0;
    
}
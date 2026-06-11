#include<bits/stdc++.h>
using namespace std;

vector<int> root;
vector<int> Rank;

//通常バージョン
int find(int x){
    if (root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

bool check(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    x = find(x); y = find(y);
    if (check(x, y)){
        return;
    }
    if (Rank[x] >= Rank[y]) root[y] = x;
    else root[x] = y;
    if (Rank[x] == Rank[y]) Rank[x]++;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> set_root(n);
    for (int i = 0; i < n; i++) set_root[i] = i;
    root = set_root;
    vector<int> set_Rank(n, 0);
    Rank = set_Rank;
    for (int i = 0; i < m; i++){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) Union(u, v);
		if (t == 1) cout << check(u, v) << endl;
    }
}
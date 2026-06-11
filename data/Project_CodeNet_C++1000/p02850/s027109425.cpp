#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge{
    int to;
    int id;
    Edge(int t, int i):to(t), id(i){}
};
vector<int> ans;
int k = 0;

void dfs(vector<vector<Edge>> &G, int u, int v,int c){
    int k = 1;
    for(int i = 0; i < G[u].size(); i++){
        if(G[u][i].to == v) continue;
        if(k == c) k++;
        ans[G[u][i].id] = k; k++;
        dfs(G, G[u][i].to, u, ans[G[u][i].id]);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<vector<Edge>> G(n);
    ans.resize(n);
    ans.assign(n, 0);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(Edge(b, i + 1));
        G[b].push_back(Edge(a, i + 1));
    }
    int x;
    rep(i, n){
        if(k < int(G[i].size())){
            k = G[i].size();
            x = i;
        }
    }
    cout << k << endl;
    dfs(G, x, -1, 0);
    for(int i = 1; i  < n ; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
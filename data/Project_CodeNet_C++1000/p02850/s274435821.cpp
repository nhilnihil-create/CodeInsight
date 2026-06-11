#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)
using Edge = pair<int,int>;
using Graph  = vector<vector<Edge> >;

ll N;
Graph G;

void dfs(int v, int p, int pc, vector<int> &res){
    int color = 1;
    if(color == pc) color++;
    for(auto &nv : G[v]){
        if(nv.first == p) continue;
        res[nv.second] = color;
        dfs(nv.first, v, color, res);
        color++;
        if(color == pc) color++;
    }
}

int main(){
    cin >> N;
    G.assign(N, vector<Edge>());
    rep(i,0,N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(make_pair(b,i));
        G[b].push_back(make_pair(a,i));
    }
    int ma = 0;
    for(auto &v : G){
        ma = max(ma, (int)v.size());
    }
    vector<int> res(N-1,-1);
    dfs(0,-1,-1,res);

    cout << ma << endl;
    rep(i,0,N-1){
        cout << res[i] << endl;
    }
}
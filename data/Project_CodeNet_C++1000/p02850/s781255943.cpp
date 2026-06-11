#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using ll = long long;
using P = pair<int, int>;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct Edge{
    int to, id;
    Edge(int to, int id):to(to), id(id){}
};

int n;
vector<vector<Edge>> G;
vector<int> res;

void dfs(int v, int p, int pc){
    int color = 1;
    if(color==pc)color++;
    for(auto e : G[v]){
        if(e.to == p) continue;
        res[e.id] = color;
        dfs(e.to, v, color);
        ++color;
        if(color == pc) ++ color;
    }
}


int main(){
    cin >> n;
    G.resize(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b; 
        --a, --b;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    int mx = 0;
    rep(i,n) mx = max(mx, (int)G[i].size());
    res.assign(n-1, 0);
    dfs(0, -1, -1);
    cout << mx << endl;
    for(auto v : res) cout << v << endl;
    return 0;
}
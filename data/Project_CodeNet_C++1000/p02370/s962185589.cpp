#include <bits/stdc++.h>
#define ll long long
#define V vector<long long>
#define VV vector<vector<long long>>
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

VV g;
vector<bool> used;
V topo;

void dfs(ll now){
    if(used[now])return;
    used[now]=true;
    for(ll to:g[now]){
        dfs(to);
    }
    topo.push_back(now);
}

int main(){
    ll n,m;
    cin>>n>>m;
    g.assign(n, V());
    rep(i,m){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    used.assign(n, false);
    rep(i,n)dfs(i);
    reverse(topo.begin(), topo.end());
    rep(i,n)cout<<topo[i]<<endl;
}


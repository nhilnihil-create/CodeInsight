#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
using Graph = vector<vector<ll>>;
Graph G;
ll n,q;
void dfs(ll v,ll p,vector<ll> &res){
    if(p!=-1) res[v]+=res[p];
    for(auto nv:G[v]){
        if(nv==p) continue;
        dfs(nv,v,res);
    }
    return;
}



int main(){
    cin >> n >> q;
    G.assign(n, vector<ll>());
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> c(n,0);
    for(ll i=0;i<q;i++){
        ll p,x;
        cin >> p >> x;
        p--;
        c[p]+=x;
    }
    dfs(0,-1,c);
    for(ll i=0;i<n;i++){
        cout << c[i] << " ";
    }
    cout << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

void dfs(ve<ve<int>> &G, ve<int> &ans,int i, int j,int a){
    ans[i] += a;
    for(int x:G[i]){
        if(x==j) continue;
        dfs(G,ans,x,i,ans[i]);
    }
    return;
}

int main(){
    int n,q;
    cin >> n >> q;
    ve<ve<int>> G(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ve<int> ans(n);
    rep(i,q){
        int p,x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(G,ans,0,-1,0);
    rep(i,n) {
        cout << ans[i] << endl;
    }
    return 0;
}
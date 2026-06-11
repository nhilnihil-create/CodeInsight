#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> G;
ll ans[200010];

void dfs(int v,int p=-1){
    for(auto nv : G[v]){
        if(nv==p) continue;
        ans[nv]+=ans[v];
        dfs(nv,v);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    G.resize(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i,q){
        int p;
        ll x;
        cin>>p>>x;
        p--;
        ans[p]+=x;
    }

    dfs(0);

    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<int>> G;
ll c[200000];
bool seen[200000];

void dfs(int x){
    seen[x]=true;

    for(auto i : G[x]){
        if(seen[i])continue;
        c[i]+=c[x];
        dfs(i);
    }
}

int main(){
    int N,Q; cin>>N>>Q;
    G.resize(N);
    rep(i,N-1){
        int a,b; cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    rep(i,N){
        seen[i]=false;
        c[i]=0;
    }
    rep(i,Q){
        int p,x;
        cin>>p>>x;
        c[p-1]+=x;
    }
    dfs(0);
    rep(i,N){
        if(i!=N-1)cout<<c[i]<<" ";
        else cout<<c[i]<<endl;
    }
    return 0;
}
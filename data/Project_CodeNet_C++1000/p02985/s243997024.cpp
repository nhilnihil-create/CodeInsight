#include<iostream>
#include<vector>
using namespace std;

static const long long MOD=1e9+7;

int n,k;
vector<vector<int>> g;

long long dfs(int k, int v, int p){ 
    int color=(p==-1)?k-1:k-2;
    //cout<<"color: "<<color<<endl;
    if(k<g[v].size()) return 0;
    long long res=1;
    for(auto nv: g[v]){
        if(nv==p) continue;
        res*=color--;
        res%=MOD;
    }
    for(auto nv: g[v]){
        if(nv==p) continue;
        res*=dfs(k,nv,v);
        res%=MOD;
    }
    //cout<<"k: "<<k<<" v: "<<v<<" p: "<<p<<endl;
    //cout<<"res: "<<res<<endl;
    return res;
}

int main(){
    cin>>n>>k;
    g.resize(n);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long res=(k*dfs(k,0,-1))%MOD;
    cout<<res<<endl;
}
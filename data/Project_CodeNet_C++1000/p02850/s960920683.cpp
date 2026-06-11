#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

vector<int>to[100010],id[100010],ans;

void dfs(int v, int c=-1, int p=-1){
    int k=1;
    rep(i,to[v].size()){
        int u=to[v][i],ei=id[v][i];
        if(u==p)continue;
        if(k==c)k++;
        ans[ei]=k; k++;
        dfs(u,ans[ei],v);
    }
}

int main(){
    int n;
    cin>>n;
    ans.resize(n);
    rep(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        id[a].push_back(i);
        id[b].push_back(i);
    }
    dfs(0);
    int mx=0;
    rep(i,n-1)mx=max(mx,ans[i]);
    cout<<mx<<endl;
    rep(i,n-1)cout<<ans[i]<<endl;
    return 0;
}
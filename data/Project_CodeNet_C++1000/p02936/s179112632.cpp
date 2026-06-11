#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e5+5;
vector<int>g[maxm];
int L[maxm],R[maxm],idx;
int a[maxm];
int n,q;
void dfs(int x,int fa){
    L[x]=++idx;
    for(int v:g[x]){
        if(v==fa)continue;
        dfs(v,x);
    }
    R[x]=idx;
}
signed main(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    while(q--){
        int x,val;cin>>x>>val;
        a[L[x]]+=val;
        a[R[x]+1]-=val;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<a[L[i]]<<' ';
    }
    return 0;
}

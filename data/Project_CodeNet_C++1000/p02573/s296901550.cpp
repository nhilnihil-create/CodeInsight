#include <bits/stdc++.h>
//#include <atcoder/all>
using ll = long long;
using namespace std;
//using namespace atcoder;

int par[200000],siz[200000];

int find(int a) {
    if (par[a]==a)
        return a;
    return par[a]=find(par[a]);
}

void unite(int a,int b) {
    a=find(a);
    b=find(b);
    if (a==b)
        return;
    par[b]=a;
    siz[a]+=siz[b];
}

int main() {
    int n,m;cin>>n>>m;
    for (int i=0;i<n;i++) {
        par[i]=i;
        siz[i]=1;
    }
    int ans=1;
    for (int i=0;i<m;i++) {
        int a,b;cin>>a>>b;
        unite(a-1,b-1);
        ans=max(ans,siz[par[a-1]]);
    }
    cout<<ans<<endl;
    return 0;
}
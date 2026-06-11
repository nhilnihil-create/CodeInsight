#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

struct UnionFind{
    vector<int> par;

    UnionFind(int N):par(N,-1){}

    int root(int x){
        if(par[x]<0) return x;
        return par[x]=root(par[x]);
    }

    bool unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry) return false;
        if(par[rx]>par[ry]) swap(rx,ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }

    bool issame(int x,int y){
        return root(x)==root(y);
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind UN(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        UN.unite(a,b);
    }
    int ans=0;
    rep(i,n){
        ans = max(ans,UN.size(i));
    }
    cout << ans << endl;
}
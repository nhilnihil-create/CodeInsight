#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct UnionFind{
    vector<int>p,r;
    UnionFind(int n){
        p.resize(n,-1);
        r.resize(n,1);
    }
    int find(int x){
        if(p[x]==-1)return x;
        else return p[x]=find(p[x]);
    }
    void unite(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(r[x]>r[y])swap(x,y);
        if(r[x]==r[y])r[y]++;
        p[x]=y;
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    UnionFind uf(n);
    rep(i,q){
        int p,a,b;
        cin>>p>>a>>b;
        if(p==0){
            uf.unite(a,b);
        }
        else{
            cout<<(uf.same(a,b)?"1":"0")<<endl;
        }
    }
}

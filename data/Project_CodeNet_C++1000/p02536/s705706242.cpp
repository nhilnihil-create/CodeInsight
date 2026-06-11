#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;

struct UnionFind{
    int gro=0;
    vector<int> d;
    UnionFind(int n=0){
        d=vector<int>(n,-1);
        gro=n;
    }
    int find(int a){
        if(d[a]<0) return a;
        return d[a]=find(d[a]);
    }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        gro--;
        if(d[a]>d[b]) swap(a,b);
        d[a]+=d[b];
        d[b]=a;
        return true;
    }
    bool same(int a,int b){return find(a)==find(b);}
    int size(int a) {return -d[find(a)];}
    int group() {return gro;}
};

int main()
{
    int n,m;
    cin>>n>>m;
    UnionFind uf(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;a--;b--;
        if(!uf.same(a,b)){
            uf.unite(a,b);
        }
    }
    cout<<uf.group()-1<<endl;
    return 0;
}
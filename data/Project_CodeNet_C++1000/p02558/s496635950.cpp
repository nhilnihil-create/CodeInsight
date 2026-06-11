#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

struct UnionFind
{
    int i;
    vector<int> par;
    vector<int> size;
    UnionFind(int n): par(n),size(n,1){
        for(i = 0;i < n;++i){
            par.at(i) = i;
        }
    }
    
    int root(int x){
        if(par.at(x) == x){
            return x;
        }else{
            return par.at(x) = root(par.at(x));
        }
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return;
        }else{
            if(size.at(rx) < size.at(ry)){
                swap(rx,ry);
            }
            par.at(ry) = rx;
            size.at(rx) += size.at(ry);
            return;
        }
    }
    
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    
    int get_size(int x){
        return size.at(root(x));
    }
};

int main()
{
    ll i,j;
    ll n, q;
    cin >> n >> q;
    UnionFind uf(n);
    rep(i,q){
        ll c;
        cin >> c;
        ll u,v;
        cin >> u >> v;
        if(c) cout << uf.same(u, v) << endl;
        else uf.unite(u,v);
    }

    return 0;
}
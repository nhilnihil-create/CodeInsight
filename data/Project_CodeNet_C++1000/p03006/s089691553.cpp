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
    ll n;
    cin >> n;
    vector<pair<ll,ll>> xy(n);
    for(i = 0;i < n;++i){
        cin >> xy.at(i).first >> xy.at(i).second;
    }
    ll ans = n;
    for(i = 0;i < n-1;++i){
        for(j = i+1;j < n;++j){
            ll tx = xy.at(j).first - xy.at(i).first;
            ll ty = xy.at(j).second - xy.at(i).second;
            ll k, l;
            UnionFind uf(n);
            for(k = 0;k < n-1;++k){
                for(l = k+1;l < n;++l){
                    ll sx = xy.at(l).first - xy.at(k).first;
                    ll sy = xy.at(l).second - xy.at(k).second;
                    if((sx == tx && sy == ty) || (sx == -tx && sy == -ty)) uf.unite(k, l);
                }
            }
            ll tmp = 0;
            for(k = 0;k < n;++k){
                if(uf.root(k) == k) ++tmp;
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}
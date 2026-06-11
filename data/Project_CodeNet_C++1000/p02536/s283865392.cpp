#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
    ll n,m;
    cin >> n >> m;
    UnionFind tree(n);
    ll ans=n-1;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        if(!tree.issame(a,b)){
            tree.merge(a,b);
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}  

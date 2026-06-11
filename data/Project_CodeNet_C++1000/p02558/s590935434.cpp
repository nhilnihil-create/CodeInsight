#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

using i64 = long long;

const i64 MOD = i64(1e9) + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

signed main(){
    using atcoder::dsu;
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    for(int i = 0; i < q; ++i){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0)
            uf.merge(u, v);
        else
            cout << uf.same(u, v) << endl;
    }
}


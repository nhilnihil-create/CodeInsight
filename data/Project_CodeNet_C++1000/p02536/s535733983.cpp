#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
#define rep(i,n) for (ll i=0;i<n;i++)
using namespace std;

struct UnionFind {
    vector<ll> par;
    vector<ll> rank;

    UnionFind(ll N) : par(N),rank(N){
        // 初期化
        rep(i,N) {
            par[i] = i;
            rank[i] = 0;
        }
    }


    ll root(ll x){
        // unionfind木をたどって頂点を探す
        if(par[x]==x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(ll x,ll y){
        // 高さを考慮し、結合する。
        ll rx = root(x);
        ll ry = root(y);
        if(rx==ry) return;
        if(rank[x]<rank[y]){
            par[rx] = y;
        }else{
            par[ry] = x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }

    bool same(ll x,ll y){
        // 親が同じなら同じグループ
        return root(x)==root(y);
    }

};

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    UnionFind tree(n);

    rep(i,m){
        ll a,b;
        cin >> a >> b;
        tree.unite(a,b);
    }

    ll ans = 0;
    vector<ll> cnt(n);
    rep(i,n){
        cnt[i] = tree.root(i);
    }
    sort(cnt.begin(),cnt.end());
    rep(i,n-1){
        if(cnt[i]!=cnt[i+1]){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
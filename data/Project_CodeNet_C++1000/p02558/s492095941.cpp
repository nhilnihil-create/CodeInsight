#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define ll long long
using namespace std;

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll N) : par(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main(){
    ll n,q; cin>>n>>q;
    UnionFind tree(n);
    
    for(ll i=0; i<q; i++){
        ll a,b,c; cin>>a>>b>>c;
        if(a==0) tree.unite(b,c);
        if(a==1){
            if(tree.same(b,c)) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
}
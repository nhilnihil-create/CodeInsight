#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;

struct UnionFind {
    vector<ll> d;
    //親(負)…木のsize*(-1)
    //子(正)…親のindex

    UnionFind(ll n){
        d = vector<ll>(n,-1);        
    }
    //初期化

    ll find(ll x){
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    //親のindexを返す

    bool unite(ll x,ll y){
        x = find(x);
        y = find(y);

        if (x == y) return false;

        if (d[x] >d[y]) swap(x,y);

        d[x] += d[y];
        d[y] = x;

        return true;
    }
    //木と木を接続する

    bool same(ll x,ll y){
        return find(x) == find(y) ? true : false;
    }
    //xとyの親が同じか判定する

    ll size(ll x){
        return -d[find(x)];
    }
    //xが属する木のsizeを返す
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    UnionFind uf(n);

    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;

        uf.unite(a,b);
    }

    ll ans = 0;
    rep(i,n){
        ans = max(ans,uf.size(i));
    }

    cout << ans << endl;


}
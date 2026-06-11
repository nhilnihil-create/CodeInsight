#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef complex<double> comp;
const ll INF=1e9+7;
const ll MOD=998244353;
const int MAX=200010;

struct UnionFind {
    vector< int > data;

    UnionFind() = default;

    explicit UnionFind(size_t sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return data[k] = find(data[k]);
    }

    int size(int k) {
        return -data[find(k)];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,q;cin>>n>>q;
    UnionFind uf(n);
    rep(tmp,q){
        ll i,u,v;cin>>i>>u>>v;
        if(i){
            ll ans=uf.same(u,v);
            cout<<ans<<endl;
        }else{
            uf.unite(u,v);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
struct UnionFind {
    vector<int> par;
    vector<long long> siz;
    long long psiz;

    UnionFind(int N) : par(N),siz(N,1LL),psiz(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if(siz[rx] < siz[ry]) swap(rx,ry);
        siz[rx] += siz[ry];
        psiz -= siz[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    long long size(int x){
        return siz[root(x)];
    }
    long long psize() {
        return psiz;
    }
};

int main(){
    int n,q;
    cin >> n >> q;
    UnionFind tree(n);
    rep(i,q){
        int t,u,v;
        cin >> t >> u >> v;
        if (t){
            if(tree.same(u,v)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else{
            tree.unite(u,v);
        }
    }
}
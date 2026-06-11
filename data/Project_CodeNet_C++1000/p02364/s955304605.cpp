#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

class UnionFind{
public:
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll k):par(k), siz(k,1LL){
        for(int i = 0; i < k; i++) par[i] = i;
    }

    ll root(ll k){
        if(par[k] == k) return k;
        else return par[k] = root(par[k]);
    }
    
    bool unite(ll x, ll y){
        x = root(x);
        y = root(y);
        if(x==y) return false;

        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    bool same(ll x, ll y){
        return root(x) == root(y);
    }

    ll size(ll x){
        return siz[root(x)];
    }
};

struct edge{
    ll from, to, cost;
};

bool comp(const edge& a, const edge& b){
    return a.cost < b.cost;
}

vector<edge> ed;
ll V, E;

int main(){
    cin >> V >> E;
    ed.resize(E);
    rep(i,E){
        ll a, b, c;
        cin >> a >> b >> c;
        edge e = {a,b,c};
        ed[i] = e;
    }
    UnionFind uf(V);
    ll ans = 0;
    sort(ed.begin(), ed.end(), comp);
    for(int i = 0; i < E; i++){
        edge e = ed[i];
        if(!uf.same(e.from, e.to)){
            uf.unite(e.from, e.to);
            ans += e.cost;
        }
    }
    cout << ans << endl;
}

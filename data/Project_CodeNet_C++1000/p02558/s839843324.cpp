#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Union_Find_Tree{
    vector<int> par, rank, num;
    const int n;
    
    Union_Find_Tree(int n) : n(n){
        par.assign(n, -1), rank.assign(n, 0), num.assign(n, 1);
    }
    
    int root(int x){
        if(par[x] < 0 || par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x, num[x] += num[y];
        return true;
    }
    
    int size(int x) {return num[root(x)];}
    
    bool same(int x, int y) {return root(x) == root(y);}
    
    void clear(){
        fill(all(par), -1), fill(all(rank), 0), fill(all(num), 1);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int N, Q;
    cin >> N >> Q;
    Union_Find_Tree uf(N);
    while(Q--){
        int q, u, v; cin >> q >> u >> v;
        if(q == 0) uf.unite(u, v);
        else cout << uf.same(u, v) << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
using intmap = map<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
inline bool bit (ll b, ll i) { return b & (1 << i); }
inline ll ceiv (ll a, ll b) { return (a + b - 1) / b; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define debug(x) cerr << #x << ": " << x << '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

class UnionFind {
    vector<int> par, treesize;
    int groups;
    
public:
    UnionFind(int n){
        rep(i, n) par.push_back(i);
        treesize = vector<int>(n,1);
        groups = n;
    }
    
    int root(int x){
        if(x == par[x]) return x;
        return par[x] = root(par[x]);
    }
    
    bool same(int x, int y){
        return root(x) == root(y);
    }
    
    void unite(int x, int y){
        if(same(x,y)) return;
        int rx = root(x), ry = root(y);
        treesize[ry] += treesize[rx];
        treesize[rx] = 0;
        groups--;
        par[rx] = ry;
    }
    
    int get_size(int x){
        return treesize[root(x)];
    }
    
    int get_groups(){ return groups; }
};

signed main(){
    int n, k;
    cin >> n >> k;
    vi p(n), c(n);
    rep(i,n){
        cin >> p[i]; p[i]--;
    }
    rep(i,n) cin >> c[i];
    
    UnionFind loop_union(n);
    vi loop_score(n);
    rep(i,n){
        if(loop_union.get_size(i) != 1) continue;
        int j = p[i];
        int score = c[i];
        while(j != i) {
            loop_union.unite(j, p[j]);
            score += c[j];
            j = p[j];
        }
        loop_score[loop_union.root(i)] = score;
    }
    
    int ans = -9e18;
    rep(i,n){
        int t_score = 0;
        const int LOOPSIZE = loop_union.get_size(i);
        
        int j = i;
        rep(_, min(k, LOOPSIZE)){
            j = p[j];
            t_score += c[j];
            ans = max(ans, t_score);
        }
        
        const int LOOPS = k / LOOPSIZE;
        t_score = (LOOPS - 1) * loop_score[loop_union.root(i)];
        
        const int STEPS = k - ((LOOPS - 1) * LOOPSIZE);
        if(LOOPS == 0) continue;
        
        j = i;
        rep(_, STEPS){
            j = p[j];
            t_score += c[j];
            ans = max(ans, t_score);
        }
    }
    
    cout << ans << endl;
}
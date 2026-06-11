#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os, const map<T,U>& mp){ os << "{"; for(auto& p : mp){ os << p << ","; } os << "}"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int,int>;
using vi = std::vector<int>;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/


struct SCC{
    int V; // # of node
    vector<vector<int>> G,rG;
    vector<int> vs,cmp; // vs:行きかけ順序の並び cmp:どの集合に属するか?
    vector<bool> used;

    SCC(){}
    SCC(int v){ init(v); }

    void init(int v){
        V = v;
        G.assign(V,vector<int>());
        rG.assign(V,vector<int>());
        vs.clear();
        cmp.resize(V);
    }

    void add_edge(int from,int to){
        G[from].emplace_back(to);
        rG[to].emplace_back(from);
    }

    void dfs(int v){
        used[v] = true;
        for(const int& u : G[v]) if(!used[u]) dfs(u);
        vs.push_back(v);
    }

    // @args k 何番目の成分か?
    void rdfs(int v,int k){
        used[v] = true;
        cmp[v] = k;
        for(const int& u : rG[v]) if(!used[u]) rdfs(u,k);
    }

    // @return 強連結成分分解した後の成分の数
    int scc(){
        used.assign(V,false);
        for(int v=0;v<V;v++) if(!used[v]) dfs(v);
        used.assign(V,false);
        int k=0;
        for(int i=vs.size()-1;i>=0;i--){
            if(!used[vs[i]]) rdfs(vs[i],k++);
        }
        return k;
    }

    bool is_same(int i,int j){ return cmp[i] == cmp[j]; }
};

int n;

int index(int x,int y){
    if(x>y) swap(x,y);
    return x*n+y;
}

int memo[1000000];
int dfs(int cur, vector<vector<int>>& g){
    if(memo[cur] > 0) return memo[cur];

    int ret = 0;
    for(auto v : g[cur]){
        int d = dfs(v,g);
        ret = max(ret, d+1);
    }
    return memo[cur] = ret;
}

int main(){
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n) rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    }

    int m = n*n;
    vector<vector<int>> g(m);
    SCC scc(m);
    rep(i,n){
        rep(j,n-2){
            int from = index(i,a[i][j]);
            int to = index(i,a[i][j+1]);
            g[from].emplace_back(to);
            scc.add_edge(from,to);
        }
    }


    int sz = scc.scc();
    if(sz < m){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    rep(i,n){
        rep(j,i){
            ans = max(ans, dfs(index(i,j),g));
        }
    }
    cout << ans+1 << endl;
}

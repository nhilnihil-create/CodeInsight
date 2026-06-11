#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define vll(a,n) vll a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
using vbool=vector<bool>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
struct edge{
    int to, c;
};

arr<edge> g;
// int col[1005][1005];
set<int> st[100005];

void dfs(int n, int p){
    int ci = 0;
    for(edge& e: g[n]){
        if(e.to==p) continue;
        while(st[n].find(ci)!=st[n].end()) ci++;
        // col[n][e] = col[e][n] = ci;
        e.c = ci;
        st[e.to].insert(ci);
        st[n].insert(ci);
    }

    for(edge e: g[n]){
        if(e.to == p) continue;
        dfs(e.to, n);
    }
}

int main()
{
    int n; cin >> n;

    vint x(n), y(n);
    g.resize(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back({b, 1000000});
        g[b].push_back({a, 1000000});
        x[i] = a;
        y[i] = b;
    }

    // rep(i, n) rep(j, n) col[i][j] = INF;
    
    dfs(0, -1);

    int m = 0;
    rep(i, n) chmax(m, (int)g[i].size());
    pr(m);

    // rep(i, 3){
    //     rep(j, 3) cout << col[i][j] << " ";
    //     pr("");
    // }

    rep(i, n-1){
        bool flg = false;
        for(edge e: g[x[i]]){
            if(e.to == y[i] && e.c!=INF){
                pr(e.c+1);
                flg = true;
                break;
            }
        }
        if(flg) continue;
        for(edge e: g[y[i]]){
            if(e.to == x[i] && e.c!=INF){
                pr(e.c+1);
                flg = true;
                break;
            }
        }
    }

    return 0;}
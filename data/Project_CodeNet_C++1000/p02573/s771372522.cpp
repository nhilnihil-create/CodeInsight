#include <bits/stdc++.h>

using namespace std;

#define rep(x,a,b)         for(int x = a; x < b; x++)
#define per(x,a,b)         for(int x = a; x >= b; x--)
#define all(container)     (container).begin(), container.end()
#define rall(container)    (container).rbegin(), container.rend()
#define sz(container)      (int) (container).size()
#define pb                 push_back
#define eb                 emplace_back
#define fi                 first
#define sc                 second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool smin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool smax(T &a, T b) { return a < b ? (a = b, true) : false; }

#ifdef LOCAL_DEFINE
    #include "DEBUG.hpp"
#else
    #define debug(...) 0
#endif
const int maxn = 200010;
vector<int> e[maxn];
int vis[maxn], cc = 0;
void dfs(int at) {
    vis[at] = 1;
    ++cc;
    for(auto& x : e[at]) {
        if(vis[x]) continue;
        dfs(x);
    }
}
int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(vis,0,sizeof(vis));
    rep(i,0,m) {
        int from, to;
        scanf("%d%d", &from, &to);
        e[from].pb(to);
        e[to].pb(from);
    }
    int ans = 0;
    rep(i,1,n+1) {
        if(vis[i]) continue;
        cc = 0;
        dfs(i);
        smax(ans, cc);
    }
    printf("%d\n", ans);
    return 0;
}
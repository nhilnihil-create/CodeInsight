#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

using graph = vector<vector<ll>>;
vector<ll> x(200000, 0), ans(200000, 0);
vector<bool> seen;
void dfs(const graph &g, int v, int sum = 0){
    seen[v] = true;
    ans[v] = sum + x[v];

    for(auto next : g[v]){
        if(seen[next]) continue;
        dfs(g, next, ans[v]);
    }
}

int main(){
    ll n, q; cin >> n >> q;
    graph g(n+1);
    
    rep(i, n-1){
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, q){
        ll p, xi; cin >> p >> xi;
        x[p] += xi;
    }

    seen.assign(n+1, false);
    dfs(g, 1);

    rep(i, n+1){
        if(i == 0) continue;
        if(i > 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
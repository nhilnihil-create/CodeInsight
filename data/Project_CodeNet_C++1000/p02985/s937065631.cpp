#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

ll n, k;
vector<vector<ll>> g(100010);

ll dfs(ll v, ll p){
    ll ret = 1;
    ll colors = k-2;
    for(ll vi : g[v]){
        if(vi == p)continue;

        ret *= (colors * dfs(vi, v)) % MOD;
        ret %= MOD;

        colors--;
    }

    return ret;
}
int main(){
    cin >> n >> k;

    rep(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ans = k;
    ll colors = k-1;
    for(ll vi : g[0]){
        ans *= (colors * dfs(vi, 0)) % MOD;
        ans %= MOD;

        colors--;
    }

    cout << ans << endl;
}
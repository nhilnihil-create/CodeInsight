#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

vector<ll> E[100005];
ll ans[100005];
ll n,k;

void dfs(ll v, ll g, ll cnt) {
    if (g == 0) ans[g] = k;
    else if (v == 0) ans[g] = max(0ll, k-cnt-1);
    else ans[g] = max(0ll, k-cnt-2);
    int t = 0;
    for (ll x : E[g]) {
        if (x != v) {
            dfs(g, x, t);
            t++;
        }
    }
}

int main() {
    cin >> n >> k;
    ll u,v;
    rep(i,n-1) {
        cin >> u >> v;
        E[u-1].push_back(v-1);
        E[v-1].push_back(u-1);
    }
    dfs(-1,0,0);
    ll anss = 1;
    //rep(i,n) cout << ans[i] << endl;
    rep(i,n) {
        anss = anss * ans[i] % mod;
    }
    cout << anss << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx = 1e7 + 9;
ll par[mx];
ll p_u, p_v;

ll find_parent(ll x) {
    if(x == par[x]) return x;

    return par[x] = find_parent(par[x]);
}

void join(ll v, ll u) {
    p_u = find_parent(u);
    p_v = find_parent(v);

    if(p_v == p_u) return;
    par[p_u] = p_v;
}


int main() {
    ll n, m;  cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        par[i] = i;
    }


    while(m--) {
        ll u, v; cin >> u >> v;
        join(u, v);
    }

    map<ll, ll>mm;

    for(ll i = 1; i <= n; i++) {
        ll k = find_parent(i);
        mm[k]++;
    }
    ll ans = 0;
    for(auto i : mm) {
        ans = max(ans, i.second);
    }
    cout << ans << endl;
    return 0;

}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e7 + 7;

ll par[mx];
ll p_u, p_v;

ll find_parent(ll x) {
    if(x == par[x]) return x;

   return par[x] = find_parent(par[x]);
}



void join(ll u, ll v) {

    p_u = find_parent(u);
    p_v = find_parent(v);

   if(p_u == p_v) return;

   par[p_u] = p_v;
}

int main() {
    ll n, q;  cin >> n >> q;
    for(ll i = 0; i < n; i++) par[i] = i;

    while(q--) {
        ll t; cin >> t;
        if(t == 1) {
            ll u, v;  cin >> u >> v;
             p_u = find_parent(u);
             p_v = find_parent(v);
            if(p_u == p_v) cout << 1 << endl;
            else cout << 0 << endl;
        }

        else if( t == 0) {
            ll u, v;  cin >> u >> v;
            join(u, v);
        }
    }

    return 0;
}

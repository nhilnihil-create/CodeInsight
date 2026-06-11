#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define int ll
#define pll pair<ll, ll> 
#define pdd pair<ld, ld> 
#define pb push_back
#define reset(x,v) memset(x,v,sizeof(x))
#define mod 1000000007
using namespace std;

void dfs(vector<int> adj[], int sv, vector<bool> &vis){
	vis[sv] = true;
	for(int i = 0; i < adj[sv].size(); i++){
		if(!vis[adj[sv][i]]){
			dfs(adj, adj[sv][i], vis);
		}
	}
}
ll power(ll x, ll y){  
	if(x == 1 || y == 0)
		return 1;
    ll res = 1;   
    x = x % mod; 
    if (x == 0) 
		return 0;  
    while (y > 0){  
        if (y & 1)  
            res = (res * x) % mod;  
        y = y >> 1; 
        x = (x * x) % mod;  
    }  
    return res;  
}  
ll nCr(ll n, ll r) {
    ll x = 1, y = 1;
    rep(i, 0, r) {
        x = x * (n - i) % mod;
        y = y * (i + 1) % mod;
    }
    return x * power(y, mod - 2) % mod;
}

signed main(){
	FASTIO
	ll x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	ll p[a], q[b], r[c];
	rep(i, 0, a)
		cin >> p[i];
	rep(i, 0, b)
		cin >> q[i];
	rep(i, 0, c)
		cin >> r[i];
	vector<ll> v;
	ll ans = 0;
	sort(p, p + a, greater<ll>());
	sort(q, q + b, greater<ll>());
	sort(r, r + c, greater<ll>());
	rep(i, 0, x)
		v.pb(p[i]);
	rep(i, 0, y)
		v.pb(q[i]);
	rep(i, 0, c)
		v.pb(r[i]);
	sort(v.begin(), v.end(), greater<ll>());
	rep(i, 0, x + y)
		ans += v[i];
	cout << ans;
    return 0;
}
/*
1 2 2 2 1
2 4
5 1
1000
*/
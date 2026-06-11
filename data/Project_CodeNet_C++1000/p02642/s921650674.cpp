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
//#define int ll
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
	int n;
	cin >> n;
	int a[n];
	unordered_map<int, vi> mp;
	rep(i, 0, n){
		cin >> a[i];
		mp[a[i]].pb(i);
	}
	
	int ans = 0, mx = *max_element(a, a + n);
	vector<bool> mark(n, true);
	rep(i, 0, n){
//		if(mark[i]){
			for(int j = a[i]; j <= mx; j += a[i]){
				if(mp.count(j) > 0){
					vi v = mp[j];
					vi t;
					rep(k, 0, v.size()){
						if(v[k] != i)
							mark[v[k]] = false;
						else
							t.pb(v[k]);	
					}
					mp[j] = t;
				}
			}
//		}
	}
	rep(i, 0, n){
		if(mark[i])
			ans++;
	}
	cout << ans;
    return 0;
}

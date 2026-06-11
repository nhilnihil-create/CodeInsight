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
int n, m, q, ans;
int a[50], b[50], c[50], d[50];
int v[11];
void solve(int st, int prev){
	if(st == n){
		int temp = 0;
		rep(i, 0, q){
			if(v[b[i]] - v[a[i]] == c[i])
				temp += d[i];
		}
		ans = max(ans, temp);
		return;
	}
	rep(i, prev, m + 1){
		v[st+1] = i;
		solve(st + 1, i);
	}
	
}

signed main(){
	FASTIO
	cin >> n >> m >> q;
	rep(i, 0, q){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	solve(0, 1);
	cout << ans;
    return 0;
}

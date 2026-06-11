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
#define pll pair<ll, ll> 
#define pdd pair<ld, ld> 
#define pb push_back
#define reset(x,v) memset(x,v,sizeof(x))
#define mod 998244353
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


int main(){
	FASTIO
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> ans(n, 0);
	rep(i, 1, n + 1){
		rep(j, i + 1, n + 1){
			int d = min(j - i, abs(x - i) + 1 + abs(y - j));
			ans[d]++;
		}
	}
	rep(i, 1, n)
		cout << ans[i] << endl;
    return 0;
}

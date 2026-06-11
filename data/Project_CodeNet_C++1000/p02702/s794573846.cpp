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
	string s;
	cin >> s;
	int n = s.size();
	vi p(2019, 0);
	int curr = 0, f = 1;
	for(int i = n - 1; i >= 0; i--){
		curr = (curr + f * (s[i] - '0')) % 2019;
		p[curr]++;
		f = (f * 10) % 2019;
	}
	ll ans = p[0];
	rep(i, 0, 2019){
		ans += p[i] * (ll)(p[i] - 1) / 2;
	}
	cout << ans;
    return 0;
}

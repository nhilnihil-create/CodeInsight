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

signed main(){
	FASTIO
	int n, k;
	cin >> n >> k;
	int p[n+1], c[n+1];
	rep(i, 1, n+1)
		cin >> p[i];
	rep(i, 1, n+1)
		cin >> c[i];
	vector<bool> vis(n+1, false);
	int sol = *max_element(c + 1, c + n + 1);
	rep(i, 1, n + 1){
		int ans = c[i];
		rep(i, 1, n + 1)
			vis[i] = false;
		int temp = 0, sum = 0;
		int u = i, y = k, l = 0;
		while(!vis[u] && y > 0){
			vis[u] = true;
			u = p[u];
			sum += c[u];
			l++;
		}
		if(y / l > 1 && sum > 0){
			temp = temp + sum * ((y / l) - 1);
			ans = max(ans, temp);
		}
		if(y / l > 0){
			rep(i, 1, n + 1)
				vis[i] = false;
			u = i;
			while(!vis[u]){
				vis[u] = true;
				u = p[u];
				temp = temp + c[u];
				ans = max(ans, temp);
			}	
		}
		rep(i, 1, n + 1)
			vis[i] = false;
		y = y % l;
		u = i;
		if(temp < 0) temp = 0;
		while(!vis[u] && y > 0){
			vis[u] = true;
			u = p[u];
			y--;
			temp = temp + c[u];
			ans = max(ans, temp);
		}
		sol = max(sol, ans);
	}
	cout << sol;
    return 0;
}
 
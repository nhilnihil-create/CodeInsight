#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define ubo upper_bound
#define lbo lower_bound
#define VI vector<int>
#define VL vector<ll>
#define VP vector<pll >
#define all(x) x.begin(), x.end()
#define M vector<VI >

const int N = 202020;

using namespace std;

ll n, ans;
VI g[N];

int main(){

	cin >> n;
	for(int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		if(u>v) swap(u, v);
		g[u].pb(v);
	}

	for(ll x=1; x<=n; x++){
		ans += (n-x+1LL)*x;
	}

	for(ll i=1; i<=n; i++){
		for(ll j : g[i]){
			ans -= i*(n-j+1LL);
		}
	}

	cout << ans << endl;

	return 0;
}

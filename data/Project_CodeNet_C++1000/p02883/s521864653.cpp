#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	for(auto &x:a)
		cin >> x;
	for(auto &x:f)
		cin >> x;

	ll l = -1, r = 1e18+100;
	sort(all(a));
	sort(all(f), greater<ll>());
	while(r-l>1){
		ll res = l + (r-l)/2LL;
		ll cost = 0;
		for(ll i=0; i<n; ++i){ 
			ll x = res/f[i];
			if(a[i]<x) continue;
			cost += a[i]-x;
		}
		if(cost<=k) r = res;
		else l = res;
	}
	cout << r << endl;
}

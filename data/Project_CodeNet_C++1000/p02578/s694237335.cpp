#include "bits/stdc++.h"
using namespace std;

using ll = long long;

signed main(){
	ll n;
	cin >> n;

	vector<ll>v(n);
	for(ll i=0;i<n;i++){
		cin >> v[i];
	}

	vector<ll>a(n);
	a[0] = v[0];

	for(ll i=1;i<n;i++){
		a[i] = max(v[i],a[i-1]);
	}

	ll sum = 0;
	for(ll i=0;i<n;i++){
		sum = sum + abs(a[i]-v[i]);
	}
	
	cout << sum << "\n";

	return 0;
}
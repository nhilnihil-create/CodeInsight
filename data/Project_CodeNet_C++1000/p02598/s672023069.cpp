#include <bits/stdc++.h>
#include <iostream>

#define ll long long
using namespace std;

bool valid(vector<ll>& arr, ll m, ll k) {
	ll cnt = 0;
	for (int i=0; i<arr.size(); i++) {
		if (arr[i] <= m) continue;
		if (arr[i] % m == 0) cnt += (arr[i] / m - 1);
		else cnt += arr[i] / m;		
	}
	return cnt <= k;	
}

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i];
	ll l = 1LL, r = (ll)INT_MAX;
	while (l < r) {
		ll m = (l+r)/2LL;
		if (valid(arr, m, k)) {
			r = m;
		}
		else {
			l = m+1;
		}
	}
	cout << l;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	for(ll& x : arr) {
		cin >> x;
		sum ^= x;
	}

	// consider each bit in the sum:
	// 	if bit k is set, we get it for free
	// 	if bit k is not set, 
	// 		divide into 2 sets greedily, such that both
	// 		have bit k set
	//
	// 	remove set bits in sum from each num,
	// 	maximize A + B, ans = sum + (A + B)
	// 	but A == B, maximize A
	
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = arr[i] - (sum & arr[i]);
	}

	//sort(a.rbegin(), a.rend());
	int i = 0;
	for(int b = 59; b >= 0; b--) {
		int x = i;
		while(x < n && (a[x] >> b & 1) == 0) {
			x++;
		}
		if(x == n) continue;
		swap(a[i], a[x]);
		for(int j = 0; j < n; j++) {
			if(j == i) continue;
			if(a[j] >> b & 1) {
				a[j] ^= a[i];
			}
		}
		i++;
	}
	ll mx = 0;
	for(int i = 0; i < n; i++) {
		mx = max(mx, mx ^ a[i]);
	}
	sum += 2*mx;
	cout << sum << endl;
}

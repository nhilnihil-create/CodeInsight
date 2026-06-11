#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n, h[100100], a[100100];
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << "Yes";
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		cin >> h[i];			
	}
	for(int i = 1; i < n; ++i) {
		if (h[i]-1 >= h[i-1]) h[i] = h[i]-1; 
	}
	for(int i = 0; i < n-1; ++i) {
		if (h[i] > h[i+1]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}

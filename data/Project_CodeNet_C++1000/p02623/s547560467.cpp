#include <bits/stdc++.h>
#include <iostream>

#define ll long long
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr1(n),  arr2(m);
	for (int i=0; i<n; i++) cin >> arr1[i];
	for (int i=0; i<m; i++) cin >> arr2[i];
	vector<ll> pre1(n+1), pre2(m+1);
	for (int i=0; i<n; i++) pre1[i+1] = pre1[i]+arr1[i];
	for (int i=0; i<m; i++) pre2[i+1] = pre2[i]+arr2[i];
	int mx = 0;
	for (int i=0; i<= n; i++) {
		if (pre1[i] > k) break;
		int t = k - pre1[i];
		if (t >= pre2[m]) mx = max(mx, i+m);
		else {
			int l=0, r=m;
			while (l<r) {
				int m = (l+r)/2;
				if (pre2[m] <= t) {
					l = m+1;
				}
				else {
					r = m;
				}
			}
			mx = max(mx, i+l-1);
		}
	}
	cout << mx;
}

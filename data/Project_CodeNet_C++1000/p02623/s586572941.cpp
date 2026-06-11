#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll i, j;
	ll s = 0;
	ll res;
	vector<ll> a(n+1);
	vector<ll> b(m+1);
	a[0] = 0; b[0] = 0;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (i = 1; i <= m; i++) {
		cin >> b[i];
		b[i] += b[i - 1];
	}
	for (i = 1; i <= n; i++) {
		if (a[i] > k) {
			break;
		}
	}
	i--;
	res = i;
	for (j = i ; j >= 0; j--) {
		if (s >= m)break;
		while (a[j] + b[s] < k) {
			if (j + s > res)res = j + s;
			s++;
			if (s >= m)break;
		}
		if (j + s > res && a[j] + b[s] <= k)res = j + s;
		
	}
	cout << res;
	return 0;
}
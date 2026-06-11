#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> f(n);
	for (ll i = 0; i < n; ++i)cin >> a[i];
	for (ll i = 0; i < n; ++i)cin >> f[i];
	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());
	ll Min = -1;
	ll Max = 1e15;
	while (Max - Min > 1) {
		ll Mid = (Min + Max) / 2;
		ll cnt = 0;
		for (ll i = 0; i < n; ++i) {
			cnt += max(0ll, a[i] - Mid / f[i]);
		}
		if (cnt > k)Min = Mid;
		else Max = Mid;
	}
	cout << Max << endl;
}

#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int k;
vector<int> d;

ll solve(ll n, ll x, ll m) {
	// dm[i] := d[i] mod m
	vector<ll> dm(k);
	for (int i = 0; i < k; ++i)
		dm[i] = d[i] % m;
	// a[n-1]を計算する
	// dm[i % k] = 0となるiの個数をカウントする
	ll a_lst = x;
	ll cnt = 0;
	for (int i = 0; i < k; ++i) {
		ll tmp = (n - 1) / k;
		if ((n - 1) % k > i) ++tmp;
		a_lst += dm[i] * tmp;
		if (dm[i] == 0)
			cnt += tmp;
	}
	// 答えを計算する
	return (n - 1) - (a_lst / m - x / m + cnt);
}

int main() {
	int q;
	cin >> k >> q;
	d.resize(k);
	for (int i = 0; i < k; ++i)
		cin >> d[i];
	while (q--) {
		ll n, x, m;
		cin >> n >> x >> m;
		cout << solve(n, x, m) << endl;
	}
	return 0;
}
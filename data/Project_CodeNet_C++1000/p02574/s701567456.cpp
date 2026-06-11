#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i)
		cin >> a[i];
	vector<ll> primes = { 2, 3, 5, 7, 11, 13 };
	for (ll i = 17; i < 100000; i += 2) {
		bool ok = true;
		for (ll j = 0; primes[j] * primes[j] <= i; ++j) {
			if (i % primes[j] == 0) {
				ok = false;
				break;
			}
		}
		if (ok)
			primes.emplace_back(i);
	}
	
	map<ll, ll> cnt;
	for (ll i : a) {
		ll t = i;
		for (ll j = 0; primes[j] * primes[j] <= t; ++j) {
			if (t % primes[j] == 0) cnt[primes[j]]++;
			while (t % primes[j] == 0) t /= primes[j];
		}
		if (t != 1) cnt[t]++;
	}
	
	ll hi = 0;
	for (auto p : cnt) hi = max(hi, p.second);
	if (hi <= 1) {
		printf("pairwise coprime");
		return 0;
	}
	
	printf(hi < n ? "setwise coprime" : "not coprime");
	
	return 0;
}
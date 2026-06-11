#include <bits/stdc++.h>
#include <iostream>

#define ll long long
using namespace std;

int main() {
	ll x; cin >> x;
	unordered_map<ll, ll> map;
	ll i = 0LL;
	ll n, n5;
	while (true) {
		n = i;
		n5 = n*n*n*n*n;
		if (map.find(n5-x) != map.end()) {
			cout << n << " " << map[n5-x];
			return 0;
		}
		if (map.find(n5+x) != map.end()) {
			cout << map[n5-x] << " " << n;
			return 0;
		} 
		map[n5] = n;
		n = -i;
		n5 = n*n*n*n*n;
		if (map.find(n5-x) != map.end()) {
			cout << n << " " << map[n5-x];
			return 0;
		}
		if (map.find(n5+x) != map.end()) {
			cout << map[n5-x] << " " << n;
			return 0;
		}
		map[n5] = n;
		i += 1LL;
	}
}

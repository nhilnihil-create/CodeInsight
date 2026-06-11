#include"bits/stdc++.h"
//#include"atcoder.h"
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = ll(1e18) + 1;
const ll mod = 1000000007;

int main() {
	ll n;
	cin >> n;

	vector<ll> z(n + 5);
	vector<ll> w(n + 5);

	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		z[i] = x + y;
		w[i] = x - y;
	}

	ll result = 0;
	ll z_max = z[0];
	ll z_min = z[0];
	ll w_max = w[0];
	ll w_min = w[0];

	for (int i = 1; i < n; i++) {
		if (z[i] >= z_max) {
			z_max = z[i];
		}
		else if (z[i] <= z_min) {
			z_min = z[i];
		}

		if (w[i] >= w_max) {
			w_max = w[i];
		}
		else if (w[i] <= w_min) {
			w_min = w[i];
		}
	}

	result = max(z_max-z_min, w_max - w_min);

	cout << result << endl;

	return 0;
}

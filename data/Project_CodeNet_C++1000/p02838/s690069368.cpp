#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<vector<ll>> bit(n,vector<ll> (61));
	for (int j = n - 1; j >= 0; --j) {
		for (int i = 0; i <= 60; ++i) {
			if (j == n - 1) {
				if ((v[j] >> i) & 1) {
					bit[j][i] = 1;
				}
			}else {
				bit[j][i] = bit[j + 1][i];
				if ((v[j] >> i) & 1) {
					bit[j][i]++;
				}
			}
		}
	}
	//for (int i = 0; i < n; ++i) {
		//for (int j = 60; j >= 0; --j) {
			//cout << bit[i][j] << " ";
		//}
		//cout << endl;
	//}
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < 61; ++j) {
			if ((v[i] >> j) & 1) {
				ans += (((ll)pow(2,j) % mod) * ((n - i - 1) - bit[i + 1][j]) % mod) % mod;
			}else {
				ans += (((ll)pow(2,j) % mod) * (bit[i + 1][j] % mod)) % mod;
			} 
		}
		ans %= mod;
	}
	cout << ans;
}

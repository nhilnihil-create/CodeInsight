#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int MaxN = 1e6 + 10;
int poww(int a, int b) {
	if(a == 0) return 0;
	if(b == 0) return 1;
	if(b % 2 == 0) {
		return (poww(a, b / 2) * poww(a, b / 2)) % mod;
	}
	else {
		return (((poww(a, b / 2) * poww(a, b / 2)) % mod) * a) % mod;
	}
}
signed main() {
	int n;
	cin >> n;
	cout << (((poww(10, n) - 2 * poww(9, n) + poww(8, n)) % mod) + mod) % mod;
	return 0;
}
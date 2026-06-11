#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

#define MOD 1000000007

int f(ll n, ll k) {
	ll low = (k * (k - 1)) / 2;
	low %= MOD;
	ll up = (n * (n + 1) - (n - k) * (n - k + 1)) / 2;
	up %= MOD;
	int ret = (up - low  + 1 + MOD) % MOD;
	return ret;

}

int main() {
	int n, k;
	cin >> n >> k;
	int ret = 0;
	for (int i = k; i <= n + 1; i++) {
		ret += f(n, i);
		ret %= MOD;
	}
	cout << ret << endl;
	return 0;
}

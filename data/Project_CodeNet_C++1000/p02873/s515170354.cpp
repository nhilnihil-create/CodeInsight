#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 998244353
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

string s;
int d[500010], d2[500010];
int ans;

signed main() {
	cin >> s;
	int n = (int)s.size();
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '<')d[i + 1] = d[i] + 1;
		else d[i + 1] = 0;
	}
	d2[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '>')d2[i] = d2[i + 1] + 1;
		else d2[i] = 0;
	}
	for (int i = 0; i <= n; i++)ans += max(d[i], d2[i]);
	cout << ans << endl;
}
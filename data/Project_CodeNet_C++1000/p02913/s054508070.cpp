#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919810364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
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

typedef unsigned long long ull;
const ull B = 1000000007;

int n;
string s;

bool contain(string a, string b) {
	int al = (int)a.size(), bl = (int)b.size();
	ull t = 1;
	for (int i = 0; i < al; i++)t *= B;
	ull ah = 0, bh = 0;
	for (int i = 0; i < al; i++) {
		ah = ah * B + a[i];
		bh = bh * B + b[i];
	}
	for (int i = 0; i + al <= bl; i++) {
		if (ah == bh)return true;
		if (i + al < bl)bh = bh * B + b[i + al] - b[i] * t;
	}
	return false;
}

signed main() {
	cin >> n >> s;
	int mi = 0, ma = n / 2 + 1;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		bool bl = false;
		for (int i = 0; i + 2 * md <= n; i++) {
			if (contain(s.substr(i, md), s.substr(i + md, n - i - md))) {
				bl = true;
				break;
			}
		}
		if (bl)mi = md;
		else ma = md;
	}
	cout << mi << endl;
}
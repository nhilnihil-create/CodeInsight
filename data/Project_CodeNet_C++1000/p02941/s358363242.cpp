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
int kai(int x, int y, int m) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
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

int comb(int x, int y, int m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n, a[200010], b[200010];
queue<int> que;
int ans;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	for (int i = 0; i < n; i++) {
		if (b[(i - 1 + n) % n] + b[(i + 1) % n] <= b[i])que.push(i);
	}
	while (!que.empty()) {
		int p = que.front(); que.pop();
		int x = b[(p - 1 + n) % n] + b[(p + 1) % n];
		int s = b[p] % x;
		if (s < a[p]) {
			if ((b[p] - a[p]) % x) {
				cout << -1 << endl;
				return 0;
			}
			ans += (b[p] - a[p]) / x;
			b[p] = a[p];
		}
		else {
			ans += b[p] / x;
			b[p] = s;
		}
		if (b[(p - 2 + n) % n] + b[p] <= b[(p - 1 + n) % n])que.push((p - 1 + n) % n);
		if (b[p] + b[(p + 2) % n] <= b[(p + 1) % n])que.push((p + 1) % n);
	}
	for (int i = 0; i < n; i++)if (a[i] != b[i]) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
}
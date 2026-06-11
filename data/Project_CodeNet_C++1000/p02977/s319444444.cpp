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

int n;
vector<int> vec;

signed main() {
	cin >> n;
	if (n <= (n ^ (n - 1))) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	vec.push_back(0);
	for (int i = 4;; i *= 2) {
		if (n < i - 1)break;
		vec.push_back(i - 1);
	}
	for (int i = 1; i < (int)vec.size(); i++) {
		if (1 < i)cout << vec[i - 1] + n << " " << vec[i - 1] + 1 << endl;
		for (int j = vec[i - 1] + 2; j <= vec[i]; j++)cout << j - 1 << " " << j << endl;
		cout << vec[i] << " " << vec[i - 1] + n + 1 << endl;
		for (int j = vec[i - 1] + 2 + n; j <= vec[i] + n; j++)cout << j - 1 << " " << j << endl;
	}
	if (vec.back() == n)return 0;
	int p = vec.back();
	cout << p + 1 << " " << 1 << endl;
	cout << p + 2 + n << " " << p + 1 << endl;
	cout << p + 2 << " " << 1 << endl;
	cout << p + 2 << " " << p + 1 + n << endl;
	int k = p + 3;
	int s = 0;
	for (int i = 1; i < (int)vec.size(); i++) {
		for (int j = vec[i - 1] + 1; j <= vec[i]; j++) {
			if (n < k)return 0;
			s ^= j;
			if (j % 2)continue;
			if (s % 2) {
				cout << p + 2 << " " << k << endl;
				cout << j << " " << k + n << endl;
				k++;
				if (n < k)return 0;
				cout << p + 1 << " " << k << endl;
				cout << j << " " << k + n << endl;
				k++;
			}
			else {
				cout << p + 1 << " " << k << endl;
				cout << j << " " << k + n << endl;
				k++;
				if (n < k)return 0;
				cout << p + 2 << " " << k << endl;
				cout << j << " " << k + n << endl;
				k++;
			}
		}
	}
}
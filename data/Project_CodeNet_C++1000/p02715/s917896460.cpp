#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
#include <fstream>
#include<map>
#include <cassert>
#include<sstream>
#include<fstream>
#include <cstring>
using namespace std;
typedef pair<int, string>p;
map< int64_t, int > prime_factor(int64_t n) {
	map< int64_t, int > ret;
	for (int64_t i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
long long mod = 1e9 + 7;
vector< int64_t > divisor(int64_t n) {
	vector< int64_t > ret;
	for (int64_t i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}
long long pow(long long x, long long kata) {
	if (kata == 0)return 1;
	if (kata == 1)return x;
	if (kata % 2 == 0) {
		return pow(x, kata / 2)*pow(x, kata / 2) % mod;
	}
	else {
		return pow(x, kata - 1)*x%mod;
	}
}
const int MAX = 101010;
bool is_prime[MAX];
int min_factor[MAX];
int meb[MAX];
vector<int> preprocess(int n = MAX) {
	vector<int> res;
	for (int i = 0; i < n; ++i) is_prime[i] = true, min_factor[i] = -1, meb[i] = 1;
	is_prime[0] = false; is_prime[1] = false;
	min_factor[0] = 0, min_factor[1] = 1;
	meb[0] = 0; meb[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_prime[i]) continue;
		res.push_back(i);
		min_factor[i] = i;
		meb[i] = -1;
		for (int j = i * 2; j < n; j += i) {
			is_prime[j] = false;
			meb[j] *= -1;
			if (min_factor[j] == -1) min_factor[j] = i;
			if ((j / i) % i == 0) meb[j] = 0;
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long n, k;
	cin >> n >> k;
	preprocess();
	long long ans = 0;
	for (long long i = 1; i <= k; i++) {
		long long tmp = 0;
		for (long long j = i; j <= k; j += i) {
			tmp += pow(k / j, n)*meb[j/i];
			tmp += mod;
			tmp %= mod;
		}
		ans += tmp*i;
		ans %= mod;
	}
	cout << ans;
}


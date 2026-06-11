#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int power(int x, int y) { //x^y
	long long p = 1;
	for (long long b = x; y > 0; y >>= 1, b = b * b % mod) {
		if (y & 1)
			p = p * b % mod;
	}
	return p;
}

int main() {
	string l;
	cin >> l;
	int n = l.size();
	int leftPopBit = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (l[i] == '1') {
			sum += (long long) power(2, leftPopBit) * power(3, n - i - 1) % mod;
			sum %= mod;
			leftPopBit++;
		}
	}
	sum += power(2, leftPopBit);
	sum %= mod;
	cout << sum << endl;
}

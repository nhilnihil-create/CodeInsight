#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

bool isprime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	while (cin >> n && n) {
		int sum = 0;
		rep(i, n) {
			int x = n + i + 1;
			sum += isprime(x);
		}
		cout << sum << endl;
	}
}
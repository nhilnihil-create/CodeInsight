#include <iostream>
using namespace std;

constexpr long long int mod = 1e9 + 7;

long int solve(long long int x, long long int n) {
	long int num = 1;
	
	for (long int i = 0; i < n; i++) {
		num = num * x % mod;
	}
	return num;
}

int main() {
	long long int n;
	cin >> n;

	long long int ans = solve(10, n) - solve(9, n) - solve(9, n) + solve(8, n);
	ans %= mod;
	ans = (ans + mod) % mod;

	cout << ans << endl;
}

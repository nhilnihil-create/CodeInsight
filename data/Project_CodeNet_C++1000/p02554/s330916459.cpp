#include <iostream>

using namespace std;

int N;
long long int MOD = 1000000007;

int main(void) {

	cin >> N;

	long long int num1 = 1;
	for (int i = 1; i <= N; i++) {
		num1 *= 10;
		num1 %= MOD;
	}

	long long int num2 = 1;
	for (int i = 1; i <= N; i++) {
		num2 *= 9;
		num2 %= MOD;
	}

	long long int num3 = 1;
	for (int i = 1; i <= N; i++) {
		num3 *= 8;
		num3 %= MOD;
	}

	long long int ans = 0;

	ans = (num1 - num2 * 2 + num3 + MOD * 3) % MOD;

	cout << ans << endl;

	return 0;
}
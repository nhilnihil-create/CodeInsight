#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

int main(){
	long long N, K;
	cin >> N >> K;

	long long ans = 0;
	for (long long k = K; k <= N + 1; k++){
		long long temp = (2 * N - k + 1) * k / 2 - k * (k - 1) / 2;
		// cerr << k << " " << temp << endl;
		ans += temp + 1;
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}

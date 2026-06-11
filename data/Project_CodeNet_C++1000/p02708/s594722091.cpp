#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

long long mod = 1000000007;

int main() {
	long long N, K, sum = 0; cin >> N >> K;
	for (int i = K; i <= N + 1; i++) {
		long long cl = 1LL * i * (i - 1) / 2LL;
		long long cr = cl + 1LL * i * (N + 1LL - i);
		sum += (cr - cl + 1) % mod;
		sum %= mod;
	}
	cout << sum << endl;
	return 0;
}
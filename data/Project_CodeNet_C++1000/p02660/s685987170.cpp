#include <bits/stdc++.h>
using namespace std;

bool prime[1000005];


int dp[100][100];


int f(int a, int b) {
	if (a == 0) {
		return 0;
	}
	if (b > a) 
		return 0;
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = max(f(a,b+1), f(a-b, b+1)+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int64_t N;
	cin >> N;

	fill(prime, prime+1000005, 1);
	prime[0] = prime[1] = 0;

	for (int64_t p = 2; p <= 1000000; ++p) if (prime[p]) {
		for (int64_t m = p*p; m <= 1000000; m += p) {
			prime[m] = 0;
		}
	}

	memset(dp, -1, sizeof dp);

	map<int, int> facts;

	int64_t num = N;

	for (int64_t p = 2; p*p <= N; ++p) if (prime[p]) {
		// cout << num << " " << p << endl;
		while (num%p == 0) {
			num /= p;
			facts[p]++;
		}
		// if (num <= 1000000 && prime[num]) {
		// 	facts[num]++;
		// 	break;
		// }
	}

	if (num > 1) {
		facts[num]++;
	}

	// cout << "here" << endl;

	int64_t ans = 0;

	for (auto kv : facts) {
		// cout << kv.first << " " << kv.second << " " << f(kv.second, 1) << endl;
		ans += f(kv.second, 1);
	}

	cout << ans << endl;

}
#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;
const long long MOD = 1000000000 + 7;

long long modPow(int n, int num) {
	if (num == 0) return 1;
	long long res = modPow(n, num / 2);
	if (num % 2 == 0) res = (res * res) % MOD;
	else res = (((res * res) % MOD) * n) % MOD;
	return res;
}

void modNck(int n, int k, vector<long long> & nums) {
	long long res = 1;
	nums.push_back(res);
	for (int i = 0; i < k; i++) {
		res = (res * ((long long)n - i) % MOD * modPow(i + 1, MOD - 2)) % MOD;
		nums.push_back(res);
	}
}

int main() {
	int N, K; cin >> N >> K;
	vector<long long> nums;
	vector<long long> nums2;
	modNck(N - K + 1, K, nums);
	modNck(K - 1, K - 1, nums2);
	rep(i, K) {
		if (i == 0)cout << nums[i + 1] << endl;
		else cout << (nums[i + 1] * nums2[i]) % MOD << endl;
	}
}
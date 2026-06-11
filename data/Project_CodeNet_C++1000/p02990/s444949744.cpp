#include <bits/stdc++.h>
using namespace std;

#define MODNUMBER 1000000007

long long pow_mod(long long a, long long n) {  // a^n mod MODNUMBER
	long long result = 1;
	long long a_i = a;
	long long n_tmp = n;
	while (n_tmp > 0) {
		if (n_tmp & 0b1) {
			result = (result * a_i) % MODNUMBER;
			// cout << result << "\n";
		}
		a_i = a_i * a_i % MODNUMBER;
		n_tmp = n_tmp >> 1;
	}
	return result;
}

long long fact_mod(long long k) {  // k! mod MODNUMBER

	long long result = 1;
	for (int i = 1; i <= k; i++) {
		result = (result * i) % MODNUMBER;
	}
	return result;
}

long long inv_mod(long long k) {  // k^(-1) mod MODNUMBER

	return pow_mod(k, MODNUMBER - 2);
}

/* TODO: fact_mod()の途中経過を使いまわす実装にすれば早くなるらしい */
long long comb_mod(long long n, long long k) {  // nCk mod MODNUMBER

	if (k < 0 || k > n) {
		return 0;
	}
	return (fact_mod(n) *
	        inv_mod((fact_mod(k) * fact_mod(n - k)) % MODNUMBER)) %
	       MODNUMBER;
}

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	long long N, K;
	scanf("%lld %lld", &N, &K);
	// N-K-1Ci + N-K-1Ci-1 *2 +N-K-1Ci-2

	for (int i = 1; i <= K; i++) {
		cout << comb_mod(N - K + 1, i) * comb_mod(K - 1, i - 1) % MODNUMBER
		     << "\n";
	}

	return 0;
}
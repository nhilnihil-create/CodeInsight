#include <bits/stdc++.h>

using namespace std;

int MAX = 123456 * 2 + 1;
int N;
int cnt[123456 * 2 + 1];

void countPrime() {
	memset(cnt, 0, sizeof(cnt));
	vector<bool> isPrime(MAX, true);
	
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			cnt[i] = cnt[i - 1] + 1;
			for (int j = 2 * i; j <= MAX; j += i) isPrime[j] = false;
		} else {
			cnt[i] = cnt[i - 1];
		}
	}
}


int main() {
	countPrime();
	
	while (1) {
		cin >> N; if (N == 0) break;
		cout << cnt[2 * N] - cnt[N] << endl;
	}
	
	return 0;
}
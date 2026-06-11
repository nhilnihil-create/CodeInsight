#include <bits/stdc++.h>
using namespace std;

long long ipow(long long b, long long e) {
	if (e == 0) {
		return 1;
	} else if (e % 2 == 0) {
		return ipow(b * b, e / 2);
	} else {
		return ipow(b * b, e / 2) * b;
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1;; i++) {
		if (ipow(K, i - 1) <= N && N < ipow(K, i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}

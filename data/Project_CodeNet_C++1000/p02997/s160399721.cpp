#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if (K > (N - 1)*(N - 2)/2) {
		cout <<  -1 <<endl;
		return 0;
	}
	int tmp = (N - 1)*(N - 2) / 2 - K;
	cout <<tmp + N-1 << endl;
	for (int n = 2; n <= N; ++n) {
		cout << 1 << " " << n << endl;
	}
	for (int n = 2;n<=N;++n) {
		for (int m = n + 1;m<=N;++m) {
			if (0 == tmp) {
				return 0;
			}
			tmp--;
			cout << n << " "<<m <<  endl;

		}
	}
	return 0;
}
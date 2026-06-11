#include <bits/stdc++.h>
using namespace std;
int main() {
	//input
	int64_t N;
	string S;
	cin >> N >> S;

	//calculation
	int64_t r = 0;
	int64_t g = 0;
	int64_t b = 0;
	for (int64_t i = 0; i < N; i++) {
		if (S[i] == 'R') {
			r++;
		} else if (S[i] == 'G') {
			g++;
		} else {
			b++;
		}
	}

	int64_t output = r * g * b;
	for (int64_t i = 0; i < N - 2; i++) {
		for (int64_t j = i + 1; j < N - 1; j++) {
			int64_t k = 2 * j - i;
			if (k >= N) {
				continue;
			}
			if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
				output--;
			}
		}
	}


	//output
	cout << output << endl;


	return 0;
}

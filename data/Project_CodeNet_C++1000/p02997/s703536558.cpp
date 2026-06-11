#include <iostream>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	if (K > (N - 1) * (N - 2) / 2) {
		cout << -1 << endl;
	}
	else {
		int u = N * (N - 1) / 2 - K;
		cout << u << endl;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (u > 0) {
					cout << i + 1 << ' ' << j + 1 << endl;
					--u;
				}
			}
		}
	}
	return 0;
}
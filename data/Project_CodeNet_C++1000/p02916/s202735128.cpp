#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N + 1, -100), B(N + 1,-100), C(N,-100);
	for (int n = 1; n <= N; n++) {
		cin >> A[n];
	}
	for (int n = 1; n <= N; n++) {
		cin >> B[n];
	}
	for (int n = 1; n < N; n++) {
		cin >> C[n];
	}
	int res = 0;
	for (int n = 1; n <= N; n++) {
		res += B[A[n]];
		if (n + 1 <= N && A[n + 1] == A[n] + 1) {
			res += C[A[n]];
		}


	}
	cout << res << endl;

	return 0;
}
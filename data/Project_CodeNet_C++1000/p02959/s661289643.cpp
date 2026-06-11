#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N + 1), B(N);
	for (int i = 0; i < N + 1; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		int u1 = min(B[i], A[i]);
		sum += u1;
		A[i] -= u1;
		B[i] -= u1;
		int u2 = min(B[i], A[i + 1]);
		sum += u2;
		A[i + 1] -= u2;
		B[i] -= u2;
	}
	cout << sum << endl;
	return 0;
}
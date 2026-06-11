#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N - 1);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> C[i];
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		total += B[A[i]];
	}
	for (int i = 0; i < N - 1; i++) {
		if (A[i + 1] == A[i] + 1) total += C[A[i]];
	}
	cout << total << endl;
	return 0;
}
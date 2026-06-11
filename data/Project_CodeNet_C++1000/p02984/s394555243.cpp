#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	vector<int64_t> A(N);
	int64_t sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	vector<int64_t> X(N);
	for (int i = 1; i < N - 1; i+=2) {
		X[0] += 2 * A[i];
	}
	X[0] = sum - X[0];

	for (int i = 1; i < N; i++) {
		X[i] = 2 * A[i - 1] - X[i - 1];
	}

	for (int i = 0; i < N; i++) {
		if (i) cout << ' ';
		cout << X[i];
	}
	cout << endl;
}
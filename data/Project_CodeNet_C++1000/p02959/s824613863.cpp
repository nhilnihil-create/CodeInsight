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

	vector<int> A(N + 1), B(N);
	for (int i = 0; i <= N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int64_t ret = 0;
	for (int i = 0; i < N; i++) {
		int d = B[i] - A[i];
		if (d >= 0) {
			ret += A[i];
			ret += min(d, A[i + 1]);
			A[i + 1] -= d;
			if (A[i + 1] < 0) A[i + 1] *= 0;
		}
		else {
			ret += B[i];
		}
	}

	cout << ret << endl;
}
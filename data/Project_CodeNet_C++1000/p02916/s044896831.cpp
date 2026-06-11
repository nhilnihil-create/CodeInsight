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

	vector<int> A(N), B(N), C(N - 1);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N - 1; i++) cin >> C[i];

	int ret = 0;
	for (int i = 0; i < N; i++) {
		int cui = A[i];
		ret += B[cui - 1];
		if (i) {
			if (cui == A[i - 1] + 1) ret += C[A[i - 1] - 1];
		}
	}

	cout << ret << endl;
}

// E - Count Median

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[200001];
int B[200001];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i] >> B[i];
	}

	sort(A, A+N);
	sort(B, B+N);

	int ans;

	if (N % 2 == 1) {
		int m = N / 2;
		ans = B[m] - A[m] + 1;
	} else {
		int m1 = N / 2 - 1;
		int m2 = N / 2;
		ans = (B[m1] + B[m2]) - (A[m1] + A[m2]) + 1;
	}

	cout << ans << endl;

	return 0;
}
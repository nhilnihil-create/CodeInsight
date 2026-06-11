#include <iostream>
#include <algorithm>
using namespace std;
const int N_MAX = 200000;

int main() {
	int n;
	int A[N_MAX], B[N_MAX];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}
	sort(A, A+n);
	sort(B, B+n);
	long long ans;
	if (n % 2 == 0) {
		int l = n / 2 - 1;
		ans = (B[l] + B[l+1]) - (A[l] + A[l+1]) + 1;
	} else {
		int l = (n+1) / 2 - 1;
		ans = B[l] - A[l] + 1;
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	long long N;
	cin >> N;
	long long ans[MAX];
	long long A[MAX];
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	for (int i = 1; i < N; i += 2) {
		sum -= 2 * A[i];
	}
	ans[0] = sum;
	for (int i = 1; i < N; i++) {
		ans[i] = 2 * A[i - 1] - ans[i - 1];
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
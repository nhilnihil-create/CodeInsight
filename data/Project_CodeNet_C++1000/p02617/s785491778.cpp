#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], B[1 << 18];
long long ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) cin >> A[i] >> B[i];
	for (int i = 1; i <= N; i++) ans += 1LL * i * (N + 1LL - i);
	for (int i = 1; i <= N; i++) {
		if (A[i] > B[i]) swap(A[i], B[i]);
		long long T = A[i] * (N + 1LL - B[i]);
		ans -= T;
	}
	cout << ans << endl;
	return 0;
}
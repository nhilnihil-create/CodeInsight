#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N;
long long A[1 << 18], B[1 << 18];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	sort(A, A + N);
	sort(B, B + N);

	if (N % 2 == 0) {
		int M = (N / 2);
		long long V1 = B[M - 1] + B[M];
		long long V2 = A[M - 1] + A[M];
		cout << V1 - V2 + 1LL << endl;
	}
	else {
		int M = (N / 2);
		long long V1 = B[M];
		long long V2 = A[M];
		cout << V1 - V2 + 1LL << endl;
	}
	return 0;
}
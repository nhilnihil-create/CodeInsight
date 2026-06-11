#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	int N;
	long int A[100010];
	long int B[100010];

	cin >> N;

	for (int i = 0; i < N + 1; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}

	long int ans = 0;

	for (int i = 0; i < N; ++i) {
		long int v1 = A[i];
		long int v2 = A[i + 1];
		A[i] += A[i + 1];
		A[i + 1] = 0;

		if (A[i] > B[i]) {
			if (v1 >= B[i]) {
				ans += B[i];
				A[i + 1] = v2;
			}else if (v1 < B[i]) {
				ans += B[i];
				A[i + 1] = A[i] - B[i];
			}
		}

		else if (A[i] == B[i]) {
			ans += B[i];
			A[i] = 0;
		}

		else if (A[i] < B[i]) {
			ans += A[i];
		}

	}

	cout << ans << endl;
}
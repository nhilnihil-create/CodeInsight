#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	int X = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		X ^= a[i];
	}

	for (int i = 0; i < N; ++i) {
		cout << (X ^ a[i]) << (i < N - 1 ? " " : "\n");
	}

	return 0;
}


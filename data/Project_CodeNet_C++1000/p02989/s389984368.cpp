#include <iostream>
#include <algorithm>
using namespace std;

long long N, L[1000009];

int main() {
	cin >> N;
	for (long long i = 0; i < N; i++) cin >> L[i];

	sort(L + 0, L + N);

	if (N % 2 != 0) {
		cout << 0;
		return 0;
	}

	long long h = (long long)(N / 2);
	cout <<  L[h] - L[h - 1];

	return 0;
}
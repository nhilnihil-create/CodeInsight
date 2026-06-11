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

long long N, A[1 << 18];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	long long s = -A[N - 1];
	for (int i = 0; i < N; i++) s += 2LL * A[i];
	for (int i = 0; i < N; i++) {
		s -= A[i / 2];
	}
	cout << s << endl;
	return 0;
}
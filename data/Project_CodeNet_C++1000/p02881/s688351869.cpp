#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N;
	cin >> N;

	int64_t rt = sqrt(N);
	int64_t a = 0, b = 0;

	for (int64_t i = rt; rt > 0; i--) {
		if (N % i == 0) {
			a = i;
			b = N / i;
			break;
		}
	}

	cout << (a - 1) + (b - 1) << endl;
}
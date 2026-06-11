#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, L;
	cin >> N >> L;

	int sum = 0, ab = INF, x = INF;
	for (int i = 0; i < N; i++) {
		int n = L + i;
		sum += n;
		int m = abs(n);
		if (m < ab) {
			ab = m;
			x = n;
		}
	}

	cout << sum - x << endl;
}
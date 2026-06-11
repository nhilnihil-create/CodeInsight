#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t L, R;
	cin >> L >> R;

	int64_t a, b;
	a = (L - 1) / 2019;
	b = R / 2019;

	int64_t ret = INF;
	if (b - a == 0) {
		for (int64_t i = L; i < R; i++) {
			for (int64_t j = i + 1; j <= R; j++) {
				int64_t n = (i % 2019) * (j % 2019) % 2019;
				ret = min(ret, n);
			}
		}
	}
	else {
		ret = 0;
	}

	cout << ret << endl;
}
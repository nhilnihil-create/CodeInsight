#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	bool b = 0;
	for (int i = 1; i <= 9; i++) {
		if (N % i == 0) {
			int n = N / i;
			if (n < 10) {
				b = 1;
				break;
			}
		}
	}

	cout << (b ? "Yes" : "No") << endl;
}
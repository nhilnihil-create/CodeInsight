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

	vector<int> H(N);
	for (int i = 0; i < N; i++) cin >> H[i];

	int m = NIL, L = NIL;
	bool f = 1;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		a = H[i]; b = H[i + 1];
		if (a > b) {
			if (a - b > 1) {
				f = 0;
				break;
			}
			else {
				if ((L != NIL) && (L > b)) {
					f = 0;
					break;
				}
				else {
					L = b;
				}
			}
		}
	}

	cout << (f ? "Yes" : "No") << endl;
}
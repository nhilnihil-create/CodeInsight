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

	vector<int> v(N);
	int b1, b2;
	b1 = NIL; b2 = NIL;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v[i] = n;
		if (n >= b1) {
			b2 = b1;
			b1 = n;
		}
		else if (n >= b2) {
			b2 = n;
		}
	}

	for (int i = 0; i < N; i++) {
		int n = v[i];
		if (n == b1) cout << b2 << endl;
		else cout << b1 << endl;
	}
}
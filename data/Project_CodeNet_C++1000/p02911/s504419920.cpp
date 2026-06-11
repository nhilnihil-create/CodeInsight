#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K, Q;
	cin >> N >> K >> Q;

	vector<int> v(N, K);
	for (int i = 0; i < Q; i++) {
		int n;
		cin >> n;
		v[n - 1]++;
	}

	for (int i = 0; i < N; i++) v[i] -= Q;

	for (int i = 0; i < N; i++) {
		int n = v[i];
		if (n > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
		//cout << n << endl;
	}
}
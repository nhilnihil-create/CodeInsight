#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	int ans = INT_MAX;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			int n = v[i] + v[j];
			ans = min(ans, n);
		}
	}

	cout << ans << endl;
}
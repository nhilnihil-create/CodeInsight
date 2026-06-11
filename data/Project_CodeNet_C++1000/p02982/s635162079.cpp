#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, D;
	cin >> N >> D;

	vector<vector<int>> v(N, vector<int>(D));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < D; j++) cin >> v[i][j];
	}

	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i+1; j < N; j++) {
			int s = 0;
			for (int k = 0; k < D; k++) {
				int n = abs(v[i][k] - v[j][k]);
				s += n * n;
			}
			int m = sqrt(s);
			if (m * m == s) cnt++;
		}
	}

	cout << cnt << endl;
}
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

	vector<vector<int>> v(N, vector<int>(N, NIL));
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		for (int j = 0; j < A; j++) {
			int x, y;
			cin >> x >> y;
			x--;
			v[i][x] = y;
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < v[i].size(); j++) {
	//		if (j) cout << ' ';
	//		cout << v[i][j];
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	int ans = 0;
	for (int bit = 0; bit < (1 << N); bit++) {
		vector<int> vec(N, 0);
		for (int i = 0; i < N; i++) {
			if (bit & (1 << i)) vec[i] = 1;
		}
		/*for (int i = 0; i < N; i++) cout << vec[i];
		cout << endl;*/

		bool b = 1;
		for (int i = 0; i < N; i++) {
			if (vec[i] == 0) continue;
			for (int j = 0; j < N; j++) {
				if (v[i][j] != NIL) {
					if (vec[j] != v[i][j]) {
						b = 0;
						break;
					}
				}
			}
			if (!b) break;
		}
		if (!b) continue;
		int n = count(vec.begin(), vec.end(), 1);
		ans = max(ans, n);
	}

	cout << ans << endl;
}
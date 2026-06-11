#include<bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	vector<int>x(N);
	vector<int>y(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	int ans = MOD;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			int cx = x[j] - x[i];
			int cy = y[j] - y[i];
			int cnt = 0;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (cx == x[l] - x[k] && cy == y[l] - y[k])
						cnt++;
				}
			}
			ans = min(ans, N - cnt);
		}
	}
	cout <<ans<< endl;
	return 0;
}
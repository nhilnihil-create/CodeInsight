#include <bits/stdc++.h>
using namespace std;

int A[3005], N;

const int64_t mod = 998244353;

int64_t DP[4000][4000];

int64_t f(int i, int s) {
	if (i == N) {
		if (s == 0) return 1;
		else return 0;
	}
	if (DP[i][s] != -1) return DP[i][s];
	int64_t ans = (2*f(i+1, s))%mod;
	if (A[i] <= s)  {
		ans += f(i+1, s-A[i]);
		ans %= mod;
	}
	return DP[i][s] = ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int S;
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	memset(DP, -1, sizeof DP);

	cout << f(0, S) << endl;

}
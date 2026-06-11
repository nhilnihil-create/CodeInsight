#include <bits/stdc++.h>
typedef long long int LL;
using namespace std;

// 插入此處

const int MAXN = 2e3 + 2;
const int MOD = 1e9 +7;
LL ans[MAXN][MAXN];
int ans_T[MAXN][MAXN];
int ans_S[MAXN][MAXN];
int find_T[MAXN][MAXN];
int find_S[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M; cin >> N >> M;
	vector<int> S(N+2), T(M+2);
	for (int i = 1; i <= N; ++i) {
		cin >> S[i];
	}
	for (int i = 1; i <= M; ++i) {
		cin >> T[i];
	}
	memset(find_S, -1, sizeof(find_S));
	memset(find_T, -1, sizeof(find_T));
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (T[i] == S[j]) {
				find_S[i][j] = j;
				find_T[i][j] = i;
			} else {
				find_S[i][j] = find_S[i][j-1];
				find_T[i][j] = find_T[i-1][j];
			}
		}
	}
	memset(ans_S, 0, sizeof(ans_S));
	memset(ans_T, 0, sizeof(ans_T));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i <= M; ++i) {
		ans[i][0] = 1;
	}
	for (int i = 0; i <= N; ++i) {
		ans[0][i] = 1;
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (find_T[i][j] != -1) {
				ans_T[i][j] = (ans[find_T[i][j]-1][j-1] + ans_T[find_T[i][j]-1][j]) % MOD;
			}
			if (find_S[i][j] != -1) {
				ans_S[i][j] = (ans[i-1][find_S[i][j]-1] + ans_S[i][find_S[i][j]-1]) % MOD;
			}
			ans[i][j] = ans[i-1][j-1] + ans_T[i][j] + ans_S[i][j];
			if (S[j] == T[i])  ans[i][j] -= ans[i-1][j-1];
			ans[i][j] %= MOD;
			// cout << "i " << i << " j " << j << " ans_T " << ans_T[i][j] << " ans_S " << ans_S[i][j] << " ans " << ans[i][j] << endl;
		}
	}
	cout << ans[M][N] << endl;
	return 0;
}

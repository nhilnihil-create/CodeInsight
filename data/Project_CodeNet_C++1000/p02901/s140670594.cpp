#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 998244353, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> key;

ll dp[1001][(1 << 12)];
key keys[1000];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	rep(i, M + 1) {
		rep(j, (1 << N)) {
			dp[i][j] = MAX;
		}
	}
	dp[0][0] = 0;
	rep(i, M) {
		cin >> A >> B;
		ll sum = 0;
		rep(j, B) {
			cin >> C; C--;
			sum += (1 << C);
		}
		keys[i] = key(A, sum);
	}
	rep(i, M) {
		rep(j, (1 << N)) {
			dp[i + 1][j | keys[i].second] = min(dp[i + 1][j | keys[i].second], dp[i][j] + keys[i].first);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		}
	}
	if (dp[M][(1 << N) - 1] == MAX) cout << -1;
	else cout << dp[M][(1 << N) - 1];
}
#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 998244353, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

ll dp[3001][3001];
Pa arr[3000];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> T;
	rep(i, N) {
		cin >> A >> B;
		arr[i] = Pa(A, B);
	}
	sort(arr, arr + N);
	rep(i, N + 1) {
		rep(j, T + 1) {
			dp[i][j] = 0;
		}
	}
	ll maxv = 0;
	rep(i, N) {
		rep(j, T) {
			if (j + arr[i].first <= T) dp[i + 1][j + arr[i].first] = max(dp[i + 1][j + arr[i].first], dp[i][j] + arr[i].second);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}
	rep(i, N + 1) {
		rep(j, T) {
			maxv = max(maxv, dp[i][j] + arr[i].second);
		}
	}
	cout << maxv;
}

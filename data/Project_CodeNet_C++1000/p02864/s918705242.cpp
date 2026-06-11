#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

ll dp[601][601];

void chmin(ll&a, ll b) {
	a = min(a, b);
}

int main(){
	int N, K;
	cin >> N >> K;
	vector<ll> H(N + 2, 0);
	for (int i = 1;i <= N;i++) {
		cin >> H[i];
	}

	ll a, b, c, d;

	for (int i = 0;i <= N + 1;i++)
		for (int j = 0;j <= K;j++)
			dp[i][j] = LLONG_MAX / 3;

	dp[0][0] = 0;

	for (int i = 0;i <= N + 1;i++) {
		for (int k = 0;k <= K;k++) {
			for (int j = i + 1;j <= N + 1;j++) {
				a = H[i];
				b = H[j];
				c = min(a, b);
				d = b * 2;
				chmin(dp[j][k + j - i - 1], dp[i][k] + d - c * 2);
			}
		}
	}
	a = LLONG_MAX;
	for (int i = 0;i <= K;i++) {
		chmin(a, dp[N + 1][i]);
	}
	cout << a / 2 << endl;
}
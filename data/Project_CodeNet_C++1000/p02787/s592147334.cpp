#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll dp[1002][10002];

void solve() {
	int h, n;
	cin >> h >> n;
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j <= h; j++) {
			if (j == 0) dp[i][j] = 0;
			else if (i == n) {
				dp[i][j] = INF;
			} else {
				dp[i][j] = min(dp[i][max(0ll, j - a[i])] + b[i], dp[i + 1][j]);
			}
		}
	}
	cout << dp[0][h] << endl;
}

int main() {
	solve();
	return 0;
}
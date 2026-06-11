#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int MAX_H = 10000;

int main() {
	int h, n;
	cin >> h >> n;
	vector<int> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	vector<vector<int>> dp(n+1, vector<int>(MAX_H + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= h; j++) {
			if (j - a[i] <= 0) {
				dp[i+1][j] = min(dp[i][j], b[i]);
			} else {
				dp[i+1][j] = min(dp[i][j], dp[i+1][j - a[i]] + b[i]);
			}
		}
	}
	cout << dp[n][h] << endl;
}
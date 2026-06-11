#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int n, m;
const int dx[] = {0, 1};
const int dy[] = {1, 0};
bool ok(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<vector<char>>v(n + 1, vector<char>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<int>>dp((n + 1), vector<int>(m + 1, 1e9));
	dp[0][0] = (v[0][0] == '#');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (ok(nx, ny)) {
					dp[nx][ny] = min(dp[nx][ny], (v[i][j] == '.' && v[nx][ny] == '#') + dp[i][j]);
				}
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
}


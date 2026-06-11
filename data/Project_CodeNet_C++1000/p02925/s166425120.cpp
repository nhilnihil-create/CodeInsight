#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1LL << 61);
const int inf = 1001001001;
const int mod = 1000000007;

const int MAXN = 1005;
const int MAXV = MAXN * (MAXN - 1) / 2;

vector<int> g[MAXV];
int id[MAXN][MAXN];

int dp[MAXV];
bool vi[MAXV];
bool cal[MAXV];

int f(int a, int b) {
	if (a > b) swap(a, b);
	return id[a][b];
}

int dfs(int s) {
	if (vi[s]) {
		if (!cal[s]) return -1;
		return dp[s];
	}
	vi[s] = true;
	dp[s] = 1;
	for (int c : g[s]) {
		int res = dfs(c);
		if (res == -1) return -1;
		maxs(dp[s], res + 1);
	}
	cal[s] = true;
	return dp[s];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n - 1));
	rep(i, n)rep(j, n - 1) cin >> a[i][j], a[i][j]--;
	int V = 0;
	rep(i, n) {
		rep(j, n) {
			if (i < j) {
				id[i][j] = V++;
			}
		}
	}
	rep(i, n) {
		rep(j, n - 1) {
			a[i][j] = f(i, a[i][j]);
		}
		rep(j, n - 2) {
			g[a[i][j + 1]].push_back(a[i][j]);
		}
	}
	int ans = 0;
	rep(i, V) {
		int res = dfs(i);
		if (res == -1) {
			cout << -1 << endl;
			return 0;
		}
		maxs(ans, res);
	}
	cout << ans << endl;
	return 0;
}
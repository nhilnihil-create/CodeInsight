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

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	rep(i,h) cin >> v[i];
	vector<vector<int>> g(h, vector<int>(w));
	rep(i,h) {
		rep(j,w) {
			int l = j;
			int r = j;
			int t = 1;
			while (r + 1 < w && v[i][r] == v[i][r + 1]) {
				r++;
				t++;
			}
			if (v[i][j] == '#') t = 0;
			for (int k = l; k <= r; k++) {
			 	g[i][k] += t;
			}
			j = r;
		}
	}
	rep(j,w) {
		rep(i,h) {
			int l = i;
			int r = i;
			int t = 1;
			while (r + 1 < h && v[r][j] == v[r + 1][j]) {
				r++;
				t++;
			}
			if (v[i][j] == '#') t = 0;
			for (int k = l; k <= r; k++) {
			 	g[k][j] += max(0, t - 1);
			}
			i = r;
		}
	}
	int ans = 0;
	rep(i,h) {
		rep(j,w) ans = max(ans, g[i][j]);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
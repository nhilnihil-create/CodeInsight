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
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> H_(h, vector<int>(w));
	vector<vector<int>> W_(h, vector<int>(w));
	rep(j, w) {
		int cnt = 0;
		rep(i, h) {
			if (s[i][j] == '.') cnt++;
			if (s[i][j] == '#') {
				if (i != 0) H_[i - 1][j] = cnt;
				cnt = 0;
			}
			if (i == h - 1) {
				if (s[i][j] != '#') H_[i][j] = cnt;
			}
		}
		int now = -1;
		for (int i = h - 1; i >= 0; --i) {
			if (now == -1 && s[i][j] != '#') now = H_[i][j];
			else {
				if (s[i][j] == '.') {
					H_[i][j] = now;
				}
				else {
					now = -1;
				}
			}
		}
	}
	rep(i, h) {
		int cnt = 0;
		rep(j, w) {
			if (s[i][j] == '.') cnt++;
			if (s[i][j] == '#') {
				if (j != 0) W_[i][j - 1] = cnt;
				cnt = 0;
			}
			if (j == w - 1) {
				if (s[i][j] != '#') W_[i][j] = cnt;
			}
		}
		int now = -1;
		for (int j = w - 1; j >= 0; --j) {
			if (now == -1 && s[i][j] != '#') now = W_[i][j];
			else {
				if (s[i][j] == '.') {
					W_[i][j] = now;
				}
				else {
					now = -1;
				}
			}
		}
	}
	/*rep(i, h) {
		rep(j, w) cout << H_[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	rep(i, h) {
		rep(j, w) cout << W_[i][j] << ' ';
		cout << endl;
	}*/
	int ans = 0;
	rep(i, h)rep(j, w) maxs(ans, W_[i][j] + H_[i][j] - 1);
	cout << ans << endl;
	return 0;
}
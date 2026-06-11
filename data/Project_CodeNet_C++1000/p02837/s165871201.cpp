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
	int n;
	cin >> n;
	vector<vector<pii>> v(n);
	rep(i,n) {
		int a;
		cin >> a;
		int x, y;
		rep(j,a) {
			cin >> x >> y;
			x--;
			v[i].push_back(pii(x, y));
		}
	}
	int ans = 0;
	rep(bit, (1 << n)) {
		bool b = true;
		rep(i, n) {
			if (!(bit & (1 << i))) continue;
			for (auto p: v[i]) {
				if ((bool)(bit & (1 << p.first)) ^ p.second) b = false;
			}
		}
		if (b) ans = max(ans, __builtin_popcount(bit));
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
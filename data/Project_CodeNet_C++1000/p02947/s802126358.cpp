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

ll choose(ll a) {
	return a * (a - 1) / 2;
}

void solve() {
	int n;
	cin >> n;
	vector<string> v(n);
	rep(i,n) cin >> v[i];
	vector<vector<int>> u(n, vector<int>(26));
	rep(i,n) {
		string s = v[i];
		rep(j,10) {
			u[i][(s[j] - 'a')]++;
		}
	}
	ll ans = 0;
	map<vector<int>, int> mp;
	for (int i = 0; i < n; i++) {
		mp[u[i]]++;
	}
	for (auto p: mp) {
		if (p.second <= 1) continue;
		ans += choose(p.second);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
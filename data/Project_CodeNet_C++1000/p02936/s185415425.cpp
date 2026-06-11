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

vector<vector<int>> to;
vector<int> cnt;

void dfs(int s, int t) {
	for (int p: to[t]) {
		if (p == s) continue;
		cnt[p] += cnt[t];
		dfs(t, p);
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	to.resize(n);
	cnt.resize(n);
	rep(i,n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	rep(i,q) {
		int p, x;
		cin >> p >> x;
		p--;
		cnt[p] += x;
	}
	dfs(-1, 0);
	rep(i,n) cout << cnt[i] << " ";
	cout << endl;
}

int main() {
	solve();
	return 0;
}
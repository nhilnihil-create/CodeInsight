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
	int n, x, y;
	cin >> n >> x >> y;
	x--, y--;
	vector<vector<int>> to(n);
	rep(i,n-1) {
		to[i].push_back(i + 1);
		to[i + 1].push_back(i);
	}
	to[x].push_back(y);
	to[y].push_back(x);

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		queue<int> q;
		vector<int> d(n, INF);
		auto update = [&] (int s, int t) {
			if (d[t] != INF) return;
			d[t] = d[s] + 1;
			q.push(t);
		};
		q.push(i);
		d[i] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int y: to[x]) {
				update(x, y);
			}
		}
		rep(j, n) {
			if (d[j] != INF) ans[d[j]]++;
		}
	}
	for (int i = 1; i < n; i++) cout << ans[i] / 2 << endl;
}

int main() {
	solve();
	return 0;
}
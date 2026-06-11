#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;

vector<vector<int>> g(100005);
vector<bool> visited(100005);

int maxcol = 1;
map<int, pair<int, int>> BAN;
map<pair<int, int>, int> ans;
map<pair<int, int>, bool> used;

void bfs(int s) {
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		int col = 1;
		visited[v] = true;
		for (int to: g[v]) {
			if (visited[to]) continue;
			while (used[make_pair(v, col)]) col++;
			ans[make_pair(min(v, to), max(v, to))] = col;
			used[make_pair(v, col)] = true;
			used[make_pair(to, col)] = true;
			Q.push(to);
		}
	}
}



int main() {
	int n;
	cin >> n;
	int a[n - 1], b[n - 1];
	rep (i, n - 1) cin >> a[i] >> b[i];
	rep (i, n - 1) {
		a[i]--; b[i]--;
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
		BAN[i] = make_pair(min(a[i], b[i]), max(a[i], b[i]));
	}


	bfs(0);

	int m = -1;

	rep (i, n - 1) {
		chmax(m, ans[make_pair(BAN[i].fi, BAN[i].se)]);
	}
	cout << m << endl;
	rep (i, n - 1) cout << ans[make_pair(BAN[i].fi, BAN[i].se)] << endl;
	return 0;
}
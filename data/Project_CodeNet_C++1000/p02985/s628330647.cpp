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
using P = pair<int, int>;

vector<vector<int>> g(100005);
constexpr ll MOD = 1000000007;

int n, k;
ll ans = 1;

vector<bool> visited(100005);

void bfs() {
	queue<P> Q;
	Q.emplace(0, k);
	while (!Q.empty()) {
		auto v = Q.front(); Q.pop();
		ans *= v.se;
		ans %= MOD;

		visited[v.fi] = true;

		int cnt = 1;
		for (int to: g[v.fi]) {
			if (visited[to]) continue;
			if (v.fi == 0) Q.emplace(to, k - cnt);
			else Q.emplace(to, k - (1 + cnt));
			cnt++;
		}
	}
}

int main() {
	
	cin >> n >> k;
	rep (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	bfs();

	cout << ans << endl;
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;

int n;
vector<vector<P>> G;
vl color;

void dfs(int i, int pre, int pre_c) {
	int cnt = 1;
	for (auto g : G[i]) {
		if (g.first == pre) continue;
		if (cnt == pre_c) {
			cnt++;	//親と同じ色なら変える
		}
		color[g.second] = cnt;
		dfs(g.first, i, color[g.second]);
		cnt++;		//次の辺も異なる色
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	cin >> n;
	G.resize(n);
	color.resize(n - 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back({ b, i });
		G[b].push_back({ a, i });
	}

	int maxc = 0;	//最大の辺
	int start = 0;
	rep(i, n) {
		if (maxc < sz(G[i])) {
			chmax(maxc, sz(G[i]));
			start = i;	//最も辺が多い所から始める
		}
	}
	out(maxc);
	
	dfs(0, -1, -1);
	rep(i, n - 1) {
		out(color[i]);
	}

	return 0;
}
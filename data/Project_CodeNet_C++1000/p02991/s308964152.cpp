#include <bits/stdc++.h>


#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<int, int> P;
typedef tuple<int, int, int> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

const ll mod = 1000000007;

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	ll s, t;
	cin >> s >> t;
	s--; t--;
	vector<vector<ll>> dp(n, vector<ll>(3, INF));
	priority_queue<P, vector<P>, greater<P>> q;
	q.emplace(0, s);
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		auto step = p.first;
		auto ns = step % 3;
		auto current = p.second;
		if (dp[current][ns] <= step) continue;
		dp[current][ns] = step;
		if (current == t && ns == 0) break;
		for (auto e : g[current]) {
			if (dp[e][(step + 1) % 3] <= step+1) continue;
			q.emplace(step + 1, e);
		}
	}
	if (dp[t][0] == INF) {
		cout << -1 << endl;
	}
	else {
		cout << dp[t][0] / 3 << endl;
	}
	return 0;
}

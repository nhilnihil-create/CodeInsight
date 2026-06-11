#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<ll> add(n, 0);
	rep(i, q) {
		ll a, v;
		cin >> a >> v;
		a--;
		add[a] += v;
	}
	vector<ll> score(n, 0);
	function<void(int, int, int)> dfs = [&](int current, int parent, ll s) {
		ll cs = s + add[current];
		score[current] = cs;
		for (auto child : g[current]) {
			if (child == parent) continue;
			dfs(child, current, cs);
		}
	};
	dfs(0, -1, 0);
	rep(i, n) {
		cout << score[i] << " ";
	}
	cout << endl;
	return 0;
}

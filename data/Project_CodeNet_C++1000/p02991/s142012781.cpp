#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
//const ll p = 1e9 + 7;
//const ll p = 998244353;
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

ll bfs(ll n, vector<vll> &nx, ll s, ll t) {
	queue<ll> task;
	task.push(s);
	vector<bool> seen(n, false);
	seen[s] = true;
	ll depth = 1;
	while (task.size()) {
		ll sz = task.size();
		while (sz--) {
			for (ll i = 0; i < nx[task.front()].size(); i++) {
				if (nx[task.front()][i] == t) return depth;
				if (!seen[nx[task.front()][i]]) {
					task.push(nx[task.front()][i]);
					seen[nx[task.front()][i]] = true;
				}
			}
			task.pop();
		}
		depth++;
	}
	return -3;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	auto index = [&] (ll i, ll x) {return i + x * n;};

	vector<vll> nx(3 * n, vll(0));
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		nx[index(u, 0)].push_back(index(v, 1));
		nx[index(u, 1)].push_back(index(v, 2));
		nx[index(u, 2)].push_back(index(v, 0));
	}

	ll s, t;
	cin >> s >> t;
	s--;
	t--;

	//index(s, 0) -> index(t, 0)の到達可否・最短距離を求める
	ll ans = bfs(3 * n, nx, index(s, 0), index(t, 0));
	cout << ans / 3 << endl;
}

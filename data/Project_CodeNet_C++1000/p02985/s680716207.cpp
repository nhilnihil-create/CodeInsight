#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (ll)a; i <= (ll)b; i++)
#define DEC(i, a, b) for(ll i = (ll)a; i >= (ll)b; i--)

ll n, k, a, b, ans = 1, m = 1e9+7;
vector <int> adj[100050];

void mul(ll &a, ll b) {
	a *= b;
	a %= m;
}

void dfs(int x, int p, int coun) {
	if (coun >= k) {cout << 0; exit(0);}
	mul(ans, k - coun);
	int c = 1 + (p != -1);
	for(auto it:adj[x]) {
		if (it == p) continue;
		dfs(it, x, c);
		c++;
	}
}

int main() {
	cin >> n >> k;
	FOR(i, 1, n-1) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1, 0);
	cout << ans;
}

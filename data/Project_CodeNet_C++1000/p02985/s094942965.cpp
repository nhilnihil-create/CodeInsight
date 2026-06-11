#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

vvi e;
ll k, ans;
V<bool> vis;

void dfs(int v) {
	vis[v] = true;

	int h = 0;
	if (v == 0)for (int vv : e[v]) {
		if (vis[vv])continue;
		ans *= max(k - 1 - h, 0LL);ans %= MOD;
		h++;
	}
	else for (int vv : e[v]) {
		if (vis[vv])continue;
		ans *= max(k - 2 - h, 0LL);ans %= MOD;
		h++;
		
	}
	
	for (int vv : e[v])if(!vis[vv])dfs(vv);

}

int main() {

	int n;
	cin >> n >> k;
	e.resize(n);
	vis.resize(n);
	ans = k;
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfs(0);

	cout << ans << endl;

}
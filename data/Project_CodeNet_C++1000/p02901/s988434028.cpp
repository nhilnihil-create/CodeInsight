#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)

const int N = 5e5 + 7;
const ll mod = 1e9 + 7;

vector<vector<int>> keys;
vector<int> costs;
ll dp[1007][1 << 13];
int n, m;

ll solve(int idx, int mask) {
	if (mask == (1 << n)-1)
		return 0;

	if (idx == m) {
		return 1e18;
	}

	ll& ans = dp[idx][mask];
	if (~ans)
		return ans;

	int newmask = mask;
	for (int i = 0; i < (int)keys[idx].size(); i++) {
		newmask |= (1 << keys[idx][i]);
	}

	ans = min(solve(idx+1, mask), costs[idx] + solve(idx+1, newmask));
	return ans;
}


int main() {
	fastIO;
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		costs.push_back(a);
		vector<int> tmp(b);
		for (int j = 0; j < b; j++) {
			cin >> tmp[j];
			tmp[j]--;
		}
		keys.push_back(tmp);
	}
	ll ans = solve(0, 0);
	if (ans >= 1e18)
		cout << -1;
	else
		cout << ans;

}

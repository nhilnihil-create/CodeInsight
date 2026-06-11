#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 12, M = 1e3 + 5;
int dp[M][(1 << N)], a[M], c[M], n, m;

int solve(int idx, int mask){
	if(idx == m){
		if(mask != (1 << n) - 1)
			return 1e8 + 5;
		else
			return 0;
	}
	int &ans = dp[idx][mask];
	if(~ans)
		return ans;
	return ans = min(solve(idx + 1, mask), solve(idx + 1, mask | c[idx]) + a[idx]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int b;
		cin >> a[i] >> b;
		for(int j = 0; j < b; j++){
			int cc;
			cin >> cc;
			cc--;
			c[i] |= (1 << cc);
		}
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	if(ans > 1e8)
		ans = -1;
	cout << ans;
	return 0;
}

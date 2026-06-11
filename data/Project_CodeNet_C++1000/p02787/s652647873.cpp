#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//clock_t begin = clock();
	int h, n;
	cin >> h >> n;
	vector<pi>v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i].fi >> v[i].se;
	}
	vector<ll>dp(h + 1, 1e9);
	dp[h] = 0;
	for (int i = h; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int can = v[j].fi;
			int by = v[j].se;
			if (i - can <= 0)
				dp[0] = min(dp[0], dp[i] + by);
			else
				dp[i - can] = min(dp[i - can], dp[i] + by);
		}
	}
	cout << dp[0] << endl;
	//clock_t end = clock();
	//cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}
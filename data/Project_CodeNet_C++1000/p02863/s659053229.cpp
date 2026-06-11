#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> r(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		r[i] = pair<int, int>(a, b);
	}
	sort(r.begin(), r.end());
	vector<vector<ll>> dp(3010, vector<ll>(7000, -1));
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, 6000) {
			int time = r[i].first;
			int hap = r[i].second;
			if (j - time >= 0 && dp[i][j - time] != -1 && j - time < t) {
				chmax(dp[i + 1][j], dp[i][j - time] + hap);
			}
			chmax(dp[i + 1][j], dp[i][j]);
		}
	}
	ll ans = 0;
	rep(i, 6000) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}
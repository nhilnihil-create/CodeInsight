#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<ll,ll>> a(n);
	rep(i, n) {
		ll ai;
		cin >> ai;
		a[i] = { ai,(ll)i };
	}
	sort(a.rbegin(), a.rend());
	vector<vector<ll>> dp(n+1, vector<ll>(n+1,0));
	rep(i, n) {
		rep(j, i + 1) {//合計i+1人、dp[j][i-j]から遷移していく
			dp[j + 1][i - j] = max(dp[j + 1][i - j], dp[j][i - j] + a[i].first * (a[i].second - j));
			dp[j][i - j + 1] = max(dp[j][i - j + 1], dp[j][i - j] + a[i].first * (((ll)n-i+j-1) - a[i].second));
		}
	}
	ll ans = 0;
	rep(i, n + 1) {
		ans = max(ans, dp[i][n - i]);
	}
	cout << ans << endl;
}
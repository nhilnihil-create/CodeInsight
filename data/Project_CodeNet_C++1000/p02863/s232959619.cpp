#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n, t;
	cin >> n >> t;
	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end());
	vector<int> dp(t + 1, 0);
	rep(i, n) {
		for (int j = t - 1; j >= 0; --j) {
			dp[min(t,j + p[i].first)] = max(dp[min(t,j + p[i].first)], dp[j] + p[i].second);
		}
	}
	cout << dp[t] << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	vector <int> dp, cnt;
	int n; ll k;
	cin >> s >> k; n = s.size();
	dp.resize(n); cnt.resize(n);
	for (int i=n-2; i>=0; i--) {
		cnt[i] = cnt[i+1];
		if (s[i] != s[i+1]) {
			cnt[i] ++;
		}
	}
	int tec = 0;
	for (int i=1; i<n-1; i++) {
		if (!cnt[i] || cnt[i] == cnt[0]) continue;
		dp[i] = dp[i-1];
		if (s[i] != s[i-1]) {
			dp[i] += tec>>1;
			tec = 1;
		} else {
			tec ++;
		}
		if (!cnt[i+1]) {
			dp[i] += tec>>1;
		}
	}
	ll ans;
	if (!cnt[0]) {
		ans = k*n>>1;
		cout << ans;
		return 0;
	}
	int first = 1;
	for (int i=1; i<n; i++) {
		if (s[i] != s[i-1]) {
			break;
		}
		first ++;
	}
	int last = 1;
	for (int i=n-2; i>=0; i--) {
		if (s[i] != s[i+1]) {
			break;
		}
		last ++;
	}
	ans = k*(*max_element(dp.begin(), dp.end())) + (first>>1) + (last>>1);
	if (s[0] == s.back()) {
		ans += ((last+first)>>1)*(k-1);
	} else {
		ans += ((last>>1)+(first>>1))*(k-1);
	}
	cout << ans;
	return 0;
}

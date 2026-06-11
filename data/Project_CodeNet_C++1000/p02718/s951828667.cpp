#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

ll dp[200005][4];

int main() {
	int n, m, sum = 0;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	string ans;
	a[n - m] >= (4 * m + sum - 1) / (4 * m) ? ans = "Yes" : ans = "No";
	cout << ans << endl;
	return 0;
}

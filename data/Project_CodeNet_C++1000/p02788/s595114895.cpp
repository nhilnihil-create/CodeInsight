#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int asd[12345678];
signed main() {
	int n, d, a, cnt = 0, ans = 0; cin >> n >> d >> a;
	queue<int> v, cost; vector<vector<int>> x(n, vector<int>(2));
	for (int h = 0; h < n; h++) {
		cin >> x[h][0] >> x[h][1];
	}
	sort(x.begin(), x.end());
	for (int h = 0; h < n; h++) {
		while (true) {
			if (v.empty()) { break; }
			if (v.front() < x[h][0]) { cnt -= cost.front(); v.pop(); cost.pop(); }
			else { break; }
		}
		x[h][1] -= cnt;
		if (x[h][1] > 0) {
			ans += (x[h][1] + a - 1) / a;
			v.push(x[h][0] + d + d); cost.push((x[h][1] + a - 1) / a * a);
			cnt += (x[h][1] + a - 1) / a * a;
			//cout << h << ' ' << ans << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
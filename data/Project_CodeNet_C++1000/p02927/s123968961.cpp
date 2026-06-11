#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000;
const ll mod = 1000000007;
ll test[12345678][2], aa[1234][1234], bb[1234][1234];
ll dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
char maze[1234][1234];
signed main() {
	ll n, m, k, cnt = 1, ans = 0; cin >> n >> m;
	for (int h = 2; h <= 9; h++) {
		for (int i = 2; i <= 9; i++) {
			if (h * 10 + i <= m && h * i <= n) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
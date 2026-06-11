#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
typedef double db;
#define inf 0x3f3f3f3f
vector<int>a[100005];
queue<int>que;
bool b[100005];
const ll mod = 1e9 + 7;
//std::ios::sync_with_stdio(0); std::cin.tie(0);
int main() {
	int n, x, y, i, len, j;
	ll k, ans = 1;
	cin >> n >> k;
	for (i = 1; i < n; ++i) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	ans *= k;
	b[1] = 1;
	len = a[1].size();
	for (i = 0; i < len; ++i) {
		b[a[1][i]] = 1;
		que.push(a[1][i]);
		ans = (ans * (k - i - 1)) % mod;
	}
	while (!que.empty()) {
		int temp = 0;
		for (i = 0; i < len; ++i) {
			int t = que.front();
			b[t] = 1;
			int m = a[t].size();
			int cnt = k - 2;
			for (j = 0; j < m; ++j) {
				if (!b[a[t][j]]) {
					ans = (ans * cnt) % mod;
					--cnt;
					que.push(a[t][j]);
					++temp;
				}
			}
			que.pop();
		}
		len = temp;
	}
	cout << ans << endl;
	return 0;
}
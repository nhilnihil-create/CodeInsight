#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	vector<queue<int>> q(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		q[a].push(b);
		q[b].push(a);
	}
	ans = n;
	rep(i, n) {
		int x = h[i];
		while (q[i].size()) {
			int t = q[i].front();
			q[i].pop();
			if (x > h[t]) continue;
			ans--;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

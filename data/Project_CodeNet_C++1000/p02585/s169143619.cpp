#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const ll MNA = -1e18;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	ll n, k;
	cin >> n >> k;
	ll p[n+1], c[n+1];
	for (int i=1; i<=n; i++) cin >> p[i];
	for (int i=1; i<=n; i++) cin >> c[i];
	ll ans = MNA;
	for (int i=1; i<=n; i++) {
		ll cur = 0;
		int tmp = 0;
		vector<bool> vis(n+1);
		vis[i] = true;
		int idx = i;
		while (tmp < k) {
			idx = p[idx];
			cur += c[idx];
			ans = max(ans, cur);
			tmp++;
			if (vis[idx]) break;
			vis[idx] = true;
		}
		if (cur > 0) {
			ll mul = k/tmp - 1;
			cur *= mul;
			ans = max(ans, cur);
			tmp = k - mul*tmp;
			idx = i;
			while (tmp--) {
				idx = p[idx];
				cur += c[idx];
				ans = max(ans, cur);
			}
		}
	}
	cout << ans << '\n';
}
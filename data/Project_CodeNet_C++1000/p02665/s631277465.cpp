typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define INF 1000000000
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<ll> leaf(n + 1);
	for (int i = 0; i <= n; ++i) {
		cin >> leaf[i];
	}
	if (leaf[0] >= 2) {
		cout << -1 << '\n';
		return 0;
	}
	vector<ll> sum(n + 2);
	for (int i = 1; i <= n + 1; ++i) {
		sum[i] = sum[i - 1] + leaf[i - 1];
	}
	vector<ll> n_leaf(n + 1);
	n_leaf[0] = 1 - leaf[0];
	for (int i = 1; i <= n; ++i) {
		n_leaf[i] = (2LL * n_leaf[i - 1]) - leaf[i];
		n_leaf[i] = min(n_leaf[i], sum[n + 1] - sum[i + 1]);
		if (n_leaf[i] < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans += leaf[i] + n_leaf[i];
	}
	cout << ans << '\n';
	
	return 0;
}

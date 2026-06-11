#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100010];
int c[3];
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];

	ll ans = 1;
	rep(i,n) {
		int cnt = 0, id = -1;
		if (a[i] == c[0]) {
			cnt++; id = 0;
		}
		if (a[i] == c[1]) {
			cnt++; id = 1;
		}
		if (a[i] == c[2]) {
			cnt++; id = 2;
		}
		
		if (id == -1) {
			cout << 0 << endl;
			return 0;
		}
		c[id]++;
		ans *= cnt;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
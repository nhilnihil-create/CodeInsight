#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	vector<bool> snuke(n, false);
	int ans = n;
	rep(i, k) {
		int d;
		cin >> d;
		rep(j, d) {
			int a;
			cin >> a;
			a--;
			if (!snuke[a]) {
				ans--;
				snuke[a] = true;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

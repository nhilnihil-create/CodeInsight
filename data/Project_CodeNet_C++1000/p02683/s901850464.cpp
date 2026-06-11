#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else { return gcd(b, a % b); } }

int main() {

	ll n, m, x;
	cin >> n >> m >> x;
	vector<ll> C(n);
	ll A[12][12];
	for (int i = 0; i < n; i++) {
		cin >> C[i];
		for (int j = 0; j < m; j++) {
			ll k;
			cin >> k;
			A[i][j] = k;
		}
	}
	ll ans = -1;

	for (int bit = 0; bit < (1 << n); bit++) {
		ll cost = 0;
		vector<ll> abr(m, 0);
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				cost += C[i];
				for (int j = 0; j < m; j++) {
					abr[j] += A[i][j];
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < m; i++) {
			if (abr[i] < x) {
				flag = false;
				break;
			}
		}
		if (flag == true && ans == -1)ans = cost;
		else if (flag == true && ans != -1) ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}
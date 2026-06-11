#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;
ll money[1005];
int main() {
	ll n, m, x;
	cin >> n >> m >> x;
	vector<vector<ll>>a(n);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		a[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	ll ans = mod;
	for (int bit = 0; bit < (1 << n); bit++) {
		ll sum = 0;
		vector<ll>alg(m, 0);
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				sum += money[i];
				for (int j = 0; j < m; j++) {
					alg[j] += a[i][j];
				}
			}
		}
		ll check = 0;
		for (int i = 0; i < m; i++) {
			if (alg[i] >= x) {
				check++;
			}
		}
		if (check == m) {
			ans = min(ans, sum);
		}
	}
	if (ans == mod) {
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;

}
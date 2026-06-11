#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	sort(a.rbegin(), a.rend());
	bool flag = true;
	for (int i = 0; i < m; i++) {
		if (a[i] < (total + (4*m) - 1) / (4 * m)) {
			flag = false;
			break;
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
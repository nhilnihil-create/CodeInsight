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
	vector<int> a;
	for (int i = 0; i < n; i++) a.push_back(2 * i);
	for (int i = 0; i < m; i++) a.push_back(2 * i + 1);
	int ans = 0;
	for (int i = 0; i < n + m - 1; i++) {
		for (int j = i + 1; j < n + m; j++) {
			if ((a[i] + a[j]) % 2 == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
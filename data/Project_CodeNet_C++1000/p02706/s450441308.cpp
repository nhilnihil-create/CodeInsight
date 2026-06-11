#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;
const double pi = acos(-1);

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	ll total = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		total += a[i];
	}

	if (total > n) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << n - total << endl;
	return 0;
}
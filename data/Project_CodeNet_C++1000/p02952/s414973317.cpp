#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int count(int num) {
	int res = 0;
	while (num > 0) {
		num /= 10;
		res++;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (count(i) % 2 == 1) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
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

int min_len(int i, int j, int x, int y) {
	int res = min({ abs(j - i),abs(x - i) + 1 + abs(j - y),abs(y - i) + 1 + abs(j - x) });
	return res;
}
int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> cnt(n);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n + 1; j++) {
			cnt[min_len(i, j, x, y)]++;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << cnt[i] << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll ex(ll x) {
	ll res = x / 10;
	x /= 10;
	while (x > 0)
	{
		res += x / 5;
		x /= 5;
	}
	
	return res;
}


int main() {
	ll n;
	cin >> n;
	if (n % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}

	cout << ex(n) << endl;
	
	return 0;
}
#include <iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll a[100001];
ll go(ll x) {
	ll cnt = 0;
	while (x % 2 == 0) {
		x /= (ll)2; 
		cnt += 1;
	}
	return cnt;
}
ll gcd(ll x, ll y) {
	if (y == 0)return x;
	else return gcd(y, x % y);
}
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	// X = y / 2 + y * p
	// X = y/2 (1 + 2 p) // 만약에 y/2 = 짝수 = 무조건 짝수임. 
	// X = 4 (1 + 2p)
	// X = 2 (1 + 2p)
	// X = 4 ( 1 + 2p)
	ll n, m; cin >> n >> m;
	bool f = false, f2 = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] /= 2;
		if (a[i] & 1) {
			f = true;
		}
		else f2 = true;	
	}
	if (f && f2) {
		cout << 0 << '\n'; return 0;
	}
	ll t = go(a[0]);
	for (int i =1; i < n; i++) {
		if (go(a[i]) != t) {
			cout << 0 << '\n'; return 0;
		}
	}

	ll lcd = a[0];
	for (int i = 1; i < n; i++) {
		ll g = gcd(lcd, a[i]);
		lcd = (lcd * a[i]) / g;
		if (lcd > m) {
			cout << 0 << '\n'; return 0;
		}
	}

	m /= lcd;
	ll ans = (m + 1) / 2;
	cout << ans << '\n';
	// 8 4
	//






}

#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
typedef double db;
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a, ll b) {
	return a % b ? gcd(b, a % b) : b;
}
bool fun(ll n) {
	if (n < 3)return n - 1;
	ll q = sqrt(n + 0.5) + 1, i;
	for (i = 2; i < q; ++i) {
		if (n % i == 0)return 0;
	}
	return 1;
}
signed main() {
	ll a, b;
	cin >> a >> b;
	ll n = gcd(a, b);
	ll q = sqrt(n + 0.5) + 1;
	ll i;
	ll ans = 1;
	for (i = 2; i < q; ++i) {
		if (n % i == 0) {
			if (fun(i))++ans;
			if (n / i != i) {
				if (fun(n / i))++ans;
			}
		}
	}
	if (n > 1 && ans == 1)++ans;
	cout << ans << endl;
	return 0;
}
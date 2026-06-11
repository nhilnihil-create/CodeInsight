#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	ll a = -1e18;
	ll b = -1e18;
	ll c = -1e18;
	ll d = -1e18;
	rep(i, n) {
		ll x, y;
		cin >> x >> y;
		a = max(a, x + y);
		b = max(b, x - y);
		c = max(c, -x + y);
		d = max(d, -x - y);
	}
	ll ans = -1e18;
	ans = max(a + d, b + c);
	cout << ans << endl;
}
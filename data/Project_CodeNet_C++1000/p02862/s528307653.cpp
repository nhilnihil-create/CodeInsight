#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll F[2100010];

ll Mul(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}

void fact(void) {
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i <= 2100000; i++) {
		F[i] = Mul(i, F[i - 1]);
	}
}
ll square(ll x) {
	return (x * x) % mod;
}

ll power(ll x, ll y) {
	if (y == 0) return 1;
	else if (y == 1) return x % mod;
	else if (y % 2 == 0) return square(power(x, y / 2)) % mod;
	else return square(power(x, y / 2)) * x % mod;
}

ll Div(ll a, ll b) {
	return Mul(a, power(b, mod - 2));
}
ll P(ll n, ll r) {
	if (n < r || n < 0 || r < 0) return 0;
	return Div(F[n], F[n - r]);
}

ll C(ll n, ll r) {
	if (n < r || n < 0 || r < 0) return 0;
	ll ret;
	ret = Div(F[n], Mul(F[n - r], F[r]));
	return ret;
}

int main()
{
	ll X, Y;
	cin >> X >> Y;
	if ((X + Y) % 3 != 0 || abs(X - Y) > (X + Y) / 3) {
		cout << 0 << endl;
	}
	else {
		if (abs(X - Y) > (X + Y) / 3) {
			cout << 0 << endl;
			return 0;
		}
		fact();
		int n = (X + Y) / 3;
		int r = (n - abs(X - Y)) / 2;
		cout << C(n, r) << endl;
	}
}
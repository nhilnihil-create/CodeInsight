#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;
const int mod = 1e9 + 7;

using namespace std;

template<typename T>
T mpow(T a, T n) {
	if (n == 1)return a;
	T temp = mpow(a, n / 2);
	return ((temp * temp) % mod) * (n % 2 != 0 ? a : 1) % mod;
}

template<typename T>
T mcomb(T n, T r) {
	if (n < 0 || r < 0 || n < r) return 0;
	T X = 1, Y = 1;
	rep(i, r)X = (X * (n - i)) % mod;
	rep(i, r)Y = (Y * (r - i)) % mod;
	T ret = X * mpow<T>(Y, mod - 2);
	return ret%mod;
}

int main(void) {
	ll n, a, b; cin >> n >> a >> b;

	ll total = mpow<ll>(2, n) - 1;
	ll A = mcomb<ll>(n, a);
	ll B = mcomb<ll>(n, b);

	ll ans = total - A;
	ans = ans % mod + (ans < 0 ? mod : 0);
	ans -= B;
	ans = ans % mod + (ans < 0 ? mod : 0);

	cout << ans << endl;

	return 0;
}
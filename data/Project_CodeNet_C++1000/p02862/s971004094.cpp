#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int modPow(ll a, ll n, ll p) {
  if (n == 0) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
	ll X, Y; cin >> X >> Y;
	if((X + Y) % 3 != 0 || (double)Y > 2 * (double)X || (double)Y < (double)X / 2)  {
		cout << 0 << endl;
		return 0;
	}
	else if((X % 2 == 0 && Y == X / 2) || (Y % 2 == 0 && Y == 2 * X)) {
		cout << 1 << endl;
		return 0;
	}
	ll l = max((2 * X - Y) / 3, (ll)0);
	ll s = max((2 * Y - X) / 3, (ll)0);
	
	ll fact = 1;
	for(int i = 2; i <= l + s; i++) fact = fact * i % mod;
	ll invfact1 = 1;
	for(int i = 1; i <= l; i++) invfact1 = invfact1 * modPow(i, mod - 2, mod) % mod;
	ll invfact2 = 1;
	for(int i = 1; i <= s; i++) invfact2 = invfact2 * modPow(i, mod - 2, mod) % mod;
	ll ans = fact * invfact1 % mod;
	ans = ans * invfact2 % mod;
	cout << ans << endl;
	return 0;
}
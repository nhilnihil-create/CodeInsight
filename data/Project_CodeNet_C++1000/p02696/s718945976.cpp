#include<bits/stdc++.h>
using namespace std;
#define ll         long long int
#define mod        1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf        1e18
#define ps(x,y)    fixed<<setprecision(y)<<x

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll a, b, n;
	cin >> a >> b >> n;

	ll x1 = n % b;
	ll x2 = n - x1 - 1;

	ll ans = (a * n) / b - (a * (n / b));
	ll ans2 = INT_MIN;
	if (x2 > 0)
		ans2 = (a * x2) / b - (a * (x2 / b));

	ans = max(ans, ans2);
	cout << ans;






}
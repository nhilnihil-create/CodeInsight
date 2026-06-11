#include<bits/stdc++.h>
using namespace std;
#define ll         long long
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

	ll a, b, c, k;
	cin >> a >> b >> c >> k;


	if (k <= a)
	{
		cout << k;
		return 0;
	}
	else if (k <= a + b)
	{
		cout << a;
		return 0;
	}
	else
	{
		k = k - a - b;
		k = a - k;
		cout << k;
		return 0;
	}

}
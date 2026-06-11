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

	ll int x;
	cin >> x;
	ll int a, b;

	for (ll i = -150; i <= 150; i++)
	{
		for (ll j = -150; j <= 150; j++)
		{
			a = i * i * i * i * i;
			b = j * j * j * j * j;
			if (a == x + b)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}
}
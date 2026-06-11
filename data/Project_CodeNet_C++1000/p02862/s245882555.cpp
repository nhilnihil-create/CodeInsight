#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define PI 3.14159265358979
#define ll long long
using namespace std;

int Msquare_int(int x)
{
	return (ll)x* (ll)x% MOD_P;
}

int Mpower_int(int x, int e)
{
	if (e == 1) {
		return x;
	}
	if (e % 2) {
		return (int)((ll)(Msquare_int(Mpower_int(x, (e - 1) / 2))) * (ll)x % MOD_P);
	}
	return Msquare_int((Mpower_int(x, e / 2)) % MOD_P);
}

int inverse(int x, int y = MOD_P)
{
	return Mpower_int(x, y - 2);
}

ll permitation(int n)
{
	ll p = 1LL;
	for (ll i = 2LL; i <= n; i++) {
		p *= i;
		p %= MOD_P;
	}

	return p;
}

int main()
{
	int x, y;
	cin >> x >> y;

	if ((2 * y - x) % 3 || (2 * x - y) % 3 || (2 * y - x) < 0 || (2 * x - y) < 0) {
		printf("0");
	} else {
		int a = (2 * y - x) / 3;
		int b = (2 * x - y) / 3;
		ll pa = permitation(a);
		ll pb = permitation(b);
		ll ps = permitation(a + b);
		//printf("[%lld,%lld,%lld]\n", pa, pb, ps);
		ps *= (ll)inverse(pa);
		ps %= MOD_P;
		ps *= (ll)inverse(pb);
		ps %= MOD_P;
		printf("%lld", ps);
	}

	return 0;
}


#include <bits/stdc++.h>

using namespace std;
// ax + by = gcd(a, b)
long long extended_euclidean(long long a, long long b, long long &x, long long &y)
{
	x = 1;
	y = 0;
	long long u = 0, v = 1;
	long long ri = a, rj = b, rk, k;

	// [x y]
	// [u v]
	while (1) {
		k = ri/rj;
		rk = ri%rj;
		ri = rj;
		rj = rk;


		// [newx newy] = [0  1] [x y]
		// [newu newv] = [1 -k] [u v]
		long long newx, newy, newu, newv;
		newx = u;
		newy = v;
		newu = x-k*u;
		newv = y-k*v;
		x = newx;
		y = newy;
		u = newu;
		v = newv;

		if (rk == 0)
			break;
	}

	return a*x+b*y; // gcd
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	long long x, y;
	long long d = extended_euclidean(a, b, x, y);
	cout << a / d * b << endl;
	return 0;
}
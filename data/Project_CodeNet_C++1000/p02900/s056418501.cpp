#include <bits/stdc++.h>
using namespace std;
// ax + by = gcd(a, b) O(logN)
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
void prime_factorization(long long n, map<long long, int>& m) // O(sqrt(n))
{
	for (long long i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			n/=i;
			m[i]++;
		}
	}
	if (n != 1)
		m[n]++;
}
int main(void)
{
	long long a, b;
	cin >> a >> b;
	long long x, y;
	long long gcd = extended_euclidean(a, b, x, y);

	map<long long, int> m;
	prime_factorization(gcd, m);
	cout << m.size()+1 << endl;


	return 0;
}
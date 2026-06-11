#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, z;
	cin >> x >> y >> z;
	
	swap(x, y);
	swap(x, z);

	cout << x << ' ' << y << ' ' << z << '\n';

	return 0;
}

/*template < typename T >
long long modexp(T a, T b, T p) {
	// returns a to the power b mod p by modular exponentiation

	long long res = 1;
	long long mult = a % p;
	while (b > 0) {
		if (b & 1) {
			res = (res * mult) % p;
		}
		b >>= 1;
		mult = (mult * mult) % p;
	}

	return res;
}*/

/*int primeModInverse(int a, int n) {
	// returns inverse of a mod n by mod exponentiation, use only if n is prime
	return (int) modexp(a, n - 2, n);
}*/

/*template < typename T >
T gcd(T a, T b) {

	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);

}*/

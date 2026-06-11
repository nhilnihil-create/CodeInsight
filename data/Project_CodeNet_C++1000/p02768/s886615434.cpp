#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>


#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define MAXMIN(a,b,c) std::max(a,min(b,c))
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using tlll = tuple<lli, lli, lli>;
using vll = vector<lli>;

lli mod197 = 1000000007LL;
lli INF = 10000000000000;

// ax + by = gcd(a,b) 最大公約数
template< typename T >
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}

	return d;
}

lli inv_fac[200001] = {};
lli fac[200001] = {};


//a^x mod mod197
lli pow_mod(lli a, lli x) {

	lli answer = 1;
	while (x != 0) {
		if (x % 2 == 1) answer = (answer * a) % mod197;
		a *= a;
		a %= mod197;
		x >>= 1;
	}

	return answer;
}

lli comb_mod(lli n, lli r) {
	if (fac[0] == 0) {
		fac[0] = 1;
		inv_fac[0] = 1;
		for (lli i = 1; i <= 200000; i++) {
			fac[i] = (fac[i - 1] * i) % mod197;
			inv_fac[i] = (inv_fac[i - 1] * pow_mod(i, mod197 - 2)) % mod197;
		}
	}
	if (n == 0 && r == 0) return 1;
	lli tmp = (inv_fac[n - r] * inv_fac[r]) % mod197;
	return (tmp * fac[n]) % mod197;
}

lli min_r_comb_mod(lli n, lli r) {
	if (n == 0 && r == 0) return 1;

	lli x = 1;
	lli y = 1;

	for (lli i = 1; i <= r; i++) {
		y *= i;
		y %= mod197;
		x *= (n - i + 1);
		x %= mod197;
	}

	return (pow_mod(y, mod197 - 2) * x) % mod197;
}


int main(void) {

	lli n, a, b;
	cin >> n >> a >> b;



	lli answer = pow_mod(2, n) - min_r_comb_mod(n, a) - min_r_comb_mod(n, b);
	answer %= mod197;
	answer += mod197;
	answer %= mod197;
	cout << answer - 1 << endl;


	return 0;
}
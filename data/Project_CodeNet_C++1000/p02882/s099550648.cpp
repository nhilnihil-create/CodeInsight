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



int main(void) {

	double a, b, x;
	cin >> a >> b >> x;

	double pi = atan(1) * 4;

	if (a * a * b / 2 == x) {
		cout << setprecision(10) << atan(b / a) / pi * 180 << endl;
	}
	else if (a * a * b / 2 < x) {
		cout << setprecision(10) << atan(2 * (a * a * b - x) / (a * a * a)) / pi * 180 << endl;
	}
	else {
		cout << setprecision(10) << (pi / 2 - atan(2 * x / (a * b * b))) / pi * 180 << endl;
	}




	return 0;
}
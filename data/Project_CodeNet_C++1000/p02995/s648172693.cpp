#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

template<typename T>
T gcd(T a, T b) {
	if( a < b ) swap(a, b);
	
	T r;
	while( r = a % b ) {
		a = b;
		b = r;
	}
	
	return b;
}

template<typename T> 
T lcm(T a, T b) {
	return (a / gcd(a, b)) * b;
}

int main(void) {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll l = lcm(c, d);
	ll na = a - 1LL;
	na -= ((a - 1LL) / c + (a - 1LL) / d);
	na += (a - 1LL) / l;
	
	ll nb = b;
	nb -= (b / c + b / d);
	nb += b / l;
	
	cout << nb - na << endl;
	
	return 0;
}

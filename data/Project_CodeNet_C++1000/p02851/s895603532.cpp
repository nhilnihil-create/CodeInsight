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

lli a[200002] = {};
lli ruiseki[200002] = {};

int main(void) {

	lli n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		ruiseki[i] += a[i];
		ruiseki[i + 1] += ruiseki[i];
		ruiseki[i] = (ruiseki[i] - i + k) % k;
		//cerr << ruiseki[i] << " ";
	}
	//cerr << endl;

	map<lli, lli> m;
	m[1]++;

	lli sum = 0;

	for (lli i = 0; i < min(k,n); i++) {
		if (i == k - 1) {
			m[1]--;
		}
		//ここで尺取りを使う
		m[ruiseki[i]]++;

		sum += m[ruiseki[i]] - 1;

		//cerr << sum << " ";
	}

	for (lli i = k; i < n; i++) {

		m[ruiseki[i - k]]--;
		m[ruiseki[i]]++;

		sum += m[ruiseki[i]] - 1;
		//cerr << sum << " ";
	}

	//cerr << endl;

	cout << sum << endl;



	return 0;
}
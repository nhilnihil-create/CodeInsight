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

lli r[4001] = {};
lli g[4001] = {};
lli b[4001] = {};

int main(void) {

	lli n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			r[i] += 1;
		}
		if (s[i] == 'G') {
			g[i] += 1;
		}
		if (s[i] == 'B') {
			b[i] += 1;
		}
		r[i + 1] += r[i];
		g[i + 1] += g[i];
		b[i + 1] += b[i];
	}

	lli answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			char c = 'R' + 'G' + 'B' - s[i] - s[j];

			if (2 * j - i < n && s[2 * j - i] == c) {
				answer--;
			}

			switch (c) {
			case 'R':
				answer += r[n] - r[j];
				break;
			case 'G':
				answer += g[n] - g[j];
				break;
			case 'B':
				answer += b[n] - b[j];
				break;
			}

		}
	}


	cout << answer << endl;

	return 0;
}
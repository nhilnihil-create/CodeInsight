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

lli ans[200000] = {};

int main(void) {

	string s;
	cin >> s;

	lli n = s.size();

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R' && s[i + 1] == 'L') {
			//rをカウントする
			for (int j = i; j >= 0 && s[j] == 'R'; j--) {
				if (j % 2 == i % 2) {
					ans[i]++;
				}
				else {
					ans[i + 1]++;
				}
			}
			//lをカウントする
			for (int j = i + 1;j < n &&  s[j] == 'L'; j++) {
				if (j % 2 == (i + 1) % 2) {
					ans[i + 1]++;
				}
				else {
					ans[i]++;
				}
			}
		}
	}


	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;



	return 0;
}
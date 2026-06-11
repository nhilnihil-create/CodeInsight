#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
#include <random>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;
using pis = std::pair<int, std::string>;

const long long INF = 1000000000000000001;
const long long _MOD_ = 1000000000000000009;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string l;
	cin >> l;
	ll* sum = new ll[l.length() + 1];
	sum[0] = 1;
	REP(i, 1, l.length() + 1) {
		sum[i] = 2 * sum[i - 1] + sum[i - 1];
		sum[i] %= _MOD;
	}

	ll ans = 0;
	ll t = 1;
	rep(i, l.length()) {
		if (l[i] == '1') {
			if(t != 1) ans += ((sum[l.length() - 1 - i] - 1) * t) % _MOD;
			else ans += sum[l.length() - 1 - i];
			ans %= _MOD;
			ans += 2 * t;
			ans %= _MOD;

			t *= 2;
			t %= _MOD;
		}
	}

	cout << ans << "\n";

	return 0;
}

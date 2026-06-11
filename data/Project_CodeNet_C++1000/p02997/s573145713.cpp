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

void warshallFloyd(int** graph, int n) noexcept {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	set<pii> m;
	REP(i, 1, n) m.insert(pii(0, i));
	
	int sum = ((n - 1)*(n - 2)) / 2;
	if (sum < k) {
		cout << "-1" << "\n";
		return 0;
	}
	REP(i, 1, n) {
		bool flag = false;

		REP(j, i + 1, n) {
			if (sum > k) {
				m.insert(pii(i, j));
				--sum;
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	cout << m.size() << "\n";
	for (auto p = m.begin(); p != m.end(); ++p) cout << (*p).first + 1 << " " << (*p).second + 1 << "\n";

	return 0;
}

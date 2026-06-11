//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>

// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
using qul = queue<ll>;
using pql = priority_queue<ll>;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#pragma region header
//#define int long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define INF (ll)10000000000000000
#define mod (ll)1000000007
#define P pair<lint,lint>
#pragma endregion
#pragma endregion


int main(void) {
	lint n; cin >> n;
	vector<pair<lint, lint>> d(n);
	for (int i = 0; i < n; i++) cin >> d[i].first >> d[i].second;
	vl x(n);
	for (int i = 0; i < n; i++) x[i] = i + 1;
	ld ans = 0;
	do {
		for (int i = 0; i < n - 1; i++) {
			ans += sqrt(pow((d[x[i + 1] - 1].first - d[x[i] - 1].first), 2) + pow((d[x[i + 1] - 1].second - d[x[i] - 1].second), 2));
		}
	} while (next_permutation(x.begin(), x.end()));
	lint cnt = 1;
	for (int i = 0; i < n; i++) {
		cnt *= (i + 1);
	}
	printf("%.30Lf", ans / (ld)(cnt));

	return 0;
}
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)

























int main() {
	ll n;
	cin >> n;
	ll ans = n * (n + 1) * (n + 2) / 6;
	REP(i, n - 1) {
		ll u, v;
		cin >> u >> v;
		ans -= min(u, v) * (n + 1 - max(u, v));
	}
	cout << ans << endl;
}
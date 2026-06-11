#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> v;
	map<pair<ll, ll>, ll> m;
	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			ll x = v[i].first - v[j].first;
			ll y = v[i].second - v[j].second;
			m[make_pair(x, y)]++;
			m[make_pair(-x, -y)]++;
		}
	}
	ll maxm = 0;
	for (auto itr = m.begin(); itr != m.end(); itr++) {
		if (maxm < itr->second) {
			maxm = itr->second;
		}
	}
	cout << n - maxm << endl;
}

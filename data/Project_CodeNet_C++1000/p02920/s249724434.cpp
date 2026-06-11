#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << x << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	multiset<int, greater<int>> st;
	rep(i, (1 << n)) {
		int a;
		cin >> a;
		st.insert(a);
	}
	st.insert(-inf);
	vector<int> vec;
	int ma = *st.begin();
	vec.pb(ma);
	st.erase(st.find(ma));
	rep(_, n) {
		vector<int> nxt = vec;
		for (auto i : vec) {
			int val = *st.upper_bound(i);
			if (val == -inf) {
				cout << "No\n";
				return 0;
			}
			nxt.pb(val);
			st.erase(st.find(val));
		}
		vec = nxt;
	}
	cout << "Yes\n";
}
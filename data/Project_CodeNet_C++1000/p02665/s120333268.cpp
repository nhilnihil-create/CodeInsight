#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
//#include <unordered_map>

using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}


#define int long long
#define double long double
#define right right228
#define mp make_pair
#define all(v) v.begin(), v.end()

const int N = 100 * 1000 + 228;

int a[N], v[N], suff[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = n; i >= 0; --i) {
		suff[i] = suff[i + 1] + a[i];
	}
	v[0] = 1;
	if (a[0] > 1) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		v[i] = min( (v[i - 1] - a[i - 1]) * 2LL , suff[i] );

		if (v[i] < a[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}

	int sum_vert = 0;
	for (int i = 0; i <= n; ++i) {
		sum_vert += v[i];
	}
	cout << sum_vert << '\n';
	return 0;
}

/*

1
3 2 2
1 2 3 1 
2 3 1 0
1
1 3

01.a
3 3 4
...
.#.
...
1 1 1 3 8 
1 3 1 3 64
2 1 1 3 24
2 1 3 3 40

3 4 3
1 2
2 2
2 4
3
1 1 1 4
2 2 3 3
3 2 2 4

*/

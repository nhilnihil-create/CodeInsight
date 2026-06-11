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

#define double long double
#define right right228
#define mp make_pair
#define all(v) v.begin(), v.end()


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int A = h1 * 60 + m1;
	int B = h2 * 60 + m2;
	cout << max(0, B - A - k) << '\n';
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

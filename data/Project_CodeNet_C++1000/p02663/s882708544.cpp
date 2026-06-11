#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
using namespace std;
 

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define int long long

 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
 
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = INT64_MAX;


mt19937 rnd(time(0));


signed main() {
	FAST_IO;
	// int q;
	// cin >> q;
	// while (q--) {	
		int h1, m1, h2, m2, k;
		cin >> h1 >> m1 >> h2 >> m2 >> k;
		m1 += h1 * 60;
		m2 += h2 * 60;
		m2 -= k;
		cout << m2 - m1 << "\n";
	// }
 	return 0;
}
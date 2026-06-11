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
		string s;
		cin >> s;
		int n = s.size();
		forn(i, n) {
			if (s[i] == '?') {
				if (i - 1 >= 0) {
					if (s[i - 1] == 'P') {
						s[i] = 'D';
						continue;
					}
				}
				if (i + 1 < n) {
					if (s[i + 1] == 'D' || s[i + 1] == '?') {
						s[i] = 'P';
					} else {
						s[i] = 'D';
					}
				} else {
					s[i] = 'D';
				}
			}
		}
		cout << s << "\n";
	// }
 	return 0;
}
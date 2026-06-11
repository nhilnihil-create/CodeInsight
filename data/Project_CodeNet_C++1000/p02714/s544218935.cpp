//Apparat : drobucs, aleonov, vit_72
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <stack>

//#pragma warning(disable : 4996)
//#pragma GCC optimize("O3")

using namespace std;

#define nptr nullptr
#define all(x) (x).begin(), (x).end()
#define drobucs ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define ff first
#define ss second
#define pb push_back
#define sz(x) (int)(x).size()

typedef  long long ll;

const int maxn = (int)1e6 + 13;
const ll INFL = (1ll << 62ll) - 1 + (1ll << 62ll);
const ll INF = (1ll << 30ll) - 1ll + (1ll << 30ll);
const ll MOD = (int)1e9 + 7, MOD2 = 998244353;//1e9 + 21, 1e9 + 33, 1e9 + 87, 1e9 + 93
const ll base = 101, base2 = 37;



int main() {
	drobucs;
	int n;
	cin >> n;
	string s;
	cin >> s;
	// r - 1, g - 2, b - 3
	vector<ll> a;
	vector<ll> col[4];
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R')a.push_back(1), col[1].push_back(i);
		if (s[i] == 'G')a.push_back(2), col[2].push_back(i);
		if (s[i] == 'B')a.pb(3), col[3].push_back(i);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] != a[j]) {
				int c = a[i] ^ a[j];
				ll l = -1, r = sz(col[c]);
				while (r - l > 1) {
					ll m = (l + r) / 2;
					if (col[c][m] >= j + 1)r = m;
					else l = m;
				}
				if (r == sz(col[c]))continue;
				ans += sz(col[c]) - r;
				if (2 * j - i < n && a[2 * j - i] == c)ans--;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
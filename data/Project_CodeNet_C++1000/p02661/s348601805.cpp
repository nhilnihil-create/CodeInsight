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

const int maxn = (int)1e7 + 13;
const ll INFL = 9223372036854775807;
const ll INF = 2147483647;
const ll MOD = (int)1e9 + 7, MOD2 = 998244353;//1e9 + 21, 1e9 + 33, 1e9 + 87, 1e9 + 93
const ll base = 101, base2 = 37;

int main() {
	drobucs;

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)cin >> v[i].ff >> v[i].ss;
	sort(all(v));
	if (n & 1) {
		int l = 0, r = 0;
		l = v[n / 2].ff;
		sort(all(v), [](pair<int, int> a, pair<int, int> b) {return a.second > b.second; });
		r = v[n / 2].ss;
		cout << r - l + 1 << "\n";
	}
	else {
		int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
		l2 = v[n / 2].ff;
		l1 = v[n / 2 - 1].ff;
		sort(all(v), [](pair<int, int> a, pair<int, int> b) {return a.second < b.second; });
		r1 = v[n / 2].ss;
		r2 = v[n / 2 - 1].ss;
		cout << r1 + r2 - l1 - l2 + 1 << "\n";
	}
	return 0;
}
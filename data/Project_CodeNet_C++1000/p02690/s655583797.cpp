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
const ll INFL = (1ll << 63ll) - 1ll;
const ll INF = (1ll << 31ll) - 1ll;
const ll MOD = (int)1e9 + 7, MOD2 = 998244353;//1e9 + 21, 1e9 + 33, 1e9 + 87, 1e9 + 93
const ll base = 101, base2 = 37;



int main() {
	drobucs;
	
	ll x;
	cin >> x;
	for (ll i = 0; i <= 5000; ++i) {
		ll d = i * i * i * i * i;
		ll l = -5000, r = 5000;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (d - m * m * m * m * m <= x)r = m;
			else l = m;
		}
		if (d - r * r * r * r * r == x) {
			cout << i << " " << r << "\n";
			return 0;
		}
	}
	
	return 0;
}
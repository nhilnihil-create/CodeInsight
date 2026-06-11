#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9 + 7;
const int maxn = 2007;
int arr[maxn], n;
ll k;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> k;
	rep(i, 0, n) {
		cin >> arr[i];
	}
	ll res = 0;

	ll fact = ((k * k) - k) / 2;
	fact %= mod;
	rep(i, 0, n) {
		ll total = 0, part = 0;
		rep(j, i + 1, n) {
			if (arr[j] < arr[i]) part++;
		}
		rep(j, 0, n) {
			if (arr[j] < arr[i]) total++;
		}
		res += (total * fact);
		res %= mod;
		res += (part * k);
		res %= mod;
	}
	cout << res << endl;
}

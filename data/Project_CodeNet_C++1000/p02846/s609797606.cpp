#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	vector<int> t(2);
	for (int i = 0; i < 2; i++) {
		cin >> t[i];
	}
	vector<ll> a(2);
	for (int i = 0; i < 2; i++) {
		cin >> a[i];
	}
	vector<ll> b(2);
	for (int i = 0; i < 2; i++) {
		cin >> b[i];
	}


	vector<ll> d(2);
	for (int i = 0; i < 2; i++) {
		d[i] = a[i] - b[i];
	}

	if (d[0] < 0) {
		d[0] *= -1;
		d[1] *= -1;
	}

	ll dis = d[0] * t[0];
	ll c = dis + d[1] * t[1];
	if (c == 0) {
		cout << "infinity" << endl;
		return 0;
	}

	if (c > 0) {
		cout << 0 << endl;
	}
	else {
		ll ans = 2 * (dis / abs(c));

		if (dis % abs(c) != 0) {
			ans++;
		}

		cout << ans << endl;


	}
}
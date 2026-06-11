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



ll md(pll a, pll b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	int n;
	cin >> n;

	
	vector<ll> z(n);
	vector<ll> w(n);
	for (int i = 0; i < n; i++) {
		ll xi, yi;
		cin >> xi >> yi;

		ll zi = xi + yi;
		ll wi = xi - yi;
		z[i] = zi;
		w[i] = wi;
	}

	sort(z.begin(), z.end());
	sort(w.begin(), w.end());

	cout << max(z[n - 1] - z[0], w[n - 1] - w[0]) << endl;

	
}
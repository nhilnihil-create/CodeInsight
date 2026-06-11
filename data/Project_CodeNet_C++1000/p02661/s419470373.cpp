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



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;



int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<ll>());

	if (n % 2 == 0) {
		ll mi = (a[n / 2] + a[n / 2 - 1]);
		ll ma = (b[n / 2] + b[n / 2 - 1]);

		cout << ma - mi + 1 << endl;
	}
	else {
		ll mi = a[n / 2];
		ll ma = b[n / 2];

		cout << ma - mi + 1 << endl;
	}
}

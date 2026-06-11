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
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;




int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}



	vector<ll> b(n + 1);
	vector<ll> sum(n + 2);
	for (int i = n; i >= 0; i--) {
		sum[i] = sum[i + 1] + a[i];
	}

	b[0] = 1 - a[0];

	for (int i = 1; i <= n; i++) {
		b[i] = min(2 * b[i - 1] - a[i], sum[i + 1]);

	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += a[i] + b[i];
		if (b[i] < 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << ans << endl;
}

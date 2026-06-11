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
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> c(3);
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			if (c[j] == a[i]) {
				cnt++;
			}
		}

		ans = (ans * cnt) % MOD;
		for (int j = 0; j < 3; j++) {
			if (c[j] == a[i]) {
				c[j] = a[i] + 1;
				break;
			}
		}

	}
	cout << ans << endl;
}
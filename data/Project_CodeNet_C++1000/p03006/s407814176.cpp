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
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int n;
	cin >> n;
	vector<ll> x(n);
	vector<ll> y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	
	int ans = n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int p = (x[i] - x[j]);
			int q = (y[i] - y[j]);

			int cnt = 0;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (k == l) {
						continue;
					}
					if ((x[k] - x[l] == p) && (y[k] - y[l] == q)) {
						cnt++;
					}
				}
			}

			ans = min(ans, n - cnt);
			
		}
	}
	
	
	
	cout << ans << endl;
}
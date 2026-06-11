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
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;



int main() {
	int n, q;
	cin >> n >> q;
	
	dsu d(n);
	for (int i = 0; i < q; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t) {
			cout << d.same(u, v) << endl;
		}
		else {
			d.merge(u, v);
		}
	}
}
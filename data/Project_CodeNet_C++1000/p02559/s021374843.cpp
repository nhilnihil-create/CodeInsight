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
#include<atcoder/fenwicktree.hpp>
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
	fenwick_tree<ll> fw(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		fw.add(i, a);
	}

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t) {
			int l, r;
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
		else {
			int p, x;
			cin >> p >> x;
			fw.add(p, x);
		}
	}
}
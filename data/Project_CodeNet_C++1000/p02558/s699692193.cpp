#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>
#include <atcoder/dsu.hpp>

using namespace std;
using namespace atcoder;

#define unionFind dsu

typedef long long ll;
#define endl '\n'

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, Q; cin >> N >> Q;
	unionFind uf = unionFind(N);
	for (int i = 0; i < Q; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
			uf.merge(u, v);
		}
		else {
			cout << uf.same(u, v) << endl;
		}
	}

	return 0;
}
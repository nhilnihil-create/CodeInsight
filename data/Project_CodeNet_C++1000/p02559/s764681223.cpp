#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")


// range query using fenwick tree
// note index starts at 1

class fenwick_tree {
	vector<long long> t;
	long long size;
public:
	fenwick_tree(long long n) {
		t.assign(n + 1, 0);
		size = n + 1;
	}

	long long LSOne(long long k) {	// least significant 1-bit
		return k & (-k);
	}

	void update(long long index, long long val) {	// can go up or go down
		for (; index < size; index += LSOne(index)) t[index] += val;
	}

	long long query_full(long long a, long long b) {		// range query
		return query(b) - ((a <= 1) ? 0 : query(a - 1));
	}

	long long query(long long b) {	// range query 1..b
		if (b < 1) return 0;

		long long sum = 0;
		for (; b; b -= LSOne(b)) sum += t[b];
		return sum;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, q, id, x, t, l, r, ans, i, j, k;

	cin >> n >> q;
	fenwick_tree ft(n + 10);
	for (i = 0; i < n; i++) {
		cin >> x;
		ft.update(i + 1, x);
	}

	while (q--) {
		cin >> t;
		if (t == 0) {
			cin >> id >> x;
			ft.update(id + 1, x);
		}
		else {
			cin >> l >> r;
			ans = ft.query_full(l + 1, r);
			cout << ans << "\n";
		}
	}



	return 0;
}

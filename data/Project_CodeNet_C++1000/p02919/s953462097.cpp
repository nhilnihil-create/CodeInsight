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

using namespace std;


// range sum query using fenwick tree
// note index starts at 1

class fenwick_tree {
	vector<long> t;
	long size;
public:
	fenwick_tree(long n) {
		t.assign(n + 1, 0);
		size = n + 1;
	}

	long LSOne(long k) {	// least significant 1-bit
		return k & (-k);
	}

	void update(long index, long val) {	// can go up or go down
		for (; index < size; index += LSOne(index)) t[index] += val;
	}

	long query_full(long a, long b) {		// range query
		return query(b) - ((a <= 1) ? 0 : query(a - 1));
	}

	long query(long b) {	// range query 1..b
		if (b < 1) return 0;

		long sum = 0;
		for (; b; b -= LSOne(b)) sum += t[b];
		return sum;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans, a, b, c, x, y, xx, yy, p, v;
	cin >> n;
	vector<pair<long long, long long>> d(n);
	for (i = 0; i < n; i++) {
		cin >> x;
		d[i] = { x, i + 2 };
	}

	sort(d.rbegin(), d.rend());

	fenwick_tree ft(n + 3);
	ft.update(1, 1); 
	ft.update(n + 2, 1);

	ans = 0;
	for (i = 0; i < n; i++) {
		p = d[i].second;

		a = p + 1; b = n + 2;
		while (a < b) {
			c = (a + b) / 2;
			v = ft.query_full(p + 1, c);
			if (v >= 1) b = c;
			else a = c + 1;
		}
		y = a;

		if (y == n + 2) yy = y;
		else {
			a = p + 1; b = n + 2;
			while (a < b) {
				c = (a + b) / 2;
				v = ft.query_full(p + 1, c);
				if (v >= 2) b = c;
				else a = c + 1;
			}
			yy = a;
		}
			   
		a = 1; b = p - 1;
		while (a < b) {
			c = (a + b + 1) / 2;
			v = ft.query_full(c, p - 1);
			if (v >= 1) a = c;
			else b = c - 1;
		}
		x = b;

		if (x == 1) xx = 1;
		else {
			a = 1; b = p - 1;
			while (a < b) {
				c = (a + b + 1) / 2;
				v = ft.query_full(c, p - 1);
				if (v >= 2) a = c;
				else b = c - 1;
			}
			xx = b;
		}

		v = (y - p) * (x - xx) + (p - x) * (yy - y);
		ans += d[i].first * v;

		ft.update(p, 1);
	}

	cout << ans << "\n";

	return 0;
}



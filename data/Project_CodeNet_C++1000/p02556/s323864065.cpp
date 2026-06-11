/*
https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/339968/JavaC++Python-Maximum-Manhattan-Distance

Intuition
Take |x[i] - x[j]| + |y[i] - y[j]| as Manhattan distance of two points.
x is the coordinate of points on the x-axis,
y is the coordinate of points on the y-axis.


Explanation 1: Math
Assume i < j, there are four possible expression:
|x[i] - x[j]| + |y[i] - y[j]| = (x[i] - x[j]|) + (y[i] - y[j]) = (x[i] + y[i]|) - (x[j] + y[j])
|x[i] - x[j]| + |y[i] - y[j]| = (x[i] - x[j]|) - (y[i] - y[j]) = (x[i] - y[i]|) - (x[j] - y[j])
|x[i] - x[j]| + |y[i] - y[j]| = -(x[i] - x[j]|) + (y[i] - y[j]) = (-x[i] + y[i]|) - (-x[j] + y[j])
|x[i] - x[j]| + |y[i] - y[j]| = -(x[i] - x[j]|) - (y[i] - y[j]) = (-x[i] - y[i]|) - (-x[j] - y[j])

So we can see, the expression
|x[i] - x[j]| + |y[i] - y[j]| + |i - j| = f(j) - f(i)

where f(i) = p * x[i] + q * y[i] + i
with p = 1 or -1, q = 1 or -1


Explanation 2: Graph
For 3 points on the plane, we always have |AO| - |BO| <= |AB|.
When AO and BO are in the same direction, we have ||AO| - |BO|| = |AB|.

We take 4 points for point O, left-top, left-bottom, right-top and right-bottom.
Each time, for each point B, and find the smallest A point to O,
the Manhattan distance |AB| >= |AO| - |BO|.


*/
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#endif

void solve() {
	int n, x, y;
	cin >> n;
	vector<int> sum(n), diff(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		sum[i] = x;
		diff[i] = y;
	}

	int ans = 0;

	for (int p : {1, -1}) {
		for (int q : {1, -1}) {
			int smallest = p * sum[0] + q * diff[0] + 0;
			for (int i = 1; i < n; ++i) {
				int cur = p * sum[i] + q * diff[i];
				ans = max(ans, cur - smallest);
				smallest = min(smallest, cur);
			}
		}
	}

	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0); 		cin.tie(0); cout.tie(0);

	solve();
}


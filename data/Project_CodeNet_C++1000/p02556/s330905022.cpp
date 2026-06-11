#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 10;
int n, maxn;
struct node {
	int x, y;
}s[N];

int cmp1 (node x, node y) {
	return x.x + x.y > y.x + y.y;
}

int cmp2 (node x, node y) {
	return x.x - x.y > y.x - y.y;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf ("%d%d", &s[i].x, &s[i].y);
	sort (s + 1, s + 1 + n, cmp1);
	maxn = abs (s[1].x - s[n].x) + abs (s[1].y - s[n].y);
	sort (s + 1, s + 1 + n, cmp2);
	maxn = max (maxn, abs (s[1].x - s[n].x) + abs (s[1].y - s[n].y));
	cout << maxn << endl;
	return 0;
}

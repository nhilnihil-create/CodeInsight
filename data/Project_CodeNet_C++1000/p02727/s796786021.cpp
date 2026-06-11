#include <stdio.h>
#include <algorithm>
using namespace std;

int x, y, a, b, c;
int p[100100], q[100100], r[100100];

int main()
{
	scanf ("%d %d %d %d %d", &x, &y, &a, &b, &c);
	for (int i = 0; i < a; i++) scanf ("%d", &p[i]); sort(p, p + a); reverse(p, p + a);
	for (int j = 0; j < b; j++) scanf ("%d", &q[j]); sort(q, q + b); reverse(q, q + b);
	for (int k = 0; k < c; k++) scanf ("%d", &r[k]); sort(r, r + c); reverse(r, r + c);

	int i = 0, j = 0, k = 0; long long ans = 0;
	while (i + j + k < x + y){
		int mx = -1000;
		if (i < x) mx = max(mx, p[i]);
		if (j < y) mx = max(mx, q[j]);
		if (k < c) mx = max(mx, r[k]);
		if (i < x && p[i] == mx) ans += p[i++];
		else if (j < y && q[j] == mx) ans += q[j++];
		else ans += r[k++];
	}

	printf ("%lld\n", ans);
	return 0;
}
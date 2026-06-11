#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 55
#define X first
#define Y second
using namespace std;

int n, c, mn = 1e9;
bool v[N];
pair<int, int> a[N];

void f(int p, int q, int r) {
	int i, tp = a[r].X, tq = a[r].Y;
	for (i = r; i < n; i++) {
		if (a[i].X == tp && a[i].Y == tq) {
			v[i] = 1;
			tp += p;
			tq += q;
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n;
	if (n == 1) {puts("1"); return 0;}
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a[i].X, &a[i].Y);
	}
	sort(a, a + n);
    for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			c = 0;
			for (k = 0; k < n; k++) v[k] = 0;
			for (k = 0; k < n; k++) {
				if (!v[k]) c++, f(a[i].X - a[j].X, a[i].Y - a[j].Y, k);
			}
			mn = min(mn, c);
		}
    }
    cout << mn << endl;
    return 0;
}
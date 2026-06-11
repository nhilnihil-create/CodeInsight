#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100005
using namespace std;

int n, w1, w2, a[N];
int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
	}
	sort(a, a + n);
	w1 = a[n - 1];
	w2 = a[0];
	for (i = 1; i < n - 1; i++) {
		if (a[i] > 0) w2 -= a[i];
		else w1 -= a[i];
	}
	cout << w1 - w2 << endl;
	w1 = a[n - 1];
	w2 = a[0];
	for (i = 1; i < n - 1; i++) {
		if (a[i] > 0) break;
		printf("%d %d\n", w1, a[i]);
		w1 -= a[i];
	}
	for (; i < n - 1; i++) {
		printf("%d %d\n", w2, a[i]);
		w2 -= a[i];
	}
	printf("%d %d\n", w1, w2);
    return 0;
}

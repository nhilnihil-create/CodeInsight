#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack> 
#include <bitset>
#include <queue>
#include <assert.h>
#include <unordered_map>
using namespace std;

const int N = 200010;
int a[N], b[N];

void solve1(int n) {
	int lt = 1, rt = 2000000000, mid, l = 1000000000, r = 0;
	while (lt <= rt) {
		mid = (0LL + lt + rt) >> 1;
		int tot1 = 0, tot2 = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] >= mid) tot1++;
			if (a[i] <= mid) tot2++;
		}

		if (tot1 >= (n + 1) / 2 && tot2 >= (n + 1) / 2) {
			l = mid;
			rt = mid - 1;
		} else if (tot1 >= (n + 1) / 2) lt = mid + 1;
		else rt = mid - 1;
	}
	lt = 1, rt = 1000000000;
	while (lt <= rt) {
		mid = (lt + rt) >> 1;
		int tot1 = 0, tot2 = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] >= mid) tot1++;
			if (a[i] <= mid) tot2++;
		}

		if (tot1 >= (n + 1) / 2 && tot2 >= (n + 1) / 2) {
			r = mid;
			lt = mid + 1;
		} else if (tot1 >= (n + 1) / 2) lt = mid + 1;
		else rt = mid - 1;
	}
	printf("%d\n", r - l + 1);
}

void solve2(int n) {
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int l = a[n / 2] + a[n / 2 + 1];
	int r = b[n / 2] + b[n / 2 + 1];
	cout << r - l + 1 << endl;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	if (n & 1) solve1(n);
	else solve2(n);
	return 0;
}

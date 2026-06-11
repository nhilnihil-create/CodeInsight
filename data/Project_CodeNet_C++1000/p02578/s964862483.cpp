#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 200005
using namespace std;
int a[MAXN];
int main()
{
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i != 1) {
			if (a[i] < a[i - 1]) {
				ans += a[i - 1] - a[i];
				a[i] = a[i - 1];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
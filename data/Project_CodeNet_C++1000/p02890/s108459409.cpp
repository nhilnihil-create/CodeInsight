#include <iostream>
#include <cstdio>
#define N 300005
using namespace std;

int n, c[N], s[N], ans[N];
int main()
{
	int i, j, t;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		c[t]++;
		s[c[t]]++;
	}
	for (i = 1; i <= n; i++) s[i] += s[i - 1];
	for (i = n, j = 1; i > 0; i--) {
		for (; ; j++) {
			if (s[j] < j * i) break;
		}
		ans[i] = j - 1;
	}
	for (i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}
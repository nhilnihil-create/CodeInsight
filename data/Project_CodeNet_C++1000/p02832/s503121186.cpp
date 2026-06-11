#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int cur = 1;
    for (int i = 1; i <= n; i ++) {
		if (a[i] == cur) cur ++;
    }
    if (cur == 1) puts("-1");
    else printf("%d\n", n - cur + 1);
	return 0;
}

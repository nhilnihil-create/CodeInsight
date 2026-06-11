#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	int tot = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] * 4 * m < tot) continue;
		cnt++;
	}
	
	if (cnt < m) printf("No\n");
	else printf("Yes\n");
}

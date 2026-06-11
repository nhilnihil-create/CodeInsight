#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < k; i++) {
		int d;
		scanf("%d", &d);
		for (int j = 0; j < d; j++) {
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++) res += (cnt[i] == 0);
	printf("%d\n", res);
}

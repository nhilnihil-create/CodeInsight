#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int a[200005];

int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int res = INF;
	
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) {
			res = min(res, a[i] + k - a[i + 1]);
		}
		else {
			res = min(res, a[i] - a[0]);
		}
		
		if (i - 1 >= 0) {
			res = min(res, k - a[i] + a[i - 1]);
		}
		else {
			res = min(res, a[n - 1] - a[i]);
		}
	}
	
	printf("%d\n", res);
}

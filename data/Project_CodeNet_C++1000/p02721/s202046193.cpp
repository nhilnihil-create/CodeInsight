#include<bits/stdc++.h>

using namespace std;
int n, m, k;
char a[200010];
int dp1[200010] = {0}, vis1[200010] = {0}, dp2[200010] = {0}, vis2[200010] = {0};
int main() {
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", a+1);
	int u = 0;
	for (int i = 1; i <= n; i++) {
		vis1[i] = max(vis1[i-1]-1, 0);
		if (a[i] == 'o' && vis1[i] == 0) {
			vis1[i] = k+1;
			dp1[i] = dp1[i-1] + 1;
		}
		else {
			dp1[i] = dp1[i-1];
		}
	}
	for (int i = n; i >= 1; i--) {
		vis2[i] = max(vis2[i+1]-1, 0);
		if (a[i] == 'o' && vis2[i] == 0) {
			vis2[i] = k+1;
			dp2[i] = dp2[i+1] + 1;
		}
		else {
			dp2[i] = dp2[i+1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis1[i] == k+1 && vis2[i] == k+1 && a[i] == 'o' && dp1[i] + dp2[i+1] == m) {
			printf("%d\n", i);
		}
	}
	return 0;
}
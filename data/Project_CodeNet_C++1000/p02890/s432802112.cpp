#include <iostream>
#include <cstdio>
#define N 300005
using namespace std;

int n, k, sum, c[N], cnt[N], ans[N];
int main() {
	int i, t;
	cin >> n;
	for(i=0; i<n; i++) {
		scanf("%d", &t);
		c[t]++;
		cnt[c[t]]++;
	}
	for(i=n; i; i--) {
		while(k*i <= sum) sum += cnt[++k];
		ans[i] = k-1;
	}
	for(i=1; i<=n; i++) printf("%d\n", ans[i]);
	return 0;
}
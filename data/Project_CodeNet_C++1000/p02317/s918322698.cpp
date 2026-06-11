#include <cstdio>
#include <algorithm>
#define inf 1001001001
using namespace std;
int n, a, dp[100000];
int main() {
	scanf("%d", &n);
	fill(dp, dp+n, inf);
	for (int i=0; i<n; i++) {
		scanf("%d", &a);
		*lower_bound(dp, dp+n, a) = a;
	}
	printf("%ld\n", (lower_bound(dp, dp+n, inf) - dp));
}
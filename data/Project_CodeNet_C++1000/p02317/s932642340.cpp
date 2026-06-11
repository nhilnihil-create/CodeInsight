#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 1001001001;
int n, a, dp[100000];
int main() {
	scanf("%d",&n);
	fill(dp, dp+n, inf);
	for (int i = 0; i < n; i++) {
		scanf("%d",&a);
		*lower_bound(dp, dp+n, a) = a;
	}
	printf("%d\n", (int)(lower_bound(dp, dp+n, inf)-dp));
}
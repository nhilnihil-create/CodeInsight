#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
constexpr int kN = 100;
int a[kN];
ll dp[kN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dp[1] = 1000;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j]);
			dp[i] = max(dp[i], dp[j] % a[j] + (dp[j] / a[j]) * a[i]);
		}
	}
	printf("%lld\n", dp[n]);
}
